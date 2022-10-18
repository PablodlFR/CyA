// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadoras de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo alf.h: Definición de la clase alfabeto.         
// Referencia:
// Historial de revisiones:
//       09/10/2022 - Creación (primera versión) del código.
//       10/10/2022 - Continuación del código.
//       11/10/2022 - Continuación del código.
//       12/10/2022 - Continuación del código.

#ifndef _CyA_P01_ALF_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P01_ALF_

#include "sim.h"
#include "fun_aux.h"

#include <vector>

class Alf {
  public:
    Alf(std::string);    // Constructor
    void PrintAlf();     // Método de prueba para imprimir por pantala un alfabeto.
  
  private:
    std::vector<Sim> alf_; 
};

#endif