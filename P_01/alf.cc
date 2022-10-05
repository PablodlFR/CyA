// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 01/10/2022
// Archivo alf.cc: Implementación de la clase alfabeto (alf.h).         
// Referencia:
// Historial de revisiones:
//       01/10/2022 - Creación (primera versión) del código.
//       02/10/2022 - Continuación del código.
//       03/10/2022 - Continuación del código.
//       04/10/2022 - Continuación del código.
//       05/10/2022 - Continuación del código.

#include "alf.h"

Alf::Alf(std::string alfabeto) {
  alfabeto = GetAlpString(alfabeto);
  for(int i = 0; i < alfabeto.size(); i++) {
    std::string aux = "";
    if(alfabeto[i] != ' ') {
     aux += alfabeto[i];
     alf_.push_back(aux);     
    }
  }
}

void Alf::PrintAlf() {
  std::cout << "{";
  for(int i = 0; i < alf_.size(); i++) {
    if( i < alf_.size() - 1) {
      std::cout << alf_[i].GetSim() << ", ";
    }    
    else {
      std::cout << alf_[i].GetSim() << "}" << std::endl;
    }
  }
}
