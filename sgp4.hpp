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
#include "orbital.hpp"
#include "utilities.hpp"

using namespace std;

#ifndef sgp4_hpp
#define sgp4_hpp
class sgp4
{
    
    private:
    
        orbital     *orb;
        utilities   *util;
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
        std::string query_field;
        std::string query_output;
        std::string space_vehicle;
        
    
    public:
    

    
     // constructors  and destructors
                    sgp4();
                   ~sgp4();
        void        set_model(orbital *model);
    
    //void    sgp4::builds();
};

#endif /* sgp4_hpp */


