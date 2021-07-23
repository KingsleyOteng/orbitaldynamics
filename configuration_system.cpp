//
//  configuration_systems.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020,2021 Kwadwo Oteng-Amoko. All rights reserved.
//

// header guards
//#ifndef configuration_systems_hpp
//#define configuration_systems_hpp

#include "configuration_system.hpp"

class configuration_system_impl
{
    public:
        configuration_system_impl();
        double  getLocationLongitude();
        double  getLocationHeight();
        int     getMonth();
        void    getSensor();
        int     getSunSet();
        int     getSunRise();

    private:
        // whatever members you actually need
}

double  getLocationLongitude
() {return 0;};

void getSensor
() {};

double getLocationHeight
() {return configuration_system.sensor_location_longitude;};

int getMonth
() { return 0;};

int getSunRise
() { return 0;};

int getSunSet
() { return 0;};
