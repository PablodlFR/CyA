// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo variables.cc: Implementación de la clase variables.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.
//       26/10/2022 - Continuación del código.

#include "variables.h"

void Variables::GetVariables(std::ifstream& fe) {
  std::string string_aux;
  std::smatch matches;
  std::regex txt_line("[^(](int|double).*");       // Cualquier línea que tenga "int" pero sin que tenga "(" para así diferenciarlo de otras declaraciones como bucles o parámetros.
  std::regex txt_var_int("int *");  
  std::regex txt_var_double("double *");
  std::regex txt_pyc(";");
  int cont = 1;
  Data aux_data;

  while (!fe.eof()) {                
    while (getline(fe, string_aux)) {       
      if (std::regex_search(string_aux, matches, txt_line)) {              // Busca aquella líneas que cumpla txt_line. se guarda el resultado en matches.
        string_aux = matches[0];
        if (std::regex_search(string_aux, txt_var_int)) {
          string_aux = std::regex_replace(string_aux, txt_var_int, "");    // Elimina la parte donde se declara el tipo de variable, en este caso int.
          string_aux = std::regex_replace(string_aux, txt_pyc, "");        // Elimina el ";" del final de la sentencia. 
          aux_data.num_line = cont;
          aux_data.type = "INT";
          aux_data.name = string_aux;
          data_.push_back(aux_data);
        } else if (std::regex_search(string_aux, txt_var_double)) {
          string_aux = std::regex_replace(string_aux, txt_var_double, "");    
          string_aux = std::regex_replace(string_aux, txt_pyc, "");  
          aux_data.num_line = cont;
          aux_data.type = "DOUBLE";
          aux_data.name = string_aux;
          data_.push_back(aux_data);
        }        
      }     
      cont++;
    }
  }    
}

void Variables::PrintVariables(std::ofstream& fo) {
  fo << "VARIABLES: " << std::endl;
  for(int i = 0; i < data_.size(); i++) {
    fo << "[Line " << data_[i].num_line << "] " << data_[i].type << ": " << data_[i].name << std::endl;
  }
  fo << std::endl;
}