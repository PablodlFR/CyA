#include <iostream>

using namespace std;

// poner aqui los ejemplos como funciones con el siguiente formato,
// donde 'X' es el numero de ejemplo
int ejemploX(const int n)
{ // codigo fuente de cada bloque
  int suma = 0;
for (int i = 1; i <= n; i++)
  for (int j = 1; j <= n; j *= 2)
    for (int k = 1; k <= n; k++)
      suma++;

  return suma;
}

int main()
{ // pedir el valor de n
  int n;
  cout << "Introducir n: ";
  cin >> n;

  // invocar a cada ejemplo
  cout << "Ejemplo X: " << ejemploX(n) << endl;
  return 0;
}