buildModel <- function(modelName, modelPath = ".") {
  fileNameMCSimModel <- paste(file.path(modelPath, modelName), '.model', sep='')
  fileNameCModel <- paste(file.path(modelPath, modelName), '.c', sep='')
  system(paste('mod.exe -R "' , fileNameMCSimModel, '" "', fileNameCModel, '"', sep=''))
  system(paste('R CMD SHLIB "', file.path(modelPath, modelName), '".c', sep=''))
}

loadModel <- function(modelName, modelPath = "./") {
  dllFileName <- paste(file.path(modelPath, modelName), .Platform$dynlib.ext, sep="")
  if (is.loaded(dllFileName)) {
    dyn.unload(dllFileName)
  }
  dyn.load(dllFileName)
}

runModel <- function(
    modelName,
    modelInstanceParms,
    times,
    events = NULL,
    forcings = NULL,
    modelPath = "."
) {
  require('deSolve')
  
  source(paste(file.path(modelPath, modelName), '_inits.R', sep=''))
  
  # create parameters
  parms <- initParms(newParms = setNames(as.numeric(modelInstanceParms$Value), modelInstanceParms$Parameter))
  
  # read default initial state values
  Y <- initStates(parms)
  
  # run solver
  out <- ode(y=Y, times=times, func = "derivs", parms = parms, 
             dllname = modelName,
             initfunc = "initmod",
             initforc = "initforc",
             jacfunc = "jac",
             forcings = forcings,
             nout = length(Outputs),
             events = list(data = events),
             outnames = Outputs)
}

getInstancesFromMcraDataFile <- function(fileName) {
  require('xlsx')
  instances <- read.xlsx(
    fileName, 
    sheetName = "KineticModelInstances", 
    header=TRUE)
}

getParametersFromMcraDataFile <- function(fileName, idModelInstance) {
  require('xlsx')
  instanceParameters <- read.xlsx(
    fileName, 
    sheetName = "KineticModelInstanceParameters", 
    header=TRUE, 
    keepFormulas=FALSE)
  instanceParameters[which((instanceParameters$idModelInstance == idModelInstance)), ]
}

getModelInputs <- function(
  modelName,
  modelPath = "."
) {
  library(xml2)
  xmlFile <- file.path(modelPath, paste(modelName, '.xml', sep=""))
  data <- read_xml(xmlFile)
  data.frame(
    Id = xml_text(xml_find_all(data, "//Forcings//Forcing//Id")),
    Description = xml_text(xml_find_all(data, "//Forcings//Forcing//Description")),
    Unit = xml_text(xml_find_all(data, "//Forcings//Forcing//Unit"))
  )
}

getModelParameters <- function(
    modelName,
    modelPath = "."
) {
  library(xml2)
  xmlFile <- file.path(modelPath, paste(modelName, '.xml', sep=""))
  data <- read_xml(xmlFile)
  data.frame(
    Id = xml_text(xml_find_all(data, "//Parameters//Parameter//Id")),
    Description = xml_text(xml_find_all(data, "//Parameters//Parameter//Description")),
    Unit = xml_text(xml_find_all(data, "//Parameters//Parameter//Unit"))
  )
}

getModelOutputs <- function(
    modelName,
    modelPath = "."
) {
  library(xml2)
  xmlFile <- file.path(modelPath, paste(modelName, '.xml', sep=""))
  data <- read_xml(xmlFile)
  data.frame(
    Id = xml_text(xml_find_all(data, "//Outputs//Output//Id")),
    Description = xml_text(xml_find_all(data, "//Outputs//Output//Description")),
    #BiologicalMatrix = xml_text(xml_find_all(data, "//Outputs//Output//BiologicalMatrix")),
    Unit = xml_text(xml_find_all(data, "//Outputs//Output//Unit"))
  )
}

