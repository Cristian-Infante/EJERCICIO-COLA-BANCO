#include "COLA.h"
#include "string"
#include "iostream"
#include "conio.h"
#include "ctime"
#include "windows.h"
#include "stdio.h"

 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void clreol () {
    COORD coord;
    DWORD escrito;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), & info);
    coord.X = info.dwCursorPosition.X;
    coord.Y = info.dwCursorPosition.Y;
    FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',info.dwSize.X - info.dwCursorPosition.X, coord,& escrito);
    gotoxy (coord.X, coord.Y);
}

template <typename T>
COLA<T>::COLA(){
    start = end = nullptr;
}

template <typename T>
COLA<T>::~COLA(){
    /*NODO<T> *aux;
    while(start != nullptr){
        aux = start;
        start = start->getSiguiente();
        delete aux;
    }*/
}

template <typename T>
bool COLA<T>::isEmpty(){
    if(start==nullptr){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
void COLA<T>::push(T dato){
    NODO<T> *nuevo = new NODO<T>(dato);
    if(isEmpty()==true){
        start = end = nuevo;
    }
    else{
        end->setSiguiente(nuevo);
        end = nuevo;
    }
}

template <typename T>
T COLA<T>::pop(){
    if(isEmpty()==true){
        //cout<<"EMPTY"<<endl;
    }
    else if(start==end){
        NODO<T> *aux = start;
        start = end = nullptr;
        return aux->getInfo();
    }
    else{
        NODO<T> *aux = start;
        start = aux->getSiguiente();
        return aux->getInfo();
    }
}

template <typename T>
void COLA<T>::print(){
    NODO<T> *aux = start;
    int x=7, y=12;
    if(start==nullptr){
        gotoxy(x,y); cout<<"VACIO     "<<endl;
    }
    else{
        while(aux != nullptr){
            gotoxy(x,y); cout<<aux->getInfo();
            gotoxy(x,y+1);clreol();
            gotoxy(x,y+2);clreol();
            y++;
            aux = aux->getSiguiente();
        }
    }
}
