// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo statements.cc: Implementación de la clase statements.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.
//       26/10/2022 - Continuación del código.

#include "statements.h"

void Statements::GetStatements(std::ifstream& fe) {
  std::string string_aux;
  std::smatch matches;
  std::regex txt_line("(for|while) [(].*[)]");    // Cualquier línea que contenga un for o while y a continuación su declaración "(.*)" para evitar confundirlo con posibles comentarios.
  std::regex txt_par(" [(].*[)]");      
  int cont = 1;
  Data aux_data;        

  while (!fe.eof()) {
    while (getline(fe, string_aux)) {
      if (std::regex_search(string_aux, matches, txt_line)) {
        string_aux = matches[0];
        string_aux = std::regex_replace(string_aux, txt_par, "");  // Elimina la declaración del bucle, dejando solo su tipo (for o while).
        aux_data.num_line = cont;
        aux_data.type = "LOOP";
        aux_data.name = string_aux;
        data_.push_back(aux_data);
      }
      cont++;
    }
  }
}

void Statements::PrintStatements(std::ofstream& fo) {
  fo << "STATEMENTS: " << std::endl;
  for(int i = 0; i < data_.size(); i++) {
    fo << "[Line " << data_[i].num_line << "] " << data_[i].type << ": " << data_[i].name << std::endl;
  }
  fo << std::endl;
}