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

tm* coordinate_transforms::
    setTimeConversionM(string date_phrase, string year)
{
    tm* tmepoch = new tm();
    
    int fract = 1;
    int month = 1;
    int year_int = std::stoi(year);
    int day_int;
    int hour_int;
    int min_int;
    int sec_int;
    
    std::string phrase;
    std::string hello;
    hello = date_phrase;
    
    boost::xpressive::sregex rex = boost::xpressive::sregex::compile( "(\\w+) (\\d+) @ (\\d+):(\\d+):(\\d+)\\.(\\d+) " );
    boost::xpressive::smatch what;
    
    if( regex_match( hello, what, rex ) )
    {
        // obtain number of days elapsed from the phrase
        phrase =  what[2];
        day_int = (stoi(phrase));
        
        // obtain hours from phrase
        phrase = what[3];
        hour_int = (stoi(phrase));
        
        // obtain minutes from phrase
        phrase = what[4];
        min_int = (stoi(phrase));
        
        // obtain seconds from phrase
        phrase = what[5];
        sec_int = (stoi(phrase));
        
        // add the mantissa to the seconds
        phrase = what[6];
        sec_int = sec_int + (stoi(phrase) / pow(10,phrase.size()));
        
        while (fract > 0)
           {
               day_int = day_int - days_in_month[month];
               if (day_int > days_in_month[month+1])
                   { fract = 0;}
               month++;
           }
        
        tmepoch->tm_year = 2000 + year_int - 1900;
        tmepoch->tm_mon = month - 2;
        tmepoch->tm_mday = day_int;
        tmepoch->tm_hour = hour_int;
        tmepoch->tm_min = min_int;
        tmepoch->tm_sec = sec_int;
    }
       
   
    return tmepoch;
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

// function reconstructs the calendar date and time broken down into its components
void coordinate_transforms::
    setUserPositionModel(double lat, double lon, double elev, double timet)
{
    double          theta;
    double          r;
    
    longitude       = lon;
    latitude        = lat;
    elevation       = elev;
    time_variable   = timet;
    
    
    // calculate the angle theta
    theta           = fMod(FunctionThetaGJD(time_variable) + longitude,twopi);
    
    // radius after accounting for sea level
    r = (earth_radius_equitorial + elevation)*cos(latitude);
    
    // coordinates after transformation
    x_coordinate = r*cos(theta);
    y_coordinate = r*sin(theta);
    z_coordinate = (earth_radius_equitorial + elevation)*sin(latitude);
}

double coordinate_transforms::
fMod(double a, double b)
{
    double quot;
    quot = (int) a / b;
    
    return (a - quot * b);
}

void coordinate_transforms::
getTropocentricCoordinates                      ()
{
    // We convert from ECI to look-angles by shifting to the tropocentric-horizon
    // In the tropocentric-horizon: (z-axis) must point north, (y-axis) must point east and the (x-axis) must point north
    // To achieve that we must first rotate through an angle phi (local sidereal time), about the z azis (Earth rotation axis)
    // and then through an angle gamma (the observer's latitude)
    double theta;
    
    // calculate the angle theta
    theta           = fMod(FunctionThetaGJD(time_variable) + longitude,twopi);
    
    
    range_sidereal = sin(theta)*cos(latitude)*x_range + sin(theta)*sin(latitude)*y_range - cos(theta)*z_range;
    range_earthrotation = -1 * sin(latitude)*x_range + cos(latitude)*y_range;
    range_theta = cos(theta)*cos(latitude)*x_range + cos(theta)*sin(latitude)*y_range + sin(theta)*z_range;
    
    viewing_range = sqrt(pow(range_sidereal,2.0) + pow(range_earthrotation,2.0) + pow(range_theta,2.0));
    viewing_elevation = asin(range_theta/viewing_range);
    
    // we use negative sign because he azimuth is determied clockwise from the North instead of counter-clockwise from the South
    viewing_azimuth = atan(-1*range_earthrotation/range_sidereal);
    if (range_sidereal > 0)     { viewing_azimuth = viewing_azimuth + pi_constant; }
    if (viewing_azimuth < 0)    { viewing_azimuth = viewing_azimuth + twopi; }
    
}

void coordinate_transforms::
getObserverRange                       ()
{
    // Note that the range vector generated here will be in ECI
    // A conversion from ECI to look-angles is required
    x_range = (x_coordinate - x_observer);
    y_range = (y_coordinate - y_observer);
    z_range = (z_coordinate - z_observer);
}

void coordinate_transforms::
getBenchMarking                         ()
{
    
    std::string         i,j;
    std::string         test_type;
    double              start,stop,dt;
    clock_t                time1,time2;
    
    time1 = clock();
    const clock_t begin_time = clock();
    
    for (int j=0; j<=9; j++)
    {
        int a = 1;
        for (int k=1; k<=2499; k++)
        {
            a = tan(atan(exp(log(sqrt(a*a))))) + 1;
        }
    }
    
    time2 = clock();
    
    cout << "hello time elapse" << '\n';
    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << '\n';
}


