//
//  mag.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 13/01/2021.
//  Copyright © 2021 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "mag.hpp"

mag::mag()
{
  
    temp= m_vec[1]*m_vec[1] + m_vec[2]*m_vec[2] + m_vec[3]*m_vec[3];
    
    if (abs(temp) >= 1.0e-16)
    {
        m_mag=sqrt( temp );
    }
    else
    {
        m_mag= 0.0;
    }
    
    
};

mag::mag(double vec[])
{};

mag::mag(double vec)
{};


double mag::setMag(double vec)
{return 0.0;};




mag::~mag()
{};
