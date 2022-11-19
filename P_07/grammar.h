// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramática Regular a partir de un DFA.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 12/11/2022
// Archivo grammar.h: Definición de la clase grammar.         
// Referencia:
// Historial de revisiones:
//       12/11/2022 - Creación (primera versión) del código.
//       13/11/2022 - Continuación del código.
//       14/11/2022 - Continuación del código.
//       16/11/2022 - Continuación del código.

#ifndef _CyA_P07_GRAMMAR_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P07_GRAMMAR_

#include "automata.h"

#include <string>

class Grammar {
  public:
    void LoadGrammar(Automata);
    void PrintGrammar(std::ofstream&);
    bool IsProduced(std::string); // MODIFICACIÓN.

  private:
    int num_sim_ter_;                       // Nº de símbolos terminales (alfabeto).
    int num_sim_no_ter_;                    // Nº de símbolos no terminales.
    int num_prod_ = 0;
    std::vector<std::string> sim_no_ter;    // Vector que contiene las ids de los símbolos no terminales.
    Alfabeto alp_;
    std::string start_sim_;    // Símbolo de arranque.
    std::string accept_sim_;
    std::vector<std::pair<std::string,std::string>> vec_prod_; // Vector que contiene las producciones. Primer elemento, parte izquierda de la producción. Segundo elemento, parte derecha de la producción.
};

#endif