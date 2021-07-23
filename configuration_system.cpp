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
{}

configuration_system::~configuration_system()
{}

double  configuration_system::getLocationLongitude
() {return 0;};

void getSensor
() {};

double configuration_system::getLocationHeight
() {
    sensor_location_longitude = 0;
    return 0;};

int configuration_system::getMonth
() { return 0;};

int configuration_system::getSunRise
() { return 0;};

int configuration_system::getSunSet
() { return 0;};
