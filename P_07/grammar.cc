// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramática Regular a partir de un DFA.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 12/11/2022
// Archivo grammar.cc: Implementación de la clase grammar.         
// Referencia:
// Historial de revisiones:
//       12/11/2022 - Creación (primera versión) del código.
//       13/11/2022 - Continuación del código.
//       14/11/2022 - Continuación del código.
//       16/11/2022 - Continuación del código.

#include "grammar.h"

void Grammar::LoadGrammar(Automata aut) {
  std::vector<Estado> vec_est;

  if (aut.CheckAut() == false) {
    std::cout << "ERROR. No se puede generar la grmática, ya que se trata de un NFA.";
    exit (EXIT_FAILURE);
  }

  alp_ = aut.GetAlp();                  // Guardamos como atributo privado el alfabeto, que es el mismo que el del autómata.
  start_sim_ = aut.GetStart();
  accept_sim_ = aut.GetEstAcc();

  num_sim_ter_ = alp_.GetSize();        // El nº de símbolos terminarles, corresponde con el tamaño del alfabeto.
  num_sim_no_ter_ = aut.GetNumEst();    // El nº de símbolos no terminales, corresponde al nº de estados del DFA. 
  vec_est = aut.GetVecEst();   
  for (int i = 0; i < vec_est.size(); i++) {
    sim_no_ter.push_back(vec_est[i].GetId());
  }         
  std::vector<std::pair<std::string,std::string>> vec_trans;
  std::pair<std::string,std::string> prod;
 
  for (int i = 0; i < vec_est.size(); i++) {
    num_prod_ += vec_est[i].GetNumTrans();
    vec_trans = vec_est[i].GetVecTrans();
    for (int j = 0; j < vec_trans.size(); j++) {
      prod.first = vec_est[i].GetId();
      prod.second = vec_trans[j].first + vec_trans[j].second;
      vec_prod_.push_back(prod);
    }
    if (vec_est[i].GetAccept() == 1) {    // Si el estado es de aceptación, siempre tiene una producción con la cadena vacía.
      prod.first = vec_est[i].GetId();
      prod.second = "&";
      vec_prod_.push_back(prod);
      num_prod_++; // Sumamos una produción.      
    }
  }          
}

void Grammar::PrintGrammar(std::ofstream& fo_gram) {
  std::vector<std::string> vec_alp;     // Vector donde se guarda el alfabeto.
  vec_alp = alp_.GetVecAlp();

  fo_gram << num_sim_ter_ << std::endl;
  for (int i = 0; i < vec_alp.size(); i++) {
    fo_gram << vec_alp[i] << std::endl;
  }

  fo_gram << num_sim_no_ter_ << std::endl;
  for (int i = 0; i < sim_no_ter.size(); i++) {
    fo_gram << sim_no_ter[i] << std::endl;
  }
  fo_gram << start_sim_ << std::endl;
  fo_gram << num_prod_ << std::endl;
  for (int i = 0; i < vec_prod_.size(); i++) {
    fo_gram << vec_prod_[i].first << " -> " << vec_prod_[i].second << std::endl;
  }
}

bool Grammar::IsProduced(std::string str) {   // MODIFICACIÓN.
  int j = 0;
  std::string aux;
  std::pair<std::string,std::string> prod_aux, prod_aux2;
  for (int i = 0; i < vec_prod_.size(); i++) {
    if (vec_prod_[i].first == start_sim_) {
      prod_aux = vec_prod_[i];       
    }
  }
    while (j < str.size()) {   
      aux = "";                      // Limpiamos aux.
      aux.append(1, str[j]);         // Pasa un char de cad a string y lo guarda en aux.
      for (int i = 0; i < vec_prod_.size(); i++) {
        if (vec_prod_[i].first == prod_aux.first && vec_prod_[i].second.at(0) == str[j]) {
          prod_aux2.first = vec_prod_[i].second.at(1);           
           
        }
      }
      prod_aux.first = prod_aux2.first;
      
    j++;
  }
  if (prod_aux.first == accept_sim_) {
    return true;
  }
  return false;
}