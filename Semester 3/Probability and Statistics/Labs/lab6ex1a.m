X = [7 7 4 5 9 9 ...
4 12 8 1 8 7 ...
3 13 2 1 17 7 ...
12 5 6 2 1 13 ...
14 10 2 4 9 11 ...
3 5 12 6 10 7]

n = length(X)
alpha = input("give the significance level ")
%solving subpoint a)
%the null hypothesis is H0: miu(greek letter) = 8.5(it goes together with miu > 8.5, the standard is met)
%the alternative hypothesis H1: miu < 8.5(the standard is not met)
%this is a left tailed test for miu

printf("left tailed test for the mean when sigma is known\n")
sigma = 5
m0 = 8.5
[H, PVAL, CI, ZVALUE] = ztest(X, m0, sigma, 'alpha', alpha, 'tail', 'left');
zalpha = norminv(alpha, 0, 1)
RR = [-inf zalpha]

printf("the value of H is %d\n", H)

if H == 1
  printf("the null hypothesis is rejected\n")
  printf("the data suggests that the standard is not met\n")
else
  printf("the null hypothesis is not rejected\n")
  printf("the data suggests that the standard is met\n")
end

printf("the rejection region is (%4.3f,%4.3f)\n", RR)
printf("the observed value of the test statistic is ((%4.3f,%4.3f)\n", ZVALUE)
printf("the pvalue of the test is (%4.3f,%4.3f)\n", PVAL)

%hint for 1b ttest
%hint for 2a vartest2
%hint for 2b ttest2
%1b right tailed test for the mean
%2a two tailed test for comparing variances
%2b right tailed test for the difference of means
