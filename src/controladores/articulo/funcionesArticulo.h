#include "../../clases/Articulo.h"
#include "../../clases/Proveedor.h"
#include "../proveedor/funcionesProveedor.h"
#include "../../clsArchivo/ArchivoArticulo.h"
#include "../../clsArchivo/ArchivoProveedor.h"

#include "listadoArticulo.h"
#include "../proveedor/listadoProveedor.h"

void cargarArticulo();
void buscarArticulo();
Articulo elegirArticulo();
void actualizarStock();
void aumentarStock();
void disminuirStock();

void cargarArticulo(){
    system("cls");
    Articulo regArticulo;
    Proveedor regProveedor;
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");
    ArchivoProveedor regArchivoProveedor("../../data/proveedores.dat");
    int id,id_proveedor;
    bool proveedor_existe;
    bool continuar;
        
    listaDeProveedores();
    do{
        cout<<"INGRESE EL ID DEL PROVEEDOR CON EL QUE DESEA VINCULAR ESTE ARTICULO: ";
        cin>>id_proveedor;
        proveedor_existe= regArchivoProveedor.validarId(id_proveedor);

        if(!proveedor_existe){
            cout<<"ESE ID DE PROVEEDOR NO COINCIDE CON NINGUN PROOVEDOR REGISTRADO, PRUEBE NUEVAMENTE: ";
        }
    } while(!proveedor_existe);

    regProveedor = regArchivoProveedor.traerProveedor(id_proveedor);

    if(regProveedor.getId() <= 0){
        manejoExcepciones(id_proveedor);
        return;
    }

    system("cls");
    cout<<"ENCONTRAMOS EL PROVEEDOR: " << regProveedor.getNombre() << endl;

    cout<<"CONTINUE CON EL INGRESO DE DATOS DEL ARTICULO. "<<endl;

    id = regArchivoArticulo.obtenerIdDisponible();

    do{
        regArticulo.Cargar(id,regProveedor);
        system("cls");
        regArticulo.Mostrar();
        continuar = confirmacion();
    }while (!continuar);

    regArchivoArticulo.agregarArticulo(regArticulo);

}

void buscarArticulo(){
    ArchivoArticulo Archivo("../../data/articulos.dat");
    int id;
    cout<<"BUSCAR UN ARTICULO POR ID."<<endl;

    listaArticulosSimplificada();
    cout<<endl;

    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA BUSCAR EN NUESTRA BdD:"<<endl;
    cin>>id;

    system("cls");

    Articulo articulo = Archivo.traerArticulo(id);

    if(articulo.getId() <=0) {
    manejoExcepciones( articulo.getId() );
    return;
    }
    
    else{
        cout<<"SE ENCONTRO UN ARTICULO CON ESE ID: ";
        articulo.Mostrar();
    }

}

Articulo elegirArticulo() {
    int idArticulo;
    Articulo Articulo;
    ArchivoArticulo ArchivoArticulo;

    cout << "AGREGAR ARTICULO AL CARRITO" << endl;

    listaArticulosSimplificada();

    cout << endl << "Ingrese el ID del articulo que desea agregar al carrito: ";
    cin >> idArticulo;
    Articulo=ArchivoArticulo.traerArticulo(idArticulo);
    cout << endl << "Articulo seleccionado:" << Articulo.getDescripcion() << endl;
    return Articulo;
}

void actualizarStock() {

        cout<<"ACTUALIZACION DE STOCK PARA NUEVOS INGRESOS O EGRESOS:"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        cout<<"1 - AUMENTAR STOCK:"<<endl;
        cout<<"2 - DISMINUIR STOCK:"<<endl;
        
        int menu;
        cin>>menu;
        switch (menu){
            case 1: aumentarStock(); break;
            case 2: disminuirStock(); break;
            
            default:
            break;
        }
        
    }
    
void aumentarStock(){

    int idArticulo;
    int idProveedor;
    Articulo Articulo;
    ArchivoArticulo ArchivoArticulo;

    Proveedor Proveedor;
    ArchivoProveedor ArchivoProveedor;

    cout<<"1 - AUMENTAR STOCK:"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    listaArticulosStock();
    cout<<"------------------------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO AL CUAL SE LE VA A AUMENTAR EL STOCK:"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cin>>idArticulo;
    system("cls");
    Articulo = ArchivoArticulo.traerArticulo(idArticulo);

    if(Articulo.getId() <= 0){
        manejoExcepciones(Articulo.getId());
        return;
    }

    cout<<"INGRESE EL ID DEL PROVEEDOR VINCULADO CON ESTE INGRESO:"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    listaDeProveedores();
    cout<<"------------------------------------------------------"<<endl;
    cin>>idProveedor;
    system("cls");
    Proveedor = ArchivoProveedor.traerProveedor(idProveedor);

    if(Proveedor.getId() <= 0){
        manejoExcepciones(Proveedor.getId());
        return;
    }

    cout<<"STOCK ACTUAL: "<<Articulo.getUnidades()<<endl;
    cout<<"INGRESE LA CANTIDAD DE UNIDADES A SUMAR AL STOCK ACTUAL DEL ARTICULO "<<Articulo.getDescripcion()<<": "<<endl;
    int unidades_a_sumar;
    cin>>unidades_a_sumar;  

    int nuevo_stock = Articulo.getUnidades() + unidades_a_sumar;;
    Articulo.setUnidades(nuevo_stock);  
    ArchivoArticulo.actualizarArticulo(Articulo);
    
    cout<<"SE HA AUMENTADO EL STOCK DEL ARTICULO: "<<Articulo.getDescripcion()<<" PROVEEDOR: "<<Proveedor.getNombre()<<endl;
    Proveedor.setCantidadCompras( Proveedor.getCantidadCompras() + 1 );
    Proveedor.setCantidadUnidades( Proveedor.getCantidadUnidades() + unidades_a_sumar );
    ArchivoProveedor.actualizarProveedor( Proveedor );
    system("pause");
}
    
void disminuirStock(){

        int idArticulo;
        Articulo Articulo;
        ArchivoArticulo ArchivoArticulo;

        cout<<"2 - DISMINUIR STOCK:"<<endl;
        cout<<"------------------------------------------------------"<<endl;
        listaArticulosStock();
        cout<<"------------------------------------------------------"<<endl;
        cout<<"INGRESE EL ID DEL ARTICULO AL CUAL SE LE VA A DISMINUIR EL STOCK:"<<endl;
        cin>>idArticulo;

        system("cls");
        Articulo = ArchivoArticulo.traerArticulo(idArticulo);

        if(Articulo.getId() <= 0){
            manejoExcepciones(Articulo.getId());
            return;
        }

        cout<<"STOCK ACTUAL: "<<Articulo.getUnidades()<<endl;
        cout<<"INGRESE LA CANTIDAD DE UNIDADES A RESTAR AL STOCK ACTUAL DEL ARTICULO "<<Articulo.getDescripcion()<<": "<<endl;
        int unidades_a_restar;  
        cin>>unidades_a_restar;
        int nuevo_stock = Articulo.getUnidades() - unidades_a_restar;;
        Articulo.setUnidades(nuevo_stock);
        ArchivoArticulo.actualizarArticulo(Articulo);
        cout<<"SE HA DISMINUIDO EL STOCK DEL ARTICULO: "<<Articulo.getDescripcion()<<endl;
        system("pause");
}
