#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void mostrarMenuPrincipal();

void mostrarMenuPrincipal(){
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout<<"MENU PRINCIPAL"<<endl<<endl;

    cout<<"1 - MENU EMISION."<<endl;
    cout<<"2 - MENU CLIENTES."<<endl;
    cout<<"3 - MENU ARTICULOS."<<endl;
    cout<<"4 - MENU PROVEEDORES."<<endl;
    cout<<"5 - MENU CONTACTOS."<<endl;
    cout<<"6 - MENU VENDEDORES."<<endl;
    cout<<"7 - MENU REPORTES."<<endl;
    cout<<"8 - CONFIGURACIONES."<<endl;
    cout<<"----------------------"<<endl;
    cout<<"0 - FIN DEL PROGRAMA..."<<endl<<endl;
    cout<<"Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

#endif // MENUPRINCIPAL_H_INCLUDED
