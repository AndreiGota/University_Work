pkg load statistics

%we ask the user to input the required values for the binomial
n = input("Give the number of trials n= ")
p = input("Give the prob. of success p= ")
%n is a natural number
%p is a value between 0 and 1
%x is the number of successes x - values for the pdf
x = 0:1:n
px = binopdf(x,n,p);
%doesn't overwrite the last graph "hold on"
hold on
plot(x,px,'r+')
%to give the values for the cdf
%you must always "simulate continuity"
%that is,
xx = 0:01:n
fx = binocdf(xx, n, p)
legend
plot(xx, fx, 'b')


