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
    
    
}

void sgp4::set_model                            ()
{
    
}

void sgp4::set_wgs                              (orbital *model)
{
    std::string wgs = model->getWGS();
    
    if (wgs == "wgs-72-low")
    {
            const_mu     = 398600.79964;        
            const_radiusearthkm = 6378.135;
            const_xke    = 0.0743669161;
            const_tumin  = 1.0 / const_xke;
            const_j2     =   0.001082616;
            const_j3     =  -0.00000253881;
            const_j4     =  -0.00000165597;
            const_j3oj2  =  const_j3 / const_j2;
    }
    else if (wgs == "wgs-72")
    {
            const_mu     = 398600.8;
            const_radiusearthkm = 6378.135;
            const_xke    = 60.0 / (sqrt(const_radiusearthkm * const_radiusearthkm * const_radiusearthkm  / const_mu));
            const_tumin  = 1.0 / const_xke;
            const_j2     =   0.001082616;
            const_j3     =  -0.00000253881;
            const_j4     =  -0.00000165597;
            const_j3oj2  =  const_j3 / const_j2;
    }
    else if (wgs == "wgs-84")
    {
            const_mu     = 398600.5;
            const_radiusearthkm = 6378.137;
            const_xke    = 60.0 / (sqrt(const_radiusearthkm*const_radiusearthkm*const_radiusearthkm/const_mu));
            const_tumin  = 1.0 / const_xke;
            const_j2     =   0.00108262998905;
            const_j3     =  -0.00000253215306;
            const_j4     =  -0.00000161098761;
            const_j3oj2  =  const_j3 / const_j2;
    };
        
    
}

sgp4::sgp4                            ()
{
    orbital *orb = new orbital();
    orb -> SetSATnumber (m_satellite_number);
    
    //  % /* ------------------ set mathematical constants --------------- */
    //  %  outputs       :
    //  %    tumin       - minutes in one time unit
    //  %    mu          - earth gravitational parameter
    //  %    radiusearthkm - radius of the earth in km
    //  %    xke         - reciprocal of tumin
    //  %    j2, j3, j4  - un-normalized zonal harmonic values
    //  %    j3oj2       - j3 divided by j2
    
    
    
    m_pi            = 3.14159267;
    m_twopi         = 2.0 * m_pi;
    m_x2o3          = 2.0 / 3.0;
    m_temp4         = 1.5e-12;
   // m_vkmpersec     = const_radiusearthkm * const_xke/60.0;
}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{}
