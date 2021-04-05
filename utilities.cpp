//      Source
//      Overview: Data parsing utilities
//
//      Created by Kwadwo Oteng-Amoko on 22/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//


#include "utilities.hpp"
#include "orbital.hpp"
#include <stdio.h>
#include <boost/algorithm/string/replace.hpp>

using namespace std;

// constructor
utilities::utilities                            ()
{}

// destructor
utilities::~utilities                           ()
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
    utilities::getStringParser                  ()
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

// string parser method
void
    utilities::setStringParser                  (std::string str)
{
    strcpy(parse_input_phrase,str.c_str());
}

// set the Julian date variable
void
    utilities::SetEpochJulianDate               (double epoch)
{
    m_epoch_julian_date_fraction = epoch;
}

// converts Julian dates into the gregorian calendar
void
    utilities::SetSimpleDateFormatLong          ()
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
    utilities::GetSimpleDateFormatLong          ()
{
    double seconds_formatted;
    double minutes_formatted = 0.0;
    double hours_formatted = 0.0;
    
    std::string seconds_string;
    std::string minutes_string;
    std::string hours_string;
    char m_epoch_gregorian_day_of_year_string[75];
    
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

    // generate string expression
    int n;
    if (m_epoch_gregorian_year < 100)
        {
            n=sprintf (m_epoch_gregorian_day_of_year_string, "0%d", m_epoch_gregorian_day_of_year);
        }
    else
        {
            n=sprintf (m_epoch_gregorian_day_of_year_string, "%d", m_epoch_gregorian_day_of_year);
        }
    
    // generate final expression
    if (m_epoch_greogorian_hour < 10)
    {
        sprintf(return_string,"Day %s @ 0%d:%.0f:%s ",m_epoch_gregorian_day_of_year_string, m_epoch_greogorian_hour , m_epoch_gregorian_minute, seconds_string.c_str() );
    }
    else
    {
        sprintf(return_string,"Day %s @ %d:%.0f:%s ",m_epoch_gregorian_day_of_year_string, m_epoch_greogorian_hour , m_epoch_gregorian_minute,  seconds_string.c_str() );
    }
    
    return return_string;
}

void
utilities::RungeKuttaMethod                 ()
{
    
};

void
utilities::ParseDateFile                    (std::string fileName)
{
    
};

std::string
utilities::SatelliteNORADRecord(std::string noradId, std::string indx)
{
    // variables
    int indx_ref;
    string line;
    std::string output;
    smatch match;
    
    // flat file search key
    if      (indx == "Name")                    {indx_ref = 0;}
    else if (indx == "country-orig")            {indx_ref = 1;}
    else if (indx == "country-operator")        {indx_ref = 2;}
    else if (indx == "operator")                {indx_ref = 3;}
    else if (indx == "users")                   {indx_ref = 4;}
    else if (indx == "purpose")                 {indx_ref = 5;}
    else if (indx == "purpose-detailed")        {indx_ref = 6;}
    else if (indx == "orbit")                   {indx_ref = 7;}
    else if (indx == "orbit-type")              {indx_ref = 8;}
    else if (indx == "longitude-geo")           {indx_ref = 9;}
    else if (indx == "perigree")                {indx_ref = 10;}
    else if (indx == "apogee")                  {indx_ref = 11;}
    else if (indx == "eccentricity")            {indx_ref = 12;}
    else if (indx == "inclination")             {indx_ref = 13;}
    else if (indx == "period")                  {indx_ref = 14;}
    else if (indx == "mass-launch")             {indx_ref = 15;}
    else if (indx == "mass-dry")                {indx_ref = 16;}
    else if (indx == "power")                   {indx_ref = 17;}
    else if (indx == "date-launch")             {indx_ref = 18;}
    else if (indx == "lifetime")                {indx_ref = 19;}
    else if (indx == "contractor")              {indx_ref = 20;}
    else if (indx == "contractor-country")      {indx_ref = 21;}
    else if (indx == "launch-site")             {indx_ref = 22;}
    else if (indx == "launch-vehicle")          {indx_ref = 23;}
    else if (indx == "cospar")                  {indx_ref = 24;}
    else if (indx == "norad")                   {indx_ref = 25;}
    else if (indx == "comments")                {indx_ref = 26;}
    else if (indx == "source")                  {indx_ref = 28;}
    else                                        {indx_ref = 0;};
    
    // create a read stream for text file
    ifstream myfile ("/Users/kwadwooteng-amoko/Development/data/UCS-Satellite-Database/database-2020-4-1.txt");
    
     //stream flat file
     if (myfile.is_open())
     {
       while ( getline (myfile,line) )
       {
         // search using the norad id
         regex  regexp("("+noradId+")");
        
         regex regexpsecond(
                            "(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)"
                            );
          
        // where there is a match extract data using a key
        if (regex_search(line, regexp))
           {
               if (regex_search(line, match, regexpsecond) == true)
                    {
                        output = match.str(indx_ref+2);
                    }
           }
       }
       myfile.close();
     }
    else cout << "Unable to open file";
   
    
   // remove the comma present in apogee, perigree, period, mass-launch, dry,mass and power data fields
    if   (
            (indx == "apogee")      ||
            (indx == "perigree")    ||
            (indx == "period")      ||
            (indx == "mass-launch") ||
            (indx == "dry-mass")    ||
            (indx == "power")
         )
    {
        boost::replace_all
        (
            output,
            ",",
            ""
        );
        
        boost::replace_all
        (
            output,
            "\"",
            ""
        );
    };
    
    return
            output;
}
