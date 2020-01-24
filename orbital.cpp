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
#include <vector>

using namespace std;

// Date constructor
// store the data
orbital::orbital(int year, int month, int day)
{
    SetDate(year, month, day);
}
 
// Date member function
// store the data
void orbital::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}

// Date member function
// store the data
void orbital::getDataFile()
{
    std::string filename = "/Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/source/TLE_File.txt";
    std::ifstream in(filename, std::ios::out);
    std::string line;
    
    if (!in.is_open())
    {
        std::cerr << "Error: Unable to open settings file \"" << filename << "\" for reading!" << std::endl;
    }
    
    int x = 0;
    while (std::getline(in, line))
    {
           std::cout << line << "\n";
        
        if (x == 0)
        { orbital::SetTLEname(line); }
        
        if (x == 1)
        {
            cout << "hello 1 :" << line << "\n";
            orbital::SetTLElineone(line);
            
            
        }
        
        if (x == 2)
        {
            cout << "hello 2 :" << line << "\n";
            orbital::SetTLElinetwo(line);
            
            
        }
        
        x++;
    }
    
    in.close();
}

// Date member function
// store the data
void orbital::SetTLEname(std::string name)
{
    m_tle_name = name;
};

// sets the statellite number
// store the data
void orbital::SetSATnumber(int number)
{
    m_satellite_number = number;
};

// sets the classifier field (1 digits)
// store the data
void orbital::SetCLASSIFIERfield(char field)
{
    m_classification = field;
};

// sets the laumncher year field
// store the data
void orbital::SetLAUNCHERyearfield(int field)
{
    m_designator_launch_year = field;
};

// sets the launcher number field
// store the data
void orbital::SetLAUNCHERnumberfield(int field)
{
    m_designator_launch_number_of_year = field;
};


// sets the piece designator
// store the data
void orbital::SetLAUNCHpiecedesignator(string designator)
{
    m_designator_piece_of_launch = designator;
};

// set the epoch year
// store the data
void orbital::SetEPOCHyear(int year)
{
    m_epoch_year = year;
};

// set the julian date fraction
// store the data
void orbital::SetJULIANdatefraction(double fraction)
{
    m_julian_date_fraction = fraction;
};

// set the ballistic coefficient
// store the data
void orbital::SetBALLISTICcoefficient(double coefficient)
{
    m_ballistic_coefficient = coefficient;
};

// extract and store the second derivative
// store the data
void orbital::SetSECONDderivativemotion(std::string motion)
{
    m_second_derivative_of_motion = motion;
};

// extract and store the degradation coefficient
// store the data
void orbital::SetDRAGRADIATIONcoefficient(std::string coefficient)
{
    m_drag_term_or_radition_coefficient = coefficient;
};

// set the ephemeris details
// store the data
void orbital::SetEPHEMERIStype(int type)
{
    m_ephemeris_type = type;
};

// set the element number
// store the data
void orbital::SetELEMENTnumber(int number)
{
    m_element_number = number;
};

// set the checksum
// store the data
void orbital::SetCHECKsum(int sum)
{
    m_check_sum = sum;
};

// set the satellite number obtained from line 2
// store the data
void orbital::SetSATNUMBERline2(int number)
{
    m_satellite_number_2 = number;
};

// set the inclination of the field
// store the data
void orbital::SetINCLINATIONfield(double field)
{
    m_satellite_inclination = field;
};

// set the ascension node
// store the data
void orbital::SetRIGHTASCENTIONnode(double node)
{
    m_satellite_ascension_node = node;
};

// set the eccentricity coefficient
// store the data
void  orbital::SetECCENTRICITYcoefficient(double coefficient)
{
    m_satellite_eccentricity_coefficient = coefficient;
};

// set the argument perigree
// store the data
void  orbital::SetARGUMENTperigree(double perigree)
{
    m_argument_perigree = perigree;
};

// set the mean anomaly
// store the data
void  orbital::SetMEANanomlay(double anomaly)
{
    m_mean_anomaly = anomaly;
};

// set the mean motion
// store the data
void  orbital::SetMEANmotion(double motion)
{
    m_mean_motion = motion;
};

// set the epoch and the corresponding checksum
// store the data
void  orbital::SetREVOLUTIONepochchecksum(double checksum)
{
    m_epoch_checksum = checksum;
};

// set the data from the first line of the tle
// store the data
void  orbital::SetTLElineone(std::string phrase)
{
    m_tle_line_one = phrase;
};


// set the data from the second line of the tle
// store the data
void  orbital::SetTLElinetwo(std::string phrase)
{
    m_tle_line_two = phrase;
};

// set all TLE parameters
void orbital::SetTLEparameters(std::vector<std::string> parsed_line_one, std::vector<std::string>parsed_line_twos)
{
    std::string phrase;
    orbital::SetTLEname(parsed_line_one[0]);
    
    phrase = parsed_line_one[1];
    phrase = phrase.substr(0, 4);
    orbital::SetSATnumber(stoi(parsed_line_one[1]));
    
    phrase = parsed_line_one[1];
    phrase = phrase.substr(4, 5);
    orbital::SetCLASSIFIERfield(stoi(phrase));
    
    phrase = parsed_line_one[2];
    phrase = phrase.substr(0, 1);
    orbital::SetLAUNCHERyearfield(stoi(phrase));
    
    phrase = parsed_line_one[2];
    phrase = phrase.substr(2, 4);
    orbital::SetLAUNCHERnumberfield(stoi(phrase));
    
    phrase = parsed_line_one[2];
    phrase = phrase.substr(5, 5);
    orbital::SetLAUNCHpiecedesignator(phrase);
    
    phrase = parsed_line_one[3];
    phrase = phrase.substr(0, 1);
    orbital::SetEPOCHyear(stoi(phrase));
    
    phrase = parsed_line_one[3];
    phrase = phrase.substr(2, 13);
    orbital::SetJULIANdatefraction(stoi(phrase));

    phrase = parsed_line_one[4];
    orbital::SetBALLISTICcoefficient(stoi(phrase));
    
    phrase = parsed_line_one[5];
    orbital::SetSECONDderivativemotion(phrase);
    
    phrase = parsed_line_one[6];
    orbital::SetDRAGRADIATIONcoefficient(phrase);
    
    phrase = parsed_line_one[7];
    orbital::SetEPHEMERIStype(stoi(phrase));
    
    phrase = parsed_line_one[8];
    orbital::SetELEMENTnumber(stoi(phrase));
    
    orbital::SetCHECKsum(0);
};
