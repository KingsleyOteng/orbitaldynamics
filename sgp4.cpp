//
//  sgp4.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sgp4.hpp"
#include "dpper.hpp"
#include <cmath>
#include <math.h> 
#include <string>
#include "dspace_model.hpp"

//std::vector<int> v{1,2,3};
// constructor
void sgp4::set_parameters                       (orbital *model)
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
    m_check_sum = model -> getCHECKsum();
    m_satellite_number_2 = model -> getSATNUMBERline2();
    m_satellite_inclination = model -> getINCLINATIONfield();
    m_satellite_ascension_node = model -> getRIGHTASCENTIONnode();
    m_satellite_eccentricity_coefficient = model -> getECCENTRICITYcoefficient();
    m_argument_perigree = model -> getARGUMENTperigree();
    m_mean_anomaly = model -> getMEANanomlay();
    m_mean_motion = model -> getMEANmotion();
    m_epoch_checksum = model -> getREVOLUTIONepochchecksum();
    m_lineone_checksum = model -> getCheckSumLineOne();
    m_linetwo_checksum = model -> getCheckSumLineTwo();
    
    // scrape the accompanying text file
    m_space_vehicle = util -> SatelliteNORADRecord("43108", m_query_field = "Name");
    m_operator_of_vehicle = util -> SatelliteNORADRecord("43108", m_query_field = "Operator");
    m_space_object_use = util ->  SatelliteNORADRecord("43108", m_query_field = "purpose");
    m_space_users = util ->  SatelliteNORADRecord("43108", m_query_field = "users");
    m_date_of_launch = util -> SatelliteNORADRecord("43108", m_query_field = "date-launch");
    
    // set the wgs model
    set_wgs(model);
}

double      sgp4::dspace
(
 double satrec_d2201,double satrec_d2211,double satrec_d3210,
 double satrec_d3222, double satrec_d4410, double satrec_d4422,
 double satrec_d5220,double satrec_d5232,double satrec_d5421,
 double satrec_d5433,double satrec_dedt,double satrec_del1,
 double satrec_del2,double satrec_del3,double satrec_didt,
 double satrec_dmdt,double satrec_dnodt,double satrec_domdt,
 double satrec_irez,double satrec_argpo,double satrec_argpdot,double satrec_t,
 double tc, double satrec_gsto,double satrec_xfact,double satrec_xlamo, double satrec_no,
 double satrec_atime, double em, double argpm, double inclm, double satrec_xli, double mm,
 double satrec_xni,double nodem,double nm
 )
{return 0;}

void sgp4::set_model                            ()
{}

void sgp4::set_wgs                              (orbital *model)
{
    
 

         
}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{}
