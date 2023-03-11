library('deSolve') 
source('PbkUtils.R')

server <- function(input, output) {
  selectedVals <- reactiveValues(outputs = NULL)

  observe({
    req(input$selectedOutputs)
    selectedVals$outputs <- input$selectedOutputs
  })

  getModel <- reactive({
    req(input$modelSelect)
    modelName <- input$modelSelect
    modelPath <- input$modelSelect
    buildModel(modelName, modelPath = modelName)
    loadModel(modelName, modelPath = modelName)
    list(
      modelName = modelName,
      modelPath = modelPath
    )
  })
  
  getInstances <- reactive({
    req(input$modelSelect)
    req(input$paramFile)
    file <- input$paramFile
    paramsFile <- file$datapath
    getInstancesFromMcraDataFile(paramsFile)
  })
  
  getInstanceParams <- reactive({
    req(input$paramFile)
    req(input$selectedModelInstance)
    file <- input$paramFile
    paramsFile <- file$datapath
    getParametersFromMcraDataFile(paramsFile, input$selectedModelInstance)
  })

  getModelDefinitionOutputs <- reactive({
    req(input$modelSelect)
    req(input$selectedModelInstance)
    modelOutputs <- getModelOutputs(input$modelSelect, input$modelSelect)
    selectedVals$outputs <- modelOutputs$Id
    modelOutputs
  })
  
  getOutput <- reactive({
    req(input$paramFile)
    req(input$selectedModelInstance)
    model <- getModel()
    numDays <- input$numDays
    bodyweight <- input$bodyweight;
    MM <- 223;
    times <- seq(from=0, to=24*numDays, by=1)
    oralDose <- as.numeric(1/24/MM * 1e3 * bodyweight)
    doseTimes <- seq(from=0, to=24*50, by=24)
    eventsData <- data.frame(
      var=rep("QGut", length(doseTimes)),
      time=doseTimes,
      value=rep(oralDose, length(doseTimes)), 
      method=rep("add",length(doseTimes))
    )
    out <- runModel(
      model$modelName, 
      getInstanceParams(), 
      times, 
      events = eventsData,
      modelPath = model$modelPath
    )
  })

  output$modelInstanceSelect <- renderUI({
    req(input$modelSelect)
    req(input$paramFile)
    file <- input$paramFile
    paramsFile <- file$datapath
    instances <- getInstancesFromMcraDataFile(paramsFile)
    selectInput(
      "selectedModelInstance", 
      label = "Select instance",
      choices = instances$idModelInstance
    )
  })

  output$outputMultiSelect <- renderUI({
    req(input$modelSelect)
    modelOutputs <- getModelDefinitionOutputs()
    out <- getOutput()
    selectInput(
      "selectedOutputs", 
      label = "Select outputs",
      choices = modelOutputs$Id,
      multiple = TRUE,
      selected = selectedVals$outputs
    )
  })

  output$modelInputs <- renderTable({
    req(input$modelSelect)
    req(input$selectedModelInstance)
    getModelInputs(input$modelSelect, input$modelSelect)
  })

  output$modelParameters <- renderTable({
    req(input$modelSelect)
    req(input$selectedModelInstance)
    getModelParameters(input$modelSelect, input$modelSelect)
  })
  
  output$modelOutputs <- renderTable({
    getModelDefinitionOutputs()
  })

  output$modelInstanceParams <- renderTable({
    req(input$modelSelect)
    req(input$paramFile)
    instanceParameters <- getInstanceParams()
    instanceParameters[,c("Parameter", "Value", "DistributionType", "CvVariability", "CvUncertainty")]
  })

  output$modelInstanceOutputs <- renderTable({
    req(input$modelSelect)
    req(input$paramFile)
    out <- getOutput()
  })

  output$modelInstanceOutputPlots <- renderUI({
    req(input$modelSelect)
    req(input$paramFile)
    req(input$selectedOutputs)
    out <- getOutput()
    plotOutputList <- lapply(1:length(selectedVals$outputs), function(i) {
      column(width = 6, {
        plotname <- paste("plot_", selectedVals$outputs[i], sep="")
        plotOutput(plotname, width = "100%")
      })
    })
    do.call(tagList, plotOutputList)
  })
  
  observe({
    req(input$modelSelect)
    req(input$paramFile)
    req(input$selectedOutputs)
    out <- getOutput()
    for (selectedOutput in selectedVals$outputs) {
      local({
        sel <- selectedOutput
        plotname <- paste("plot_", selectedOutput, sep="")
        output[[plotname]] <- renderPlot({
          plot(out[,c("time", sel)], type='l')
        })
      })
    }
  })
}
