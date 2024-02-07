p = input("p (0.05 <= p <= 0.95) = ")
for n = 1:3:100
  k = 0:n;
  y = binopdf(k, n, p)
  plot(k, y)
  pause(0.5)

endfor
