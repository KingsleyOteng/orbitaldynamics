//      Source
//      implementation of a sensor model for the orbital software
//
//
//      Created by Kwadwo Oteng-Amoko on 31/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// preprocessor instructions
#include "sensor.hpp"
#include "orbital.hpp"


//susing namespace std;

// constructor
sensor::sensor()
    {};

// destructor
sensor::~sensor()
    {};




// get methods


// sensor methods
void
    sensor::SetJulianEpochDate(double epoch)
{
    m_sensor_epoch = epoch;
};

void
    sensor::SetJulianEpochDate(int YY, int MM, int DD)
{
   
};

void
    sensor::SetMSensorLocationLatitude     (double latitude_location)
    {   m_sensor_latitude = latitude_location; }

void
    sensor::SetMSensorLocationLongitude    (double longitude_location)
    {   m_sensor_longitude = longitude_location; }

void
    sensor::SetMSensorRange                (double range)
    {   m_sensor_range = range; }

void
    sensor::SetMSensorMinAzimuthSector     (double minAzimuth)
    {   m_sensor_min_azimuth = minAzimuth; }

void
sensor::SetMSensorMaxAzimuthSector         (double maxAzimuth)
    {   m_sensor_max_azimuth = maxAzimuth; }

double
    sensor::GetMSensorLocationLatitude     (double latitude_location)
    { return m_sensor_latitude; }

double
    sensor::GetMSensorLocationLongitude    (double longitude_location)
    { return m_sensor_longitude; }

double
    sensor::GetMSensorElevation            (double elevation)
    { return m_sensor_elevation; }

double
    sensor::GetMSensorRange                (double range)
    { return m_sensor_range; }

double
    sensor::GetMSensorMinAzimuthSector     (double minAzimuth)
    { return m_sensor_min_azimuth; }

double
    sensor::GetMSensorMaxAzimuthSector     (double maxAzimuth)
    { return m_sensor_max_azimuth; }

// object methods
void
    sensor::set_m_object_position          (double m_position_vector, double vector_propogation)
    {}

void
    sensor::set_m_object_velocity          (double m_velocity_vector, double vector_propogation)
    {}

void
    sensor::set_m_object_acceleration       (double m_acceleration_vector, double vector_propogation)
    {}

void
    sensor::set_m_object_time               (double m_time_vector, double vector_propogation)
    {}

void
    sensor::set_m_prediction_azimuth        (double m_azimuth_vector, double vector_propogation)
    {}

void
    sensor::set_m_prediction_elevation      (double m_elevation_vector, double vector_propogation)
    {}

void
    sensor::set_m_prediction_distance       (double m_distance_vector, double vector_propogation)
    {}

double
    sensor::get_m_object_position           ()
    {   return m_position; }

double
    sensor::get_m_object_velocity           ()
    {   return m_velocity;}

double
    sensor::get_m_object_acceleration       ()
    {   return m_acceleration; }

double
    sensor::get_m_object_time               ()
    {   return m_time; }

double
    sensor::get_m_prediction_azimuth        ()
    {   return m_azimuth; }

double
    sensor::get_m_prediction_elevation      ()
    {   return m_elevation; }

double
    sensor::get_m_prediction_distance       ()
    {   return m_distance;  }
