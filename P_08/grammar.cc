// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramáticas en Forma Normal de Chomsky.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 19/11/2022
// Archivo grammar.cc: Implementación de la clase grammar.         
// Referencia:
// Historial de revisiones:
//       19/11/2022 - Creación (primera versión) del código.
//       20/11/2022 - Continuación del código.
//       22/11/2022 - Continuación del código.

#include "grammar.h"

void Grammar::LoadGrammar(std::ifstream& fe_gram) {
  std::string fich_line;
  std::pair<std::string,std::string> prod; // Producción para posteriormente hacer un push en el vector de producciones vec_prod_  
  int cont_line = 1;                       // Contador de la línea por la que va el fichero, ya que cada una tiene un significado distinto.
  int cont_alp_size = 0;                   // Contador para recorrer correctamente todos los símbolos del alfabeto del fichero de entrada.
  int cont_sim_no_ter = 0;                 // Contador para recorrer correcamente todos los símbolos no terminales.  

  while (!fe_gram.eof()) {   
    while (getline(fe_gram, fich_line)) {  
      if (cont_line == 1) {                                             // Guardamos el tamaño del alfabeto de la gramática para así recorrer correctamente las líneas que forman el alfabeto.
        num_sim_ter_ = stoi(fich_line);
        cont_alp_size = num_sim_ter_;
      }
      if (cont_line > 1 && cont_alp_size >= 0) {                        // Guardamos cada uno de los símbolos terminales en el alfabeto.
        alp_.SetAlf(fich_line);
      }
      if (cont_line == 2 + num_sim_ter_) {                              // Guardamos el nº de símbolos no terminales que componen la gramática.
        num_sim_no_ter_ = stoi(fich_line);   
        cont_sim_no_ter = num_sim_no_ter_;    
      }
      if (cont_line > 2 + num_sim_ter_ && cont_sim_no_ter >= 0) {       // Guardamos en un set los símbolos no terminales.
        set_sim_no_ter_.insert(fich_line);
      }
      if (cont_line == 3 + num_sim_ter_ + num_sim_no_ter_) {            // Guardamos el símbolo de arranque.
        start_sim_ = fich_line;
      }
      if (cont_line >= 5 + num_sim_ter_ + num_sim_no_ter_) {            // Guardamos las produccines en un vector de pares.
        std::string fich_line_copy = fich_line;
        fich_line.erase(fich_line.begin() + 1, fich_line.end());                    // Separamos la primera parte de la producción y la guardamos.
        prod.first = fich_line;
        fich_line_copy.erase(fich_line_copy.begin(), fich_line_copy.begin() + 5);   // Separamos la segunda parte de la producción y la guardamos. 
        prod.second = fich_line_copy;

        set_prod_.insert(prod);
      } 
      cont_line ++;
      cont_alp_size --;
      cont_sim_no_ter --;
    }    
  }
}

void Grammar::PrintGrammar(std::ofstream& fo_gram) {
  std::vector<std::string> vec_alp;     // Vector donde se guarda el alfabeto.
  vec_alp = alp_.GetVecAlp();

  fo_gram << vec_alp.size() << std::endl;
  for (int i = 0; i < vec_alp.size(); i++) {
    fo_gram << vec_alp[i] << std::endl;
  }
  fo_gram << set_sim_no_ter_.size() << std::endl;
  for (std::set<std::string>::iterator it = set_sim_no_ter_.begin(); it != set_sim_no_ter_.end(); it++) {
    fo_gram << *it << std::endl;
  }
  fo_gram << start_sim_ << std::endl;
  fo_gram << set_prod_.size() << std::endl;   // El nº de producciones es igual al tamaño del conjunto de las producciones.
  for (std::set<std::pair<std::string,std::string>>::iterator it = set_prod_.begin(); it != set_prod_.end(); it++) {
    fo_gram << it->first << " -> " << it->second << std::endl;
  }
}

void Grammar::GrammarToCNF() {
  std::vector<std::string> vec_alp = alp_.GetVecAlp();     // Vector donde se guarda el alfabeto.
  std::vector<std::string> vec_prod_relized;               // Vector para contar las prodcciones ya realizadas y evitar que vuelvan a ocurrir.
  std::pair<std::string,std::string> prod;                 // Producción para posteriormente hacer un push en el vector de producciones vec_prod_ 

  // Comprobar que la gramática no tiene producciones unitarias ni vacías.
  for (std::set<std::pair<std::string,std::string>>::iterator it = set_prod_.begin(); it != set_prod_.end(); it++) {
    for (std::set<std::string>::iterator it2 = set_sim_no_ter_.begin(); it2 != set_sim_no_ter_.end(); it2++) {
      if (it->second == *it2) {    // Unitarias.
        std::cout << "No se puede pasar a forma normal de Chomsky ya que contiene producciones unitarias." << std::endl;
        exit (EXIT_FAILURE);
      }
      if (it->second == "&") {     // Vacías.
        std::cout << "No se puede pasar a forma normal de Chomsky ya que contiene producciones vacías." << std::endl;
        exit (EXIT_FAILURE);
      } 
    }    
  }
  
  std::string aux;  
  std::set<std::pair<std::string,std::string>> set_prod_aux;

  // Primer bucle del algoritmo.
  // Añade nuevas producciones para los símbolos terminales, del estilo A -> a.
  for (std::set<std::pair<std::string,std::string>>::iterator it = set_prod_.begin(); it != set_prod_.end(); it++) {
    if (it->second.size() >= 2) {
      for (int z = 0; z < it->second.size(); z++) {
        for (int x = 0; x < vec_alp.size(); x++) {
          if (std::string(1, it->second[z]) == vec_alp[x]) {
            prod.first = 'A' + x;
            prod.second = vec_alp[x];
            set_prod_.insert(prod); 
            set_prod_aux.insert(prod);            
          }
        }          
      }        
    }
  }

  // Sustituye las producciones creadas anteriormente en las ya existentes cuando corresponda. S -> aXbX ; S -> AXBX.
  for (std::set<std::pair<std::string,std::string>>::iterator it = set_prod_.begin(); it != set_prod_.end(); it++) {
    if (it->second.size() >= 2) {
      aux = it->second;
      std::string aux2 = aux;
      for (std::set<std::pair<std::string,std::string>>::iterator it2 = set_prod_aux.begin(); it2 != set_prod_aux.end(); it2++) {  
        if (aux.find(it2->second) != std::string::npos) {
          aux.replace(aux.find(it2->second), it2->second.length(), it2->first);
        }           
      }
      set_prod_.erase(it);

      prod.first = it->first;
      prod.second = aux;  
      set_prod_.insert(prod); 
    }
  }

int cont = 0;
set_prod_aux.clear();

  // Segundo bucle del algoritmo.
 for (std::set<std::pair<std::string,std::string>>::iterator it = set_prod_.begin(); it != set_prod_.end(); it++) {
    if (it->second.size() >= 3) {
      aux = it->second;
      while (aux.size() > 2) {
        prod.first = 'F' + cont;
        prod.second = aux.substr(aux.length() - 2);   // Guardamos los 2 últimos simbolos no terminales que serían los de la nueva producción.
        set_prod_aux.insert(prod);

        aux.erase(aux.begin() + aux.length() - 2, aux.end()); // Borramos los dos últimos simbolos no terminales.
        aux += 'F' + cont;

        prod.first = it->first;
        prod.second = aux;
      
        cont++;
      }
      set_prod_aux.insert(prod);
    }
    else {
      set_prod_aux.insert(*it);
    }
  }
  set_prod_ = set_prod_aux;  

  // Recorremos el set de producciones para añadir aquellos nuevos símbolos no terminales al set de símbolos no terminales.
  for (std::set<std::pair<std::string,std::string>>::iterator it = set_prod_.begin(); it != set_prod_.end(); it++) {
    set_sim_no_ter_.insert(it->first);
  }
}