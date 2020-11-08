//
//  sgp4.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//
//  https://github.com/jgte/matlab-sgp4/blob/master/sgp4.m
//  https://github.com/jgte/matlab-sgp4/blob/master/twoline2rv.m
//  https://core.ac.uk/download/pdf/55536475.pdf
//  http://large.stanford.edu/courses/2017/ph241/summerville2/docs/a093554.pdf
//  http://www.satobs.org/seesat/Dec-2002/0197.html
//  https://core.ac.uk/download/pdf/55536475.pdf
//  http://www.spaceacademy.net.au/watch/track/TLEdecod.txt

#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>
#include <iostream>
#include <vector>       // c-11 vector
#include <algorithm>    // c-11 algoithm
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <array>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "orbital.hpp"
#include "utilities.hpp"

using namespace std;

#ifndef sgp4_hpp
#define sgp4_hpp
class sgp4
{
    
    private:
    
        double      model_const_radiusearthkm;
        double      model_const_xke;
        double      model_const_tumin;
        double      model_const_j2;
        double      model_const_j3;
        double      model_const_j4;
        double      model_const_j3oj2;
        double      model_const_mu;
    
        orbital     *orb;
        utilities   *util = new utilities();
        int         m_satellite_number;
        char        m_classification            [ARRAY_SIZE_ONE];
        int         m_designator_launch_year; // ??
        int         m_designator_launch_number_of_year; //??
        char        m_designator_piece_of_launch        [ARRAY_SIZE_ONE];
        int         m_epoch_year;
        double      m_julian_date_fraction;
        double      m_ballistic_coefficient;
        char        m_second_derivative_of_motion       [ARRAY_SIZE];
        int         m_drag_term_or_radiation_coefficient;
        int         m_ephemeris_type;
        int         m_element_number;
        int         m_check_sum; //????
        int         m_satellite_number_2;
        double      m_satellite_inclination;
        double      m_satellite_ascension_node;
        double      m_satellite_eccentricity_coefficient;
        double      m_argument_perigree;
        double      m_mean_anomaly;
        double      m_mean_motion;
        double      m_epoch_checksum; //???
        int         m_lineone_checksum;
        int         m_linetwo_checksum;
        std::string m_query_field;
        std::string m_space_vehicle;
        std::string m_operator_of_vehicle;
        std::string m_space_object_use;
        std::string m_space_users;
        std::string m_date_of_launch;
    
        // %% SGP4 constants
        // i have introduced these variables
        //  they may be best placed elsewhere
        double
    m_pi, m_twopi, m_x2o3, m_temp4, m_tumin, m_mu, m_radiusearthkm, m_xke, m_j2, m_j3,           m_j4, m_j3oj2, m_vkmpersec, m_satrec_error, m_mrt, m_xmdf, m_argpdf,             m_nodedf, m_argpm, m_mm, m_t2,  m_nodem, m_tempa,  m_tempe,  m_templ, m_satrec_mdot,         m_satrec_mo, m_satrec_argpo, m_satrec_argpdot, m_satrec_nodeo, m_satrec_nodedot, m_satrec_nodecf, m_satrec_cc1, m_satrec_cc4, m_satrec_cc5, m_satrec_bstar, m_satrec_c,                     m_satrec_t2cof, m_satrec_isimp, m_delm, m_temp, m_satrec_omgcof,                           m_delomg, m_satrec_xmcof, m_satrec_t, m_t4, m_t3, m_satrec_eta, m_satrec_delmo, m_satrec_d3, m_satrec_d2, m_satrec_d4, m_satrec_t3cof, m_satrec_sinmao, m_satrec_t4cof, m_satrec_t5cof,
        m_nm, m_satrec_no, m_em, m_satrec_ecco, m_inclm, m_satrec_inclo;
    public:

     // constructors  and destructors
                    sgp4();
                   ~sgp4();
        void        set_parameters(orbital *model);
        void        set_model();
        void        set_wgs(orbital *model);
    //void    sgp4::builds();
};

#endif /* sgp4_hpp */


