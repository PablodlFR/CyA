// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 09/10/2022
// Archivo func_aux.cc: Implementación de funciones auxiliares.         
// Referencia:
// Historial de revisiones:
//       09/10/2022 - Creación (primera versión) del código.
//       10/10/2022 - Continuación del código.
//       11/10/2022 - Continuación del código.
//       12/10/2022 - Continuación del código.

#include "fun_aux.h"

std::string GetAlpString(std::string alp_string) {  
  alp_string.erase(alp_string.find(" }"));    // Borramos todo aquello desde el símbolo " }".
  alp_string.erase(0, 2);                     // Eliminamos los dos primeros caracteres que corresponden a "{ ".
  return alp_string;
}

std::string GetLengString(std::string leng_string) {
  std::string aux = leng_string;  
  aux.erase(leng_string.find(" { "));          // Borramos todo aquello desde el símbolo " { " Para obtener los caracteres que ocupa el alfabeto.
  leng_string.erase(0, aux.size() + 3);        // Eliminamos sobre la líne completa la parte del alfabeto.
  leng_string.erase(leng_string.find("}"));    // Finalmente eliminamos el último "}".

  return leng_string;
}