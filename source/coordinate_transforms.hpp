//
//  coordinate_transforms.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef coordinate_transforms_hpp
#define coordinate_transforms_hpp

#include <stdio.h>
#include <math.h>

//
//  coordinate_transforms.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "coordinate_transforms.hpp"

class coordinate_transforms
{
   
    
private:
    
    double latitude;
    double longitude;
    double elevation;
    
    double z_coordinate;
    double x_coordinate;
    double y_coordinate;
    
    double gst;
    double gmst;
    double utc;
    
    double universal_time_tu;
    double universal_time_du;
    
public:
    
    // we mainly use kelso for this analysis
    // https://www.celestrak.com/columns/v02n02/
    // https://www.latlong.net/lat-long-dms.html
    
    void setCartesianCoordinates               (double latitude_box1, double longitude_box1, double elevation);
    void getCartesianCoordinates               ();
    
    // toggle cartesian coordinates
    void getLatitude                           ();
    void getLongitude                          ();
    void getElevation                          ();
    void setLatitude                           ();
    void setLongitude                          ();
    void setElevation                          ();
    void setGST                                ();
    
    // toggle eci coordinates
    void get_eci_z_coordinate                  ();
    void get_eci_x_coordinate                  ();
    void get_eci_y_coordinate                  ();
    void set_eci_z_coordinate                  ();
    void set_eci_x_coordinate                  ();
    void set_eci_y_coordinate                  ();

    
};


#endif /* coordinate_transforms_hpp */

