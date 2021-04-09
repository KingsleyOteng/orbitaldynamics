//      Headers
//      Overview: Extraction of object tracking data from NORAD TLE
//
//      Created by Kwadwo Oteng-Amoko on 22/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// preprocessor instructions
#ifndef utilities_hpp
#define utilities_hpp

// system header files
#include <regex>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

// api header files
#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/regex.hpp>



class utilities
{
    
private:
    
   // macro defining array size
   #define         ARRAY_SIZE                              50
   #define         ARRAY_LARGE_BUFFER                      256
   #define         ARRAY_EXTRA_LARGE_BUFFER                4096
   #define         JULIAN_AHEAD_OF_UTC                     68.184
   #define         JULIAN_DAY_OFFSET                       0.5
    
  // members
  char             parse_input_phrase                       [ARRAY_SIZE];
  char             parsed_string                            [ARRAY_SIZE];
  double           m_epoch_julian_date;
  double           m_epoch_julian_date_fraction;
  int              m_epoch_julian_day;
  int              m_epoch_julian_month;
  int              m_epoch_julian_year;
  int              m_epoch_gregorian_year;
  int              m_epoch_gregorian_day_of_year;
  int              m_epoch_greogorian_hour;
  double           m_epoch_gregorian_minute;
  double           m_epoch_gregorian_second;
  double           m_epoch_gregorian_splits;
  char             simple_date_buffer                       [ARRAY_LARGE_BUFFER];
  char             return_string                            [ARRAY_EXTRA_LARGE_BUFFER];
  struct           tm *ptr = new struct tm();

public:

  // constructors  and destructors
  utilities();
 ~utilities();
       

  // getters and setters
  // setters
  void                      setStringParser                  (std::string str);
  char*                     getStringParser                  (std::string str);
  std::vector<std::string>  getStringParser                  ();

    
  // getters
  void                      SetEpochJulianDate               (double epoch);
  void                      SetSimpleDateFormatLong          ();

  char*                     GetSimpleDateFormatLong          ();
  double                    GetEpochJulianDate               ();
  std::string               GetSatelliteLog                  (std::string phrasalmatching);
  std::string               SatelliteNORADRecord             (std::string noradId, std::string indx);
  void                      RungeKuttaMethod                 ();
  void                      ParseDateFile                    (std::string fileName);
};
#endif /* utilities_hpp */
