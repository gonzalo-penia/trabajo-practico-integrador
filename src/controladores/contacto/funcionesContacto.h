#ifndef FUNCIONESCONTACTO_H_INCLUDED
#define FUNCIONESCONTACTO_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ARCHIVOCONTACTO_H_INCLUDED
    #include "../../clsArchivo/ArchivoContacto.h"
    #define ARCHIVOCONTACTO_H_INCLUDED
#endif

#include "listadoContacto.h"
#include "../cliente/listadoCliente.h"
#include "../proveedor/listadoProveedor.h"



void agregarContacto() {
    ArchivoContacto archivoContacto;
    Contacto nuevoContacto;

    cout << "=======================================" << endl;
    cout << "       AGREGAR NUEVO CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;
    cout << endl;
    cout << "SELECCIONE EL TIPO DE ENTIDAD A LA QUE DESEA ASOCIAR EL CONTACTO:" << endl;
    cout << "1 - CLIENTE" << endl;
    cout << "2 - PROVEEDOR" << endl;
    cout << "0 - CANCELAR" << endl;

    int opcion;
    cout << "OPCION: ";
    cin >> opcion;

    if (opcion == 0) {
        cout << "OPERACION CANCELADA" << endl;
        return;
    }

    if (opcion == 1) {
        listarClientesResumido();
    } else if (opcion == 2) {
        listarProveedoresResumido();
    } else {
        cout << "OPCION INVALIDA" << endl;
        return;
    }

    cout << endl;
    int idEntidad;
    cout << "DIGITE EL ID DE LA ENTIDAD A LA CUAL QUIERE ASOCIAR EL CONTACTO: ";
    cin >> idEntidad;

    if (opcion == 1) {
        ArchivoCliente archivoCliente;
        if (!archivoCliente.validarIdCliente(idEntidad)) {
            cout << endl;
            cout << "ERROR: EL ID " << idEntidad << " NO PERTENECE A NINGUN CLIENTE" << endl;
            cout << "No puede vincular contactos con proveedores desde este menu." << endl;
            return;
        }
    } else if (opcion == 2) {
        ArchivoProveedor archivoProveedor;
        if (!archivoProveedor.validarId(idEntidad)) {
            cout << endl;
            cout << "ERROR: EL ID " << idEntidad << " NO PERTENECE A NINGUN PROVEEDOR" << endl;
            cout << "No puede vincular contactos con clientes desde este menu." << endl;
            return;
        }
    }

    nuevoContacto.setIdEntidad(idEntidad);

    if (opcion == 1) {
        nuevoContacto.setTipoEntidad('C');
    } else if (opcion == 2) {
        nuevoContacto.setTipoEntidad('P');
    }

    int idContacto = archivoContacto.obtenerIdDisponible();
    nuevoContacto.setIdContacto(idContacto);

    nuevoContacto.Cargar();

    if (archivoContacto.escribirArchivo(nuevoContacto)) {
        cout << endl;
        cout << "CONTACTO AGREGADO EXITOSAMENTE CON ID DE CONTACTO: " << idContacto << endl;
        cout << "CONTACTO ASOCIADO EXITOSAMENTE A LA ENTIDAD:  " << idEntidad << endl;

    } else {
        cout << "ERROR AL GUARDAR EL CONTACTO" << endl;
    }
}

void agregarContacto(int idEntidad, char tipoEntidad) {
    ArchivoContacto archivoContacto;
    Contacto Contacto;

    Contacto.setIdEntidad(idEntidad);
    Contacto.setTipoEntidad(tipoEntidad);

    cout << endl;
    cout << "=======================================" << endl;
    cout << "       AGREGAR UN CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    Contacto.setIdContacto( archivoContacto.obtenerIdDisponible() );

    Contacto.Cargar();

    if (archivoContacto.escribirArchivo(Contacto)) {
        cout << endl;
        cout << "EL CONTACTO " << Contacto.getIdContacto() << " SE AGREGÓ EXITOSAMENTE" << endl;

    } else {
        cout << "ERROR AL GUARDAR EL CONTACTO" << endl;
    }
}

#endif // FUNCIONESCONTACTO_H_INCLUDED
