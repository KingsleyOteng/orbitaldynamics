//      Source
//      Overview: Data parsing utilities
//
//      Created by Kwadwo Oteng-Amoko on 22/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "utilities.hpp"

using namespace std;

// constructor
utilities::utilities()
{}

// destructor
utilities::~utilities()
{}

// methods
char*
    utilities::getStringParser(std::string str)
{
    // Used to split string around spaces.
    std::istringstream ss(str);
    
    
    // Traverse through all words
    do
        {
            // Read a word
            string word;
            ss >> word;
            word = word + "\n";
            
            // Print the read word
            cout << word << endl;
            
            strcpy(parsed_string,word.c_str());
           // finals = finals + "\n" + word;
            
      
        }
    while (ss); // While there is more to read
    
    return parsed_string;
}
  

std::vector<string>
    utilities::getStringParser()
{
    // Used to split string around spaces.
    std::istringstream ss(parse_input_phrase);
    string final;
    vector<string> detokenized_strings;
    
    // Traverse through all words
    do
        {
            // Read a word
            string word;
            ss >> word;
      
            // Print the read word
            //cout << "><><<" << word << endl;
            //final = final + "\n" + word;
            
            detokenized_strings.push_back(word);
      
        }
    while (ss); // While there is more to read
    
    return detokenized_strings;
}

void
    utilities::setStringParser(std::string str)
{
    strcpy(parse_input_phrase,str.c_str());
}

void
    utilities::setEpochJulianDate(int ut, int dd, int mm, int YYYY)
{
      
    m_epoch_julian_date = 367*YYYY - int(7*(YYYY + int((mm+9)/12))/4) - int(3*(int((YYYY + (mm-9)/7)/100)+1)/4) + int(275*mm/9) + dd + 1721028.5 + ut/24;

};

void
    utilities::setEpochJulianDate(double julian_date)
{
      
    m_epoch_julian_date = julian_date;

};

void
    utilities::setSimpleFormatDate()
{
      
    0;

};
char*
    utilities::getSimpleFormatDate()
{
      
    return simple_date_buffer;

};

double
    utilities::getEpochJulianDate()
{
      
    return m_epoch_julian_date;

};

void
    utilities::SetSimpleDateFormatLong()
{
    //double juliandate = m_epoch_julian_date;
    m_epoch_gregorian_day_of_year = int(m_epoch_julian_date);
    m_epoch_gregorian_year = int(m_epoch_julian_date);
    m_epoch_greogorian_hour = m_epoch_gregorian_year - int(m_epoch_julian_date);
    m_epoch_gregorian_minute =  m_epoch_greogorian_hour - int(m_epoch_greogorian_hour);
    m_epoch_gregorian_second =  double(m_epoch_gregorian_minute - int(m_epoch_gregorian_minute));
};

