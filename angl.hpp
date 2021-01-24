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
#include "mag.cpp"

using namespace std;

#ifndef angl_hpp
#define angl_hpp



class angl
{
    
    private:
        double theta;
        double m_angl;
        double small;
        double undefined;
        double magv1;
        double magv2;
        double temp;

    
    public:
        angl(double m_vec_1[], double m_vec_2[]);
        angl();
        ~angl();
        //double setMag(double m_vec_1[]);
        //double setAngl();
        //double dot(double vec1[], double vec2[]);

    
};

#endif /* sdp4_hpp */


