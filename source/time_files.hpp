
#ifndef time_files_hpp
#define time_files_hpp

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctime>
#include <string>
#include <iostream>
#include <boost/xpressive/xpressive.hpp>

using namespace std;
//
//  coordinate_transforms.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoko on 09/03/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

//#include "coordinate_transforms.hpp"

class time_files
{
   
    
private:
    std::chrono::milliseconds    time_chrono_format_ms;
    using jd_elapsed             = std::chrono::duration<float, std::ratio<14*24*60*60, 1000000>>;
    time_t                       time_standard_block_format;
    tm*                          time_components_format;
    
public:
   
    
};


#endif /* coordinate_transforms_hpp */
