// std
#include <ctime>
#include <random>

// local
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // this timer is set to call updateCustomPlot()
    // based on the time set in milliseconds UPDATE_FREQUENCY_MS
    // for e.g. if the update frequency is set to be 10000 milliseconds
    // updateCustomPlot() is called every 10 secs
    m_timer = new QTimer(this);
    QObject::connect(m_timer, &QTimer::timeout, this, &MainWindow::updateCustomPlot);
    m_timer->start(UPDATE_FREQUENCY_MS); //time specified in ms

    // set up plot design
    setPlotAppearance();

    // prepare data
    prepareData();

    // init axes and tickers
    initAxesAndTickers();

    // create bars
    createBars();

    // update plot with data
    updateCustomPlot();

    // rescale y-axis to fit all the content
    ui->customplot->yAxis->rescale();

    // set zooming and dragging functionality
    // although zooming will be lost when the plot updates itself
    ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customplot->axisRect()->setRangeZoomAxes(ui->customplot->xAxis2, ui->customplot->yAxis);
    ui->customplot->axisRect()->setRangeDragAxes(ui->customplot->xAxis2, ui->customplot->yAxis);

    // set widget
    setCentralWidget(ui->widget);
    setWindowTitle("Space Object Observations");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlotAppearance()
{

    // how the plot looks
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customplot->setBackground(QBrush(gradient));

    // try changing colors and see how it looks
    ui->customplot->xAxis2->setBasePen(QPen(Qt::white));
    ui->customplot->xAxis2->setTickPen(QPen(Qt::white));
    ui->customplot->xAxis2->grid()->setVisible(true);
    ui->customplot->xAxis2->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customplot->xAxis2->setTickLabelColor(Qt::white);
    ui->customplot->xAxis2->setLabelColor(Qt::white);

    // design y axis appearance
    ui->customplot->yAxis->setBasePen(QPen(Qt::white));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setLabelColor(Qt::white);
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // hide bottom and right axis
    ui->customplot->xAxis->setVisible(false);
    ui->customplot->yAxis2->setVisible(false);

    // set axis fonts
    ui->customplot->xAxis2->setTickLabelFont(QFont(QFont().family(), 10));
    ui->customplot->yAxis->setTickLabelFont(QFont(QFont().family(), 10));

    // set axis labels
    ui->customplot->xAxis2->setLabel("Observation Horizon");
    ui->customplot->yAxis->setLabel("Space Objects");
}

void MainWindow::updateCustomPlot()
{

    // but it is actually the x-axis updating

    // the origin(0,0) of the plot holds the current time always
    m_datetimeTicker->setTickOrigin(QDateTime::currentDateTime());

    // feel free to change and see how the plot and bars behave
    ui->customplot->xAxis2->setRange(QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime()),
                                     QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime().addSecs(72000)));

    // repaint the whole plot
    ui->customplot->replot();
}

void MainWindow::createBars()
{
    // create random generator engine
    // seed it with std::time otherwise same number will be generated everytime
    // set the distribution to generate values between 0 and 255
    // these values will be used for generating random
    // r, g, b values for the bars
    std::default_random_engine randomGenerator(std::time(0));
    std::uniform_int_distribution<int> value(0, 255);

    // iterate through all the Satellites in the vector
    // create as many bars as there are Satellites in the vector
    for(int i = 0; i < flight_names.size(); i++)
    {
        // initialize a bar and set all the properties
        Bar* bar = new Bar(ui->customplot->yAxis, ui->customplot->xAxis2);
        bar->setBarName(flight_names[i]);
        bar->setArrivalTime(flight_arrival_times[i]);
        bar->setDepartureTime(flight_departure_times[i]);
        bar->setOrigin(flight_origins[i]);
        bar->setDestination(flight_destinations[i]);
        bar->setFlightNumber(flight_numbers[i]);
        bar->setFlightType(flight_types[i]);
        bar->setOvernight(flight_overnight[i]);

        // generate random r,g,b values for the bars
        qint32 r = value(randomGenerator);
        qint32 g = value(randomGenerator);
        qint32 b = value(randomGenerator);

        // color the bars with random values
        bar->setPen(QPen(QColor(r, g, b).lighter(200)));
        bar->setBrush(QColor(r, g, b));

        // set your own bar width
        //bar->setWidthType(QCPBars::WidthType::wtAbsolute);
        //bar->setWidth(25);

        // base value is the starting value of the bar
        // in secs elapsed since 1970 epoch
        bar->setBaseValue(m_timingDataDeparture[i]);

        // here we add the data of the bar
        // difference time in secs between arrival and departure
        bar->addData(m_ticks[i], m_timingDataArrival[i]);
    }
}

void MainWindow::prepareData()
{
    m_timingDataDeparture.resize(flight_names.size());
    m_timingDataArrival.resize(flight_names.size());
    m_ticks.resize(flight_names.size());

    for(int i = 0; i < flight_names.size(); i++)
    {
        m_ticks[i] = 1.0 + i;

        // our arrival and departure times are in QString formats inside the vector
        // For e.g. "1456" is read as 14 hrs and 56 mins
        // In order to use it in QTime() we need to split the string in half
        // to get our time in hours and mins
        int departure_hrs = flight_departure_times[i].midRef(0, 2).toInt();
        int departure_mins = flight_departure_times[i].midRef(2, 2).toInt();

        // same comment as above
        // split the arrival time in half
        // For e.g. "0546" means 05 hrs and 46 mins
        int arrival_hrs = flight_arrival_times[i].midRef(0, 2).toInt();
        int arrival_mins = flight_arrival_times[i].midRef(2, 2).toInt();

        // departure values
        // feed our hrs and mins to QTime()
        // init QDateTime instance
        QDateTime dateTimebase(QDateTime::currentDateTime().date(), QTime(departure_hrs, departure_mins));

        // dataTimeToKey() converts our datetime format into
        // number of seconds since 1970 epoch
        m_timingDataDeparture[i] = QCPAxisTickerDateTime::dateTimeToKey(dateTimebase);

        QDateTime dateTimeFinal;

        // calculatating arrival time is bit tricky
        // since we do not have timestamp with date
        // we cannot know departure and arrival times are on different days
        // so we have to explicitly check if this flight is overnight or not
        // if overnight, we addDays(1) to arrival time
        if(flight_overnight[i] == "Yes")
        {
            // arrival values
            // add 1 extra day to the time
            dateTimeFinal = QDateTime(QDateTime::currentDateTime().addDays(1).date(), QTime(arrival_hrs, arrival_mins));
        }
        else
        {
            // arrival values
            dateTimeFinal = QDateTime(QDateTime::currentDateTime().date(), QTime(arrival_hrs, arrival_mins));
        }

        // TODO: If the flight goes on for 2 days then you need to figure out a way to determine how to calculate.
        // flight_overnight can mean it can go for 1 day or more days
        // if you want a flight with 2 days of running time
        // add this line of code
        // dateTimeFinal = QDateTime(QDateTime::currentDateTime().addDays(2).date(), QTime(arrival_hrs, arrival_mins));
        // notice addDays(2) to the arrival time

        // so the arrival time for the bar
        // would just be the difference of arrival time and departure time in seconds
        // save the diff in a vector
        m_timingDataArrival[i] = QCPAxisTickerDateTime::dateTimeToKey(dateTimeFinal) - m_timingDataDeparture[i];
    }
}


void MainWindow::initAxesAndTickers()
{
    // initialize x-axis
    // time tickers
    m_datetimeTicker.reset(new QCPAxisTickerDateTime);
    m_datetimeTicker->setDateTimeFormat("d. MMM\nhh:mm:ss");
    m_datetimeTicker->setTickCount(10);
    ui->customplot->xAxis2->setTicker(m_datetimeTicker);
    ui->customplot->xAxis2->setVisible(true);
    ui->customplot->xAxis2->grid()->setSubGridVisible(true);

    // initialize y-axis
    // flight names tickers
    m_textTicker.reset(new QCPAxisTickerText);
    m_textTicker->setTicks(m_ticks, flight_numbers);
    ui->customplot->yAxis->setTicker(m_textTicker);
}

void MainWindow::on_pushButton_clicked()
{
    // here write your code to load CSV files
    // and parsing
}
