//
//  dspace_model.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 11/11/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "dspace_model.hpp"

 dspace_model::dspace_model(double satrec_d2201,double satrec_d2211,double satrec_d3210,
double satrec_d3222, double satrec_d4410, double satrec_d4422,
double satrec_d5220,double satrec_d5232,double satrec_d5421,
double satrec_d5433,double satrec_dedt,double satrec_del1,
double satrec_del2,double satrec_del3,double satrec_didt,
double satrec_dmdt,double satrec_dnodt,double satrec_domdt,
double satrec_irez,double satrec_argpo,double satrec_argpdot,double satrec_t,
double tc, double satrec_gsto,double satrec_xfact,double satrec_xlamo, double satrec_no,
double satrec_atime, double em, double argpm, double inclm, double satrec_xli, double mm,
double satrec_xni,double nodem,double nm)
{
    satrec_d2201 = satrec_d2201;
    satrec_d2211 = satrec_d2211;
    satrec_d3210 = satrec_d3210;
    satrec_d3222 = satrec_d3222;
    satrec_d4410 = satrec_d4410;
    satrec_d4422 = satrec_d4422;
    satrec_d5220 = satrec_d5220;
    satrec_d5232 = satrec_d5232;
    satrec_d5421 = satrec_d5421;
    satrec_d5433 = satrec_d5433;
    satrec_dedt = satrec_dedt;
    satrec_dedt = satrec_dedt;
    satrec_del2 = satrec_del2;
    satrec_del3 = satrec_del3;
    satrec_didt = satrec_didt;
    satrec_dmdt = satrec_dmdt;
    satrec_dnodt = satrec_dnodt;
    satrec_domdt = satrec_domdt;
    satrec_irez =satrec_irez;
    satrec_argpo = satrec_argpo;
    satrec_argpdot= satrec_argpdot;
    satrec_t = satrec_t;
    t = t;
    tc =tc;
    satrec_gsto = satrec_gsto;
    satrec_xfact = satrec_xfact;
    satrec_xlamo = satrec_xlamo;
    satrec_no = satrec_no;
    satrec_atime = satrec_atime;
    em = em;
    argpm = argpm;
    inclm = inclm;
    satrec_xli = satrec_xli;
    mm = mm;
    satrec_xni = satrec_xni;
    nodem = nodem;
    nm = nm;
    
};

void dspace_model::getModelParameters()
{
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
    
    /* ----------- calculate deep space resonance effects ----------- */
      dndt   = 0.0;
     // theta  = rem(gsto + tc * rptim, twopi);
      em     = em + satrec_dedt * satrec_t;
      inclm  = inclm + satrec_didt * satrec_t;
      argpm  = argpm + satrec_domdt * satrec_t;
      nodem  = nodem + satrec_dnodt * satrec_t;
      mm     = mm + satrec_dmdt * satrec_t;
}
