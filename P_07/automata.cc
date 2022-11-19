// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 05/11/2022
// Archivo automata.cc: Implementación de la clase automata.         
// Referencia:
// Historial de revisiones:
//       05/11/2022 - Creación (primera versión) del código.
//       06/11/2022 - Continuación del código.
//       07/11/2022 - Continuación del código.
//       08/11/2022 - Continuación del código.
//       09/11/2022 - Continuación del código.

#include "automata.h"

void Automata::LoadAut(std::ifstream& fe) {
  Estado est_aux;
  std::pair<std::string,std::string> pair_aux;  // Guardamos la transición de un estado, primer elemento: símbolo con el que transiciona; segundo elemento: estado al que transiciona con dicho elemento. 
  std::string fich_line, string_aux;

  int cont_line = 1;
  int cont_est_line = 1;          // Contar las separaciones de la línea de un estado, ya que cada nº representa una cosa diferente.

  while (!fe.eof()) {   
    while(getline(fe, fich_line)) {   
      if (cont_line == 1) {                      // Línea 1 del fichero. Símbolos del alfabeto.
        std::stringstream iss(fich_line);
        while (getline(iss, string_aux, ' ')) {  
          alf_.SetAlf(string_aux);
        }
      }   
      if (cont_line == 2) {                       // Línea 2 del fichero. Número total de estados del autómata.
        SetNumEst(stoi(fich_line));            
      }
      if (cont_line == 3) {                       // Línea 3 del fichero. Estado de arranque del autómata.
        SetEstArr(fich_line);               
      }
      if (cont_line > 3) {                        // Línea 4 en adelante del fichero. Cada uno de los estados del autómata.
        std::stringstream iss(fich_line);
        cont_est_line = 1;
        while (getline(iss, string_aux, ' ')) {        
          if (cont_est_line == 1) {           
            est_aux.SetId(string_aux);            
          }
          if (cont_est_line == 2) {
            est_aux.SetAccept(string_aux);
          }
          if (cont_est_line == 3) {
            est_aux.SetNumTrans(stoi(string_aux));
          }              
          if (cont_est_line >= 4 && cont_est_line % 2 == 0) {            
            pair_aux.first = string_aux;            
          }    
          if (cont_est_line >= 4 && cont_est_line % 2 != 0) {
            pair_aux.second = string_aux;         
            est_aux.SetTrans(pair_aux);
          }
          cont_est_line++;
        }        
        SetEst(est_aux);
        est_aux.ClearTrans();
      }    
      cont_line++;      
    }       
  }
}

void Automata::SetNumEst(int num) {
  num_est_ = num;
}

void Automata::SetEstArr(std::string est_arr) {
  est_arr_ = est_arr;
}

void Automata::SetEst(Estado estado) {
  estados_.push_back(estado);
}

Alfabeto Automata::GetAlp() {
  return alf_;
}

std::string Automata::GetStart() {
  return est_arr_;
}

int Automata::GetNumEst() {
  return num_est_;
}

std::vector<Estado> Automata::GetVecEst() {
  return estados_;
}

Estado Automata::GetEst(std::string id) {
  for (int i = 0; i < estados_.size(); i++) {
    if (estados_[i].GetId() == id) {
      return estados_[i];
    }
  }
  return Estado();
}

std::string Automata::CheckCad(std::string cad) {
  int j = 0;
  std::string aux;
  Estado est_aux;
  std::vector<std::string> vec_aux, vec_aux2;
  std::set<Estado> set_aux;
  est_aux = GetEst(est_arr_);  
   
  while (j < cad.size()) {     
    aux = "";                      // Limpiamos aux.
    aux.append(1, cad[j]);         // Pasa un char de cad a string y lo guarda en aux.
    if( j == 0) {
      vec_aux2 = est_aux.GetTrans(aux);   // Obtenemos el id del siguiente estado en base al símbolo pasado y guardamos el id en aux. 
    }     
    
    for (std::set<Estado>::iterator it = set_aux.begin(); it != set_aux.end(); it++) {
      est_aux = *it;
      vec_aux = est_aux.GetTrans(aux);
      for(int z = 0; z < vec_aux.size(); z++) {
        vec_aux2.push_back(vec_aux[z]);
      }
    }   
    set_aux.clear();
    for (int i = 0; i < vec_aux2.size(); i++) {
      set_aux.insert(GetEst(vec_aux2[i]));
    }
    vec_aux2.clear(); 
    j++;
  }  

  for (std::set<Estado>::iterator it = set_aux.begin(); it != set_aux.end(); it++) {
    est_aux = *it;
    if (est_aux.GetAccept() == true) {     
      return "Accepted";
    } 
  } 
  return "Rejected";
}

bool Automata::CheckAut() {
  std::vector<std::string> vec_aux, vec_aux2, vec_ep;
  vec_aux = alf_.GetVecAlp();
  for (int j = 0; j < estados_.size(); j++) {
    for (int i = 0; i < vec_aux.size(); i++) {
      vec_aux2 = estados_[j].GetTrans(vec_aux[i]);
      vec_ep = estados_[j].GetTrans("&");
      if (vec_aux2.size() > 1 || vec_aux2.size() == 0 || vec_ep.size() >= 1) {
        return false; // NO es un DFA
      }
    }
  }
  return true; //El autómata es un DFA
}

std::string Automata::GetEstAcc() {
  for (int i = 0; i < estados_.size(); i++) {
    if (estados_[i].GetAccept() == 1) {
      return estados_[i].GetId();
    }
  }
}