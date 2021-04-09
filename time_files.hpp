// preprocessor instructions
#ifndef time_files_hpp
#define time_files_hpp


// system header files
#include <time.h>
#include <iostream>

// api header files
#include <boost/xpressive/xpressive.hpp>

using namespace std;
//
//  coordinate_transforms.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

//#include "coordinate_transforms.hpp"

class time_files
{
   
    
private:
    std::chrono::milliseconds    time_chrono_format_ms;
    using jd_elapsed             = std::chrono::duration<float, std::ratio<14*24*60*60, 1000000>>;
    time_t                       time_standard_block_format;
    tm*                          time_components_format;
    double                       TimeElapsed;
    
public:
    

     // constructors  and destructors
     time_files();
   ~time_files();

          

     // getters and setters
     void                      setJDtime    (double jd);
     double                    getJDtime    ();
     void                      setTMtime    (int tm_sec, int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year, int tm_isdst);
     std::tm*                  getTMtime    ();
     void                      setCTIMEtime (int tm_sec, int tm_min, int tm_hour, int tm_mday, int tm_mon, int tm_year, int tm_isdst);
     time_t                    getCTIMEtime ();
     
     // time step calculation
     double                     deltaJD         (int unit_time, double lapse, double jd_current);
     std::tm*                   deltaTM         (int unit_time, double lapse,char* ctime);
     time_t                     deltaTIMET      (int unit_time, time_t *tm);
     char*                      deltaCTIME      (int unit_time, double lapse, char* ctime);
     void                       setCurrentTLETime  (char* ctime);
     void                       setTimeElapsed  (double time_now, double epoch);
     double                     getTimeElapsed  ();

    
     // time conversion strings
     std::tm*                    jdTOtm          (double jd);

     time_t                      jdTOtime_t      (double jd);
     char*                       jdTOctime       (double jd);
     double                      time_tTOjd      (char* input);
     double                      tmTOjd          (tm input);
     double                      tmTOmodifiedjd  (tm input);
     double                      tmTOj2000       (tm input);
     char*                       tmTOctime       (tm* input);
     time_t                      tmTOtime_t      (tm* input);
     double                      ctimeTOjd       (char* ctime);
     std::tm*                    ctimeTOtm       (time_t input);
     time_t                      ctimeTOtime_t   (time_t input);
     double                      getTimeDiff  (char*  Time1, char*  Time2);
     double                      getDeltaCtimeFromTLE (std::string dateStringTLE);
     char*                       month_generator_classification_phrase(double days_elapsed);
     char*                       month_generator_classification_number(double days_elapsed);
     char*                       time_elapsed_since_epoch();
     double                      getCheckLaunchDate();
     void                        getCheckLaunchDateV();
     void                        connectToDatabase();
    void                        disconnectToDatabase();
    
};


#endif /* coordinate_transforms_hpp */
