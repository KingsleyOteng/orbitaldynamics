
#include "coordinate_transforms.hpp"

using namespace std;

#define Re              6378.1370               // the earths radius; from Kelso
#define we              0.00007.29211510        // Earth's rotation rate in radians/second; from Kelso


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
void coordinate_transforms::setGMST
    (double latitude_box1, double longitude_box1, double elevation)
{
        double R;
    
        R = (Re + elevation) * cos(latitude_box1);
    
        // refer to Kelso https://www.celestrak.com/columns/v02n02/
        z_coordinate = ((Re+elevation) * sin(latitude_box1));
        y_coordinate = R * sin(longitude_box1);
        x_coordinate = R * cos(longitude_box1);
    
}

void coordinate_transforms::setTimeElapsedSinceJDIndex
    (double date_du)
{
    universal_time_tu = (date_du - 2451545.0) / 36525;
}

// calculates the Greenwich sidereal time at midnight
void coordinate_transforms::setGST
    (double date_Tu)
{
    // calculate the gst
    gst = 24110.54841 + (8640184.812866*date_Tu) + (0.093104*date_Tu*date_Tu) - (0.0000062*date_Tu*date_Tu*date_Tu);
}

// calculates the Greenwich mean sidereal time at midnight
void coordinate_transforms::setGMST
    ()
{
    // calculate the gmst
    gmst = gst + we * utc_time;
}
