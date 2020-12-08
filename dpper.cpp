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
//                           procedure dpper
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
//  ----------------------------------------------------------------------------*/
 dpper::dpper()
{};
void dpper::set_parameters (double e3, double ee2, double peo,double pgho,double pho,double    pinco,double  plo,    double se2,double se3, double   sgh2, double  sgh3,  double sgh4, double  sh2, double   sh3,  double  si2,    double si3, double sl2, double   sl3,  double  sl4,  double  t, double     xgh2, double  xgh3, double  xgh4,   double xh2, double xh3,    double xi2,  double  xi3, double   xl2, double   xl3,   double xl4, double   zmol,
   double zmos, double  inclo,  double init,  double  ep,  double   inclp,  double nodep, double argpp,  double mp)
{
 
    satrec *rec = new satrec();

   // --------------- calculate time varying periodics ----------- */
   rec->varZm    = rec->satrec_zmos + rec->const_zns * rec->satrec_zmos;
    
   // be sure that the initial call has time set to zero
   if (init == 'y')
   {
    rec->varZm   = rec->satrec_zmos;
   };
   rec->varZf    = rec->varZm  + 2.0 * rec->const_zes * sin(rec->varZm);
   rec->varSinzf = sin(rec->varZf);
   rec->varF2    =  0.5 * rec->varSinzf * rec->varSinzf - 0.25;
   rec->varF3    = -0.5 * rec->varSinzf * cos(rec->varZf);
   rec->varSes   = rec->satrec_se2 * rec->varF2  + rec->satrec_se3 * rec->varF3;
   rec->varSis   = rec->satrec_si2 * rec->varF2 + rec->satrec_si3 * rec->varF3;
   rec->varSls   = rec->satrec_sl2 * rec->varF2 + rec->satrec_sl3 * m_f3 + rec->satrec_sl4 * rec->varSinzf;
   rec->varSghs  = rec->satrec_sgh2 * rec->varF2 + rec->satrec_sgh3 * rec->varF3 + rec->satrec_sgh4 * rec->varSinzf;
   rec->varShs   = rec->satrec_sh2 * rec->varF2 + rec->satrec_sh3 * rec->varF3;
   rec->varZm    = rec->satrec_zmol + rec->const_znl * rec->satrec_t;
    
   if (init == 'y')
   {
       rec->varZm = rec->satrec_zmol;
   };
    
    rec->varZf      =  rec->varZm+ 2.0 * rec->const_zel * sin(rec->varZm);
    rec->varSinzf   =  sin(rec->varZf);
    rec->varF2      =  0.5 *  m_sinzf *  m_sinzf - 0.25;
    rec->varF3      = -0.5 *  m_sinzf * cos( m_zf);
    rec->varSes     =  m_ee2 *  m_f2 +  m_e3 *  m_f3;
    rec->varSil     =  m_xi2 *  m_f2 +  m_xi3 *  m_f3;
    rec->varSll     =  m_xl2 *  m_f2 +  m_xl3 *  m_f3 +  m_xl4 *  m_sinzf;
    rec->varSghl    =  m_xgh2 *  m_f2 +  m_xgh3 *  m_f3 +  m_xgh4 *  m_sinzf;
    rec->varShll    =  m_xh2 *  m_f2 +  m_xh3 *  m_f3;
    rec->varPe      =  rec->varSes  + rec->varSel;
    rec->varPinc    =  rec->varSis +  rec->varSil;
    rec->varPl      =  rec->varSls +  rec->varSll;
    rec->varPgh     =  rec->varSghs +  rec->varSghl;
    rec->varPh      =  rec->varShs +  rec->varShll;
    
    if (init == 'n')
    {
        //  //  0.2 rad = 11.45916 deg
        m_pe    = m_pe - m_peo;
        m_pinc  = m_pinc - m_pinco;
        m_pl    = m_pl - m_plo;
        m_pgh   = m_pgh - m_pgho;
        m_ph    = m_ph - m_pho;
        m_inclp = m_inclp + m_pinc;
        m_ep    = m_ep + m_pe;
        m_sinip = sin(m_inclp);
        m_cosip = cos(m_inclp);

        // ----------------- apply periodics directly ------------ */
           //  sgp4fix for lyddane choice
          //  strn3 used original inclination - this is technically feasible
          //  gsfc used perturbed inclination - also technically feasible
           //  probably best to readjust the 0.2 limit value and limit discontinuity
          //  use next line for original strn3 approach and original inclination
          //  if (inclo >= 0.2)
           //  use next line for gsfc version and perturbed inclination
        if (inclp >= 0.2)
        {
            m_ph     = m_ph / m_sinip;
            m_pgh    = m_pgh - m_cosip * m_ph;
            m_argpp  = m_argpp + m_pgh;
            m_nodep  = m_nodep + m_ph;
            m_mp     = m_mp + m_pl;
        }
        else
        {
            // ---- apply periodics with lyddane modification ---- */
            m_sinop  = sin(m_nodep);
            m_cosop  = cos(m_nodep);
            m_alfdp  = m_sinip * m_sinop;
            m_betdp  = m_sinip * m_cosop;
            m_dalf   =  m_ph * m_cosop + m_pinc * m_cosip * m_sinop;
            m_dbet   = -m_ph * m_sinop + m_pinc * m_cosip * m_cosop;
            m_alfdp  = m_alfdp + m_dalf;
            m_betdp  = m_betdp + m_dbet;
            m_nodep  = remainder(m_nodep, rec->const_twopi);
            // sgp4fix for afspc written intrinsic functions
            // nodep used without a trigonometric function ahead
            if ((m_nodep < 0.0) & (m_opsmode == 'a'))
            {
                m_nodep = m_nodep + rec->const_twopi;
            }
            m_xls    = m_mp + m_argpp + m_cosip * m_nodep;
            m_dls    = m_pl + m_pgh - m_pinc * m_nodep * m_sinip;
            m_xls    = m_xls + m_dls;
            m_xnoh   = m_nodep;
            m_nodep  = atan2(m_alfdp, m_betdp);
            // sgp4fix for afspc written intrinsic functions
            // nodep used without a trigonometric function ahead
                
            if ((m_nodep < 0.0) & (m_opsmode == 'a'))
            {
                m_nodep = m_nodep + rec->const_twopi;
            }
            
            if (abs(m_xnoh - m_nodep) > rec->const_pi)
            {
                if (m_nodep < m_xnoh)
                {
                    m_nodep = m_nodep + rec->const_twopi;
                }
                else
                {
                    m_nodep = m_nodep - rec->const_twopi;
                }
            }
            m_mp    = m_mp + m_pl;
            m_argpp = m_xls - m_mp - m_cosip * m_nodep;
        }
    }

}
