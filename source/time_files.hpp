#ifndef time_files_hpp
#define time_files_hpp

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctime>
#include <string>
#include <iostream>
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
     
     std::tm*                   jdTOtm          (double jd);
     time_t                     jdTOtime_t      (double jd);
     char*                      jdTOctime       (double jd);
     double                     tmTOjd          (tm* input);
     char*                      tmTOctime       (tm* input);
     time_t                     tmTOtime_t      (tm* input);
     double                     ctimeTOjd       (time_t input);
     std::tm*                   ctimeTOtm       (time_t input);
     time_t                     ctimeTOtime_t   (time_t input);
};


#endif /* coordinate_transforms_hpp */
