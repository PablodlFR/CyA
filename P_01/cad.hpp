#ifndef _CyA_P01_CAD_  //<PROJECT>_<PATH>_<FILE>_H_
#define _CyA_P01_CAD_

#include <iostream>
#include <string.h>

class Cad {
  public:
    Cad(std::string);
   // ~Cad();

    char* GetCad();
    int GetLength();

  private:
    char* cad_;

};



// Cad::~Cad()
// {
// }


#endif
