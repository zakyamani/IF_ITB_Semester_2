apen([], X, X):-!.
apen([A|B], C, [A|D]):-apen(B,C,D).