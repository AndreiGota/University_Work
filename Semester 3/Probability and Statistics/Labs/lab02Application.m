pkg load statistics
%Application lab2
%subpoint a)
%use binomial distribution
%n = 3, p = 0.5
x = 0:1:3
px = binopdf(x,3,0.5)
%the probality distribution of x is:
%first row 0 1 2 3
%second row 1/8 3/8 3/8 1/8

%subpoint b)
xx = 0:0.5:3
fx = binocdf(xx, 3, 0.5)

%subpoint c)
p1 = binopdf(0, 3, 0.5)
p2 = 1 - binopdf(1, 3, 0.5)

%subpoint d)
p3 = binocdf(2, 3, 0.5)
p4 = binocdf(1, 3, 0.5)

%subpoint e)
p5 = 1 - binopdf(0, 3, 0.5)
%also works 1 - binocdf(0, 3, 0.5)
%P(X>=1) = 1 - P(X<1) = 1 - P(x <= 0) = 1 - P(x = 0) for above
p6 = 1 - binocdf(1, 3, 0.5)
%P(x > 1) = 1 - P(x <= 1) for above

