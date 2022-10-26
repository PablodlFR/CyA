// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo checkmain.cc: Implementación de la clase checkmain.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.

#include "checkmain.h"

void Main::GetMain(std::ifstream& fe) {
  std::string string_aux;
  std::regex txt_line("int main [(].*[)]");

  while (!fe.eof()) {
    while (getline(fe, string_aux)) {
      if (std::regex_search(string_aux, txt_line)) {
        main_ = "True\n";        
      }
    }
  }  
}

void Main::PrintMain(std::ofstream& fo) {
  fo << "MAIN: " << std::endl;
  fo << main_ << std::endl;
}