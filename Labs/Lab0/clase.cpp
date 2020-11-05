#include "clase.h"

clase::clase(int myInt) {
  _myInt = myInt;
}

int clase::getMyInt() {
  return _myInt;
}

int clase::incrementar(){   // Metodo que aumentar en 1 _myInt
  _myInt++;
}

int clase::_incrementar(int aux){  // Metodo que suma aux a _myInt
  _myInt += aux;
}
