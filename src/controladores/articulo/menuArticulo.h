void mostrarSubMenuBajaArticulos();
void mostrarSubMenuListarArticulos();
void mostrarSubMenuModificarArticulos();
void mostrarMenuPrincipalArticulos();
void menuArticulos();

void menuArticulos(){
    int sub_menu = 1;
    while(sub_menu != 0){
        system ("cls");
        mostrarMenuPrincipalArticulos();
        cin >> sub_menu;
        system ("cls");
        switch(sub_menu){
            case 1: cargarArticulo(); break;

            case 2: buscarArticulo(); break;

            case 3: {
                int modificar;
                system ("cls");
                mostrarSubMenuModificarArticulos();
                cin >> modificar;
                switch (modificar){
                    case 1: modificarDescripcion(); break;
                    case 2: modificarProveedor(); break;
                    case 3: modificarCostoVenta(); break;
                    case 4: modificarGanancia(); break;
                    default:
                        break;
                }
                break;
            }

            case 4: actualizarStock(); break;

            case 5: {
                int listar;
                mostrarSubMenuListarArticulos();
                cin >> listar;
                switch (listar){

                    case 1: listarArticuloPorPrecioDeMayorAMenor(); break;
                    case 2: listarArticuloPorPrecioDeMenorAMayor(); break;
                    case 3: listaArticuloPorIdDeMayorAMenor(); break;
                    case 4: listaArticuloPorIdDeMenorAMayor(); break;
                    case 5: listaArticulosSimplificada(); break;
                    default: break;
                }
                break;
            }

            case 6: {
                int baja;
                
                mostrarSubMenuBajaArticulos();

                cin >> baja;
                switch (baja){
                    case 1: borrarLogico(); break;
                    case 2: borrarFisico(); break;
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

void mostrarMenuPrincipalArticulos(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU ARTICULOS"<<endl<<endl;
    cout<<"1 - AGREGAR ARTICULO."<<endl;
    cout<<"2 - BUSCAR ARTICULO."<<endl;
    cout<<"3 - MODIFICAR ARTICULO."<<endl;
    cout<<"4 - ACTUALIZAR STOCK."<<endl;
    cout<<"5 - LISTAR ARTICULOS."<<endl;
    cout<<"6 - ELIMINAR ARTICULO."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuBajaArticulos(){
    system("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"BAJA ARTICULOS"<<endl<<endl;
    cout<<"1 - BAJA LOGICA."<<endl;
    cout<<"2 - BAJA FISICA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuListarArticulos(){
    system("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"LISTAR ARTICULOS"<<endl<<endl;
    cout<<"1 - LISTAR DE MAYOR A MENOR PRECIO."<<endl;
    cout<<"2 - LISTAR DE MENOR A MAYOR PRECIO."<<endl;
    cout<<"3 - ORDENAR POR ID DE MAYOR A MAYOR."<<endl;
    cout<<"4 - ORDENAR POR ID DE MENOR A MAYOR."<<endl;
    cout<<"5 - LISTAR POR ORDEN EN EL QUE FUERON AGREGADOS."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuModificarArticulos(){
    dibujarCuadro(1,1,77,3);
    gotoxy(24,2);
    cout<<"MODIFICAR ATRIBUTOS ARTICULOS"<<endl<<endl;
    cout<<"1 - MODIFICAR DESCRIPCION."<<endl;
    cout<<"2 - MODIFICAR PROVEEDOR."<<endl;
    cout<<"3 - MODIFICAR PRECIO VENTA."<<endl;
    cout<<"4 - MODIFICAR GANANCIA."<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"0 - VOLVER ATRAS"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}