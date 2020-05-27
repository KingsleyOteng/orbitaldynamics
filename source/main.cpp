//
//      Overview: We implement here a tracking tool based off of NORAD Two-Line Element Sets.
//      We then propogage using SGP4 and also higher
//
//      Created by Kwadwo Oteng-Amoko on 14/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// preprocessor instructions
#include <iostream>
#include <vector>                      // c-11 vector
#include <algorithm>                   // c-11 algoithm
#include "orbital.hpp"                 // header files
#include "Benchmarking.hpp"            // benchmarking routines
#include "time_files.hpp"
#include "coordinate_transforms.hpp"   // coordinate transforms library
#include "utilities.hpp"               // my own routines for processing data
#include <boost/any.hpp>               // boost standard library
#include <boost/asio.hpp>              // io streaming headers
#include <boost/lambda/lambda.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <cmath>

using namespace std;

int main()
{
   // boost::regex e;

    //std::vector<int> v{1,2,3};
    orbital *orb = new orbital(12,13,14);
    utilities *util = new utilities();
    
    //
    
    // map to the TLE resoure
    // then open the resource
    orb -> SetURLData("https://celestrak.com/satcat/tle.php?CATNR=43108");
    orb -> getURLData();
   
    
    // summary of the current NORAD two-line elements details
    std::cout << "\nSatellite name: \n \n"      << orb ->
                                                    getTLEname() << "\n";
    std::cout << "\nNORAD TLE line one: \n \n"  << orb ->
                                                    getTLElineone() << "\n";
    std::cout << "\nNORAD TLE line two: \n \n"  << orb ->
                                                    getTLElinetwo() << "\n\n";
    
    // back out TLE parameters
    util -> setStringParser(orb -> getTLElineone ());
    vector<string> parsed_line_ones             = util ->
                                                    getStringParser();
    
    util -> setStringParser(orb -> getTLElinetwo ());
    vector<string> parsed_line_twos             = util ->
                                                    getStringParser();
    
    // store TLE parameters
    orb->SetTLEparameters(orb -> getTLEname(), parsed_line_ones, parsed_line_twos);
    
   // std::cout << "Phrase" <<
    
    std::cout << "Line Number of Element Data : " << "\n";
    std::cout << "Satellite Number : " << orb->getTLEname() << "\n";
    std::cout << "Classification (U=Unclassified) : " << orb->getCLASSIFIERfield() << "\n";
    std::cout << "International Designator (Last two digits of launch year) : "<< orb->getLAUNCHERyearfield() << "\n";
    std::cout << "International Designator (Launch number of the year) : " << orb->getLAUNCHERnumberfield() << "\n";
    std::cout << "International Designator (Piece of the launch) : " << orb->getLAUNCHpiencedesignator() <<  "\n";
    std::cout << "International Designator (Epoch Year (Last two digits of year) : " << orb->getEPOCHyear() << "\n";
    std::cout << "International Designator (Epoch (Day of the year and fractional portion of the day)) : " << orb->getJULIANdatefraction() << "\n";
    std::cout << "First Time Derivative of the Mean Motion : " << orb->getBALLISTICcoefficient() << "\n";
    std::cout << "Second Time Derivative of Mean Motion (Leading decimal point assumed) : " << orb->getSECONDderivativemotion() << "\n";
    std::cout << "BSTAR drag term (Leading decimal point assumed) : " << orb->getDRAGRADIATIONcoefficient() << "\n";
    std::cout << "Ephemeris type : " << orb->getEPHEMERIStype() << "\n";
    std::cout << "Checksum (Modulo 10) (Letters, blanks, periods, plus signs = 0; minus signs = 1) : " << orb->getELEMENTnumber() << "\n";
    
    std:cout  << "line two" << "\n";
    
    orb -> getTLEsummary();
    util -> SetEpochJulianDate(orb->getJULIANdatefraction());
    util -> SetSimpleDateFormatLong();
    cout << util -> GetSimpleDateFormatLong() << "\n";
    
    coordinate_transforms *ct = new coordinate_transforms();
    
    // do the GMST and GST conversion
    ct -> setTimeElapsedSinceJDIndex(30000000);
    ct -> setGST();
    ct -> setGMST();
    
    //cout << ct -> gmst;
    
    benchmarking *b = new benchmarking();
    b->getBenchMarking();
    
    // generate a julian date time string
    cout << "time conversion" << ct->setTimeConversionM(util -> GetSimpleDateFormatLong(),"20") << "\n";
    
    
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    cout << "current time" << std::ctime(&end_time) << "\n";

    
    std::tm tm = {0};
       tm.tm_sec = 45.57;
       tm.tm_min = 0;
       tm.tm_hour = 6;
       tm.tm_mday = 17;
       tm.tm_mon = 2;
       tm.tm_year = 85;
       tm.tm_isdst = 0;
       // Convert std::tm to std::time_t (popular extension)
       std::time_t tt = timegm(&tm);
       // Convert std::time_t to std::chrono::system_clock::time_point
       std::chrono::system_clock::time_point tp =
                                        std::chrono::system_clock::from_time_t(tt);
    
    //Algorithm from 'Practical Astronomy with your Calculator or Spreadsheet',
    //       4th ed., Duffet-Smith and Zwart, 2011.
    
    double year = 1900 + tm.tm_year;
    double month = tm.tm_mon;
    long double day = (double)(tm.tm_mday + (double(tm.tm_hour))/24 + (double(tm.tm_min))/(24*60)  + (double(tm.tm_sec))/(24*60*60));
    
    cout << "(double)(tm.tm_mday + (tm.tm_hour /24))" << (double(tm.tm_hour))/24 << "\n";
    
    cout << "month" << month << "\n";
    cout << "day" << day << "\n";
    cout << "year" << year << "\n";
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
    cout << "jd" << jd <<"\n";
    
//Algorithm from 'Practical Astronomy with your Calculator or Spreadsheet',
    //       4th ed., Duffet-Smith and Zwart, 2011.
    
    double jd_out;
    double BB,E,F,G,I;
    double day_final, month_final, year_final;
    jd_out = jd + 0.5;
    std::cout << std::fixed;
    cout  << "jd_out" << jd_out<<"\n";
    F = modf(jd_out, &I);
    double dayg, monthg, yearg;
   
    I = int(I);
     F = jd_out - I;
    cout<<"frac"<<F<<"\n";
    cout<<"int"<<I<<"\n";
    
    A = trunc((I - 1867216.25)/36524.25);
     cout << "A " << A << "\n";
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
    std::cout << std::fixed;
    cout  << "dayg" << dayg << "\n";
    cout << "monthg" << monthg << "\n";
    cout  << "yearg" << yearg << "\n";
    
    double frac_days, days_gg;
    
    frac_days = modf(dayg,&days_gg);
    days_gg = int(days_gg);
    frac_days = dayg - days_gg;
    
    cout<<"dayg"<<dayg<<"\n";
    cout<<"frac_days"<<frac_days<<"\n";
           
    cout<<"B"<<BB   <<"\n";
    cout << "A" << A << "\n";
    cout << "I" << I << "\n";
    cout << "BB" << BB << "\n";
    
    C = BB + 1524;
    
    D = trunc((C - 122.1) / 365.25);
    
    E = trunc(365.25 * D);
    
    G = trunc((C - E) / 30.6001);
    
    day_final = C - E + F - trunc(30.6001 * G);
    
    cout<<"day_final"<<day_final;
    
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
    cout << "frac_hours" << frac_hours << "\n";
    cout << "hours_gg" << hours_gg << "\n";
    hours_final = frac_hours * 24;
    min_final = 60 * (hours_final - (int)(hours_final));
    hours_final = (int) hours_final;
    
    
    seconds_final = ((min_final - (int)(min_final)))*60;
    min_final = (int) (min_final);
    
    cout << "time from " << std::chrono::system_clock::to_time_t(tp) << "\n";
    cout << "time year " << 1990 + tm.tm_year << "\n";
    cout << "time year " << trunc(365.25 * (1990 + year - 1)) + trunc(30.600001 * 14) + 1720994.5 + BB << "\n";
    cout << "julian date" << jd << "\n";
    cout << "year from julian date" << year_final << "\n";
    cout << "month from julian date" << month_final << "\n";
    cout << "day from julian date" << day_final << "\n";
    cout << "hours from julian date" << hours_final << "\n";
    cout << "minutes from julian date" << min_final << "\n";
    cout << "seconds from julian date" << round(seconds_final) << "\n";
    
    cout << "local: " << put_time(&tm, "%c %Z") << '\n';
    
    time_files* nf = new time_files();
    cout << nf->time_tTOjd ("2005-07-24 17:48:11") << "\n";
    cout << nf->ctimeTOjd  ("Sun Jul  24 17:48:11 2005") << "\n";
    double xx = nf->ctimeTOjd  ("Sun Jul  24 17:48:11 2005");
    cout << nf->jdTOctime(xx);
    //deltaCTIME
    // https://www.satellite-calculations.com/TLETracker/SatTracker.htm
    //cout << nf->deltaCTIME("Day 040 @ 09:58:04.421280") << "\n";
    return 61;
}
