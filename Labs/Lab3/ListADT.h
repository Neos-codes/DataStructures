#ifndef LISTA_H
#define LISTA_H

class List{
 public:
  virtual void push_back(int) = 0; // Agregar elemento al final de la cola
  virtual int at(int) = 0;         // Obtiene un elemento de la lista
  virtual int size() = 0;          // Retorna el tamaño de la lista
};

#endif
