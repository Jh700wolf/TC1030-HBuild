/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

*/

#ifndef HABILIDAD_H_
#define HABILIDAD_H_

#include <string>
#include <iostream>
#include <sstream>


using namespace std;

class Habilidad{
    protected:
        string nombre;
        string dios;
        string rareza;
        string efecto;
    public:
        Habilidad();
        Habilidad(string,string,string,string);
        string getNombre(){return nombre;}
        string getDios(){return dios;}
        string getRareza(){return rareza;}
        string getEfecto(){return efecto;}
        void setNombre(string);
        void setDios(string);
        void setRareza(string);
        void setEfecto(string);
        virtual void mostrarInfo();
};
Habilidad::Habilidad(){
    nombre="";
    dios= "";
    rareza="";
    efecto="";
}
Habilidad::Habilidad(string nombre_, string dios_, string rareza_, string efecto_){
    nombre=nombre_;
    dios= dios_;
    rareza=rareza_;
    efecto=efecto_;
}
void Habilidad::setNombre(string nombre_){
    nombre=nombre_;
}
void Habilidad::setDios(string dios_){
    dios=dios_;
}
void Habilidad::setRareza(string rareza_){
    rareza=rareza_;
}
void Habilidad::setEfecto(string efecto_){
    efecto=efecto_;
}
void Habilidad::mostrarInfo(){
    cout << "Nombre: " << nombre << endl;
    cout << "Rareza: " << rareza << endl;
    cout << "Dios: " << dios << endl;
    cout << "Efecto: " << efecto << endl;
}


class Slot : public Habilidad{
    private:
        string posicion;
    public:
        Slot() : Habilidad("", "", "", ""), posicion(""){};
        Slot(string nombre_, string dios_, string rareza_, string efecto_, string posicion_): Habilidad(nombre_, dios_, rareza_, efecto_),posicion(posicion_){};
        string getPosicion(){return posicion;}
        void setPosicion(string);
        void mostrarInfo();
};

void Slot::setPosicion(string posicion_){
    posicion=posicion_;
}

void Slot::mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "Posicion: " << posicion << endl;
        cout << "Rareza: " << rareza << endl;
        cout << "Dios: " << dios << endl;
        cout << "Efecto: " << efecto << endl;
}


class Pasiva : public Habilidad{
    private:
        string prerequisito;
    public:
        Pasiva() : Habilidad("", "", "", ""), prerequisito(""){};
        Pasiva(string nombre_, string dios_, string rareza_, string efecto_): Habilidad(nombre_, dios_, rareza_, efecto_),prerequisito("No tiene"){};
        Pasiva(string nombre_, string dios_, string rareza_, string efecto_, string prerequisito_): Habilidad(nombre_, dios_, rareza_, efecto_),prerequisito(prerequisito_){};
        string getPrerequisito(){return prerequisito;}
        void setPrerequisito(string);
        void mostrarInfo();
    
};

void Pasiva::setPrerequisito(string prerequisito_){
    prerequisito=prerequisito_;
}

void Pasiva::mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "Prereq: " << prerequisito << endl;
        cout << "Rareza: " << rareza << endl;
        cout << "Dios: " << dios << endl;
        cout << "Efecto: " << efecto << endl;
}

class Calling : public Habilidad{
    private:
        string duracion;
    public:
        Calling() : Habilidad("", "", "", ""), duracion(""){};
        Calling(string nombre_, string dios_, string rareza_, string efecto_, string prerequisito_): Habilidad(nombre_, dios_, rareza_, efecto_),duracion(prerequisito_){};
    string getDuracion(){return duracion;}
    void setDuracion(string);
    void mostrarInfo();
};

void Calling::setDuracion(string duracion_){
    duracion=duracion_;
}
void Calling::mostrarInfo(){
    cout << "Nombre: " << nombre << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Rareza: " << rareza << endl;
    cout << "Dios: " << dios << endl;
    cout << "Efecto: " << efecto << endl;
}
#endif 
