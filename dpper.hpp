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
    
    
public:
    
    // constructors  and destructors
    dpper();
    ~dpper();
    
    void        set_parameters(orbital *model);
    void        set_model();
    
};

#endif /* dpper_hpp */
