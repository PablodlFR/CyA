// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo checkmain.h: Definición de la clase checkmain.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.

#ifndef _CyA_P04_MAIN_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P04_MAIN_

#include <iostream>
#include <fstream>
#include <regex>

class Main {
  public:
    void GetMain(std::ifstream&);
    void PrintMain(std::ofstream&);

  private:
    std::string main_ = "False";
};

#endif