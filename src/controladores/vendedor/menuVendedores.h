void mostrarMenuPrincipalVendedores();
void mostrarSubMenuBajaVendedores();
void mostrarSubMenuModificarVendedores();
void mostrarSubMenuListarVendedores();
void menuVendedores();

void mostrarMenuPrincipalVendedores(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU VENDEDORES"<<endl<<endl;
    cout<<"1 - AGREGAR VENDEDOR."<<endl;
    cout<<"2 - BUSCAR VENDEDOR."<<endl;
    cout<<"3 - MODIFICAR VENDEDOR."<<endl;
    cout<<"4 - LISTAR VENDEDORES."<<endl;
    cout<<"5 - ELIMINAR VENDEDOR."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void menuVendedores(){
    int sub_menu = 1;
    while(sub_menu != 0){
        system ("cls");
        mostrarMenuPrincipalVendedores();
        cin >> sub_menu;
        system ("cls");
        switch(sub_menu){
            case 1: cargarVendedor(); break;
            case 2: buscarVendedor(); break;
            case 3: {
                int modificar;
                system ("cls");
                mostrarSubMenuModificarVendedores();
                cin >> modificar;
                switch (modificar){
                    case 1: modificarSueldoVendedor(); break;
                    case 2: modificarVentasVendedor(); break;
                    case 3: modificarNombreVendedor(); break;
                    case 4: modificarAntiguedadVendedor(); break;
                    case 5: modificarFechaNacimientoVendedor(); break;
                    case 6: modificarDomicilioVendedor(); break;
                    default: break;
                }
                break;
            }
            case 4: {
                int listar;
                system ("cls");
                mostrarSubMenuListarVendedores();
                cin >> listar;
                switch (listar){
                    case 1: listarDeMayorAMenorVentasVendedor(); break;
                    case 2: listarDeMenorAMayorVentasVendedor(); break;
                    case 3: listaAntiguedadMayorAMenorVendedor(); break;
                    case 4: listaAntiguedadMenorAMayorVendedor(); break;
                    case 5: listarVendedores(); break;
                    default: break;
                }
                break;
            }
            case 5: {
                int baja;
                system ("cls");
                mostrarSubMenuBajaVendedores();
                cin >> baja;
                switch (baja){
                    case 1: borrarLogicoVendedor(); break;
                    case 2: borrarFisicoVendedor(); break;
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

void mostrarSubMenuBajaVendedores(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"BAJA VENDEDORES"<<endl<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuModificarVendedores(){
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout<<"MODIFICAR ATRIBUTOS VENDEDOR"<<endl<<endl;
    cout<<"1 - MODIFICAR SUELDO."<<endl;
    cout<<"2 - MODIFICAR VENTAS REALIZADAS."<<endl;
    cout<<"3 - MODIFICAR NOMBRE."<<endl;
    cout<<"4 - MODIFICAR FECHA DE INGRESO."<<endl;
    cout<<"5 - MODIFICAR FECHA DE NACIMIENTO."<<endl;
    cout<<"6 - MODIFICAR DOMICILIO."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarVendedores(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"LISTAR VENDEDORES"<<endl<<endl;
    cout<<"1 - LISTAR DE MAYOR A MENOR VENTAS."<<endl;
    cout<<"2 - LISTAR DE MENOR A MAYOR VENTAS."<<endl;
    cout<<"3 - ORDENAR POR ANTIGUEDAD DE MAYOR A MENOR."<<endl;
    cout<<"4 - ORDENAR POR ANTIGUEDAD DE MENOR A MAYOR."<<endl;
    cout<<"5 - LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}