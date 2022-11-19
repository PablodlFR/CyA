// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 05/11/2022
// Archivo estado.cc: Implementación de la clase estado.         
// Referencia:
// Historial de revisiones:
//       05/11/2022 - Creación (primera versión) del código.
//       06/11/2022 - Continuación del código.
//       07/11/2022 - Continuación del código.
//       08/11/2022 - Continuación del código.
//       09/11/2022 - Continuación del código.

#include "estado.h"

void Estado::SetId(std::string id) {
  id_ = id;
}

void Estado::SetAccept(std::string accept) {
  if (accept == "1") {
    accept_ = true;
  } else if (accept == "0") {
    accept_ = false;
  }
}

void Estado::SetNumTrans(int num_trans) {
  num_trans_ = num_trans;
}

void Estado::SetTrans(std::pair<std::string,std::string> trans) {
  vec_trans_.push_back(trans);
}

void Estado::ClearTrans() {
  vec_trans_.clear();
}

std::string Estado::GetId() {
  return id_;
}

std::vector<std::string> Estado::GetTrans(std::string sim) {
  std::vector<std::string> vec_aux;
  for(int i = 0; i < vec_trans_.size(); i++) {
    std::string aux;  
    if (vec_trans_[i].first == sim) { 
      vec_aux.push_back(vec_trans_[i].second);  
    } 
  }
  return vec_aux;
}

bool Estado::GetAccept() {
  return accept_;
}

std::vector<std::pair<std::string,std::string>> Estado::GetVecTrans() {
  return vec_trans_;
}

int Estado::GetNumTrans() {
  return num_trans_;
}