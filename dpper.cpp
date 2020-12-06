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

void dpper::set_parameters (double e3, double ee2, double peo,double pgho,double pho,double    pinco,double  plo,    double se2,double se3, double   sgh2, double  sgh3,  double sgh4, double  sh2, double   sh3,  double  si2,    double si3, double sl2, double   sl3,  double  sl4,  double  t, double     xgh2, double  xgh3, double  xgh4,   double xh2, double xh3,    double xi2,  double  xi3, double   xl2, double   xl3,   double xl4, double   zmol,
   double zmos, double  inclo,  double init,  double  ep,  double   inclp,  double nodep, double argpp,  double mp)
{
 

    // --------------------- local variables ------------------------
   m_pi  = 3.14159267;
   m_twopi = 2.0 * m_pi;

    // ---------------------- constants -----------------------------
   m_zns   = 1.19459e-5;
   m_zes   = 0.01675;
   m_znl   = 1.5835218e-4;
   m_zel   = 0.05490;

   // --------------- calculate time varying periodics ----------- */
   m_zm    = m_zmos + m_zns * m_t;
   // be sure that the initial call has time set to zero
   if (init == 'y')
   {
       m_zm = m_zmos;
   };
   m_zf    = m_zm + 2.0 * m_zes * sin(m_zm);
   m_sinzf = sin(m_zf);
   m_f2    =  0.5 * m_sinzf * m_sinzf - 0.25;
   m_f3    = -0.5 * m_sinzf * cos(m_zf);
   m_ses   = m_se2 * m_f2 + m_se3 * m_f3;
   m_sis   = m_si2 * m_f2 + m_si3 * m_f3;
   m_sls   = m_sl2 * m_f2 + m_sl3 * m_f3 + m_sl4 * m_sinzf;
   m_sghs  = m_sgh2 * m_f2 + m_sgh3 * m_f3 + m_sgh4 * m_sinzf;
   m_shs   = m_sh2 * m_f2 + m_sh3 * m_f3;
   m_zm    = m_zmol + m_znl * m_t;
    
   if (init == 'y')
   {
       m_zm = m_zmol;
   };
    
   m_zf    =  m_zm + 2.0 * m_zel * sin( m_zm);
    m_sinzf = sin( m_zf);
    m_f2    =  0.5 *  m_sinzf *  m_sinzf - 0.25;
    m_f3    = -0.5 *  m_sinzf * cos( m_zf);
    m_sel   =  m_ee2 *  m_f2 +  m_e3 *  m_f3;
    m_sil   =  m_xi2 *  m_f2 +  m_xi3 *  m_f3;
    m_sll   =  m_xl2 *  m_f2 +  m_xl3 *  m_f3 +  m_xl4 *  m_sinzf;
    m_sghl  =  m_xgh2 *  m_f2 +  m_xgh3 *  m_f3 +  m_xgh4 *  m_sinzf;
    m_shll  =  m_xh2 *  m_f2 +  m_xh3 *  m_f3;
    m_pe    =  m_ses +  m_sel;
    m_pinc  =  m_sis +  m_sil;
    m_pl    =  m_sls +  m_sll;
    m_pgh   =  m_sghs +  m_sghl;
    m_ph    =  m_shs +  m_shll;

}
