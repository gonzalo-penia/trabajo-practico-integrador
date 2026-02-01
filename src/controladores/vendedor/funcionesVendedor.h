#include "listadoVendedor.h"

void cargarVendedor();
void buscarVendedor();
Vendedor elegirVendedor();

void cargarVendedor(){
    Vendedor regVendedor;
    ArchivoVendedor regArchivoVendedor("../../data/vendedores.dat");
    int id;
    cout<<"CARGA NUEVO VENDEDOR."<<endl<<endl;
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SERAN SOLICITADOS."<<endl<<endl;
    bool aux=true;
    while (aux==true){
        bool continuar;
        do{
            id = regArchivoVendedor.obtenerIdDisponible();
            cout<<"ID ASIGNADO AL VENDEDOR: "<<id<<endl;
            regVendedor.Cargar(id);
            system("cls");
            regVendedor.Mostrar();
            continuar = confirmacion();
        }while(!continuar);

        if(regArchivoVendedor.escribirArchivo(regVendedor)==true){
            cout<<"VENDEDOR AGREGADO EXITOSAMENTE"<<endl;
            aux = false;
        }else{
            cout<<"NO SE PUDO AGREGAR EL VENDEDOR"<<endl;
            aux = false;
        }
    }
}

void buscarVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id;
    cout<<"BUSCAR UN VENDEDOR POR ID."<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA BUSCAR EN NUESTRA BdD:"<<endl;
    cin>>id;

    Vendedor vendedor = regVendedor.traerVendedor(id);

    if(vendedor.getId() == -1) {
        cout << "NO HAY NADIE REGISTRADO CON ESE ID" << endl;
    } else if(vendedor.getId() == -2) {
        cout << "ERROR AL ACCEDER AL ARCHIVO" << endl;
    } else {
        vendedor.Mostrar();
    }
}

Vendedor elegirVendedor(){

    Vendedor vendedor;
    ArchivoVendedor archivoVendedor;
    int idVendedor;

    cout << "PARA CONTINUAR DEBE SELECCIONAR UN VENDEDOR." << endl << endl;

    do {
        listarVendedores();
        cout << endl << "INGRESE EL ID DEL VENDEDOR A CARGO DE LA VENTA: ";
        cin >> idVendedor;

        vendedor = archivoVendedor.traerVendedor(idVendedor);

        if (vendedor.getId() == -1) {
            cout << endl << "ERROR: NO SE ENCONTRO UN VENDEDOR CON EL ID " << idVendedor << endl;
            cout << "POR FAVOR, INTENTE NUEVAMENTE." << endl << endl;
            system("pause");
            system("cls");
        }
    } while (vendedor.getId() == -1);
    system("cls");
    cout << endl << "VENDEDOR SELECCIONADO: " << vendedor.getNombre() << endl;

    return vendedor;
}

//FIN