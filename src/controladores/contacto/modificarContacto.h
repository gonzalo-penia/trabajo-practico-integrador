void mostrarMenuModificarContactos();
void mostrarSubMenuModificarContactos();

void modificarContacto() {
    system("cls");

    mostrarMenuModificarContactos();

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
                cout << "  MODIFICAR CONTACTO DE CLIENTE" << endl;
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

                Cliente regCliente;
                regCliente = archivoCliente.traerCliente( idEntidad) ;

                if(regCliente.getId() <= 0) {
                    cout << endl << "ERROR: NO SE PUDO OBTENER LOS DATOS DEL CLIENTE" << endl;
                    return;
                }

                system("cls");
                cout << "=======================================" << endl;
                cout << "  LOS CONTACTOS DEL CLIENTE " << regCliente.getNombre() <<" SON:"<< endl;
                cout << "=======================================" << endl;
                cout << endl;

                listarContactosResumido(idEntidad, 'C');

                if (contarContactosPorEntidad(idEntidad, 'C') == 0) {
                    cout<<"NO HAY CONTACTOS ASOCIADOS A ESA ENTIDAD";
                    return;
                }
                break;
            }

        case 2: // PROVEEDOR
            {
                cout << "=======================================" << endl;
                cout << "  MODIFICAR CONTACTO DE PROVEEDOR" << endl;
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

                Proveedor regProveedor;
                regProveedor = archivoProveedor.traerProveedor(idEntidad);

                //system("cls");
                cout << "=======================================" << endl;
                cout << "  CONTACTOS DEL PROVEEDOR ID " << idEntidad <<"SON"<<endl;
                cout << "=======================================" << endl;
                cout << endl;

                listarContactosResumido(idEntidad, 'P');

                if (contarContactosPorEntidad(idEntidad, 'P') == 0) {
                    cout<<"NO HAY CONTACTOS ASOCIADOS A ESA ENTIDAD";
                    return;
                }
                break;
            }

        default:
            cout << "OPCION INVALIDA" << endl;
            return;
    }

    int idContacto;
    cout << "INGRESE EL ID DEL CONTACTO A MODIFICAR: ";
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
    cout << "DATOS ACTUALES DEL CONTACTO:" << endl;
    regContacto.Mostrar();
    cout << endl;

    mostrarSubMenuModificarContactos();

    int opcionMod;
    cin >> opcionMod;

    if (opcionMod == 0) {
        cout << "OPERACION CANCELADA" << endl;
        return;
    }

    cout << endl;

    switch(opcionMod) {
            case 1:
                cout << "INGRESE EL NUEVO NOMBRE: ";
                char nuevoNombre[30];
                cargarCadena(nuevoNombre, 30);
                regContacto.setNombreContacto(nuevoNombre);
                break;

            case 2:
                cout << "INGRESE EL NUEVO TELEFONO: ";
                char nuevoTelefono[20];
                cargarCadena(nuevoTelefono, 20);
                regContacto.setNroTelefono(nuevoTelefono);
                break;

            case 3:
                cout << "INGRESE EL NUEVO MAIL: ";
                char email[30];
                cargarCadena(email, 30);
                regContacto.setEmail(email);
                break;

            default:
                cout << "OPCION INVALIDA" << endl;
                return;
    }

    if ( archivoContacto.modificarArchivo(pos, regContacto) ) {
        cout << endl;
        cout << "CONTACTO MODIFICADO EXITOSAMENTE" << endl;
        cout << endl;
    } else {
        cout << "ERROR AL MODIFICAR EL CONTACTO" << endl;
    }

    cout << endl;
}
