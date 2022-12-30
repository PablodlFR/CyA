// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmos Voraces (Greedy). Cambio de Monedas.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 16/12/2022
// Archivo cam.cc: Implementación de la clase cambio.         
// Referencia:
// Historial de revisiones:
//       16/12/2022 - Creación (primera versión) del código.
//       20/12/2022 - Continuación del código.

#include "cam.h"

#include <iostream>

void Cam::devolver_cambio(float n) {
  int cantidad = n * 100;
  int suma = 0, i = 0; 

  while (suma != cantidad) {    
    if ((monedas_[i] + suma) <= cantidad) {
        sol_.insert(monedas_[i]);
        suma += monedas_[i];
      }
    else {
      i++;
    }
  }
}

void Cam::devolver_cambio_b(float n) {
  int cantidad = n * 100;
  int suma = 0, i = 0; 

  while (suma != cantidad) {    
    if ((bil_mon_[i] + suma) <= cantidad) {
        sol_.insert(bil_mon_[i]);
        suma += bil_mon_[i];
      }
    else {
      i++;
    }
  }
}

void Cam::devolver_cambio_o(float n) {
  int cantidad = n * 100;
  int suma = 0;
  int c = 0;  // nº de monedas de un tipo que hay que añadir.

  for (int i = 0; i < monedas_.size(); i++) {
    c = (cantidad - suma) / monedas_[i];
    if (c > 0) {
      for (int j = c; j > 0; j--) {
        sol_.insert(monedas_[i]);
      }               
      suma += c * monedas_[i];
    }
  }
}

void Cam::imprimir_cambio() {
  std::multiset<int>::reverse_iterator it;    // reverser iterator para imprimir las monedas de mayor a menor.
  int cont, temp, valor = 0, rep = 0, i = 0;
  std::cout << "Solución: ";
  for (it = sol_.rbegin(); it != sol_.rend(); it++) {   
    temp = *it;                                           // temp solo guarda *it para poder usarlo en .count().
    cont = sol_.count(temp);                              // Guarda el nº de veces que hay un elemento en el multiset
    if (cont > rep) {
      rep = cont;
      valor = *it;
    }
    
    i++;                                                  // Contador para pasar todas las monedas de un tipo y se solo se impriman cuando llega a la última para que solo se imprima una vez.
    if (cont  == i) {
      if (*it >= 100) {
        if (cont > 1) {                                   // Para que no ponga 1x1€ ya que es redudante.
          std::cout << cont << "x";
        }      
        std::cout << *it/100 << "€ ";
     }
      else {
        if (cont > 1) {
          std::cout << cont << "x";
        }              
        std::cout << *it << "¢ ";
      }  
      i = 0;
    }           
  }
  std::cout << std::endl;
  std::cout << "Total monedas: " << sol_.size() << std::endl;
  std::cout << "Tipo más frecuente: ";
  if (valor >= 100) {
    std::cout << valor/100 << "€ " << std::endl;
  }
  else {
    std::cout << valor << "¢ " << std::endl; 
  }
}