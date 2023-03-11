source('PbkUtils.R')

modelName <- "PBPK_generic_model_v6"
modelPath <- modelName
buildModel(modelName, modelPath = modelName)
loadModel(modelName, modelPath = modelName)

paramsFile <- file.path(modelPath, 'Parametrisations', 'EuroMix-KineticModels-CosmosV6 9 substances ParB QSAR-Invitro-v2.xlsx')
instanceParameters <- getParametersFromMcraDataFile(paramsFile, 'CosmosFlutamide')
instances <- getInstancesFromMcraDataFile(paramsFile)

MM <- 223;
BW <- 70;
times <- seq(from=0, to=24*50, by=1)
oralDose <- as.numeric(1/24/MM * 1e3 * BW)
doseTimes <- seq(from=0, to=24*50, by=12)
eventsData <- data.frame(
  var=rep("QGut", length(doseTimes)),
  time=doseTimes,
  value=rep(oralDose, length(doseTimes)), 
  method=rep("add",length(doseTimes))
)
out <- runModel(
  modelName, 
  instanceParameters, 
  times, 
  events = eventsData,
  modelPath = modelPath
)

out2 <- out[,c("time","QArt","QFat","QLiver")]
plot(out[,c("time","QLiver")], type='l')
plot(out[,c("time","QGut")], type='l')


hour <- c(1000)
allDose <- list(
  cbind(hour, 0 * doseTimes), # hour, Ing_rate
  cbind(hour, 0), #hour, Skin_exposure_rate
  cbind(hour, 0), #hour, Cinh
  cbind(hour, 0)
)
runModel(modelName, instanceParameters, times, NULL, forcings = allDose)
out <- runModel(modelName, instanceParameters, times, eventsData)


library(xml2)
xmlFile <- file.path(modelPath, paste(modelName, '.xml', sep=""))
data <- read_xml(xmlFile)
data.frame(
  id = xml_text(xml_find_all(data, "//Forcings//Forcing//Id")),
  name = xml_text(xml_find_all(data, "//Forcings//Forcing//Name")),
  description = xml_text(xml_find_all(data, "//Forcings//Forcing//Description"))
)



