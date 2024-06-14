/* 

Proyecto Builds de Hades
José Pablo Gonzalez Avila
A01706819
23/05/2023

Esta clase define a un objeto tipo Habilidad que contiene sus clases heredadas de
Slot, Pasiva y Calling, ademas de contener el metodo de como mostrar la info de cada
una de las clases a base de poliformismo. 
*/
#ifndef HABILIDAD_H_
#define HABILIDAD_H_

#include <string>
#include <iostream>
#include <sstream>


using namespace std;

// Declaracion de la calse abstracta de Habilidad
class Habilidad{
    protected:
    // Se declaran las variables de nombre, dios, rareza y efecto como strings.
        string nombre;
        string dios;
        string rareza;
        string efecto;
    public:
    /* Se crean los modificadores de acseso, el constructor de Habilidad, y un 
    metodo abstracto para poder mostrar la informacion.
    */
        Habilidad(); //Constructor por Default
        Habilidad(string,string,string,string); //Constuctor con un nombre, dios, rareza y efecto.
        string getNombre(){return nombre;}
        string getDios(){return dios;}
        string getRareza(){return rareza;}
        string getEfecto(){return efecto;}
        void setNombre(string);
        void setDios(string);
        void setRareza(string);
        void setEfecto(string);
        virtual void mostrarInfo()=0; //Metodo sobreescrito
};

Habilidad::Habilidad(){
    nombre="";
    dios= "";
    rareza="";
    efecto="";
}
Habilidad::Habilidad(string nombre_, string dios_, 
string rareza_, string efecto_){
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


//Declaracion de la clase hija de Habilidad, Slot.
class Slot : public Habilidad{
    private:
    //La variable del objeto
        string posicion;
    public:
    //Constructor, modificador de acceso y metodo para mostrar info
        Slot() : Habilidad("", "", "", ""), posicion(""){};
        Slot(string nombre_, string dios_, string rareza_, 
        string efecto_, string posicion_): 
        Habilidad(nombre_, dios_, rareza_, efecto_),posicion(posicion_){};

        string getPosicion(){return posicion;}
        void setPosicion(string);
        void mostrarInfo();
};

void Slot::setPosicion(string posicion_){
    posicion=posicion_;
}

/*
mostrarInfo en el caso de Slot muestra todos los atributos especificos 
de Slot. Estos serian nombre, dios, rarezam efecto y posicion.

@param no tiene parametros
@return no regresa nada, ya que utiliza couts
*/
void Slot::mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "Posicion: " << posicion << endl;
        cout << "Rareza: " << rareza << endl;
        cout << "Dios: " << dios << endl;
        cout << "Efecto: " << efecto << endl;
}

//Declaracion de la clase hija de Habilidad, Pasiva.
class Pasiva : public Habilidad{
    private:
        //La variable del objeto
        string prerequisito;
    public:
    //Constructor, modificador de acceso y metodo para mostrar info
        Pasiva() : Habilidad("", "", "", ""), prerequisito(""){}; //Constructor DEFAULT
        Pasiva(string nombre_, string dios_, string rareza_, string efecto_):
        Habilidad(nombre_, dios_, rareza_, efecto_),prerequisito("No tiene"){};
        //Constructor sin prerequisito
        Pasiva(string nombre_, string dios_, string rareza_, string efecto_, string prerequisito_):
        Habilidad(nombre_, dios_, rareza_, efecto_),prerequisito(prerequisito_){};
        //Constructor con prerequisito.
        string getPrerequisito(){return prerequisito;}
        void setPrerequisito(string);
        void mostrarInfo();
    
};

void Pasiva::setPrerequisito(string prerequisito_){
    prerequisito=prerequisito_;
}

/*
mostrarInfo en el caso de Pasiva muestra todos los atributos especificos 
de Pasiva. Estos serian nombre, dios, rarezam efecto y prerequisito.

@param no tiene parametros
@return no regresa nada, ya que utiliza couts
*/
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
        Calling(string nombre_, string dios_, string rareza_, string efecto_, string prerequisito_):
        Habilidad(nombre_, dios_, rareza_, efecto_),duracion(prerequisito_){};
    string getDuracion(){return duracion;}
    void setDuracion(string);
    void mostrarInfo();
};

void Calling::setDuracion(string duracion_){
    duracion=duracion_;
}

/*
mostrarInfo en el caso de Calling muestra todos los atributos especificos 
de Calling. Estos serian nombre, dios, rarezam efecto y duracion.

@param no tiene parametros
@return no regresa nada, ya que utiliza couts
*/
void Calling::mostrarInfo(){
    cout << "Nombre: " << nombre << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Rareza: " << rareza << endl;
    cout << "Dios: " << dios << endl;
    cout << "Efecto: " << efecto << endl;
}
#endif 
