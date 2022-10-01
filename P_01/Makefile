P01: main.o cad.o
	g++ main.o cad.o -o P01

main.o: main.cpp
	g++ -c main.cpp

cad.o: cad.cpp cad.hpp
	g++ -c cad.cpp

clean: 
	rm *.o P01