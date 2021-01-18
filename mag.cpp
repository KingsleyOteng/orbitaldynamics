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
    temp= m_vec_1*m_vec_1 + m_vec_2*m_vec_2 + m_vec_3*m_vec_3;

    if (abs(temp) >= 1.0e-16)
    {
        m_mag=sqrt( temp );
    }
    else
    {
        m_mag= 0.0;
    }
    
    
};

mag::~mag()
{};
