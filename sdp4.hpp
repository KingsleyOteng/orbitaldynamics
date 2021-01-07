
//
//  sdp4.hpp
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <array>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <cmath>

using namespace std;

#ifndef sdp4_hpp
#define sdp4_hpp



class sdp4
{
    
    public:
    sdp4();
    ~sdp4();
    double      m_vkmpersec, m_pi, m_twopi, m_x2o3, m_temp4, m_xke, m_pixpi, m_radiusearthkm;
    double      m_satrec_t, m_tsince, m_satrec_error, m_mrt;
    void        set_model();
    
    
};

#endif /* sdp4_hpp */



