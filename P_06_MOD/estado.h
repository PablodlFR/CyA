// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 05/11/2022
// Archivo estado.cc: Definición de la clase estado.         
// Referencia:
// Historial de revisiones:
//       05/11/2022 - Creación (primera versión) del código.
//       06/11/2022 - Continuación del código.
//       07/11/2022 - Continuación del código.
//       08/11/2022 - Continuación del código.
//       09/11/2022 - Continuación del código.

#ifndef _CyA_P06_ESTADO_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P06_ESTADO_

#include <utility> //std::pair
#include <string>
#include <set>     
#include <iostream>
#include <vector> 
#include <iterator>

class Estado {
  public:
    void SetId(std::string);                            // Establecer una id para el estado.
    void SetAccept(std::string);                        // Establecer el si el estado es de aceptación o no.
    void SetNumTrans(int);                              // Establecer el nº de transiciones del estado.
    void SetTrans(std::pair<std::string,std::string>);  // Establecer una transición del estado.

    std::string GetId();                                // Devuelve el id del estado.
    std::vector<std::string> GetTrans(std::string);     // Devuelve todas las transiciones del estado a las que se puede llegar con un símbolo pasado por parámetro.
    void ClearTrans();                                  // Limpia el vector que contiene todas las transiciones del estado.
    bool GetAccept();                                   // Devuelve si un estado es de acceptación o no.

    friend bool operator < (Estado est1, Estado est2) {     // Necesario para usar la librería set.
      if(est1.num_trans_ <= est2.num_trans_) {
        return true;
      } 
      return false;
    }

  private:
    std::string id_;
    bool accept_;                         // 1 si es de acceptación, 0 si no lo es.
    int num_trans_;                       // número de transiciones del estado.
    std::vector<std::pair<std::string,std::string>> vec_trans_; // Vector de transiciones. Transición de un estado, primer elemento: símbolo con el que transiciona; segundo elemento: estado al que transiciona con dicho elemento. 
};

#endif