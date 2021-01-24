//
//  angl.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 21/01/2021.
//  Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "angl.hpp"

angl::angl(double m_vec_1[], double m_vec_2[])
{
  
    small     = 0.00000001;
    undefined = 999999.1;

    
    magv1 = setMag(m_vec_1);
    magv2 = setMag(m_vec_2);

           if (magv1*magv2 > small^2)
           {
               temp= dot(m_vec_1,m_vec_2) / (magv1*magv2);
               if (abs( temp ) > 1.0)
               {
                if (temp < 0)
                    {
                        temp= -1 * 1.0;
                    }
                  else
                    {
                        temp= 1 * 1.0;
                    }
               }
               theta= acos( temp );
           }
           else
           {
               theta= undefined;
           }

};
angl::angl()
{
  
    

};

angl::~angl()
{};
