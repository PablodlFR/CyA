// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 07/11/2022
// Archivo alfabeto.cc: Definición de la clase alfabeto.         
// Referencia:
// Historial de revisiones:
//       07/11/2022 - Creación (primera versión) del código.

#ifndef _CyA_P06_ALFABETO_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P06_ALFABETO_

#include <vector>
#include <string>

class Alfabeto {
  public:
    void SetAlf(std::string);

  private:
    std::vector<std::string> alf_;
};

#endif