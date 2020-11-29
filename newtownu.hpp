
//
//  newtownu.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 28/11/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef newtownu_hpp
#define newtownu_hpp


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>
#include <cmath>


class newtownu
{
    
private:
    
   // macro defining array size
   #define         numiter                              50
   #define         small                      256

    
  // members
    double halfpi;
    double ecc;
    double m;
    double e0;
    double e1;
    double ktr;
    double pi;
    double sinv;
    double cosv;
    double nu;
    double s;
    double w;

    
void setNewtonU
    (double ecc, double m);
  
};
#endif /* utilities_hpp */
