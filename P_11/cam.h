// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Cambio de Monedas.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 16/12/2022
// Archivo cam.cc: definición de la clase cambio.         
// Referencia:
// Historial de revisiones:
//       16/12/2022 - Creación (primera versión) del código.
//       20/12/2022 - Continuación del código.

#ifndef _CyA_P11_CAMBIO_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P11_CAMBIO_

#include <vector>
#include <set>

class Cam {
  public:
    void devolver_cambio(float);
    void imprimir_cambio();
    void devolver_cambio_b(float);    // Considerando tanto monedas como billetes. Opción -b.
    void devolver_cambio_o(float);    // Algoritmo más eficiente. Opción -o.

  private:
    std::vector<int> monedas_ = {200, 100, 50, 20, 10, 5, 2, 1};
    std::vector<int> bil_mon_ = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    std::multiset<int> sol_;
};

#endif