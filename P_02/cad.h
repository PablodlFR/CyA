// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 09/10/2022
// Archivo cad.h: Definición de la clase cadena.         
// Referencia:
// Historial de revisiones:
//       09/10/2022 - Creación (primera versión) del código.
//       10/10/2022 - Continuación del código.
//       11/10/2022 - Continuación del código.
//       12/10/2022 - Continuación del código.

#ifndef _CyA_P01_CAD_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P01_CAD_

#include "sim.h"

#include <vector>
#include <string>
#include <iostream>
#include <set>

class Cad {
  public:
    Cad(std::string);           // Constructor.
      
    int GetLength();            // Obtiene longitud de la cadena.
    Cad Invert();               // Obtiene la inversa de la cadena.
    std::vector<Cad> Prefix();  // Obtiene todos los prefijos de una cadena.
    std::vector<Cad> Sufix();   // Obtiene todos los sufijos de una cadena.
    std::vector<Cad> SubCad();  // Obtiene todas las subcadenas de una cadena.
    void PrintCad();            // Método de prueba para imprimir por pantalla una cadena.
  
    // Sobrecarga de operadores.
    friend std::ostream& operator << (std::ostream& os, Cad& aux) {
      for(int i = 0; i < aux.cad_.size(); i++) {
      os << aux.cad_[i].GetSim();
      }
    return os;  
    };

    friend Cad operator * (Cad& cad1, Cad& cad2) {    // Concatenar
      std::string string_aux;

      for(int i = 0; i < cad1.GetLength(); i++) {
        string_aux += cad1.cad_[i].GetSim();
      }
      for(int i = 0; i < cad2.GetLength(); i++) {
        string_aux += cad2.cad_[i].GetSim();
      }
      Cad cad_aux(string_aux);
      return cad_aux;
    }
    
    friend bool operator == (Cad& cad1, Cad& cad2) {
      if(cad1.GetLength() != cad2.GetLength()) {
        return false;
      }
      for(int i = 0; i < cad1.GetLength(); i++) {
        if(cad1.cad_[i].GetSim() != cad2.cad_[i].GetSim()){
          return false;
        }
      }
      return true;   
    }

    friend bool operator != (Cad& cad1, Cad& cad2) {
      if(cad1.GetLength() != cad2.GetLength()) {
        return true;
      }
      for(int i = 0; i < cad1.GetLength(); i++) {
        if(cad1.cad_[i].GetSim() != cad2.cad_[i].GetSim()){
          return true;
        }
      }
      return false;   
    }

    friend bool operator < (Cad cad1, Cad cad2) {
      if(cad1.GetLength() < cad2.GetLength()) {
        return true;
      } else if (cad1.GetLength() > cad2.GetLength()){
        return false;
      }
      // Si ambas cadenas tienen el mismo tamaño:
      for(int i = 0; i < cad1.GetLength(); i++) {
        if(cad1.cad_[i] < cad2.cad_[i]) {
          return true;
        } else if (cad2.cad_[i] < cad1.cad_[i]) {
          return false;
        }
      }    
      return false;  
    }

  private:
   std::vector<Sim> cad_;
};

#endif
