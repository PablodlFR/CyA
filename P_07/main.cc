// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramática Regular a partir de un DFA.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 12/11/2022
// Archivo main.cc: programa cliente.         
// Referencia:
// Historial de revisiones:
//       12/11/2022 - Creación (primera versión) del código.
//       13/11/2022 - Continuación del código.
//       14/11/2022 - Continuación del código.
//       16/11/2022 - Continuación del código.

#include "automata.h"
#include "grammar.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::ifstream fe_aut;       // Fichero de entrada con el autómata finito.
std::ofstream fo_gram;       // Fichero de entrada con las cadenas a probar.

std::string help, fich_line;

int main (int argc, char *argv[]) {    
  if (argc > 1) {
    help = argv[1];  
  }
  if (help == "--help") {
    std::cout << "Modo correcto de ejecución: ./p07_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "input.fa: definición del autómata finito." << std::endl;
    std::cout << "input.txt: cadenas de entrada que leerá el autómata." << std::endl;
    return 0;
  } else if (argc < 3 || argc > 3) {
    std::cout << "ERROR. Ejecutado incorrectamente." << std::endl;
    std::cout << "Modo correcto de ejecución: ./p06_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "Pruebe 'p06_automata_simulator --help' para más información" << std::endl;
    return 0;
  } 

  fe_aut.open(argv[1]);
  fo_gram.open(argv[2]);

  Automata aut_test;  
  Grammar gram_test;
  
  aut_test.LoadAut(fe_aut);  // Cargar el autómata según los valores dados por el fichero de entrada.
  gram_test.LoadGrammar(aut_test);
  gram_test.PrintGrammar(fo_gram);

  std::cout << gram_test.IsProduced("10") << std::endl;
  std::cout << gram_test.IsProduced("0101") << std::endl;

  fe_aut.close();
  fo_gram.close();
  return 0;
}
