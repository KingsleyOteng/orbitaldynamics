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



configuration_system::configuration_system()
{
    pimpl = new configuration_system();
}

configuration_system::~configuration_system()
{
    delete pimpl;
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
