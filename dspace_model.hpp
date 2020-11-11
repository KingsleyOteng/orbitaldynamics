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
    double satrec_d2201;
    double satrec_d2211;
    double satrec_d3210;
    double satrec_d3222;
    double satrec_d4410;
    double satrec_d4422;
    double satrec_d5220;
    double satrec_d5232;
    double satrec_d5421;
    double satrec_d5433;
    double satrec_dedt;
    double satrec_del1;
    double satrec_del2;
    double satrec_del3;
    double satrec_didt;
    double satrec_dmdt;
    double satrec_dnodt;
    double satrec_domdt;
    double satrec_irez;
    double satrec_argpo;
    double satrec_argpdot;
    double satrec_t;
    double tc;
    double satrec_gsto;
    double satrec_xfact;
    double satrec_xlamo;
    double satrec_no;
    double satrec_atime;
    double em;
    double argpm;
    double inclm;
    double satrec_xli;
    double mm;
    double satrec_xni;
    double nodem;
    double nm;
    
    
public:
        dspace_model(double satrec_d2201,double satrec_d2211,double satrec_d3210,
        double satrec_d3222, double satrec_d4410, double satrec_d4422,
        double satrec_d5220,double satrec_d5232,double satrec_d5421,
        double satrec_d5433,double satrec_dedt,double satrec_del1,
        double satrec_del2,double satrec_del3,double satrec_didt,
        double satrec_dmdt,double satrec_dnodt,double satrec_domdt,
        double satrec_irez,double satrec_argpo,double satrec_argpdot,double satrec_t,
        double tc, double satrec_gsto,double satrec_xfact,double satrec_xlamo, double satrec_no,
        double satrec_atime, double em, double argpm, double inclm, double satrec_xli, double mm,
        double satrec_xni,double nodem,double nm);
        dspace_model();
        ~dspace_model();
        void getParameters                        ();
    
    
};
#endif /* dspace_model_hpp */
