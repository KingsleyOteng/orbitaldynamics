//      Overview: Extraction of object tracking data from NORAD TLE
//
//      Created by Kwadwo Oteng-Amoko on 14/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// header guards
#ifndef orbital_hpp
#define orbital_hpp

// api references
#include <boost/functional/hash.hpp>

// class method declarations
class orbital
{
    
   
    
private:
    
    // macro defining array size
    #define ARRAY_SIZE_DOUBLE 100
    #define ARRAY_SIZE 50
    #define ARRAY_SIZE_ONE 5
    
    
    // observer and satellite coordinates
    double z_coordinate;
    double x_coordinate;
    double y_coordinate;
    
    double model_z_observer;
    double model_x_observer;
    double model_y_observer;
    
    // members
    double      m_sensor_epoch;
    std::string m_file_name;
    char        m_tle_name                          [ARRAY_SIZE];
    char        m_tle_url                           [ARRAY_SIZE];
    char        m_tle_line_one                      [ARRAY_SIZE_DOUBLE];
    char        m_tle_line_two                      [ARRAY_SIZE_DOUBLE];
    char        m_id                                [ARRAY_SIZE];
    std::vector<std::
    string>     parsed_line_one_a;
    std::vector<std::
    string>     parsed_line_two_a;
    int         m_satellite_number;
    char        m_classification                    [ARRAY_SIZE_ONE];
    int         m_designator_launch_year;
    int         m_designator_launch_number_of_year;
    char        m_designator_piece_of_launch        [ARRAY_SIZE_ONE];
    int         m_epoch_year;
    double      m_julian_date_fraction;
    double      m_ballistic_coefficient;
    char        m_second_derivative_of_motion       [ARRAY_SIZE];
    char        m_drag_term_or_radition_coefficient [ARRAY_SIZE];
    int         m_ephemeris_type;
    int         m_element_number;
    int         m_check_sum;
    int         m_satellite_number_2;
    double      m_satellite_inclination;
    double      m_satellite_ascension_node;
    double      m_satellite_eccentricity_coefficient;
    double      m_argument_perigree;
    double      m_mean_anomaly;
    double      m_mean_motion;
    double      m_epoch_checksum;
    int         m_lineone_checksum;
    int         m_linetwo_checksum;
    
    double      m_launch_date_jd;
    double      m_number_of_revoltions_elapsed;
    double      m_deg_solar_per_day;
    std::string m_wgs;                          //supports wgs-72, wgs-72-low-precision, wgs-84
    
    int         m_year;
    int         m_month;
    int         m_day;
    int         m_epoch_julian_date;
    
    
public:
    
    // constants
    #define ARRAY_SIZE_ONE  1
    #define Re              6378.1370
    
    // constructor and destructors
    orbital();
    orbital(int year, int month, int day);
    orbital(double x_observer, double y_observer, double z_observer);
    orbital(double x_observer, double y_observer, double z_observer, std::string wgs_model);
   ~orbital();
    
    
    // getters and setters
    // setters
    void        SetEpochDate                    (double epoch);
    void        SetCurrentEpoch                 (int year, int month, int day);
    void        SetDate                         (int year, int month, int day);
    void        SetTLEname                      (std::string name);
    void        SetSATnumber                    (int number);
    void        SetCLASSIFIERfield              (std::string id);
    void        SetLAUNCHERyearfield            (int field);
    void        SetLAUNCHERnumberfield          (int field);
    void        SetLAUNCHpiecedesignator        (char designator [ARRAY_SIZE_ONE]);
    void        SetEPOCHyear                    (int year);
    void        SetJULIANdatefraction           (double fraction);
    void        SetBALLISTICcoefficient         (double coefficient);
    void        SetSECONDderivativemotion       (std::string motion);
    void        SetDRAGRADIATIONcoefficient     (std::string coefficient);
    void        SetEPHEMERIStype                (int type);
    void        SetELEMENTnumber                (int number);
    void        SetCHECKsum                     (int sum);
    void        SetCHECKsumtwo                  (int sum);
    void        SetSATNUMBERline2               (int number);
    void        SetTLElineone                   (std::string phrase);
    void        SetTLElinetwo                   (std::string phrase);
    void        SetINCLINATIONfield             (double field);
    void        SetRIGHTASCENTIONnode           (double node);
    void        SetECCENTRICITYcoefficient      (double coefficient);
    void        SetARGUMENTperigree             (double perigree);
    void        SetMEANanomlay                  (double anomaly);
    void        SetMEANmotion                   (double motion);
    void        SetREVOLUTIONepochchecksum      (double checksum);
    void        SetTLEparameters                (std::string spacecraft, std::vector<std::string> parsed_line_one, std::vector<std::string> parsed_line_two);
    void        SetDataFile                     (std::string TLE);
    void        setURLData                      (std::string URL);
    void        SetTLEparameters                ();
    void        SetClassifierID                 (std::string ClassifierID);
    void        SetCheckSumLineOne              (int checksum);
    void        SetCheckSumLineTwo              (int checksum);
    void        SetObserverCoordinates          (double x_observer, double y_observer, double z_observer);
    void        SetSatelliteData                ();
    void        SetWGS                          (std::string wgs_model);
    
    // getter
    void        getDataFile                     ();
    void        getURLData                      ();
    void        getTLEsummary                   ();
    void        getURLData                      (std::string resource_locator);
    char*       getTLEname                      () { return m_tle_name; }
    char*       getTLElinetwo                   () { return m_tle_line_two; }
    char*       getTLElineone                   () { return m_tle_line_one; }
    int         getSATnumber                    () { return m_satellite_number; }
    char*       getCLASSIFIERfield              () { return m_classification; }
    int         getLAUNCHERyearfield            () { return m_designator_launch_year; }
    int         getLAUNCHERnumberfield          () { return m_designator_launch_number_of_year; }
    char*       getLAUNCHpiencedesignator       () { return m_designator_piece_of_launch; }
    int         getEPOCHyear                    () { return m_epoch_year; }
    double      getJULIANdatefraction           () { return m_julian_date_fraction; }
    double      getBALLISTICcoefficient         () { return m_ballistic_coefficient; }
    char*       getSECONDderivativemotion       () { return m_second_derivative_of_motion; }
    char*       getDESIGNATORpiece              () { return m_designator_piece_of_launch;  }
    int         getDRAGRADIATIONcoefficient     () { return m_designator_launch_number_of_year; }
    int         getEPHEMERIStype                () { return m_ephemeris_type; }
    int         getELEMENTnumber                () { return m_element_number; }
    int         getCHECKsum                     () { return m_check_sum; }
    int         getSATNUMBERline2               () { return m_satellite_number_2; }
    double      getINCLINATIONfield             () { return m_satellite_inclination; }
    double      getRIGHTASCENTIONnode           () { return m_satellite_ascension_node; }
    double      getECCENTRICITYcoefficient      () { return m_satellite_eccentricity_coefficient; }
    double      getARGUMENTperigree             () { return m_argument_perigree; }
    double      getMEANanomlay                  () { return m_mean_anomaly; }
    double      getMEANmotion                   () { return m_mean_motion; }
    double      getREVOLUTIONepochchecksum      () { return m_epoch_checksum; }
    int         getCheckSumLineOne              () { return m_lineone_checksum; }
    int         getCheckSumLineTwo              () { return m_linetwo_checksum; }
    double      getCheckLaunchDate              () { return m_linetwo_checksum; }
    double      getNumberOfRevolutionsSinceLaunch
                                                () { return m_linetwo_checksum; }
    char*       getClassifierID                 ();
    int         getYear                         () { return m_year; }
    int         getMonth                        () { return m_month; }
    int         getDay                          () { return m_day; }
    double      getCheckSum                     ();
    std::string getWGS                          ();
    
    std::string getOrbit                        ();
    double      getElevation                    ();
    std::string getObjectName                   ();
    std::string getObjectType                   ();
    
};


#endif /* orbital_hpp */
