
//
//  newtownu.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 28/11/2020.
//  Copyright © 2020,2021 Kingsley Kwadwo Oteng-Amoko. All rights reserved.
//

// header guards
#ifndef newtownu_hpp
#define newtownu_hpp


// preprocessor instructions
#include <cmath>

// class defintions
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

    
    //  this function performs the newton rhapson iteration to find the
    //  eccentric anomaly given the mean anomaly.  the true anomaly is also
    //  calculated.
    
    void setNewtonU
    (double ecc, double m);
  
};
#endif /* utilities_hpp */
