#include "cad.hpp"

Cad::Cad(std::string aux) {
   cad_ = const_cast<char*>(aux.c_str());
}

int Cad::GetLength() {
  return strlen(cad_);
}

char* Cad::GetCad() {
  return cad_;
}

char* Cad::Invert() {
  char aux;
  for(int i = 0, j = GetLength() - 1; i < (GetLength() / 2); i++, j--) {       
    aux = cad_[i];
    cad_[i] = cad_[j];
    cad_[j] = aux;
  }
  return cad_;  
}

std::string Cad::Prefix() {     // El tamaño de la cadena se modifica después de crear otros strings, ¿Por qué?

  int size = GetLength();

  std::string aux = cad_;
  //std::cout << GetLength();
  //std::string aux2 = "& ";
  //std::cout << GetLength();
  std::string aux2, aux3;

  //std::cout << GetLength();

  for(int i = 0; i < size; i++) {
    aux2 += aux[i];
    aux3 += aux2 + " ";
  }
  
  aux3 = "& " + aux3;
  
  return aux3;
}

std::string Cad::Sufix() {

  int size = GetLength();

  std::string aux = cad_;
  std::string aux2, aux3;

  for(int i = size - 1; i >= 0; i--) {
    aux2 = aux[i] + aux2;
    aux3 += aux2 + " ";
  }
  
  aux3 = "& " + aux3;
  
  return aux3;
}

std::string Cad::SubCad() {
  int size = GetLength();
  std::string aux = cad_;
  std::string aux2;
  std::string aux3 = " ";

  for(int i = 0; i < size; i++) {
    for(int j = 1 + i; j < size + 1; j++) {
      aux2 += aux.substr(i, j - i) + " ";
    }
  }

  aux2 = "& " + aux2;  

  return aux2;
}
