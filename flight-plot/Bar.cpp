// qt
#include <QToolTip>

// local
#include "Bar.h"



Bar::Bar(QCPAxis* horizontal, QCPAxis* vertical) :
    QCPBars(horizontal, vertical)
{
}

void Bar::setBarName(const QString& name)
{
    m_barName = name;
}

void Bar::setOrigin(const QString& origin)
{
    m_origin = origin;
}

void Bar::mousePressEvent(QMouseEvent* event, const QVariant& details)
{
    // call base class function
    QCPBars::mousePressEvent(event, details);

    // show tool tip on mouse press event
    // modify your custom message here
    QString text = m_flightNumber + "\n" +
                   m_barName + "\n" +
                   "Origin: " + m_origin + "\n" +
                   "Destination: " + m_destination + "\n"
                   "Departure: " + m_departureTime + "\n" +
                   "Arrival: " + m_arrivalTime + "\n" +
                   "Flight type: " + m_flightType + "\n" +
                   "Is Overnight: " + m_overnight;

    QToolTip::showText(event->globalPos(), text);
}

QString Bar::flightType() const
{
    return m_flightType;
}

void Bar::setFlightType(const QString& flightType)
{
    m_flightType = flightType;
}

void Bar::setDestination(const QString& destination)
{
    m_destination = destination;
}

void Bar::setDepartureTime(const QString& departureTime)
{
    m_departureTime = departureTime;
}

void Bar::setArrivalTime(const QString& arrivalTime)
{
    m_arrivalTime = arrivalTime;
}

void Bar::setOvernight(const QString& status)
{
    m_overnight = status;
}

QString Bar::flightNumber() const
{
    return m_flightNumber;
}

void Bar::setFlightNumber(const QString& flightNumber)
{
    m_flightNumber = flightNumber;
}

const QString& Bar::overnight() const
{
    return m_overnight;
}

const QString& Bar::arrivalTime() const
{
    return m_arrivalTime;
}

const QString& Bar::departureTime() const
{
    return m_departureTime;
}

const QString& Bar::destination() const
{
    return m_destination;
}

const QString& Bar::origin() const
{
    return m_origin;
}

const QString& Bar::barName() const
{
    return m_barName;
}
