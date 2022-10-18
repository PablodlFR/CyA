// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadoras de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo sim.h: Definición de la clase símbolo.         
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#ifndef _CyA_P01_SIM_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P01_SIM_

#include <iostream>

class Sim {
  public:
    Sim();                      // Constructor sin pasar parámetro.
    Sim(std::string);           // Constructor pasando una string.

    void SetSim(std::string);   // Setter de un símbolo mediante una string.
    std::string GetSim();       // Getter de un símbolo.

    bool operator < (Sim& sim_aux) {
      return sim_ < sim_aux.sim_;
    }

  private:
    std::string sim_;
};

#endif
