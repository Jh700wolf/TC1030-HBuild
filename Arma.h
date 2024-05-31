/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

*/

#ifndef ARMA_H_
#define ARMA_H_

#include <string>
#include <iostream>
#include <sstream>


using namespace std;

//Declaracion de la clase Arma. 
class Arma {
    private:
        string nombre;
        string aspecto;
        int nivel;

    public:
        Arma();
        Arma(string, string);
        Arma(string, string, int);
        string getNombre() {return nombre;}
        string getAspecto() {return aspecto;}
        int getNivel() {return nivel;}
        void setNombre(string);
        void setAspecto(string);
        void setNivel(int);

};

Arma::Arma(){
    nombre="";
    aspecto="";
    nivel=1;

}
Arma::Arma(string nombre_, string aspecto_){
    nombre=nombre_;
    aspecto=aspecto_;
}
Arma::Arma(string nombre_, string aspecto_, int nivel_){
    nombre=nombre_;
    aspecto=aspecto_;
    nivel=nivel_;
}

void Arma::setNombre(string nombre_){
    nombre=nombre_;
}

void Arma::setAspecto(string aspecto_){
    aspecto=aspecto_;
}

void Arma::setNivel(int nivel_){
    nivel=nivel_;
}


#endif
