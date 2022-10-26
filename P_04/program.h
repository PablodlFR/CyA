// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo program.h: Definición de la clase program.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.

#ifndef _CyA_P04_PROGRAM_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P04_PROGRAM_

#include <iostream>
#include <fstream>
#include <regex>

class Program {
  public:
    void GetProgram(char*);
    void PrintProgram(std::ofstream&);

  private:
    std::string program_;
};

#endif