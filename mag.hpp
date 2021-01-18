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

#ifndef mag_hpp
#define mag_hpp



class mag
{
    
    private:
        double m_mag;
        double temp;
        double m_vec[4];
    
    public:
        mag();
        ~mag();
    mag(double vec[]);
   
    
    
};

#endif /* sdp4_hpp */


