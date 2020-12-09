//
//  satrec.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 08/12/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef satrec_hpp
#define satrec_hpp

#include <stdio.h>



struct satrec
{
    
public:

    
     // ---------------------- constants -----------------------------
    double const_pi  = 3.14159267;
    double const_twopi = 2.0 * const_pi;
    double const_zns   = 1.19459e-5;
    double const_zes   = 0.01675;
    double const_znl   = 1.5835218e-4;
    double const_zel   = 0.05490;
    char   global_opsmode;
    
    char    satrec_init,    satrec_inclp;
    
    // outputs
    double
    
    output_satrec_eep,
    output_satrec_einclp,
    output_satrec_enodep,
    output_satrec_eargpp,
    output_satrec_emp;
    
    // inputs
    double
   
    satrec_e3,
    satrec_ee2,
    satrec_peo,
    satrec_pgho,
    satrec_pho,
    satrec_pinco,
    satrec_plo,
    satrec_se2,
    satrec_se3,
    satrec_sgh2,
    satrec_sgh3,
    satrec_sgh4,
    satrec_sh2,
    satrec_sh3,
    satrec_si2,
    satrec_si3,
    satrec_sl2,
    satrec_sl3,
    satrec_sl4,
    satrec_t,
    satrec_xgh2,
    satrec_xgh3,
    satrec_xgh4,
    satrec_xh2,
    satrec_xh3,
    satrec_xi2,
    satrec_xi3,
    satrec_xl2,
    satrec_xl3,
    satrec_xl4,
    satrec_zmol,
    satrec_zmos,
    satrec_inclo,
    satrec_ep,
    satrec_nodep,
    satrec_argpp,
    satrec_mp;
    
    // variables
    double
    varZm,
    varZmos,
    varT,
    varZf,
    varSinzf,
    varF2,
    varF3,
    varSes,
    varSis,
    varSls,
    varSghs,
    varShs,
    varSe2,
    varSi2,
    varSe3,
    varSi3,
    varSl2,
    varSgh2,
    varSh2,
    varZmol,
    varSl3,
    varSgh3,
    varSgh4,
    varSl4,
    varSh3,
    varE3,
    varEe2,
    varSil,
    varXi2,
    varSel,
    varXi3,
    varSli,
    varSghl,
    varShll,
    varSll,
    varXl4,
    varXl2,
    varXl3,
    varXgh2,
    varXgh3,
    varXgh4,
    varXh2,
    varXh3,
    varPe,
    varPinc,
    varPl,
    varPgh,
    varPh,
    varPeo,
    varPinco,
    varPlo,
    varPgho,
    varEp,
    varPho,
    varInclp,
    varSinip,
    varCosip,
    varArgpp,
    varNodep,
    varMp,
    varSinop,
    varCosop,
    varAlfdp,
    varBetdp,
    varDalf,
    varDbet,
    varOpsmode,
    varXls,
    varDls,
    varXnoh;
   
};

#endif
/* satrec_hpp */
