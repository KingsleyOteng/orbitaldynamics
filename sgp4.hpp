//
//  sgp4.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef sgp4_hpp
#define sgp4_hpp

#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>
#include "utilities.hpp"
#include "orbital.hpp"
#include <boost/regex.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/regex.hpp>
#include <regex>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

class sgp4
{
    
private:
    
    orbital     *orb;
    utilities   *util;
};

#endif /* sgp4_hpp */
