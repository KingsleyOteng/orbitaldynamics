//
//  dpper.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 06/12/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//



#include <stdio.h>
#include <string>
#include <sstream>      // std::istringstream
#include <iostream>     // std::cout
#include <vector>
#include <iostream>
#include <vector>       // c-11 vector
#include <algorithm>    // c-11 algoithm
#include <time.h>
#include <fstream>
#include <stdio.h>
#include <array>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "orbital.hpp"
#include "utilities.hpp"
#include "satrec.hpp"

using namespace std;

#ifndef dpper_hpp
#define dpper_hpp
class dpper
{
    
private:
    
    double
    e3,     ee2,    peo,    pgho,   pho,    pinco,  plo,    se2,
    se3,    sgh2,   sgh3,   sgh4,   sh2,    sh3,    si2,    si3,
    sl2,    sl3,    sl4,    t,      xgh2,   xgh3,   xgh4,   xh2,
    xh3,    xi2,    xi3,    xl2,    xl3,    xl4,    zmol,
    zmos,   inclo,  init,   ep,     inclp,  nodep, argpp,  mp;
    //m_twopi, m_pi, m_zes,m_znl, m_zel, m_zns,
    
    double  m_zm, m_zmos, m_t,   m_zf, m_sinzf, m_f2, m_f3, m_ses, m_sis, m_sls, m_sghs, m_shs, m_se2, m_si2, m_se3, m_si3, f3, m_sl2, m_sgh2, m_sh2, m_zmol, m_sl3, m_sgh3, m_sgh4, m_sl4, m_sh3, m_e3, m_ee2, m_sil, m_xi2, m_sel, m_xi3, m_sli, m_sghl, m_shll, m_sll, m_xl4, m_xl2, m_xl3, m_xgh2, m_xgh3, m_xgh4, m_xh2, m_xh3, m_pe, m_pinc, m_pl, m_pgh, m_ph, m_peo, m_pinco, m_plo, m_pgho, m_ep, m_pho, m_inclp, m_sinip, m_cosip, m_argpp, m_nodep, m_mp, m_sinop, m_cosop, m_alfdp, m_betdp, m_dalf, m_dbet, m_opsmode, m_xls, m_dls, m_xnoh;
    

       


    
    
public:
    
    // constructors  and destructors
    dpper();
    ~dpper();
    
    void        set_parameters(orbital *model);
    void        set_parameters
        (double e3, double ee2, double peo,double pgho,double pho, double pinco, double  plo, double se2,double se3, double sgh2, double sgh3, double sgh4, double  sh2, double sh3, double si2, double si3, double sl2, double sl3, double sl4, double t, double xgh2, double xgh3, double xgh4, double xh2, double xh3, double xi2, double xi3, double xl2, double xl3, double xl4, double zmol, double zmos, double inclo, double init, double ep, double inclp, double nodep, double argpp, double mp);
    void        set_parameters (satrec * rec);
    void        set_model();
    
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

#endif /* dpper_hpp */
