//      Source  
//      Overview: Extraction of object tracking data from NORAD TLE
//
//      Created by Kwadwo Oteng-Amoko on 14/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "orbital.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
#define ARRAY_SIZE_ONE 1


// methods
// store the data
orbital::orbital(int year, int month, int day)
{
    SetDate(year, month, day);
}

// Set the current epoch
void
    orbital::SetCurrentEpoch(int year, int month, int day)
{
    SetDate(year, month, day);
}
 
// Date member function
// store the data
void
    orbital::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}


// Date member function
// store the data
void
    orbital::getURLData(std::string resource_locator)
{
    
};

// Date member function
// store the data
void
    orbital::getDataFile()
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
        
        if (x == 0)
        { orbital::SetTLEname(line); }
        
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

// set the checksum
// store the data
void
    orbital::getURLData()
{
    // variables declarationm
    std::string FILENAME;
    std::string cmd;
    char* line = NULL;
    size_t len = 0;
    
    
    
   // cout << orbital::m_tle_url;
    
    /* Initial memory allocation */
    line = (char *) malloc(100*sizeof(char));
    
    std::string url;
    url += orbital::m_tle_url;
    cmd = ("php -f /Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/source/run.php "+url);

    
    // capture the file required
    cout << std::system(cmd.c_str());
    
    // open the file - we are using c here, it's about 5 times faster
    FILE* fp = fopen("/Users/kwadwooteng-amoko/Desktop/CPP/HelloWorld/source/resource.html", "r");
    
    if (fp == NULL)
        cout<<"failed to open";

    // get information from the file
    // note the getline approach is c
    int x = 0;
    while ((getline(&line, &len, fp)) != -1)
    {
        // using printf() in all tests for consistency
        // printf("%s >>>>", line);
        
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
    
    /* deallocate memory allocation */
    // fclose the file -- again c
    fclose(fp);
    
    // free the memory -- again c
    if (line)
        free(line);
    
};

// Date member function
// store the data
void
    orbital::SetTLEname(string name)
{
    strcpy(m_tle_name,name.c_str());
};

// sets the statellite number
// store the data
void
    orbital::SetSATnumber(int number)
{
    m_satellite_number = number;
};

// sets the classifier field (1 digits)
// store the data
void
    orbital::SetCLASSIFIERfield(std::string field)
{
    strcpy(m_classification,field.c_str());
};

// sets the laumncher year field
// store the data
void
    orbital::SetLAUNCHERyearfield(int field)
{
    m_designator_launch_year = field;
};

// sets the launcher number field
// store the data
void
    orbital::SetLAUNCHERnumberfield(int field)
{
    m_designator_launch_number_of_year = field;
};


// sets the piece designator
// store the data
void
    orbital::SetLAUNCHpiecedesignator(char designator[ARRAY_SIZE_ONE])
{
    strcpy(m_designator_piece_of_launch,designator);
};

// set the epoch year
// store the data
void
    orbital::SetEPOCHyear(int year)
{
    m_epoch_year = year;
};

// set the julian date fraction
// store the data
void
    orbital::SetJULIANdatefraction(double fraction)
{
    m_julian_date_fraction = fraction;
};

// set the ballistic coefficient
// store the data
void
    orbital::SetBALLISTICcoefficient(double coefficient)
{
    m_ballistic_coefficient = coefficient;
};

// extract and store the second derivative
// store the data
void
    orbital::SetSECONDderivativemotion(std::string motion)
{
    strcpy(m_second_derivative_of_motion,motion.c_str());
};

// extract and store the degradation coefficient
// store the data
void
    orbital::SetDRAGRADIATIONcoefficient(std::string coefficient)
{
    strcpy(m_drag_term_or_radition_coefficient,coefficient.c_str());
};

// set the ephemeris details
// store the data
void
    orbital::SetEPHEMERIStype(int type)
{
    m_ephemeris_type = type;
};

// set the element number
// store the data
void
    orbital::SetELEMENTnumber(int number)
{
    m_element_number = number;
};

// set the checksum
// store the data
void
    orbital::SetCHECKsum(int sum)
{
    m_check_sum = sum;
};

// set the satellite number obtained from line 2
// store the data
void
    orbital::SetSATNUMBERline2(int number)
{
    m_satellite_number_2 = number;
};

// set the inclination of the field
// store the data
void
    orbital::SetINCLINATIONfield(double field)
{
    m_satellite_inclination = field;
};

// set the ascension node
// store the data
void
    orbital::SetRIGHTASCENTIONnode(double node)
{
    m_satellite_ascension_node = node;
};

// set the eccentricity coefficient
// store the data
void
    orbital::SetECCENTRICITYcoefficient(double coefficient)
{
    m_satellite_eccentricity_coefficient = coefficient;
};

// set the argument perigree
// store the data
void
    orbital::SetARGUMENTperigree(double perigree)
{
    m_argument_perigree = perigree;
};

// set the mean anomaly
// store the data
void
    orbital::SetMEANanomlay(double anomaly)
{
    m_mean_anomaly = anomaly;
};

// set the mean motion
// store the data
void
    orbital::SetMEANmotion(double motion)
{
    m_mean_motion = motion;
};

// set the epoch and the corresponding checksum
// store the data
void
    orbital::SetREVOLUTIONepochchecksum(double checksum)
{
    m_epoch_checksum = checksum;
};

// set the data from the first line of the tle
// store the data
void
    orbital::SetTLElineone(std::string phrase)
{
    strcpy(m_tle_line_one,phrase.c_str());
};


// set the data from the second line of the tle
// store the data
void
    orbital::SetTLElinetwo(std::string phrase)
{
    strcpy(m_tle_line_two,phrase.c_str());
};



// set all TLE parameters
void
    orbital::SetTLEparameters(std::string spacecraft, std::vector<std::string> parsed_line_one, std::vector<std::string> parsed_line_two)
    {
        std::string phrase;
        char        phrase_c[1];
        
        // set the objects name
        
        orbital::SetTLEname(spacecraft.c_str());
        
        // line number one of the NORAD Set Format
        // set the details
        phrase = parsed_line_one[1];
        phrase = phrase.substr(0, 4);
        orbital::SetSATnumber(stoi(phrase));
        
        phrase = parsed_line_one[1];
        phrase = phrase.substr(5, 5);
        //phrase_c = phrase;
        orbital::SetCLASSIFIERfield(phrase);
        
        phrase = parsed_line_one[2];
        phrase = phrase.substr(0, 2);
        orbital::SetLAUNCHERyearfield(stoi(phrase));
        
        phrase = parsed_line_one[2];
        phrase = phrase.substr(2, 4);
        orbital::SetLAUNCHERnumberfield(stoi(phrase));
        
        phrase = parsed_line_one[2];
        phrase = phrase.substr(5, 5);
        strcpy(phrase_c, phrase.c_str());
        orbital::SetLAUNCHpiecedesignator(phrase_c);
        
        phrase = parsed_line_one[3];
        phrase = phrase.substr(0, 2);
        orbital::SetEPOCHyear(stoi(phrase));
        
        phrase = parsed_line_one[3];
        phrase = phrase.substr(2, 13);
        orbital::SetJULIANdatefraction(stoi(phrase));

        phrase = parsed_line_one[4];
        orbital::SetBALLISTICcoefficient(stod(phrase));
        
        phrase = parsed_line_one[5];
        orbital::SetSECONDderivativemotion(phrase);
        
        phrase = parsed_line_one[6];
        orbital::SetDRAGRADIATIONcoefficient(phrase);
        
        phrase = parsed_line_one[7];
        orbital::SetEPHEMERIStype(stoi(phrase));
        
        phrase = parsed_line_one[8];
        orbital::SetELEMENTnumber(stoi(phrase));
        
        orbital::SetCHECKsum(0);
        
        // line number two of the NORAD Set Format
        // set the details
        
        phrase = parsed_line_two[0];
        orbital :: SetTLElinetwo(phrase);
        
        phrase = parsed_line_two[1];
        orbital :: SetSATNUMBERline2(stoi(phrase));
            
        phrase = parsed_line_two[2];
        orbital :: SetINCLINATIONfield(stod(phrase));
        
        phrase = parsed_line_two[3];
        orbital :: SetRIGHTASCENTIONnode(stod(phrase));
        
        phrase = parsed_line_two[4];
        orbital :: SetECCENTRICITYcoefficient(stoi(phrase));
        
        phrase = parsed_line_two[5];
        orbital :: SetARGUMENTperigree(stod(phrase));
        
        phrase = parsed_line_two[6];
        orbital :: SetMEANanomlay(stod(phrase));
        
        phrase = parsed_line_two[7];
        orbital :: SetMEANmotion(stod(phrase));
        
        phrase = parsed_line_two[8];
        orbital :: SetREVOLUTIONepochchecksum(stod(phrase));
        
        orbital::SetCHECKsumtwo(0);
        
};

// set the checksum
// store the data
void
    orbital::SetCHECKsumtwo(int sum)
{
    m_check_sum = sum;
};

// set the checksum
// store the data
void
    orbital::SetDataFile(std::string TLE)
{
        m_file_name = TLE;
};

// set the checksum
// store the data
void
    orbital::SetURLData(std::string TLE)
{
 
        strcpy(m_tle_url,TLE.c_str());

};


// generate a summary of the TLE
void
    orbital::getTLEsummary()
{
    cout << "\n";
    cout << "TLE {"                 << "\n";
    cout << "   name:  "            << m_tle_name           ;
    cout << "   number:  "          << m_satellite_number                   << "\n";
    cout << "   class:  "           << m_classification                     << "\n";
    cout << "   id:  "              << m_de             << "\n";
    cout << "   date:  "            << m_designator_launch_number_of_year   << "\n";
    cout << "   fdmm:  "            << m_satellite_number                   << "\n";
    cout << "   sdmm:  "            << m_satellite_number                   << "\n";
    cout << "   drag:  "            << m_satellite_number                   << "\n";
    cout << "   ephemeris:  "       << m_satellite_number                   << "\n";
    cout << "   esn:  "             << m_satellite_number                   << "\n";
    cout << "   inclination:  "     << m_satellite_number                   << "\n";
    cout << "   ascension:  "       << m_satellite_number                   << "\n";
    cout << "   eccentricity:  "    << m_satellite_number                   << "\n";
    cout << "   perigee:  "         << m_satellite_number                   << "\n";
    cout << "   anomaly:  "         << m_satellite_number                   << "\n";
    cout << "   motion:  "          << m_satellite_number                   << "\n";
    cout << "   revolution:  "      << m_satellite_number                   << "\n";
    cout << "}";
};
