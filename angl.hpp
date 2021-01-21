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

#ifndef angl_hpp
#define angl_hpp



class angl
{
    
    private:
        double m_angl;
        double small;
        double undefined;

    
    public:
        angl(double m_vec_1, double m_vec_2);
        angl();
        ~angl();

    
};

#endif /* sdp4_hpp */


