//
//  dspace_model.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 11/11/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef dspace_model_hpp
#define dspace_model_hpp

#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>
#include <iostream>
#include <vector>       // c-11 vector
#include <algorithm>    // c-11 algoithm
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <array>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "orbital.hpp"
#include "utilities.hpp"

using namespace std;

class dspace_model
{
   
    
private:
    double d2201;
    double d2211;
    double d3210;
    double d3222;
    double d4410;
    double d4422;
    double d5220;
    double d5232;
    double d5421;
    double d5433;
    double dedt;
    double del1;
    double del2;
    double del3;
    double didt;
    double dmdt;
    double dnodt;
    double domdt;
    double irez;
    double argpo;
    double argpdot;
    double t;
    double tc;
    double gsto;
    double xfact;
    double xlamo;
    double no;
    double atime;
    double em;
    double argpm;
    double inclm;
    double satrec_xli;
    double mm;
    double satrec_xni;
    double nodem;
    double nm;
    
    // get the model output parameters
    double dndt;
    
    
public:
        dspace_model(double d2201,double d2211,double d3210,
        double d3222, double d4410, double d4422,
        double d5220,double d5232,double d5421,
        double d5433,double dedt,double del1,
        double del2,double del3,double didt,
        double dmdt,double dnodt,double domdt,
        double irez,double argpo,double rgpdot,double t,
        double tc, double sto,double xfact,double xlamo, double no,
        double satrec_atime, double em, double argpm, double inclm, double xli, double mm,
        double satrec_xni,double nodem,double nm);
        dspace_model();
        ~dspace_model();
        void getModelParameters                        ();
    
    
};
#endif /* dspace_model_hpp */
