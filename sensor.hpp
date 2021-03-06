//      Headers
//      Implementation of a sensor model
//      
//
//      Created by Kwadwo Oteng-Amoko on 31/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// header guards
#ifndef sensor_hpp
#define sensor_hpp

// class definitions
class sensor{
    
   
    
private:
    
    
    // constructors and destructors
    sensor();
   ~sensor();
    
    
    // members
    double      m_sensor_epoch;
    int         m_epoch_julian_date;
    
    // sensor specific parameters
    double      m_sensor_latitude;
    double      m_sensor_longitude;
    double      m_sensor_elevation;
    double      m_sensor_range;
    double      m_sensor_min_azimuth;
    double      m_sensor_max_azimuth;
    
    // object predicted parameters
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
    void        SetJulianEpochDate             (double epoch);
    void        SetJulianEpochDate             (int YY, int MM, int DD);
    
    // sensor methods
    void        SetMSensorLocationLatitude     (double latitude_location);
    void        SetMSensorLocationLongitude    (double longitude_location);
    void        SetMSensorElevation            (double elevation);
    void        SetMSensorRange                (double range);
    void        SetMSensorMinAzimuthSector     (double maxAzimuth);
    void        SetMSensorMaxAzimuthSector     (double maxAzimuth);
    
    double      GetMSensorLocationLatitude     (double latitude_location);
    double      GetMSensorLocationLongitude    (double longitude_location);
    double      GetMSensorElevation            (double elevation);
    double      GetMSensorRange                (double range);
    double      GetMSensorMinAzimuthSector     (double minAzimuth);
    double      GetMSensorMaxAzimuthSector     (double maxAzimuth);
    
    // object methods
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
