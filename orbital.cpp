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
    std::string filename = "/Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/HelloWorld/TLE_File.txt";
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
        x++;
       }
    
    in.close();
}

// Date member function
void orbital::SetTLEname(std::string name)
{
    m_tle_name = name;
};


std::string m_tle_name;
int         m_satellite_number;
std::string m_classification;
int         m_designator_launch_year;
int         m_designator_launch_number_of_year;
char        m_designator_piece_of_launch;
int         m_epoch_year;
double      m_julian_date_fraction;
double      m_ballistic_coefficient;
double      m_second_derivative_of_motion;
std::string m_drag_term_or_radition_coefficient;
int         m_ephemeris_type;
int         m_element_number;
int         m_check_sum;

void SetSATnumber(int number)
{
    m_satellite_number = number;
};

void SetCLASSIFIERfield(std::string field)
{
    m_classification = field;
};

void SetLAUNCHERyearfield(int field)
{
    m_designator_launch_year = field;
};

void SetLAUNCHERnumberfield(int field)
{
    m_designator_launch_number_of_year = field;
};

void SetLAUNCHpiencedesignator(char designator)
{
    m_designator_piece_of_launch = designator;
};

void SetEPOCHyear(int year)
{
    m_epoch_year = year;
};

void SetJULIANdatefraction(double fraction)
{
    m_julian_date_fraction = fraction;
};

void SetBALLISTICcoefficient(double coefficient)
{
    m_ballistic_coefficient = coefficient;
};

void SetSECONDderivativemotion(double motion)
{
    m_second_derivative_of_motion = motion;
};

void SetDRAGRADIATIONcoefficient(int coefficient)
{
    m_drag_term_or_radition_coefficient = coefficient;
};

void SetEPHEMERIStype(int type)
{
    m_ephemeris_type = type;
};
void SetELEMENTnumber(int number)
{
    m_element_number = number;
};

void SetCHECKsum(int sum)
{
    m_check_sum = sum;
};

