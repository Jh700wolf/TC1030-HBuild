/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

*/
#ifndef ALMACENAMIENTO_H_
#define ALMACENAMIENTO_H_

#include <string>
#include <iostream>
#include <sstream>
#include "Build.h"
using namespace std;

class Almacenamiento{
    private:
        int numBuilds;
        Build *build[100];
    public: 
        Almacenamiento():numBuilds(0) {};
        void crearBuild();
        void mostrarBuilds();
        void agregarHabBuild(int);
        void mostrarBuildEspecifica(int);
};

void Almacenamiento::mostrarBuildEspecifica(int pos){
    cout << "Esta Build se llama:" << endl;
    cout << build[pos]->getNombre() <<endl;
    build[pos]->mostrarHabilidades();
}
void Almacenamiento::agregarHabBuild(int pos){
    build[pos]->agregarHabilidad();
}

void Almacenamiento::crearBuild(){
  string nombre_build;
  string nombre_arma;
  string aspecto;
  int nivel;
  cout << "Dame el nombre del build: " << endl;
  cin >> nombre_build;
  cout << "Dame el nombre del arma: " << endl;
  cin >> nombre_arma;
  cout << "Dame el aspecto del arma: " << endl;
  cin >> aspecto;
  cout << "Dame el nivel del arma:" << endl;
  cin >> nivel;
  build[numBuilds] = new Build(nombre_build, Arma(nombre_arma, aspecto, nivel));
  numBuilds+=1;
  
}

void Almacenamiento::mostrarBuilds(){
  for(int i=0; i<numBuilds; i++){
    cout << "Build " << i << endl;
    cout << build[i]->getNombre()<< endl;
  }
}

#endif