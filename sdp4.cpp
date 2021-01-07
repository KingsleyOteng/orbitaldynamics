//
//  sdp4.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sdp4.hpp"

void sdp4::set_model                            ()
{

///* ------------------ set mathematical constants --------------- */
    m_xke = 0; ///?????
m_twopi = 2.0 * m_pi;
m_x2o3  = 2.0 / 3.0;
///% sgp4fix divisor for divide by zero check on inclination
///% the old check used 1.0 + cos(pi-1.0e-9), but then compared it to
///% 1.5 e-12, so the threshold was changed to 1.5e-12 for consistancy
m_temp4    =   1.5e-12;

///%  // sgp4fix identify constants and allow alternate values
///global tumin mu radiusearthkm xke j2 j3 j4 j3oj2
m_vkmpersec     = m_radiusearthkm * m_xke/60.0;

///% /* --------------------- clear sgp4 error flag ----------------- */
m_satrec_t        = m_tsince;
m_satrec_error    = 0;
m_mrt             = 0.0;
    
m_xmdf    = m_satrec_mo + m_satrec_mdot * m_satrec_t;
m_argpdf  = m_satrec_argpo + m_satrec_argpdot * m_satrec_t;
m_nodedf  = m_satrec_nodeo + m_satrec_nodedot * m_satrec_t;

}
