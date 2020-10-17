//
//  sgp4.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sgp4.hpp"
#include <string>

//std::vector<int> v{1,2,3};
// constructor
sgp4::sgp4                            ()
{
    // declare the variables
    orbital
            *orb = new orbital();
    utilities
            *util = new utilities();
    double perigree;
    double perigree_h;  
    
    vector<string>
            parsed_line_ones = util -> getStringParser();
    
    vector<string>
            parsed_line_twos = util -> getStringParser();

    // grab a raw TLE from the celestrak website and process it
            orb -> setURLData       ("https://celestrak.com/satcat/tle.php?CATNR=43108");
            orb -> getURLData       ();
    
    //m_designator_piece_of_launch = orb -> getDESIGNATORpiece();
    

    
    
    
    // set the TLE parameters
            orb -> SetTLEparameters (orb -> getTLEname(), parsed_line_ones, parsed_line_twos);
    
    // parameters
    int         m_satellite_number = orb -> getSATnumber();
    char        m_classification            [ARRAY_SIZE_ONE];;
                strcpy(m_classification,orb->getCLASSIFIERfield());
    int         m_designator_launch_year = orb -> getLAUNCHERyearfield(); // ??
    int         m_designator_launch_number_of_year = orb -> getLAUNCHERnumberfield(); //??
    char        m_designator_piece_of_launch        [ARRAY_SIZE_ONE];
                strcpy(m_designator_piece_of_launch,orb -> getLAUNCHpiencedesignator());
    int         m_epoch_year = orb -> getEPOCHyear();
    double      m_julian_date_fraction = orb -> getJULIANdatefraction();
    double      m_ballistic_coefficient = orb -> getBALLISTICcoefficient();
    char        m_second_derivative_of_motion       [ARRAY_SIZE];
                strcpy(m_second_derivative_of_motion,orb -> getSECONDderivativemotion());
    char        m_drag_term_or_radition_coefficient [ARRAY_SIZE];
                strcpy(m_second_derivative_of_motion,orb -> getSECONDderivativemotion());
    int         m_ephemeris_type = orb -> getEPHEMERIStype();
    int         m_element_number = orb -> getELEMENTnumber();
    int         m_check_sum = orb -> getCheckSumLineOne(); //????
    int         m_satellite_number_2 = orb -> getSATNUMBERline2();
    double      m_satellite_inclination = orb -> getINCLINATIONfield();
    double      m_satellite_ascension_node = orb -> getRIGHTASCENTIONnode();
    double      m_satellite_eccentricity_coefficient = orb->getECCENTRICITYcoefficient();
    double      m_argument_perigree = orb->getARGUMENTperigree();
    double      m_mean_anomaly = orb -> getMEANanomlay();
    double      m_mean_motion = orb -> getMEANmotion();
    double      m_epoch_checksum = orb -> getREVOLUTIONepochchecksum(); //???
    int         m_lineone_checksum = orb -> getCheckSumLineOne();
    int         m_linetwo_checksum = orb -> getCheckSumLineTwo();
}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{
    
    
    
    

}
