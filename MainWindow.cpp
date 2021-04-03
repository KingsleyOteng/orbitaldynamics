// standard c++ files
#include <ctime>
#include <random>
#include <regex>
#include <iostream>

// qt ready files
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>

// local ready files
#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
    QObject::connect(m_timer, &QTimer::timeout, this, &MainWindow::updateCustomPlot);
    m_timer->start(UPDATE_FREQUENCY_MS); //set time count to ms
    setPlotAppearance();
    prepareData();
    initAxesAndTickers();
    createBars();
    updateCustomPlot();
    ui->customplot->yAxis->rescale();
    ui->customplot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customplot->axisRect()->setRangeZoomAxes(ui->customplot->xAxis2, ui->customplot->yAxis);
    ui->customplot->axisRect()->setRangeDragAxes(ui->customplot->xAxis2, ui->customplot->yAxis);
    setCentralWidget(ui->widget);
    setWindowTitle("Flight Plot");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPlotAppearance()
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customplot->setBackground(QBrush(gradient));
    ui->customplot->xAxis2->setBasePen(QPen(Qt::white));
    ui->customplot->xAxis2->setTickPen(QPen(Qt::white));
    ui->customplot->xAxis2->grid()->setVisible(true);
    ui->customplot->xAxis2->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customplot->xAxis2->setTickLabelColor(Qt::white);
    ui->customplot->xAxis2->setLabelColor(Qt::white);
    ui->customplot->yAxis->setBasePen(QPen(Qt::white));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setLabelColor(Qt::white);
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customplot->xAxis->setVisible(false);
    ui->customplot->yAxis2->setVisible(false);
    ui->customplot->xAxis2->setTickLabelFont(QFont(QFont().family(), 10));
    ui->customplot->yAxis->setTickLabelFont(QFont(QFont().family(), 10));
    ui->customplot->xAxis2->setLabel("Schedule");
    ui->customplot->yAxis->setLabel("Spacecraft");
}

void MainWindow::updateCustomPlot()
{
    m_datetimeTicker->setTickOrigin(QDateTime::currentDateTime());
    ui->customplot->xAxis2->setRange(QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime()),
                                     QCPAxisTickerDateTime::dateTimeToKey(QDateTime::currentDateTime().addSecs(86400)));
    ui->customplot->replot();
}

void MainWindow::createBars()
{
    std::default_random_engine randomGenerator(std::time(0));
    std::uniform_int_distribution<int> value(0, 255);
    for(int i = 0; i < flight_names.size(); i++)
    {
        Bar* bar = new Bar(ui->customplot->yAxis, ui->customplot->xAxis2);
        bar->setBarName(flight_names[i]);
        bar->setArrivalTime(flight_arrival_times[i]);
        bar->setDepartureTime(flight_departure_times[i]);
        bar->setOrigin(flight_origins[i]);
        bar->setDestination(flight_destinations[i]);
        bar->setFlightNumber(flight_numbers[i]);
        bar->setFlightType(flight_types[i]);
        bar->setOvernight(flight_overnight[i]);
        qint32 r = value(randomGenerator);
        qint32 g = value(randomGenerator);
        qint32 b = value(randomGenerator);
        bar->setPen(QPen(QColor(r, g, b).lighter(200)));
        bar->setBrush(QColor(r, g, b));
        bar->setBaseValue(m_timingDataDeparture[i]);
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
        int departure_hrs = flight_departure_times[i].midRef(0, 2).toInt();
        int departure_mins = flight_departure_times[i].midRef(2, 2).toInt();
        int arrival_hrs = flight_arrival_times[i].midRef(0, 2).toInt();
        int arrival_mins = flight_arrival_times[i].midRef(2, 2).toInt();
        QDateTime dateTimebase(QDateTime::currentDateTime().date(), QTime(departure_hrs, departure_mins));
        m_timingDataDeparture[i] = QCPAxisTickerDateTime::dateTimeToKey(dateTimebase);
        QDateTime dateTimeFinal;
        if(flight_overnight[i] == "Yes")
        {
            dateTimeFinal = QDateTime(QDateTime::currentDateTime().addDays(1).date(), QTime(arrival_hrs, arrival_mins));
        }
        else
        {
            dateTimeFinal = QDateTime(QDateTime::currentDateTime().date(), QTime(arrival_hrs, arrival_mins));
        }
        m_timingDataArrival[i] = QCPAxisTickerDateTime::dateTimeToKey(dateTimeFinal) - m_timingDataDeparture[i];
    }
}

void MainWindow::initAxesAndTickers()
{
    m_datetimeTicker.reset(new QCPAxisTickerDateTime);
    m_datetimeTicker->setDateTimeFormat("d. MMM\nhh:mm:ss");
    m_datetimeTicker->setTickCount(10);
    ui->customplot->xAxis2->setTicker(m_datetimeTicker);
    ui->customplot->xAxis2->setVisible(true);
    ui->customplot->xAxis2->grid()->setSubGridVisible(true);
    m_textTicker.reset(new QCPAxisTickerText);
    m_textTicker->setTicks(m_ticks, flight_numbers);
    ui->customplot->yAxis->setTicker(m_textTicker);
}

void MainWindow::on_pushButton_clicked()
{

    QString filepath = QFileDialog::getOpenFileName(nullptr, "Choose a csv file", QString(),
                       QString("csv files(*.csv)"));

    if(filepath.isNull())
    {
        return;
    }

    QFile file(filepath);
    if ( !file.open(QFile::ReadOnly | QFile::Text) )
    {
        qDebug() << "File could not be opened";
    }
    else
    {

        QTextStream in(&file);
        while (!in.atEnd())
        {

            QString line = in.readLine();


                for (QString item : line.split(","))
                {
                    qDebug() << item;
                    parseFiles(item.toStdString());
                }
        }

        file.close();
    }
}

void MainWindow::parseFiles(std::string phrase)
{
    std::string str ("software");
    std::regex str_expr ("(soft)(.*)");

       if (regex_match (str,str_expr))
          qDebug() << "string:object => matched\n";

};
