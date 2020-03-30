//
//  BenchMarking.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 26/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "BenchMarking.hpp"

void benchmarking::
getBenchMarking                         ()
{
    
    std::string         i,j;
    std::string         test_type;
    double              start,stop,dt;
    //clock_t             time1,time2;
    tm                  *time_stamp1, *time_stamp2;
     double a = 1;
    
    // start timer
    auto begins = chrono::steady_clock::now();

    std::time_t t;
    
    // we take an initial time stamp
    time_stamp1 = std::localtime( &t);
    cout << "time 1: " << time_stamp1->tm_sec << '\n';
    
    // we then run 1 billion iterations
    for (int j=0; j<=20; j++)
    {
        a = 1;
        for (int k=1; k<10000; k++)
        {
            a = tan(atan(exp(log(sqrt(a*a))))) + 1;
        }
    }
    // end timer
    auto ends = chrono::steady_clock::now();
    // take the final stamp
    std::time_t t2;
    time_stamp2 = std::localtime( &t2);
    cout << "time 2: " << time_stamp2->tm_sec << '\n';
    
    coordinate_transforms *ct = new coordinate_transforms();
    
    ct->setJulianDateFractionOfDay(mktime(time_stamp1));
    start = ct->getJulianDateFractionOfDay();
    
    ct->setJulianDateFractionOfDay(mktime(time_stamp2));
    stop = ct->getJulianDateFractionOfDay();
 
    
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(ends - begins);
    cout << "clocked at: " << int_ms.count() <<'\n';
    cout << "Aggregate mean was: " << a << '\n';
}


void benchmarking::
getBenchMarkingChrono                         ()
{
    std::time_t         t;
    std::string         i,j;
    std::string         test_type;
    double              start,stop,dt;
    //clock_t             time1,time2;
    tm                  *time_stamp1, *time_stamp2;
     double a = 1;
    
    // start chrono timer
    auto begins = chrono::steady_clock::now();

    
    
    // we take an initial time stamp
    time_stamp1 = std::localtime( &t);
    cout << "time 1: " << time_stamp1->tm_sec << '\n';
    
    // we then run 1 billion iterations
    for (int j=0; j<=20; j++)
    {
        a = 1;
        for (int k=1; k<=100000; k++)
        {
            a = tan(atan(exp(log(sqrt(a*a))))) + 1;
        }
    }
    // end chrono timer
    auto ends = chrono::steady_clock::now();
    
    // take the final stamp
    std::time_t t2;
    time_stamp2 = std::localtime( &t2);
    cout << "time 2: " << time_stamp2->tm_sec << '\n';
    
    coordinate_transforms *ct = new coordinate_transforms();
    
    ct->setJulianDateFractionOfDay(mktime(time_stamp1));
    start = ct->getJulianDateFractionOfDay();
    
    ct->setJulianDateFractionOfDay(mktime(time_stamp2));
    stop = ct->getJulianDateFractionOfDay();
 
    
    auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(ends - begins);
    cout << "clocked at: " << int_ms.count() <<'\n';
    cout << "Aggregate mean was: " << a << '\n';
}


