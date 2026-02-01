#ifndef LISTADOVENDEDOR_H_INCLUDED
#define LISTADOVENDEDOR_H_INCLUDED

#include "../../clases/Vendedor.h"
#include "../../clsArchivo/ArchivoVendedor.h"

#include <iostream>
#include <iomanip>
using namespace std;

void listarVendedores();
void listarDeMayorAMenorVentasVendedor();
void listarDeMenorAMayorVentasVendedor();
void listaAntiguedadMenorAMayorVendedor();
void listaAntiguedadMayorAMenorVendedor();

void listarDeMayorAMenorVentasVendedor(){
    system("cls");
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMaximo;

    Vendedor *vVendedores;

    cantidad=regVendedor.contarArchivo();
    vVendedores = new Vendedor[cantidad];

    if(vVendedores == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedores, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedores[j].getventasRealizadas() > vVendedores[posMaximo].getventasRealizadas() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Vendedor aux = vVendedores[i];
                vVendedores[i] = vVendedores[posMaximo];
                vVendedores[posMaximo] = aux;
                }
        }

    if(cantidad!=0){

        cout<<"LISTADO DE VENDEDORES ORDENADOS DE MAYOR A MENOR CANTIDAD DE VENTAS REALIZADAS"<<endl;
        cout<<endl;
        cout << left << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Cargo" << setw(15) << "Ventas" << setw(15) << "Antiguedad" << endl;
            for(int i=0; i<cantidad; i++)
        {
        if(vVendedores[i].getEstado())
            {
            vVendedores[i].Mostrar(true);
            }
        }


        }


    delete [] vVendedores;
    system("pause");
}

void listarDeMenorAMayorVentasVendedor(){

    system("cls");
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMinimo;

    Vendedor *vVendedor;

    cantidad=regVendedor.contarArchivo();
    vVendedor = new Vendedor[cantidad];

    if(vVendedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedor[j].getventasRealizadas() < vVendedor[posMinimo].getventasRealizadas() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Vendedor aux = vVendedor[i];
                vVendedor[i] = vVendedor[posMinimo];
                vVendedor[posMinimo] = aux;
                }
        }

        cout<<"LISTADO DE VENDEDORES ORDENADOS DE MENOR A MAYOR CANTIDAD DE VENTAS REALIZADAS"<<endl;
        cout<<endl;
        cout << left << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Cargo" << setw(15) << "Ventas" << setw(15) << "Antiguedad" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vVendedor[i].getEstado())
            {
            vVendedor[i].Mostrar(true);
            }
    }

    delete [] vVendedor;
    system("pause");
}

void listaAntiguedadMenorAMayorVendedor(){
    system("cls");
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMinimo;

    Vendedor *vVendedor;

    cantidad=regVendedor.contarArchivo();
    vVendedor = new Vendedor[cantidad];

    if(vVendedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedor[j].getaniosAntiguedad() < vVendedor[posMinimo].getaniosAntiguedad() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Vendedor aux = vVendedor[i];
                vVendedor[i] = vVendedor[posMinimo];
                vVendedor[posMinimo] = aux;
                }
        }

    cout<<"LISTADO DE VENDEDORES ORDENADOS DE MENOR A MAYOR ANTIGUEDAD"<<endl;
    cout<<endl;
    cout << left << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Cargo" << setw(15) << "Ventas" << setw(15) << "Antiguedad" << endl;

    for(int i=0; i<cantidad; i++)
    {
        if(vVendedor[i].getEstado())
        {
        vVendedor[i].Mostrar(true);
        }
    }

    delete [] vVendedor;
    system("pause");
}

void listaAntiguedadMayorAMenorVendedor(){
    system("cls");
    ArchivoVendedor regVendedor("../../data/vendedores.dat");

    int i, j,cantidad,posMaximo;

    Vendedor *vVendedor;

    cantidad=regVendedor.contarArchivo();
    vVendedor = new Vendedor[cantidad];

    if(vVendedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regVendedor.vectorizarArchivo(vVendedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vVendedor[j].getaniosAntiguedad() > vVendedor[posMaximo].getaniosAntiguedad() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Vendedor aux = vVendedor[i];
                vVendedor[i] = vVendedor[posMaximo];
                vVendedor[posMaximo] = aux;
                }
        }
    cout<<"LISTADO DE VENDEDORES ORDENADOS DE MAYOR A MENOR ANTIGUEDAD"<<endl;
    cout<<endl;
    cout << left << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Cargo" << setw(15) << "Ventas" << setw(15) << "Antiguedad" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vVendedor[i].getEstado())
            {
            vVendedor[i].Mostrar(true);
            }
    }

    delete [] vVendedor;
    system("pause");
}

void listarVendedores(){
    //cout<<"5-LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    //cout<<"--------------------"<<endl;
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    regVendedor.leerArchivo();
    cout<<"-------------------------"<<endl;
    system("pause");
}

#endif // LISTADOVENDEDOR_H_INCLUDED
