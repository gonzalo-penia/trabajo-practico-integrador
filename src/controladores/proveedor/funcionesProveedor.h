#ifndef FUNCIONESPROVEEDOR_H_INCLUDED
#define FUNCIONESPROVEEDOR_H_INCLUDED

#include "listadoProveedor.h"

void cargarProveedor();
void buscarProveedor();

inline void cargarProveedor(){
    system ("cls");
    Proveedor regProveedor;
    ArchivoProveedor regArchivoProveedor;
    int id;
    cout<<"CARGA DE NUEVO PROVEEDOR."<<endl<<endl;
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SERAN SOLICITADOS."<<endl<<endl;
    bool aux=true;
    while (aux==true){
        bool continuar;
        do{
            id = regArchivoProveedor.obtenerIdDisponible();
            cout<<"ID ASIGNADO AL PROVEEDOR: "<<id<<endl;
            regProveedor.Cargar(id);
            system("cls");
            regProveedor.Mostrar();
            continuar = confirmacion();
        }while(!continuar);

        if(regArchivoProveedor.agregarProveedor(regProveedor)==true){
            cout<<"PROVEEDOR AGREGADO EXITOSAMENTE"<<endl;

            int agregarContactos;
            cout << endl;
            cout << "DESEA AGREGAR CONTACTOS PARA ESTE PROVEEDOR? (1-SI, 0-NO): ";
            cin >> agregarContactos;

            if(agregarContactos == 1){
                system("cls");
                agregarContacto(id, 'P');
            }

            aux = false;
        } else {
            cout<<"NO SE PUDO AGREGAR EL PROVEEDOR"<<endl;
            aux = false;
        }
    }
}

inline void buscarProveedor()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    int id;
    cout<<"BUSCAR UN PROVEEDOR POR ID."<<endl;
    listarProveedoresResumido();
    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA BUSCAR EN NUESTRA BdD:"<<endl;
    cin>>id;

    Proveedor regProveedor = Archivo.traerProveedor(id);

    if(regProveedor.getId() <= 0){
        manejoExcepciones(regProveedor.getId());
        return;
    }
    else{
        cout<<"SE ENCONTRO UN PROVEEDOR CON ESE ID:"<<endl<<endl;
        regProveedor.Mostrar();
    }

}

#endif // FUNCIONESPROVEEDOR_H_INCLUDED
