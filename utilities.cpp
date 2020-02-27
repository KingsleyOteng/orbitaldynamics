//      Source
//      Overview: Data parsing utilities
//
//      Created by Kwadwo Oteng-Amoko on 22/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "utilities.hpp"
#include "orbital.hpp"
#include <stdio.h>

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
    utilities::SetEpochJulianDate               (double epoch)
{
    m_epoch_julian_date_fraction = epoch;
}

// converts Julian dates into the gregorian calendar
void
    utilities::SetSimpleDateFormatLong()
{
    
    m_epoch_gregorian_day_of_year = int(m_epoch_julian_date_fraction);
    m_epoch_greogorian_hour = int(24*(m_epoch_julian_date_fraction - m_epoch_gregorian_day_of_year));
    m_epoch_gregorian_minute = 60 * ((24*(m_epoch_julian_date_fraction - m_epoch_gregorian_day_of_year)) - int(m_epoch_greogorian_hour));
    m_epoch_gregorian_second = 60 * (m_epoch_gregorian_minute - (int)m_epoch_gregorian_minute);
    m_epoch_gregorian_minute = int(m_epoch_gregorian_minute);
    m_epoch_gregorian_splits = (m_epoch_gregorian_second - (int)m_epoch_gregorian_second);
    m_epoch_gregorian_second = int (m_epoch_gregorian_second);

}

// returns string of the Julian to Gregorian date conversion
char*
    utilities::GetSimpleDateFormatLong()
{
    char return_string [4096];
    double seconds_formatted;
    double minutes_formatted = 0.0;
    double hours_formatted = 0.0;
    
    std::string seconds_string;
    std::string minutes_string;
    std::string hours_string;
    
    // generate seconds with splits expression.
        seconds_formatted = m_epoch_gregorian_second + m_epoch_gregorian_splits;
    
    
    // format the notation for military time
    if (seconds_formatted < 10)
    {
        seconds_string = "0" + std::to_string(seconds_formatted);
    }
    
    // format the notation for military time
       if (m_epoch_gregorian_minute < 10)
       {
           minutes_string = "0" + std::to_string(minutes_formatted);
       }
    
    // format the notation for military time
       if (m_epoch_greogorian_hour < 10)
       {
           hours_string = "0" + std::to_string(hours_formatted);
       }

    // generate final expression
    if (m_epoch_greogorian_hour < 10)
    {
        sprintf(return_string,"Day %d @ 0%d:%.0f:%s \n",m_epoch_gregorian_day_of_year, m_epoch_greogorian_hour , m_epoch_gregorian_minute, seconds_string.c_str() );
    }
    else
    {
        sprintf(return_string,"Day %d @ %d:%.0f:%s \n",m_epoch_gregorian_day_of_year, m_epoch_greogorian_hour , m_epoch_gregorian_minute,  seconds_string.c_str() );
    }
    
    return return_string;
}

double
    utilities::GetEpochJulianDate()
{
    return m_epoch_julian_date;
}


