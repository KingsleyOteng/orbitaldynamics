//
//  dpper.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 06/12/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//



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

#ifndef dpper_hpp
#define dpper_hpp
class dpper
{
    
private:
    
    double
    e3,     ee2,    peo,    pgho,   pho,    pinco,  plo,    se2,
    se3,    sgh2,   sgh3,   sgh4,   sh2,    sh3,    si2,    si3,
    sl2,    sl3,    sl4,    t,      xgh2,   xgh3,   xgh4,   xh2,
    xh3,    xi2,    xi3,    xl2,    xl3,    xl4,    zmol,
    zmos,   inclo,  init,   ep,     inclp,  nodep, argpp,  mp;
    
    double m_twopi, m_pi, m_zns, m_zm, m_zmos, m_t, m_zes, m_znl, m_zel, m_zf, m_sinzf, m_f2, m_f3, m_ses, m_sis, m_sls, m_sghs, m_shs, m_se2, m_si2, m_se3, m_si3, f3, m_sl2, m_sgh2, m_sh2, m_zmol, m_sl3, m_sgh3, m_sgh4, m_sl4, m_sh3;
    
    
public:
    
    // constructors  and destructors
    dpper();
    ~dpper();
    
    void        set_parameters(orbital *model);
    void        set_parameters (double e3, double ee2, double peo,double pgho,double pho,double    pinco,double  plo,    double se2,double se3, double   sgh2, double  sgh3,  double sgh4, double  sh2, double   sh3,  double  si2,    double si3, double sl2, double   sl3,  double  sl4,  double  t, double     xgh2, double  xgh3, double  xgh4,   double xh2, double xh3,    double xi2,  double  xi3, double   xl2, double   xl3,   double xl4, double   zmol,
                                double zmos, double  inclo,  double init,  double  ep,  double   inclp,  double nodep, double argpp,  double mp);
    void        set_model();
    
};

#endif /* dpper_hpp */
