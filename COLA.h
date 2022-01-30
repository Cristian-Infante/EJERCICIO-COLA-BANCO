#ifndef COLA_H
#define COLA_H
#include "NODO.cpp"

template <class T>
class COLA
{
    private:
        NODO<T> *start;
        NODO<T> *end;
    public:
        COLA();
        virtual ~COLA();
        bool isEmpty();
        void push(T);
        T pop();
        void print();
};

#endif // COLA_H
