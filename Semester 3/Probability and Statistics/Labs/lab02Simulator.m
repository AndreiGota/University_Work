%number of simulation
N = input("Number  of simulations: ")
U = rand(3, N)
Y = (U < 0.5)
X = sum(Y)

clf
hist(X)
