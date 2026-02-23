void mostrarMenuPrincipalProveedores();
void mostrarSubMenuBajaProveedores();
void mostrarSubMenuListarProveedores();
void mostrarSubMenuModificarProveedores();
void menuProveedores();

void menuProveedores(){
    int sub_menu = 1;
    while(sub_menu != 0){
        system ("cls");
        mostrarMenuPrincipalProveedores();
        cin >> sub_menu;
        system ("cls");
        switch(sub_menu){
            case 1: cargarProveedor(); break;
            case 2: buscarProveedor(); break;
            case 3: {

                system ("cls");
                int modificar;
                mostrarSubMenuModificarProveedores();
                cin >> modificar;
                switch (modificar){
                    case 1: modificarNombreProveedor(); break;
                    case 2: modificarDireccionProveedor(); break;
                    default: break;
                }
                break;
            }
            case 4: {
                system ("cls");
                int listar;
                mostrarSubMenuListarProveedores();
                cin >> listar;
                switch (listar){
                    case 1: listarProveedoresPorIdMayorAMenor(); break;
                    case 2: listarProveedoresPorIdMenorAMayor(); break;
                    case 3: listarProveedoresPorMayorCantidadDeCompras(); break;
                    case 4: listarProveedoresPorMenorCantidadDeCompras(); break;
                    case 5: listarProveedoresPorMayorCantidadDeUnidades(); break;
                    case 6: listarProveedoresPorMenorCantidadDeUnidades(); break;
                    default: break;
                }
                break;
            }
            case 5: {
                int borrar;
                mostrarSubMenuBajaProveedores();
                cin >> borrar;
                switch (borrar){
                    case 1: borrarProveedorLogico(); break;
                    case 2: borrarProveedorFisico(); break;
                    default: break;
                }
                break;
            }
            case 0: break;
            default:
                cout << "ERROR" << endl << endl;
                cout << "Algo salio mal, intente nuevamente" << endl << endl;
                system ("pause");
                break;
        }
    }
}

void mostrarMenuPrincipalProveedores(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU PROVEEDORES"<<endl<<endl;

    cout<<"1 - AGREGAR PROVEEDOR."<<endl;
    cout<<"2 - BUSCAR PROVEEDOR."<<endl;
    cout<<"3 - MODIFICAR PROVEEDOR."<<endl;
    cout<<"4 - LISTAR PROVEEDORES."<<endl;
    cout<<"5 - ELIMINAR PROVEEDOR."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}


void mostrarSubMenuBajaProveedores(){
    cout<<"BAJA PROVEEDOR."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarProveedores(){
    cout<<"LISTA PROVEEDORES."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - LISTAR POR ID DE MAYOR A MENOR."<<endl;
    cout<<"2 - LISTAR POR ID DE MENOR A MAYOR."<<endl;
    cout<<"3 - LISTAR POR CANTIDAD DE COMPRAS DE MAYOR A MENOR."<<endl;
    cout<<"4 - LISTAR POR CANTIDAD DE COMPRAS DE MENOR A MAYOR."<<endl;
    cout<<"5 - LISTAR POR CANTIDAD DE UNIDADES DE MAYOR A MENOR."<<endl;
    cout<<"6 - LISTAR POR CANTIDAD DE UNIDADES DE MENOR A MAYOR."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuModificarProveedores(){
    cout<<"MODIFICAR PROVEEDOR."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"1 - MODIFICAR NOMBRE DEL PROVEEDOR."<<endl;
    cout<<"2 - MODIFICAR DIRECCION DEL PROVEEDOR."<<endl;

    cout<<"Si usted desea modificar un contacto debe gestionarlo a traves del menu de contactos."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}