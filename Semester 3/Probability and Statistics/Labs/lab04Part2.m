%2 b)
n = input("nr of trials ");
p = input("nr probability ");
N = input("nr of simulations ");

U = rand(n, N);
X = sum(U < p);

k = 0:n;
p_k = binopdf(k, n, p);
U_X = unique(X);
N_X = hist(X, length(U_X));
rel_freq = N_X/N
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')
