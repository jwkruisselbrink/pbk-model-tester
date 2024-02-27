initParms <- function(newParms = NULL) {
  parms <- c(
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
    log_aPoor = 0.0,
    log_aRich = 0.0,
    log_aLiver = 0.0,
    log_aSkin = 0.0,
    log_aSkin_sc = 0.0,
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
    PCSkin_sc = 0
  )

  if (!is.null(newParms)) {
    if (!all(names(newParms) %in% c(names(parms)))) {
      stop("illegal parameter name")
    }
    parms[names(newParms)] <- newParms
  }

  parms <- within(as.list(parms), {
    log_aPoor = log (1) - log_PCFat;
    log_aRich = log (1) - log_PCFat;
    log_aLiver = log (1) - log_PCFat;
    log_aSkin = log (1) - log_PCFat;
    log_aSkin_sc = log (1) - log_PCFat;
  })
  out <- .C("getParms",  as.double(parms),
            out=double(length(parms)),
            as.integer(length(parms)))$out
  names(out) <- names(parms)
  out
}

Outputs <- c(
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
    "CSkin_sc_e"
)

initStates <- function(parms, newStates = NULL) {
  Y <- c(
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
    QMetab = 0.0
  )

  Y <- within(c(as.list(parms),as.list(Y)), {
    Y["QSkin_sc_e"] <- DermalDose 
    Y["QGut"] <- Frac * OralDose 

  })$Y

  if (!is.null(newStates)) {
    if (!all(names(newStates) %in% c(names(Y)))) {
      stop("illegal state variable name in newStates")
    }
    Y[names(newStates)] <- newStates
  }

.C("initState", as.double(Y));
Y
}
