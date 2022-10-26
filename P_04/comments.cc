// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo comments.cc: implementación de la clase comments.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.
//       26/10/2022 - Continuación del código.

#include "comments.h"

void Comments::GetComments(std::ifstream& fe) {
  std::string string_aux;
  std::smatch matches;
  std::regex txt_line("// .*");         // Comentarios de una sola línea.
  std::regex txt_line2("/[*].*|.*[*]/");    // Comentarios multilínea.
  int cont = 1;
  Data aux_data;
  
  while (!fe.eof()) {
     while (getline(fe, string_aux)) {
      if (std::regex_search(string_aux, matches, txt_line2)) {
        string_aux = matches[0];
        aux_data.beg_com = cont;
        aux_data.comment = string_aux + "\n";
        while (getline(fe, string_aux) && std::regex_search(string_aux, matches, txt_line2) == 0) {
          aux_data.comment += string_aux + "\n";
          cont++;
        }
        cont++;       // Para contar también el cierre del comentario -> "*/"
        aux_data.end_com = cont;
        string_aux = matches[0];
        aux_data.comment += string_aux + "\n";
        aux_data.multi_line = true;
        data_.push_back(aux_data);
      }
    }
  }

  fe.clear();
  fe.seekg(0);
  cont = 1;  

  // Bucle para comentarios de una sola linea.
  while (!fe.eof()) {
    while (getline(fe, string_aux)) {
      if (std::regex_search(string_aux, matches, txt_line)) {
        string_aux = matches[0];
        aux_data.num_line = cont;
        aux_data.comment = string_aux;
        aux_data.multi_line = false;
        data_.push_back(aux_data);        
      }
      cont ++;
    }
  }
}

void Comments::PrintDesciption(std::ofstream& fo) {
 fo << "DESCRIPTON: " << std::endl;
 fo << data_[0].comment << std::endl;
}

void Comments::PrintComments(std::ofstream& fo) { 
  fo << "COMMENTS: " << std::endl;
 for (int i = 0; i < data_.size(); i++) {
    if (i < 1) {  // Imprime solo el primer comentario, que es siempre la descripción.
      if (data_[i].multi_line == true) {    // Comprueba si es un comentario multilínea para imprimirlo con otro formato.
      fo << "[Line " << data_[i].beg_com << "-" << data_[i].end_com << "] DESCRIPTION" << std::endl;
    } else {
      fo << "[Line " << data_[i].num_line << "] DESCRIPTION" << std::endl;  
    }
    }   
    
    if (i > 0) {  // Imprime a partir del segundo comentario, ya que el primero es la descripción.
      if (data_[i].multi_line == true) {    // Comprueba si es un comentario multilínea para imprimirlo con otro formato.
      fo << "[Line " << data_[i].beg_com << "-" << data_[i].end_com << data_[i].comment << std::endl;
      } else {
        fo << "[Line " << data_[i].num_line << "] " << data_[i].comment << std::endl;
      }      
    }    
  }
}