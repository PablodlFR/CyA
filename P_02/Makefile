P02: main.o cad.o alf.o sim.o leng.o fun_aux.o
	g++ main.o cad.o alf.o sim.o leng.o fun_aux.o -o P02

main.o: main.cc
	g++ -c main.cc

cad.o: cad.cc cad.h
	g++ -c cad.cc

alf.o: alf.cc cad.h
	g++ -c alf.cc

sim.o: sim.cc sim.h
	g++ -c sim.cc

leng.o: leng.cc leng.h
	g++ -c leng.cc

fun_aux.o: fun_aux.cc fun_aux.h
	g++ -c fun_aux.cc

clean: 
	rm *.o P02