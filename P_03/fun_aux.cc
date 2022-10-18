// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo func_aux.cc: Implementación de funciones auxiliares.         
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#include "fun_aux.h"

std::string GetAlpString(std::string alp_string) {  
  alp_string.erase(alp_string.find(" }"));            // Borramos todo aquello desde el símbolo " }".
  alp_string.erase(0, 2);                             // Eliminamos los dos primeros caracteres que corresponden a "{ ".
  return alp_string;
}

std::string GetLengString(std::string leng_string) {  
  int cont = 0;                                           // Contar el nº de veces que aparece el carácter ',' y así eliminarlo posteriormente.
  leng_string.erase(0, leng_string.find("{") + 1);        // .find() devuelve un int, de la posición de la string donde se encuentra la string pasada por parámetro.
  leng_string.erase(leng_string.find("}"));
  for(int i = 0; i < leng_string.size(); i++) {           // Recorremos todo el string, buscando cuantas veces se repite ','.
    if(leng_string[i] == ',') {
      cont++;
    }
  }
  for(int i = 0; i < cont; i++) {                         // Eliminamos todas las ','.
    leng_string.erase(leng_string.find(","), 1);
  }
  return leng_string;
}

std::string GetIdString(std::string id_string) {
  id_string.erase(id_string.find(" "));                   // Elimina todo aquello despues del primer " ", dejando solo su identificador.
  return id_string;
}