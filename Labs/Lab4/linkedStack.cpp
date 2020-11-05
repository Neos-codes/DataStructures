#include "linkedStack.h"
#include <iostream>

using namespace std;

linkedStack::linkedStack(){
  nodo *head = NULL;
  int tam = 0;
}

void linkedStack::push(int num){
  nodo *aux = (nodo *)malloc(sizeof(nodo));  //crea un nodo en el hype

  if(head == NULL){
    head = aux;
    aux -> next = NULL;
  }

  else{
    aux -> next = head;
    head = aux;
  }
  head -> n = num;
  tam ++;
  //  cout << "linked push: " << head -> n << endl;
}

int linkedStack::pop(){

  if(tam != 0){

    nodo *temp = head;
    int ret;
    head = head -> next;
    ret = temp -> n;
    free(temp);
    tam--;
    //    cout << "linked pop: " << ret << endl;
    return ret;
  }
  else{
    cout << "El Stack esta vacio\n";
    return -1;
  }
}

bool linkedStack::isEmpty(){
  if(head != NULL)
    return false;
  else
    return true;
}

