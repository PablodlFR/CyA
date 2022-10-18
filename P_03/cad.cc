// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadoras de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 09/10/2022
// Archivo cad.cc: Implementación de la clase cadena.         
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#include "cad.h"

Cad::Cad(std::string new_cad) {  
  for(int i = 0; i < new_cad.size(); i++) {
    std::string aux = "";
    aux += new_cad[i];
    cad_.push_back(aux);    
  } 
}

void Cad::PrintCad() {
  for(int i = 0; i < cad_.size(); i++) {
    std::cout << cad_[i].GetSim();
  }
  std::cout << std::endl;
}

int Cad::GetLength() {
  return cad_.size();
}

Cad Cad::Invert() {
  Sim sim_aux;
  Cad cad_aux("");
  for(int i = GetLength() - 1; i >= 0; i--) {
    cad_aux.cad_.push_back(cad_[i]);
  }
  return cad_aux;
}

std::vector<Cad> Cad::Prefix() {     
  std::vector<Cad> vec_cad_aux;
  std::string string_aux;
  Cad cad_aux("&");
  vec_cad_aux.push_back(cad_aux);
  cad_aux.cad_.clear();
  
  cad_aux.cad_.resize(GetLength() + 1); // Dar tamaño al vector para evitar segmentation fault, el número de cadenas totales de un prefijo siempre es el nº de simbolos de la cadena + 1 (cadena vacía).

  for(int i = 0; i < GetLength(); i++) {
    string_aux += cad_[i].GetSim();
    cad_aux.cad_.push_back(string_aux);    
    vec_cad_aux.push_back(cad_aux);
    cad_aux.cad_.clear();
  }
  return vec_cad_aux;
}

std::vector<Cad> Cad::Sufix() {
  std::vector<Cad> vec_cad_aux;
  std::string string_aux;
  Cad cad_aux("&");
  vec_cad_aux.push_back(cad_aux);
  cad_aux.cad_.clear();

  cad_aux.cad_.resize(GetLength() + 1); // Dar tamaño al vector para evitar segmentation fault, el número de cadenas totales de un prefijo siempre es el nº de simbolos de la cadena + 1 (cadena vacía).

  for(int i = GetLength() - 1; i >= 0; i--) {
    string_aux = cad_[i].GetSim() + string_aux;
    cad_aux.cad_.push_back(string_aux);
    vec_cad_aux.push_back(cad_aux);
    cad_aux.cad_.clear();
  }  
  return vec_cad_aux;
}

std::vector<Cad> Cad::SubCad() {
  std::vector<Cad> vec_cad_aux;
  std::string string_aux;
  Cad cad_aux("&");
  vec_cad_aux.push_back(cad_aux);
  cad_aux.cad_.clear();

  for(int i = 0; i < GetLength(); i++) {
    string_aux = "";    
    for(int j = i; j < GetLength(); j++) {
      string_aux += cad_[j].GetSim();
      cad_aux.cad_.push_back(string_aux);
      vec_cad_aux.push_back(cad_aux);
      cad_aux.cad_.clear();
    }
  }
  return vec_cad_aux; 
}
