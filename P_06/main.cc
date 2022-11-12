// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 05/11/2022
// Archivo main.cc: programa cliente.         
// Referencia:
// Historial de revisiones:
//       05/11/2022 - Creación (primera versión) del código.
//       06/11/2022 - Continuación del código.
//       07/11/2022 - Continuación del código.
//       08/11/2022 - Continuación del código.
//       09/11/2022 - Continuación del código.

#include "automata.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::ifstream fe_aut;       // Fichero de entrada con el autómata finito.
std::ifstream fe_cad;       // Fichero de entrada con las cadenas a probar.

std::string help, fich_line;
int cont_line = 1;
int cont_est_line = 1; // Contar las separaciones de la línea de un estado, ya que cada nº representa una cosa diferente.

int main (int argc, char *argv[]) {    
  help = argv[1];  
  if (help == "--help") {
    std::cout << "Modo correcto de ejecución: ./p06_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "input.fa: definición del autómata finito." << std::endl;
    std::cout << "input.txt: cadenas de entrada que leerá el autómata." << std::endl;
  } else if (argc < 3 || argc > 3) {
    std::cout << "ERROR. Ejecutado incorrectamente." << std::endl;
    std::cout << "Modo correcto de ejecución: ./p06_automata_simulator input.fa input.txt" << std::endl;
    std::cout << "Pruebe 'p06_automata_simulator --help' para más información" << std::endl;
  } 

  fe_aut.open(argv[1]);
  fe_cad.open(argv[2]);

  Automata test;  
  
  test.LoadAut(fe_aut);  // Cargar el autómata según los valores dados por el fichero de entrada.

  while (!fe_cad.eof()) {                
    while(getline(fe_cad, fich_line)) {
      std::cout << fich_line << " --- " << test.CheckCad(fich_line) << std::endl;   // Devuelve si dicha cadena es aceptada o no por el autómata.      
    }
  }

  fe_aut.close();
  fe_cad.close();
  return 0;
}
