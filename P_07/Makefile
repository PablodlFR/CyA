p07_dfa2grammar: main.o automata.o estado.o alfabeto.o grammar.o
	g++ main.o automata.o estado.o alfabeto.o grammar.o -o p07_dfa2grammar

main.o: main.cc
	g++ -c main.cc

automata.o: automata.cc automata.h
	g++ -c automata.cc

estado.o: estado.cc estado.h
	g++ -c estado.cc

alfabeto.o: alfabeto.cc alfabeto.h
	g++ -c alfabeto.cc

grammar.o: grammar.cc grammar.h
	g++ -c grammar.cc

clean: 
	rm *.o p07_dfa2grammar