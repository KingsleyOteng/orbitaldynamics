//
//  orbital.hpp
//  HelloWorld
//
//  Created by Kwadwo Oteng-Amoko on 14/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef orbital_hpp
#define orbital_hpp

#include <stdio.h>
#include <string>


class orbital{
    

private:
    std::string m_tle_name;
    int         m_satellite_number;
    std::string m_classification;
    int         m_designator_launch_year;
    int         m_designator_launch_number_of_year;
    char        m_designator_piece_of_launch;
    int         m_epoch_year;
    double      m_julian_date_fraction;
    double      m_ballistic_coefficient;
    double      m_second_derivative_of_motion;
    std::string m_drag_term_or_radition_coefficient;
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
    
    int m_year;
    int m_month;
    int m_day;
 
public:
    orbital(int year, int month, int day);
    
    void        SetDate(int year, int month, int day);
    void        SetTLEname(std::string name);
    void        SetSATnumber(int number);
    void        SetCLASSIFIERfield(std::string field);
    void        SetLAUNCHERyearfield(int field);
    void        SetLAUNCHERnumberfield(int field);
    void        SetLAUNCHpiecedesignator(char designator);
    void        SetEPOCHyear(int year);
    void        SetJULIANdatefraction(double fraction);
    void        SetBALLISTICcoefficient(double coefficient);
    void        SetSECONDderivativemotion(double motion);
    void        SetDRAGRADIATIONcoefficient(int coefficient);
    void        SetEPHEMERIStype(int type);
    void        SetELEMENTnumber(int number);
    void        SetCHECKsum(int sum);
    
    void        SetSATNUMBERline2(int number);
    void        SetTLElineone(string phrase);
    void        SetTLElinetwo(string phrase);
    void        SetINCLINATIONfield(double field);
    void        SetRIGHTASCENTIONnode(double node);
    void        SetECCENTRICITYcoefficient(double coefficient);
    void        SetARGUMENTperigree(double perigree);
    void        SetMEANanomlay(double anomaly);
    void        SetMEANmotion(double motion);
    void        SetREVOLUTIONepochchecksum(double checksum);
    
    void        getDataFile();
    std::string getTLEname() { return m_tle_name; }
    int         getSATnumber() { return m_satellite_number; }
    std::string getCLASSIFIERfield() { return m_classification; }
    int         getLAUNCHERyearfield() { return m_designator_launch_year; }
    int         getLAUNCHERnumberfield() { return m_designator_launch_number_of_year; }
    char        getLAUNCHpiencedesignator() { return m_designator_piece_of_launch; }
    int         getEPOCHyear() { return m_epoch_year; }
    double      getJULIANdatefraction() { return m_julian_date_fraction; }
    double      getBALLISTICcoefficient() { return m_ballistic_coefficient; }
    double      getSECONDderivativemotion() { return m_second_derivative_of_motion; }
    int         getDRAGRADIATIONcoefficient() { return m_designator_launch_number_of_year; }
    int         getEPHEMERIStype() { return m_ephemeris_type; }
    int         getELEMENTnumber() { return m_element_number; }
    int         getCHECKsum() { return m_check_sum; }
    
    int         getSATNUMBERline2(int number) { return m_satellite_number_2; }
    double      getINCLINATIONfield(double field) { return m_satellite_inclination; }
    double      getRIGHTASCENTIONnode(double node) { return m_satellite_ascension_node; }
    double      getECCENTRICITYcoefficient(double coefficient) { return m_satellite_eccentricity_coefficient; }
    double      getARGUMENTperigree(double perigree) { return m_argument_perigree; }
    double      getMEANanomlay(double anomaly) { return m_mean_anomaly; }
    double      getMEANmotion(double motion) { return m_mean_motion; }
    double      getREVOLUTIONepochchecksum(double checksum) { return m_epoch_checksum; }
    
    int         getYear() { return m_year; }
    int         getMonth() { return m_month; }
    int         getDay()  { return m_day; }
};


#endif /* orbital_hpp */
