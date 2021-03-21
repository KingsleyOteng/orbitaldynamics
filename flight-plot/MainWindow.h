#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// qt
#include <QMainWindow>

// local
#include "Bar.h"
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

// frequency value should always be in milliseconds
// 10000 milliseconds = 10 seconds
// modify this value to update
// your GUI plot as desired
#define UPDATE_FREQUENCY_MS 10000

// these are the hardcoded properties for all the flights
// number of bars on the plot depends on how many flights are in flight_names vector
// all the vectors must have equal sizes at all times
// adding or removing details must be done for all the vectors
// for e.g. adding a new flight must also have flight name, flight_origins and so on..
// VECTOR SIZES MUST REMAIN THE SAME ALL THE TIME
namespace
{
    const QVector<QString> flight_numbers = { "AA123", "KA456", "GA789", "AZ1011", "MA1213", "LX205", "IA147", "EK056", "LU1988"};
    const QVector<QString> flight_names = { "Air America", "Kenyan Air", "Garuda Airlines", "Air Zimbabwe",
                                            "Mexican Airlines", "Swiss", "Air India", "Emirates", "Lufthansa"
                                          };

    const QVector<QString> flight_origins = { "San Francisco, USA", "Mombasa, Kenyan", "Jakarta, Indonesia",
                                              "London UK", "Mexico City", "Zurich, Switzerland", "Mumbai, India",
                                              "Dubai, UAE", "Munich, Germany"
                                            };
    const QVector<QString> flight_destinations = { "New York, USA", "Cairo, Egypt", "Bali, Indonesia",
                                                   "Dublin, Ireland", "Ontario, Canada", "Berlin, Germany",
                                                   "Sydney, Australia", "Moscow, Russia", "Doha, Qatar"
                                                 };
    const QVector<QString> flight_overnight = { "No", "Yes", "No", "No", "No", "Yes", "No", "No", "Yes" };
    const QVector<QString> flight_departure_times = { "2200", "1835", "1448", "1510", "1435", "2320", "1653", "1940", "2107" };
    const QVector<QString> flight_arrival_times = { "2345", "2132", "1824", "2148", "1901", "0554", "1847", "2310", "2356" };
    const QVector<QString> flight_types = { "A220", "A380-800", "B777", "A320", "B747", "A380-800", "A310-300F", "E767-300", "C137" };
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:

        /**
         * @brief Constructor
         * @param parent
         */
        MainWindow(QWidget* parent = nullptr);

        /**
         * @brief Destructor
         */
        ~MainWindow();

    private slots:

        /**
         * @brief so this updates the plot when timer timeout signal is emitted
         */
        void updateCustomPlot();

        /**
         * @brief so this loads CSV file
         */
        void on_pushButton_clicked();

    private:

        // UI
        Ui::MainWindow* ui;

        /**
         * @brief designs how the plot looks
         */
        void setPlotAppearance();

        /**
         * @brief createBars
         */
        void createBars();

        /**
         * @brief prepareData
         */
        void prepareData();

        /**
         * @brief initAxesAndTickers
         */
        void initAxesAndTickers();

        /**
         * @brief Properties
         */
        QTimer* m_timer;
        QVector<double> m_ticks;
        QVector<uint64_t> m_timingDataDeparture;
        QVector<uint64_t> m_timingDataArrival;
        QSharedPointer<QCPAxisTickerDateTime> m_datetimeTicker;
        QSharedPointer<QCPAxisTickerText> m_textTicker;
        QVector<Bar*> m_bars;
};
#endif // MAINWINDOW_H
