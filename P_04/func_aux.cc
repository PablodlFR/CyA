// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 26/10/2022
// Archivo func_aux.h: Implementación de las funciones auxiliares.         
// Referencia:
// Historial de revisiones:
//       26/10/2022 - Creación (primera versión) del código.

#include "func_aux.h"

void RestFich(std::ifstream& fe) {
  fe.clear();
  fe.seekg(0);
}