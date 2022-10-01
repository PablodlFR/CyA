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