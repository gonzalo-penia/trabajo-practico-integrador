#pragma once

#include <cstring>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#ifndef CONTACTO_H_INCLUDED
    #include "../clases/Contacto.h"
#endif

#ifndef FUNCIONESGLOBALES_H_INCLUDED
    #include "../globales/funcionesGlobales.h"
#endif

//ARCHIVO DE CONTACTOS

class ArchivoContacto{

private:

    char nombre[30];

public:
    ArchivoContacto(const char *n="../../data/contactos.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
    }
    const char *getNombre(){return nombre;}
    bool escribirArchivo(Contacto regContacto);
    Contacto leerArchivo(int pos);
    void leerArchivo();
    bool modificarArchivo(int pos, Contacto regContacto);

    int buscarEnArchivo(int id);
    int buscarRegistro(int id);
    int buscarRegistro(const char* cuit);

    int contarArchivo();
    void encontrarContacto(int id);
    int buscarSinMostrar(int id);
    int obtenerIdDisponible();
};

int ArchivoContacto::obtenerIdDisponible(){
    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        // SI NO EXISTE EL ARCHIVO, EL PRIMER ID DISPONIBLE ES 1
        return 1;
    }
    int contador = 0;
    while(fread(&regContacto,sizeof regContacto,1,p)==1){
        contador++;
    }
    fclose(p);
    return contador + 1;
}

int ArchivoContacto::buscarEnArchivo(int id){

    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return -2;
    }

    int contador=0;
    while(fread(&regContacto, sizeof (regContacto),1,p)==1){
        if(regContacto.getIdContacto()==id){
            cout<<endl<<"SE ENCONTRO UN CONTACTO: "<<endl;
            regContacto.Mostrar();
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

int ArchivoContacto::buscarRegistro(int id){

    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return -2;
    }

    int contador=0;
    while(fread(&regContacto, sizeof (regContacto),1,p)==1){
        if(regContacto.getIdContacto()==id && regContacto.getEstado()==true){
            cout<<endl<<"SE ENCONTRO UN CONTACTO CON ESE ID: "<<endl<<endl;
            cout << left << setw(5) << "ID" << setw(30) << "Nombre" << setw(20) << "Telefono" << endl;
            cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regContacto.getIdContacto() << setw(30) << regContacto.getNombreContacto() << setw(20) << regContacto.getNroTelefono() << endl << endl;
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

int ArchivoContacto::buscarRegistro(const char* email){
    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoContacto-buscarRegistro)"<<endl;
        return -2;
    }
    int contador=0;
    while(fread(&regContacto,sizeof (regContacto),1,p)==1){
        if(strcmp(regContacto.getEmail(),email)==0 && regContacto.getEstado()==true){
            cout<<endl<<"SE ENCONTRO UN CONTACTO CON ESE EMAIL: "<<endl<<endl;
            cout << left << setw(5) << "ID" << setw(30) << "Nombre" << setw(20) << "Email" << endl;
            cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regContacto.getIdContacto() << setw(30) << regContacto.getNombreContacto() << setw(20) << regContacto.getEmail() << endl << endl;
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

bool ArchivoContacto::escribirArchivo(Contacto regContacto){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(&regContacto,sizeof (regContacto),1,p);
    fclose(p);
    return true;
}

Contacto ArchivoContacto::leerArchivo(int pos){
    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoContacto-leerArchivo)"<<endl;
        return regContacto;
    }
    fseek (p,sizeof(Contacto)*pos,0);
    fread(&regContacto,sizeof (regContacto),1,p);
    fclose(p);
    return regContacto;
}

void ArchivoContacto::leerArchivo(){
    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoContacto-leerArchivo)"<<endl;
        return ;
    }
    cout << left << setw(5) << "ID" << setw(30) << "Nombre" << setw(20) << "Telefono" << setw(30) << "Email" << endl;
    while(fread(&regContacto, sizeof (regContacto),1,p)==1){
        if(regContacto.getEstado()){
            cout << setfill('-') << setw(85) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regContacto.getIdContacto() << setw(30) << regContacto.getNombreContacto() << setw(20) << regContacto.getNroTelefono() << setw(30) << regContacto.getEmail() << endl;
        }
    }
    fclose(p);
    return;
}

bool ArchivoContacto::modificarArchivo(int pos, Contacto regContacto){
    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoContacto-modificarArchivo)"<<endl;
        return false;
    }
    fseek (p,sizeof(regContacto)*pos,0);
    bool confirmacion=fwrite(&regContacto,sizeof (regContacto),1,p);
    fclose(p);
    return confirmacion; //DEVUELVE CONFIRMACION EN CASO DE SER EXITOSO
}

int ArchivoContacto::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoContacto-contarArchivo)"<<endl;
    return false;
    }
    int contador = 0;
    while(fread(&regContacto,sizeof (regContacto),1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoContacto::encontrarContacto(int id){
    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&regContacto,sizeof (regContacto),1,p)==1){
        if(regContacto.getIdContacto()==id){
            if(regContacto.getEstado()){
                regContacto.Mostrar();
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE ID"<<endl;
            }
        }
    }
    fclose(p);
}

int ArchivoContacto::buscarSinMostrar(int id){

    Contacto regContacto;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return -2;
    }

    int contador=0;
    while(fread(&regContacto, sizeof (regContacto),1,p)==1){
        if(regContacto.getIdContacto()==id){
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

