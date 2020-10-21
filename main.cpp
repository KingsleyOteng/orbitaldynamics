//
//      Overview: We implement here a tracking tool based off of NORAD Two-Line Element Sets.
//      We then propogage using SGP4 and also higher
//
//      Created by Kwadwo Oteng-Amoko on 14/01/2020.
//      Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// preprocessor instructions
//#include "jni.h"
#include <iostream>
#include <vector>                      // c-11 vector
#include <algorithm>                   // c-11 algoithm
#include "orbital.hpp"                 // header files
#include "Benchmarking.hpp"            // benchmarking routines
#include "time_files.hpp"
#include "sgp4.hpp"
#include "sdp4.hpp"
#include <mysql.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <array>
#include <iterator>
#include <stdlib.h>
#include "coordinate_transforms.hpp"   // coordinate transforms library
#include "utilities.hpp"               // my own routines for processing data
#include <boost/any.hpp>               // boost standard library
#include <boost/asio.hpp>              // io streaming headers
#include <boost/lambda/lambda.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <cmath>
#include <string>
#include <iostream>

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;
//using namespace soci;
// https://medium.com/@dane.bulat/working-with-databases-in-c-an-introduction-7d6a6a78ae66
double frac_hours, hours_example, hours_final, min_final, seconds_final;
const string server = "156.67.222.64";
const string username = "u311839917_koteng";
const string password = "Mypass1234!";
time_files* nf = new time_files();
double ctime_example;

int main()
{
   // boost::regex e;

    //std::vector<int> v{1,2,3};
    orbital *orb = new orbital(12,13,14);
    utilities *util = new utilities();
    std::tm tm = {0};
    double year = 1900 + tm.tm_year;
    double month = tm.tm_mon;
    long double day = (double)(tm.tm_mday + (double(tm.tm_hour))/24 + (double(tm.tm_min))/(24*60)  + (double(tm.tm_sec))/(24*60*60));
    double C,D,jd;
    double A = trunc(year/100);
    double B = 2 - A + trunc(A/4);
    double yearp, monthp;
    double jd_out;
    double BB,E,F,G,I;
    double day_final, month_final, year_final;
    double dayg, monthg, yearg;
    double frac_days, days_gg;
    
    // map to the TLE resoure
    // then open the resource
    orb -> setURLData("https://celestrak.com/satcat/tle.php?CATNR=43108");
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
    //util -> ReadLineByLine();
    
    vector<string> parsed_line_ones             = util ->
                                                    getStringParser();
    
    util -> setStringParser(orb -> getTLElinetwo ());
    vector<string> parsed_line_twos             = util ->
                                                    getStringParser();
    
    // store TLE parameters
    orb->SetTLEparameters(orb -> getTLEname(), parsed_line_ones, parsed_line_twos);
    
    std:cout  << "line one: " << "\n";
    std::cout << "Line Number of Element Data : " << "\n";
    std::cout << "Satellite Name : " << orb->getTLEname() << "\n";
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
    
    std::cout  << "line two: " << "\n";
    orb -> getTLEsummary();
    util -> SetEpochJulianDate(orb->getJULIANdatefraction());
    util -> SetSimpleDateFormatLong();
    std::cout << util -> GetSimpleDateFormatLong() << "\n";
    
    coordinate_transforms *ct = new coordinate_transforms();
    
    // do the GMST and GST conversion
    ct -> setTimeElapsedSinceJDIndex(30000000);
    ct -> setGST();
    ct -> setGMST();
    
    benchmarking *b = new benchmarking();
    b->getBenchMarking();
    
    // generate a julian date time string
    cout << "time conversion" << ct->setTimeConversionM(util -> GetSimpleDateFormatLong(),"20") << "\n";
    
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    cout << "current time" << std::ctime(&end_time) << "\n";

    
 
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
    
//Algorithm from 'Practical Astronomy with your Calculator or Spreadsheet',
    //       4th ed., Duffet-Smith and Zwart, 2011.
    

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
    std::cout << std::fixed;
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
    
    frac_hours = modf(dayg,&hours_example);
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
    cout << "time_t: "  << nf->time_tTOjd ("2005-07-24 17:48:11") << "\n";
    cout << "conversion from ctime: " << nf->ctimeTOjd  ("Sun Jul  24 17:48:11 2005") << "\n";
    ctime_example = nf->ctimeTOjd  ("Sun Jul  24 17:48:11 2005");
    cout << "ctime: " << nf->jdTOctime(ctime_example) << "\n";
    cout << "delta ctime: " << nf->getDeltaCtimeFromTLE("20040.41532895") << "\n";
    nf->getCheckLaunchDateV();
  
    // https://www.satellite-calculations.com/TLETracker/SatTracker.htm
    cout << "Day to Month: " << nf->month_generator_classification_phrase(80);
    
    ///TESTING  FOR JULIAND DATE CALCULATOR (COMPLETED)
       tm.tm_sec = 0;
       tm.tm_min = 0;
       tm.tm_hour = 0;
       tm.tm_mday = 5;
       tm.tm_mon = 6;
       tm.tm_year = 120;
       tm.tm_isdst = 1;
    
    cout << "\n" << "julian date: " << nf->tmTOjd(tm) << "\n";
    
    ///TESTING  FOR MODIFIED JULIAN DATE CALCULATOR (COMPLETED)
    cout << "\n" << "modified julian " << nf->tmTOmodifiedjd(tm) << "\n";
    
    ///TESTING  FOR J2000 DATE CALCULATOR (COMPLETED)
    cout << "\n" << "j2000 date " << nf->tmTOj2000(tm) << "\n";
    
    ///TESTING GET SATELLITE NUMBER LINE 1 (COMPLETED)
    cout << "\n" << "satellite number " << orb->getSATnumber() << "\n";
    
    ///TESTING GET SATELLIT INTERNATIONAL DESIGNATOR (COMPLETED)
    cout << "\n" << "satellite id " << orb->getClassifierID() << "\n";
    
    ///TESTING GET NUMBER OF ORBITS AT EPOCH (COMPLETED)
    cout << "\n" << "revolutions " << orb->getREVOLUTIONepochchecksum() << "\n";
    
    // Let's grab a record using the NORAD ID and query the record for launch details
    // -----> The goal of this code was to check the launchdate
    // Psalm 19:12
    std::string query_field = "apogee";
    std::string query_output = util -> SatelliteNORADRecord("43108", query_field);
    cout << "record> " << query_field <<  " " << query_output << "\n";
    
    // let's introduce sgp4
    // exit
    return 61;
}
