//
//  coordinate_transforms.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef coordinate_transforms_hpp
#define coordinate_transforms_hpp

#include <iostream>
#include <boost/xpressive/xpressive.hpp>

using namespace std;
//
//  coordinate_transforms.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

//#include "coordinate_transforms.hpp"

class coordinate_transforms
{
   
    
private:
    
    #define twopi                       6.28318530718
    #define pi_constant  3.1415
    #define earth_radius_equitorial     6378.137
    
    int days_in_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    
    double latitude;
    double longitude;
    double elevation;
    
    double z_coordinate;
    double x_coordinate;
    double y_coordinate;
    
    double z_observer;
    double x_observer;
    double y_observer;
    
    double z_range;
    double x_range;
    double y_range;
    
    // eci coordinates
    double range_sidereal;
    double range_earthrotation;
    double range_theta;
    
    // viewing coordinates
    double viewing_range;
    double viewing_elevation;
    double viewing_azimuth;
    
    double gst;
    
    double time_variable;
    double utc;
    double utc_time;
    double Julian_Date_of_Year;
    double Julian_Date_Day;
    double Julian_Fraction_Of_Day;
    double Julian_Date;
    
    double  m_julian_date_epoch;
    double  m_epoch_julian_date_fraction;
    int     m_epoch_gregorian_day_of_year;
    int     m_epoch_greogorian_hour;
    int     m_epoch_gregorian_minute;
    int     m_epoch_gregorian_second;
    int     m_epoch_gregorian_splits;
    int     m_fraction_of_day;

    
    double universal_time_tu;
    double universal_time_du;
    double ThetaG_JD;
    
public:
    coordinate_transforms();
    ~coordinate_transforms();
    
    double gmst;
    
    // we mainly use kelso for this analysis
    // https://www.celestrak.com/columns/v02n02/
    // https://www.latlong.net/lat-long-dms.html
    
    void setCartesianCoordinates               (double latitude_box1, double longitude_box1, double elevation);
    void getCartesianCoordinates               ();
    
    // toggle cartesian coordinates
    void    getLatitude                           ();
    void    getLongitude                          ();
    void    getElevation                          ();
    void    setLatitude                           ();
    void    setLongitude                          ();
    void    setElevation                          ();
    void    setGST                                ();
    void    setGMST                               ();
    void    setCoordinates                        (double latitude_box1, double longitude_box1, double elevation);
    void    setEpoch                              (double epoch);
    void    setJulianDate                         (time_t yr_mo_dd);
    void    setJulianDateDay                      (time_t yr_mo_dd);
    void    setJulianDateFractionOfDay            (time_t yr_mo_dd);
    void    setJulianDateYear                     (time_t yr_mo_dd);
    void    setTimeElapsedSinceJDIndex            (double date_du);
    double  fMod                                  (double a, double b);
    double  FunctionThetaGJD                      (double jd);
    void    FunctionThetaGJDM                     (double jd);
    
    
    // toggle eci coordinates
    void    get_eci_z_coordinate                  ();
    void    get_eci_x_coordinate                  ();
    void    get_eci_y_coordinate                  ();
    void    set_eci_z_coordinate                  ();
    void    set_eci_x_coordinate                  ();
    void    set_eci_y_coordinate                  ();
    

    tm* setTimeConversionM                      (std::string date, std::string year);
    void setUserPositionModel                   (double lat, double lon, double elev, double timet);
    void getObserverRange                       ();
    void getTropocentricCoordinates             ();
    int  getJulianDateFractionOfDay             ();
    double getPolarRadius                       ();
    double getGeocentricLatitude                (double geodeticLatitude, double a, double b);
    double getElapsedTime                       (double jd_epoch, double jd_now);
    double getTLEDateTimeFormat                 ();
    double getTLEDayFormat                      ();
};


#endif /* coordinate_transforms_hpp */
