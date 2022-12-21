// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 19/11/2022
// Archivo main.cc: programa cliente.         
// Referencia:
// Historial de revisiones:
//       19/11/2022 - Creación (primera versión) del código.

#include "grammar.h"

#include <iostream>
#include <fstream>

std::ifstream fe_gram;       // Fichero de entrada con la gramática.
std::ofstream fo_gram;       // Fichero de salida con la gramática en forma normal de chomsky.

std::string help, fich_line;

int main (int argc, char *argv[]) {    
  if (argc > 1) {
    help = argv[1];  
  }
  if (help == "--help") {
    std::cout << "Modo correcto de ejecución: ./p08_grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "input.gra: introduce la gramática que desea transformar en la forma normal de chomsky." << std::endl;
    std::cout << "output.gra: fichero de salida de la gramática en forma normal de chomsky." << std::endl;
    return 0;
  } else if (argc < 3 || argc > 3) {
    std::cout << "ERROR. Ejecutado incorrectamente." << std::endl;
    std::cout << "Modo correcto de ejecución: ./p08_grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "Pruebe 'p08_grammar2CNF --help' para más información" << std::endl;
    return 0;
  } 

  fe_gram.open(argv[1]);
  fo_gram.open(argv[2]);

  Grammar gram_test;

  gram_test.LoadGrammar(fe_gram);
  gram_test.GrammarToCNF();
  gram_test.PrintGrammar(fo_gram); 

  fe_gram.close();
  fo_gram.close();
  return 0;
}
