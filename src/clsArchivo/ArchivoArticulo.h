#ifndef ARCHIVOARTICULO_H_INCLUDED
#define ARCHIVOARTICULO_H_INCLUDED

class ArchivoArticulo{
private:
    char nombre[30];

public:
    ArchivoArticulo(const char *n="../../data/articulos.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
    }
    const char *getNombre(){return nombre;}


    int contarArchivo(); 

    Articulo traerArticulo(int id);
    bool agregarArticulo(Articulo regArticulo);
    void actualizarArticulo(Articulo regArticulo);
    void mostrarArticulo();
    void vectorizarArchivo(Articulo registros[],int cantidad);
    int obtenerIdDisponible();
};

Articulo ArchivoArticulo::traerArticulo(int id){
    Articulo regArticulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoArticulo-traerArticulo)"<<endl;
        regArticulo.setId(-2);
        return regArticulo;
    }
    int contador=0;
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){
        if(regArticulo.getId()==id){
            fclose(p);
            return regArticulo;
        }
        contador++;
    }
    fclose(p);
    regArticulo.setId(-1);
    return regArticulo;
}

int ArchivoArticulo::obtenerIdDisponible(){
    Articulo regArticulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        // SI NO EXISTE EL ARCHIVO, EL PRIMER ID DISPONIBLE ES 1
        return 1;
    }
    int contador = 0;
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){
        contador++;
    }
    fclose(p);
    return contador + 1;
}

void ArchivoArticulo::mostrarArticulo(){
    Articulo regArticulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){
        regArticulo.Mostrar();
    }
    fclose(p);
}

int ArchivoArticulo::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Articulo regArticulo;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoArticulo-contarArchivo)"<<endl;
    return 0;
    }
    int contador = 0;
    while(fread(&regArticulo,sizeof regArticulo,1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoArticulo::vectorizarArchivo(Articulo registros[],int cantidad){
    FILE *p;

    p = fopen(nombre, "rb");

    if(p == nullptr){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoArticulo-vectorizarArchivo)"<<endl;
        return;
    }
    fread(registros, sizeof(Articulo), cantidad, p);
    fclose(p);
}

bool ArchivoArticulo::agregarArticulo(Articulo regArticulo){
    FILE *p = fopen(nombre, "ab");
    if(p == NULL){
        cout << "ERROR DE ARCHIVO (ArchivoArticulo-agregarArticulo)" << endl;
        return false;
    }
    fwrite(&regArticulo, sizeof(Articulo), 1, p);
    fclose(p);
    return true;
}

void ArchivoArticulo::actualizarArticulo(Articulo regArticulo){
    int id = regArticulo.getId();
    int pos = id - 1;

    if(pos < 0) {
        cout << "ERROR: ESTAS INTENTANDO ACCEDER A UN REGISTRO INEXISTENTE" << endl;
    }

    FILE *p = fopen(nombre, "rb+");
    if(p == NULL) {
        cout << "FALLO EN EL ACCESO AL ARCHIVO (articulo.dat)" << endl;
    }

    fseek(p, sizeof(Articulo) * pos, 0);
    fwrite(&regArticulo, sizeof(Articulo), 1, p);
    fclose(p);
}
#endif // ARCHIVOARTICULO_H_INCLUDED
