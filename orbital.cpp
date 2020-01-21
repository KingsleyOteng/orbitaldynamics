//
//  orbital.cpp
//  HelloWorld
//
//  Created by Kwadwo Oteng-Amoko on 14/01/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "orbital.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Date constructor
orbital::orbital(int year, int month, int day)
{
    SetDate(year, month, day);
}
 
// Date member function
void orbital::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

// Date member function
void orbital::getDataFile()
{
    std::string filename = "/Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/source/TLE_File.txt";
    std::ifstream in(filename, std::ios::out);
    std::string line;
    
    if (!in.is_open()) {
        std::cerr << "Error: Unable to open settings file \"" << filename << "\" for reading!" << std::endl;
        
    }
    int x = 0;
    while (std::getline(in, line)) {
           std::cout << line << "\n";
        if (x == 0)
        {
            orbital::SetTLEname(line);
        }
        
        if (x == 1)
        {
            orbital::SetTLElineone(line);
        }
        
        if (x == 2)
        {
            orbital::SetTLElinetwo(line);
        }
        
        x++;
       }
    
    in.close();
}

// Date member function
void orbital::SetTLEname(std::string name)
{
    m_tle_name = name;
};

// sets the statellite number
void orbital::SetSATnumber(int number)
{
    m_satellite_number = number;
};

// sets the classifier field
void orbital::SetCLASSIFIERfield(std::string field)
{
    m_classification = field;
};

// sets the laumncher year field
void orbital::SetLAUNCHERyearfield(int field)
{
    m_designator_launch_year = field;
};

// sets the launcher number field
void orbital::SetLAUNCHERnumberfield(int field)
{
    m_designator_launch_number_of_year = field;
};


// sets the piece designator
void orbital::SetLAUNCHpiecedesignator(char designator)
{
    m_designator_piece_of_launch = designator;
};

// set the epoch year
void orbital::SetEPOCHyear(int year)
{
    m_epoch_year = year;
};

// set the julian date fraction
void orbital::SetJULIANdatefraction(double fraction)
{
    m_julian_date_fraction = fraction;
};

// set the ballistic coefficient
void orbital::SetBALLISTICcoefficient(double coefficient)
{
    m_ballistic_coefficient = coefficient;
};

// extract and store the second derivative
void orbital::SetSECONDderivativemotion(double motion)
{
    m_second_derivative_of_motion = motion;
};

// extract and store the degradation coefficient
void orbital::SetDRAGRADIATIONcoefficient(int coefficient)
{
    m_drag_term_or_radition_coefficient = coefficient;
};

// set the ephemeris details
void orbital::SetEPHEMERIStype(int type)
{
    m_ephemeris_type = type;
};

// set the element number
void orbital::SetELEMENTnumber(int number)
{
    m_element_number = number;
};

// set the checksum
void orbital::SetCHECKsum(int sum)
{
    m_check_sum = sum;
};

// set the satellite number obtained from line 2
void orbital::SetSATNUMBERline2(int number)
{
    m_satellite_number_2 = number;
};

// set the inclination of the field
void orbital::SetINCLINATIONfield(double field)
{
    m_satellite_inclination = field;
};

// set the ascension node
void orbital::SetRIGHTASCENTIONnode(double node)
{
    m_satellite_ascension_node = node;
};

// set the eccentricity coefficient
void  orbital::SetECCENTRICITYcoefficient(double coefficient)
{
    m_satellite_eccentricity_coefficient = coefficient;
};

// set the argument perigree
void  orbital::SetARGUMENTperigree(double perigree)
{
    m_argument_perigree = perigree;
};

// set the mean anomaly
void  orbital::SetMEANanomlay(double anomaly)
{
    m_mean_anomaly = anomaly;
};

// set the mean motion
void  orbital::SetMEANmotion(double motion)
{
    m_mean_motion = motion;
};

// set the epoch and the corresponding checksum
void  orbital::SetREVOLUTIONepochchecksum(double checksum)
{
    m_epoch_checksum = checksum;
};

// set the data from the first line of the tle
void  orbital::SetTLElineone(std::string phrase)
{
    m_tle_line_one = phrase;
};

// set the data from the second line of the tle
void  orbital::SetTLElinetwo(std::string phrase)
{
    m_tle_line_two = phrase;
};


