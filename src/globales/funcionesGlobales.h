#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

#include "../clases/Fecha.h"

class Articulo;
class ArchivoArticulo;
class Item;
class Detalle;
class Factura;

///FUNCIONES GLOBALES

/// FUNCIONES GLOBALES
void cargarCadena(char *palabra, int tam);
void convertirMinuscula(char* palabra);
bool confirmacion();
void manejoExcepciones(int id);
void gotoxy(int x, int y);
void dibujarCuadro(int x1, int y1, int x2, int y2);
/// FUNCIONES PARA BORRAR LA PANTALLA Y MANTENER DISTINTOS TITULOS
void systemClsEmisionFactura();
void systemClsListadoFactura();
///FUNCIONES DE LISTADOS
Fecha rangoFecha (Fecha& fechaInicial);

//PERMITE CARGAR UNA CADENA DE CARACTERES INDICANDO LA CADENA Y EL TAMA�O DE LA MISMA
void cargarCadena(char *palabra, int tam){
    int i = 0;
    fflush(stdin);
    for (i = 0 ; i < tam ; i++ ){
        palabra[i] = cin.get();
        if(palabra[i] == '\n') break;
    }
    palabra[i] = '\0';
    fflush(stdin);
}

    //PERMITE CONVERTIR A MINUSCULA UNA CADENA DE CARACTERES
void convertirMinuscula(char* palabra) {
    while (*palabra) {
        *palabra = tolower(static_cast<unsigned char>(*palabra));
        palabra++;
    }
}

    //DA LA OPCION DE CONFIRMAR UNA DECISION. DEVUELVE TRUE SI SE CONFIRMA, Y FALSE SI SE DESEA MODIFICAR.
bool confirmacion (){
    char opcion[3]{};
    bool confirmacion;
    bool bandera = true;
    while (bandera){
        bandera = false;
        cout << endl << "Esta conforme con su seleccion (1-SI, 2-NO): ";
        cargarCadena(opcion,3);
        if (strcmp(opcion,"1")==0||strcmp(opcion,"s")==0||strcmp(opcion,"S")==0||strcmp(opcion,"SI")==0||strcmp(opcion,"si")==0){
            confirmacion = true;
            cout << endl << "La opcion ha sido confirmada sin modificacion!" << endl << endl;
        } else if (strcmp(opcion,"2")==0||strcmp(opcion,"n")==0||strcmp(opcion,"N")==0||strcmp(opcion,"NO")==0||strcmp(opcion,"no")==0){
            cout << endl << "Esta seguro que desea modificar su seleccion (1-SI, 2-NO): ";
            cargarCadena(opcion,3);
            if (strcmp(opcion,"1")==0||strcmp(opcion,"s")==0||strcmp(opcion,"S")==0||strcmp(opcion,"SI")==0||strcmp(opcion,"si")==0){
                confirmacion = false;
                cout << endl << "Usted ha decidido modificar el ingreso." << endl << endl;
            } else if (strcmp(opcion,"2")==0||strcmp(opcion,"n")==0||strcmp(opcion,"N")==0||strcmp(opcion,"NO")==0||strcmp(opcion,"no")==0){
                bandera = true;
            }
        } else {
            cout << endl << "La opcion ingresada es invalida. Vuelva a intentarlo." << endl << endl;
            bandera = true;
        }
    }
    system ("pause");
    system ("cls");
    return confirmacion;
}

    //MANEJA LAS EXCEPCIONES DE ACCESO A ARCHIVOS Y BUSQUEDA DE REGISTROS
void manejoExcepciones(int id){
    if(id == -1){
        cout << "NO HAY NINGUN REGISTRO RELACIONADO CON ESE ID" << endl;
    }
    else if(id == -2){
        cout << "FALLO EN EL ACCESO AL ARCHIVO" << endl;
    }
    system("pause");
    return;
}

    //FUNCION QUE PERMITE SITUAR EL CURSOR EN UNA COORDENADA
void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

    //FUNCION QUE DIBUJA UN CUADRO PARA LOS TITULOS
void dibujarCuadro(int x1, int y1, int x2, int y2){
    int i;

    for (i=x1; i<x2; i++){
		gotoxy(i,y1); cout << "\304"; //LINEA HORIZONTAL SUPERIOR
		gotoxy(i,y2); cout << "\304"; //LINEA HORIZONTAL INFERIOR
    }

    for (i=y1; i<y2; i++){
		gotoxy(x1,i); cout <<"\263"; //LINEA VERTICAL IZQUIERDA
		gotoxy(x2,i); cout <<"\263"; //LINEA VERTICAL DERECHA
	}

    gotoxy(x1,y1); cout<< "\332";
    gotoxy(x1,y2); cout<< "\300";
    gotoxy(x2,y1); cout<< "\277";
    gotoxy(x2,y2); cout<< "\331";
}

/// FUNCIONES PARA BORRAR LA PANTALLA Y MANTENER DISTINTOS TITULOS

void systemClsEmisionFactura(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout << "EMISION DE FACTURA" << endl << endl;
}

void systemClsListadoFactura(){
    system ("cls");
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    cout << "LISTADO DE FACTURAS" << endl << endl;
}

///FUNCIONES DE LISTADOS
Fecha rangoFecha (Fecha& fechaInicial){
    Fecha fechaFinal;
    cout<<"Debera ingresar el rango de Fechas."<<endl<<endl;
    cout<<"\tFECHA INICIAL: "<<endl;
    fechaInicial.Cargar();
    cout<<endl<<"\tFECHA FINAL: "<<endl;
    fechaFinal.Cargar();
    return fechaFinal;
}

#endif // FUNCIONESGLOBALES_H_INCLUDED

