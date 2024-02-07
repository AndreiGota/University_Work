%2 c)
p = input("probability of success ");
N = input("nr of simulations ");
x = [0*N];
for i = 1:N
  x(i) = 0;
  while rand() >= p
    x(i) = x(i) + 1;
  endwhile
endfor

k = [0:20];
p_k = geopdf(k, p);
U_X = unique(x);
N_X = hist(x, length(U_X));
rel_freq = N_X/N
clf
plot(U_X, rel_freq, '*', k, p_k, 'ro')

