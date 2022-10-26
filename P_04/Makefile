p04_code_analyzer: main.o program.o variables.o statements.o checkmain.o comments.o func_aux.o
	g++ main.o program.o variables.o statements.o checkmain.o comments.o func_aux.o -o p04_code_analyzer

main.o: main.cc
	g++ -c main.cc

program.o: program.cc program.h
	g++ -c program.cc

variables.o: variables.cc variables.h
	g++ -c variables.cc

statements.o: statements.cc statements.h
	g++ -c statements.cc

checkmain.o: checkmain.cc checkmain.h
	g++ -c checkmain.cc

comments.o: comments.cc comments.h
	g++ -c comments.cc

func_aux.o: func_aux.cc func_aux.h
	g++ -c func_aux.cc

clean: 
	rm *.o p04_code_analyzer