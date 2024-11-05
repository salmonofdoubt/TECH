######  ######

# ------------------------------------------------
# Set up and Load Packages
# ------------------------------------------------

# Set CRAN repository to ensure reliable package installations
options(repos = c(CRAN = "https://cloud.r-project.org/"))

# List of packages required for analysis ordered alphabetically
packages <- c("corrplot", "dplyr", "ggplot2", "moments", "nortest", 
              "report", "reshape2", "tidyverse")

# Loop to install packages if they’re not already installed
for (pkg in packages) {
  if (!require(pkg, character.only = TRUE)) install.packages(pkg)  # Install if missing
  library(pkg, character.only = TRUE)  # Load package
}

# Clear the environment to avoid conflicts with old variables
rm(list = ls())

# ------------------------------------------------
# Load the Data
# ------------------------------------------------

# Load data from CSV file and check the structure
data <- read.csv("/Users/diandre/OneDrive - Trinity College Dublin/PhD/MODULES/ST8000/ST8002 R PROJECT/AndreBaumann_13314656_D1.csv")

# View the structure of the data to confirm column names and data types
str(data)


########################### 
### Report_1_Evaluation ###
########################### 

# ------------------------------------------------
# Topic: (E6) Summary Statistics for Shape__Area and Shape__Length
# ------------------------------------------------

# Display summary statistics (like mean, median) for Shape__Area and Shape__Length
summary(data$Shape__Area)
summary(data$Shape__Length)

# Calculate skewness and kurtosis for Shape__Area and Shape__Length to assess normality
skewness(data$Shape__Area)
kurtosis(data$Shape__Area)
skewness(data$Shape__Length)
kurtosis(data$Shape__Length)

# Plot histogram and density curve for Shape__Area to visualize its distribution
ggplot(data, aes(x = Shape__Area)) +
  geom_histogram(aes(y = ..density..), bins = 20, fill = "skyblue", color = "black") +
  geom_density(color = "blue", size = 1) +
  labs(title = "Distribution of Shape__Area", x = "Shape__Area", y = "Density") +
  theme_minimal()

# Plot histogram and density curve for Shape__Length to visualize its distribution
ggplot(data, aes(x = Shape__Length)) +
  geom_histogram(aes(y = ..density..), bins = 20, fill = "lightgreen", color = "black") +
  geom_density(color = "darkgreen", size = 1) +
  labs(title = "Distribution of Shape__Length", x = "Shape__Length", y = "Density") +
  theme_minimal()

# ------------------------------------------------
# Topic: (E7) Outlier Detection for Shape__Area and Shape__Length
# ------------------------------------------------

# Calculate z-scores for Shape__Area and identify outliers (z-score > 3)
z_scores_area <- (data$Shape__Area - mean(data$Shape__Area, na.rm = TRUE)) / sd(data$Shape__Area, na.rm = TRUE)
outliers_area <- data$Shape__Area[abs(z_scores_area) > 3]  # Values with high z-scores
outliers_area

# Calculate z-scores for Shape__Length and identify outliers (z-score > 3)
z_scores_length <- (data$Shape__Length - mean(data$Shape__Length, na.rm = TRUE)) / sd(data$Shape__Length, na.rm = TRUE)
outliers_length <- data$Shape__Length[abs(z_scores_length) > 3]  # Values with high z-scores
outliers_length

# ------------------------------------------------
# Topic: (E9) Correlation Matrix Visualization
# ------------------------------------------------

# Select numeric columns and calculate the correlation matrix
numeric_data <- data[, c("Shape__Area", "Shape__Length")]
cor_matrix <- cor(numeric_data, use = "complete.obs")  # Calculate correlation
corrplot(cor_matrix, method = "circle", title = "")
title(main = "Correlation Matrix of Spatial Variables", cex.main = 1.5, line = 3)

# ------------------------------------------------
# Topic: (E12) Scatter Plot of Shape__Area and Shape__Length
# ------------------------------------------------

# Scatter plot to visualize relationship between Shape__Area and Shape__Length
plot(data$Shape__Area, data$Shape__Length, 
     main = "Scatter Plot of Shape__Area vs Shape__Length", 
     xlab = "Shape Area", ylab = "Shape Length")

# ------------------------------------------------
# Topic: (E22) Heatmap of Correlation Matrix
# ------------------------------------------------

# Melt the correlation matrix to a format suitable for heatmap
cor_data <- melt(cor_matrix)

# Create a heatmap to visualize correlations between Shape__Area and Shape__Length
ggplot(cor_data, aes(Var1, Var2, fill = value)) +
  geom_tile(color = "white") +
  scale_fill_gradient2(low = "red", high = "blue", mid = "white", 
                       midpoint = 0, limit = c(-1, 1), space = "Lab",
                       name = "Correlation\nCoefficient") +
  theme_minimal() +
  labs(title = "Heatmap of Correlation Matrix for Spatial Variables",
       x = "", y = "") +
  theme(axis.text.x = element_text(angle = 45, vjust = 1, hjust = 1))

# ------------------------------------------------
# Topic: (E15) Bar Chart of Environmental Status
# ------------------------------------------------

# Bar chart to show count of each Status category
ggplot(data, aes(x = reorder(Status, Status, function(x) -length(x)), fill = Status)) +
  geom_bar() +
  labs(title = "Environmental Status (all regions)",
       x = "Status",
       y = "Count") +
  theme_minimal() +
  scale_fill_brewer(palette = "Set2") +
  theme(axis.text.x = element_text(angle = 45, hjust = 1))


########################### 
### Report_1_Statistics ###
########################### 

# ------------------------------------------------
# Topic: (S2) Regression Analysis and Coefficient of Determination
# ------------------------------------------------

# Convert Status to numeric for regression analysis
data$Status_numeric <- as.numeric(as.factor(data$Status))

# Fit linear model to explore relationship between Shape__Area and Status
lm_model <- lm(Status_numeric ~ Shape__Area, data = data, na.action = na.exclude)
summary(lm_model)

# Scatter plot with regression line to show the relationship visually
plot(data$Shape__Area, data$Status_numeric,
     main = "Regression of Status_numeric on Shape__Area",
     xlab = "Shape Area", ylab = "Status (Numeric)")
abline(lm_model, col = "blue", lwd = 2)

# Report regression model summary
report(lm_model)

# ------------------------------------------------
# Topic: (S20) ANOVA Analysis on Shape__Length by Status
# ------------------------------------------------

# Run ANOVA to test if mean Shape__Length differs across Status categories
anova_model <- aov(Shape__Length ~ Status, data = data, na.action = na.exclude)
summary(anova_model)

# Report ANOVA results
report(anova_model)

# ------------------------------------------------
# Topic: (S7) Chi-Square Test for Independence
# ------------------------------------------------

# Convert Policy01_Name to factor for chi-square test
data$Policy01_Name <- as.factor(data$Policy01_Name)

# Create contingency table and run chi-square test
contingency_table <- table(data$Status, data$Policy01_Name)
chi_test_independence <- chisq.test(contingency_table)
summary(chi_test_independence)

# Report chi-square test results
report(chi_test_independence)

# ------------------------------------------------
# Topic: (S9) Shapiro-Wilk Test for Normality
# ------------------------------------------------

# Run Shapiro-Wilk test to check normality of Shape__Area
shapiro_test_area <- shapiro.test(data$Shape__Area)
print("Shapiro-Wilk Test for Shape__Area")
print(shapiro_test_area)

# Run Shapiro-Wilk test to check normality of Shape__Length
shapiro_test_length <- shapiro.test(data$Shape__Length)
print("Shapiro-Wilk Test for Shape__Length")
print(shapiro_test_length)

# ------------------------------------------------
# Topic: (S8) Anderson–Darling Test for Normality
# ------------------------------------------------

# Run Anderson-Darling test for Shape__Area to check for normality
ad_test_result <- ad.test(data$Shape__Area)
print(ad_test_result)

# ------------------------------------------------
# Topic: (S27) F-Test for Equality of Variances
# ------------------------------------------------

# Filter data for two levels in Status to use in F-test
data_filtered <- subset(data, Status %in% c("Unpolluted", "Intermediate"))

# Perform F-test to compare variances of Shape__Area between two Status levels
f_test_result <- var.test(Shape__Area ~ Status, data = data_filtered)
print(f_test_result)

# End of Report 1
