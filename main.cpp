/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

*/

#include <string>
#include <iostream>
#include <sstream>
#include "Almacenamiento.h"

using namespace std;


int main(){
    int buildTrabajada=0;
    bool ciclo = true;
    cout << "Bienvenido al Creador de Builds de Hades."<< endl;
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
            cout<<"Ahora estas trabajando en la Build: "<<endl;
            cout << buildTrabajada << endl;  
        }
        else if (des==5){
            ciclo=false;
        }
    }
    
}

