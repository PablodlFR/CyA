// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 19/11/2022
// Archivo grammar.cc: Definición de la clase grammar.         
// Referencia:
// Historial de revisiones:
//       19/11/2022 - Creación (primera versión) del código.
//       20/11/2022 - Continuación del código.
//       22/11/2022 - Continuación del código.

#ifndef _CyA_P08_GRAMMAR_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P08_GRAMMAR_

#include "alfabeto.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

class Grammar {
  public:
    void LoadGrammar(std::ifstream&);
    void PrintGrammar(std::ofstream&);
    void GrammarToCNF();

  private:
    int num_sim_ter_;                                           // Nº de símbolos terminales (alfabeto).
    int num_sim_no_ter_;                                        // Nº de símbolos no terminales.   
    std::set<std::string> set_sim_no_ter_;                      // Vector de símbolos no terminales.
    std::string start_sim_;                                     // Símbolo de arranque.
    Alfabeto alp_;                                              // Alfabeto de la gramática.
    std::set<std::pair<std::string,std::string>> set_prod_;     // Vector de pares de producciones de la gramática, first = parte izq de la producción, second = parte derecha de la producción.  
    // parte izquierda sim, derecha cadena.
};

#endif