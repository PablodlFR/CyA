// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadoras de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo alf.cc: Implementación de la clase alfabeto (alf.h).         
// Referencia:
// Historial de revisiones:
//       09/10/2022 - Creación (primera versión) del código.
//       10/10/2022 - Continuación del código.
//       11/10/2022 - Continuación del código.
//       12/10/2022 - Continuación del código.

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
