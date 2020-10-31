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
void sgp4::set_model                       (orbital *model)
{
    m_satellite_number = model->getSATnumber();
    strcpy(m_classification,model->getClassifierID());
    m_designator_launch_year = model->getLAUNCHERyearfield();
    m_designator_launch_number_of_year = model->getLAUNCHERnumberfield();
    m_epoch_year = model -> getEPOCHyear();
    m_julian_date_fraction = model -> getJULIANdatefraction();
    m_ballistic_coefficient = model -> getBALLISTICcoefficient();
    strcpy(m_second_derivative_of_motion,model->getSECONDderivativemotion());
    m_drag_term_or_radiation_coefficient = model-> getDRAGRADIATIONcoefficient();
    m_ephemeris_type = model-> getEPHEMERIStype();
    m_element_number = model -> getELEMENTnumber();
   // strcpy(m_check_sum, model -> getCHECKsum());
    m_satellite_number_2 = model -> getSATNUMBERline2();
    m_satellite_inclination = model -> getINCLINATIONfield();
    m_satellite_ascension_node;
    m_satellite_eccentricity_coefficient;
    m_argument_perigree = model -> getARGUMENTperigree();
    m_mean_anomaly = model -> getMEANanomlay();
    m_mean_motion = model -> getMEANmotion();
    m_epoch_checksum; //???
    m_lineone_checksum;
    m_linetwo_checksum;
    query_field;
    query_output;
    space_vehicle;
    
}

sgp4::sgp4                            ()
{
    orbital *orb = new orbital();

    orb -> SetSATnumber (3);
    
    cout << "satellite number: " << orb -> getSATnumber() << "\n";
    // declare the variables
}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{}
