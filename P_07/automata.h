// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 05/11/2022
// Archivo automata.cc: Definición de la clase automata.         
// Referencia:
// Historial de revisiones:
//       05/11/2022 - Creación (primera versión) del código.
//       06/11/2022 - Continuación del código.
//       07/11/2022 - Continuación del código.
//       08/11/2022 - Continuación del código.
//       09/11/2022 - Continuación del código.

#ifndef _CyA_P06_AUTOMATA_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P06_AUTOMATA_

#include "estado.h"
#include "alfabeto.h"

#include <fstream>
#include <sstream>

class Automata {
  public:
    void LoadAut(std::ifstream&);     // Cargar el autómata.
    void SetNumEst(int);              // Poner el nº de estados totales del autómata.
    void SetEstArr(std::string);      // Establecer el estado de arrance.
    void SetEst(Estado);              // Meter un estado en el vector de estados.
    Alfabeto GetAlp();
    std::string GetStart();           // Devuelve el id del estado de arranque.
    std::string GetEstAcc();

    std::string CheckCad(std::string);
    Estado GetEst(std::string);       // Devuelve un estado según el id pasado.
    int GetNumEst();
    std::vector<Estado> GetVecEst();  // Devuelve el vector de todos los estados que componen el autómata.
    bool CheckAut();                  // Comprueba si se trata de un DFA o NFA, 1 = DFA, 0 = NFA.

  private:
    int num_est_;                     // Número total de estados del autómata.
    std::string est_arr_;             // Estado de arranque del autómata. 
    std::vector<Estado> estados_;     // Vector de los estados del autómata.
    Alfabeto alf_;                    // Alfabeto del autómata.
};

#endif