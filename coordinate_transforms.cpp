
#include "coordinate_transforms.hpp"

using namespace std;

#define Re              6378.1370               // the earths radius; from Kelso
#define we              0.0000729211510        // Earth's rotation rate in radians/second; from Kelso


// methods
// perform coordinate transforms
void coordinate_transforms::setCartesianCoordinates
    (double latitude_box1, double longitude_box1, double elevation)
{
        double R;
    
        R = (Re + elevation) * cos(latitude_box1);
    
        // refer to Kelso https://www.celestrak.com/columns/v02n02/
        z_coordinate = ((Re+elevation) * sin(latitude_box1));
        y_coordinate = R * sin(longitude_box1);
        x_coordinate = R * cos(longitude_box1);
    
}

// perform coordinate side real transforms
void coordinate_transforms::setCoordinates
    (double latitude_box1, double longitude_box1, double elevation)
{
        double R;
    
        R = (Re + elevation) * cos(latitude_box1);
    
        // refer to Kelso https://www.celestrak.com/columns/v02n02/
        z_coordinate = ((Re+elevation) * sin(latitude_box1));
        y_coordinate = R * sin(longitude_box1);
        x_coordinate = R * cos(longitude_box1);
    
}

void coordinate_transforms::
    setTimeElapsedSinceJDIndex
    (double date_du)
{
    universal_time_tu = (date_du - 2451545.0) / 36525;
}

// calculates the Greenwich sidereal time at midnight
void coordinate_transforms::
    setGST
    (double date_Tu)
{
    // calculate the gst
    gst = 24110.54841 + (date_Tu*8640184.812866) + (date_Tu*date_Tu*0.093104) - (0.0000062*date_Tu*date_Tu*date_Tu);
    
}

// calculates the Greenwich mean sidereal time at midnight
void coordinate_transforms::
    setGMST
    ()
{
    utc_time = 0;
    // calculate the gmst
    gmst = gst + we * utc_time;
}

// calculates the JD elapsed
void coordinate_transforms::
    setJulianDateYear
    (time_t yr_mo_dd)
{
    //int current_year;
    int year;
    double A;
    double B;
    
    tm *epoch_time = localtime(&yr_mo_dd);
    
    year = (1900 + epoch_time->tm_year) - 1;
    A = trunc(year/100);
    B = 2 - A + trunc(A/4);
    
    Julian_Date_of_Year = trunc(365.25 * year) + trunc(30.6001 * 14) + 1720994.5 + B;
}

void coordinate_transforms::
    setJulianDateDay
    (time_t yr_mo_dd)
{
    int day;
    int yr;
    int mo;
    int dy;
    
    tm *epoch_time = localtime(&yr_mo_dd);
    
    // get date data
    yr = epoch_time->tm_year;
    mo = epoch_time->tm_mon;
    dy = epoch_time->tm_mday;
    
    day = 0;
    
    // get length of the particular integer array
    int length = sizeof(days_in_month) / sizeof(int);
    
    for(int i=1; i<= length; i++)
        {
            day = day + days_in_month[i];
        }
    
    day = day + dy;
    
    if (((yr % 4) == 0) && (((yr % 100) != 0) || ((yr % 400) == 0)) && (mo > 2))
        {
            day = day + 1;
        }
    
    Julian_Date_Day = day;
}

void coordinate_transforms::
    setJulianDate
    (time_t yr_mo_dd)
{
    setJulianDateDay(yr_mo_dd);
    setJulianDateYear(yr_mo_dd);
    
    Julian_Date = Julian_Date_of_Year + Julian_Date_Day;
    
}

tm* coordinate_transforms::
    setTimeConversion(string date, string year)
{
    tm* tmepoch;
    
    tmepoch->tm_year = 2000 + std::stoi(date) - 1900;
    tmepoch->tm_mon = 1 - 1;
    tmepoch->tm_mday = 1;
    tmepoch->tm_hour = 0;
    tmepoch->tm_min = 0;
    tmepoch->tm_sec = 0;
    
    return tmepoch;
}
