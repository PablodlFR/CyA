// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 01/10/2022
// Archivo main.c: programa cliente.
//         Contiene la función main del proyecto, donde se usan las clases cadena (cad.h),
//         alfabeto (alf.h) y símbolo (sim.h), tal y como pide la práctica.
// Referencia:
// Historial de revisiones:
//       01/10/2022 - Creación (primera versión) del código.
//       02/10/2022 - Continuación del código.
//       03/10/2022 - Continuación del código.
//       04/10/2022 - Continuación del código.
//       05/10/2022 - Continuación del código.

#include "cad.h"
#include "alf.h"
#include "sim.h"
#include "fun_aux.h"

#include <fstream>

std::ifstream fe;     // Fichero de entrada.
std::ofstream fo;     // Fichero de salida.

std::string line, aux_cont;
int cont = 0;

int main(int argc, char *argv[]) {
  fe.open(argv[1]);
  fo.open(argv[2]);
  
  while (!fe.eof()) {     // Contamos el nº de líneas que tiene el fichero de entrada.
    while(getline(fe, aux_cont)) {
      cont++;
    }
  }

  fe.clear();     // Cuando el archivo llega al final cualquier operación de cancela, con clear() limpiamos los flags y podemos hacer seekg().
  fe.seekg(0);    // Una vez leido todo el archivo volvemos al inicio.

  for(int i = 0; i < cont; i++) {
    getline(fe, line);            // Toma cada una de las líneas del fichero de entrada.
    line = GetCadString(line);    // Toma la última palabra de la línea, que corresponde a la cadena.
    Cad cad(line);

    Cad cad_aux("");                  // Cadena auxiliar, donde guardamos la cadena antes de imprimirla al fichero de salida.
    std::vector<Cad> vec_cad_aux;     // Vector de cadenas auxiliar, donde guardamos las cadenas antes de imprimirla al fichero de salida.    

    switch(atoi(argv[3])) {
      case 1:
        fo << cad.GetLength() << std::endl;    
        break;

      case 2:
        cad_aux = cad.Invert();
        fo << cad_aux << std::endl;    
        break;

      case 3:
        vec_cad_aux = cad.Prefix();    
        for(int i = 0; i < vec_cad_aux.size(); i++) {
          fo << vec_cad_aux[i] << " ";      
        }  
        fo << std::endl;
        break;

      case 4:
        vec_cad_aux = cad.Sufix();
        for(int i = 0; i < vec_cad_aux.size(); i++) {
          fo << vec_cad_aux[i] << " ";
        } 
        fo << std::endl;
        break;
    
      case 5:
        vec_cad_aux = cad.SubCad();
        for(int i = 0; i < vec_cad_aux.size(); i++) {
          fo << vec_cad_aux[i] << " ";
        } 
        fo << std::endl;
        break;
        
    default:
      std::cout << "[Opción introducida incorrecta]" << std::endl;
      std::cout << "Opciones:" << std::endl;
      std::cout << " 1 - Longitud." << std::endl;
      std::cout << " 2 - Inversa." << std::endl;
      std::cout << " 3 - Prefijos." << std::endl;
      std::cout << " 4 - Sufijos." << std::endl;
      std::cout << " 5 - Subcadenas." << std::endl;
      return 1;
      break;
    }  
  }

  fe.close();   // Cerramos el fichero de entrada.
  fo.close();   // Cerramos el fichero de salida.

  return 0;
}