#ifndef LISTADOARTICULO_H_INCLUDED
#define LISTADOARTICULO_H_INCLUDED

#include "../../clases/Articulo.h"
#include "../../clsArchivo/ArchivoArticulo.h"

#include <iostream>
#include <iomanip>
using namespace std;



void listaDeArticulos();
void listaArticulosSimplificada();
void listaArticulosStock();
void listarArticuloPorPrecioDeMayorAMenor();
void listarArticuloPorPrecioDeMenorAMayor();
void listaArticuloPorIdDeMayorAMenor();
void listaArticuloPorIdDeMenorAMayor();

void listaDeArticulos(){
    ArchivoArticulo ArchivoArticulo("../../data/articulos.dat");
    ArchivoArticulo.mostrarArticulo();
}

void listaArticulosSimplificada(){
    system("cls");
    ArchivoArticulo ArchivoArticulo;
    Articulo Articulo;

    FILE *p=fopen( ArchivoArticulo.getNombre(),"rb" );
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    cout << "LISTA DE ARTICULOS:" << endl;
    cout << "--------------------------------" << endl;
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        if(Articulo.getEstado()==true){
            cout << "ID: " << Articulo.getId() << " | DESCRIPCION: " << Articulo.getDescripcion() << " | PRECIO VENTA: $" << Articulo.getCosto() * (1 + Articulo.getGanancia() / 100.0) << endl;
        }
    }
    fclose(p);
    //system ("pause");
}

void listaArticulosStock(){
    system("cls");
    ArchivoArticulo ArchivoArticulo;
    Articulo Articulo;

    FILE *p=fopen( ArchivoArticulo.getNombre(),"rb" );
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    cout << "LISTA DE ARTICULOS:" << endl;
    cout << "--------------------------------" << endl;
    while(fread(&Articulo,sizeof Articulo,1,p)==1){
        if(Articulo.getEstado()==true){
            cout << "ID: " << Articulo.getId() << " | DESCRIPCION: " << Articulo.getDescripcion() << " | UNIDADES: " << Articulo.getUnidades() << endl;
        }
    }
    fclose(p);
}

void listarArticuloPorPrecioDeMayorAMenor(){

    system("cls");
    cout << "LISTADO DE ARTICULOS POR PRECIO DE MAYOR A MENOR" << endl;
    cout << "------------------------------------------------" << endl;

    ArchivoArticulo regArchivo("../../data/articulos.dat");

    int i, j,cantidad,posMaximo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        system ("pause");
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {

                float precioVenta = vArticulos[j].getCosto() * ( 1 + vArticulos[j].getGanancia()/100.0 );
                float precioVentaMax = vArticulos[posMaximo].getCosto() * ( 1 + vArticulos[posMaximo].getGanancia()/100.0 );

                if( precioVenta > precioVentaMax )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMaximo];
                vArticulos[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar(true);
            }
    }
    delete [] vArticulos;
    system ("pause");
}

void listarArticuloPorPrecioDeMenorAMayor(){

    system("cls");
    cout << "LISTADO DE ARTICULOS POR PRECIO DE MENOR A MAYOR" << endl;
    cout << "------------------------------------------------" << endl;

    ArchivoArticulo regArchivo("../../data/articulos.dat");

    int i, j,cantidad,posMinimo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {

                float precioVenta = vArticulos[j].getCosto() * ( 1 + vArticulos[j].getGanancia()/100.0 );
                float precioVentaMin = vArticulos[posMinimo].getCosto() * ( 1 + vArticulos[posMinimo].getGanancia()/100.0 );

                if( precioVenta < precioVentaMin )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMinimo];
                vArticulos[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar(true);
            }
    }

    delete [] vArticulos;
    system ("pause");
}

void listaArticuloPorIdDeMayorAMenor(){
    system("cls");
    cout << "LISTADO DE ARTICULOS POR ID DE MAYOR A MENOR   " << endl;
    cout << "-----------------------------------------------" << endl;
    ArchivoArticulo regArchivo("../../data/articulos.dat");

    int i, j,cantidad,posMaximo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vArticulos[j].getId() > vArticulos[posMaximo].getId() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMaximo];
                vArticulos[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar(true);
            }
    }

    delete [] vArticulos;
    system ("pause");
}

void listaArticuloPorIdDeMenorAMayor(){


    system("cls");
    cout << "LISTADO DE ARTICULOS POR ID DE MENOR A MAYOR" << endl;
    cout << "-----------------------------------------------" << endl;
    ArchivoArticulo regArchivo("../../data/articulos.dat");

    int i, j,cantidad,posMinimo;

    Articulo *vArticulos;

    cantidad=regArchivo.contarArchivo();
    vArticulos = new Articulo[cantidad];

    if(vArticulos == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regArchivo.vectorizarArchivo(vArticulos, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vArticulos[j].getId() < vArticulos[posMinimo].getId() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Articulo aux = vArticulos[i];
                vArticulos[i] = vArticulos[posMinimo];
                vArticulos[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vArticulos[i].getEstado())
            {
            vArticulos[i].Mostrar(true);
            }
    }

    delete [] vArticulos;
    system ("pause");
}

#endif // LISTADOARTICULO_H_INCLUDED
