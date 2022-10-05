// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 01/10/2022
// Archivo func_aux.cc: Implementación de funciones auxiliares.         
// Referencia:
// Historial de revisiones:
//       01/10/2022 - Creación (primera versión) del código.
//       02/10/2022 - Continuación del código.
//       03/10/2022 - Continuación del código.
//       04/10/2022 - Continuación del código.
//       05/10/2022 - Continuación del código.

#include "fun_aux.h"

std::string GetAlpString(std::string alp_string) {
  return alp_string.substr(0, alp_string.find_last_of(" "));
}

std::string GetCadString(std::string cad_string) {
  std::stringstream iss(cad_string);
  while(getline(iss, cad_string, ' '));   // Toma la última palabra de la línea, que corresponde a la cadena.
  return cad_string;
}