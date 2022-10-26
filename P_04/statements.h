// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo statements.h: Definición de la clase statements.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.
//       26/10/2022 - Continuación del código.

#ifndef _CyA_P04_STATEMENTS_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P04_STATEMENTS_

#include <iostream>
#include <fstream>
#include <regex>

class Statements {
  public:
    void GetStatements(std::ifstream&);      // Obtener los bucles según la expresión regular correspondiente sobre el fichero pasado por parámetro.
    void PrintStatements(std::ofstream&);    

  private:
    struct Data {
      int num_line = 1;
      std::string type;
      std::string name;
    };    
    std::vector<Data> data_;   
};

#endif