//
//  sdp4.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 10/10/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "sdp4.hpp"

///* ------------------ set mathematical constants --------------- */
m_twopi = 2.0 * m_pi;
m_x2o3  = 2.0 / 3.0;
///% sgp4fix divisor for divide by zero check on inclination
///% the old check used 1.0 + cos(pi-1.0e-9), but then compared it to
///% 1.5 e-12, so the threshold was changed to 1.5e-12 for consistancy
temp4    =   1.5e-12;

///%  // sgp4fix identify constants and allow alternate values
global tumin mu radiusearthkm xke j2 j3 j4 j3oj2
vkmpersec     = radiusearthkm * xke/60.0;

///% /* --------------------- clear sgp4 error flag ----------------- */
satrec_t        = tsince;
satrec_error    = 0;
mrt             = 0.0;

