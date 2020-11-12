//
//  dspace_model.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 11/11/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "dspace_model.hpp"

 dspace_model::dspace_model(double d2201,double d2211,double d3210,
double d3222, double d4410, double d4422,
double d5220,double d5232,double d5421,
double d5433,double dedt,double del1,
double el2,double del3,double idt,
double dmdt,double dnodt,double domdt,
double irez,double argpo,double argpdot,double t,
double tc, double gsto,double xfact,double xlamo, double _no,
double atime, double em, double argpm, double inclm, double xli, double mm,
double xni,double nodem,double nm)
{
    d2201 = d2201;
    d2211 = d2211;
    d3210 = d3210;
    d3222 = d3222;
    d4410 = d4410;
    d4422 = d4422;
    d5220 = d5220;
    d5232 = d5232;
    d5421 = d5421;
    d5433 = d5433;
    dedt = dedt;
    dedt = dedt;
    del2 = del2;
    del3 = del3;
    didt = didt;
    dmdt = dmdt;
    dnodt = dnodt;
    domdt = domdt;
    irez = irez;
    argpo = argpo;
    argpdot= argpdot;
    t = t;
    t = t;
    tc =tc;
    gsto = gsto;
    xfact = xfact;
    xlamo = xlamo;
    no = no;
    atime = atime;
    em = em;
    argpm = argpm;
    inclm = inclm;
    xli = xli;
    mm = mm;
    xni = xni;
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
