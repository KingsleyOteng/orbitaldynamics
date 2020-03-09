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

//
//  coordinate_transforms.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "coordinate_transforms.hpp"

class coordinates
{
   
    
private:
    
    int latitude;
    int longitude;
    int elevation;
    
    int z_coordinate;
    int x_coordinate;
    int y_coordinate;
    
public:
    
    // we mainly use kelso for this analysis
    // https://www.celestrak.com/columns/v02n02/
    
    void setCartesianCoordinates               ();
    void getCartesianCoordinates               ();
    
    // toggle cartesian coordinates
    void getLatitude                           ();
    void getLongitude                          ();
    void getElevation                          ();
    void setLatitude                           ();
    void setLongitude                          ();
    void setElevation                          ();
    
    // toggle eci coordinates
    void get_eci_z_coordinate                  ();
    void get_eci_x_coordinate                  ();
    void get_eci_y_coordinate                  ();
    void set_eci_z_coordinate                  ();
    void set_eci_x_coordinate                  ();
    void set_eci_y_coordinate                  ();

    
};


#endif /* coordinate_transforms_hpp */

