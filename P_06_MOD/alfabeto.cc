// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 07/11/2022
// Archivo alfabeto.cc: Implementación de la clase alfabeto.         
// Referencia:
// Historial de revisiones:
//       07/11/2022 - Creación (primera versión) del código.

#include "alfabeto.h"

void Alfabeto::SetAlf(std::string sim) {
  alf_.push_back(sim);
}

int Alfabeto::GetSize() {
  return alf_.size();
}

std::vector<std::string> Alfabeto::GetAlf() {
  std::vector<std::string> vec_aux;
  for (int i = 0; i < alf_.size(); i++) {
    vec_aux.push_back(alf_[i]);
  }
  return vec_aux;
}