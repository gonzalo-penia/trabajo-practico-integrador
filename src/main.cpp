#include <iostream>     // ENTRADA Y SALIDA ESTANDAR (CIN, COUT, >>, <<, ENDL, SETW, SETPRECISION, FIXED)
#include <iomanip>      // MANIPULADORES DE FLUJO (SETW, SETPRECISION, SETFILL, FIXED)
#include <cstdlib>      // GESTION DE MEMORIA, GENERACION DE NUMEROS ALEATORIOS, ETC (SRAND, EXIT)
#include <windows.h>    // INTERACTUAR CON S.O. WINDOWS (VERIFICARARCHIVOEXISTENTE, GOTOXY)
#include <cstdio>       // ENTRADA Y SALIDA DE DATOS (FOPEN, FCLOSE, FREAD, FWRITE, FSEEK, FTELL,
#include <cstring>      // MANIPULADORES DE CADENAS DE CARACTERES (STRCPY, STRCMP, STRLEN, STRSTR, )
#include <vector>       // PROPORCIONA LA CLASE DINAMICA "VECTOR" (PUSH_BACK)
#include <ctime>        // MANIPULAR Y TRABAJAR CON FECHAS Y TIEMPOS (TIME)
#include <cctype>       // ANALISIS Y CONVERSION DE CARACTERES (TOLOWER)
#include <direct.h>     // PROPORCIONA FUNCIONES PARA TRABAJAR CON ARCHIVOS Y DIRECTORIOS
#include <algorithm>

using namespace std;

#include "globales/funcionesGlobales.h"
#include "globales/menuPrincipal.h"
#include "clases/Direccion.h"
#include "clases/Fecha.h"
#include "clases/Vendedor.h"
#include "clsArchivo/ArchivoVendedor.h"
#include "controladores/vendedor/funcionesVendedor.h"
#include "clases/Contacto.h"
#include "clases/Entidad.h"
#include "clases/Cliente.h"
#include "clases/Proveedor.h"
#include "clsArchivo/ArchivoProveedor.h"
#include "clsArchivo/ArchivoCliente.h"
#include "controladores/cliente/funcionesCliente.h"
#include "clases/Articulo.h"
#include "clsArchivo/ArchivoArticulo.h"
#include "controladores/articulo/funcionesArticulo.h"
#include "controladores/proveedor/funcionesProveedor.h"
#include "clases/Item.h"
#include "clases/Detalle.h"
#include "clases/Emision.h"
#include "clases/Factura.h"
#include "clsArchivo/ArchivoFactura.h"
#include "controladores/factura/funcionesFactura.h"
#include "controladores/factura/funcionesCarrito.h"
#include "controladores/articulo/listadoArticulo.h"
#include "controladores/articulo/modificarArticulo.h"
#include "controladores/articulo/borrarArticulo.h"
#include "controladores/cliente/listadoCliente.h"
#include "controladores/cliente/modificarCliente.h"
#include "controladores/cliente/borrarCliente.h"
#include "controladores/proveedor/listadoProveedor.h"
#include "controladores/proveedor/modificarProveedor.h"
#include "controladores/proveedor/borrarProveedor.h"
#include "controladores/vendedor/listadoVendedor.h"
#include "controladores/vendedor/modificarVendedor.h"
#include "controladores/vendedor/borrarVendedor.h"
#include "controladores/contacto/listadoContacto.h"
#include "controladores/contacto/modificarContacto.h"
#include "controladores/contacto/borrarContacto.h"
#include "controladores/factura/listadoFactura.h"
#include "controladores/articulo/menuArticulo.h"
#include "controladores/cliente/menuCliente.h"
#include "controladores/contacto/menuContacto.h"
#include "controladores/factura/menuFactura.h"
#include "controladores/proveedor/menuProveedor.h"
#include "controladores/vendedor/menuVendedores.h"
#include "controladores/reportes/menuReportes.h"
#include "globales/testing/registrosDePrueba.h"
#include "globales/menuConfiguraciones.h"

int main(){
    int menu=1;
    while(menu!=0){
        system ("cls");
        mostrarMenuPrincipal();
        cin>>menu;
        switch(menu){
            case 1: menuEmision(); break;
            case 2: menuClientes(); break;
            case 3: menuArticulos(); break;
            case 4: menuProveedores(); break;
            case 5: menuContactos(); break;
            case 6: menuVendedores(); break;
            case 7: menuReportes(); break;
            case 8: menuConfiguraciones(); break;
            case 0: break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
        }
    }
    return 0;
}
