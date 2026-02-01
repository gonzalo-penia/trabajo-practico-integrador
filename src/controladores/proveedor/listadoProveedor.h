#ifndef LISTADOPROVEEDOR_H_INCLUDED
#define LISTADOPROVEEDOR_H_INCLUDED

#include "../../clases/Proveedor.h"
#include "../../clsArchivo/ArchivoProveedor.h"

#include <iostream>
#include <iomanip>
using namespace std;

void listaDeProveedores();
void listarProveedoresResumido();
void listarProveedoresPorIdMayorAMenor();
void listarProveedoresPorIdMenorAMayor();
void listarProveedoresPorMayorCantidadDeCompras();
void listarProveedoresPorMenorCantidadDeCompras();
void listarProveedoresPorMayorCantidadDeUnidades();
void listarProveedoresPorMenorCantidadDeUnidades();

inline void listaDeProveedores()
{
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    Archivo.leerArchivo();
}

inline void listarProveedoresResumido() {
    ArchivoProveedor regProveedor("../../data/proveedores.dat");
    Proveedor proveedor;
    FILE *p = fopen("../../data/proveedores.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE PROVEEDORES" << endl;
        return;
    }

    cout << "PROVEEDORES DISPONIBLES:" << endl;
    cout << left << setw(10) << "ID" << setw(50) << "NOMBRE" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    bool hayProveedores = false;
    while (fread(&proveedor, sizeof(proveedor), 1, p) == 1) {
        if (proveedor.getEstado()) {
            cout << left << setw(10) << proveedor.getId()
                 << setw(50) << proveedor.getNombre() << endl;
            hayProveedores = true;
        }
    }

    if (!hayProveedores) {
        cout << "NO HAY PROVEEDORES REGISTRADOS" << endl;
    }

    fclose(p);
    cout << endl;
}

inline void listarProveedoresPorIdMayorAMenor(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMaximo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    cout<<"LISTADO DE PROVEEDORES POR ID DE MAYOR A MENOR."<<endl<<endl;
    cout << left << setw(5) << "ID" << setw(40) << "NOMBRE" << setw(20) << "COMPRAS REALIZADAS:" << setw(20) << "UNIDADES COMPRADAS:" << endl;

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getId() > vProveedor[posMaximo].getId() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMaximo];
                vProveedor[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar(true);
            }
    }

    delete [] vProveedor;
    system("pause");
}

inline void listarProveedoresPorIdMenorAMayor(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMinimo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    cout<<"LISTADO DE PROVEEDORES POR ID DE MENOR A MAYOR."<<endl<<endl;
    cout << left << setw(5) << "ID" << setw(40) << "NOMBRE" << setw(20) << "COMPRAS REALIZADAS:" << setw(20) << "UNIDADES COMPRADAS:" << endl;

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getId() < vProveedor[posMinimo].getId() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMinimo];
                vProveedor[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar(true);
            }
    }

    delete [] vProveedor;
    system("pause");
}

inline void listarProveedoresPorMayorCantidadDeCompras(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMaximo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    cout<<"LISTADO DE PROVEEDORES POR MAYOR CANTIDAD DE COMPRAS."<<endl<<endl;
     cout << left << setw(5) << "ID" << setw(40) << "NOMBRE" << setw(20) << "COMPRAS REALIZADAS:" << setw(20) << "UNIDADES COMPRADAS:" << endl;

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getCantidadCompras() > vProveedor[posMaximo].getCantidadCompras() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMaximo];
                vProveedor[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar(true);
            }
    }

    delete [] vProveedor;
    system("pause");
}

inline void listarProveedoresPorMenorCantidadDeCompras(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMinimo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    cout<<"LISTADO DE PROVEEDORES POR MENOR CANTIDAD DE COMPRAS."<<endl<<endl;
    cout << left << setw(5) << "ID" << setw(40) << "NOMBRE" << setw(20) << "COMPRAS REALIZADAS:" << setw(20) << "UNIDADES COMPRADAS:" << endl;

    regArchivo.vectorizarArchivo(vProveedor, cantidad); //CARGO EN EL VECTOR DINAMICO EL CONTENIDO DEL ARCHIVO

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getCantidadCompras() < vProveedor[posMinimo].getCantidadCompras() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMinimo];
                vProveedor[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar(true);
            }
    }

    delete [] vProveedor;
    system("pause");
}

inline void listarProveedoresPorMayorCantidadDeUnidades(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMaximo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    cout<<"LISTADO DE PROVEEDORES POR MAYOR CANTIDAD DE UNIDADES."<<endl<<endl;
    cout << left << setw(5) << "ID" << setw(40) << "NOMBRE" << setw(20) << "COMPRAS REALIZADAS:" << setw(20) << "UNIDADES COMPRADAS:" << endl;

    regArchivo.vectorizarArchivo(vProveedor, cantidad);

    for(i=0; i<cantidad-1; i++)
        {
            posMaximo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getCantidadUnidades() > vProveedor[posMaximo].getCantidadUnidades() )
                    {
                    posMaximo=j;
                    }
                }

            if (i != posMaximo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMaximo];
                vProveedor[posMaximo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar(true);
            }
    }

    delete [] vProveedor;
    system("pause");
}

inline void listarProveedoresPorMenorCantidadDeUnidades(){
    ArchivoProveedor regArchivo("../../data/proveedores.dat");

    int i, j,cantidad,posMinimo;

    Proveedor *vProveedor;

    cantidad=regArchivo.contarArchivo();
    vProveedor = new Proveedor[cantidad];

    if(vProveedor == nullptr)
    {
        cout << "NO SE PUDO PEDIR MEMORIA... " << endl;
        return;
    }

    cout<<"LISTADO DE PROVEEDORES POR MENOR CANTIDAD DE UNIDADES."<<endl<<endl;
    cout << left << setw(5) << "ID" << setw(40) << "NOMBRE" << setw(20) << "COMPRAS REALIZADAS:" << setw(20) << "UNIDADES COMPRADAS:" << endl;

    regArchivo.vectorizarArchivo(vProveedor, cantidad);

    for(i=0; i<cantidad-1; i++)
        {
            posMinimo=i;
            for(j=i+1;j<cantidad;j++)
                {
                if( vProveedor[j].getCantidadUnidades() < vProveedor[posMinimo].getCantidadUnidades() )
                    {
                    posMinimo=j;
                    }
                }

            if (i != posMinimo )
                {
                Proveedor aux = vProveedor[i];
                vProveedor[i] = vProveedor[posMinimo];
                vProveedor[posMinimo] = aux;
                }
        }

    for(int i=0; i<cantidad; i++)
    {
        if(vProveedor[i].getEstado())
            {
            vProveedor[i].Mostrar(true);
            }
    }

    delete [] vProveedor;
    system("pause");
}

#endif // LISTADOPROVEEDOR_H_INCLUDED
