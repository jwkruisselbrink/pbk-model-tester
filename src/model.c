/* model.c
   ___________________________________________________

   Model File:  .\BIOMD0000001028\SBML_List.in

   Date:  Sat Jun  3 10:06:13 2023

   Created by:  "/cygdrive/c/Programs/MCSim/mod v6.1.0"
    -- a model preprocessor by Don Maszle
   ___________________________________________________

   Copyright (c) 1993-2019 Free Software Foundation, Inc.

   Model calculations for compartmental model:

   17 States:
     GLCi = 0.097652231064563;
     ATP = 2.52512746499271;
     G6P = 2.52512746499271;
     ADP = 2.52512746499271;
     F6P = 2.52512746499271;
     F16bP = 2.52512746499271;
     AMP = 2.52512746499271;
     DHAP = 2.52512746499271;
     GAP = 2.52512746499271;
     NAD = 1.50329030201531;
     BPG = 1.50329030201531;
     NADH = 1.50329030201531;
     P3G = 0.885688538360659;
     P2G = 0.127695817386632;
     PEP = 0.0632352144936527;
     PYR = 1.81531251192736;
     AcAld = 0.178140579850657;

   0 Outputs:

   0 Inputs:

   95 Parameters:
     J0_Vmax_1 = 97.24;
     J0_Kglc_1 = 1.1918;
     J0_Ki_1 = 0.91;
     J1_Vmax_3 = 1056;
     J1_Kg6p_3 = 1.4;
     J1_Keq_3 = 0.29;
     J1_Kf6p_3 = 0.3;
     J2_Vmax_4 = 110;
     J2_gR_4 = 5.12;
     J2_Kf6p_4 = 0.1;
     J2_Katp_4 = 0.71;
     J2_L0_4 = 0.66;
     J2_Ciatp_4 = 100;
     J2_Kiatp_4 = 0.65;
     J2_Camp_4 = 0.0845;
     J2_Kamp_4 = 0.0995;
     J2_Cf26_4 = 0.0174;
     J2_Kf26_4 = 0.000682;
     J2_Cf16_4 = 0.397;
     J2_Kf16_4 = 0.111;
     J2_Catp_4 = 3;
     J2_F26bP = 0.02;
     J3_Vmax_5 = 94.69;
     J3_Kf16bp_5 = 0.3;
     J3_Keq_5 = 0.069;
     J3_Kdhap_5 = 2;
     J3_Kgap_5 = 2.4;
     J3_Kigap_5 = 10;
     J4_k1_6 = 450000;
     J4_k2_6 = 10000000;
     J5_C_7 = 1;
     J5_Vmaxf_7 = 1152;
     J5_Kgap_7 = 0.21;
     J5_Knad_7 = 0.09;
     J5_Vmaxr_7 = 6719;
     J5_Kbpg_7 = 0.0098;
     J5_Knadh_7 = 0.06;
     J6_Vmax_9 = 2585;
     J6_Kp3g_9 = 1.2;
     J6_Keq_9 = 0.19;
     J6_Kp2g_9 = 0.08;
     J7_Vmax_10 = 201.6;
     J7_Kp2g_10 = 0.04;
     J7_Keq_10 = 6.7;
     J7_Kpep_10 = 0.5;
     J8_Vmax_12 = 857.8;
     J8_Kpyr_12 = 4.33;
     J8_nH_12 = 1.9;
     J9_Vmax_13 = 209.5;
     J9_Ketoh_13 = 17;
     J9_Kinad_13 = 0.92;
     J9_Keq_13 = 6.9E-5;
     J9_Knad_13 = 0.17;
     J9_Knadh_13 = 0.11;
     J9_Kinadh_13 = 0.031;
     J9_Kacald_13 = 1.11;
     J9_Kiacald_13 = 1.1;
     J9_Kietoh_13 = 90;
     J10_Katpase_14 = 39.5;
     J11_k1_15 = 45;
     J11_k2_15 = 100;
     J12_Vmax_16 = 47.11;
     J12_Kdhap_16 = 0.4;
     J12_Knadh_16 = 0.023;
     J12_Keq_16 = 4300;
     J12_Kglycerol_16 = 1;
     J12_Knad_16 = 0.93;
     J13_k_19 = 21.4;
     J14_Vmax_8 = 1288;
     J14_Keq_8 = 3200;
     J14_Kp3g_8 = 0.53;
     J14_Katp_8 = 0.3;
     J14_Kbpg_8 = 0.003;
     J14_Kadp_8 = 0.2;
     J15_Ktrehalose_18 = 2.4;
     J16_Vmax_2 = 236.7;
     J16_Kglc_2 = 0.08;
     J16_Katp_2 = 0.15;
     J16_Keq_2 = 2000;
     J16_Kg6p_2 = 30;
     J16_Kadp_2 = 0.23;
     J17_Vmax_11 = 1000;
     J17_Kpep_11 = 0.14;
     J17_Kadp_11 = 0.53;
     J17_Keq_11 = 6100;
     J17_Kpyr_11 = 21;
     J17_Katp_11 = 1.5;
     J18_KGLYCOGEN_17 = 6;
     GLCo = 2;
     CO2 = 2;
     EtOH = 2;
     Glycerol = 2;
     Glycogen = 2;
     Trehalose = 2;
     Succinate = 2;
*/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include "modelu.h"
#include "random.h"
#include "yourcode.h"


/*----- Indices to Global Variables */

/* Model variables: States and other outputs */
#define ID_GLCi 0x00000
#define ID_ATP 0x00001
#define ID_G6P 0x00002
#define ID_ADP 0x00003
#define ID_F6P 0x00004
#define ID_F16bP 0x00005
#define ID_AMP 0x00006
#define ID_DHAP 0x00007
#define ID_GAP 0x00008
#define ID_NAD 0x00009
#define ID_BPG 0x0000a
#define ID_NADH 0x0000b
#define ID_P3G 0x0000c
#define ID_P2G 0x0000d
#define ID_PEP 0x0000e
#define ID_PYR 0x0000f
#define ID_AcAld 0x00010

/* Inputs */

/* Parameters */
#define ID_J0_Vmax_1 0x00011
#define ID_J0_Kglc_1 0x00012
#define ID_J0_Ki_1 0x00013
#define ID_J1_Vmax_3 0x00014
#define ID_J1_Kg6p_3 0x00015
#define ID_J1_Keq_3 0x00016
#define ID_J1_Kf6p_3 0x00017
#define ID_J2_Vmax_4 0x00018
#define ID_J2_gR_4 0x00019
#define ID_J2_Kf6p_4 0x0001a
#define ID_J2_Katp_4 0x0001b
#define ID_J2_L0_4 0x0001c
#define ID_J2_Ciatp_4 0x0001d
#define ID_J2_Kiatp_4 0x0001e
#define ID_J2_Camp_4 0x0001f
#define ID_J2_Kamp_4 0x00020
#define ID_J2_Cf26_4 0x00021
#define ID_J2_Kf26_4 0x00022
#define ID_J2_Cf16_4 0x00023
#define ID_J2_Kf16_4 0x00024
#define ID_J2_Catp_4 0x00025
#define ID_J2_F26bP 0x00026
#define ID_J3_Vmax_5 0x00027
#define ID_J3_Kf16bp_5 0x00028
#define ID_J3_Keq_5 0x00029
#define ID_J3_Kdhap_5 0x0002a
#define ID_J3_Kgap_5 0x0002b
#define ID_J3_Kigap_5 0x0002c
#define ID_J4_k1_6 0x0002d
#define ID_J4_k2_6 0x0002e
#define ID_J5_C_7 0x0002f
#define ID_J5_Vmaxf_7 0x00030
#define ID_J5_Kgap_7 0x00031
#define ID_J5_Knad_7 0x00032
#define ID_J5_Vmaxr_7 0x00033
#define ID_J5_Kbpg_7 0x00034
#define ID_J5_Knadh_7 0x00035
#define ID_J6_Vmax_9 0x00036
#define ID_J6_Kp3g_9 0x00037
#define ID_J6_Keq_9 0x00038
#define ID_J6_Kp2g_9 0x00039
#define ID_J7_Vmax_10 0x0003a
#define ID_J7_Kp2g_10 0x0003b
#define ID_J7_Keq_10 0x0003c
#define ID_J7_Kpep_10 0x0003d
#define ID_J8_Vmax_12 0x0003e
#define ID_J8_Kpyr_12 0x0003f
#define ID_J8_nH_12 0x00040
#define ID_J9_Vmax_13 0x00041
#define ID_J9_Ketoh_13 0x00042
#define ID_J9_Kinad_13 0x00043
#define ID_J9_Keq_13 0x00044
#define ID_J9_Knad_13 0x00045
#define ID_J9_Knadh_13 0x00046
#define ID_J9_Kinadh_13 0x00047
#define ID_J9_Kacald_13 0x00048
#define ID_J9_Kiacald_13 0x00049
#define ID_J9_Kietoh_13 0x0004a
#define ID_J10_Katpase_14 0x0004b
#define ID_J11_k1_15 0x0004c
#define ID_J11_k2_15 0x0004d
#define ID_J12_Vmax_16 0x0004e
#define ID_J12_Kdhap_16 0x0004f
#define ID_J12_Knadh_16 0x00050
#define ID_J12_Keq_16 0x00051
#define ID_J12_Kglycerol_16 0x00052
#define ID_J12_Knad_16 0x00053
#define ID_J13_k_19 0x00054
#define ID_J14_Vmax_8 0x00055
#define ID_J14_Keq_8 0x00056
#define ID_J14_Kp3g_8 0x00057
#define ID_J14_Katp_8 0x00058
#define ID_J14_Kbpg_8 0x00059
#define ID_J14_Kadp_8 0x0005a
#define ID_J15_Ktrehalose_18 0x0005b
#define ID_J16_Vmax_2 0x0005c
#define ID_J16_Kglc_2 0x0005d
#define ID_J16_Katp_2 0x0005e
#define ID_J16_Keq_2 0x0005f
#define ID_J16_Kg6p_2 0x00060
#define ID_J16_Kadp_2 0x00061
#define ID_J17_Vmax_11 0x00062
#define ID_J17_Kpep_11 0x00063
#define ID_J17_Kadp_11 0x00064
#define ID_J17_Keq_11 0x00065
#define ID_J17_Kpyr_11 0x00066
#define ID_J17_Katp_11 0x00067
#define ID_J18_KGLYCOGEN_17 0x00068
#define ID_GLCo 0x00069
#define ID_CO2 0x0006a
#define ID_EtOH 0x0006b
#define ID_Glycerol 0x0006c
#define ID_Glycogen 0x0006d
#define ID_Trehalose 0x0006e
#define ID_Succinate 0x0006f


/*----- Global Variables */

/* For export. Keep track of who we are. */
char szModelDescFilename[] = ".\BIOMD0000001028\SBML_List.in";
char szModelSourceFilename[] = __FILE__;
char szModelGenAndVersion[] = "/cygdrive/c/Programs/MCSim/mod v6.1.0";

/* Externs */
extern BOOL vbModelReinitd;

/* Model Dimensions */
int vnStates = 17;
int vnOutputs = 0;
int vnModelVars = 17;
int vnInputs = 0;
int vnParms = 95;

/* States and Outputs*/
double vrgModelVars[17];

/* Inputs */
IFN vrgInputs[1];

/* Parameters */
double J0_Vmax_1;
double J0_Kglc_1;
double J0_Ki_1;
double J1_Vmax_3;
double J1_Kg6p_3;
double J1_Keq_3;
double J1_Kf6p_3;
double J2_Vmax_4;
double J2_gR_4;
double J2_Kf6p_4;
double J2_Katp_4;
double J2_L0_4;
double J2_Ciatp_4;
double J2_Kiatp_4;
double J2_Camp_4;
double J2_Kamp_4;
double J2_Cf26_4;
double J2_Kf26_4;
double J2_Cf16_4;
double J2_Kf16_4;
double J2_Catp_4;
double J2_F26bP;
double J3_Vmax_5;
double J3_Kf16bp_5;
double J3_Keq_5;
double J3_Kdhap_5;
double J3_Kgap_5;
double J3_Kigap_5;
double J4_k1_6;
double J4_k2_6;
double J5_C_7;
double J5_Vmaxf_7;
double J5_Kgap_7;
double J5_Knad_7;
double J5_Vmaxr_7;
double J5_Kbpg_7;
double J5_Knadh_7;
double J6_Vmax_9;
double J6_Kp3g_9;
double J6_Keq_9;
double J6_Kp2g_9;
double J7_Vmax_10;
double J7_Kp2g_10;
double J7_Keq_10;
double J7_Kpep_10;
double J8_Vmax_12;
double J8_Kpyr_12;
double J8_nH_12;
double J9_Vmax_13;
double J9_Ketoh_13;
double J9_Kinad_13;
double J9_Keq_13;
double J9_Knad_13;
double J9_Knadh_13;
double J9_Kinadh_13;
double J9_Kacald_13;
double J9_Kiacald_13;
double J9_Kietoh_13;
double J10_Katpase_14;
double J11_k1_15;
double J11_k2_15;
double J12_Vmax_16;
double J12_Kdhap_16;
double J12_Knadh_16;
double J12_Keq_16;
double J12_Kglycerol_16;
double J12_Knad_16;
double J13_k_19;
double J14_Vmax_8;
double J14_Keq_8;
double J14_Kp3g_8;
double J14_Katp_8;
double J14_Kbpg_8;
double J14_Kadp_8;
double J15_Ktrehalose_18;
double J16_Vmax_2;
double J16_Kglc_2;
double J16_Katp_2;
double J16_Keq_2;
double J16_Kg6p_2;
double J16_Kadp_2;
double J17_Vmax_11;
double J17_Kpep_11;
double J17_Kadp_11;
double J17_Keq_11;
double J17_Kpyr_11;
double J17_Katp_11;
double J18_KGLYCOGEN_17;
double GLCo;
double CO2;
double EtOH;
double Glycerol;
double Glycogen;
double Trehalose;
double Succinate;

BOOL bDelays = 0;


/*----- Global Variable Map */

VMMAPSTRCT vrgvmGlo[] = {
  {"GLCi", (PVOID) &vrgModelVars[ID_GLCi], ID_STATE | ID_GLCi},
  {"ATP", (PVOID) &vrgModelVars[ID_ATP], ID_STATE | ID_ATP},
  {"G6P", (PVOID) &vrgModelVars[ID_G6P], ID_STATE | ID_G6P},
  {"ADP", (PVOID) &vrgModelVars[ID_ADP], ID_STATE | ID_ADP},
  {"F6P", (PVOID) &vrgModelVars[ID_F6P], ID_STATE | ID_F6P},
  {"F16bP", (PVOID) &vrgModelVars[ID_F16bP], ID_STATE | ID_F16bP},
  {"AMP", (PVOID) &vrgModelVars[ID_AMP], ID_STATE | ID_AMP},
  {"DHAP", (PVOID) &vrgModelVars[ID_DHAP], ID_STATE | ID_DHAP},
  {"GAP", (PVOID) &vrgModelVars[ID_GAP], ID_STATE | ID_GAP},
  {"NAD", (PVOID) &vrgModelVars[ID_NAD], ID_STATE | ID_NAD},
  {"BPG", (PVOID) &vrgModelVars[ID_BPG], ID_STATE | ID_BPG},
  {"NADH", (PVOID) &vrgModelVars[ID_NADH], ID_STATE | ID_NADH},
  {"P3G", (PVOID) &vrgModelVars[ID_P3G], ID_STATE | ID_P3G},
  {"P2G", (PVOID) &vrgModelVars[ID_P2G], ID_STATE | ID_P2G},
  {"PEP", (PVOID) &vrgModelVars[ID_PEP], ID_STATE | ID_PEP},
  {"PYR", (PVOID) &vrgModelVars[ID_PYR], ID_STATE | ID_PYR},
  {"AcAld", (PVOID) &vrgModelVars[ID_AcAld], ID_STATE | ID_AcAld},
  {"J0_Vmax_1", (PVOID) &J0_Vmax_1, ID_PARM | ID_J0_Vmax_1},
  {"J0_Kglc_1", (PVOID) &J0_Kglc_1, ID_PARM | ID_J0_Kglc_1},
  {"J0_Ki_1", (PVOID) &J0_Ki_1, ID_PARM | ID_J0_Ki_1},
  {"J1_Vmax_3", (PVOID) &J1_Vmax_3, ID_PARM | ID_J1_Vmax_3},
  {"J1_Kg6p_3", (PVOID) &J1_Kg6p_3, ID_PARM | ID_J1_Kg6p_3},
  {"J1_Keq_3", (PVOID) &J1_Keq_3, ID_PARM | ID_J1_Keq_3},
  {"J1_Kf6p_3", (PVOID) &J1_Kf6p_3, ID_PARM | ID_J1_Kf6p_3},
  {"J2_Vmax_4", (PVOID) &J2_Vmax_4, ID_PARM | ID_J2_Vmax_4},
  {"J2_gR_4", (PVOID) &J2_gR_4, ID_PARM | ID_J2_gR_4},
  {"J2_Kf6p_4", (PVOID) &J2_Kf6p_4, ID_PARM | ID_J2_Kf6p_4},
  {"J2_Katp_4", (PVOID) &J2_Katp_4, ID_PARM | ID_J2_Katp_4},
  {"J2_L0_4", (PVOID) &J2_L0_4, ID_PARM | ID_J2_L0_4},
  {"J2_Ciatp_4", (PVOID) &J2_Ciatp_4, ID_PARM | ID_J2_Ciatp_4},
  {"J2_Kiatp_4", (PVOID) &J2_Kiatp_4, ID_PARM | ID_J2_Kiatp_4},
  {"J2_Camp_4", (PVOID) &J2_Camp_4, ID_PARM | ID_J2_Camp_4},
  {"J2_Kamp_4", (PVOID) &J2_Kamp_4, ID_PARM | ID_J2_Kamp_4},
  {"J2_Cf26_4", (PVOID) &J2_Cf26_4, ID_PARM | ID_J2_Cf26_4},
  {"J2_Kf26_4", (PVOID) &J2_Kf26_4, ID_PARM | ID_J2_Kf26_4},
  {"J2_Cf16_4", (PVOID) &J2_Cf16_4, ID_PARM | ID_J2_Cf16_4},
  {"J2_Kf16_4", (PVOID) &J2_Kf16_4, ID_PARM | ID_J2_Kf16_4},
  {"J2_Catp_4", (PVOID) &J2_Catp_4, ID_PARM | ID_J2_Catp_4},
  {"J2_F26bP", (PVOID) &J2_F26bP, ID_PARM | ID_J2_F26bP},
  {"J3_Vmax_5", (PVOID) &J3_Vmax_5, ID_PARM | ID_J3_Vmax_5},
  {"J3_Kf16bp_5", (PVOID) &J3_Kf16bp_5, ID_PARM | ID_J3_Kf16bp_5},
  {"J3_Keq_5", (PVOID) &J3_Keq_5, ID_PARM | ID_J3_Keq_5},
  {"J3_Kdhap_5", (PVOID) &J3_Kdhap_5, ID_PARM | ID_J3_Kdhap_5},
  {"J3_Kgap_5", (PVOID) &J3_Kgap_5, ID_PARM | ID_J3_Kgap_5},
  {"J3_Kigap_5", (PVOID) &J3_Kigap_5, ID_PARM | ID_J3_Kigap_5},
  {"J4_k1_6", (PVOID) &J4_k1_6, ID_PARM | ID_J4_k1_6},
  {"J4_k2_6", (PVOID) &J4_k2_6, ID_PARM | ID_J4_k2_6},
  {"J5_C_7", (PVOID) &J5_C_7, ID_PARM | ID_J5_C_7},
  {"J5_Vmaxf_7", (PVOID) &J5_Vmaxf_7, ID_PARM | ID_J5_Vmaxf_7},
  {"J5_Kgap_7", (PVOID) &J5_Kgap_7, ID_PARM | ID_J5_Kgap_7},
  {"J5_Knad_7", (PVOID) &J5_Knad_7, ID_PARM | ID_J5_Knad_7},
  {"J5_Vmaxr_7", (PVOID) &J5_Vmaxr_7, ID_PARM | ID_J5_Vmaxr_7},
  {"J5_Kbpg_7", (PVOID) &J5_Kbpg_7, ID_PARM | ID_J5_Kbpg_7},
  {"J5_Knadh_7", (PVOID) &J5_Knadh_7, ID_PARM | ID_J5_Knadh_7},
  {"J6_Vmax_9", (PVOID) &J6_Vmax_9, ID_PARM | ID_J6_Vmax_9},
  {"J6_Kp3g_9", (PVOID) &J6_Kp3g_9, ID_PARM | ID_J6_Kp3g_9},
  {"J6_Keq_9", (PVOID) &J6_Keq_9, ID_PARM | ID_J6_Keq_9},
  {"J6_Kp2g_9", (PVOID) &J6_Kp2g_9, ID_PARM | ID_J6_Kp2g_9},
  {"J7_Vmax_10", (PVOID) &J7_Vmax_10, ID_PARM | ID_J7_Vmax_10},
  {"J7_Kp2g_10", (PVOID) &J7_Kp2g_10, ID_PARM | ID_J7_Kp2g_10},
  {"J7_Keq_10", (PVOID) &J7_Keq_10, ID_PARM | ID_J7_Keq_10},
  {"J7_Kpep_10", (PVOID) &J7_Kpep_10, ID_PARM | ID_J7_Kpep_10},
  {"J8_Vmax_12", (PVOID) &J8_Vmax_12, ID_PARM | ID_J8_Vmax_12},
  {"J8_Kpyr_12", (PVOID) &J8_Kpyr_12, ID_PARM | ID_J8_Kpyr_12},
  {"J8_nH_12", (PVOID) &J8_nH_12, ID_PARM | ID_J8_nH_12},
  {"J9_Vmax_13", (PVOID) &J9_Vmax_13, ID_PARM | ID_J9_Vmax_13},
  {"J9_Ketoh_13", (PVOID) &J9_Ketoh_13, ID_PARM | ID_J9_Ketoh_13},
  {"J9_Kinad_13", (PVOID) &J9_Kinad_13, ID_PARM | ID_J9_Kinad_13},
  {"J9_Keq_13", (PVOID) &J9_Keq_13, ID_PARM | ID_J9_Keq_13},
  {"J9_Knad_13", (PVOID) &J9_Knad_13, ID_PARM | ID_J9_Knad_13},
  {"J9_Knadh_13", (PVOID) &J9_Knadh_13, ID_PARM | ID_J9_Knadh_13},
  {"J9_Kinadh_13", (PVOID) &J9_Kinadh_13, ID_PARM | ID_J9_Kinadh_13},
  {"J9_Kacald_13", (PVOID) &J9_Kacald_13, ID_PARM | ID_J9_Kacald_13},
  {"J9_Kiacald_13", (PVOID) &J9_Kiacald_13, ID_PARM | ID_J9_Kiacald_13},
  {"J9_Kietoh_13", (PVOID) &J9_Kietoh_13, ID_PARM | ID_J9_Kietoh_13},
  {"J10_Katpase_14", (PVOID) &J10_Katpase_14, ID_PARM | ID_J10_Katpase_14},
  {"J11_k1_15", (PVOID) &J11_k1_15, ID_PARM | ID_J11_k1_15},
  {"J11_k2_15", (PVOID) &J11_k2_15, ID_PARM | ID_J11_k2_15},
  {"J12_Vmax_16", (PVOID) &J12_Vmax_16, ID_PARM | ID_J12_Vmax_16},
  {"J12_Kdhap_16", (PVOID) &J12_Kdhap_16, ID_PARM | ID_J12_Kdhap_16},
  {"J12_Knadh_16", (PVOID) &J12_Knadh_16, ID_PARM | ID_J12_Knadh_16},
  {"J12_Keq_16", (PVOID) &J12_Keq_16, ID_PARM | ID_J12_Keq_16},
  {"J12_Kglycerol_16", (PVOID) &J12_Kglycerol_16, ID_PARM | ID_J12_Kglycerol_16},
  {"J12_Knad_16", (PVOID) &J12_Knad_16, ID_PARM | ID_J12_Knad_16},
  {"J13_k_19", (PVOID) &J13_k_19, ID_PARM | ID_J13_k_19},
  {"J14_Vmax_8", (PVOID) &J14_Vmax_8, ID_PARM | ID_J14_Vmax_8},
  {"J14_Keq_8", (PVOID) &J14_Keq_8, ID_PARM | ID_J14_Keq_8},
  {"J14_Kp3g_8", (PVOID) &J14_Kp3g_8, ID_PARM | ID_J14_Kp3g_8},
  {"J14_Katp_8", (PVOID) &J14_Katp_8, ID_PARM | ID_J14_Katp_8},
  {"J14_Kbpg_8", (PVOID) &J14_Kbpg_8, ID_PARM | ID_J14_Kbpg_8},
  {"J14_Kadp_8", (PVOID) &J14_Kadp_8, ID_PARM | ID_J14_Kadp_8},
  {"J15_Ktrehalose_18", (PVOID) &J15_Ktrehalose_18, ID_PARM | ID_J15_Ktrehalose_18},
  {"J16_Vmax_2", (PVOID) &J16_Vmax_2, ID_PARM | ID_J16_Vmax_2},
  {"J16_Kglc_2", (PVOID) &J16_Kglc_2, ID_PARM | ID_J16_Kglc_2},
  {"J16_Katp_2", (PVOID) &J16_Katp_2, ID_PARM | ID_J16_Katp_2},
  {"J16_Keq_2", (PVOID) &J16_Keq_2, ID_PARM | ID_J16_Keq_2},
  {"J16_Kg6p_2", (PVOID) &J16_Kg6p_2, ID_PARM | ID_J16_Kg6p_2},
  {"J16_Kadp_2", (PVOID) &J16_Kadp_2, ID_PARM | ID_J16_Kadp_2},
  {"J17_Vmax_11", (PVOID) &J17_Vmax_11, ID_PARM | ID_J17_Vmax_11},
  {"J17_Kpep_11", (PVOID) &J17_Kpep_11, ID_PARM | ID_J17_Kpep_11},
  {"J17_Kadp_11", (PVOID) &J17_Kadp_11, ID_PARM | ID_J17_Kadp_11},
  {"J17_Keq_11", (PVOID) &J17_Keq_11, ID_PARM | ID_J17_Keq_11},
  {"J17_Kpyr_11", (PVOID) &J17_Kpyr_11, ID_PARM | ID_J17_Kpyr_11},
  {"J17_Katp_11", (PVOID) &J17_Katp_11, ID_PARM | ID_J17_Katp_11},
  {"J18_KGLYCOGEN_17", (PVOID) &J18_KGLYCOGEN_17, ID_PARM | ID_J18_KGLYCOGEN_17},
  {"GLCo", (PVOID) &GLCo, ID_PARM | ID_GLCo},
  {"CO2", (PVOID) &CO2, ID_PARM | ID_CO2},
  {"EtOH", (PVOID) &EtOH, ID_PARM | ID_EtOH},
  {"Glycerol", (PVOID) &Glycerol, ID_PARM | ID_Glycerol},
  {"Glycogen", (PVOID) &Glycogen, ID_PARM | ID_Glycogen},
  {"Trehalose", (PVOID) &Trehalose, ID_PARM | ID_Trehalose},
  {"Succinate", (PVOID) &Succinate, ID_PARM | ID_Succinate},
  {"", NULL, 0} /* End flag */
};  /* vrgpvmGlo[] */


/*----- InitModel
   Should be called to initialize model variables at
   the beginning of experiment before reading
   variants from the simulation spec file.
*/

void InitModel(void)
{
  /* Initialize things in the order that they appear in
     model definition file so that dependencies are
     handled correctly. */

  J0_Vmax_1 = 97.24;
  J0_Kglc_1 = 1.1918;
  J0_Ki_1 = 0.91;
  J1_Vmax_3 = 1056;
  J1_Kg6p_3 = 1.4;
  J1_Keq_3 = 0.29;
  J1_Kf6p_3 = 0.3;
  J2_Vmax_4 = 110;
  J2_gR_4 = 5.12;
  J2_Kf6p_4 = 0.1;
  J2_Katp_4 = 0.71;
  J2_L0_4 = 0.66;
  J2_Ciatp_4 = 100;
  J2_Kiatp_4 = 0.65;
  J2_Camp_4 = 0.0845;
  J2_Kamp_4 = 0.0995;
  J2_Cf26_4 = 0.0174;
  J2_Kf26_4 = 0.000682;
  J2_Cf16_4 = 0.397;
  J2_Kf16_4 = 0.111;
  J2_Catp_4 = 3;
  J2_F26bP = 0.02;
  J3_Vmax_5 = 94.69;
  J3_Kf16bp_5 = 0.3;
  J3_Keq_5 = 0.069;
  J3_Kdhap_5 = 2;
  J3_Kgap_5 = 2.4;
  J3_Kigap_5 = 10;
  J4_k1_6 = 450000;
  J4_k2_6 = 10000000;
  J5_C_7 = 1;
  J5_Vmaxf_7 = 1152;
  J5_Kgap_7 = 0.21;
  J5_Knad_7 = 0.09;
  J5_Vmaxr_7 = 6719;
  J5_Kbpg_7 = 0.0098;
  J5_Knadh_7 = 0.06;
  J6_Vmax_9 = 2585;
  J6_Kp3g_9 = 1.2;
  J6_Keq_9 = 0.19;
  J6_Kp2g_9 = 0.08;
  J7_Vmax_10 = 201.6;
  J7_Kp2g_10 = 0.04;
  J7_Keq_10 = 6.7;
  J7_Kpep_10 = 0.5;
  J8_Vmax_12 = 857.8;
  J8_Kpyr_12 = 4.33;
  J8_nH_12 = 1.9;
  J9_Vmax_13 = 209.5;
  J9_Ketoh_13 = 17;
  J9_Kinad_13 = 0.92;
  J9_Keq_13 = 6.9E-5;
  J9_Knad_13 = 0.17;
  J9_Knadh_13 = 0.11;
  J9_Kinadh_13 = 0.031;
  J9_Kacald_13 = 1.11;
  J9_Kiacald_13 = 1.1;
  J9_Kietoh_13 = 90;
  J10_Katpase_14 = 39.5;
  J11_k1_15 = 45;
  J11_k2_15 = 100;
  J12_Vmax_16 = 47.11;
  J12_Kdhap_16 = 0.4;
  J12_Knadh_16 = 0.023;
  J12_Keq_16 = 4300;
  J12_Kglycerol_16 = 1;
  J12_Knad_16 = 0.93;
  J13_k_19 = 21.4;
  J14_Vmax_8 = 1288;
  J14_Keq_8 = 3200;
  J14_Kp3g_8 = 0.53;
  J14_Katp_8 = 0.3;
  J14_Kbpg_8 = 0.003;
  J14_Kadp_8 = 0.2;
  J15_Ktrehalose_18 = 2.4;
  J16_Vmax_2 = 236.7;
  J16_Kglc_2 = 0.08;
  J16_Katp_2 = 0.15;
  J16_Keq_2 = 2000;
  J16_Kg6p_2 = 30;
  J16_Kadp_2 = 0.23;
  J17_Vmax_11 = 1000;
  J17_Kpep_11 = 0.14;
  J17_Kadp_11 = 0.53;
  J17_Keq_11 = 6100;
  J17_Kpyr_11 = 21;
  J17_Katp_11 = 1.5;
  J18_KGLYCOGEN_17 = 6;
  vrgModelVars[ID_GLCi] = 0.097652231064563;
  vrgModelVars[ID_ATP] = 2.52512746499271;
  vrgModelVars[ID_G6P] = 2.52512746499271;
  vrgModelVars[ID_ADP] = 2.52512746499271;
  vrgModelVars[ID_F6P] = 2.52512746499271;
  vrgModelVars[ID_F16bP] = 2.52512746499271;
  vrgModelVars[ID_AMP] = 2.52512746499271;
  vrgModelVars[ID_DHAP] = 2.52512746499271;
  vrgModelVars[ID_GAP] = 2.52512746499271;
  vrgModelVars[ID_NAD] = 1.50329030201531;
  vrgModelVars[ID_BPG] = 1.50329030201531;
  vrgModelVars[ID_NADH] = 1.50329030201531;
  vrgModelVars[ID_P3G] = 0.885688538360659;
  vrgModelVars[ID_P2G] = 0.127695817386632;
  vrgModelVars[ID_PEP] = 0.0632352144936527;
  vrgModelVars[ID_PYR] = 1.81531251192736;
  vrgModelVars[ID_AcAld] = 0.178140579850657;
  GLCo = 2;
  CO2 = 2;
  EtOH = 2;
  Glycerol = 2;
  Glycogen = 2;
  Trehalose = 2;
  Succinate = 2;

  vbModelReinitd = TRUE;

} /* InitModel */


/*----- Dynamics section */

void CalcDeriv (double  rgModelVars[], double  rgDerivs[], PDOUBLE pdTime)
{
  /* local */ double J0;
  /* local */ double J1;
  /* local */ double J2;
  /* local */ double J3;
  /* local */ double J4;
  /* local */ double J5;
  /* local */ double J6;
  /* local */ double J7;
  /* local */ double J8;
  /* local */ double J9;
  /* local */ double J10;
  /* local */ double J11;
  /* local */ double J12;
  /* local */ double J13;
  /* local */ double J14;
  /* local */ double J15;
  /* local */ double J16;
  /* local */ double J17;
  /* local */ double J18;

  CalcInputs (pdTime); /* Get new input vals */


  J0 = J0_Vmax_1 * ( GLCo - rgModelVars[ID_GLCi] ) / J0_Kglc_1 / ( 1 + ( GLCo + rgModelVars[ID_GLCi] ) / J0_Kglc_1 + J0_Ki_1 * GLCo * rgModelVars[ID_GLCi] / pow ( J0_Kglc_1 , 2 ) ) ;

  J1 = J1_Vmax_3 * ( rgModelVars[ID_G6P] / J1_Kg6p_3 - rgModelVars[ID_F6P] / ( J1_Kg6p_3 * J1_Keq_3 ) ) / ( 1 + rgModelVars[ID_G6P] / J1_Kg6p_3 + rgModelVars[ID_F6P] / J1_Kf6p_3 ) ;

  J2 = J2_Vmax_4 * ( J2_gR_4 * ( rgModelVars[ID_F6P] / J2_Kf6p_4 ) * ( rgModelVars[ID_ATP] / J2_Katp_4 ) * ( 1 + rgModelVars[ID_F6P] / J2_Kf6p_4 + rgModelVars[ID_ATP] / J2_Katp_4 + J2_gR_4 * rgModelVars[ID_F6P] / J2_Kf6p_4 * rgModelVars[ID_ATP] / J2_Katp_4 ) / ( pow ( 1 + rgModelVars[ID_F6P] / J2_Kf6p_4 + rgModelVars[ID_ATP] / J2_Katp_4 + J2_gR_4 * rgModelVars[ID_F6P] / J2_Kf6p_4 * rgModelVars[ID_ATP] / J2_Katp_4 , 2 ) + J2_L0_4 * pow ( ( 1 + J2_Ciatp_4 * rgModelVars[ID_ATP] / J2_Kiatp_4 ) / ( 1 + rgModelVars[ID_ATP] / J2_Kiatp_4 ) , 2 ) * pow ( ( 1 + J2_Camp_4 * rgModelVars[ID_AMP] / J2_Kamp_4 ) / ( 1 + rgModelVars[ID_AMP] / J2_Kamp_4 ) , 2 ) * pow ( ( 1 + J2_Cf26_4 * J2_F26bP / J2_Kf26_4 + J2_Cf16_4 * rgModelVars[ID_F16bP] / J2_Kf16_4 ) / ( 1 + J2_F26bP / J2_Kf26_4 + rgModelVars[ID_F16bP] / J2_Kf16_4 ) , 2 ) * pow ( 1 + J2_Catp_4 * rgModelVars[ID_ATP] / J2_Katp_4 , 2 ) ) ) ;

  J3 = J3_Vmax_5 * ( rgModelVars[ID_F16bP] / J3_Kf16bp_5 - rgModelVars[ID_DHAP] * rgModelVars[ID_GAP] / ( J3_Kf16bp_5 * J3_Keq_5 ) ) / ( 1 + rgModelVars[ID_F16bP] / J3_Kf16bp_5 + rgModelVars[ID_DHAP] / J3_Kdhap_5 + rgModelVars[ID_GAP] / J3_Kgap_5 + rgModelVars[ID_F16bP] * rgModelVars[ID_GAP] / ( J3_Kf16bp_5 * J3_Kigap_5 ) + rgModelVars[ID_DHAP] * rgModelVars[ID_GAP] / ( J3_Kdhap_5 * J3_Kgap_5 ) ) ;

  J4 = J4_k1_6 * rgModelVars[ID_DHAP] - J4_k2_6 * rgModelVars[ID_GAP] ;

  J5 = J5_C_7 * ( J5_Vmaxf_7 * rgModelVars[ID_GAP] * rgModelVars[ID_NAD] / ( J5_Kgap_7 * J5_Knad_7 ) - J5_Vmaxr_7 * rgModelVars[ID_BPG] * rgModelVars[ID_NADH] / ( J5_Kbpg_7 * J5_Knadh_7 ) ) / ( ( 1 + rgModelVars[ID_GAP] / J5_Kgap_7 + rgModelVars[ID_BPG] / J5_Kbpg_7 ) * ( 1 + rgModelVars[ID_NAD] / J5_Knad_7 + rgModelVars[ID_NADH] / J5_Knadh_7 ) ) ;

  J6 = J6_Vmax_9 * ( rgModelVars[ID_P3G] / J6_Kp3g_9 - rgModelVars[ID_P2G] / ( J6_Kp3g_9 * J6_Keq_9 ) ) / ( 1 + rgModelVars[ID_P3G] / J6_Kp3g_9 + rgModelVars[ID_P2G] / J6_Kp2g_9 ) ;

  J7 = J7_Vmax_10 * ( rgModelVars[ID_P2G] / J7_Kp2g_10 - rgModelVars[ID_PEP] / ( J7_Kp2g_10 * J7_Keq_10 ) ) / ( 1 + rgModelVars[ID_P2G] / J7_Kp2g_10 + rgModelVars[ID_PEP] / J7_Kpep_10 ) ;

  J8 = J8_Vmax_12 * pow ( rgModelVars[ID_PYR] / J8_Kpyr_12 , J8_nH_12 ) / ( 1 + pow ( rgModelVars[ID_PYR] / J8_Kpyr_12 , J8_nH_12 ) ) ;

  J9 = J9_Vmax_13 * ( EtOH * rgModelVars[ID_NAD] / ( J9_Ketoh_13 * J9_Kinad_13 ) - rgModelVars[ID_AcAld] * rgModelVars[ID_NADH] / ( J9_Ketoh_13 * J9_Kinad_13 * J9_Keq_13 ) ) / ( 1 + rgModelVars[ID_NAD] / J9_Kinad_13 + EtOH * J9_Knad_13 / ( J9_Kinad_13 * J9_Ketoh_13 ) + rgModelVars[ID_AcAld] * J9_Knadh_13 / ( J9_Kinadh_13 * J9_Kacald_13 ) + rgModelVars[ID_NADH] / J9_Kinadh_13 + EtOH * rgModelVars[ID_NAD] / ( J9_Kinad_13 * J9_Ketoh_13 ) + rgModelVars[ID_NAD] * rgModelVars[ID_AcAld] * J9_Knadh_13 / ( J9_Kinad_13 * J9_Kinadh_13 * J9_Kacald_13 ) + EtOH * rgModelVars[ID_NADH] * J9_Knad_13 / ( J9_Kinad_13 * J9_Kinadh_13 * J9_Ketoh_13 ) + rgModelVars[ID_AcAld] * rgModelVars[ID_NADH] / ( J9_Kacald_13 * J9_Kinadh_13 ) + EtOH * rgModelVars[ID_NAD] * rgModelVars[ID_AcAld] / ( J9_Kinad_13 * J9_Kiacald_13 * J9_Ketoh_13 ) + EtOH * rgModelVars[ID_AcAld] * rgModelVars[ID_NADH] / ( J9_Kietoh_13 * J9_Kinadh_13 * J9_Kacald_13 ) ) ;

  J10 = J10_Katpase_14 * rgModelVars[ID_ATP] ;

  J11 = J11_k1_15 * rgModelVars[ID_ADP] * rgModelVars[ID_ADP] - J11_k2_15 * rgModelVars[ID_ATP] * rgModelVars[ID_AMP] ;

  J12 = J12_Vmax_16 * ( rgModelVars[ID_DHAP] / J12_Kdhap_16 * ( rgModelVars[ID_NADH] / J12_Knadh_16 ) - Glycerol / J12_Kdhap_16 * ( rgModelVars[ID_NAD] / J12_Knadh_16 ) * ( 1 / J12_Keq_16 ) ) / ( ( 1 + rgModelVars[ID_DHAP] / J12_Kdhap_16 + Glycerol / J12_Kglycerol_16 ) * ( 1 + rgModelVars[ID_NADH] / J12_Knadh_16 + rgModelVars[ID_NAD] / J12_Knad_16 ) ) ;

  J13 = J13_k_19 * rgModelVars[ID_AcAld] ;

  J14 = J14_Vmax_8 * ( ( J14_Keq_8 * rgModelVars[ID_BPG] * rgModelVars[ID_ADP] - rgModelVars[ID_P3G] * rgModelVars[ID_ATP] ) / ( J14_Kp3g_8 * J14_Katp_8 ) ) / ( ( 1 + rgModelVars[ID_BPG] / J14_Kbpg_8 + rgModelVars[ID_P3G] / J14_Kp3g_8 ) * ( 1 + rgModelVars[ID_ADP] / J14_Kadp_8 + rgModelVars[ID_ATP] / J14_Katp_8 ) ) ;

  J15 = J15_Ktrehalose_18 ;

  J16 = J16_Vmax_2 * ( rgModelVars[ID_GLCi] * rgModelVars[ID_ATP] / ( J16_Kglc_2 * J16_Katp_2 ) - rgModelVars[ID_G6P] * rgModelVars[ID_ADP] / ( J16_Kglc_2 * J16_Katp_2 * J16_Keq_2 ) ) / ( ( 1 + rgModelVars[ID_GLCi] / J16_Kglc_2 + rgModelVars[ID_G6P] / J16_Kg6p_2 ) * ( 1 + rgModelVars[ID_ATP] / J16_Katp_2 + rgModelVars[ID_ADP] / J16_Kadp_2 ) ) ;

  J17 = J17_Vmax_11 * ( rgModelVars[ID_PEP] * rgModelVars[ID_ADP] / ( J17_Kpep_11 * J17_Kadp_11 ) - rgModelVars[ID_PYR] * rgModelVars[ID_ATP] / ( J17_Kpep_11 * J17_Kadp_11 * J17_Keq_11 ) ) / ( ( 1 + rgModelVars[ID_PEP] / J17_Kpep_11 + rgModelVars[ID_PYR] / J17_Kpyr_11 ) * ( 1 + rgModelVars[ID_ADP] / J17_Kadp_11 + rgModelVars[ID_ATP] / J17_Katp_11 ) ) ;

  J18 = J18_KGLYCOGEN_17 ;

  rgDerivs[ID_GLCi] = + J0 - J16 ;

  rgDerivs[ID_G6P] = - J1 - J15 + J16 - J18 ;

  rgDerivs[ID_F6P] = + J1 - J2 ;

  rgDerivs[ID_ATP] = - J2 - J10 + J11 + J14 - J15 - J16 + J17 - J18 ;

  rgDerivs[ID_ADP] = + J2 + J10 - 2 * J11 - J14 + J15 + J16 - J17 + J18 ;

  rgDerivs[ID_F16bP] = + J2 - J3 ;

  rgDerivs[ID_DHAP] = + J3 - J4 - J12 ;

  rgDerivs[ID_GAP] = + J3 + J4 - J5 ;

  rgDerivs[ID_NAD] = - J5 - J9 + J12 - 3 * J13 ;

  rgDerivs[ID_BPG] = + J5 - J14 ;

  rgDerivs[ID_NADH] = + J5 + J9 - J12 + 3 * J13 ;

  rgDerivs[ID_P3G] = - J6 + J14 ;

  rgDerivs[ID_P2G] = + J6 - J7 ;

  rgDerivs[ID_PEP] = + J7 - J17 ;

  rgDerivs[ID_PYR] = - J8 + J17 ;

  rgDerivs[ID_AcAld] = + J8 + J9 - 2 * J13 ;

  rgDerivs[ID_AMP] = + J11 ;

} /* CalcDeriv */


/*----- Model scaling */

void ScaleModel (PDOUBLE pdTime)
{

} /* ScaleModel */


/*----- Jacobian calculations */

void CalcJacob (PDOUBLE pdTime, double rgModelVars[],
                long column, double rgdJac[])
{

} /* CalcJacob */


/*----- Outputs calculations */

void CalcOutputs (double  rgModelVars[], double  rgDerivs[], PDOUBLE pdTime)
{

}  /* CalcOutputs */


