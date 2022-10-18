// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadoras de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo sim.cc: Implementación de la clase símbolo.         
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#include "sim.h"

Sim::Sim() {  

}

Sim::Sim(std::string new_sim) {
  sim_ = new_sim;
}

void Sim::SetSim(std::string new_sim) {
  sim_ = new_sim;
}

std::string Sim::GetSim() {
  return sim_;
}