/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

Esta clase funciona como el almacenamiento de todas las builds. 
Contiene metodos para crear builds, mostrar su informacion, y agregar habilidades
a una build especifica.
*/
#ifndef ALMACENAMIENTO_H_
#define ALMACENAMIENTO_H_

#include <string>
#include <iostream>
#include <sstream>
#include "Build.h" //Biblioteca de clase Build
using namespace std;

class Almacenamiento{
  //Se declaran las variables privadas.
    private:
        int numBuilds=0;
        Build *build[100]; //Arreglo de apuntadores 
    public: 
    /*Se declaran los metodos. Hay constructores, modificadores de accerso, metodo
    para crear una build, metodo para mostrarla, metodo para agregar una Habilidad,
    metodo para mostrar la info de la Build, etc.*/
        Almacenamiento():numBuilds(0) {};
        ~Almacenamiento();
        void crearBuild();
        void mostrarBuilds();
        void agregarHabBuild(int);
        void mostrarBuildEspecifica(int);
        int getNumBuilds(){return numBuilds;}
};

Almacenamiento::~Almacenamiento() {
    for (int i = 0; i < numBuilds; ++i) {
        delete build[i]; // Liberar la memoria asignada a cada Build
    }
}
/*
mostrarBuildEspecifica es una funcion la cual recibe la posicion de una build en el
arreglo y despues regresa el nombre de la build y sus habilidades.

@param un int de la posicion de la Build dentro del arreglo
@return no regresa nada, ya que utiliza couts
*/
void Almacenamiento::mostrarBuildEspecifica(int pos){
    cout << "Esta Build se llama:" << endl;
    cout << build[pos]->getNombre() <<endl;
    build[pos]->mostrarHabilidades();
/*
agregarHabBuild es una funcion la cual recibe la posicion de una build en el arreglo
y despues hace uso de la funcion agregarHabilidad de la Build.

@param un int de la posicion de la Build dentro del arreglo
@return no regresa nada, ya que utiliza couts
*/
}
void Almacenamiento::agregarHabBuild(int pos){
    build[pos]->agregarHabilidad();
}

/*
crearBuild es una funcion que pide al usuario la informacion basica para la creacion
de una Build junto con su arma. Aqui se crea el objeto arma. Despues, crea la Build.

@param no tiene
@return no regresa nada, ya que utiliza couts
*/
void Almacenamiento::crearBuild(){
  string nombre_build;
  string nombre_arma;
  string aspecto;
  int nivel;
  cout << "Dame el nombre del build. Asegurate de usar _ para marcar espacios: " << endl;
  cin >> nombre_build;
  cout << "Dame el nombre del arma. Asegurate de usar _ para marcar espacios: " << endl;
  cin >> nombre_arma;
  cout << "Dame el aspecto del arma. Asegurate de usar _ para marcar espacios: " << endl;
  cin >> aspecto;
  cout << "Dame el nivel del arma. Asegurate de usar _ para marcar espacios:" << endl;
  cin >> nivel;
  build[numBuilds] = new Build(nombre_build, Arma(nombre_arma, aspecto, nivel));
  numBuilds+=1;
  
}

/*
mostrarBuilds es una funcion que va a mostrar  el nombre de cada una de las builds
dentro del arreglo de almacenamiento.

@param no tiene
@return no regresa nada, ya que utiliza couts
*/
void Almacenamiento::mostrarBuilds(){
  for(int i=0; i<numBuilds; i++){
    cout << "Build " << i << endl;
    cout << build[i]->getNombre()<< endl;
  }
}


#endif
