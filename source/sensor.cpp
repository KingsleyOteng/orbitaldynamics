//
//      implementation of a sensor model for the orbital software
//
//
//      Created by Kwadwo Oteng-Amoko on 31/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sensor.hpp"
#include "orbital.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// constructor
sensor::sensor()
    {};

// destructor
sensor::~sensor()
    {};

// methods
void
    sensor::set_m_object_position          (double m_position_vector, double vector_propogation)
    {}

void
    sensor::set_m_object_velocity          (double m_velocity_vector, double vector_propogation)
    {}

void
    sensor::set_m_object_acceleration      (double m_acceleration_vector, double vector_propogation)
    {}

void
    sensor::set_m_object_time              (double m_time_vector, double vector_propogation)
    {}

void
    sensor::set_m_prediction_azimuth       (double m_azimuth_vector, double vector_propogation)
    {}

void
    sensor::set_m_prediction_elevation     (double m_elevation_vector, double vector_propogation)
    {}

void
    sensor::set_m_prediction_distance      (double m_distance_vector, double vector_propogation)
    {}

double
    sensor::get_m_object_position        ()
    {   return m_position; }

double
    sensor::get_m_object_velocity        ()
    {   return m_velocity;}

double
    sensor::get_m_object_acceleration    ()
    {   return m_acceleration; }

double
    sensor::get_m_object_time            ()
    {   return m_time; }

double
    sensor::get_m_prediction_azimuth     ()
    {   return m_azimuth; }

double
    sensor::get_m_prediction_elevation   ()
    {   return m_elevation; }

double
    sensor::get_m_prediction_distance    ()
    {   return m_distance;  }
