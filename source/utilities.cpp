//      Source
//      Overview: Data parsing utilities
//
//      Created by Kwadwo Oteng-Amoko on 22/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "utilities.hpp"
#include "orbital.hpp"

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

void
    utilities::SetSimpleDateFormatLong()
{
    
    //double juliandate = m_epoch_julian_date;
    cout<<"m_epoch_julian_date "<<m_epoch_julian_date_fraction<<"\n";
    m_epoch_gregorian_day_of_year = int(m_epoch_julian_date_fraction);
    cout<<"m_epoch_gregorian_day_of_year "<<m_epoch_gregorian_day_of_year<<"\n";
    m_epoch_greogorian_hour = int(24*(m_epoch_julian_date_fraction - m_epoch_gregorian_day_of_year));
    cout<<"m_epoch_greogorian_hour "<<m_epoch_greogorian_hour<<"\n";
    m_epoch_gregorian_minute = 60 * ((24*(m_epoch_julian_date_fraction - m_epoch_gregorian_day_of_year)) - int(m_epoch_greogorian_hour));
    cout<<"m_epoch_gregorian_minute "<<(int)m_epoch_gregorian_minute<<"\n";
    m_epoch_gregorian_second = 60 * (m_epoch_gregorian_minute - (int)m_epoch_gregorian_minute);
    cout<<"m_epoch_gregorian_second "<<(int)m_epoch_gregorian_second<<"\n";
    m_epoch_gregorian_splits = (m_epoch_gregorian_second - (int)m_epoch_gregorian_second);
    cout<<"m_epoch_gregorian_splits "<<m_epoch_gregorian_splits<<"\n";
}

double
    utilities::GetEpochJulianDate()
{
    return m_epoch_julian_date;
}

char*
    utilities::GetSimpleDateFormatLong()
{
    return "hello";
}
