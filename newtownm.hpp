//
//  newtownm.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 29/11/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

// header guards
#ifndef newtownm_hpp
#define newtownm_hpp

// preprocessor instructions
#include <cmath>


class newtownm
{
    
private:
    
   // macro defining array size
    
    #define         numiter                    50
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

    

    // this function solves keplers equation when the true anomaly is known.
    // the mean and eccentric, parabolic, or hyperbolic anomaly is also found.
    // the parabolic limit at 168 is arbitrary
    
    void setNewtonM
    (double ecc, double m);
  
};

#endif /* newtownm_hpp */
