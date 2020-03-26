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
    tm                  *time1, *time2;
    

    std::time_t t;
    
    time1 = std::localtime( &t);
    for (int j=0; j<=9; j++)
    {
        int a = 1;
        for (int k=1; k<=2499; k++)
        {
            a = tan(atan(exp(log(sqrt(a*a))))) + 1;
        }
    }
    

    time2 = std::localtime( &t);
    
    coordinate_transforms ct;
  //  cout
   // cout << "hello time elapse" << '\n';
   //    std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << '\n';
}


