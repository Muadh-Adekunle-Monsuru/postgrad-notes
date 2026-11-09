## 12. Central Limit Theorem (CLT)

Page 23.

The Central Limit Theorem states that, under suitable conditions, the sampling distribution of the sample mean becomes approximately normal as the sample size increases, even when the original population is not normally distributed.

The lecture uses $n>30$ as a general guideline for a sufficiently large sample. In practice, the sample size required depends on the shape of the original distribution and the presence of extreme observations.

The key formulas remain:

$$ E(\bar X)=\mu $$

$$ SE(\bar X)=\frac{\sigma}{\sqrt n} $$

### Worked example: Baby giraffes

Page 23.

Population mean weight:

$$ \mu=125\text{ pounds} $$

Population standard deviation:

$$ \sigma=15\text{ pounds} $$

Sample size:

$$ n=40 $$

Question: What is the probability that the sample mean is between 120 and 130 pounds?

Step 1 — Calculate the standard error.

$$ SE=\frac{15}{\sqrt{40}}=2.3717 $$

Step 2 — Calculate the lower Z-score.

$$ Z_1=\frac{120-125}{2.3717}=-2.108 $$

Step 3 — Calculate the upper Z-score.

$$ Z_2=\frac{130-125}{2.3717}=2.108 $$

Step 4 — Find the probability between the Z-scores.

$$ P(120<\bar X<130)=P(-2.108<Z<2.108) $$

$$ =0.9826-0.0174 $$

$$ \boxed{P\approx0.9652=96.52\%} $$

Answer: The probability that the sample mean weight is between 120 and 130 pounds is approximately 96.52%.

Key difference to remember: The normal distribution concerns individual measurements, while the sampling distribution concerns statistics calculated from samples.

## 13. Confidence intervals

Pages 24–28.

A confidence interval (CI) is an interval calculated from sample data to estimate an unknown population parameter.

Instead of giving only one estimate, the researcher gives a range of plausible values.

The general formula is:

$$ \boxed{\text{Confidence interval}=\text{Point estimate}\pm\text{Margin of error}} $$

Margin of error:

$$ \boxed{ME=\text{Critical value}\times SE} $$

A 95% confidence interval is constructed using a method that, over many repeated samples, would contain the true population parameter approximately 95% of the time.

### 13.1 Z-confidence interval

Use a Z-interval for the population mean when the population standard deviation $\sigma$ is known and the normal approximation is appropriate.

$$ \boxed{\bar x\pm Z_{\alpha/2}\frac{\sigma}{\sqrt n}} $$

Common two-sided critical values:

|Confidence level|Alpha ($\alpha$)|Critical Z|
|---|---|---|
|90%|0.10|1.645|
|95%|0.05|1.960|
|99%|0.01|2.576|

### Worked question: Z-confidence interval

A sample of 100 students has an average examination score of 75. The population standard deviation is known to be 10.

Find a 95% confidence interval for the population mean.

Step 1 — Given information.

$$ \bar x=75,\quad \sigma=10,\quad n=100 $$

$$ Z_{0.025}=1.96 $$

Step 2 — Standard error.

$$ SE=\frac{10}{\sqrt{100}}=1 $$

Step 3 — Margin of error.

$$ ME=1.96(1)=1.96 $$

Step 4 — Calculate the confidence interval.

$$ CI=75\pm1.96 $$

$$ \boxed{CI=(73.04,\ 76.96)} $$

Interpretation: We are 95% confident that the population mean examination score lies between 73.04 and 76.96, in the frequentist confidence-interval sense explained above.

### 13.2 T-confidence interval

Use the t-distribution when estimating a population mean and the population standard deviation is unknown.

$$ \boxed{\bar x\pm t_{\alpha/2,n-1}\frac{s}{\sqrt n}} $$

Where:

- $s$ = sample standard deviation
    
- $t_{\alpha/2,n-1}$ = t critical value
    
- $n-1$ = degrees of freedom
    

The t-distribution accounts for the additional uncertainty in estimating $\sigma$ using $s$.

### Worked example from the lecture: Emergency room waiting time

Page 27.

A random sample of 50 patients has:

$$ n=50,\qquad \bar x=30,\qquad s=20 $$

Find a 95% confidence interval.

Step 1 — Choose the t-distribution.

The population standard deviation is unknown, so use a t-confidence interval.

Step 2 — Calculate degrees of freedom.

$$ df=n-1=50-1=49 $$

The lecture uses $t=2.021$, from the available table row for 40 degrees of freedom.

Step 3 — Calculate standard error.

$$ SE=\frac{20}{\sqrt{50}}=2.8284 $$

Step 4 — Margin of error.

$$ ME=2.021(2.8284)=5.717 $$

Step 5 — Construct the confidence interval.

$$ CI=30\pm5.717 $$

$$ \boxed{CI\approx(24.28,\ 35.72)} $$

Answer: Following the lecture's table approximation, the 95% confidence interval for the average ER waiting time is 24.28 to 35.72 minutes.

Using the more precise critical value for 49 degrees of freedom, approximately 2.010, gives a slightly narrower interval of about (24.31, 35.69).

### Normal probability plot

Page 28 explains a method for assessing whether data are consistent with a normal distribution.

The procedure is to order the data, assign plotting probabilities, convert them into standard normal quantiles, and plot those quantiles against the observed values.

One plotting-probability formula from the lecture is:

$$ p_i=\frac{i-0.5}{n} $$

If the plotted points lie approximately on a straight line, the normality assumption may be reasonable.

This is particularly useful for small-sample t-procedures.

# Part V — Hypothesis testing

## 14. The theory of hypothesis testing

Pages 29–36.

Hypothesis testing is a statistical procedure for evaluating claims about population parameters using sample evidence.

For example, a hospital claims that its average patient waiting time is 10 minutes. A researcher collects data to determine whether the mean actually exceeds 10 minutes.

### 14.1 Null and alternative hypotheses

Null hypothesis ($H_0$): The baseline statement being tested. It commonly represents no effect, no difference, or a specified population parameter value.

Alternative hypothesis ($H_a$): The competing claim that the researcher is investigating.

For example:

$$ H_0:\mu=10 $$

$$ H_a:\mu>10 $$

The null hypothesis says that the population mean is 10 minutes, while the alternative states that it exceeds 10 minutes.

### 14.2 Types of hypothesis tests

|Test|Alternative hypothesis|When used|
|---|---|---|
|Two-tailed|$H_a:\mu\neq\mu_0$|Checking whether a mean is different|
|Right-tailed|$H_a:\mu>\mu_0$|Checking whether a mean is greater|
|Left-tailed|$H_a:\mu<\mu_0$|Checking whether a mean is smaller|

### 14.3 Significance level

The significance level, $\alpha$, is the chosen threshold for rejecting the null hypothesis.

Common values:

$$ \alpha=0.05,\quad0.01,\quad0.10 $$

At $\alpha=0.05$, a hypothesis-testing procedure has a 5% Type I error rate under its stated assumptions.

### 14.4 P-value

The p-value is the probability, assuming the null hypothesis is true, of obtaining a test statistic as extreme as or more extreme than the observed one in the direction specified by the alternative hypothesis.

Decision rule:

$$ \boxed{ \begin{aligned} p&\leq\alpha $$\Rightarrow \text{Reject }H_0\\ p&>\alpha $$\Rightarrow \text{Fail to reject }H_0 \end{aligned}} $$

Failing to reject the null hypothesis does not prove that it is true.

### 14.5 Type I and Type II errors

|Error|Meaning|
|---|---|
|Type I error|Rejecting a true null hypothesis|
|Type II error|Failing to reject a false null hypothesis|
|Power|Probability of correctly rejecting a false null hypothesis|

The probability of a Type I error is controlled by $\alpha$. The probability of a Type II error is commonly denoted by $\beta$.

Statistical power is:

$$ \boxed{\text{Power}=1-\beta} $$

### The six steps of hypothesis testing

1

State the hypotheses

Write H₀ and Hₐ and check the assumptions.

2

Choose significance level

Use the given α, often 0.05.

3

Calculate the test statistic

Apply the appropriate Z, t or other test formula.

4

Determine the p-value or critical value

Use the appropriate statistical distribution.

5

Make a decision

Reject or fail to reject H₀.

6

Write the conclusion

Explain the result in the context of the question.

## 15. One-sample t-test

This test evaluates a claim about one population mean when the population standard deviation is unknown.

$$ \boxed{t=\frac{\bar x-\mu_0}{s/\sqrt n}} $$

Where:

- $\bar x$ = sample mean
    
- $\mu_0$ = hypothesized population mean
    
- $s$ = sample standard deviation
    
- $n$ = sample size
    

Degrees of freedom:

$$ df=n-1 $$

### Worked example: Lumber length

Pages 33–34.

A builder believes the mean length of pieces of lumber is 8.5 feet.

A sample gives:

$$ n=61,\quad \bar x=8.3,\quad s=1.2 $$

At 1% significance, test whether the average length differs from 8.5 feet.

Step 1 — State the hypotheses.

$$ H_0:\mu=8.5 $$

$$ H_a:\mu\neq8.5 $$

It is a two-tailed test.

Step 2 — Significance level.

$$ \alpha=0.01 $$

Step 3 — Calculate the test statistic.

$$ t=\frac{8.3-8.5}{1.2/\sqrt{61}} $$

$$ =\frac{-0.2}{0.1536} $$

$$ \boxed{t\approx-1.302} $$

Step 4 — Determine the critical value.

$$ df=61-1=60 $$

From the lecture's t-table:

$$ t_{\text{critical}}=\pm2.660 $$

Rejection region:

$$ t<-2.660\quad\text{or}\quad t>2.660 $$

Step 5 — Compare.

The calculated t-value of −1.302 does not fall in the rejection region.

Step 6 — Conclusion.

We fail to reject $H_0$.

Answer: At the 1% significance level, there is insufficient statistical evidence to conclude that the population mean lumber length differs from 8.5 feet.

## 16. One-tailed hypothesis test

### Worked example: Hospital waiting time

Pages 35–36.

A hospital claims that its average weekend waiting time is 10 minutes.

A sample of 40 patients gives:

$$ n=40,\quad\bar x=11,\quad s=3 $$

Test whether the average waiting time exceeds 10 minutes at a 5% significance level.

Step 1 — Hypotheses.

$$ H_0:\mu=10 $$

$$ H_a:\mu>10 $$

This is a right-tailed test.

Step 2 — Significance level.

$$ \alpha=0.05 $$

Step 3 — Test statistic.

$$ t=\frac{11-10}{3/\sqrt{40}} $$

$$ =\frac{1}{0.47434} $$

$$ \boxed{t=2.108} $$

Step 4 — Critical value.

$$ df=40-1=39 $$

The lecture uses a critical t-value of approximately 1.69.

Step 5 — Make the decision.

$$ 2.108>1.69 $$

Therefore, reject $H_0$.

Step 6 — Conclusion.

At the 5% significance level, there is sufficient statistical evidence that the average weekend waiting time exceeds 10 minutes.

### Interactive practice: Understanding the p-value rule

Try different p-values and significance levels

P-value

## 0.030

Significance level (α)

1%

5%

10%

Reject H₀

The p-value (0.030) is at or below α (0.05). The result is statistically significant at the selected level.

# Part VI — Comparing two populations

## 17. Independent samples versus paired samples

Pages 37–38.

Researchers frequently want to compare two groups to determine whether their population means differ.

There are two major situations.

|Independent samples|Paired samples|
|---|---|
|Observations in one sample are not matched to observations in the other|Every observation has a corresponding matched observation|
|Comparing scores from two separate groups of students|Comparing students' scores before and after training|
|Comparing two different production machines|Comparing measurements from two locations on each specimen|

This distinction determines which statistical test to use.

## 18. Two independent sample means

Pages 39–44.

The objective is to test whether the means of two independent populations differ.

The population parameter of interest is:

$$ \mu_1-\mu_2 $$

A common null hypothesis is:

$$ H_0:\mu_1-\mu_2=0 $$

There are two approaches discussed in the lecture:

Pooled variance: Used when the population variances can reasonably be assumed equal.

Unpooled variance: Used when the equal-variance assumption cannot be justified.

### 18.1 Pooled variance formula

$$ \boxed{ s_p=\sqrt{ \frac{(n_1-1)s_1^2+(n_2-1)s_2^2} {n_1+n_2-2} }} $$

The pooled two-sample t-statistic is:

$$ \boxed{ t=\frac{\bar x_1-\bar x_2} {s_p\sqrt{\frac1{n_1}+\frac1{n_2}}} } $$

For the null hypothesis that the two means are equal:

$$ df=n_1+n_2-2 $$

### Worked example from the lecture: Comparing two machines

Pages 41–43.

A factory wants to determine whether a new machine packs cartons faster than an old machine.

The sample statistics are:

|Statistic|New machine|Old machine|
|---|---|---|
|Sample size|10|10|
|Sample mean|42.14|43.23|
|Sample standard deviation|0.683|0.750|

Assume the independence, normality and equal-variance conditions are sufficiently met.

Test the claim at a 5% significance level.

Step 1 — State the hypotheses.

Define:

$$ \mu_1=\text{Mean packing time of new machine} $$

$$ \mu_2=\text{Mean packing time of old machine} $$

Because a faster machine has a smaller packing time:

$$ H_0:\mu_1-\mu_2=0 $$

$$ H_a:\mu_1-\mu_2<0 $$

This is a left-tailed test.

Step 2 — Calculate the pooled standard deviation.

$$ s_p=\sqrt{ \frac{9(0.683)^2+9(0.750)^2}{18} } $$

Square the sample standard deviations:

$$ 0.683^2=0.466489 $$

$$ 0.750^2=0.5625 $$

Substitute:

$$ s_p=\sqrt{ \frac{9(0.466489)+9(0.5625)}{18} } $$

$$ =\sqrt{\frac{9.260901}{18}} $$

$$ \boxed{s_p\approx0.7173} $$

Step 3 — Calculate the standard error of the difference.

$$ SE=s_p\sqrt{\frac1{10}+\frac1{10}} $$

$$ =0.7173\sqrt{0.2} $$

$$ \boxed{SE\approx0.3208} $$

Step 4 — Calculate the t-statistic.

$$ t=\frac{42.14-43.23}{0.3208} $$

$$ =\frac{-1.09}{0.3208} $$

$$ \boxed{t\approx-3.398} $$

Step 5 — Determine the critical value.

$$ df=10+10-2=18 $$

At the 5% significance level for a left-tailed test:

$$ t_{\text{critical}}=-1.734 $$

Step 6 — Make the decision.

$$ -3.398<-1.734 $$

The calculated statistic falls within the rejection region.

Therefore, reject $H_0$.

Conclusion: There is sufficient statistical evidence at the 5% significance level that the new machine has a lower mean packing time and is therefore faster than the old machine.

### 18.2 Confidence interval for the difference between two means

For pooled independent samples:

$$ \boxed{ (\bar x_1-\bar x_2)\pm t_{\alpha/2}\,s_p\sqrt{\frac1{n_1}+\frac1{n_2}} } $$

The lecture asks for a 99% confidence interval using the same machine data.

Given:

$$ \bar x_1-\bar x_2=42.14-43.23=-1.09 $$

$$ s_p=0.7173,\quad t_{\alpha/2}=2.878 $$

$$ CI=-1.09\pm2.878(0.7173)\sqrt{0.2} $$

$$ CI=-1.09\pm0.923 $$

$$ \boxed{CI\approx(-2.013,\,-0.167)} $$

Interpretation: We are 99% confident that the new machine's population mean packing time is approximately 0.167 to 2.013 time units lower than the old machine's mean.

Since the interval does not include zero, the difference is statistically significant at the corresponding 1% two-sided level.

### 18.3 Unpooled variance test

When population variances cannot reasonably be assumed equal, the lecture uses the unpooled approach, commonly called Welch's t-test.

$$ \boxed{ t=\frac{\bar x_1-\bar x_2} {\sqrt{\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}}} } $$

The degrees of freedom are approximated using the Welch–Satterthwaite formula.

$$ df\approx \frac{\left(\frac{s_1^2}{n_1}+\frac{s_2^2}{n_2}\right)^2} {\frac{(s_1^2/n_1)^2}{n_1-1}+ \frac{(s_2^2/n_2)^2}{n_2-1}} $$

Exam tip: Do not automatically pool sample variances. The lecture uses the similarity of standard deviations as a rough check, but a pooled test requires a justified equal-population-variance assumption. When that assumption is doubtful, Welch's test is generally appropriate.

## 19. Paired sample t-test

Pages 45–48.

A paired sample t-test is used when observations are naturally matched.

Examples include measurements on the same patients before and after treatment, performance of the same students before and after instruction, and observations from two locations on the same specimen.

The important idea is to calculate a difference for each pair:

$$ d_i=x_i-y_i $$

Then analyze the differences as a single sample.

The sample mean difference is:

$$ \boxed{\bar d=\frac{\sum d_i}{n}} $$

The paired t-statistic is:

$$ \boxed{t=\frac{\bar d-\mu_{d,0}}{s_d/\sqrt n}} $$

Usually, $\mu_{d,0}=0$.

The confidence interval is:

$$ \boxed{\bar d\pm t_{\alpha/2,n-1}\frac{s_d}{\sqrt n}} $$

### Worked example from the lecture: Zinc concentrations in water

Pages 46–48.

Researchers measure zinc concentrations in bottom water and surface water at 10 paired locations.

For each pair:

$$ d_i=\text{Bottom concentration}-\text{Surface concentration} $$

The lecture gives:

$$ n=10 $$

$$ \bar d=0.0804,\quad s_d=0.0523 $$

Question A: Calculate a 95% confidence interval for the true mean difference.

Step 1 — Calculate degrees of freedom.

$$ df=10-1=9 $$

At 95% confidence:

$$ t_{0.025,9}=2.2622 $$

Step 2 — Calculate the standard error.

$$ SE=\frac{0.0523}{\sqrt{10}} $$

$$ \boxed{SE\approx0.01654} $$

Step 3 — Calculate the margin of error.

$$ ME=2.2622(0.01654)\approx0.03741 $$

Step 4 — Construct the interval.

$$ CI=0.0804\pm0.03741 $$

$$ \boxed{CI\approx(0.04299,\ 0.11781)} $$

Interpretation: The interval is entirely positive. This provides evidence that bottom-water zinc concentrations are higher on average than surface-water concentrations.

### Question B: Hypothesis testing

At the 5% significance level, test whether the mean bottom-water concentration exceeds the surface-water concentration.

Step 1 — State the hypotheses.

$$ H_0:\mu_d=0 $$

$$ H_a:\mu_d>0 $$

Step 2 — Calculate the statistic.

$$ t=\frac{0.0804-0}{0.0523/\sqrt{10}} $$

$$ =\frac{0.0804}{0.01654} $$

$$ \boxed{t\approx4.86} $$

Step 3 — Determine the critical value.

For $df=9$ and a right-tailed test at 5%:

$$ t_{\text{critical}}=1.833 $$

Step 4 — Compare.

$$ 4.86>1.833 $$

Reject $H_0$.

Conclusion: At the 5% significance level, the data provide sufficient statistical evidence that bottom water has a higher mean zinc concentration than surface water.

## 20. Comparing two population variances

Page 49.

Sometimes the objective is to compare the variability of two populations rather than their means.

For example, two machines may have similar average production times but different levels of consistency.

The hypotheses for comparing variances can be written as:

$$ H_0:\sigma_1^2=\sigma_2^2 $$

$$ H_a:\sigma_1^2\neq\sigma_2^2 $$

### F-test

For two independent samples from normal populations, the test statistic is:

$$ \boxed{F=\frac{s_1^2}{s_2^2}} $$

The statistic follows an F-distribution under the null hypothesis, with degrees of freedom $n_1-1$ and $n_2-1$.

### Worked example: Machine variances

Using the sample standard deviations from the lecture:

$$ s_{\text{new}}=0.683,\quad s_{\text{old}}=0.750 $$

Calculate the F-statistic:

$$ F=\frac{0.683^2}{0.750^2} $$

$$ =\frac{0.466489}{0.5625} $$

$$ \boxed{F\approx0.8293} $$

The lecture reports an F-test p-value of approximately 0.787.

Since:

$$ 0.787>0.05 $$

We fail to reject $H_0$.

Conclusion: There is insufficient statistical evidence at the 5% level to conclude that the two machines have different population variances.

The lecture also identifies Bonett's test and Levene's test as methods for comparing variability when the normality assumptions of the classical F-test are less suitable.

# Part VII — Other important statistical methods

## 21. Methods mentioned but not developed in detail

The lecture explicitly identifies the following as topics not covered in depth on page 50. The short definitions below are provided for conceptual understanding; their full calculation procedures are not part of the uploaded lecture.

### Chi-square test of independence

A chi-square test of independence assesses whether two categorical variables are associated in a population.

Example: Is employment status associated with gender?

Its test statistic compares observed frequencies with expected frequencies:

$$ \chi^2=\sum\frac{(O-E)^2}{E} $$

Where $O$ is an observed frequency and $E$ is an expected frequency under independence.

### Correlation

Correlation measures the strength and direction of a relationship between two quantitative variables.

Pearson's correlation coefficient is denoted by $r$:

$$ -1\leq r\leq1 $$

- $r=1$: Perfect positive linear relationship.
    
- $r=-1$: Perfect negative linear relationship.
    
- $r=0$: No linear correlation.
    

Correlation does not establish causation.

### Linear regression

Linear regression models or predicts one quantitative variable from another.

A simple linear regression equation is:

$$ \boxed{\hat y=a+bx} $$

Where $a$ is the intercept, $b$ is the slope, and $\hat y$ is the predicted response.

### Analysis of variance (ANOVA)

ANOVA is used to compare population means across more than two groups.

Example: Comparing average examination scores across three different teaching methods.

The null hypothesis typically states that all group population means are equal.

A significant ANOVA result indicates evidence that not all means are equal; it does not by itself identify which groups differ.

# Part VIII — Formula summary and examination preparation

## 22. Important formulas to memorize

|Topic|Formula|
|---|---|
|Sample mean|$\bar x=\frac{\sum x_i}{n}$|
|Sample variance|$s^2=\frac{\sum(x_i-\bar x)^2}{n-1}$|
|Standard deviation|$s=\sqrt{s^2}$|
|Range|Maximum − Minimum|
|IQR|$Q_3-Q_1$|
|Coefficient of variation|$CV=\frac{s}{\bar x}\times100\%$|
|Conditional probability|$P(A\mid B)=\frac{P(A\cap B)}{P(B)}$|
|Binomial probability|$P(X=x)=\binom nx p^x(1-p)^{n-x}$|
|Normal Z-score|$Z=\frac{X-\mu}{\sigma}$|
|Standard error|$SE=\frac{\sigma}{\sqrt n}$|
|Z-confidence interval|$\bar x\pm z_{\alpha/2}\frac{\sigma}{\sqrt n}$|
|t-confidence interval|$\bar x\pm t_{\alpha/2,n-1}\frac{s}{\sqrt n}$|
|One-sample t-test|$t=\frac{\bar x-\mu_0}{s/\sqrt n}$|
|Pooled t-test|$t=\frac{\bar x_1-\bar x_2}{s_p\sqrt{1/n_1+1/n_2}}$|
|Paired t-test|$t=\frac{\bar d}{s_d/\sqrt n}$|
|F-test|$F=\frac{s_1^2}{s_2^2}$|

## 23. How to identify the correct statistical method

A frequent examination challenge is determining which formula to use.

Interactive statistical test selector

What are you analyzing?

One quantitative population mean

Two quantitative population means

Two population variances

Categorical outcome / proportions

Relationship between two quantitative variables

What is the objective?

Estimate using a confidence interval

Test a hypothesis

Is the population standard deviation known?

Known

Unknown

RECOMMENDED METHOD

One-sample t-confidence interval

Check the sampling, distribution and other assumptions before applying the method.

## 24. Exam-style practice questions with answers

These additional questions are based on concepts covered in the lecture. They are not necessarily questions appearing verbatim in the original slides.

Descriptive statistics

### Question 1 of 8

0/8 answered

The scores of five students are 4, 6, 8, 10 and 12. What are the mean, median and sample variance?

A. 8, 8, 10

B. 8, 8, 8

C. 10, 8, 10

D. 8, 10, 10

PreviousCheck answer

Restart practice

## 25. Important theoretical questions and model answers

These are useful for short-answer and essay-style examination questions.

Q1. Explain the difference between descriptive and inferential statistics.

Descriptive statistics summarize and organize observed data using measures such as the mean, median, standard deviation, percentages and charts. Inferential statistics use sample information and probability models to estimate population parameters, test hypotheses and draw conclusions about a larger population.

Q2. What is the importance of randomization in experimental research?

Randomization helps distribute participant characteristics across treatment groups, reducing systematic differences and supporting more reliable estimates of treatment effects. Random assignment strengthens causal inference, whereas random sampling supports generalization to the sampled population.

Q3. Explain the difference between standard deviation and standard error.

Standard deviation measures the dispersion of individual observations around their mean. Standard error measures the sampling variability of an estimator, such as the sample mean, across repeated samples. For independent observations, the standard error of the sample mean is $\sigma/\sqrt n$.

Q4. What is the Central Limit Theorem, and why is it important?

The Central Limit Theorem states that under appropriate conditions, the sampling distribution of the sample mean approaches a normal distribution as sample size increases. This allows researchers to use normal-based approximations for confidence intervals and hypothesis testing even when the original population distribution is not normal.

Q5. Explain the difference between a Z-test and a t-test for a population mean.

A Z-test uses the standard normal distribution and is appropriate when the population standard deviation is known and the required distributional conditions hold. A t-test uses the sample standard deviation and the t-distribution when the population standard deviation is unknown. The t-distribution has heavier tails and depends on degrees of freedom.

Q6. What is the relationship between confidence intervals and hypothesis testing?

Both use sample data and a sampling distribution to perform statistical inference. For a two-sided hypothesis test at significance level $\alpha$, a corresponding $100(1-\alpha)\%$ confidence interval gives an equivalent decision: reject the hypothesized parameter value if it lies outside the interval.

Q7. What is statistical significance?

A result is statistically significant at level $\alpha$ when the p-value is at or below $\alpha$. This indicates that the result is sufficiently inconsistent with the null hypothesis according to the chosen testing procedure. Statistical significance does not necessarily mean that the effect is large or practically important.

Q8. Why must paired data be analyzed differently from independent data?

Paired observations are related because each observation in one sample corresponds to a specific observation in the other. Analyzing within-pair differences accounts for this relationship. An independent-samples procedure ignores the pairing and may produce inappropriate standard errors and conclusions.

## 26. Final revision guide

For examination preparation, the following sequence gives you a practical way to revise this lecture.

|Priority|Topics|What you should be able to do|
|---|---|---|
|1|Definitions, sampling and study design|Define concepts and distinguish research designs|
|2|Mean, median, variance and SD|Calculate descriptive statistics step by step|
|3|Conditional probability and Bayes|Solve probability problems using correct conditions|
|4|Binomial and normal distributions|Identify distributions and calculate probabilities|
|5|Sampling distributions and CLT|Calculate standard errors and sample-mean probabilities|
|6|Confidence intervals|Select Z or t and calculate interval bounds|
|7|Hypothesis testing|Formulate hypotheses, calculate test statistics and interpret decisions|
|8|Independent, paired and variance tests|Select appropriate tests and solve comparison problems|

### Five examination mistakes to avoid

1. Using $n$ instead of $n-1$ when calculating sample variance or the degrees of freedom for a one-sample t-test.
    
2. Using standard deviation instead of standard error when standardizing the sample mean.
    
3. Choosing the wrong probability tail, especially when a question asks for a probability greater than a value.
    
4. Confusing independent and paired samples, which leads to the wrong test statistic.
    
5. Writing that the null hypothesis has been accepted or proven true when the correct conclusion is merely to fail to reject it.
    

### Key takeaway

The central idea connecting almost every topic in this lecture is:

Collect representative data → describe the sample → understand sampling uncertainty → estimate population parameters or test hypotheses → interpret the results in the research context.

The calculations matter, but understanding why each formula is used and what its result means is equally important. That is what allows you to solve both numerical and theoretical examination questions correctly.

Source: SGS 501/601 Statistical Analysis, 53-page Kadir Has University lecture. The worked lecture examples have been retained with explanatory steps, while additional practice questions and clarifications are identified separately. Some numerical results use more precise rounding than the original slides.