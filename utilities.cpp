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

// string parser method
void
    utilities::setStringParser(std::string str)
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

// returns the Julian date variable
double
    utilities::GetEpochJulianDate()
{
    return m_epoch_julian_date;
}

// extracts data from a flat file
std::string
    utilities::GetSatelliteLog(std::string phrasalmatching)
{
    const std::string x = "'NIUSat (Noorul Islam University Satellite)' 'India' 'India' 'Noorul Islam University'    'Civil'    'Technology Development'";
    
    const std::string s = "01/02/2003 blahblah 04/23/1999 blahblah 11/13/1981";
    
       std::regex words_regex("('\\w+)|(\\(\\w+)|(\\w+)|(\\w+')");
       auto words_begin =
           std::sregex_iterator(x.begin(), x.end(), words_regex);
       auto words_end = std::sregex_iterator();
    
       std::cout << "Found "
                 << std::distance(words_begin, words_end)
                 << " words:\n";
    
       for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
           std::smatch match = *i;
           std::string match_str = match.str();
           std::cout << match_str << '\n';
       }
    
    return "0";
}


void
utilities::SatelliteNORADRecord(std::string noradId, std::string indx)
{

    int indx_ref;
    string line;
    
    if (indx == "Name") {indx_ref = 0;}
    else if (indx == "country-orig") {indx_ref = 1;}
    else if (indx == "country-operator") {indx_ref = 2;}
    else if (indx == "operator") {indx_ref = 3;}
    else if (indx == "users") {indx_ref = 4;}
    else if (indx == "purpose") {indx_ref = 5;}
    else if (indx == "purpose-detailed") {indx_ref = 6;}
    else if (indx == "orbit") {indx_ref = 7;}
    else if (indx == "orbit-type") {indx_ref = 8;}
    else if (indx == "longitude-geo") {indx_ref = 9;}
    else if (indx == "perigree") {indx_ref = 10;}
    else if (indx == "apogee") {indx = 11;}
    else if (indx == "eccentricity") {indx = 12;}
    else if (indx == "inclination") {indx = 13;}
    else if (indx == "period") {indx = 14;}
    else if (indx == "mass-launch") {indx = 15;}
    else if (indx == "mass-dry") {indx = 16;}
    else if (indx == "power") {indx = 17;}
    else if (indx == "date-launch") {indx = 18;}
    else if (indx == "lifetime") {indx = 19;}
    else if (indx == "contractor") {indx = 20;}
    else if (indx == "contractor-country") {indx = 21;}
    else if (indx == "launch-site") {indx = 22;}
    else if (indx == "launch-vehicle") {indx = 23;}
    else if (indx == "cospar") {indx = 24;}
    else if (indx == "norad") {indx = 25;}
    else if (indx == "comments") {indx = 26;}
    else if (indx == "source") {indx = 28;}
    else {indx = 0;};
    
    // create a read stream for the text file
     ifstream myfile ("example.txt");
    
    //open the file stream
     if (myfile.is_open())
     {
       while ( getline (myfile,line) )
       {
         regex
           regexp("("+noradId+")");
         regex regexpsecond("(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)\t(.*?)");
           
           cout << "("+noradId+")" << "\n";
         smatch match;
           if (regex_search(line, regexp))
           {
             cout<< line;
             
            if (regex_search(line, match, regexpsecond) == true)
            {
  
                          //for (int xI = 1; xI < match.size() - 1; xI++)
                            {
                                cout <<"nth capturing group is>>>>>>>>>>>>>>>> '" << match.str(indx) <<"\n";
                            }
             }
         }
       }
       myfile.close();
     }
     else cout << "Unable to open file";
   

    //no return value.
   
}
