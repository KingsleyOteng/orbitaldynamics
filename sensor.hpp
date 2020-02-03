//
//      Implementation of a sensor model
//      
//
//      Created by Kwadwo Oteng-Amoko on 31/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef sensor_hpp
#define sensor_hpp

#include <stdio.h>
#include <string>
#include <vector>


class sensor{
    
   
    
private:
    
    
    // constructors and destructors
    sensor();
   ~sensor();
    
    
    // members
    // sensor predicted parameters
    double      m_object_position;
    double      m_object_velocity;
    double      m_object_acceleration;
    double      m_object_time;
    
    // sensor positining
    double      m_prediction_azimuth;
    double      m_prediction_elevation;
    double      m_prediction_distance;
    
    // object tracking
    double      m_position;
    double      m_velocity;
    double      m_acceleration;
    double      m_time;
    double      m_azimuth;
    double      m_elevation;
    double      m_distance;
    
    
public:
    
    
    // getters and setters
    // setter methods
    void        set_m_object_position          (double m_position_vector, double vector_propogation);
    void        set_m_object_velocity          (double m_velocity_vector, double vector_propogation);
    void        set_m_object_acceleration      (double m_acceleration_vector, double vector_propogation);
    void        set_m_object_time              (double m_time_vector, double vector_propogation);
    void        set_m_prediction_azimuth       (double m_azimuth_vector, double vector_propogation);
    void        set_m_prediction_elevation     (double m_elevation_vector, double vector_propogation);
    void        set_m_prediction_distance      (double m_distance_vector, double vector_propogation);
    
    // getter methods
    double      get_m_object_position          ();
    double      get_m_object_velocity          ();
    double      get_m_object_acceleration      ();
    double      get_m_object_time              ();
    double      get_m_prediction_azimuth       ();
    double      get_m_prediction_elevation     ();
    double      get_m_prediction_distance      ();
    
    
};


#endif /* orbital_hpp */
