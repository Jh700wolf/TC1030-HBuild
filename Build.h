/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

Esta clase define los objetos tipo build. Aqui estan los metodos de
la clase. Ademas, tiene las formas de crear habilidades y agregarlas.
*/

#ifndef BUILD_H_
#define BUILD_H_

#include <string>
#include <iostream>
#include <sstream>
#include "Arma.h" //Biblioteca de objetos tipo Arma
#include "Habilidad.h"  //Biblioteca de objetos tipo Habilidad.

using namespace std;

class Build {
    private:
    //Declaracion de las variables privadas
        string nombre;
        int numHabilidades;
        Arma arma;
        Habilidad *habilidades[30]; //Arreglo de apuntadores (poliformismo) de habilidades
    /*Declaracion de metodos de la clase. Modificadores de acceso, constructores y
    maneras de mostrar y agregar habilidades*/
    public:
        Build(); //Constructor Default
        Build(string, Arma); //Constructor
        void agregarArma();
        void setNombre(string);
        string getNombre(){return nombre;}
        void mostrarHabilidades(); //Metodo que muestra las Habilidades.
        void agregarHabilidad(); //Mestodo que agrega las Habilidades.
        
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

/*
agregarHabilidad permite al usuario elegir que tipo de habilidad va a agregar a su Build.
Una vez seleccionado, se le va a pedir la informacion requerida para ese tipo de Habilidad.
Finalmente, crea el objeto tipo Habilidad guardandolo en el Heap.

@param no tiene parametros
@return no regresa nada, ya que utiliza couts
*/
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
    cout<<"Dame el nombre de la habilidad. Asegurate de usar _ para marcar espacios: "<<endl;
    cin>>nombre_;
    cout<<"Dame el dios de la habilidad. Asegurate de usar _ para marcar espacios: "<<endl;
    cin>>dios_;
    cout<<"Dame la rareza de la habilidad. Asegurate de usar _ para marcar espacios: "<<endl;
    cin>>rareza_;
    cout<<"Dame el efecto de la habilidad. Asegurate de usar _ para marcar espacios:"<<endl;
    cin>>efecto_;
    
    if(tipo==1){
        string posicion_;
        cout<<"Dame la posicion de la habilidad. Asegurate de usar _ para marcar espacios:"<<endl;
        cin>>posicion_;
        habilidades[numHabilidades]= new Slot(nombre_, dios_, rareza_, efecto_, posicion_);
        numHabilidades++;
    }
    if(tipo==2){
        int restric;
        cout<<"Esta pasiva tiene alguna restriccion? 0) NO 1) SI"<<endl;
        cin>>restric;
        cout<<restric;
        if(restric==0){
            habilidades[numHabilidades]= new Pasiva(nombre_, dios_, rareza_, efecto_);
            numHabilidades++;
        }
        else if(restric==1){
            string restricciones_;
            cout<<"Dame la restricciones. Asegurate de usar _ para marcar espacios:"<<endl;
            cin>>restricciones_;
            habilidades[numHabilidades]= new Pasiva(nombre_, dios_, rareza_, efecto_, restricciones_);
            numHabilidades++;
        }
    }
    if(tipo==3){
        string duracion_;
        cout<<"Dame la duracion de la habilidad. Asegurate de usar _ para marcar espacios:"<<endl;
        cin>>duracion_;
        habilidades[numHabilidades]= new Calling(nombre_, dios_, rareza_, efecto_, duracion_);
        numHabilidades++;
    }
}

/*
mostrarHabilidades hace uso de poliformismo y llama al metodo de mostrar info
el cual es diferente para cada una de las habilidades con apuntadores dentro de
el arreglo de la Build..

@param no tiene parametros
@return no regresa nada, ya que utiliza couts
*/
void Build::mostrarHabilidades(){
    cout<<"Las Habilidades son: "<<endl;
    for(int i=0; i<numHabilidades; i++){
        cout << "Habilidad " << i << endl;
        habilidades[i]->mostrarInfo();
    }
}
#endif
