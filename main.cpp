/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

Este es un proyecto que tiene como funcion almacenar la informacion de las distintas 
"Builds" que quiera hacer el usuario. Despues nos permite enseñar todas sus Habilidades
para que dentro del juego sepa que dioses elegir, ademas de ver como funcionan las
Habilidades.
*/

#include <string>
#include <iostream>
#include <sstream> //Para el uso de Strings
#include "Almacenamiento.h" //Biblioteca de mi proyecto

using namespace std;


int main(){
    int buildTrabajada=0; //Se usa para saber donde esta trabajando el usuario.
    bool ciclo = true;
    cout << "Bienvenido al Creador de Builds de Hades."<< endl;
    cout << "Este es un almacenamiento de infromacion para tus Builds de Hades."<<endl;
    cout << "Comienza creando tu primera Build."<< endl;
    Almacenamiento almacenamientoBuilds;
    almacenamientoBuilds.crearBuild();
    while (ciclo==true){
        cout << "Dime que deseas hacer: "<< endl;
        cout << "1. Crear una nueva Build"<< endl;
        cout << "2. Ver Info de la Build"<< endl;
        cout << "3. Agregar Habilidad a la Build actual" << endl;
        cout << "4. Cambiar de Build" << endl;
        cout << "5. Salir" << endl;
        int des;
        cin >> des;
        if(des==1){
            almacenamientoBuilds.crearBuild();
            buildTrabajada=almacenamientoBuilds.getNumBuilds()-1;
        }
        if (des==2){
            almacenamientoBuilds.mostrarBuildEspecifica(buildTrabajada);
        }
        else if (des==3){
            almacenamientoBuilds.agregarHabBuild(buildTrabajada);
        }
        else if (des==4){
            cout<<"Estas son las Builds que tienes disponibles: "<<endl;
            almacenamientoBuilds.mostrarBuilds();
            cout<<"Estas trabajando en la Build: "<<endl;
            cout << buildTrabajada << endl;
            cout<<"Dime el numero de la Build que quieres trabajar: "<<endl;
            cin>>buildTrabajada;
            cout<<almacenamientoBuilds.getNumBuilds()<<endl;
            if (buildTrabajada >= almacenamientoBuilds.getNumBuilds()){
                cout<<"Esta Build no existe!"<<endl;
            }
            else{
                cout<<"Ahora estas trabajando en la Build: "<<endl;
                cout<<buildTrabajada<<endl;
            }
        }
        else if (des==5){
            ciclo=false;
            almacenamientoBuilds.~Almacenamiento();
        }
    }
    
}

