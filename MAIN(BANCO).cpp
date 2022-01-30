#include "COLA.cpp"
#include "string"
#include "iostream"
#include "conio.h"
#include "ctime"
#include "windows.h"
#include "stdio.h"
using namespace std;

int delay(int secs){
    for(int i = (time(NULL) + secs); time(NULL) != i; time(NULL));
    return secs;
}

string nombres(){
    int num, DESDE=1, HASTA=10; string name;
    num = rand()%(15-1+1)+1;

    switch (num)
    {
    case(1):
        name = "Juan     ";
        return name;
        break;
    case(2):
        name = "Federico";
        return name;
        break;
    case(3):
        name = "Jose     ";
        return name;
        break;
    case(4):
        name = "Cristian";
        return name;
        break;
    case(5):
        name = "Fabian   ";
        return name;
        break;
    case(6):
        name = "Lina     ";
        return name;
        break;
    case(7):
        name = "Susana   ";
        return name;
        break;
    case(8):
        name = "Michelle";
        return name;
        break;
    case(9):
        name = "Angy     ";
        return name;
        break;
    case(10):
        name = "Paco    ";
        return name;
        break;
    case(11):
        name = "Paco    ";
        return name;
        break;
    case(12):
        name = "Luis    ";
        return name;
        break;
    case(13):
        name = "Maria    ";
        return name;
        break;
    case(14):
        name = "Fernanda    ";
        return name;
        break;
    case(15):
        name = "Pedro    ";
        return name;
        break;
    }
}

int main()
{
    string caj1="NO", caj2="NO", caj3="NO";
    string nombre;
    COLA<string> turno;

    turno.push(nombres());
    turno.push(nombres());
    turno.push(nombres());
    turno.push(nombres());
    turno.push(nombres());
    turno.push(nombres());

    for(int i=0; i<600; i++){
        if(i%1==0){
            gotoxy(7,10); cout<<"Cola"<<endl;
            turno.print();
        }

        if(i%4==0){
            turno.push(nombres());
            turno.push(nombres());
            turno.push(nombres());
            turno.print();
            if(caj1=="NO"){
                caj1 = turno.pop();
                gotoxy(12,4); cout<<caj1;
                turno.print();
            }
            else if(caj2=="NO"){
                caj2 = turno.pop();
                gotoxy(42,4); cout<<caj1;
                turno.print();
            }
            else if(caj3=="NO"){
                caj3 = turno.pop();
                gotoxy(82,4); cout<<caj1;
                turno.print();
            }
        }
        if(i%3==0){
            gotoxy(10,2); cout<<"Cajero 1"<<endl;
            if(turno.isEmpty()){
                gotoxy(12,4); cout<<"LIBRE    ";
                caj1 = "NO";
            }
            else{
                caj1 = turno.pop();
                turno.print();
                gotoxy(12,4); cout<<caj1;
            }
        }
        if(i%6==0){
            gotoxy(40,2); cout<<"Cajero 2"<<endl;
            if(turno.isEmpty()){
                gotoxy(42,4); cout<<"LIBRE    ";
                caj2 = "NO";
            }
            else{
                caj2 = turno.pop();
                turno.print();
                gotoxy(42,4); cout<<caj2;
            }
        }
        if(i%4==0){
            gotoxy(80,2); cout<<"Cajero 3"<<endl;
            if(turno.isEmpty()){
                gotoxy(82,4); cout<<"LIBRE    ";
                caj3 = "NO";
            }
            else{
                caj3 = turno.pop();
                turno.print();
                gotoxy(82,4); cout<<caj3;
            }
        }
        delay(1);
    }
}
