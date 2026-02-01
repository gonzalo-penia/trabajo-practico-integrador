void mostrarMenuModificarContactos();
void mostrarSubMenuModificarContactos();
void mostrarMenuContactos();
void menuContactos();

void menuContactos(){
    int sub_menu = 1;
    while(sub_menu != 0){
        system ("cls");
        mostrarMenuContactos();
        cin >> sub_menu;
        system ("cls");
        switch(sub_menu){
            case 1: agregarContacto(); break;
            case 2: listarContactosPorEntidad(); break;
            case 3: modificarContacto(); break;
            case 4: eliminarContacto(); break;
            case 0: break;

            default:
                cout << "ERROR" << endl << endl;
                cout << "Algo salio mal, intente nuevamente" << endl << endl;
                system ("pause");
                break;
        }
    }
}

void mostrarMenuModificarContactos(){
    dibujarCuadro(1,1,77,3);
    gotoxy(28,2);
    cout<<"MODIFICAR CONTACTO"<<endl<<endl;

    cout << "SELECCIONE EL TIPO DE ENTIDAD:" << endl;
    cout << "1 - CONTACTOS DE CLIENTE" << endl;
    cout << "2 - CONTACTOS DE PROVEEDOR" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";
}

void mostrarSubMenuModificarContactos(){
    cout << "QUE DESEA MODIFICAR?" << endl;
    cout << "1 - NOMBRE" << endl;
    cout << "2 - TELEFONO" << endl;
    cout << "3 - MAIL" << endl;
    cout << "0 - CANCELAR" << endl;
    cout << endl;
    cout << "OPCION: ";
}
void mostrarMenuContactos(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU CONTACTOS"<<endl<<endl;
    cout<<"1 - AGREGAR CONTACTO."<<endl;
    cout<<"2 - BUSCAR CONTACTO."<<endl;
    cout<<"3 - MODIFICAR CONTACTO."<<endl;
    cout<<"4 - ELIMINAR CONTACTO."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}