// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 09/10/2022
// Archivo main.c: programa cliente.
//         Contiene la función main del proyecto, donde se usan las clases  lenguaje (leng.h), cadena (cad.h),
//         alfabeto (alf.h) y símbolo (sim.h), tal y como pide la práctica.
// Referencia:
// Historial de revisiones:
//       09/10/2022 - Creación (primera versión) del código.
//       10/10/2022 - Continuación del código.
//       11/10/2022 - Continuación del código.
//       12/10/2022 - Continuación del código.

#include "cad.h"
#include "alf.h"
#include "sim.h"
#include "leng.h"
#include "fun_aux.h"

#include <fstream>

std::ifstream fe1, fe2;   // Fichero de entrada.
std::ofstream fo;         // Fichero de salida.

std::string line, line2, aux_cont;
int cont = 0;

int main(int argc, char *argv[]) {
  fe1.open(argv[1]);
  fe2.open(argv[2]);
  fo.open(argv[3]);
  
  while (!fe1.eof()) {                // Contamos el nº de líneas que tiene el fichero de entrada.
    while(getline(fe1, aux_cont)) {
      cont++;
    }
  }

  fe1.clear();     // Cuando el archivo llega al final cualquier operación de cancela, con clear() limpiamos los flags y podemos hacer seekg().
  fe1.seekg(0);    // Una vez leido todo el archivo volvemos al inicio.

  for(int i = 0; i < cont; i++) {
    getline(fe1, line);            // Toma cada una de las líneas del fichero de entrada 1.
    getline(fe2, line2);           // Toma cada una de las líneas del fichero de entrada 2.
    line = GetLengString(line);
    line2 = GetLengString(line2);

    Leng leng(line);
    Leng leng2(line2);

    Leng leng_aux;
    int rep_pot = 0;                // Guarda el elevado de la potencia.

    switch(atoi(argv[4])) {
      case 1:
        leng_aux = leng.Concat(leng, leng2);
        fo << leng_aux << std::endl;    
        break;

      case 2:
        leng_aux = leng.Union(leng, leng2);
        fo << leng_aux << std::endl;  
        break;

      case 3:
        leng_aux = leng.Intersec(leng, leng2);
        fo << leng_aux << std::endl;
        break;

      case 4:
        leng_aux = leng.Difer(leng, leng2);
        fo << leng_aux << std::endl;
        break;
    
      case 5:
        leng_aux = leng.Invert(leng); 
        fo << leng_aux << std::endl;
        break;

      case 6:
        std::cout << "Introduce el valor empleado en la potencia para el lenguaje " << i + 1 << ": " ;
        std::cin >> rep_pot;
        leng_aux = leng.Potencia(leng, rep_pot);
        fo << leng_aux << std::endl;
        break;
        
    default:
      std::cout << "[Opción introducida incorrecta]" << std::endl;
      std::cout << "Opciones:" << std::endl;
      std::cout << " 1 - Concatenación." << std::endl;
      std::cout << " 2 - Unión." << std::endl;
      std::cout << " 3 - Intersección." << std::endl;
      std::cout << " 4 - Diferencia." << std::endl;
      std::cout << " 5 - Inversa." << std::endl;
      std::cout << " 6 - Potencia." << std::endl;
      return 1;
      break;
    }  
  }

  fe1.close();   // Cerramos el fichero 1 de entrada.
  fe2.close();   // Cerramos el fichero 2 de entrada.
  fo.close();    // Cerramos el fichero de salida.

  return 0;
}