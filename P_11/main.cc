// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Cambio de Monedas.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 16/12/2022
// Archivo main.cc: programa cliente.         
// Referencia:
// Historial de revisiones:
//       16/12/2022 - Creación (primera versión) del código.
//       20/12/2022 - Continuación del código.

#include "cam.h"

#include <iostream>

int main(int argc, char *argv[]) {  
  Cam test;
  if (argc == 1) {
    std::cout << "ERROR. Ejecutado incorrectamente." << std::endl;
    std::cout << "Pruebe 'p11 --help' para más información." << std::endl;
    return -1;
  }
  else if (argc == 2) {           // No tiene opciones por línea de comandos. Ejecución normal.
    if (std::string(argv[1]) == "--help") {
      std::cout << "Modo correcto de ejecución: ./p11 cantidad" << std::endl;
      std::cout << "Opción: -b. Usa tanto monedas como billetes." << std::endl;
      std::cout << "        -o. Usa un algoritmo más eficiente." << std::endl;
      return 0;
    }   
    test.devolver_cambio(atof(argv[1]));    
  } else if (argc >= 3) {     // Tiene una opción por línea de comandos.
    if (std::string(argv[1]) == "-b") {
      test.devolver_cambio_b(atof(argv[2]));
    }
    else if (std::string(argv[1]) == "-o") {
      test.devolver_cambio_o(atof(argv[2]));
    }  
    else {
      std::cout << "ERROR. Ejecutado incorrectamente." << std::endl;
      std::cout << "Pruebe 'p11 --help' para más información." << std::endl;
      return -1;
    }  
  }
  test.imprimir_cambio();
  return 0;
}