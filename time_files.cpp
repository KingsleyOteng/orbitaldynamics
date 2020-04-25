//
//  time_files.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 28/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// tell the preprocessor
#include "time_files.hpp"
#include <time.h>
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

time_t
time_files::tmTOtime_t   (tm *input)
{   //return
    return mktime(input);
}

char*
time_files::tmTOctime   (tm *input)
{   //return
    time_t out = mktime(input);
    return std::ctime(&out);
}

double
time_files::tmTOjd      (tm* input)
{
    

    
     unsigned long one = 1.0;
     double year = 1900 + input->tm_year;
     double month = input->tm_mon;
     long double day = (double)(input->tm_mday + (double(input->tm_hour))/24 + (double(input->tm_min))/(24*60)  + (double(input->tm_sec))/(24*60*60));
       
       
       double C,D,jd;
       double A = trunc(year/100);
       double B = 2 - A + trunc(A/4);
       double yearp, monthp;
       
       if ((month == 1) or (month == 2))
       {
           yearp = year - 1;
           monthp = month + 12;
       }
       else
       {
           yearp = year;
           monthp = month;
       }
           
       if ((year < 1582) or
           (year == 1582 and month < 10) or
           (year == 1582 and month == 10 and day < 15))
       {
           // before start of Gregorian calendar
           B = 0;
       }
       else
       {
           // after start of Gregorian calendar
           A = trunc(yearp / 100);
           B = 2 - A + trunc(A / 4);
       };
       
       if (yearp < 0)
       {
           C = trunc((365.25 * yearp) - 0.75);
       }
          else
          {
              C = trunc(365.25 * yearp);
          };
              
       D = trunc(30.6001 * (monthp + 1));
       jd = B + C + D + day + 1720994.5;
       std::cout << std::fixed;
    
    return jd;

    
};

double
time_files::time_tTOjd      (string* input)
{
     unsigned long one = 1.0;
    
    std::string* phrase = input;
    
    std::vector<std::string> months = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    
    boost::xpressive::sregex rex = boost::xpressive::sregex::compile( "(\\w+)-(\\w+)-(\\w+) (\\d+):(\\d+):(\\d+)" );
    boost::xpressive::smatch what;
    
    std::tm *tm = {0};
    
    if( regex_match( *phrase, what, rex ) )
    {
    
        
        // determine the current month in digits
        size_t month_number = std::distance(months.begin(),std::find(months.begin(), months.end(), what[2].str()));
        
        
        
        tm->tm_sec = stoi(what[6].str());
        tm->tm_min = stoi(what[3].str());
        tm->tm_hour = stoi(what[4].str());
        tm->tm_mday = stoi(what[3].str());
        tm->tm_mon =  month_number + one;
        tm->tm_year = stoi(what[7].str());
        tm->tm_isdst = 0;
    }
    
   
    return tmTOjd(tm);

    
};

double
time_files::ctimeTOjd     (char* ctime)
{
    unsigned long one = 1.0;
    
    std::string phrase = ctime;
    
    std::vector<std::string> months = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    
    // returns index for the month

    
    boost::xpressive::sregex rex = boost::xpressive::sregex::compile( "(\\w+) (\\w+)  (\\d+) (\\d+):(\\d+):(\\d+) (\\d+)" );
    boost::xpressive::smatch what;
    
    int temp;
    
    std::tm tm = {0};
    //= time_t

    if( regex_match( phrase, what, rex ) )
    {
       
        size_t month_number = std::distance(months.begin(),std::find(months.begin(), months.end(), what[2].str()));
    
            tm.tm_sec = stoi(what[6].str());
            tm.tm_min = stoi(what[3].str());
            tm.tm_hour = stoi(what[4].str());
            tm.tm_mday = stoi(what[3].str());
            tm.tm_mon =  month_number + one;
            tm.tm_year = stoi(what[7].str());
            tm.tm_isdst = 0;
        
    }
    
    return tmTOjd(&tm);
}


double
time_files::deltaJD  (int unit_time, double lapse, double jd_current)
{
    // error check
    //if (unit_time == NULL) return;
    
    switch (unit_time){
        case 1         :    //'YY'
            return (jd_current + (lapse * 365) );
            break;
        case 2            :  //LY
            return (jd_current + (lapse * 366) );
            break;
        case 3           :  //MM
            return (jd_current + (lapse * 30) );
            break;
        case 4           :  //DD
            return (jd_current + (lapse * 1) );
            break;
        case 5           :  //HH
            return (jd_current + (lapse * (1/24) ) );
            break;
        case 6            : //mm
            return (jd_current + (lapse * (1/(24*60))));
                    break;
        case 7          :   //sec
                    return (jd_current + (lapse * (1/(24*60*60))) );
                    break;
        case 8        :     //minsec
                    return (jd_current + (lapse * (1/(24*60*60*100)))  );
            break;
}
    
    return 0;
};

std::tm*
time_files::deltaTM  (int unit_time, double lapse, char* ctime)
{
    // error check
    
    unsigned long one = 1.0;
    
    std::string phrase = ctime;
    
    std::vector<std::string> months = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    
    // returns index for the month
    
    boost::xpressive::sregex rex = boost::xpressive::sregex::compile( "(\\w+) (\\w+)  (\\d+) (\\d+):(\\d+):(\\d+) (\\d+)" );
    boost::xpressive::smatch what;
    
    std::tm *tm = {0};
    std::tm *tm2 = {0};
    if( regex_match( phrase, what, rex ) )
    {
        
        size_t month_number = std::distance(months.begin(),std::find(months.begin(), months.end(), what[2].str()));
    
        tm->tm_sec = stoi(what[6].str());
        tm->tm_min = stoi(what[3].str());
        tm->tm_hour = stoi(what[4].str());
        tm->tm_mday = stoi(what[3].str());
        tm->tm_mon =  month_number + one;
        tm->tm_year = stoi(what[7].str());
        tm->tm_isdst = 0;
        
         switch (unit_time)
         {
                  case 1            : tm2->tm_year += (lapse);           break;
                  case 2            : tm2->tm_mon  += (lapse);           break;
                  case 3            : tm2->tm_mday += (lapse);           break;
                  case 4            : tm2->tm_mday += (lapse);           break;
                  case 5            : tm2->tm_min  += (lapse);           break;
                  case 6            : tm2->tm_sec  += (lapse);           break;
         };
                                          
    };

    return tm2;
}

char*
time_files::deltaCTIME  (int unit_time, double lapse, char* ctime)
{
    // error check
    //if (unit_time == NULL) return;
    
    std::string phrase = ctime;
    std::vector<std::string> months = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
    
    // returns index for the month
    
    // cout << "index" << index << "\n";
    
    boost::xpressive::sregex rex = boost::xpressive::sregex::compile( "(\\w+) (\\w+)  (\\d+) (\\d+):(\\d+):(\\d+) (\\d+)" );
    boost::xpressive::smatch what;
    
    // int temp;
    
    std::tm tm = {0};
    std::tm tm2 = {0};
    if( regex_match( phrase, what, rex ) )
    {
        
        size_t month_number = std::distance(months.begin(),std::find(months.begin(), months.end(), what[2].str()));
        unsigned long one = 1.0;
        
        tm.tm_sec = stoi(what[6].str());
        tm.tm_min = stoi(what[3].str());
        tm.tm_hour = stoi(what[4].str());
        tm.tm_mday = stoi(what[3].str());
        tm.tm_mon =  month_number + one;
        tm.tm_year = stoi(what[7].str());
        tm.tm_isdst = 0;
        
         switch (unit_time)
         {
                  case 1            : tm2.tm_year += (lapse);           break;
                  case 2            : tm2.tm_mon  += (lapse);           break;
                  case 3            : tm2.tm_mday += (lapse);           break;
                  case 4            : tm2.tm_mday += (lapse);           break;
                  case 5            : tm2.tm_min  += (lapse);           break;
                  case 6            : tm2.tm_sec  += (lapse);           break;
         };
                                          
    };
    

    time_t out = mktime(&tm);
    
    return std::ctime(&out);
}
