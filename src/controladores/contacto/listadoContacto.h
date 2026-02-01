#ifndef LISTADOCONTACTO_H_INCLUDED
#define LISTADOCONTACTO_H_INCLUDED

#include "../../clases/Contacto.h"
#include "../../clsArchivo/ArchivoContacto.h"

#include <iostream>
#include <iomanip>
using namespace std;

void listarClientesResumido();
void listarProveedoresResumido();

int contarContactosPorEntidad(int idEntidad, char tipoEntidad);
void listarContactosResumido(int idEntidad, char tipoEntidad);
void listarContactosPorEntidad();
void listarContactosPorEntidadAux(int idEntidad, char tipoEntidad);
void listarContactos();
void buscarContactoPorID();

int contarContactosPorEntidad(int idEntidad, char tipoEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        return 0;
    }

    int contador = 0;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad &&
            regContacto.getTipoEntidad() == tipoEntidad &&
            regContacto.getEstado()) {
            contador++;
        }
    }
    fclose(p);
    return contador;
}

void listarContactosResumido(int idEntidad, char tipoEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    cout << "CONTACTOS DISPONIBLES DE:" << endl;
    cout << left << setw(10) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    bool hayContactos = false;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad &&
            regContacto.getTipoEntidad() == tipoEntidad &&
            regContacto.getEstado()) {
            cout << left << setw(10) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono() << endl;
            hayContactos = true;
        }
    }

    if (!hayContactos) {
        cout << "NO HAY CONTACTOS REGISTRADOS PARA ESTA ENTIDAD" << endl;
    }

    fclose(p);
    cout << endl;
}

void listarContactosPorEntidad() {
    system("cls");

    cout << "=======================================" << endl;
    cout << "    VER CONTACTOS DE UNA ENTIDAD" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    cout << "SELECCIONE EL TIPO DE ENTIDAD:" << endl;
    cout << "1 - CLIENTE" << endl;
    cout << "2 - PROVEEDOR" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int opcion;
    cin >> opcion;

    if (opcion == 0) {
        cout << "OPERACION CANCELADA" << endl;
        system("pause");
        return;
    }

    system("cls");

    int idEntidad;

    switch(opcion) {
        case 1: // CLIENTE
            {
                cout << "=======================================" << endl;
                cout << "     CONTACTOS DE CLIENTE" << endl;
                cout << "=======================================" << endl;
                cout << endl;

                listarClientesResumido();

                cout << "INGRESE EL ID DEL CLIENTE: ";
                cin >> idEntidad;

                ArchivoCliente archivoCliente;
                if (!archivoCliente.validarIdCliente(idEntidad)) {
                    cout << endl;
                    cout << "ERROR: EL ID " << idEntidad << " NO PERTENECE A NINGUN CLIENTE" << endl;
                    cout << "No puede acceder a contactos de proveedores desde este menu." << endl;
                    system("pause");
                    return;
                }

                cout << endl;
                cout << "CONTACTOS DEL CLIENTE ID " << idEntidad << ":" << endl;
                cout << "---------------------------------------" << endl;
                listarContactosPorEntidadAux(idEntidad, 'C');
                break;
            }
            
            case 2: // PROVEEDOR
            {
                cout << "=======================================" << endl;
                cout << "     CONTACTOS DE PROVEEDOR" << endl;
                cout << "=======================================" << endl;
                cout << endl;
                
                listarProveedoresResumido();
                
                cout << "INGRESE EL ID DEL PROVEEDOR: ";
                cin >> idEntidad;
                
                ArchivoProveedor archivoProveedor;
                if (!archivoProveedor.validarId(idEntidad)) {
                    cout << endl;
                    cout << "ERROR: EL ID " << idEntidad << " NO PERTENECE A NINGUN PROVEEDOR" << endl;
                    cout << "No puede acceder a contactos de clientes desde este menu." << endl;
                    system("pause");
                    return;
                }
                
                cout << endl;
                cout << "CONTACTOS DEL PROVEEDOR ID " << idEntidad << ":" << endl;
                cout << "---------------------------------------" << endl;
                listarContactosPorEntidadAux(idEntidad, 'P');
                break;
            }

        default:
            cout << "OPCION INVALIDA" << endl;
            system("pause");
            break;
    }

    cout << endl;
}

void listarContactosPorEntidadAux(int idEntidad, char tipoEntidad) {

    ArchivoContacto archivoContacto;
    Contacto regContacto;

    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    cout << endl;
    cout << left << setw(8) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << setw(35) << "EMAIL" << setw(15) <<endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;

    bool hayContactos = false;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {

        if (regContacto.getIdEntidad() == idEntidad &&
            regContacto.getTipoEntidad() == tipoEntidad &&
            regContacto.getEstado()) {
            cout << left << setw(8) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono()
                 << setw(35) << regContacto.getEmail()
                 << endl;
            hayContactos = true;
        }
    }

    if (!hayContactos) {
        cout << "NO HAY CONTACTOS REGISTRADOS PARA ESTA ENTIDAD" << endl;
    }
    system("pause");

    fclose(p);
    cout << endl;
}

void listarContactos(){
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb");

    if (p == NULL) {
        cout << "NO SE PUDO ABRIR EL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getEstado()) {
            regContacto.Mostrar();
        }
    }

}

void buscarContactoPorID() {
    ArchivoContacto archivoContacto;

    cout << endl;
    cout << "=======================================" << endl;
    cout << "      BUSCAR CONTACTO POR ID" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    int idContactoBuscar;
    cout << "INGRESE EL ID DEL CONTACTO A BUSCAR: ";
    cin >> idContactoBuscar;

    FILE *p = fopen("../../data/contactos.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }

    cout << endl;
    cout << left << setw(8) << "ID" << setw(30) << "NOMBRE" << setw(20) << "TELEFONO" << setw(35) << "EMAIL" << setw(15)  << "ENTIDAD" << endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ') << endl;

    Contacto regContacto;
    bool encontrado = false;

    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdContacto() == idContactoBuscar &&
            regContacto.getEstado()) {
            cout << left << setw(8) << regContacto.getIdContacto()
                 << setw(30) << regContacto.getNombreContacto()
                 << setw(20) << regContacto.getNroTelefono()
                 << setw(35) << regContacto.getEmail()
                 << setw(15) << regContacto.getIdEntidad() << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "NO SE ENCONTRO EL CONTACTO CON ID: " << idContactoBuscar << endl;
    }

    fclose(p);
    cout << endl;
    system("pause");
}

#endif // LISTADOCONTACTO_H_INCLUDED
