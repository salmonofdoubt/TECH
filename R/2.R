###### ######

# ------------------------------------------------
# Set up and Load Packages
# ------------------------------------------------

# Set CRAN repository for reliable package installations
options(repos = c(CRAN = "https://cloud.r-project.org/"))

# List of required packages, in alphabetical order
packages <- c("corrplot", "dplyr", "dunn.test", "ggplot2", "gplots", "moments",
              "pwr", "report", "reshape2", "tidyverse")

# Install and load each package
for (pkg in packages) {
  if (!require(pkg, character.only = TRUE)) install.packages(pkg)
  library(pkg, character.only = TRUE)
}

# Clear the environment to avoid conflicts with old variables
rm(list = ls())

# ------------------------------------------------
# Load the Data
# ------------------------------------------------

# Load data from the specified CSV file
data <- read.csv("/Users/diandre/OneDrive - Trinity College Dublin/PhD/MODULES/ST8000/ST8002 R PROJECT/AndreBaumann_13314656_D2.csv")

# Preview dataset structure to confirm data types and column names
str(data)

########################### 
### Report_2_Evaluation ###
########################### 

# ------------------------------------------------
# Topic: (E1) Contingency Table
# ------------------------------------------------

# Create a contingency table of Region by Sub.Region
contingency_table <- table(data$Region, data$Sub.Region)
print(contingency_table)


# ------------------------------------------------
# Topic: (E2) Pearson and Spearman Correlation
# ------------------------------------------------

# Select only numeric columns for correlation analysis
numeric_data <- data[sapply(data, is.numeric)]

# Calculate Pearson correlation matrix
pearson_correlation_matrix <- cor(numeric_data, method = "pearson", use = "complete.obs")
head(pearson_correlation_matrix, 3)  # Display first few rows of Pearson matrix

# Calculate Spearman correlation matrix
spearman_correlation_matrix <- cor(numeric_data, method = "spearman", use = "complete.obs")
head(spearman_correlation_matrix, 3)  # Display first few rows of Spearman matrix


# ------------------------------------------------
# Topic: (E3) Kendall Correlation Matrix
# ------------------------------------------------

# Calculate Kendall correlation matrix
kendall_correlation_matrix <- cor(numeric_data, method = "kendall", use = "complete.obs")

# Print overview of Kendall correlation matrix
head(kendall_correlation_matrix, 3)
summary(kendall_correlation_matrix)
report(kendall_correlation_matrix)


# ------------------------------------------------
# Topic: (E16) Box Plot
# ------------------------------------------------

# Box plot for a single variable
boxplot(data$X50._present, main = "Box Plot of X50._present", ylab = "X50._present")

# Box plot of X50._present by Region
boxplot(X50._present ~ Region, data = data, main = "Box Plot of X50._present by Region",
        xlab = "Region", ylab = "X50._present")

# Box plot for multiple variables
boxplot(data$X50._present, data$X20._present, data$X10._present,
        names = c("X50._present", "X20._present", "X10._present"),
        main = "Box Plot of Multiple Variables",
        ylab = "Values")


# ------------------------------------------------
# Topic: (E16) Balloon Plot
# ------------------------------------------------

# Create a balloon plot for Region vs Sub.Region using contingency_table
balloonplot(contingency_table, 
            main = "Balloon Plot of Region by Sub.Region",
            xlab = "Sub.Region", 
            ylab = "Region",
            label = TRUE,       # Show values inside balloons
            show.margins = TRUE) # Show row and column totals


# ------------------------------------------------
# Topic: (E17) Violin Plot
# ------------------------------------------------

# Violin plot to show distribution of X50._present by Region
ggplot(data, aes(x = Region, y = X50._present, fill = Region)) +
  geom_violin(trim = FALSE, color = "black", alpha = 0.7) +
  labs(x = "Region", 
       y = "X50._present (Concentration Level)",
       title = "Violin Plot of X50._present by Region") +
  scale_fill_brewer(palette = "Pastel1") +  
  theme_minimal() +
  theme(legend.position = "none")  # Remove legend

########################### 
### Report_2_Statistics ###
########################### 

# ------------------------------------------------
# Topic: (S6) Tukey Test
# ------------------------------------------------

# Perform ANOVA to compare X50._present across regions
anova_result <- aov(X50._present ~ Region, data = data)
summary(anova_result)
report(anova_result)

# Perform Tukey's HSD test for multiple comparisons
tukey_result <- TukeyHSD(anova_result)
print(tukey_result)


# ------------------------------------------------
# Topic: (S17) Kruskal-Wallis Test
# ------------------------------------------------

# Perform Kruskal-Wallis test to assess differences across regions
kruskal_result <- kruskal.test(X20._present ~ Region, data = data)
print(kruskal_result)  # Show Kruskal-Wallis result
summary(kruskal_result)

# Post-hoc Dunn's test for multiple comparisons
library(dunn.test)
dunn_test_result <- dunn.test(data$X20._present, data$Region, method = "bonferroni")
print(dunn_test_result)


# ------------------------------------------------
# Topic: (S1) Sample Size Determination and Power of Test
# ------------------------------------------------

library(pwr)  # Load pwr package for power analysis

# Set parameters for power analysis
effect_size <- 0.5          # Medium effect size
significance_level <- 0.05  # Alpha level
power <- 0.80               # Desired power level

# Calculate required sample size per group
sample_size <- pwr.t.test(d = effect_size, sig.level = significance_level, 
                          power = power, type = "two.sample")$n
print(sample_size)

# Calculate achieved power for the sample size
power_result <- pwr.t.test(d = effect_size, n = sample_size, 
                           sig.level = significance_level, 
                           type = "two.sample")$power
print(power_result)


# ------------------------------------------------
# Topic: (S21) ANCOVA
# ------------------------------------------------

# Fit ANCOVA model with Region and Easting as factors
ancova_result_X50 <- aov(X50._present ~ Region + Easting, data = data)

# Display ANCOVA summary
summary(ancova_result_X50)
report(ancova_result_X50)


# ------------------------------------------------
# Topic: (S22) MANOVA
# ------------------------------------------------

# Perform MANOVA with X50._present and X20._present as dependent variables
manova_result <- manova(cbind(X50._present, X20._present) ~ Region, data = data)

# Display MANOVA results
summary(manova_result)
report(manova_result)


# ------------------------------------------------
# Topic: (S4) One-Proportion Z-Test
# ------------------------------------------------

# Define parameters for one-proportion z-test
x <- 50          # Number of successes (example value)
n <- 100         # Sample size (example value)
p_null <- 0.5    # Hypothesized proportion

# Perform one-proportion z-test without continuity correction
prop_test_result <- prop.test(x = x, n = n, p = p_null, correct = FALSE)
print(prop_test_result)

# End of Report 2
