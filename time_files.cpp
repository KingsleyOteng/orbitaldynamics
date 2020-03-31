//
//  time_files.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 28/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "time_files.hpp"

std::tm*
time_files::jdTOtm      (double jd)
{
    std::tm*                    convertJDtoTM;
    

     double jd_out;
     double C,DBB,E,F,G,I;
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
     
     if (month > 2.5)
     {
         (yearg = D - 4716);
     }
     else
     {
         (yearg = D - 4715);
     }
     std::cout << std::fixed;
     cout << std::setprecision(9) << "dayg" << dayg << "\n";
     cout << std::setprecision(9) << "monthg" << monthg << "\n";
     cout << std::setprecision(9) << "yearg" << yearg << "\n";
     
     double frac_days, days_gg;
     
     frac_days = modf(dayg,&days_gg);
     days_gg = int(days_gg);
     frac_days = dayg - days_gg;
     
     cout<< std::setprecision(9)<<"dayg"<<dayg<<"\n";
     cout<< std::setprecision(9)<<"frac_days"<<frac_days<<"\n";
            
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
    
    return convertJDtoTM;
}
