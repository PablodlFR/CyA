// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 01/10/2022
// Archivo main.cpp: programa cliente.
// Referencia:
// Historial de revisiones:
//       01/10/2022 - Creación (primera versión) del código.

//#include "alf.hpp"
#include "cad.hpp"

#include <fstream>
#include <sstream>

std::ifstream fe;
std::ofstream fo;

std::string cad1, aux_cont;
char* cad2;
int cont = 0;
int cont2 = 0;

int main(int argc, char *argv[]) {

  fe.open(argv[1]);
  fo.open(argv[2]);

    // Contamos el nº de líneas que tiene el fichero de entrada.

    while (!fe.eof()) {
      while(getline(fe, aux_cont)) {
        cont2++;
      }
    }

  fe.clear();     // Cuando el archivo llega al final cualquier operación de cancela, con clear() limpiamos los flags y podemos hacer seekg().
  fe.seekg(0);    // Una vez leido todo el archivo volvemos al inicio.
  
  for(int i = 0; i < cont2; i++) {
     getline(fe, cad1);

  std::stringstream iss(cad1);
  while(getline(iss, cad1, ' '));   // Toma la última palabra de la línea, que corresponde a la cadena.
  
  Cad cad3(cad1);

  switch(atoi(argv[3])) {
  case 1:
    fo << cad3.GetLength() << std::endl;
    break;

  case 2:
    fo << cad3.Invert() << std::endl;
    break;

  case 3:
    fo << cad3.Prefix() << std::endl;
    break;

  case 4:
    fo << cad3.Sufix() << std::endl;
    break;
  
  case 5:
    fo << cad3.SubCad() << std::endl;
  
  default:
    break;
  }
  
  
  
  }
 

  // cad2 = const_cast<char*>(cad1.c_str());
  // fo << cad2;
  // std::cout << cad2 << std::endl;


  // while((fe >> cad1)) {
  //   std::cout << cad1 << std::endl;
  // }

  fe.close();
  fo.close();

  return 0;
}