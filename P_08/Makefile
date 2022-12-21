p08_grammar2CNF: main.o alfabeto.o grammar.o
	g++ main.o alfabeto.o grammar.o -o p08_grammar2CNF

main.o: main.cc
	g++ -c main.cc

alfabeto.o: alfabeto.cc alfabeto.h
	g++ -c alfabeto.cc

grammar.o: grammar.cc grammar.h
	g++ -c grammar.cc

clean: 
	rm *.o p08_grammar2CNF