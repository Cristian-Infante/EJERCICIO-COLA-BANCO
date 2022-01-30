#include "NODO.h"

template <typename T>
NODO<T>::NODO(T dato){
    info = dato;
    siguiente = NULL;
}

template <typename T>
NODO<T>::~NODO(){
}

template <typename T>
void NODO<T>::setInfo(T dato){
    info = dato;
}

template <typename T>
T NODO<T>::getInfo(){
    return info;
}

template <typename T>
void NODO<T>::setSiguiente(NODO<T> *nuevo){
    siguiente = nuevo;
}

template <typename T>
NODO<T> *NODO<T>::getSiguiente(){
    return siguiente;
}

template <typename T>
void NODO<T>::print(){
    cout<<info<<endl;
}
