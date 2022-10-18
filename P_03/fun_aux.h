// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Operaciones con lenguajes.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo func_aux.h: Definición de funciones auxiliares.         
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#ifndef _CyA_P02_FUNC_AUX_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P02_FUNC_AUX_

#include "leng.h"

#include <string>
#include <sstream>

std::string GetAlpString(std::string);                // Obtiene la parte del fichero que correspondería al alfabeto.
std::string GetLengString(std::string);               // Obtiene la parte del fichero que correspondería al lenguaje.
std::string GetIdString(std::string);                 // Obtiene la parte de la línea del fichero correspondiente a la id del lenguaje.

#endif