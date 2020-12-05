//
//  sgp4.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sgp4.hpp"
#include <cmath>
#include <math.h> //Not sure about including math.h
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
{
    
}

void sgp4::set_wgs                              (orbital *model)
{
    
    //    we implement here a method which supplies constants for the propagator.
    //    note that mu is identified to facilitiate comparisons with newer models
    
    std::string wgs = model->getWGS();
    
    if (wgs == "wgs-72-low")
    {
            model_const_mu     = 398600.79964;
            model_const_radiusearthkm = 6378.135;
            model_const_xke    = 0.0743669161;
            model_const_tumin  = 1.0 / model_const_xke;
            model_const_j2     =   0.001082616;
            model_const_j3     =  -0.00000253881;
            model_const_j4     =  -0.00000165597;
            model_const_j3oj2  =  model_const_j3 / model_const_j2;
    }
    else if (wgs == "wgs-72")
    {
            model_const_mu     = 398600.8;
            model_const_radiusearthkm = 6378.135;
            model_const_xke    = 60.0 / (sqrt(model_const_radiusearthkm * model_const_radiusearthkm * model_const_radiusearthkm  / model_const_mu));
            model_const_tumin  = 1.0 / model_const_xke;
            model_const_j2     =   0.001082616;
            model_const_j3     =  -0.00000253881;
            model_const_j4     =  -0.00000165597;
            model_const_j3oj2  =  model_const_j3 / model_const_j2;
    }
    else if (wgs == "wgs-84")
    {
            model_const_mu     = 398600.5;
            model_const_radiusearthkm = 6378.137;
            model_const_xke    = 60.0 / (sqrt(model_const_radiusearthkm*model_const_radiusearthkm*model_const_radiusearthkm/model_const_mu));
            model_const_tumin  = 1.0 / model_const_xke;
            model_const_j2     =   0.00108262998905;
            model_const_j3     =  -0.00000253215306;
            model_const_j4     =  -0.00000161098761;
            model_const_j3oj2  =  model_const_j3 / model_const_j2;
    };
        
    
}

sgp4::sgp4                            ()
{
    orbital *orb = new orbital();
    dspace_model *models = new dspace_model();
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
    m_vkmpersec     = model_const_radiusearthkm * m_xke/60.0;
   
    m_satrec_t     = 0;
        // what is the 'tsince' variable
        //m_satrec_t=tsince;
    m_satrec_error = 0;
    m_mrt = 0.0;
    
    m_xmdf    = m_satrec_mo + m_satrec_mdot * m_satrec_t;
    m_argpdf  = m_satrec_argpo + m_satrec_argpdot * m_satrec_t;
    m_nodedf  = m_satrec_nodeo + m_satrec_nodedot * m_satrec_t;
    m_argpm   = m_argpdf;
    m_mm      = m_xmdf;
    m_t2      = m_satrec_t * m_satrec_t;
    m_nodem   = m_nodedf + m_satrec_nodecf * m_t2;
    m_tempa   = 1.0 - m_satrec_cc1 * m_satrec_t;
    m_tempe   = m_satrec_bstar * m_satrec_cc4 * m_satrec_t;
    m_templ   = m_satrec_t2cof * m_t2;
    
    if (m_satrec_isimp != 1)
    {
        m_delomg = m_satrec_omgcof * m_satrec_t;
        double expr = ((1.0 + m_satrec_eta * cos(m_xmdf)));
        m_delm   = m_satrec_xmcof * (expr * expr * expr - m_satrec_delmo);
        m_temp   = m_delomg + m_delm;
        m_mm     = m_xmdf + m_temp;
        m_argpm  = m_argpdf - m_temp;
        m_t3     = m_t2 * m_satrec_t;
        m_t4     = m_t3 * m_satrec_t;
        m_tempa  = m_tempa - m_satrec_d2 * m_t2 - m_satrec_d3 * m_t3 - m_satrec_d4 * m_t4;
        m_tempe  = m_tempe + m_satrec_bstar * m_satrec_cc5 * (sin(m_mm) - m_satrec_sinmao);
        m_templ  = m_templ + m_satrec_t3cof * m_t3 + m_t4 * (m_satrec_t4cof + m_satrec_t * m_satrec_t5cof);
    };
    
    
    m_nm    = m_satrec_no;
    m_em    = m_satrec_ecco;
    m_inclm = m_satrec_inclo;
    
    if (satrec_method != 'd')
        {
            
        tc = m_satrec_t;
            
        // set the parameters
            
        models->set_dspace_line1(satrec_d2201,satrec_d2211,satrec_d3210, satrec_d3222,satrec_d4410,satrec_d4422, satrec_d5220,satrec_d5232,satrec_d5421);
     
        models->set_dspace_line2 (satrec_d5433,satrec_dedt,satrec_del1, satrec_del2,satrec_del3,satrec_didt, satrec_dmdt,satrec_dnodt,satrec_domdt);
                
        models->set_dspace_line3 (satrec_irez,satrec_argpo,satrec_argpdot,m_satrec_t, tc,satrec_gsto,satrec_xfact,satrec_xlamo,satrec_no);
                
        models->set_dspace_line3(satrec_atime,em,argpm,inclm,satrec_xli,mm, satrec_xni,nodem,nm);
        
        };
    
    if (m_nm <= 0.0)
    {
    //      cout << (1,'# error nm %f\n', nm);
    m_satrec_error = 2;
    }
       
    ///check the following expression
       m_am = pow((m_xke / nm),m_x2o3) * m_tempa * m_tempa;
       m_nm = pow(m_xke / m_am,1.5);
       m_em = m_em - m_tempe;
    
     // fix tolerance for error recognition
       if ((m_em >= 1.0) || (m_em < -0.001) || (m_am < 0.95))
       {
    //     fprintf(1,'# error em %f\n', em);
           m_satrec_error = 1;
       }

    if (m_em < 1.0e-6)
    {
        m_em  = 1.0e-6;
    };
    
    m_mm     = m_mm + m_satrec_no * m_templ;
    m_xlm    = m_mm + m_argpm + nodem;
    m_emsq   = m_em * m_em;
    m_temp   = 1.0 - m_emsq;
    m_nodem  = remainder(m_nodem, m_twopi);
    m_argpm  = remainder(m_argpm, m_twopi);
    m_xlm    = remainder(m_xlm, m_twopi);
    m_mm     = remainder(m_xlm - m_argpm - m_nodem, m_twopi);
    
    ///* ----------------- compute extra mean quantities ------------- */
    m_sinim = sin(inclm);
    m_cosim = cos(inclm);
    
    // /* -------------------- add lunar-solar periodics -------------- */
    m_ep     = m_em;
    m_xincp  = m_inclm;
    m_argpp  = m_argpm;
    m_nodep  = m_nodem;
    m_mp     = m_mm;
    m_sinip  = m_sinim;
    m_cosip  = m_cosim;

    
}

// destructor
sgp4::~sgp4                           ()
{}

void builds()
{}
