// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 22/10/2022
// Archivo main.c: programa cliente.         
// Referencia:
// Historial de revisiones:
//       22/10/2022 - Creación (primera versión) del código.
//       23/10/2022 - Continuación del código.
//       24/10/2022 - Continuación del código.
//       25/10/2022 - Continuación del código.
//       26/10/2022 - Continuación del código.

#include "program.h"
#include "variables.h"
#include "statements.h"
#include "checkmain.h"
#include "comments.h"
#include "func_aux.h"

#include <iostream>
#include <fstream>

std::ifstream fe;       // Fichero de entrada.
std::ofstream fo;       // Fichero de salida.

int main (int argc, char *argv[]) {
  if (argc < 3 || argc > 3) {
    std::cout << "ERROR. Ejecutado incorrectamente." << std::endl;
    std::cout << "Modo correcto de ejecución: ./p04_code_analyzer fichero_entrada.cc fichero_salida.txt" << std::endl;
  }

  fe.open(argv[1]);
  fo.open(argv[2]);

  Program test_pro;
  Comments test_com;
  Variables test_var;
  Statements test_state;
  Main test_main;

  test_pro.GetProgram(argv[1]);  
  test_com.GetComments(fe); 
  RestFich(fe);  
  test_var.GetVariables(fe);
  RestFich(fe);
  test_state.GetStatements(fe);
  RestFich(fe);
  test_main.GetMain(fe);  

  // Salida del programa.
  test_pro.PrintProgram(fo);
  test_com.PrintDesciption(fo);
  test_var.PrintVariables(fo);
  test_state.PrintStatements(fo);
  test_main.PrintMain(fo);
  test_com.PrintComments(fo);

  fe.close();
  fo.close();
}