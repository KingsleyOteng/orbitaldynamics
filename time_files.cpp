//
//  time_files.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 28/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "time_files.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

// constructor
time_files::time_files()
{}


std::tm*
time_files::jdTOtm      (double jd)
{

     double jd_out;
     double A,C,D,BB,E,F,G,I;
     double day_final, month_final, year_final;
     double dayg, monthg, yearg;
    
     jd_out = jd + 0.5;
     F = modf(jd_out, &I);
     I = int(I);
     F = jd_out - I;

     
     A = trunc((I - 1867216.25)/36524.25);
     if (I > 2299160)
     {
         BB = I + 1 + A - trunc(A / 4.);
     }
     else
     {
         BB = I;
     };
     
     C = BB + 1524;
     D = trunc((C - 122.1) / 365.25);
     E = trunc(365.25 * D);
     G = trunc((C - E) / 30.6001);
     dayg = C - E + F - trunc(30.6001 * G);
     
     
     
     if (G < 13.5)
     {
         monthg = G - 1;
     }
     else
     {
         monthg = G - 13;
     }
     
     if (monthg > 2.5)
     {
         (yearg = D - 4716);
     }
     else
     {
         (yearg = D - 4715);
     }
     
     double frac_days, days_gg;
     
     frac_days = modf(dayg,&days_gg);
     days_gg = int(days_gg);
     frac_days = dayg - days_gg;
     
     C = BB + 1524;
     
     D = trunc((C - 122.1) / 365.25);
     
     E = trunc(365.25 * D);
     
     G = trunc((C - E) / 30.6001);
     
     day_final = C - E + F - trunc(30.6001 * G);
     
     if (G < 13.5)
     {
         month_final = G - 1;
     }
     else
     {
         month_final = G - 13;
     }
         
     if (month_final > 2.5)
     {
         year_final = D - 4716;
     }
     else
     {
         year_final = D - 4715;
     }
     
     double frac_hours, hours_gg, hours_final, min_final, seconds_final;
     frac_hours = modf(dayg,&hours_gg);
     hours_final = frac_hours * 24;
     min_final = 60 * (hours_final - (int)(hours_final));
     hours_final = (int) hours_final;
     
     
     seconds_final = ((min_final - (int)(min_final)))*60;
     min_final = (int) (min_final);
    
    std::tm* tm = {0};
       tm->tm_sec = seconds_final;
       tm->tm_min = min_final;
       tm->tm_hour = hours_final;
       tm->tm_mday = day_final;
       tm->tm_mon = month_final;
       tm->tm_year = year_final;
       tm->tm_isdst = 0;
    
    return tm;
}


 time_t
 time_files::jdTOtime_t     (double jd)
 {

     time_t valuable;
     
     valuable =  mktime(jdTOtm(jd));
     return valuable;
 }


char*
time_files::jdTOctime     (double jd)
{

    time_t valuable;
    
    valuable =  mktime(jdTOtm(jd));
    
    return std::ctime(&valuable);
    
}

double
time_files::ctimeTOjd     (char* ctime)
{
    std::string phrase = ctime;
    
    std::vector<std::string> months = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    size_t month_number = std::distance(months.begin(),std::find(months.begin(), months.end(), "MAR"));
    cout << "index" << index << "\n";
    
    boost::xpressive::sregex rex = boost::xpressive::sregex::compile( "(\\w+) (\\w+)  (\\d+) (\\d+):(\\d+):(\\d+) (\\d+)" );
    boost::xpressive::smatch what;
    
    int temp;
    //temp = what[3];
    
    
    
   // int hour_num = int.Parse(what[4]);
   // int minute_num = int(what[5]);
   // int sec_num = int(what[6]);
   // int year_num = int(what[7]);
    
    if( regex_match( phrase, what, rex ) )
    {
        
        int hour_num = stoi(what[4].str());
        int minute_num = stoi(what[5].str());
        int sec_num = stoi(what[6].str());
        int year_num = stoi(what[7].str());
        int day_num = stoi(what[3].str());
        
        cout << "yy" << hour_num << "\n";
        
        cout << "what[0]" << what[0] << "\n";
        cout << "what[1]" << what[1] << "\n";
        cout << "what[2]" << month_number << "\n";
        cout << "what[3]" << what[3] << "\n";
        cout << "what[4]" << what[4] << "\n";
        cout << "what[5]" << what[5] << "\n";
        cout << "what[6]" << what[6] << "\n";
         cout << "what[7]" << what[7] << "\n";
        
       
        
        
        
        std::tm* tm = {0};
        tm->tm_sec = sec_num;
        tm->tm_min = minute_num;
        tm->tm_hour = hour_num;
        tm->tm_mday = day_num;
        //tm->tm_mon = int(month_number);
        tm->tm_year = year_num;
        //tm->tm_isdst = 0;
    }
    return 0;
}
