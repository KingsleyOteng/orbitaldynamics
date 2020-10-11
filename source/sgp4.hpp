//
//  sgp4.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>
#include "orbital.hpp"
#include "utilities.hpp"

using namespace std;

#ifndef sgp4_hpp
#define sgp4_hpp
class sgp4
{
    
    private:
    
        orbital *orb;
        utilities *util;
    
    public:

     // constructors  and destructors
        sgp4();
       ~sgp4();
    
    //void    sgp4::builds();
};

#endif /* sgp4_hpp */


