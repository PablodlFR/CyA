p06_automata_simulator: main.o automata.o estado.o alfabeto.o
	g++ main.o automata.o estado.o alfabeto.o -o p06_automata_simulator

main.o: main.cc
	g++ -c main.cc

automata.o: automata.cc automata.h
	g++ -c automata.cc

estado.o: estado.cc estado.h
	g++ -c estado.cc

alfabeto.o: alfabeto.cc alfabeto.h
	g++ -c alfabeto.cc

clean: 
	rm *.o p06_automata_simulator