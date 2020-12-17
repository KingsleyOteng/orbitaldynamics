//
//  dspace_model.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 11/11/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "dspace_model.hpp"

dspace_model::dspace_model()
{};

dspace_model::~dspace_model()
{};

dspace_model::dspace_model(double _d2201,double _d2211, double _d3210,
 double _d3222, double _d4410, double _d4422,
 double _d5220,double _d5232,double _d5421,
 double _d5433,double _dedt,double _del1,
 double _del2,double _del3,double _didt,
 double _dmdt,double _dnodt,double _domdt,
 double _irez,double _argpo,double _argpdot, double _t,
 double _tc, double _gsto,double _xfact,double _xlamo, double _no,
 double _atime, double _em, double _argpm, double _inclm, double _xli, double _mm,
 double _xni,double _nodem,double _nm)
 {
     d2201 = _d2201;
     d2211 = _d2211;
     d3210 = _d3210;
     d3222 = _d3222;
     d4410 = _d4410;
     d4422 = _d4422;
     d5220 = _d5220;
     d5232 = _d5232;
     d5421 = _d5421;
     d5433 = _d5433;
     dedt = _dedt;
     dedt = _dedt;
     del2 = _del2;
     del3 = _del3;
     didt = _didt;
     dmdt = _dmdt;
     dnodt = _dnodt;
     domdt = _domdt;
     irez = _irez;
     argpo = _argpo;
     argpdot= _argpdot;
     t = _t;
     tc = _tc;
     gsto = _gsto;
     xfact = _xfact;
     xlamo = _xlamo;
     no = _no;
     atime = _atime;
     em = _em;
     argpm = _argpm;
     inclm = _inclm;
     xli = _xli;
     mm = _mm;
     xni = _xni;
     nodem = _nodem;
     nm = _nm;
 };




void dspace_model::getModelParameters()
{
    // get model parameters.
    const   double twopi = 2.0 * 3.14159265359;
    const   double fasx2 = 0.13130908;
    const   double fasx4 = 2.8843198;
    const   double fasx6 = 0.37448087;
    const   double g22   = 5.7686396;
    const   double g32   = 0.95240898;
    const   double g44   = 1.8014998;
    const   double g52   = 1.0508330;
    const   double g54   = 4.4108898;
    const   double rptim = 4.37526908801129966e-3;
    const   double stepp =    720.0;
    const   double stepn =   -720.0;
    const   double step2 = 259200.0;
    
    // none of this has been tested.
    // -- calculate deep space resonance effects -- //
      dndt   = 0.0;
      theta  = remainder(gsto + tc * rptim, twopi);         //<----this command presumably behaves the same as the matlab command rem. Please check
      em     = em + dedt * t;

      inclm  = inclm + didt * t;
      argpm  = argpm + domdt * t;
      nodem  = nodem + dnodt * t;
      mm     = mm + dmdt * t;
    
    // sgp4fix take out atime = 0.0 and fix for faster operation
      ft    = 0.0;
    
    if (irez != 0)
    {
        // sgp4fix streamline check
        if ((atime == 0.0) || (t * atime <= 0.0) || (abs(t) < abs(atime)) )
        {
            atime  = 0.0;
            xni    = no;
            xli    = xlamo;
        }
        
        // sgp4fix move check outside loop
        if (t >= 0.0)
        {
            delt = stepp;
        }
        else
        {
            delt = stepn;
        }
        
        iretn = 381; // added for do loop
        iret  =   0; // added for loop
        
        while (iretn == 381)
        {
            // none of this has been tested.
            //* ------------------- dot terms calculated ------------- */
            //* ----------- near - synchronous resonance terms ------- */
            if (irez != 2)
            {
                xndt  = del1 * sin(xli - fasx2) + del2 * sin(2.0 * (xli - fasx4)) + del3 * sin(3.0 * (xli - fasx6));
                xldot = xni + xfact;
                xnddt = del1 * cos(xli - fasx2) + 2.0 * del2 * cos(2.0 * (xli - fasx4)) + 3.0 * del3 * cos(3.0 * (xli - fasx6));
                xnddt = xnddt * xldot;
            }
            else
            {
                //* --------- near - half-day resonance terms -------- */
                xomi  = argpo + argpdot * atime;
                x2omi = xomi + xomi;
                x2li  = xli + xli;
                xndt  = d2201 * sin(x2omi + xli - g22) + d2211 * sin(xli - g22) +
                    d3210 * sin(xomi + xli - g32)  + d3222 * sin(-xomi + xli - g32)+
                    d4410 * sin(x2omi + x2li - g44)+ d4422 * sin(x2li - g44) +
                    d5220 * sin(xomi + xli - g52)  + d5232 * sin(-xomi + xli - g52)+
                    d5421 * sin(xomi + x2li - g54) + d5433 * sin(-xomi + x2li - g54);
                xldot = xni + xfact;
                xnddt = d2201 * cos(x2omi + xli - g22) + d2211 * cos(xli - g22) +
                    d3210 * cos(xomi + xli - g32) + d3222 * cos(-xomi + xli - g32) +
                    d5220 * cos(xomi + xli - g52) + d5232 * cos(-xomi + xli - g52) +
                    2.0 * (d4410 * cos(x2omi + x2li - g44) +
                    d4422 * cos(x2li - g44) + d5421 * cos(xomi + x2li - g54) +
                    d5433 * cos(-xomi + x2li - g54));
                xnddt = xnddt * xldot;
            };
            
             // none of this has been tested.
            // % /* ----------------------- integrator ------------------- */
            // % sgp4fix move end checks to end of routine
            if (abs(t - atime) >= stepp)
            {
                 iret  = 0;
                 iretn = 381;
            }
            else
            {
                 ft    = t - atime;
                 iretn = 0;
            };

            if (iretn == 381)
            {
                xli   = xli + xldot * delt + xndt * step2;
                xni   = xni + xndt * delt + xnddt * step2;
                atime = atime + delt;
            };
            
            nm = xni + xndt * ft + xnddt * ft * ft * 0.5;
            xl = xli + xldot * ft + xndt * ft * ft * 0.5;
            
            if (irez != 1)
            {
                mm   = xl - 2.0 * nodem + 2.0 * theta;
                dndt = nm - no;
            }
            else
            {
                mm   = xl - nodem - argpm+ theta;
                dndt = nm - no;
            };
            
            nm = no + dndt;
        };
    };
    
}

void dspace_model::set_dspace_line1(double satrec_d2201, double satrec_d2211,double satrec_d3210, double satrec_d3222, double satrec_d4410, double satrec_d4422, double satrec_d5220, double satrec_d5232, double satrec_d5421)
    {
       //single section of parameters for the dspace model
       d2201 = satrec_d2201;
       d2211 = satrec_d2211;
       d3210 = satrec_d3210;
       d3222 = satrec_d3222;
       d4410 = satrec_d4410;
       d4422 = satrec_d4422;
       d5220 = satrec_d5220;
       d5232 = satrec_d5232;
       d5421 = satrec_d5421;
    };

   void dspace_model::set_dspace_line2(double satrec_d5433, double satrec_dedt, double satrec_del1,
      double satrec_del2, double satrec_del3, double satrec_didt,
      double satrec_dmdt, double satrec_dnodt, double satrec_domdt)
   {
        // first section of parameters for the dspace model
       d5433 = satrec_d5433;
       dedt = satrec_dedt;
       dedt = satrec_dedt;
       del2 = satrec_del2;
       del3 = satrec_del3;
       didt = satrec_didt;
       dmdt = satrec_dmdt;
       dnodt = satrec_dnodt;
       domdt = satrec_domdt;
   };
      
   void dspace_model::set_dspace_line3(double satrec_irez,double satrec_argpo, double satrec_argpdot, double satrec_t, double satrec_tc, double satrec_gsto, double satrec_xfact, double satrec_xlamo, double satrec_no)
   {
        // second section of parameters for the dspace model
       irez = satrec_irez;
       argpo = satrec_argpo;
       argpdot= satrec_argpdot;
       t = satrec_t;
       tc = satrec_tc;
       gsto = satrec_gsto;
       xfact = satrec_xfact;
       xlamo = satrec_xlamo;
       no = satrec_no;
   };
      
   void dspace_model::set_dspace_line4(double satrec_atime, double satrec_em, double satrec_argpm, double satrec_inclm, double satrec_xli, double satrec_mm, double satrec_xni,double satrec_nodem, double satrec_nm)
   {
       // fourth section of parameters for the dspace model
       atime = satrec_atime;
       em = satrec_em;
       argpm = satrec_argpm;
       inclm = satrec_inclm;
       xli = satrec_xli;
       mm = satrec_mm;
       xni = satrec_xni;
       nodem = satrec_nodem;
       nm = satrec_nm;
   };
