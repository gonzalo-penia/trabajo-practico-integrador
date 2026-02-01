#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

///FUNCION HELPER PARA FILTRAR POR ULTIMO MES
bool estaEnUltimoMes(Fecha fecha) {
    Fecha hoy;
    hoy.cargarFechaSistema();

    int mesLimite = hoy.getMes() - 1;
    int anioLimite = hoy.getAnio();
    if (mesLimite <= 0) {
        mesLimite = 12;
        anioLimite--;
    }
    Fecha limite(hoy.getDia(), mesLimite, anioLimite);

    return (fecha >= limite);
}

#include "../factura/reportesFactura.h"
#include "../articulo/reportesArticulo.h"
#include "../cliente/reportesCliente.h"
#include "../vendedor/reportesVendedor.h"
#include "../proveedor/reportesProveedor.h"

///MENU PRINCIPAL DE REPORTES
void mostrarMenuPrincipalReportes() {
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout << "MENU REPORTES" << endl << endl;

    cout << "1 - REPORTES DE ARTICULOS." << endl;
    cout << "2 - REPORTES DE CLIENTES." << endl;
    cout << "3 - REPORTES DE FACTURAS." << endl;
    cout << "4 - REPORTES DE PROVEEDORES." << endl;
    cout << "5 - REPORTES DE VENDEDORES." << endl;
    cout << "----------------------" << endl;
    cout << "0 - VOLVER AL MENU PRINCIPAL" << endl << endl;
    cout << "Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

///SUBMENUS

void mostrarSubMenuReportesArticulos() {
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "REPORTES - ARTICULOS" << endl << endl;

    cout << "1 - TOP 3 MAS VENDIDOS (ULTIMO MES)." << endl;
    cout << "2 - TOP 3 QUE MAS GANANCIAS DEJAN." << endl;
    cout << "3 - TOP 3 MAS DIFICILES DE VENDER." << endl;
    cout << "4 - ARTICULOS POR AGOTARSE (STOCK < 10)." << endl;
    cout << "----------------------" << endl;
    cout << "0 - VOLVER ATRAS" << endl << endl;
    cout << "Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuReportesClientes() {
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "REPORTES - CLIENTES" << endl << endl;

    cout << "1 - TOP 3 CLIENTES QUE MAS COMPRAS REALIZARON DURANTE EL ULTIMO MES." << endl;
    cout << "2 - TOP 3 CLIENTES QUE MAS COMPRAS REALIZARON." << endl;
    cout << "3 - TOP 3 CLIENTES QUE MAS DINERO GASTARON DURANTE EL ULTIMO MES." << endl;
    cout << "4 - TOP 3 CLIENTES QUE MAS DINERO GASTARON HISTORICAMENTE." << endl;
    cout << "----------------------" << endl;
    cout << "0 - VOLVER ATRAS" << endl << endl;
    cout << "Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuReportesFacturas() {
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "REPORTES - FACTURAS" << endl << endl;

    cout << "1 - TOP 3 FACTURAS QUE MAS DINERO DEJARON." << endl;
    cout << "2 - TOP 3 FACTURAS CON MAS ITEMS VENDIDOS." << endl;
    cout << "----------------------" << endl;
    cout << "0 - VOLVER ATRAS" << endl << endl;
    cout << "Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuReportesProveedores() {
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "REPORTES - PROVEEDORES" << endl << endl;

    cout << "1 - TOP 3 PROVEEDORES A LOS QUE MAS VECES LES COMPRE DURANTE EL ULTIMO MES." << endl;
    cout << "2 - TOP 3 PROVEEDORES A LOS QUE MAS VECES LES COMPRE." << endl;
    cout << "3 - TOP 3 PROVEEDORES A LOS QUE MAS DINERO LES DEJE DURANTE EL ULTIMO MES." << endl;
    cout << "4 - TOP 3 PROVEEDORES A LOS QUE MAS DINERO LES DEJE." << endl;
    cout << "5 - TOP 3 PROVEEDORES A LOS QUE MAS ITEMS QUE LES COMPRE DURANTE EL ULTIMO MES." << endl;
    cout << "6 - TOP 3 PROVEEDORES A LOS QUE MAS ITEMS QUE LES COMPRE." << endl;
    cout << "----------------------" << endl;
    cout << "0 - VOLVER ATRAS" << endl << endl;
    cout << "Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

void mostrarSubMenuReportesVendedores() {
    dibujarCuadro(1,1,77,3);
    gotoxy(25,2);
    cout << "REPORTES - VENDEDORES" << endl << endl;

    cout << "1 - TOP 3 VENDEDORES CON MAS VENTAS DURANTE EL ULTIMO MES." << endl;
    cout << "2 - TOP 3 VENDEDORES CON MAS VENTAS." << endl;
    cout << "3 - TOP 3 VENDEDORES QUE MAS DINERO GENERARON DURANTE EL ULTIMO MES." << endl;
    cout << "4 - TOP 3 VENDEDORES QUE MAS DINERO GENERARON." << endl;
    cout << "----------------------" << endl;
    cout << "0 - VOLVER ATRAS" << endl << endl;
    cout << "Digite el Nro. de la opcion que desea ejecutar y presione ENTER: ";
}

///FUNCIONES DE NAVEGACION DE MENUS

void menuReportesArticulo() {
    int opcion = 1;
    while(opcion != 0) {
        system("cls");
        mostrarSubMenuReportesArticulos();
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: reporteTop3ArticulosMasVendidosUltimoMes(); break;
            case 2: reporteTop3ArticulosMasGanancias(); break;
            case 3: reporteTop3ArticulosDificilVenta(); break;
            case 4: reporteArticulosPorAgotarse(); break;
            case 0: break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
        }
    }
}

void menuReportesCliente() {
    int opcion = 1;
    while(opcion != 0) {
        system("cls");
        mostrarSubMenuReportesClientes();
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: reporteTop3ClientesUltimoMesCantidad(); break;
            case 2: reporteTop3ClientesHistoricoCantidad(); break;
            case 3: reporteTop3ClientesUltimoMesDinero(); break;
            case 4: reporteTop3ClientesHistoricoDinero(); break;
            case 0: break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
        }
    }
}

void menuReportesFactura() {
    int opcion = 1;
    while(opcion != 0) {
        system("cls");
        mostrarSubMenuReportesFacturas();
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: reporteTop3FacturasMayorDinero(); break;
            case 2: reporteTop3FacturasMasItems(); break;
            case 0: break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
        }
    }
}

void menuReportesProveedor() {
    int opcion = 1;
    while(opcion != 0) {
        system("cls");
        mostrarSubMenuReportesProveedores();
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: reporteTop3ProveedoresUltimoMesVeces(); break;
            case 2: reporteTop3ProveedoresHistoricoVeces(); break;
            case 3: reporteTop3ProveedoresUltimoMesDinero(); break;
            case 4: reporteTop3ProveedoresHistoricoDinero(); break;
            case 5: reporteTop3ProveedoresUltimoMesItems(); break;
            case 6: reporteTop3ProveedoresHistoricoItems(); break;
            case 0: break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
        }
    }
}

void menuReportesVendedor() {
    int opcion = 1;
    while(opcion != 0) {
        system("cls");
        mostrarSubMenuReportesVendedores();
        cin >> opcion;
        system("cls");

        switch(opcion) {
            case 1: reporteTop3VendedoresUltimoMesCantidad(); break;
            case 2: reporteTop3VendedoresHistoricoCantidad(); break;
            case 3: reporteTop3VendedoresUltimoMesDinero(); break;
            case 4: reporteTop3VendedoresHistoricoDinero(); break;
            case 0: break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
        }
    }
}

void menuReportes() {
    int sub_menu = 1;
    while(sub_menu != 0){
        system ("cls");
        mostrarMenuPrincipalReportes();
        cin >> sub_menu;
        system ("cls");
        switch(sub_menu){
            case 1: menuReportesArticulo(); break;
            case 2: menuReportesCliente(); break;
            case 3: menuReportesFactura(); break;
            case 4: menuReportesProveedor(); break;
            case 5: menuReportesVendedor(); break;
            case 0: break;
            default:
                cout << "ERROR: Opcion invalida" << endl << endl;
                system ("pause");
                break;
        }
    }
}

#endif // MENUREPORTES_H_INCLUDED
