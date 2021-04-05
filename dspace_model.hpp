//
//  dspace_model.hpp
//  source
//
//  Created by Kwadwo Oteng-Amoako on 11/11/2020.
//  Copyright © 2020 Kwadwo Oteng-Amoko. All rights reserved.
//

#ifndef dspace_model_hpp
#define dspace_model_hpp

// object header files
#include "orbital.hpp"
#include "utilities.hpp"

using namespace std;

class dspace_model
{
   
    
private:
    double d2201;
    double d2211;
    double d3210;
    double d3222;
    double d4410;
    double d4422;
    double d5220;
    double d5232;
    double d5421;
    double d5433;
    double dedt;
    double del1;
    double del2;
    double del3;
    double didt;
    double dmdt;
    double dnodt;
    double domdt;
    double irez;
    double argpo;
    double argpdot;
    double t;
    double tc;
    double gsto;
    double xfact;
    double xlamo;
    double no;
    double atime;
    double em;
    double argpm;
    double inclm;
    double xli;
    double mm;
    double xni;
    double nodem;
    double nm;
    
    
    // get the model output parameters
    double dndt;
    double ft;
    double delt;
    double iretn;
    double iret;
    double xldot;
    double xndt;
    double xnddt;
    double xomi;
    double x2omi;
    double x2li;
    double xl;
    double theta;
    
public:
        dspace_model(double d2201,double d2211,double d3210,
        double d3222, double d4410, double d4422,
        double d5220,double d5232,double d5421,
        double d5433,double dedt,double del1,
        double del2,double del3,double didt,
        double dmdt,double dnodt,double domdt,
        double irez,double argpo,double rgpdot,double t,
        double tc, double sto,double xfact,double xlamo, double no,
        double satrec_atime, double em, double argpm, double inclm, double xli, double mm,
        double satrec_xni,double nodem,double nm);

    void setd2201 ();
    void setd2211 ();
    void setd3210 ();
    void setd3222 ();
    void setd4410 ();
    void setd4422 ();
    void setd5220 ();
    void setd5232 ();
    void setd5421 ();
    void setd5433 ();
    void setdedt ();
    void setdel2 ();
    void setdel3 ();
    void setdidt ();
    void setdmdt ();
    void setdnodt ();
    void setdomdt ();;
    void setirez ();
    void setargpo ();
    void setargpdot ();
    void sett();
    void settc ();
    void setgsto ();
    void setxfact ();
    void setxlamo ();
    void setno ();
    void setatime ();
    void setem ();
    void setargpm ();
    void setinclm ();
    void setxli ();
    void setmm ();
    void setxni ();
    void setnodem ();
    void setnm ();
    
    void getd2201 ();
    void getd2211 ();
    void getd3210 ();
    void getd3222 ();
    void getd4410 ();
    void getd4422 ();
    void getd5220 ();
    void getd5232 ();
    void getd5421 ();
    void getd5433 ();
    void getdedt ();
    void getdel2 ();
    void getdel3 ();
    void getdidt ();
    void getdmdt ();
    void getdnodt ();
    void getdomdt ();;
    void getirez ();
    void getargpo ();
    void getargpdot ();
    void gett ();
    void gettc ();
    void getgsto ();
    void getxfact ();
    void getxlamo ();
    void getno ();
    void getatime ();
    void getem ();
    void getargpm ();
    void getinclm ();
    void getxli ();
    void getmm ();
    void getxni ();
    void getnodem ();
    void getnm ();
    
        dspace_model();
        ~dspace_model();
    
    void getModelParameters                        ();
    
    void set_dspace_line1(double satrec_d2201, double satrec_d2211,double satrec_d3210, double satrec_d3222, double satrec_d4410, double satrec_d4422, double satrec_d5220, double satrec_d5232, double satrec_d5421);
    
    void set_dspace_line2(double satrec_d5433, double satrec_dedt, double satrec_del1,
       double satrec_del2, double satrec_del3, double satrec_didt,
                          double satrec_dmdt, double satrec_dnodt, double satrec_domdt);
    
    void set_dspace_line3(double satrec_irez,double satrec_argpo, double satrec_argpdot, double satrec_t, double satrec_tc, double satrec_gsto, double satrec_xfact, double satrec_xlamo, double satrec_no);
    
    void set_dspace_line4(double satrec_atime, double satrec_em, double satrec_argpm, double satrec_inclm, double satrec_xli, double satrec_mm, double satrec_xni,double satrec_nodem, double satrec_nm);
};
#endif /* dspace_model_hpp */
