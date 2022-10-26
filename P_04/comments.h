// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo comments.h: Definición de la clase comments.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.
//       26/10/2002 - Continuación del código.

#ifndef _CyA_P04_COMMENTS_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P04_COMMENTS_

#include <iostream>
#include <fstream>
#include <regex>

class Comments {
  public:
    void GetComments(std::ifstream&);
    void PrintComments(std::ofstream&);
    void PrintDesciption(std::ofstream&);

  private:
    struct Data {
      int num_line = 1;
      int beg_com = 1;    // Comentarios multi-línea contar la línea en la que comienza y en la que finaliza.
      int end_com = 1;
      std::string comment;
      bool multi_line = false;
    };
    std::vector<Data> data_;
    std::string comments_;
    std::string description_;
};

#endif