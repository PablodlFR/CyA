// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 01/10/2022
// Archivo cad.h: Definición de la clase cadena.         
// Referencia:
// Historial de revisiones:
//       01/10/2022 - Creación (primera versión) del código.
//       02/10/2022 - Continuación del código.
//       03/10/2022 - Continuación del código.
//       04/10/2022 - Continuación del código.
//       05/10/2022 - Continuación del código.

#ifndef _CyA_P01_CAD_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P01_CAD_

#include "sim.h"

#include <vector>
#include <string>
#include <iostream>
#include <set>

class Cad {
  public:
    Cad(std::string);           // Constructor.
      
    int GetLength();            // Obtiene longitud de la cadena.
    Cad Invert();               // Obtiene la inversa de la cadena.
    std::vector<Cad> Prefix();  // Obtiene todos los prefijos de una cadena.
    std::vector<Cad> Sufix();   // Obtiene todos los sufijos de una cadena.
    std::vector<Cad> SubCad();  // Obtiene todas las subcadenas de una cadena.
    void PrintCad();            // Método de prueba para imprimir por pantalla una cadena.

    bool es_palin();
  
    // Sobrecarga de operadores.
    friend std::ostream& operator << (std::ostream& os, Cad& aux) {
      for(int i = 0; i < aux.cad_.size(); i++) {
      os << aux.cad_[i].GetSim();
      }
    return os;  
    };

    // friend bool operator < (Cad& aux, Cad& aux2) {
    //   if(aux.GetLength() < aux2.GetLength()) {
    //     return true;
    //   }
    //   return false;
    // }

  private:
   std::vector<Sim> cad_;
};

#endif
