pria(loid).
pria(faqih).
pria(todoroki).
pria(levi).
pria(william).
pria(razi).
pria(owen).
pria(zoro).
pria(fathur).
pria(chopper).

wanita(yor).
wanita(karina).
wanita(adinda).
wanita(karma).
wanita(tsunade).
wanita(ariana).
wanita(kawazake).
wanita(reze).
wanita(nezuko).
wanita(anya).
wanita(umaru).

usia(loid,135).
usia(yor,132).
usia(faqih,109).
usia(karina,97).
usia(todoroki,72).
usia(adinda,67).
usia(levi,69).
usia(karma,79).
usia(kawazake,37).
usia(william,45).
usia(razi,42).
usia(reze,35).
usia(umaru,16).
usia(chopper,8).
usia(tsunade,46).
usia(owen,64).
usia(zoro,57).
usia(ariana,52).
usia(nezuko,11).
usia(fathur,3).
usia(anya,7).

menikah(loid,yor). menikah(yor,loid).
menikah(faqih,karina). menikah(karina,faqih).
menikah(todoroki,adinda). menikah(adinda,todoroki).
menikah(adinda,levi). menikah(levi,adinda).
menikah(tsunade,owen). menikah(owen,tsunade).
menikah(zoro,ariana). menikah(ariana,zoro).
menikah(kawazake,william). menikah(william,kawazake).
menikah(razi,reze). menikah(reze,razi).

anak(karma,loid). anak(karma,yor).
anak(adinda,loid). anak(adinda,yor).
anak(owen,faqih). anak(owen,karina).
anak(ariana,faqih). anak(ariana,karina).
anak(william, todoroki). anak(william, adinda).
anak(razi,adinda). anak(razi, levi).
anak(nezuko,tsunade). anak(nezuko, owen).
anak(fathur,tsunade). anak(fathur, owen).
anak(anya, zoro).  anak(anya,ariana).
anak(umaru, kawazake). anak(umaru,william).
anak(chopper, razi). anak(chopper, reze).

saudara(X,Y):-anak(X,Z), anak(Y,Z), \+X=Y.
saudaratiri(X,Y):-anak(X,A), anak(Y,C), anak(X,B), anak(Y,B), \+A=C,\+A=B, \+B=C, \+X=Y.
sepupu(X,Y):-anak(X,A), anak(Y,B), saudara(A,B).
kakak(X,Y):-saudara(X,Y), usia(X,X_umur), usia(Y, Y_umur), X_umur > Y_umur.
keponakan(X,Y):-anak(X,A), saudara(A,Y).
mertua(X,Y):-anak(A,X), menikah(A,Y).
nenek(X,Y):-wanita(Y), anak(X,A), anak(A,Y).
keturunan(X,Y):-anak(X,Y).
keturunan(X,Y):-anak(X,A), anak(A,Y).
keturunan(X,Y):-anak(X,A), anak(A,B), anak(B,Y).
lajang(X):- pria(X), \+menikah(X,A).
lajang(X):- wanita(X), \+menikah(X,A).
anakbungsu(X):-kakak(A,X), \+saudaratiri(X,A).
anaksulung(X):-kakak(X,A), \+saudaratiri(X,A).
anaktunggal(X):- \+saudara(X,A).
yatimpiatu(X):- \+anak(X,A).


sumTon(0,0).
sumTon(X,Y):-
    X > 0,
    X1 is X - 1,
    sumTon(X1, Y1),
    Y is X + Y1.

countDigits(X,Y):-
    X < 10,
    Y is 1.

countDigits(X,Y):-
    X > 0,
    X1 is X//10,
    countDigits(X1,Y1),
    Y is Y1 + 1.



reverseNum(N, N):-
    N < 10.

reverseNum(N, X):-
    N >= 10,
    countDigits(N, Dn),
    Digit is N mod 10,
    N1 is N//10,
    reverseNum(N1, X1),
    Mul is 10 ** (Dn - 1),
    X is (Digit * Mul) + X1.

isPalindrom(N):-
    reverseNum(N, X),
    N = X.

palSteps(N,0):-
    isPalindrom(N).

palSteps(N, X):-
    \+isPalindrom(N),
    reverseNum(N, Nrev),
    N1 is N + Nrev,
    palSteps(N1, X1),
    X is X1 + 1.


digitPowerSum(N, N):-
    N < 10.

digitPowerSum(N, X):-
    N >= 10,
    countDigits(N, Dn),
    N1 is (N//(10 ** (Dn - 1))) * (10 ** (Dn - 1)),
    N2 is N - N1,
    Digit = N//(10 ** (Dn - 1)),
    digitPowerSum(N2, X1),
    X is X1 + Digit ** Dn.

safeBinary(1, 2).
safeBinary(2, 3).
safeBinary(N, X):-
    N1 is N - 1,
    safeBinary(N1, X1),
    N2 is N - 2,
    safeBinary(N2, X2),
    X is X1 + X2.

fact(0, 1).
fact(N, X):-
    N1 is N - 1,
    fact(N1,X1),
    X is X1 * N.

facthmm(N, X):-
    N mod 2 =:= 0,
    fact(N, X1),
    X is -X1.

facthmm(N, X):-
    N mod 2 =:= 1,
    fact(N, X1),
    X is X1.

altFactorial(1,1).

altFactorial(N,X):-
    N > 1,
    facthmm(N, Y),
    N1 is N - 1,
    altFactorial(N1, X1),
    X is Y + X1.

sumofDigits(N, N):-
    N < 10.

sumofDigits(N, X):-
    N >= 10,
    countDigits(N, Dn),
    Digit = N//(10 ** (Dn - 1)),
    N1 is N - Digit * (10 ** (Dn - 1)),
    sumofDigits(N1, X1),
    X is Digit + X1.


vaultTransform(Code, 0, Code).

vaultTransform(Code, K, FinalCode):-
    K > 0,
    reverseNum(Code, RevCode),
    sumofDigits(Code, SumDig),
    NextCode is RevCode + SumDig,
    K1 is K - 1,
    vaultTransform(NextCode, K1, NextAgainCode),
    FinalCode is NextAgainCode.


has_divisor(N, Divisor):-
    N mod Divisor =:= 0.

has_divisor(N, Divisor):-
    Divisor * Divisor < N,
    Next is Divisor + 1,
    has_divisor(N, Next).

prime(2).
prime(N):-
    N > 2,
    \+(has_divisor(N, 2)).

palPrime(N, M):-
    prime(N),
    isPalindrom(N),
    !,
    M is 1.

palPrime(N, M):-
    M is 0.

palPrimeCount(1,1,0).
palPrimeCount(1,B,X):-
    B > 1,
    palPrime(B,M),
    B1 is B - 1,
    palPrimeCount(1, B1, X1),
    X is X1 + M.

palPrimeCount(A,B,X):-
    palPrimeCount(1, A, X1),
    palPrimeCount(1, B, X2),
    X is X2 - X1.


habisbagi2(N, M):-
    N mod 2 =:= 0,
    M is 3.

habisbagi2(N,M):-
    \+(N mod 2 =:= 0),
    M is 0.

habisbagi5(N, M):-
    N mod 5 =:= 0,
    M is -4.

habisbagi5(N, M):-
    \+(N mod 5 =:= 0),
    M is 0.

prima(N, M):-
    prime(N),
    M is 2.

prima(N, M):-
    \+prime(N),
    M is 0.

kuadSempurna(N, M):-
    N =:= (round(sqrt(N)) * round(sqrt(N))),
    M is -1.

kuadSempurna(N, M):-
    \+(N =:= (round(sqrt(N)) * round(sqrt(N)))),
    M is 0.

towerJourney(N, Energy, 0):-
    Energy =< 0.

towerJourney(0, Energy, Energy).

towerJourney(N, Energy, FinalEnergy):-
    journey(1, N, Energy, FinalEnergy).

journey(X, Y, Energy, 0):-
    Energy =< 0.

journey(Sekarang, MaxRoom, Energy, Energy):-
    Sekarang > MaxRoom.

journey(Sekarang, MaxRoom, Energy, FinalEnergy):-
    Sekarang =< MaxRoom,
    Energy > 0,
    habisbagi2(Sekarang, M1),
    habisbagi5(Sekarang, M2),
    prima(Sekarang, M3),
    kuadSempurna(Sekarang, M4),

    NextEnergy is Energy + M1 + M2 + M3 + M4,
    NextRoom is Sekarang + 1,
    journey(NextRoom, MaxRoom, NextEnergy, NextE),
    FinalEnergy is NextE.


cetakSpasi(0).
cetakSpasi(N):-
    N > 0,
    N1 is N - 1,
    cetakSpasi(N1),
    write(' ').

cetakBarisKiri(N, N):-
    write(N),
    write(' ').

cetakBarisKiri(N, X):-
    N > X,
    X1 is X + 1,
    write(X),
    write(' '),
    cetakBarisKiri(N, X1).

cetakBarisKanan(N, N):-
    write(' '),
    write(N).

cetakBarisKanan(N, X):-
    N > X,
    X1 is X + 1,
    cetakBarisKanan(N, X1),
    write(' '),
    write(X).

cetakBaris(1):-
    write(1),
    nl.

cetakBaris(N):-
    N1 is N - 1,
    cetakBarisKiri(N1, 1),
    write(N),
    cetakBarisKanan(N1, 1),
    nl.

segitigaAtas(BarisKe, TinggiDia):-    
    BanyakSpasi is TinggiDia - 1 - (2 * (BarisKe - 1)),
    BanyakSpasi =:= 0,
    cetakBaris(BarisKe).

segitigaAtas(BarisKe, TinggiDia):-    
    BanyakSpasi is TinggiDia - 1 - (2 * (BarisKe - 1)),
    BanyakSpasi > 0,
    cetakSpasi(BanyakSpasi),
    cetakBaris(BarisKe),
    NextBaris is BarisKe + 1,
    segitigaAtas(NextBaris, TinggiDia).


segitigaBawah(BarisKe, TinggiDia):-    
    BanyakSpasi is TinggiDia - 1 - (2 * (BarisKe - 1)),
    BanyakSpasi =:= 0,
    cetakSpasi(2),
    cetakBaris(BarisKe).

segitigaBawah(BarisKe, TinggiDia):-    
    BanyakSpasi is TinggiDia - 1 - (2 * (BarisKe - 1)),
    BanyakSpasi > 0,
    NextBaris is BarisKe + 1,
    segitigaBawah(NextBaris, TinggiDia),
    cetakSpasi(BanyakSpasi),
    cetakSpasi(2),
    cetakBaris(BarisKe).


makeDiamond(N):-
    segitigaAtas(1, N),
    N1 is N - 2,
    segitigaBawah(1, N1).
    





cariMin([X], X).

cariMin([H|T], Min):-
    cariMin(T, MinTail),
    H < MinTail,
    Min is H.

cariMin([H|T], Min):-
    cariMin(T, MinTail),
    H >= MinTail,
    Min is MinTail.

cariMax([X], X).

cariMax([H|T], Max):-
    cariMax(T, MaxTail),
    H >= MaxTail,
    Max is H.

cariMax([H|T], Max):-
    cariMax(T, MaxTail),
    H < MaxTail,
    Max is MaxTail.

minMax([X], [Y], Max, Min):-
    Y is ((X - Min)/(Max - Min)).

minMax([H1|T1], [H2|T2], Max, Min):-
    minMax(T1, T2, Max, Min),
    H2 is ((H1 - Min)/(Max - Min)).
    
minMaxScaling(Input, Result):-
    cariMax(Input, Max),
    cariMin(Input, Min),
    minMax(Input, Result, Max, Min).


bukanKarbit([0], [0]).
bukanKarbit([1], [1]).
bukanKarbit([], []).

bukanKarbit([H1|T1], [H2|T2]):-
    H1 =:= 0,
    H2 is 0,
    bukanKarbit(T1, T2).

bukanKarbit([H1|T1], [H2|T2]):-
    H1 =:= 1,
    H2 is 1,
    bukanKarbit(T1, T2).

bukanKarbit([H1|T1], [H2|T2]):-
    bukanKarbit(T1, [H2|T2]).


pemusnahKarbit(Input, Result):-
    bukanKarbit(Input, Result).

countString(X, [], 0).

countString(X, [X|T], N):-
    countString(X,T,N1),
    N is N1 + 1.

countString(X, [H|T], N):-
    X \= H,
    countString(X, T, N).


simpanHasilCount([], [], [InputH2|InputT2]).

simpanHasilCount([HasilH|HasilT], [InputH1|InputT1], [InputH2|InputT2]):-
    countString(InputH1, [InputH2|InputT2], HasilH),
    simpanHasilCount(HasilT, InputT1, [InputH2|InputT2]).

cariYangMax([InputH|InputT], [CountH|CountT], Max, Hasil):-
    CountH =:= Max,
    Hasil = InputH.

cariYangMax([InputH|InputT], [CountH|CountT], Max, Hasil):-
    CountH \= Max,
    cariYangMax(InputT, CountT, Max, Hasil).

nambahString([], X, X):-!.
nambahString([A|B], C, [A|D]):-
    nambahString(B,C,D).

nambahStringNKali(Input, C, Result, N):-
    N =:= 1,
    nambahString(Input, [C], Result).

nambahStringNKali(Input, C, Result, N):-
    N > 1,
    N1 is N - 1,
    nambahString(Input, [C], ResultSelanjutnya),
    nambahStringNKali(ResultSelanjutnya, C, Result, N1).

fansBarcelona(Input, FanCount, Result):-
    simpanHasilCount(HasilCount, Input, Input),
    cariMax(HasilCount, Max),
    cariYangMax(Input, HasilCount, Max, Hasil),
    Hasil = "real madrid",
    nambahStringNKali(Input, "hater", Result, FanCount).


fansBarcelona(Input, FanCount, Result):-
    simpanHasilCount(HasilCount, Input, Input),
    cariMax(HasilCount, Max),
    cariYangMax(Input, HasilCount, Max, Hasil),
    Hasil \= "real madrid",
    nambahStringNKali(Input, Hasil, Result, FanCount).


