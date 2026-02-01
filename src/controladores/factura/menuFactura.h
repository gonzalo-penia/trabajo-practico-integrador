void mostrarMenuPrincipalEmision();
void mostrarSubMenuListarFacturas();
void mostrarMenu();
void menuEmision();

void mostrarMenuPrincipalEmision(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU EMISION"<<endl<<endl;

    cout<<"1 - EMITIR FACTURA."<<endl;
    cout<<"2 - LISTAR FACTURAS."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void menuEmision(){
    int sub_menu = 1;
    while(sub_menu != 0){
        system ("cls");
        mostrarMenuPrincipalEmision();
        cin >> sub_menu;
        system ("cls");
        switch(sub_menu){
            case 1: gestionCarrito(); break;
            case 2: listadoDeFacturas(); break;
            case 0: break;

            default:
                cout << "ERROR" << endl << endl;
                cout << "Algo salio mal, intente nuevamente" << endl << endl;
                system ("pause");
                break;
        }
    }
}

void mostrarMenu() {
    cout << "MENU DE GESTION DEL CARRITO" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "1 - Agregar Articulo al Carrito" << endl;
    cout << "2 - Modificar Cantidad de un Item" << endl;
    cout << "3 - Eliminar Item del Carrito" << endl;
    cout << "4 - Vaciar Carrito" << endl;
    cout << "5 - Confirmar y Continuar" << endl;
    cout << "0 - Cancelar y Salir" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Ingrese una opcion: ";
}

void mostrarSubMenuListarFacturas(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"LISTA DE FACTURAS"<<endl<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - TODAS"<<endl;
    cout<<"2 - POR RANGO DE FECHA"<<endl;
    cout<<"3 - POR CLIENTE"<<endl;
    cout<<"4 - POR ARTICULO"<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}