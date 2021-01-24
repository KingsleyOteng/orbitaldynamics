//
//  mag.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 13/01/2021.
//  Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <array>
#include <iterator>
#include <cmath>

using namespace std;

#ifndef mag_hpp
#define mag_hpp



class mag
{
    
    private:
        
        double m_mag;
        double magv1;
        double magv2;
        double temp;
        double m_vec[4];
    double m_vec_2;
    
    public:
    double theta;
        mag();
        ~mag();
        mag(double vec[]);
        mag(double vec);
        mag(double vec1, double vec2);
        double setMag(double vec);
    
};

#endif /* sdp4_hpp */


