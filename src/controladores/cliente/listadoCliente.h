#ifndef LISTADOCLIENTE_H_INCLUDED
#define LISTADOCLIENTE_H_INCLUDED

#include "../../clases/Cliente.h"
#include "../../clsArchivo/ArchivoCliente.h"

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void listarClientes();
void listarClientesResumido();
void listarDeMayorAMenorVentas();
void listarDeMenorAMayorVentas();
void listaIdMenorAMayorCliente();
void listaIdMayorAMenorCliente();
void listaCuitMenorAMayorCliente();
void listaCuitMayorAMenorCliente();
void listaAlfabeticamenteCliente();
void listarRecaudacion();
void listarRecaudacionPorCliente();
void elegirClienteRecaudacion();

void listarClientes(){
    system("cls");
    cout<<"LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    cout<<"--------------------"<<endl;

    ArchivoCliente regCliente("../../data/clientes.dat");
    //regCliente.leerArchivo();
    cout<<"-------------------------"<<endl;
    system("pause");
}

void listarClientesResumido() {
    ArchivoCliente regCliente("../../data/clientes.dat");
    Cliente cliente;
    FILE *p = fopen("../../data/clientes.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CLIENTES" << endl;
        return;
    }

    cout << "CLIENTES DISPONIBLES:" << endl;
    cout << left << setw(10) << "ID" << setw(50) << "NOMBRE/RAZON SOCIAL" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    bool hayClientes = false;
    while (fread(&cliente, sizeof(cliente), 1, p) == 1) {
        if (cliente.getEstado()) {
            cout << left << setw(10) << cliente.getId()
                 << setw(50) << cliente.getNombre() << endl;
            hayClientes = true;
        }
    }

    if (!hayClientes) {
        cout << "NO HAY CLIENTES REGISTRADOS" << endl;
    }

    fclose(p);
    cout << endl;
}

void listarDeMayorAMenorVentas(){
    system("cls");
    cout<<"LISTAR DE MAYOR A MENOR VENTAS."<<endl;
    cout<<"----------------------------"<<endl;
    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getcantidadVentas() > vClientes[posMaximo].getcantidadVentas() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(25) << "Razon Social" << setw(35) << "CUIT" << setw(15) << "Ventas" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(25) << vClientes[i].getNombre() << setw(35) << vClientes[i].getCuit() << setw(15) << vClientes[i].getcantidadVentas() << endl << endl;

            }
    }

    delete [] vClientes;
    system("pause");
}

void listarDeMenorAMayorVentas(){
    system("cls");
    cout<<"LISTAR DE MENOR A MAYOR VENTAS."<<endl;
    cout<<"--------------------"<<endl;
    ArchivoCliente regClientes("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regClientes.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regClientes.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getcantidadVentas() < vClientes[posMinimo].getcantidadVentas() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(25) << "Razon Social" << setw(35) << "CUIT" << setw(15) << "Ventas" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(25) << vClientes[i].getNombre() << setw(35) << vClientes[i].getCuit() << setw(15) << vClientes[i].getcantidadVentas() << endl << endl;

            }
    }

    delete [] vClientes;
    system("pause");
}

void listaIdMenorAMayorCliente(){
    system("cls");
    cout<<"ORDENAR POR ID DE MENOR A MAYOR."<<endl;
    cout<<"--------------------"<<endl;

    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getId() < vClientes[posMinimo].getId() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
    system("pause");
}

void listaIdMayorAMenorCliente(){
    system("cls");
    cout<<"ORDENAR POR ID DE MAYOR A MENOR."<<endl;
    cout<<"--------------------"<<endl;

    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getId() > vClientes[posMaximo].getId() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
    system("pause");
}

void listaCuitMenorAMayorCliente(){

    system("cls");
    cout<<"LISTAR POR CUIT DE MENOR A MAYOR."<<endl;
    cout<<"--------------------"<<endl;

    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];
    int resultado;

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {

                resultado = strcmp(vClientes[posMinimo].getCuit(),vClientes[j].getCuit());

                if(resultado > 0)
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Nombre/Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
        {

        cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

        }
    }

    delete [] vClientes;
    system("pause");
}

void listaCuitMayorAMenorCliente(){
    system("cls");
    cout<<"LISTAR POR CUIT DE MAYOR A MENOR."<<endl;
    cout<<"--------------------"<<endl;

    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];
    int resultado;

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                resultado = strcmp(vClientes[posMaximo].getCuit(),vClientes[j].getCuit());

                if(resultado < 0)
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Nombre/Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
    system("pause");
}

void listaAlfabeticamenteCliente(){
    system("cls");
    cout<<"LISTAR ALFABETICAMENTE."<<endl;
    cout<<"--------------------"<<endl;

    ArchivoCliente regCliente("../../data/clientes.dat");

    int i, j,cantidad,posMaximo;

    Cliente *vClientes;

    cantidad=regCliente.contarArchivo();
    vClientes = new Cliente[cantidad];
    int resultado;

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regCliente.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                resultado = strcmp(vClientes[posMaximo].getNombre(),vClientes[j].getNombre());

            /*  strcmp("Ana", "Carlos")    // RETORNA < 0 (ANA VIENE ANTES)
                strcmp("Maria", "Maria")   // RETORNA 0 (SON IGUALES)
                strcmp("Pedro", "Ana")     // RETORNA > 0 (PEDRO VIENE DESPUES) */

                if(resultado > 0)
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMaximo];
                vClientes[posMaximo] = aux;
                }
        }
    cout << left << setw(5) << "ID" << setw(55) << "Nombre/Razon Social" << setw(15) << "CUIT" << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {

            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << vClientes[i].getId() << setw(55) << vClientes[i].getNombre() << setw(15) << vClientes[i].getCuit() << endl << endl;

            }
    }

    delete [] vClientes;
    system("pause");
}

void listarRecaudacion(){
    system("cls");

    ArchivoCliente regCliente("../../data/clientes.dat");

    int opcion;
    cout<<"CONSULTAS DE RECAUDACION"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<"1 - RECAUDACION POR CLIENTE."<<endl;
    cout<<"2 - ELEGIR CLIENTE PARA RECAUDACION."<<endl;
    cin>>opcion;
    system("cls");
    switch(opcion){
        case 1:
        listarRecaudacionPorCliente();

        break;

        case 2:
        elegirClienteRecaudacion();

        break;
    }
}

void listarRecaudacionPorCliente(){
    ArchivoCliente regClientes("../../data/clientes.dat");

    int i, j,cantidad,posMinimo;

    Cliente *vClientes;

    cantidad=regClientes.contarArchivo();
    vClientes = new Cliente[cantidad];

    if(vClientes == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    regClientes.vectorizarArchivo(vClientes, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vClientes[j].getRecaudacion() < vClientes[posMinimo].getRecaudacion() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Cliente aux = vClientes[i];
                vClientes[i] = vClientes[posMinimo];
                vClientes[posMinimo] = aux;
                }
        }
    cout << left << setw(25) << "Nombre o Razon Social" << setw(35) << "Recaudacion" << endl;
    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(vClientes[i].getEstado())
            {


            cout << left << setw(25) << vClientes[i].getNombre() << setw(35) << vClientes[i].getRecaudacion() << endl;

            }
    }

    delete [] vClientes;
    system("pause");
}

void elegirClienteRecaudacion(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    listarClientesResumido();
    cout<<"INGRESE EL ID DEL CLIENTE A BUSCAR: ";
    cin>>id;
    system("cls");
    regCliente.encontrarClienteRecaudacion(id);
    system("pause");
}

#endif // LISTADOCLIENTE_H_INCLUDED
