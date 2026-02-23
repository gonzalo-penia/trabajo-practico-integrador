void mostrarSubMenuBajaClientes();
void mostrarSubMenuListarClientes();
void mostrarSubMenuModificarCliente();
void mostrarMenuPrincipalClientes();
void menuClientes();

void menuClientes(){
    int sub_menu = 1;
    while(sub_menu != 0){
        system ("cls");
        mostrarMenuPrincipalClientes();
        cin >> sub_menu;
        system ("cls");
        switch(sub_menu){
            case 1: cargarCliente(); break;
            case 2: buscarCliente(); break;            
            
            case 3: {
                int modificar;
                system ("cls");
                mostrarSubMenuModificarCliente();
                cin >> modificar;
                switch (modificar){
                    case 1: modificarTipo(); break;
                    case 2: modificarDireccion(); break;
                    case 3: modificarCantidadVentas(); break;
                    case 4: modificarNombreCliente(); break;
                    default: break;
                }
                break;
            }
            case 4: {
                int listar;
                system ("cls");
                mostrarSubMenuListarClientes();
                cin >> listar;
                switch (listar){
                    case 1: listarDeMayorAMenorVentas(); break;
                    case 2: listarDeMenorAMayorVentas(); break;
                    case 3: listaIdMenorAMayorCliente(); break;
                    case 4: listaIdMayorAMenorCliente(); break;
                    case 5: listaCuitMenorAMayorCliente(); break;
                    case 6: listaCuitMayorAMenorCliente(); break;
                    case 7: listaAlfabeticamenteCliente(); break;
                    default: break;
                }
                break;
            }
            case 5: {
                int baja;
                mostrarSubMenuBajaClientes();
                cin >> baja;
                switch (baja){
                    case 1: borrarLogicoCliente(); break;
                    case 2: borrarFisicoCliente(); break;
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

void mostrarSubMenuBajaClientes(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"BAJA CLIENTES"<<endl<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarClientes(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"LISTAR CLIENTES"<<endl<<endl;
    cout<<"1 - LISTAR DE MAYOR A MENOR VENTAS."<<endl;
    cout<<"2 - LISTAR DE MENOR A MAYOR VENTAS."<<endl;
    cout<<"3 - ORDENAR POR ID DE MENOR A MAYOR."<<endl;
    cout<<"4 - ORDENAR POR ID DE MAYOR A MENOR."<<endl;
    cout<<"5 - ORDENAR POR CUIT DE MENOR A MAYOR."<<endl;
    cout<<"6 - ORDENAR POR CUIT DE MAYOR A MENOR."<<endl;
    cout<<"7 - LISTAR ALFABETICAMENTE."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuModificarCliente(){
    dibujarCuadro(1,1,77,3);
    gotoxy(20,2);
    cout<<"MODIFICAR ATRIBUTOS DE LOS CLIENTES"<<endl<<endl;
    cout<<"1 - MODIFICAR TIPO."<<endl;
    cout<<"2 - MODIFICAR DIRECCION."<<endl;
    cout<<"3 - MODIFICAR CANTIDAD DE VENTAS."<<endl;
    cout<<"4 - MODIFICAR NOMBRE."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarMenuPrincipalClientes(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU CLIENTES"<<endl<<endl;
    cout<<"1 - AGREGAR CLIENTE."<<endl;
    cout<<"2 - BUSCAR CLIENTE."<<endl;
    cout<<"3 - MODIFICAR CLIENTE."<<endl;
    cout<<"4 - LISTAR CLIENTES."<<endl;
    cout<<"5 - ELIMINAR CLIENTE."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}