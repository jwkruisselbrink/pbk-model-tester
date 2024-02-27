/* PBPK_generic_model_v6/PBPK_generic_model_v6.c for R deSolve package
   ___________________________________________________

   Model File:  PBPK_generic_model_v6/PBPK_generic_model_v6.model

   Date:  Tue Feb 27 20:57:47 2024

   Created by:  "/cygdrive/c/Programs/MCSim/mod v6.1.0"
    -- a model preprocessor by Don Maszle
   ___________________________________________________

   Copyright (c) 1993-2019 Free Software Foundation, Inc.

   Model calculations for compartmental model:

   13 States:
     QVen = 0.0,
     QArt = 0.0,
     QFat = 0.0,
     QPoor = 0.0,
     QRich = 0.0,
     QLiver = 0.0,
     QSkin_u = 0.0,
     QSkin_e = 0.0,
     QSkin_sc_u = 0.0,
     QSkin_sc_e = 0.0,
     QGut = 0.0,
     QExcret = 0.0,
     QMetab = 0.0,

   11 Outputs:
    "QTotal",
    "CVen",
    "CArt",
    "CFat",
    "CPoor",
    "CRich",
    "CLiver",
    "CSkin_u",
    "CSkin_e",
    "CSkin_sc_u",
    "CSkin_sc_e",

   4 Inputs:
     Ing_rate (forcing function)
     Skin_exposure_rate (forcing function)
     Cinh (forcing function)
     Event1 (forcing function)

   60 Parameters:
     BM = 70,
     BSA = 190,
     scVFat = 0.209,
     scVRich = 0.105,
     scVLiver = 0.024,
     scVBlood = 0.068,
     Height_sc = 0.0001,
     Height_vs = 0.0122,
     scFBlood = 4.8,
     scFFat = 0.085,
     scFPoor = 0.120,
     scFLiver = 0.270,
     scFSkin = 0.050,
     Falv = 2220,
     mic = 52.5,
     PCAir = 0,
     log_PCFat = 0,
     log_aPoor = log (1) - log_PCFat,
     log_aRich = log (1) - log_PCFat,
     log_aLiver = log (1) - log_PCFat,
     log_aSkin = log (1) - log_PCFat,
     log_aSkin_sc = log (1) - log_PCFat,
     Kp_sc_vs = 0,
     Ke = 12,
     Michaelis = 0,
     Vmax = 0,
     Km = 0,
     CLH = 0,
     fub = 0,
     Frac = 0,
     kGut = 0,
     Tinh = 0,
     OralDose = 0,
     DermalDose = 0,
     fSA_exposed = 1,
     FBlood = 0,
     FFat = 0,
     FPoor = 0,
     FRich = 0,
     FLiver = 0,
     FSkin = 0,
     VFat = 0,
     VRich = 0,
     VLiver = 0,
     VSkin_e = 0,
     VSkin_u = 0,
     VSkin_sc_e = 0,
     VSkin_sc_u = 0,
     VBlood = 0,
     VPoor = 0,
     VArt = 0,
     VVen = 0,
     FSkin_e = 0,
     FSkin_u = 0,
     PCFat = 0,
     PCPoor = 0,
     PCRich = 0,
     PCLiver = 0,
     PCSkin = 0,
     PCSkin_sc = 0,
*/

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <R_ext/Rdynload.h>

/* Model variables: States */
#define ID_QVen 0x00000
#define ID_QArt 0x00001
#define ID_QFat 0x00002
#define ID_QPoor 0x00003
#define ID_QRich 0x00004
#define ID_QLiver 0x00005
#define ID_QSkin_u 0x00006
#define ID_QSkin_e 0x00007
#define ID_QSkin_sc_u 0x00008
#define ID_QSkin_sc_e 0x00009
#define ID_QGut 0x0000a
#define ID_QExcret 0x0000b
#define ID_QMetab 0x0000c

/* Model variables: Outputs */
#define ID_QTotal 0x00000
#define ID_CVen 0x00001
#define ID_CArt 0x00002
#define ID_CFat 0x00003
#define ID_CPoor 0x00004
#define ID_CRich 0x00005
#define ID_CLiver 0x00006
#define ID_CSkin_u 0x00007
#define ID_CSkin_e 0x00008
#define ID_CSkin_sc_u 0x00009
#define ID_CSkin_sc_e 0x0000a

/* Parameters */
static double parms[60];

#define BM parms[0]
#define BSA parms[1]
#define scVFat parms[2]
#define scVRich parms[3]
#define scVLiver parms[4]
#define scVBlood parms[5]
#define Height_sc parms[6]
#define Height_vs parms[7]
#define scFBlood parms[8]
#define scFFat parms[9]
#define scFPoor parms[10]
#define scFLiver parms[11]
#define scFSkin parms[12]
#define Falv parms[13]
#define mic parms[14]
#define PCAir parms[15]
#define log_PCFat parms[16]
#define log_aPoor parms[17]
#define log_aRich parms[18]
#define log_aLiver parms[19]
#define log_aSkin parms[20]
#define log_aSkin_sc parms[21]
#define Kp_sc_vs parms[22]
#define Ke parms[23]
#define Michaelis parms[24]
#define Vmax parms[25]
#define Km parms[26]
#define CLH parms[27]
#define fub parms[28]
#define Frac parms[29]
#define kGut parms[30]
#define Tinh parms[31]
#define OralDose parms[32]
#define DermalDose parms[33]
#define fSA_exposed parms[34]
#define FBlood parms[35]
#define FFat parms[36]
#define FPoor parms[37]
#define FRich parms[38]
#define FLiver parms[39]
#define FSkin parms[40]
#define VFat parms[41]
#define VRich parms[42]
#define VLiver parms[43]
#define VSkin_e parms[44]
#define VSkin_u parms[45]
#define VSkin_sc_e parms[46]
#define VSkin_sc_u parms[47]
#define VBlood parms[48]
#define VPoor parms[49]
#define VArt parms[50]
#define VVen parms[51]
#define FSkin_e parms[52]
#define FSkin_u parms[53]
#define PCFat parms[54]
#define PCPoor parms[55]
#define PCRich parms[56]
#define PCLiver parms[57]
#define PCSkin parms[58]
#define PCSkin_sc parms[59]

/* Forcing (Input) functions */
static double forc[4];

#define Ing_rate forc[0]
#define Skin_exposure_rate forc[1]
#define Cinh forc[2]
#define Event1 forc[3]

/* Function definitions for delay differential equations */

int Nout=1;
int nr[1]={0};
double ytau[1] = {0.0};

static double yini[13] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; /*Array of initial state variables*/

void lagvalue(double T, int *nr, int N, double *ytau) {
  static void(*fun)(double, int*, int, double*) = NULL;
  if (fun == NULL)
    fun = (void(*)(double, int*, int, double*))R_GetCCallable("deSolve", "lagvalue");
  return fun(T, nr, N, ytau);
}

double CalcDelay(int hvar, double dTime, double delay) {
  double T = dTime-delay;
  if (dTime > delay){
    nr[0] = hvar;
    lagvalue( T, nr, Nout, ytau );
}
  else{
    ytau[0] = yini[hvar];
}
  return(ytau[0]);
}

/*----- Initializers */
void initmod (void (* odeparms)(int *, double *))
{
  int N=60;
  odeparms(&N, parms);
}

void initforc (void (* odeforcs)(int *, double *))
{
  int N=4;
  odeforcs(&N, forc);
}


/* Calling R code will ensure that input y has same
   dimension as yini */
void initState (double *y)
{
  int i;

  for (i = 0; i < sizeof(yini) / sizeof(yini[0]); i++)
  {
    yini[i] = y[i];
  }
}

void getParms (double *inParms, double *out, int *nout) {
/*----- Model scaling */

  int i;

  for (i = 0; i < *nout; i++) {
    parms[i] = inParms[i];
  }


  FBlood = scFBlood * BM ;

  FFat = FBlood * scFFat ;
  FPoor = FBlood * scFPoor ;
  FLiver = FBlood * scFLiver ;
  FSkin = FBlood * scFSkin ;

  FRich = FBlood - FFat - FPoor - FLiver - FSkin ;

  VFat = BM * scVFat ;
  VRich = BM * scVRich ;
  VLiver = BM * scVLiver ;

  VSkin_e = BSA * Height_vs * fSA_exposed ;
  VSkin_u = BSA * Height_vs * ( 1 - fSA_exposed ) ;

  VSkin_sc_e = BSA * Height_sc * fSA_exposed ;
  VSkin_sc_u = BSA * Height_sc * ( 1 - fSA_exposed ) ;

  VBlood = BM * scVBlood ;

  VPoor = BM - VFat - VRich - VLiver - VSkin_e - VSkin_u - VSkin_sc_e - VSkin_sc_u - VBlood - 0.1 * BM ;

  VArt = VBlood / 3.0 ;
  VVen = VBlood - VArt ;

  FSkin_e = FSkin * fSA_exposed ;
  FSkin_u = FSkin - FSkin_e ;

  PCFat = exp ( log_PCFat ) ;
  PCLiver = exp ( log_aLiver + log_PCFat ) ;
  PCRich = exp ( log_aRich + log_PCFat ) ;
  PCPoor = exp ( log_aPoor + log_PCFat ) ;
  PCSkin_sc = exp ( log_aSkin_sc + log_PCFat ) ;
  PCSkin = exp ( log_aSkin + log_PCFat ) ;

  for (i = 0; i < *nout; i++) {
    out[i] = parms[i];
  }
  }
/*----- Dynamics section */

void derivs (int *neq, double *pdTime, double *y, double *ydot, double *yout, int *ip)
{
  /* local */ double tmp;

  yout[ID_CFat] = y[ID_QFat] / VFat ;

  yout[ID_CPoor] = y[ID_QPoor] / VPoor ;

  yout[ID_CRich] = y[ID_QRich] / VRich ;

  yout[ID_CLiver] = y[ID_QLiver] / VLiver ;

  yout[ID_CSkin_sc_u] = ( VSkin_sc_u > 0 ? y[ID_QSkin_sc_u] / VSkin_sc_u : 0 ) ;

  yout[ID_CSkin_sc_e] = ( VSkin_sc_e > 0 ? y[ID_QSkin_sc_e] / VSkin_sc_e : 0 ) ;

  yout[ID_CSkin_u] = ( VSkin_u > 0 ? y[ID_QSkin_u] / VSkin_u : 0 ) ;

  yout[ID_CSkin_e] = ( VSkin_e > 0 ? y[ID_QSkin_e] / VSkin_e : 0 ) ;

  yout[ID_CArt] = y[ID_QArt] / VArt ;

  yout[ID_CVen] = y[ID_QVen] / VVen ;

  ydot[ID_QFat] = FFat * ( yout[ID_CArt] - yout[ID_CFat] / PCFat ) ;

  ydot[ID_QPoor] = FPoor * ( yout[ID_CArt] - yout[ID_CPoor] / PCPoor ) ;

  ydot[ID_QRich] = FRich * ( yout[ID_CArt] - yout[ID_CRich] / PCRich ) ;

  ydot[ID_QGut] = - kGut * y[ID_QGut] + Frac * Ing_rate ;

  tmp = yout[ID_CLiver] / PCLiver ;

  ydot[ID_QMetab] = ( Michaelis > 0.5 ? fub * VLiver * Vmax * tmp / ( Km + tmp ) : fub * CLH * tmp ) ;

  ydot[ID_QLiver] = FLiver * ( yout[ID_CArt] - tmp ) + kGut * y[ID_QGut] - ydot[ID_QMetab] ;

  ydot[ID_QSkin_sc_u] = Kp_sc_vs * BSA * ( 1 - fSA_exposed ) * ( yout[ID_CSkin_u] / PCSkin_sc - yout[ID_CSkin_sc_u] ) ;

  ydot[ID_QSkin_u] = FSkin_u * ( yout[ID_CArt] - yout[ID_CSkin_u] / PCSkin ) - ydot[ID_QSkin_sc_u] ;

  tmp = Kp_sc_vs * BSA * fSA_exposed * ( yout[ID_CSkin_e] / PCSkin_sc - yout[ID_CSkin_sc_e] ) ;

  ydot[ID_QSkin_sc_e] = tmp + Skin_exposure_rate ;

  ydot[ID_QSkin_e] = FSkin_e * ( yout[ID_CArt] - yout[ID_CSkin_e] / PCSkin ) - tmp ;

  ydot[ID_QExcret] = Ke * fub * yout[ID_CArt] ;

  ydot[ID_QArt] = Falv * ( Cinh - yout[ID_CArt] / PCAir ) + FBlood * ( yout[ID_CVen] - yout[ID_CArt] ) - ydot[ID_QExcret] ;

  ydot[ID_QVen] = FFat * yout[ID_CFat] / PCFat + FPoor * yout[ID_CPoor] / PCPoor + FRich * yout[ID_CRich] / PCRich + FLiver * yout[ID_CLiver] / PCLiver + FSkin_u * yout[ID_CSkin_u] / PCSkin + FSkin_e * yout[ID_CSkin_e] / PCSkin - FBlood * yout[ID_CVen] ;

  yout[ID_QTotal] = y[ID_QVen] + y[ID_QArt] + y[ID_QFat] + y[ID_QPoor] + y[ID_QRich] + y[ID_QLiver] + y[ID_QSkin_u] + y[ID_QSkin_e] + y[ID_QSkin_sc_u] + y[ID_QSkin_sc_e] + y[ID_QGut] + y[ID_QExcret] + y[ID_QMetab] ;

} /* derivs */


/*----- Jacobian calculations: */
void jac (int *neq, double *t, double *y, int *ml, int *mu, double *pd, int *nrowpd, double *yout, int *ip)
{

} /* jac */


/*----- Events calculations: */
void event (int *n, double *t, double *y)
{

  y[ID_QGut] = 1 ;

} /* event */

/*----- Roots calculations: */
void root (int *neq, double *t, double *y, int *ng, double *gout, double *out, int *ip)
{

} /* root */

