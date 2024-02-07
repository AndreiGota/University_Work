M = input("M= ") % mean of the normal law
sigma = input("Sigma= ")
alpha = input("Alpha= ") % between 0 and 1
beta = input("Beta= ") % between 0 and 1

%a)
p1 = normcdf(0, M, sigma)
%P(x >= 0) = 1 - P(x < 0) = (beacause is continuous) 1 - P(x <= 0)
p2 = 1 - normcdf(0, M, sigma)

%b)
p3 = normcdf(1, M, sigma) - normcdf(-1, M, sigma)
%P((x <= -1) or (x >= 1)) = 1 - P(-1 < x < 1)
p4 = 1 - normcdf(1, M, sigma) - normcdf(-1, M, sigma)

%c)
x_alpha = norminv(alpha, M, sigma)
x_beta = norminv(1 - beta, M, sigma)

