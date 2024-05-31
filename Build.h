/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

*/

#ifndef BUILD_H_
#define BUILD_H_

#include <string>
#include <iostream>
#include <sstream>
#include "Arma.h"
#include "Habilidad.h"

using namespace std;

class Build {
    private:
        string nombre;
        int numHabilidades;
        Arma arma;
        Habilidad *habilidades[30];

    public:
        Build();
        Build(string, Arma);
        void agregarArma();
        void setNombre(string);
        string getNombre(){return nombre;}
        void mostrarHabilidades();
        void agregarHabilidad();
        
};

Build::Build(){
    nombre="";
    arma=Arma();
    numHabilidades=0;
}

Build::Build(string nombre_, Arma arma_){
    nombre=nombre_;
    arma=arma_;
    numHabilidades=0;
}
void Build::setNombre(string nombre_){
    nombre=nombre_;  
}

void Build::agregarHabilidad(){
    int tipo;
    cout<<"Que tipo de Habilidad vas a crear?" <<endl;
    cout<<"1. Slot" <<endl;
    cout<<"2. Pasiva" <<endl;
    cout<<"3. Calling" <<endl;
    cin>>tipo;
    string nombre_;
    string dios_;
    string rareza_;
    string efecto_;
    cout<<"Dame el nombre de la habilidad"<<endl;
    cin>>nombre_;
    cout<<"Dame el dios de la habilidad"<<endl;
    cin>>dios_;
    cout<<"Dame la rareza de la habilidad"<<endl;
    cin>>rareza_;
    cout<<"Dame el efecto de la habilidad"<<endl;
    cin>>efecto_;
    
    if(tipo==1){
        string posicion_;
        cout<<"Dame la posicion de la habilidad"<<endl;
        cin>>posicion_;
        habilidades[numHabilidades]= new Slot(nombre_, dios_, rareza_, efecto_, posicion_);
        numHabilidades++;
    }
    if(tipo==2){
        string restricciones_;
        cout<<"Dame la restricciones"<<endl;
        cin>>restricciones_;
        habilidades[numHabilidades]= new Pasiva(nombre_, dios_, rareza_, efecto_, restricciones_);
    }
    if(tipo==3){
        string duracion_;
        cout<<"Dame la duracion de la habilidad"<<endl;
        cin>>duracion_;
        habilidades[numHabilidades]= new Calling(nombre_, dios_, rareza_, efecto_, duracion_);
        numHabilidades++;
    }
}

void Build::mostrarHabilidades(){
    cout<<"Las Habilidades son: "<<endl;
    for(int i=0; i<numHabilidades; i++){
        cout << "Habilidad " << i << endl;
        habilidades[i]->mostrarInfo();
    }
}
