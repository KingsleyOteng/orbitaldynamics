//
//  configuration_systems.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 29/05/2021.
//  Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
//
//

// header guards
//#ifndef newtownm_hpp
//#define newtownm_hpp
// these file will assign all the presets (July / 2021)

// preprocessor instructions
#include <cmath>

// class method defintions
class configuration_system
{
    
private:
    
   // macro defining array size
    #define         numiter                    50
    #define         small                      256

    
  // members
    
    double sensor_location_latitude;
    double sensor_location_longitude;
    double sensor_height;
    double sensor_type;
    double sunrise_time;
    double sunset_time;
    

    // this function solves keplers equation when the true anomaly is known.
    // the mean and eccentric, parabolic, or hyperbolic anomaly is also found.
    // the parabolic limit at 168 is arbitrary
    
    void setLocationLatitude
        (double ecc);
    
    void setLocationLongitude
        (double ecc);
    
    void setLocationHeight
    (double ecc, double m);
  
};

#endif /* newtownm_hpp */
