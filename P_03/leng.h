// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadoras de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo leng.h: Definición de la clase lenguaje.         
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#ifndef _CyA_P02_LENG_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P02_LENG_

#include "cad.h"

#include <vector>
#include <string>
#include <sstream>

class Leng {
  public:
    Leng(std::string);                // Constructor solo con lenguaje.
    Leng(std::string, std::string);   // Constructor con lenguaje e identificador.
    Leng();

    int GetLength();

    // Sobrecarga de operadores.
    friend std::ostream& operator << (std::ostream& os, Leng& leng_aux);
    friend Leng operator + (Leng& leng1, Leng& leng2);  // Concatenación.
    friend Leng operator | (Leng& leng1, Leng& leng2);  // Unión.
    friend Leng operator ^ (Leng& leng1, Leng& leng2);  // Intersección.
    friend Leng operator - (Leng& leng1, Leng& leng2);  // Diferencia.
    friend Leng operator ! (Leng& leng_aux);            // Inversa.
    friend Leng operator * (Leng& leng_aux, int n);     // Potencia.
        
  private:
    std::set<Cad> leng_;
};

#endif