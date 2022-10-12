// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 09/10/2022
// Archivo leng.cc: Implementación de la clase lenguaje.         
// Referencia:
// Historial de revisiones:
//       09/10/2022 - Creación (primera versión) del código.
//       10/10/2022 - Continuación del código.
//       11/10/2022 - Continuación del código.
//       12/10/2022 - Continuación del código.

#include "leng.h"

Leng::Leng(std::string string_aux) {
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

Leng Leng::Concat(Leng leng1, Leng leng2) {
  Leng leng_aux;
  Cad cad_aux(""), cad_aux2("");
  Cad cad_vac("&");

  for(std::set<Cad>::iterator it = leng1.leng_.begin(); it != leng1.leng_.end(); it++) {      
    for(std::set<Cad>::iterator it2 = leng2.leng_.begin(); it2 != leng2.leng_.end(); it2++) {           
     cad_aux = *it; 
     cad_aux2 = *it2;
     if(cad_aux == cad_vac && cad_aux2 != cad_vac) {
      leng_aux.leng_.insert(cad_aux2);
     } else if (cad_aux2 == cad_vac && cad_aux != cad_vac) {
      leng_aux.leng_.insert(cad_aux);
     } else if (cad_aux != cad_vac && cad_aux2 != cad_vac) {
      cad_aux = cad_aux * cad_aux2;
     leng_aux.leng_.insert(cad_aux);
     }     
    }   
  }      
  return leng_aux;
}

Leng Leng::Union(Leng leng1, Leng leng2) {                                                      // Recorro el conjunto de leng2 y lo inserto en el conjunto de leng1,                                                                                                                                                                                          
  for(std::set<Cad>::iterator it = leng2.leng_.begin(); it != leng2.leng_.end(); it++) {        // se quedaría ya la unión debido a que los conjuntos solo guardan una vez  
    leng1.leng_.insert(*it);                                                                    // un mismo elemento, es decir, se elimina automáticamente los repetidos.
  }                                                                                                     
  return leng1;                                                                                 // Devuelvo leng1, con la unión ya realizada.
}

Leng Leng::Intersec(Leng leng1, Leng leng2) {  
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

Leng Leng::Difer(Leng leng1, Leng leng2) {  
 Cad cad_aux("");
  for(std::set<Cad>::iterator it = leng2.leng_.begin(); it != leng2.leng_.end(); it++) {      // Recorro el conjunto del segundo lenguaje y borro del primer lenguaje todas aquellas cadenas 
    cad_aux = *it;                                                                            // que coincidan, dejando así solo las cadenas del primer lenguaje que no se encuentran también 
    leng1.leng_.erase(cad_aux);                                                               // en el segundo, es decir, la diferencia.
  }
  return leng1;
}

Leng Leng::Invert(Leng leng_aux) {                             
  Cad cad_aux("");                                             
  Leng leng_aux2;
  for(std::set<Cad>::iterator it = leng_aux.leng_.begin(); it != leng_aux.leng_.end(); it++) {
    cad_aux = *it;
    leng_aux2.leng_.insert(cad_aux.Invert());
  }
  return leng_aux2;
}

Leng Leng::Potencia(Leng leng_aux, int rep) {
  Leng leng_cad_vac("&");
  Leng leng_aux2 = leng_aux;
  if(rep == 0) {            // Cuando la potencia es 0, el lenguaje solamente contiene la cadena vacía.
    return leng_cad_vac;
  }  
  for(int i = 0; i < rep - 1; i++) {
    leng_aux2 = Concat(leng_aux, leng_aux2);
  }
  return leng_aux2;
}
