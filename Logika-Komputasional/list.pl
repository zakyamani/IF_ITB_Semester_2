
baca_file_mahasiswa :-
    open('mahasiswa.txt', read, Stream),
    baca_ke_list(Stream, ListHasil),
    close(Stream),
    write('List Mahasiswa: '), write(ListHasil), nl.


baca_ke_list(Stream, []) :-
    at_end_of_stream(Stream), !. 
    

baca_ke_list(Stream, [Nama | SisaList]) :-
    \+ at_end_of_stream(Stream), 
    read(Stream, Nama),          
    baca_ke_list(Stream, SisaList).