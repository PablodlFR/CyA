// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 01/10/2022
// Archivo sim.h: Definición de la clase símbolo.         
// Referencia:
// Historial de revisiones:
//       01/10/2022 - Creación (primera versión) del código.
//       02/10/2022 - Continuación del código.
//       03/10/2022 - Continuación del código.
//       04/10/2022 - Continuación del código.
//       05/10/2022 - Continuación del código.

#ifndef _CyA_P01_SIM_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P01_SIM_

#include <iostream>

class Sim {
  public:
    Sim();                      // Constructor sin pasar parámetro.
    Sim(std::string);           // Constructor pasando una string.

    void SetSim(std::string);   // Setter de un símbolo mediante una string.
    std::string GetSim();       // Getter de un símbolo.

  private:
    std::string sim_;
};

#endif
