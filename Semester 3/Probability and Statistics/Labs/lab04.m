%2 a)
N = input("nr of simulations ");
p = input("probability between 0 and 1 ");

U = rand(1, N);
X = (U < p);

U_X = [0, 1];
N_X = hist(X, length(U_X));
rel_freq = N_X/N
