#ifndef LISTADOFACTURA_H_INCLUDED
#define LISTADOFACTURA_H_INCLUDED

#include "../../clases/Factura.h"
#include "../../clases/Fecha.h"
#include "../../clsArchivo/ArchivoFactura.h"
#include "../../globales/funcionesGlobales.h"

#include <iostream>
#include <iomanip>
#include <string>

void mostrarSubMenuListarFacturas();
using namespace std;

void listaArticulosSimplificada();

void listarFacturas();
void listarFacturasRangoFecha(Fecha fechaInicial, Fecha fechaFinal);
void listarFacturasCliente(int idCliente);
void listarFacturasArticulo(int idArticulo);
void listadoDeFacturas();

void listarFacturas(){
    ArchivoFactura archivo("../../data/facturas.dat");
    Factura regFactura;

    int cantidad = archivo.contarRegistros();

    if(cantidad <= 0){
        cout << "No hay facturas para mostrar." << endl;
        return;
    }

    for(int i = 0; i < cantidad; i++){
        regFactura = archivo.leerRegistro(i);
        regFactura.Mostrar();
        cout << string(110, '/') << endl;
        cout << string(110, '/') << endl;
    }

    system("pause");
}

void listarFacturasRangoFecha(Fecha fechaInicial, Fecha fechaFinal){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    int cantidad = regArchivoFactura.contarRegistros();

    // ENCABEZADO
    cout << left << setw(14) << "FECHA";
    cout << right << setw(6) << "NRO" << setw(4) << " " << setw(10) << "ID CLIENTE" << setw(2) << " ";
    cout << left << setw(55) << "NOMBRE CLIENTE";
    cout << right << setw(11) << "TOTAL" << endl;
    cout << string(102, '-') << endl;

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
        if(regFactura.getFecha()>=fechaInicial && regFactura.getFecha()<=fechaFinal){
            regFactura.MostrarFacturaResumen();
        }
    }
}

void listarFacturasCliente(int idCliente){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    int cantidad = regArchivoFactura.contarRegistros();

    // ENCABEZADO
    cout << left << setw(14) << "FECHA";
    cout << right << setw(6) << "NRO" << setw(4) << " " << setw(10) << "ID CLIENTE" << setw(2) << " ";
    cout << left << setw(55) << "NOMBRE CLIENTE";
    cout << right << setw(11) << "TOTAL" << endl;
    cout << string(102, '-') << endl;

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
        if (regFactura.getIdCliente() == idCliente){
            regFactura.MostrarFacturaResumen();
        }

    }
}

void listarFacturasArticulo(int idArticulo){
    ArchivoFactura regArchivoFactura;
    Factura regFactura;

    int cantidad = regArchivoFactura.contarRegistros();

    // ENCABEZADO
    cout << left << setw(14) << "FECHA";
    cout << right << setw(6) << "NRO" << setw(4) << " " << setw(10) << "ID CLIENTE" << setw(2) << " ";
    cout << left << setw(55) << "NOMBRE CLIENTE" << setw(9) << "VENDEDOR";
    cout << right << setw(9) << "CANT" << setw(11) << "IMPORTE" << endl;
    cout << string(120, '-') << endl;

    for (int i=0; i<cantidad; i++){
        regFactura = regArchivoFactura.leerRegistro(i);
            for (int j=0; j<regFactura.getDetalleVenta().getTamActual(); j++){
                if (regFactura.getDetalleVenta().getItem(j).getIdArticulo() == idArticulo){
                    regFactura.MostrarFacturaArticulo(j);
                }
            }
    }
}

void listadoDeFacturas(){

    cout<<"2-LISTADO DE FACTURAS"<<endl;

    int opcion=1;
    while (opcion!=0){
            system("cls");
            mostrarSubMenuListarFacturas();
            cin >> opcion;
            switch (opcion){

                case 1: {   ///LISTAR TODAS LAS FACTURAS
                    systemClsListadoFactura();
                    listarFacturas();
                    break;
                }

                case 2: {   ///LISTADO POR RANGO DE FECHA
                    systemClsListadoFactura();
                    Fecha fechaInicial, fechaFinal;
                    fechaFinal = rangoFecha(fechaInicial);
                    systemClsListadoFactura();
                    cout << endl << "FECHA INICIAL: " << fechaInicial.toString() << " - FECHA FINAL: " << fechaFinal.toString() << endl;
                    listarFacturasRangoFecha(fechaInicial, fechaFinal);
                    system ("pause");
                    break;
                }

                case 3: {   ///LISTADO POR CLIENTE
                    system("cls");
                    listarClientesResumido();
                    cout << endl << "INGRESE EL ID DEL CLIENTE: ";
                    int idCliente;
                    cin >> idCliente;

                    ArchivoCliente regArchivoCliente;

                    Cliente clienteValidado = regArchivoCliente.traerCliente(idCliente);
                    while (clienteValidado.getId() <= 0){
                        cout << endl << "NO SE HA ENCONTRADO UN CLIENTE CON ESE ID." << endl;
                        cout << endl << "INGRESE EL ID DEL CLIENTE: ";
                        cin >> idCliente;
                        clienteValidado = regArchivoCliente.traerCliente(idCliente);
                    }

                    cout<<endl<<"SE ENCONTRO UN CLIENTE CON ESE ID: "<<endl<<endl;
                    cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
                    cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
                    cout << left << setw(5) << clienteValidado.getId() << setw(55) << clienteValidado.getNombre() << setw(15) << clienteValidado.getCuit() << endl << endl;

                    listarFacturasCliente(idCliente);
                    system ("pause");
                    break;
                }

                case 4: {   ///LISTADO POR ARTICULO
                    systemClsListadoFactura();
                    listaArticulosSimplificada();
                    cout << endl << "INGRESE EL ID DEL ARTICULO: ";
                    int idArticulo;
                    cin >> idArticulo;

                    ArchivoArticulo regArchivoArticulo;
                    Articulo articuloValidado = regArchivoArticulo.traerArticulo(idArticulo);

                    while (articuloValidado.getId() == -1 || articuloValidado.getId() == -2){
                        cout << endl << "NO SE HA ENCONTRADO UN ARTICULO CON ESE ID." << endl;
                        cout << endl << "INGRESE EL ID DEL ARTICULO: ";
                        cin >> idArticulo;
                        articuloValidado = regArchivoArticulo.traerArticulo(idArticulo);
                    }

                    listarFacturasArticulo(idArticulo);
                    system ("pause");
                    break;
                }

                case 0: break;

                default:
                    cout << endl << "ERROR" << endl << endl;
                    cout << "Algo salio mal, intente nuevamente" << endl << endl;
                    system ("pause");
                    break;
            }
    }
}

#endif // LISTADOFACTURA_H_INCLUDED
