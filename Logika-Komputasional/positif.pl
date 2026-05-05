
p(0, positif).

p(N, positif):- N1 is N - 1, p(N1, positif).
p(N, negatif):- \+(p(N, positif)).