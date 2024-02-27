library(shiny)

# Define UI for app that draws a histogram ----
ui <- fluidPage(
  
  # App title
  titlePanel("PBK model tester"),
  
  div(
    style = "display:flex; align-items:flex-start",

    # Sidebar panel
    wellPanel(
      style = "width: 300px; flex: 0 0 auto; margin: 0 10px;",
      width = "3",

      # Input: model
      selectInput(
        "modelSelect",
        "Model:",
        choices = c("PBPK_generic_model_v6")
      ),

      # Input: param data file
      fileInput(
        "paramFile",
        "Data file",
        accept = ".csv"),

      # Input: model instance select
      uiOutput("modelInstanceSelect"),

      # Input: dosing pattern
      selectInput(
        "dosingPattern",
        "Dosing pattern:",
        c(
          "Single dose" = "sinlge",
          "Repeated daily dose" = "daily"
        )
      ),
      
      # Input: dose
      numericInput(
        "dose", 
        "Dose",
        step = .1,
        value = 1),

      # Input: number of days
      numericInput(
        "numDays", 
        "Days",
         value = 25),

      uiOutput("outputMultiSelect"),
    ),

    # Main panel
    div( # main panel
      style = "margin: 0 10px; flex-grow: 1; resize:horizontal; overflow: hidden",
      tabsetPanel(
        type = "tabs",
        tabPanel("Model info",
           tabsetPanel(
             tabPanel("Inputs", tableOutput("modelInputs")),
             tabPanel("Parameters", tableOutput("modelParameters")),
             tabPanel("Outputs", tableOutput("modelOutputs"))
           )
        ),
        tabPanel("Parameters", tableOutput("modelInstanceParams")),
        tabPanel("Plots",                         
          fluidRow(
            column(
              width = 12,
              uiOutput("modelInstanceOutputPlots")
            )
          )
        ),
        tabPanel("Table", tableOutput("modelInstanceOutputs"))
      )
    )
  )
)
