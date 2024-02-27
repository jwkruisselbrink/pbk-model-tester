initParms <- function(newParms = NULL) {
  parms <- c(
    J0_Vmax_1 = 97.24,
    J0_Kglc_1 = 1.1918,
    J0_Ki_1 = 0.91,
    J1_Vmax_3 = 1056,
    J1_Kg6p_3 = 1.4,
    J1_Keq_3 = 0.29,
    J1_Kf6p_3 = 0.3,
    J2_Vmax_4 = 110,
    J2_gR_4 = 5.12,
    J2_Kf6p_4 = 0.1,
    J2_Katp_4 = 0.71,
    J2_L0_4 = 0.66,
    J2_Ciatp_4 = 100,
    J2_Kiatp_4 = 0.65,
    J2_Camp_4 = 0.0845,
    J2_Kamp_4 = 0.0995,
    J2_Cf26_4 = 0.0174,
    J2_Kf26_4 = 0.000682,
    J2_Cf16_4 = 0.397,
    J2_Kf16_4 = 0.111,
    J2_Catp_4 = 3,
    J2_F26bP = 0.02,
    J3_Vmax_5 = 94.69,
    J3_Kf16bp_5 = 0.3,
    J3_Keq_5 = 0.069,
    J3_Kdhap_5 = 2,
    J3_Kgap_5 = 2.4,
    J3_Kigap_5 = 10,
    J4_k1_6 = 450000,
    J4_k2_6 = 10000000,
    J5_C_7 = 1,
    J5_Vmaxf_7 = 1152,
    J5_Kgap_7 = 0.21,
    J5_Knad_7 = 0.09,
    J5_Vmaxr_7 = 6719,
    J5_Kbpg_7 = 0.0098,
    J5_Knadh_7 = 0.06,
    J6_Vmax_9 = 2585,
    J6_Kp3g_9 = 1.2,
    J6_Keq_9 = 0.19,
    J6_Kp2g_9 = 0.08,
    J7_Vmax_10 = 201.6,
    J7_Kp2g_10 = 0.04,
    J7_Keq_10 = 6.7,
    J7_Kpep_10 = 0.5,
    J8_Vmax_12 = 857.8,
    J8_Kpyr_12 = 4.33,
    J8_nH_12 = 1.9,
    J9_Vmax_13 = 209.5,
    J9_Ketoh_13 = 17,
    J9_Kinad_13 = 0.92,
    J9_Keq_13 = 6.9E-5,
    J9_Knad_13 = 0.17,
    J9_Knadh_13 = 0.11,
    J9_Kinadh_13 = 0.031,
    J9_Kacald_13 = 1.11,
    J9_Kiacald_13 = 1.1,
    J9_Kietoh_13 = 90,
    J10_Katpase_14 = 39.5,
    J11_k1_15 = 45,
    J11_k2_15 = 100,
    J12_Vmax_16 = 47.11,
    J12_Kdhap_16 = 0.4,
    J12_Knadh_16 = 0.023,
    J12_Keq_16 = 4300,
    J12_Kglycerol_16 = 1,
    J12_Knad_16 = 0.93,
    J13_k_19 = 21.4,
    J14_Vmax_8 = 1288,
    J14_Keq_8 = 3200,
    J14_Kp3g_8 = 0.53,
    J14_Katp_8 = 0.3,
    J14_Kbpg_8 = 0.003,
    J14_Kadp_8 = 0.2,
    J15_Ktrehalose_18 = 2.4,
    J16_Vmax_2 = 236.7,
    J16_Kglc_2 = 0.08,
    J16_Katp_2 = 0.15,
    J16_Keq_2 = 2000,
    J16_Kg6p_2 = 30,
    J16_Kadp_2 = 0.23,
    J17_Vmax_11 = 1000,
    J17_Kpep_11 = 0.14,
    J17_Kadp_11 = 0.53,
    J17_Keq_11 = 6100,
    J17_Kpyr_11 = 21,
    J17_Katp_11 = 1.5,
    J18_KGLYCOGEN_17 = 6,
    GLCo = 2,
    CO2 = 2,
    EtOH = 2,
    Glycerol = 2,
    Glycogen = 2,
    Trehalose = 2,
    Succinate = 2
  )

  if (!is.null(newParms)) {
    if (!all(names(newParms) %in% c(names(parms)))) {
      stop("illegal parameter name")
    }
    parms[names(newParms)] <- newParms
  }

  parms <- within(as.list(parms), {
  })
  out <- .C("getParms",  as.double(parms),
            out=double(length(parms)),
            as.integer(length(parms)))$out
  names(out) <- names(parms)
  out
}

Outputs <- c(

)

initStates <- function(parms, newStates = NULL) {
  Y <- c(
    GLCi = 0.097652231064563,
    ATP = 2.52512746499271,
    G6P = 2.52512746499271,
    ADP = 2.52512746499271,
    F6P = 2.52512746499271,
    F16bP = 2.52512746499271,
    AMP = 2.52512746499271,
    DHAP = 2.52512746499271,
    GAP = 2.52512746499271,
    NAD = 1.50329030201531,
    BPG = 1.50329030201531,
    NADH = 1.50329030201531,
    P3G = 0.885688538360659,
    P2G = 0.127695817386632,
    PEP = 0.0632352144936527,
    PYR = 1.81531251192736,
    AcAld = 0.178140579850657
  )

  if (!is.null(newStates)) {
    if (!all(names(newStates) %in% c(names(Y)))) {
      stop("illegal state variable name in newStates")
    }
    Y[names(newStates)] <- newStates
  }

.C("initState", as.double(Y));
Y
}
