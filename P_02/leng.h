// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 09/10/2022
// Archivo leng.h: Definición de la clase lenguaje.         
// Referencia:
// Historial de revisiones:
//       09/10/2022 - Creación (primera versión) del código.
//       10/10/2022 - Continuación del código.
//       11/10/2022 - Continuación del código.
//       12/10/2022 - Continuación del código.

#ifndef _CyA_P02_LENG_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P02_LENG_

#include "cad.h"

#include <vector>
#include <string>
#include <sstream>

class Leng {
  public:
    Leng(std::string);          // Constructor.
    Leng();

    int GetLength();
    Leng Concat(Leng, Leng);    // Concatenación de dos lenguajes.
    Leng Union(Leng, Leng);
    Leng Intersec(Leng, Leng);
    Leng Difer(Leng, Leng);
    Leng Invert(Leng);
    Leng Potencia(Leng, int);




    // Sobrecarga de operadores.
    friend std::ostream& operator << (std::ostream& os, Leng& leng_aux) {
      os << "{ ";
      // for(int i = 0; i < leng_aux.leng_.size(); i++) {
      // os << leng_aux.leng_[i] << " ";
      // }
      for(auto i: leng_aux.leng_) {
        os << i << " ";
      }
      os << "}";
    return os;  
    };

    // friend Leng operator * (Leng& leng1, Leng& leng2) {
    //   leng1.leng_[0] * leng2.leng_[0];
    // };

  private:
    std::set<Cad> leng_;
};

#endif