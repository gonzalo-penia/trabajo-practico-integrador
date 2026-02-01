#ifndef MENUCONFIG_H_INCLUDED
#define MENUCONFIG_H_INCLUDED

void mostrarMenuConfiguraciones(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"CONFIGURACIONES"<<endl<<endl;
    cout<<"1 - CARGAR DATOS DE PRUEBA."<<endl;
    cout<<"2 - BORRAR DATOS ACTUALES."<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"0 - VOLVER AL MENU PRINCIPAL"<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void menuConfiguraciones(){
    int sub_menu = 1;
    while(sub_menu != 0){
        system("cls");
        mostrarMenuConfiguraciones();
        cin >> sub_menu;
        system("cls");
        switch(sub_menu){
            case 1: cargarDatosDePrueba(); break;
            case 2: borrarDatosActuales(); break;
            case 0: break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
                break;
        }
    }
}

#endif // MENUCONFIG_H_INCLUDED
