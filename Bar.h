#ifndef BAR_H
#define BAR_H

// local
#include "qcustomplot.h"



class Bar : public QCPBars
{
    public:

        /**
         * @brief Bar constructor
         * @param horizontal
         * @param vertical
         */
        Bar(QCPAxis* horizontal, QCPAxis* vertical);

        /**
         * @brief Setters
         */
        void setBarName(const QString& name);
        void setOrigin(const QString& origin);
        void setDestination(const QString& destination);
        void setDepartureTime(const QString& departureTime);
        void setArrivalTime(const QString& arrivalTime);
        void setOvernight(const QString& status);
        void setFlightNumber(const QString& flightNumber);
        void setFlightType(const QString& flightType);

        /**
         * @brief Getters
         */
        const QString& barName() const;
        const QString& origin() const;
        const QString& destination() const;
        const QString& departureTime() const;
        const QString& arrivalTime() const;
        const QString& overnight() const;
        QString flightNumber() const;
        QString flightType() const;

    protected:

        /**
         * @brief mousePressEvent
         * @param event
         * @param details
         */
        virtual void mousePressEvent(QMouseEvent* event, const QVariant& details) override;

    private:

        /**
         * @brief Bar properties
         */
        QString m_barName;
        QString m_origin;
        QString m_destination;
        QString m_departureTime;
        QString m_arrivalTime;
        QString m_overnight;
        QString m_flightNumber;
        QString m_flightType;
};

#endif // BAR_H
