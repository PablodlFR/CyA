// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales.
// Autor: Pablo de la Fuente Rodríguez
// Correo: alu0101336152@ull.edu.es
// Fecha: 15/10/2022
// Archivo main.c: programa cliente.
//         Contiene la función main del proyecto, donde se usan las clases  lenguaje (leng.h), cadena (cad.h),
//         alfabeto (alf.h) y símbolo (sim.h), tal y como pide la práctica.
// Referencia:
// Historial de revisiones:
//       15/10/2022 - Creación (primera versión) del código.
//       16/10/2022 - Continuación del código.
//       17/10/2022 - Continuación del código.
//       18/10/2022 - Continuación del código.

#include "cad.h"
#include "alf.h"
#include "sim.h"
#include "leng.h"
#include "fun_aux.h"

#include <fstream>
#include <stack>
#include <map>

std::ifstream fe;       // Fichero de entrada.
std::ofstream fo;       // Fichero de salida.

std::string line, aux_cont, id_string, leng_string;
std::map<std::string, Leng> map_leng;     // Variable parecida a un conjunto(set) donde se asigna a cada variable un identificador, en este caso, a cada lenguaje se identifica con un string.
std::stack<Leng> stack;

int n_rep = 0;        // Valor para la potencia.
int cont_line = 0;    // Contar el nº de líneas totales del fichero de entrada.
int cont_leng = 0;    // Contar el nº de lenguajes que proporciona el fichero.
int cont_op = 0;      // Contar el nº de operaciones que proporciona el fichero.

int main(int argc, char *argv[]) {
  fe.open(argv[1]);  
  while (!fe.eof()) {                // Contamos el nº de líneas que tiene el fichero de entrada.
    while(getline(fe, aux_cont)) {
      cont_line++;
      for(int i = 0; i < aux_cont.size(); i++) {           // Recorremos todo el string, buscando cuantas veces se repite ','.
        if(aux_cont[i] == '=') {
          cont_leng++;
        }
      }
    }
    cont_op = cont_line - cont_leng;
  }

  fe.clear();     // Cuando el archivo llega al final cualquier operación de cancela, con clear() limpiamos los flags y podemos hacer seekg().
  fe.seekg(0);    // Una vez leido todo el archivo volvemos al inicio.

  for(int i = 0; i < cont_leng; i++) {
    getline(fe, line);            // Toma cada una de las líneas del fichero de entrada que contiene la declaración de un lenguajes.    
    id_string = GetIdString(line);
    leng_string = GetLengString(line);
    map_leng[id_string] = leng_string;
  }  
    Leng leng_aux1;
    Leng leng_aux2;    

  for(int i = 0; i < cont_op; i++) {
    getline(fe, line);               // Toma cada una de las líneas del fichero de entrada que corresponde a una operación.
    std::stringstream iss(line);
    std::string op;               
    while(getline(iss, op, ' ')) {   // Divide toda la línea por espacios, guardando cada operando u operador en op, para posteriormente meterlo en la pila.
      if(op != "+" && op != "|" && op != "^" && op != "-" && op != "!" && op != "*" &&  isdigit(op[0]) != 1) {
        stack.push(map_leng[op]);
      }
      if(isdigit(op[0]) == 1) {
        n_rep = std::stoi(op);       // Si op es un nº se guarda en n_rep que se usará posteriormente en la potencia.
      }
      if(op == "+") {
        leng_aux1 = stack.top();
        stack.pop();
        leng_aux2 = stack.top();
        stack.pop();        
        stack.push(leng_aux1 + leng_aux2); 
      } else if(op == "|") {
        leng_aux1 = stack.top();
        stack.pop();
        leng_aux2 = stack.top();
        stack.pop();        
        stack.push(leng_aux1 | leng_aux2); 
      } else if(op == "^") {
        leng_aux1 = stack.top();
        stack.pop();
        leng_aux2 = stack.top();
        stack.pop();        
        stack.push(leng_aux1 ^ leng_aux2);    
      } else if(op == "-") {
        leng_aux1 = stack.top();
        stack.pop();
        leng_aux2 = stack.top();
        stack.pop();        
        stack.push(leng_aux1 - leng_aux2);  
      } else if(op == "!") {
        leng_aux1 = stack.top();
        stack.pop();
        stack.push(!leng_aux1);    
      } else if(op == "*") {
        leng_aux1 = stack.top();
        stack.pop();
        stack.push(leng_aux1 * n_rep); 
      }     
    }
    std::cout << "Resultado de la operación " << i + 1 << ": " << stack.top() << std::endl;
  }
  fe.close();   // Cerramos el fichero de entrada.
  return 0;
}