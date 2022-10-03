#ifndef _CyA_P01_CAD_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P01_CAD_

#include <iostream>
#include <string.h>
#include <string>
#include <vector>

class Cad {
  public:
    Cad(std::string);
  
    char* GetCad();
    int GetLength();
    char* Invert();
    std::string Prefix();
    std::string Sufix();
    std::string SubCad();

  private:
    char* cad_;

};



// Cad::~Cad()
// {
// }


#endif
