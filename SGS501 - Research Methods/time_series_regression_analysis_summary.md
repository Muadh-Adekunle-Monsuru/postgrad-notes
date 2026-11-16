# Comprehensive Summary: Research Methods, Regression Analysis, and Time Series

## 1. Fundamentals of Econometric Modeling

### What is a Good Model?
A strong model possesses four key attributes:
1. **Clarity:** It helps us understand important relationships.
2. **Predictive Accuracy:** Its predictions align with empirical evidence.
3. **Communication:** It clarifies agreements and disagreements among analysts.
4. **Utility:** It can be applied practically to improve real-world systems.

### Analytical Frameworks
Research analysis typically relies on three layers:
* **Theoretical Framework:** Establishes the underlying theories and concepts.
* **Conceptual Framework:** Maps out variables and anticipated relationships.
* **Analytical Framework:** Details the data collection, diagnostic testing, econometric modeling, and reporting processes.

---

## 2. Regression Analysis

Regression is a statistical technique used to estimate relationships among variables. It measures how the typical value of a **dependent variable ($Y$)** changes when any **independent/explanatory variable ($X$)** changes, holding other variables constant (**ceteris paribus**).

### Simple Linear Regression
The population regression model is expressed as:
$$Y_i = \beta_0 + \beta_1 X_i + \varepsilon_i$$

* $Y_i$: Dependent variable (response)
* $X_i$: Independent variable (predictor)
* $\beta_0$: Population $Y$-intercept
* $\beta_1$: Population slope coefficient (degree and direction of relationship)
* $\varepsilon_i$: Random error term (unexplained noise, assumed to be normally distributed with a mean of zero)

#### Practical Example: Advertising and Sales
* **Scenario:** A retail manager wants to know how monthly advertising expenditure ($X$, in thousands of dollars) impacts monthly sales revenue ($Y$, in thousands of dollars).
* **Model:** $\text{Sales}_i = 50 + 4.5 \times \text{Advertising}_i + \varepsilon_i$
* **Interpretation:** The intercept ($\beta_0 = 50$) suggests that even with zero advertising, base sales are 50 thousand dollars. The slope ($\beta_1 = 4.5$) indicates that for every additional 1,000 dollars spent on advertising, sales increase by an average of 4.5 thousand dollars, holding everything else constant.

### Multiple Linear Regression
When there are multiple explanatory variables:
$$Y_i = \beta_0 + \beta_1 X_{1i} + \beta_2 X_{2i} + \dots + \beta_k X_{ki} + \varepsilon_i$$

### Key Goodness-of-Fit Metrics
* **$R^2$ (Coefficient of Determination):** Measures the proportion of variance in $Y$ explained by the model (ranges from 0 to 1).
* **Adjusted $R^2$:** Penalizes the inclusion of unnecessary explanatory variables.
* **p-value:** Tests statistical significance; values under $0.1$ or $0.05$ typically indicate a statistically significant predictor.
* **AIC (Akaike Information Criterion):** Used for model selection where lower values indicate a better balance of fit and simplicity.

---

## 3. Time Series Data vs. Other Data Types

* **Cross-Sectional Data:** Observations of multiple entities at a single point in time (e.g., GDP of 50 different countries in 2025).
* **Panel (Longitudinal) Data:** Multiple entities observed across multiple time periods (e.g., GDP of 50 countries from 2010 to 2025).
* **Time Series Data:** A sequence of observations of a single variable measured at successive points in time (e.g., Turkey's monthly inflation rate from 2015 to 2026). Data frequency can be annual, quarterly, monthly, weekly, daily, or high-frequency (minute/second-level).

---

## 4. Components of a Time Series

A classical time series can be decomposed into four core structural elements:
1. **Trend ($T$):** The long-term upward or downward movement in the data (e.g., long-term growth in global computing power).
2. **Cycle ($C$):** Long-term oscillatory movements lasting several years (e.g., economic business cycles of expansions and recessions).
3. **Seasonal Effects ($S$):** Short-term, regular calendar-based fluctuations (e.g., retail sales peaking every December due to holidays).
4. **Residual/Error ($E$):** Irregular, random noise remaining after trend, cycle, and seasonal components are removed. Often modeled as **white noise** (mean zero, constant variance, no autocorrelation).

#### Practical Example: Ice Cream Sales
* **Trend:** Sales grow year-over-year as the local population increases.
* **Seasonal Effect:** Sales spike every July and August (summer) and drop every January.
* **Residual:** A sudden heatwave in October causes an unexpected sales bump that the standard seasonal pattern cannot explain.

---

## 5. Stationarity and Differencing

### Why Stationarity Matters
Many econometric models require time series data to be **stationary**—meaning its mean, variance, and autocorrelation structure remain constant over time. If a series has a stochastic trend (like a **Random Walk**: $y_t = y_{t-1} + \varepsilon_t$), regressing it on another non-stationary series can yield **spurious (meaningless) regression results**.

### Differencing
To stabilize the mean and remove trends, we use **differencing**:
* **First-Order Differencing:** $y'_t = y_t - y_{t-1}$
* **Seasonal Differencing:** Removes seasonal patterns (e.g., $y_t - y_{t-12}$ for monthly data).
* **Log Transformation:** Often applied prior to differencing to stabilize the variance if fluctuations grow larger over time.

---

## 6. ARIMA Models (AutoRegressive Integrated Moving Average)

An ARIMA model is a powerful forecasting framework denoted as $\text{ARIMA}(p, d, q)(\text{P, D, Q})_s$.

### Components Breakdown:
* **AR($p$) - Autoregressive Part:** Relies on past values of the series itself. (e.g., Today's temperature depends on yesterday's temperature).
* **I($d$) - Integration / Differencing:** The number of non-seasonal differences ($d$) required to make the series stationary.
* **MA($q$) - Moving Average Part:** Relies on past forecast errors rather than past values.
* **Seasonal Parts ($P, D, Q)_s$:** Handles seasonal periodicity (e.g., $s = 12$ for monthly data).

### Model Identification Using ACF and PACF Plots
Analysts inspect **Autocorrelation Function (ACF)** and **Partial Autocorrelation Function (PACF)** plots of stationary data to determine model orders ($p$ and $q$):
* **Pure AR($p$):** PACF cuts off sharply after lag $p$, while ACF decays exponentially or sinusoidally.
* **Pure MA($q$):** ACF cuts off sharply after lag $q$, while PACF decays exponentially or sinusoidally.

---

## 7. Step-by-Step ARIMA Modeling Workflow

1. **Stationarity Check:** Plot the data and perform unit root tests (e.g., Augmented Dickey-Fuller / ADF test). Apply logs and differencing ($d$) until the series is stationary.
2. **Model Identification:** Examine ACF and PACF plots of the stationary series to propose candidate orders for $(p, d, q)$.
3. **Estimation & Comparison:** Fit candidate models and compare them using goodness-of-fit metrics like **AIC** and forecast accuracy metrics like **MAPE** or **RMSE**.
4. **Diagnostic Residual Checking:** Analyze the residuals of the chosen model. Ensure they resemble white noise (no remaining autocorrelation via Ljung-Box test). If valid, use the model for forecasting.