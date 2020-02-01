//
//  sensor.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 31/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef sensor_hpp
#define sensor_hpp

#include <stdio.h>
#include <string>
#include <vector>


class sensor{
    

private:
    
    double m_object_position;
    double m_object_velocity;
    double m_object_acceleration;
    double m_object_time;
    
    double m_prediction_azimuth;
    double m_prediction_elevation;
    double m_prediction_distance;
    
public:
    
    void set_m_object_position();
    void set_m_object_velocity();
    void set_m_object_acceleration();
    void set_m_object_time();
    void set_m_prediction_azimuth();
    void set_m_prediction_elevation();
    void set_m_prediction_distance();
    
    void get_m_object_position();
    void get_m_object_velocity();
    void get_m_object_acceleration();
    void get_m_object_time();
    void get_m_prediction_azimuth();
    void get_m_prediction_elevation();
    void get_m_prediction_distance();
    
};


#endif /* orbital_hpp */
