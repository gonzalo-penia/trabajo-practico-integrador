#ifndef BORRARCONTACTO_H_INCLUDED
#define BORRARCONTACTO_H_INCLUDED

void eliminarContacto() {
    system("cls");

    cout << "=======================================" << endl;
    cout << "         ELIMINAR CONTACTO" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    cout << "SELECCIONE EL TIPO DE ENTIDAD:" << endl;
    cout << "1 - CONTACTOS DE CLIENTE" << endl;
    cout << "2 - CONTACTOS DE PROVEEDOR" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int opcion;
    cin >> opcion;

    if (opcion == 0) {
        cout << "OPERACION CANCELADA" << endl;
        return;
    }

    system("cls");

    int idEntidad;
    ArchivoContacto archivoContacto;

    switch(opcion) {
        case 1: // CLIENTE
            {
                cout << "=======================================" << endl;
                cout << "   ELIMINAR CONTACTO DE CLIENTE" << endl;
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
                    return;
                }

                system("cls");
                cout << "=======================================" << endl;
                cout << "  CONTACTOS DEL CLIENTE ID " << idEntidad << endl;
                cout << "=======================================" << endl;
                cout << endl;

                listarContactosResumido(idEntidad, 'C');

                if (contarContactosPorEntidad(idEntidad, 'C') == 0) {
                    return;
                }
                break;
            }

        case 2: // PROVEEDOR
            {
                cout << "=======================================" << endl;
                cout << "  ELIMINAR CONTACTO DE PROVEEDOR" << endl;
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
                    return;
                }

                system("cls");
                cout << "=======================================" << endl;
                cout << "  CONTACTOS DEL PROVEEDOR ID " << idEntidad << endl;
                cout << "=======================================" << endl;
                cout << endl;

                listarContactosResumido(idEntidad, 'P');

                if (contarContactosPorEntidad(idEntidad, 'P') == 0) {
                    return;
                }
                break;
            }

        default:
            cout << "OPCION INVALIDA" << endl;
            return;
    }

    int idContacto;
    cout << "INGRESE EL ID DEL CONTACTO A ELIMINAR: ";
    cin >> idContacto;

    FILE *p = fopen("../../data/contactos.dat", "rb");
    if (p == NULL) {
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return;
    }

    Contacto regContacto;
    int pos = 0;
    bool encontrado = false;

    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdContacto() == idContacto &&
            regContacto.getIdEntidad() == idEntidad &&
            regContacto.getTipoEntidad() == (opcion == 1 ? 'C' : 'P') &&
            regContacto.getEstado()) {
            encontrado = true;
            break;
        }
        pos++;
    }
    fclose(p);

    if (!encontrado) {
        cout << "NO SE ENCONTRO EL CONTACTO O NO PERTENECE A ESTA ENTIDAD" << endl;
        return;
    }

    system("cls");
    cout << endl;
    cout << "ATENCION: VA A ELIMINAR EL SIGUIENTE CONTACTO:" << endl;
    regContacto.Mostrar();
    cout << endl;
    cout << "=======================================" << endl;
    cout << "ESTA SEGURO QUE DESEA ELIMINAR ESTE CONTACTO?" << endl;
    cout << "1 - SI, ELIMINAR" << endl;
    cout << "0 - NO, CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";

    int confirmacion;
    cin >> confirmacion;

    if (confirmacion == 1) {
        regContacto.setEstado(false);
        if (archivoContacto.modificarArchivo(pos, regContacto)) {
            cout << endl;
            cout << "=======================================" << endl;
            cout << "  CONTACTO ELIMINADO EXITOSAMENTE" << endl;
            cout << "=======================================" << endl;
        } else {
            cout << endl;
            cout << "ERROR AL ELIMINAR EL CONTACTO" << endl;
        }
    } else {
        cout << endl;
        cout << "OPERACION CANCELADA - EL CONTACTO NO FUE ELIMINADO" << endl;
    }

    cout << endl;
}

void eliminarContactosDeEntidad(int idEntidad, char tipoEntidad) {
    ArchivoContacto archivoContacto;
    Contacto regContacto;
    FILE *p = fopen("../../data/contactos.dat", "rb+");

    if (p == NULL) {
        cout << "ERROR AL ACCEDER AL ARCHIVO DE CONTACTOS" << endl;
        return;
    }

    int pos = 0;
    while (fread(&regContacto, sizeof(regContacto), 1, p) == 1) {
        if (regContacto.getIdEntidad() == idEntidad &&
            regContacto.getTipoEntidad() == tipoEntidad &&
            regContacto.getEstado()) {
            regContacto.setEstado(false);
            fseek(p, sizeof(Contacto) * pos, SEEK_SET);
            fwrite(&regContacto, sizeof(regContacto), 1, p);
            fseek(p, 0, SEEK_CUR);
        }
        pos++;
    }
    fclose(p);
}

#endif // BORRARCONTACTO_H_INCLUDED