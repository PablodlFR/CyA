// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadoras de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo leng.cc: Implementación de la clase lenguaje.         
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#include "leng.h"

Leng::Leng(std::string string_aux) {
  std::stringstream iss(string_aux);
  std::string string_aux2;
  while(getline(iss, string_aux2, ' ')) {
    Cad cad_aux(string_aux2);
    leng_.insert(cad_aux);
  }  
}

Leng::Leng(std::string string_aux, std::string id) {
  std::stringstream iss(string_aux);
  std::string string_aux2;
  while(getline(iss, string_aux2, ' ')) {
    Cad cad_aux(string_aux2);
    leng_.insert(cad_aux);
  }  
}

Leng::Leng() {

}

int Leng::GetLength() {
  return leng_.size();
}

std::ostream& operator << (std::ostream& os, Leng& leng_aux) {
  os << "{ ";
    for(auto i: leng_aux.leng_) {
      os << i << " ";
    }
    os << "}";
  return os; 
}

Leng operator + (Leng& leng1, Leng& leng2) {
  Leng leng_aux;
  Cad cad_aux(""), cad_aux2("");
  Cad cad_vac("&");
  for(std::set<Cad>::iterator it = leng1.leng_.begin(); it != leng1.leng_.end(); it++) {      
    for(std::set<Cad>::iterator it2 = leng2.leng_.begin(); it2 != leng2.leng_.end(); it2++) {           
      cad_aux = *it; 
      cad_aux2 = *it2;
      if(cad_aux == cad_vac && cad_aux2 != cad_vac) {
        leng_aux.leng_.insert(cad_aux2);
      } else if(cad_aux2 == cad_vac && cad_aux != cad_vac) {
        leng_aux.leng_.insert(cad_aux);
      } else if(cad_aux != cad_vac && cad_aux2 != cad_vac) {
        cad_aux = cad_aux * cad_aux2;
        leng_aux.leng_.insert(cad_aux);
      } else if(cad_aux == cad_vac && cad_aux2 == cad_vac) {
        leng_aux.leng_.insert(cad_aux);
      }
    }   
  }      
  return leng_aux;
}

Leng operator | (Leng& leng1, Leng& leng2) {
   for(std::set<Cad>::iterator it = leng2.leng_.begin(); it != leng2.leng_.end(); it++) {         
    leng1.leng_.insert(*it);                                                                    
  }                                                                                                     
  return leng1;    
}

Leng operator ^ (Leng& leng1, Leng& leng2) {
  Leng leng_aux;
  Cad cad_aux1("");
  Cad cad_aux2("");
  for(std::set<Cad>::iterator it = leng1.leng_.begin(); it != leng1.leng_.end(); it++) {   
    for(std::set<Cad>::iterator it2 = leng2.leng_.begin(); it2 != leng2.leng_.end(); it2++) {
      cad_aux1 = *it;
      cad_aux2 = *it2;
      if(cad_aux1 == cad_aux2) {
        leng_aux.leng_.insert(cad_aux1);
      }
    }                                                                            
  } 
  return leng_aux;  
}

Leng operator - (Leng& leng1, Leng& leng2) {
  Cad cad_aux("");
  for(std::set<Cad>::iterator it = leng2.leng_.begin(); it != leng2.leng_.end(); it++) {       
    cad_aux = *it;                                                                            
    leng1.leng_.erase(cad_aux);                                                              
  }
  return leng1;
}

Leng operator ! (Leng& leng_aux) {
  Cad cad_aux("");                                             
  Leng leng_aux2;
  for(std::set<Cad>::iterator it = leng_aux.leng_.begin(); it != leng_aux.leng_.end(); it++) {
    cad_aux = *it;
    leng_aux2.leng_.insert(cad_aux.Invert());
  }
  return leng_aux2;
}

Leng operator * (Leng& leng_aux, int n) {
  Leng leng_cad_vac("&");
  Leng leng_aux2 = leng_aux;
  if(n == 0) {                // Cuando la potencia es 0, el lenguaje solamente contiene la cadena vacía.
    return leng_cad_vac;
  }  
  for(int i = 0; i < n - 1; i++) {
    leng_aux2 = leng_aux + leng_aux2;
  }
  return leng_aux2;
}