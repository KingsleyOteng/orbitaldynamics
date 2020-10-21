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
    orbital *orb = new orbital();
    utilities *util = new utilities();
    double perigree;
    double perigree_h;  
    vector<string> parsed_line_ones;
    vector<string> parsed_line_twos;
    
    parsed_line_ones = util -> getStringParser();
    parsed_line_twos = util -> getStringParser();

    // grab a raw TLE from the celestrak website and process it
    orb -> setURLData       ("https://celestrak.com/satcat/tle.php?CATNR=43108");
    orb -> getURLData       ();

    // set the TLE parameters
    orb -> SetTLEparameters (orb -> getTLEname(), parsed_line_ones, parsed_line_twos);
    
    // member variables
    strcpy(m_designator_piece_of_launch,orb -> getLAUNCHpiencedesignator());
    strcpy(m_second_derivative_of_motion,orb -> getSECONDderivativemotion());
    strcpy(m_second_derivative_of_motion,orb -> getSECONDderivativemotion());
    strcpy(m_classification,orb->getCLASSIFIERfield());
    
      m_satellite_number = orb -> getSATnumber();
      m_designator_launch_year = orb -> getLAUNCHERyearfield(); // ??
      m_designator_launch_number_of_year = orb -> getLAUNCHERnumberfield(); //??
      m_epoch_year = orb -> getEPOCHyear();
      m_julian_date_fraction = orb -> getJULIANdatefraction();
      m_ballistic_coefficient = orb -> getBALLISTICcoefficient();
      m_ephemeris_type = orb -> getEPHEMERIStype();
      m_element_number = orb -> getELEMENTnumber();
      m_check_sum = orb -> getCheckSumLineOne(); //????
      m_satellite_number_2 = orb -> getSATNUMBERline2();
      m_satellite_inclination = orb -> getINCLINATIONfield();
      m_satellite_ascension_node = orb -> getRIGHTASCENTIONnode();
      m_satellite_eccentricity_coefficient = orb->getECCENTRICITYcoefficient();
      m_argument_perigree = orb->getARGUMENTperigree();
      m_mean_anomaly = orb -> getMEANanomlay();
      m_mean_motion = orb -> getMEANmotion();
      m_epoch_checksum = orb -> getREVOLUTIONepochchecksum();
      m_lineone_checksum = orb -> getCheckSumLineOne();
      m_linetwo_checksum = orb -> getCheckSumLineTwo();

    // query text files for additional information
      query_field = "apogee";
      query_output = util -> SatelliteNORADRecord("43108", query_field);
      cout << "record> " << query_field <<  " " << query_output << "\n";
}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{}
