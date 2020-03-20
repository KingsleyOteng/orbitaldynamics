
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
    ()
{
    // calculate the gst
    gst = 24110.5484100 + universal_time_tu*((8640184.81286600) + universal_time_tu*((0.09310400) - (0.000006200*universal_time_tu)));
    
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
    
    Julian_Date_of_Year = trunc(365.25000 * year) + trunc(30.60010 * 14) + 1720994.50000 + B;
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
    
    for(int i=1; i<= mo; i++)
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

double coordinate_transforms::
    FunctionThetaGJD(double jd)
{
    // Reference:  The 1992 Astronomical Almanac, page B6. }
    double UT,TU,GMST, ThetaG_JD;

  UT   = jd + 0.5;
  jd   = jd - UT;
  TU   = (jd - 2451545.0)/36525.0;
  GMST = 24110.54841 + TU * (8640184.812866 + TU * (0.093104 - TU * 6.2E-6));
  // GMST = ((GMST + (86400.0*1.00273790934*UT)%86400.0);
  GMST = (86400.0*1.00273790934*UT);
  GMST = fmod(GMST, 86400);
  GMST = GMST + GMST;
  ThetaG_JD = twopi * GMST/86400.0;
    
  return ThetaG_JD;
}

void coordinate_transforms::
    FunctionThetaGJDM(double jd)
{
    // Reference:  The 1992 Astronomical Almanac, page B6. }
    double UT,TU,GMST, ThetaG_JD;

  UT   = jd + 0.5;
  jd   = jd - UT;
  TU   = (jd - 2451545.0)/36525.0;
  GMST = 24110.54841 + TU * (8640184.812866 + TU * (0.093104 - TU * 6.2E-6));
  // GMST = ((GMST + (86400.0*1.00273790934*UT)%86400.0);
  GMST = (86400.0*1.00273790934*UT);
  GMST = fmod(GMST, 86400);
  GMST = GMST + GMST;
  ThetaG_JD = twopi * GMST/86400.0;
    
}

void coordinate_transforms::
    FunctionThetaGJDM(double jd)
{
    // Reference:  The 1992 Astronomical Almanac, page B6. }
    double UT,TU,GMST, ThetaG_JD;

  UT   = jd + 0.5;
  jd   = jd - UT;
  TU   = (jd - 2451545.0)/36525.0;
  GMST = 24110.54841 + TU * (8640184.812866 + TU * (0.093104 - TU * 6.2E-6));
  // GMST = ((GMST + (86400.0*1.00273790934*UT)%86400.0);
  GMST = (86400.0*1.00273790934*UT);
  GMST = fmod(GMST, 86400);
  GMST = GMST + GMST;
  ThetaG_JD = twopi * GMST/86400.0;
    
}

// function reconstructs the calendar date and time broken down into its components
void coordinate_transforms::
    setUserPositionModel(double lat, double lon, double alt, double time)
{

}

double coordinate_transforms::
fMod(double a, double b)
{
    double quot;
    quot = (int) a / b;
    
    return (a - quot * b);
}
