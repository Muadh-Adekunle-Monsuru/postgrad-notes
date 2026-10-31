# SGS 501/601 — Statistical Analysis

## 1. Overview of statistical analysis

Statistical analysis is the process of collecting, organizing, summarizing, interpreting and drawing conclusions from data.

For example, imagine a university wants to determine the average amount of time students spend studying each day.

The university has 10,000 students. Instead of interviewing everyone, researchers select 200 students, record their study hours, calculate the average and use the result to estimate the average for the entire university.

This illustrates the two main branches of statistics.

|Descriptive statistics|Inferential statistics|
|---|---|
|Describes data already collected|Makes conclusions about a larger population|
|Uses mean, median, mode, percentages, standard deviation and charts|Uses confidence intervals, hypothesis tests and probability|
|Example: The average study time of 200 students is 4 hours|Example: Estimating the average study time of all 10,000 students|

### Important statistical definitions

|Term|Meaning|Example|
|---|---|---|
|Population|Entire group being studied|All 10,000 students|
|Sample|Subset selected from the population|200 students|
|Parameter|Numerical value describing a population|Population mean, $\mu$|
|Statistic|Numerical value describing a sample|Sample mean, $\bar{x}$|
|Variable|Characteristic that can change or be measured|Age, height, income|
|Sampling error|Difference between a sample estimate and its population parameter|Sample mean differs from population mean|

Important distinction: A parameter describes the population, whereas a statistic describes the sample.

## 2. Data collection and sampling methods

Covered on pages 4–6 of the lecture.

Sampling is the process of selecting some members of a population for research.

### 2.1 Probability sampling

Every population member has a known probability of being selected.

Simple random sampling: Every member has an equal probability of selection.

Example: Randomly selecting 100 student identification numbers from a list of 2,000 students.

Stratified random sampling: Divide the population into groups called strata, then randomly select individuals from each group.

Example: Divide students into undergraduate and postgraduate groups and randomly sample from both.

Cluster sampling: Divide the population into natural groups called clusters and randomly select clusters.

Example: Randomly select 5 university departments and survey students within those departments.

### 2.2 Non-probability sampling

Selection does not rely on known random probabilities.

Convenience sampling: Selecting participants who are easiest to reach, such as students currently in the library.

Volunteer sampling: Participants decide whether they want to participate, such as responding to an online survey.

### 2.3 Types of bias

Bias is a systematic error that can produce misleading research results.

|Type|Definition|Example|
|---|---|---|
|Selection bias|Sample does not properly represent the population|Surveying only wealthy students about student income|
|Non-response bias|Those who do not participate differ systematically from respondents|Most dissatisfied customers ignore a survey|
|Response bias|Participants give inaccurate or socially desirable answers|Students exaggerate their study hours|

### Exam-style theoretical question

Question: Explain the difference between stratified sampling and cluster sampling.

Answer: In stratified sampling, researchers divide the population into groups based on shared characteristics and randomly select members from each group. In cluster sampling, researchers divide the population into clusters and randomly select some clusters for investigation. Stratified sampling is commonly intended to improve representation of important subgroups, while cluster sampling is often used to reduce data collection costs.

## 3. Study designs and variables

Pages 5–6.

### Observational studies

An observational study records information without deliberately changing the participants' conditions.

Example: Investigating whether students who sleep longer obtain higher examination scores.

A relationship may be observed, but it does not automatically demonstrate causation.

### Experimental studies

In an experiment, researchers deliberately apply treatments and assess their effects.

Example: Randomly assigning students to two groups, with one group using a new learning method and the other using a conventional method.

Random assignment helps support causal conclusions.

### Types of variables

Explanatory variable (independent variable): A variable used to explain or predict an outcome.

Response variable (dependent variable): The outcome that researchers want to measure.

Lurking variable: An additional variable that may affect the observed relationship but is not included in the analysis.

Confounding variable: A variable whose influence makes it difficult to distinguish the effect of the explanatory variable from other influences.

Example:

A researcher investigates whether coffee consumption increases examination scores.

- Explanatory variable: Cups of coffee consumed.
    
- Response variable: Examination score.
    
- Possible confounding variable: Hours spent studying.
    

If students who drink more coffee also study longer, studying may explain some of the relationship between coffee consumption and examination performance.

### Three principles of experimental design

1. Control: Limit the influence of factors other than the treatment being studied.
    
2. Randomization: Randomly allocate participants to treatment groups to reduce systematic differences.
    
3. Replication: Use enough observations or participants to improve the reliability of the findings.
    

Remember that random sampling helps researchers generalize results to a population, while random assignment helps researchers draw causal conclusions.

# Part II — Descriptive statistics and calculations

## 4. Measures of central tendency

Pages 7–9.

Measures of central tendency describe the center or typical value of a dataset.

### 4.1 Mean

The mean is the arithmetic average.

$$ \boxed{\bar{x}=\frac{\sum x_i}{n}} $$

Where:

- $\bar{x}$ = sample mean
    
- $\sum x_i$ = sum of all observations
    
- $n$ = number of observations
    

Example question: Five students obtain scores of 10, 15, 20, 25 and 30. Calculate their mean score.

Solution:

$$ \bar{x}=\frac{10+15+20+25+30}{5} $$

$$ =\frac{100}{5}=\boxed{20} $$

Answer: The mean examination score is 20.

### 4.2 Median

The median is the middle observation after arranging data in ascending order.

For an odd number of observations, it is the middle value. For an even number, it is the average of the two middle values.

Example 1 — Odd number of observations

Data: 4, 6, 8, 10, 12.

The middle observation is 8.

$$ \boxed{\text{Median}=8} $$

Example 2 — Even number of observations

Data: 4, 6, 8, 10.

The middle values are 6 and 8.

$$ \text{Median}=\frac{6+8}{2}=\boxed{7} $$

### 4.3 Mode

The mode is the value that occurs most frequently.

Example: 2, 3, 3, 5, 7, 7, 7, 9.

Since 7 occurs three times:

$$ \boxed{\text{Mode}=7} $$

A dataset can have more than one mode or no unique mode.

### Relationship between mean, median and mode

Conceptual illustrations of symmetric, positively skewed and negatively skewed distributions. These relationships are typical patterns, not universal mathematical rules.

A positively skewed distribution has a longer tail to the right. A negatively skewed distribution has a longer tail to the left.

Exam tip: Outliers can substantially change the mean, whereas the median is more resistant.

## 5. Measures of variability

Pages 10–13.

Measures of variability describe how spread out data values are.

### 5.1 Range

$$ \boxed{\text{Range}=\text{Maximum}-\text{Minimum}} $$

Example: 5, 10, 15, 20, 25.

$$ \text{Range}=25-5=\boxed{20} $$

### 5.2 Quartiles and interquartile range

Quartiles divide ordered observations into four parts.

- $Q_1$: First quartile, approximately the 25th percentile.
    
- $Q_2$: Second quartile, the median.
    
- $Q_3$: Third quartile, approximately the 75th percentile.
    

The interquartile range measures the spread of the middle 50% of observations.

$$ \boxed{IQR=Q_3-Q_1} $$

Example question: Find the quartiles and IQR of:

2, 4, 6, 8, 10, 12, 14.

Using the median-of-halves method:

$$ Q_1=4,\quad Q_2=8,\quad Q_3=12 $$

$$ IQR=12-4=\boxed{8} $$

Other quartile conventions can produce different answers for some datasets, so use your lecturer's specified convention.

### 5.3 Variance

Variance measures the average squared deviation of observations from their mean.

Population variance:

$$ \boxed{\sigma^2=\frac{\sum(x_i-\mu)^2}{N}} $$

Sample variance:

$$ \boxed{s^2=\frac{\sum(x_i-\bar{x})^2}{n-1}} $$

The important difference is that population variance divides by $N$, whereas sample variance divides by $n-1$.

### 5.4 Standard deviation

Standard deviation is the square root of variance.

$$ \boxed{s=\sqrt{\frac{\sum(x_i-\bar{x})^2}{n-1}}} $$

It expresses variability in the original units of the data.

### Worked question: Calculate mean, sample variance and standard deviation

Given the five observations:

2, 4, 6, 8, 10.

Step 1 — Calculate the mean.

$$ \bar{x}=\frac{2+4+6+8+10}{5}=6 $$

Step 2 — Subtract the mean and square the differences.

|$x_i$|$x_i-\bar{x}$|$(x_i-\bar{x})^2$|
|---|---|---|
|2|−4|16|
|4|−2|4|
|6|0|0|
|8|2|4|
|10|4|16|
|Total|0|40|

Step 3 — Calculate the sample variance.

$$ s^2=\frac{40}{5-1}=\frac{40}{4} $$

$$ \boxed{s^2=10} $$

Step 4 — Calculate the standard deviation.

$$ s=\sqrt{10}=\boxed{3.162} $$

Interpretation: The observations have a sample mean of 6 and a sample standard deviation of approximately 3.16 units.

### 5.5 Coefficient of variation

The coefficient of variation (CV) compares relative variability across datasets with different means.

$$ \boxed{CV=\frac{\text{Standard deviation}}{\text{Mean}}\times100\%} $$

Question: Dataset A has mean 50 and standard deviation 5. Dataset B has mean 100 and standard deviation 20. Which has greater relative variability?

For A:

$$ CV_A=\frac{5}{50}\times100=10\% $$

For B:

$$ CV_B=\frac{20}{100}\times100=20\% $$

Answer: Dataset B has greater relative variability.

### 5.6 Detecting outliers

The lecture introduces the 1.5 × IQR rule.

$$ \text{Lower fence}=Q_1-1.5(IQR) $$

$$ \text{Upper fence}=Q_3+1.5(IQR) $$

For the earlier dataset with $Q_1=4$, $Q_3=12$, and $IQR=8$:

$$ \text{Lower}=4-1.5(8)=-8 $$

$$ \text{Upper}=12+1.5(8)=24 $$

Any observation below −8 or above 24 is flagged as a potential outlier.

A potential outlier is not automatically an error; it should be investigated.

# Part III — Probability and probability distributions

## 6. Probability, conditional probability and independence

Pages 14–15.

Probability describes how likely an event is to occur.

Its value ranges from 0 to 1.

$$ 0\leq P(A)\leq1 $$

For example, when tossing a fair coin:

$$ P(\text{Head})=\frac12=0.5=50\% $$

### 6.1 Conditional probability

Conditional probability is the probability that event A occurs, given that event B has already occurred.

$$ \boxed{P(A\mid B)=\frac{P(A\cap B)}{P(B)}} $$

Where:

- $P(A\mid B)$ = probability of A given B
    
- $P(A\cap B)$ = probability that both A and B occur
    
- $P(B)$ = probability of B
    

Example question

A class contains 40 students. Of these, 20 are female, and 12 of the female students passed an examination.

What is the probability that a randomly selected student passed, given that the student is female?

Solution:

We only consider the 20 female students.

$$ P(\text{Pass}\mid\text{Female})=\frac{12}{20} $$

$$ =\boxed{0.60=60\%} $$

### 6.2 Independent events

Two events are independent when the occurrence of one does not change the probability of the other.

For independent events:

$$ \boxed{P(A\cap B)=P(A)P(B)} $$

For example, suppose a fair coin is tossed twice.

$$ P(H_1)=0.5,\qquad P(H_2)=0.5 $$

The probability of obtaining two heads is:

$$ P(H_1\cap H_2)=0.5(0.5)=\boxed{0.25} $$

### Worked question from the lecture: Gender and employment

The lecture presents the following table on page 15.

|Gender|Employed|Unemployed|Total|
|---|---|---|---|
|Male|460|40|500|
|Female|140|260|400|
|Total|600|300|900|

Question: Are gender and employment status independent?

Step 1 — Calculate the probability of employment.

$$ P(E)=\frac{600}{900}=0.6667 $$

Step 2 — Calculate the probability of employment given that a person is male.

$$ P(E\mid M)=\frac{460}{500}=0.92 $$

Step 3 — Compare.

$$ 0.92\neq0.6667 $$

Answer: Gender and employment status are not independent in this table because knowing a person's gender changes the observed probability of employment.

This is a mathematical check of independence in the supplied data, not a formal statistical significance test for a wider population.

## 7. Bayes' theorem

Bayes' theorem is used to update the probability of an event when new evidence becomes available.

$$ \boxed{P(A\mid B)=\frac{P(B\mid A)P(A)}{P(B)}} $$

When there are only two mutually exclusive possibilities, A and not A:

$$ P(A\mid B)= \frac{P(B\mid A)P(A)} {P(B\mid A)P(A)+P(B\mid A^c)P(A^c)} $$

### Worked example: Disease testing

Adapted from the exercise on page 15.

Suppose:

- 5% of people have a disease.
    
- 95% are healthy.
    
- The test correctly identifies 90% of sick people.
    
- The test correctly identifies 90% of healthy people.
    

What is the probability that a person actually has the disease if the test result is positive?

The lecture says the test has 90% accuracy but does not separately specify sensitivity and specificity. For this calculation, we assume both are 90%.

Step 1 — Define the probabilities.

$$ P(D)=0.05 $$

$$ P(D^c)=0.95 $$

$$ P(+\mid D)=0.90 $$

$$ P(+\mid D^c)=0.10 $$

Step 2 — Apply Bayes' theorem.

$$ P(D\mid +)= \frac{0.90(0.05)} {0.90(0.05)+0.10(0.95)} $$

$$ =\frac{0.045}{0.045+0.095} $$

$$ =\frac{0.045}{0.14} $$

$$ \boxed{P(D\mid +)=0.3214=32.14\%} $$

Answer: Under these assumptions, a person who tests positive has approximately a 32.14% probability of actually having the disease.

### Understanding the calculation using 10,000 people

Testing 10,000 people

Have the disease

# 500

450 test positive

Do not have the disease

# 9,500

950 test positive

Positive test results: 1,400

450 true positives

950 false positives

Only 450 of the 1,400 positive results are from people who truly have the disease: $450/1400=32.14\%$.

Exam lesson: Never confuse the probability of a positive test among sick people, $P(+\mid D)$, with the probability of being sick given a positive test, $P(D\mid+)$.

## 8. Random variables and probability distributions

Pages 16–18.

A random variable is a numerical quantity whose value depends on a random outcome.

### Discrete random variables

A discrete random variable takes countable values.

Examples include the number of students in a classroom, the number of defective products and the number of heads in five coin tosses.

### Continuous random variables

A continuous random variable can take any value within an interval.

Examples include height, weight, temperature and time.

|Discrete variable|Continuous variable|
|---|---|
|Uses a probability mass function (PMF)|Uses a probability density function (PDF)|
|Individual values can have positive probability|Probability is calculated over intervals|
|Example: $P(X=3)$|Example: $P(3<X<5)$|

The cumulative distribution function (CDF) gives the probability that a random variable is less than or equal to a specific value:

$$ \boxed{F(x)=P(X\leq x)} $$

### Expected value of a discrete variable

The expected value is the probability-weighted average of all possible values.

$$ \boxed{E(X)=\sum xP(X=x)} $$

Worked question

A random variable has the following distribution:

|X|Probability|
|---|---|
|0|0.2|
|1|0.5|
|2|0.3|

Calculate the expected value and variance.

Step 1 — Calculate the expected value.

$$ E(X)=0(0.2)+1(0.5)+2(0.3) $$

$$ \boxed{E(X)=1.1} $$

Step 2 — Calculate $E(X^2)$.

$$ E(X^2)=0^2(0.2)+1^2(0.5)+2^2(0.3) $$

$$ =0+0.5+1.2=1.7 $$

Step 3 — Calculate variance.

$$ Var(X)=E(X^2)-[E(X)]^2 $$

$$ =1.7-(1.1)^2 $$

$$ \boxed{Var(X)=0.49} $$

Standard deviation:

$$ SD(X)=\sqrt{0.49}=\boxed{0.7} $$

## 9. Binomial distribution

A binomial distribution models the number of successes in a fixed number of independent trials.

Four conditions must be satisfied:

1. There is a fixed number of trials, $n$.
    
2. Each trial has only two possible outcomes: success or failure.
    
3. The probability of success, $p$, remains constant.
    
4. The trials are independent.
    

The binomial probability formula is:

$$ \boxed{P(X=x)=\binom nx p^x(1-p)^{n-x}} $$

Where:

$$ \binom nx=\frac{n!}{x!(n-x)!} $$

Other formulas:

$$ \text{Mean}=np $$

$$ \text{Variance}=np(1-p) $$

$$ \text{Standard deviation}=\sqrt{np(1-p)} $$

### Worked question from the lecture

Page 17.

80% of property crimes remain unsolved. Three independent crimes occur. What is the probability that exactly one crime is solved?

Step 1 — Identify the parameters.

$$ n=3,\qquad p=0.20,\qquad x=1 $$

Notice that success here means a crime being solved, so $p=0.20$, not 0.80.

Step 2 — Substitute into the binomial formula.

$$ P(X=1)=\frac{3!}{1!(3-1)!}(0.2)^1(0.8)^2 $$

Step 3 — Calculate the combination.

$$ \frac{3!}{1!2!}=\frac{6}{2}=3 $$

Step 4 — Multiply.

$$ P(X=1)=3(0.2)(0.64) $$

$$ \boxed{P(X=1)=0.384=38.4\%} $$

Answer: There is a 38.4% probability that exactly one of the three crimes will be solved.

## 10. Normal distribution

Pages 19–20.

The normal distribution is a continuous, symmetric, bell-shaped probability distribution.

Normal distribution with center $\mu$ and spread measured by standard deviation $\sigma$.

Its main properties are:

- The mean, median and mode are equal.
    
- The total area under the curve is 1.
    
- The distribution is symmetric around its mean.
    
- Approximately 68% of observations lie within one standard deviation, 95% within two and 99.7% within three standard deviations.
    

### Standard normal distribution and Z-scores

The standard normal distribution has:

$$ \mu=0,\qquad \sigma=1 $$

The Z-score formula is:

$$ \boxed{Z=\frac{X-\mu}{\sigma}} $$

The Z-score measures how many standard deviations a particular observation is above or below the mean.

A positive Z-score is above the mean; a negative Z-score is below it.

### Worked example from the lecture: Carrot lengths

Page 20.

The lecture gives a normal distribution of carrot lengths with a center of 14 cm and a spread figure of 3.6 cm. For these calculations, we interpret 3.6 cm as the standard deviation:

$$ X\sim N(\mu=14,\sigma=3.6) $$

Question A: What is the probability that a carrot is longer than 25 cm?

Step 1 — Convert to Z-score.

$$ Z=\frac{25-14}{3.6}=\frac{11}{3.6}=3.056 $$

Step 2 — Use the standard normal table.

$$ P(X>25)=P(Z>3.056) $$

$$ =1-P(Z<3.056) $$

$$ \approx1-0.99888 $$

$$ \boxed{P(X>25)\approx0.00112=0.112\%} $$

Question B: What is the probability that a carrot is between 14 and 17.6 cm?

$$ Z_1=\frac{14-14}{3.6}=0 $$

$$ Z_2=\frac{17.6-14}{3.6}=1 $$

$$ P(14<X<17.6)=P(0<Z<1) $$

$$ =0.8413-0.5000 $$

$$ \boxed{P=0.3413=34.13\%} $$

Question C: What is the probability that a carrot is shorter than 10 cm?

$$ Z=\frac{10-14}{3.6}=-1.111 $$

$$ P(X<10)=P(Z<-1.111) $$

$$ \boxed{P\approx0.1333=13.33\%} $$

### How to use a Z-table

Most cumulative Z-tables give the area to the left of a Z-score.

For example, at $Z=1.00$, the table gives 0.8413.

Therefore:

$$ P(Z<1)=0.8413 $$

$$ P(Z>1)=1-0.8413=0.1587 $$

For probabilities between two values:

$$ P(a<Z<b)=P(Z<b)-P(Z<a) $$

Exam tip: Always sketch the curve or identify whether the question asks for the left tail, right tail or area between two values before using a Z-table.

# Part IV — Sampling distributions and statistical inference

## 11. Sampling distribution

Pages 21–22.

A sampling distribution describes how a sample statistic, such as the sample mean, varies across many random samples from the same population.

Suppose a population has a true mean of 100.

If several samples of 25 observations are selected, their means might be 98, 102, 99, 101 and 100.

The sample means vary because of random sampling.

The mean of the sampling distribution of $\bar X$ is:

$$ E(\bar X)=\mu $$

Its standard deviation is called the standard error (SE).

$$ \boxed{SE(\bar X)=\frac{\sigma}{\sqrt n}} $$

Where:

- $\sigma$ = population standard deviation
    
- $n$ = sample size
    

The standard error describes the variability of the sample mean, rather than the variability of individual observations.

### Worked example: Speedboat engines

Page 22.

A manufacturer claims that its engines have:

$$ \mu=220\text{ HP},\quad \sigma=15\text{ HP} $$

A random sample of four engines is taken.

What is the probability that the sample mean is less than 215 HP?

Step 1 — Identify the given values.

$$ \mu=220,\quad \sigma=15,\quad n=4 $$

Step 2 — Calculate the standard error.

$$ SE=\frac{15}{\sqrt4}=\frac{15}{2}=7.5 $$

Step 3 — Calculate the Z-score of the sample mean.

$$ Z=\frac{\bar X-\mu}{SE} $$

$$ Z=\frac{215-220}{7.5}=-0.6667 $$

Step 4 — Find the probability.

$$ P(\bar X<215)=P(Z<-0.6667) $$

$$ \boxed{P\approx0.2525=25.25\%} $$

The lecture obtains approximately 25.14% using the rounded Z-score of −0.67. Both answers follow from different rounding precision.

Interpretation: There is approximately a one-in-four probability that the mean power of four engines will fall below 215 HP, assuming the manufacturer's stated distribution is correct.

### What happens when the sample size increases?

Interactive example — Change the sample size

Population mean = 220 HP; standard deviation = 15 HP; probability that the sample mean is below 215 HP.

Sample size (n)

## 4

Standard error

# 7.50 HP

Probability below 215 HP

# 25.249%

As the sample size increases, the standard error decreases, making the sample mean more tightly concentrated around the population mean of 220 HP.

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