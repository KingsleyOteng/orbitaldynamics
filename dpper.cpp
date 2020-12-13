//
//  dpper.cpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 06/12/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#include "dpper.hpp"


//  -----------------------------------------------------------------------------
//
//                           class dpper
//
//   this procedure provides deep space long period periodic contributions
//     to the mean elements.  by design, these periodics are zero at epoch.
//    this used to be dscom which included initialization, but it's really a
//    recurring function.
//
// Author:
//  Jeff Beck
//  beckja@alumni.lehigh.edu
//   1.0 (aug 7, 2006) - update for paper dav
// riginal comments from Vallado C++ version:
//   author        : david vallado                  719-573-2600   28 jun 2005
//
//   inputs        :
//      e3          -
//     ee2         -
//     peo         -
//      pgho        -
//      pho         -
//     pinco       -
//     plo         -
//    se2 , se3 , Sgh2, Sgh3, Sgh4, Sh2, Sh3, Si2, Si3, Sl2, Sl3, Sl4 -
//     t           -
//      xh2, xh3, xi2, xi3, xl2, xl3, xl4 -
//     zmol        -
//     zmos        -
//      ep          - eccentricity                           0.0 - 1.0
//     inclo       - inclination - needed for lyddane modification
//    nodep       - right ascension of ascending node
//     argpp       - argument of perigee
//     mp          - mean anomaly
//
//   outputs       :
//     ep          - eccentricity                           0.0 - 1.0
//     inclp       - inclination
//      nodep       - right ascension of ascending node
//     argpp       - argument of perigee
//     mp          - mean anomaly
//
//    locals        :
//     alfdp       -
//    betdp       -
//     cosip  , sinip  , cosop  , sinop  ,
//     dalf        -
//     dbet        -
//    dls         -
//     f2, f3      -
//   pe          -
//    pgh         -
//     ph          -
//   pinc        -
//    pl          -
//    sel   , ses   , sghl  , sghs  , shl   , shs   , sil   , sinzf , sis   ,
//    sll   , sls
//    xls         -
//    xnoh        -
//     zf          -
//     zm          -
//
//   coupling      :
//     none.
//
//   references    :
//   hoots, roehrich, norad spacetrack report #3 1980
//    hoots, norad spacetrack report #6 1986
//    hoots, schumacher and glover 2004
//     vallado, crawford, hujsak, kelso  2006
//  ----------------------------------------------------------------------------
dpper::dpper()
{};

void dpper::set_parameters (double e3, double ee2, double peo,double pgho,double pho, double pinco, double  plo, double se2,double se3, double sgh2, double  sgh3,  double sgh4, double  sh2, double sh3, double si2, double si3, double sl2, double sl3, double  sl4, double  t, double xgh2, double  xgh3, double  xgh4, double xh2, double xh3, double xi2, double  xi3, double xl2, double xl3, double xl4, double zmol, double zmos, double  inclo,  double init, double  ep, double inclp, double nodep, double argpp, double mp)
{
    
    satrec *rec = new satrec();
    
    // --------------- calculate time varying periodics -----------
    
    varZm = rec->satrec_zmos + rec->const_zns * rec->satrec_zmos;
    
    // be sure that the initial call has time set to zero
    if (rec->satrec_init == 'y')
    {
        varZm   = rec->satrec_zmos;
    };
    varZf = varZm +2.0 * rec->const_zes * sin(varZm);
    varSinzf = sin(varZf);
    varF2 =  0.5 * varSinzf * varSinzf - 0.25;
    varF3 = -0.5 * varSinzf * cos(varZf);
    varSes = rec->satrec_se2 * varF2  + rec->satrec_se3 * varF3;
    varSis = rec->satrec_si2 * varF2 + rec->satrec_si3 * varF3;
    varSls = rec->satrec_sl2 * varF2 + rec->satrec_sl3 * m_f3 + rec->satrec_sl4 * varSinzf;
    varSghs = rec->satrec_sgh2 * varF2 + rec->satrec_sgh3 * varF3 + rec->satrec_sgh4 * varSinzf;
    varShs = rec->satrec_sh2 * varF2 + rec->satrec_sh3 * varF3;
    varZm = rec->satrec_zmol + rec->const_znl * rec->satrec_t;
    
    if (rec->satrec_init == 'y')
    {
        varZm = rec->satrec_zmol;
    };
    
    varZf = varZm+ 2.0 * rec->const_zel * sin(varZm);
    varSinzf = sin(varZf);
    varF2 = 0.5 *  varSinzf * varSinzf  - 0.25;
    varF3 = -0.5 *  varSinzf * cos( m_zf);
    varSel = rec->satrec_ee2 * varF2 + rec->satrec_e3 * varF3;
    varSil = rec->satrec_xi2 * varF2 + m_xi3 * varF3;
    varSll = rec->satrec_xl2 * varF2 + rec->satrec_xl3 * varF3 + rec->satrec_xl4 * varSinzf ;
    varSghl = rec->satrec_xgh2 * varF3 + rec->satrec_xgh3 *  varF3 +  rec->satrec_xgh4 * varSinzf;
    varShll = rec->satrec_xh2  * varF2 + rec->satrec_xh3 *  varF3;
    
    varPe = varSes + varSel;
    varPinc = varSis + varSil;
    varPl = varSls + varSll;
    varPgh = varSghs + varSghl;
    varPh = varShs + varShll;
    
    if (rec->satrec_init == 'n')
    {
        //  //  0.2 rad = 11.45916 deg
        varPe = varPe - rec->satrec_peo;
        varPinc = varPinc - rec->satrec_pinco;
        varPl = varPl - rec->satrec_plo;
        varPgh = varPgh - rec->satrec_pgho;
        varPh = varPh - rec->satrec_pho;
        rec->satrec_inclp = rec->satrec_inclp  + varPinc;
        rec->satrec_ep = rec->satrec_ep + varPe;
        varSinip = sin(rec->satrec_inclp);
        varCosip = cos(rec->satrec_inclp);
        
        // ----------------- apply periodics directly ------------
        //  sgp4fix for lyddane choice
        //  strn3 used original inclination - this is technically feasible
        //  gsfc used perturbed inclination - also technically feasible
        //  probably best to readjust the 0.2 limit value and limit discontinuity
        //  use next line for original strn3 approach and original inclination
        //  if (inclo >= 0.2)
        //  use next line for gsfc version and perturbed inclination
        
        if (inclp >= 0.2)
        {
            varPh = rec->satrec_mp  / varSinip;
            varPgh = varPh - m_cosip * varPh;
            
            rec->satrec_argpp = rec->satrec_argpp  + varPgh;
            rec->satrec_nodep = rec->satrec_argpp + varPh;
            rec->satrec_mp = rec->satrec_mp + varPl;
        }
        else
        {
            // ---- apply periodics with lyddane modification ----
            varSinop = sin(rec->satrec_nodep);
            varCosop = cos(rec->satrec_nodep);
            varAlfdp = varSinop * varSinop;
            varBetdp = varSinop * varCosop;
            varDalf =  varPh * varCosop + varPinc * varCosip * varSinop;
            varDbet = -varPh * varSinop + varPinc * varCosip  * varCosop ;
            varAlfdp = varAlfdp  + varDalf;
            varBetdp = varBetdp  + varDbet;
            rec->satrec_nodep  = remainder(rec->satrec_nodep, rec->const_twopi);
            // sgp4fix for afspc written intrinsic functions
            // nodep used without a trigonometric function ahead
            if ((rec->satrec_nodep< 0.0) & (rec->global_opsmode == 'a'))
            {
                rec->satrec_nodep = rec->satrec_nodep + rec->const_twopi;
            }
            varXls = rec->satrec_mp + rec->satrec_argpp + varCosip * rec->satrec_nodep;
            varDls = varPl + varPgh - varPinc * rec->satrec_nodep * varSinip ;
            varXls = varXls + varDls;
            varXnoh = rec->satrec_nodep;
            rec->satrec_nodep  = atan2(varAlfdp  , varBetdp);
            // sgp4fix for afspc written intrinsic functions
            // nodep used without a trigonometric function ahead
            
            if ((rec->satrec_nodep < 0.0) & (rec->global_opsmode == 'a'))
            {
                rec->satrec_nodep = rec->satrec_nodep + rec->const_twopi;
            }
            
            if (abs(varXnoh - rec->satrec_nodep) > rec->const_pi)
            {
                if (rec->satrec_nodep < varXnoh)
                {
                    rec->satrec_nodep = rec->satrec_nodep + rec->const_twopi;
                }
                else
                {
                    rec->satrec_nodep = rec->satrec_nodep - rec->const_twopi;
                }
            }
            rec->satrec_mp   = rec->satrec_mp + varPl;
            rec->satrec_argpp  = varXls - rec->satrec_mp - varCosip * rec->satrec_nodep;
        }
    }
    
}

void dpper::set_parameters (satrec * rec)
{
    
    // --------------- calculate time varying periodics -----------
    
    varZm = rec->satrec_zmos + rec->const_zns * rec->satrec_zmos;
    
    // be sure that the initial call has time set to zero
    if (rec->satrec_init == 'y')
    {
        varZm = rec->satrec_zmos;
    };
    
    varZf = varZm  + 2.0 * rec->const_zes * sin(varZm);
    varSinzf = sin(varZf);
    varF2 =  0.5 * varSinzf * varSinzf - 0.25;
    varF3 = -0.5 * varSinzf * cos(varZf);
    varSes = rec->satrec_se2 * varF2 + rec->satrec_se3 * varF3;
    varSis = rec->satrec_si2 * varF2 + rec->satrec_si3 * varF3;
    varSls = rec->satrec_sl2 * varF2 + rec->satrec_sl3 * m_f3 + rec->satrec_sl4 * varSinzf;
    varSghs = rec->satrec_sgh2 * varF2 + rec->satrec_sgh3 * varF3 + rec->satrec_sgh4 * varSinzf;
    varShs = rec->satrec_sh2 * varF2 + rec->satrec_sh3 * varF3;
    varZm = rec->satrec_zmol + rec->const_znl * rec->satrec_t;
    
    if (rec->satrec_init == 'y')
    {
        varZm = rec->satrec_zmol;
    };
    
    varZf      =  varZm+ 2.0 * rec->const_zel * sin(varZm);
    varSinzf   =  sin(varZf);
    varF2      =  0.5 * varSinzf * varSinzf - 0.25;
    varF3      = -0.5 * varSinzf * cos(m_zf);
    varSel     =  rec->satrec_ee2 *  varF2 + rec->satrec_e3 * varF3;
    varSil     =  rec->satrec_xi2 *  varF2 + m_xi3 * varF3;
    varSll     =  rec->satrec_xl2 *  varF2 + rec->satrec_xl3 * varF3 + rec->satrec_xl4 * varSinzf ;
    varSghl    =  rec->satrec_xgh2 * varF3 + rec->satrec_xgh3 * varF3 +  rec->satrec_xgh4 * varSinzf;
    varShll    =  rec->satrec_xh2  * varF2 + rec->satrec_xh3 * varF3;
    
    varPe      =  varSes  + varSel;
    varPinc    =  varSis +  varSil;
    varPl      =  varSls +  varSll;
    varPgh     =  varSghs +  varSghl;
    varPh      =  varShs +  varShll;
    
    if (rec->satrec_init == 'n')
    {
        //  //  0.2 rad = 11.45916 deg
        varPe = varPe -  rec->satrec_peo;
        varPinc = varPinc - rec->satrec_pinco;
        varPl = varPl - rec->satrec_plo;
        varPgh = varPgh - rec->satrec_pgho;
        varPh = varPh - rec->satrec_pho;
        rec->satrec_inclp = rec->satrec_inclp  + varPinc;
        rec->satrec_ep = rec->satrec_ep + varPe;
        varSinip = sin(rec->satrec_inclp);
        varCosip = cos(rec->satrec_inclp);
        
        // ----------------- apply periodics directly ------------
        //  sgp4fix for lyddane choice
        //  strn3 used original inclination - this is technically feasible
        //  gsfc used perturbed inclination - also technically feasible
        //  probably best to readjust the 0.2 limit value and limit discontinuity
        //  use next line for original strn3 approach and original inclination
        //  if (inclo >= 0.2)
        //  use next line for gsfc version and perturbed inclination
        
        if (rec->satrec_inclp >= 0.2)
        {
            varPh = rec->satrec_mp / varSinip;
            varPgh = varPh - m_cosip * varPh;
            rec->satrec_argpp = rec->satrec_argpp + varPgh;
            rec->satrec_nodep = rec->satrec_argpp + varPh;
            rec->satrec_mp = rec->satrec_mp + varPl;
        }
        else
        {
            
            // ---- apply periodics with lyddane modification ----
            varSinop = sin(rec->satrec_nodep);
            varCosop = cos(rec->satrec_nodep);
            varAlfdp  = varSinop * varSinop;
            varBetdp  = varSinop * varCosop;
            varDalf   =  varPh * varCosop + varPinc * varCosip * varSinop;
            varDbet   = -varPh * varSinop + varPinc * varCosip  * varCosop ;
            varAlfdp  = varAlfdp + varDalf;
            varBetdp  = varBetdp + varDbet ;
            rec->satrec_nodep  = remainder(rec->satrec_nodep, rec->const_twopi);
            
            // sgp4fix for afspc written intrinsic functions
            // nodep used without a trigonometric function ahead
            if ((rec->satrec_nodep< 0.0) & (rec->global_opsmode == 'a'))
            {
                rec->satrec_nodep = rec->satrec_nodep  + rec->const_twopi;
            }
            varXls = rec->satrec_mp + rec->satrec_argpp + varCosip * rec->satrec_nodep;
            varDls = varPl + varPgh - varPinc * rec->satrec_nodep * varSinip ;
            varXls = varXls + varDls;
            varXnoh = rec->satrec_nodep;
            rec->satrec_nodep  = atan2(varAlfdp , varBetdp);
            
            // sgp4fix for afspc written intrinsic functions
            // nodep used without a trigonometric function ahead
            
            if ((rec->satrec_nodep < 0.0) & (rec->global_opsmode == 'a'))
            {
                rec->satrec_nodep = rec->satrec_nodep + rec->const_twopi;
            }
            
            if (abs(varXnoh - rec->satrec_nodep) > rec->const_pi)
            {
                if (rec->satrec_nodep < varXnoh)
                {
                    rec->satrec_nodep = rec->satrec_nodep + rec->const_twopi;
                }
                else
                {
                    rec->satrec_nodep = rec->satrec_nodep - rec->const_twopi;
                }
            }
            rec->satrec_mp = rec->satrec_mp + varPl;
            rec->satrec_argpp = varXls - rec->satrec_mp - varCosip * rec->satrec_nodep;
        }
    }
    
}
