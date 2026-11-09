# SGS 501/601 — Statistical Analysis

## 1. Overview of statistical analysis

Statistical analysis is the process of collecting, organizing, summarizing, interpreting and drawing conclusions from data.

For example, imagine a university wants to determine the average amount of time students spend studying each day.

The university has 10,000 students. Instead of interviewing everyone, researchers select 200 students, record their study hours, calculate the average and use the result to estimate the average for the entire university.

This illustrates the two main branches of statistics.

| Descriptive statistics                                              | Inferential statistics                                            |
| ------------------------------------------------------------------- | ----------------------------------------------------------------- |
| Describes data already collected                                    | Makes conclusions about a larger population                       |
| Uses mean, median, mode, percentages, standard deviation and charts | Uses confidence intervals, hypothesis tests and probability       |
| Example: The average study time of 200 students is 4 hours          | Example: Estimating the average study time of all 10,000 students |

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

