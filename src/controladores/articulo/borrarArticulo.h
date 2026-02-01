#ifndef BORRARARTICULO_H_INCLUDED
#define BORRARARTICULO_H_INCLUDED

#include "../../clases/Articulo.h"
#include "../../clsArchivo/ArchivoArticulo.h"

#include <iostream>
#include <iomanip>
using namespace std;

void borrarLogico();
void borrarFisico();

void borrarLogico(){ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL ARTICULO
    system("cls");
    ArchivoArticulo ArchivoArticulo("../../data/articulos.dat");
    int id;
    cout<<"ELIMINAR UN ARTICULO."<<endl;
    cout<<"---------------------"<<endl;
    listaArticulosSimplificada();
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Articulo Articulo = ArchivoArticulo.traerArticulo(id);

    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    else{
        cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
        cout<<"-----------------------"<<endl;
    }

    Articulo.Mostrar();
    Articulo.setEstado(false);

    ArchivoArticulo.actualizarArticulo(Articulo);

}

void borrarFisico(){ //ESTA FUNCION ADEMAS DE DAR DE BAJA, SOBREESCRIBIRÁ LOS DATOS
    system("cls");
    ArchivoArticulo ArchivoArticulo("../../data/articulos.dat");
    int id;
    cout<<"ELIMINAR FISICO UN ARTICULO."<<endl;
    cout<<"---------------------"<<endl;
    listaArticulosSimplificada();
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Articulo Articulo = ArchivoArticulo.traerArticulo(id);

    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    else{
        cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
        cout<<"-----------------------"<<endl;
    }

    //Articulo.setId(0);
    char d[50];
    cargarCadena(d,50);
    Articulo.setDescripcion(d);
    Articulo.setCosto(0);
    Articulo.setGanancia(0);
    Articulo.setUnidades(0);
    Articulo.setEstado(false);

    ArchivoArticulo.actualizarArticulo(Articulo);
  

}


#endif // BORRARARTICULO_H_INCLUDED