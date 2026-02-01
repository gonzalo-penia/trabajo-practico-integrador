#ifndef CLSARCHIVOPROVEEDOR_H_INCLUDED
#define CLSARCHIVOPROVEEDOR_H_INCLUDED

class ArchivoProveedor{
private:

    char nombre[30];

public:
    ArchivoProveedor(const char *n="../../data/proveedores.dat"){
        strcpy(nombre, n); 
    }
    const char *getNombre(){return nombre;}

    Proveedor traerProveedor(int id);
    bool agregarProveedor(Proveedor regProveedor);
    bool actualizarProveedor(Proveedor regProveedor);

    void leerArchivo();
    int contarArchivo();
    void vectorizarArchivo(Proveedor registros[],int cantidad);

    bool validarId(int id);

    int obtenerIdDisponible();

};

int ArchivoProveedor::obtenerIdDisponible(){
    Proveedor regProveedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        // SI NO EXISTE EL ARCHIVO, EL PRIMER ID DISPONIBLE ES 1
        return 1;
    }
    int contador = 0;
    while(fread(&regProveedor,sizeof regProveedor,1,p)==1){
        contador++;
    }
    fclose(p);
    return contador + 1;
}

bool ArchivoProveedor::agregarProveedor(Proveedor regProveedor){
    FILE *p = fopen(nombre, "ab");
    if(p == NULL){
        cout << "FALLO EN EL ACCESO AL ARCHIVO (ArchivoProveedor-agregarProveedor)" << endl;
        return false;
    }
    bool confirmacion = fwrite(&regProveedor, sizeof(Proveedor), 1, p);
    fclose(p);
    return confirmacion;
}

Proveedor ArchivoProveedor::traerProveedor(int id){
    Proveedor regProveedor;
    FILE *p = fopen(nombre, "rb");
    if(p == NULL){
        cout << "FALLO EN EL ACCESO AL ARCHIVO (ArchivoProveedor-traerProveedor)" << endl;
        regProveedor.setId(-2);
        return regProveedor;
    }

    while(fread(&regProveedor, sizeof(Proveedor), 1, p) == 1){
        if(regProveedor.getId() == id){
            fclose(p);
            return regProveedor;
        }
    }

    fclose(p);
    regProveedor.setId(-1); // NO ENCONTRADO
    return regProveedor;
}

bool ArchivoProveedor::actualizarProveedor(Proveedor regProveedor){
    int id = regProveedor.getId();
    int pos = id - 1;

    if(pos < 0) {
        cout << "ERROR: ID INVALIDO (debe ser mayor a 0)" << endl;
        return false;
    }

    FILE *p = fopen(nombre, "rb+");

    if(p == NULL){
        cout << "FALLO EN EL ACCESO AL ARCHIVO (ArchivoProveedor-actualizarProveedor)" << endl;
        return false;
    }

    fseek(p, sizeof(Proveedor) * pos, 0);
    bool confirmacion = fwrite(&regProveedor, sizeof(Proveedor), 1, p);
    fclose(p);

    return confirmacion;
}

void ArchivoProveedor::leerArchivo(){
    Proveedor regProveedor;
    FILE *p=fopen("../../data/proveedores.dat","rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoProveedor-leerArchivo)"<<endl;
        return ;
    }
    cout << left << setw(5) << "ID" << setw(40) << "NOMBRE" << setw(20) << "COMPRAS REALIZADAS:" << setw(20) << "UNIDADES COMPRADAS:" << endl;
    while(fread(&regProveedor, sizeof (regProveedor),1,p)==1){
        if(regProveedor.getEstado()){
            cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regProveedor.getId() << setw(40) << regProveedor.getNombre() << setw(20) << regProveedor.getCantidadCompras() << setw(20) << regProveedor.getCantidadUnidades() << endl << endl;
        }
    }
    fclose(p);
    return;
}

int ArchivoProveedor::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Proveedor regProveedor;
    FILE *p=fopen("../../data/proveedores.dat","rb");
    if(p==NULL){
    cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoProveedor-contarArchivo)"<<endl;
    return false;
    }
    int contador = 0;
    while(fread(&regProveedor,sizeof regProveedor,1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoProveedor::vectorizarArchivo(Proveedor registros[],int cantidad){
    FILE *p;

    p = fopen(nombre, "rb");

    if(p == nullptr){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoProveedor-vectorizarArchivo)"<<endl;
        return;
    }
    fread(registros, sizeof(Proveedor), cantidad, p);
    fclose(p);
}

bool ArchivoProveedor::validarId(int id){
    Proveedor regProveedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoProveedor-validarId)"<<endl;
        return false;
    }

    while(fread(&regProveedor,sizeof(regProveedor),1,p)==1){
        if(regProveedor.getId()==id && regProveedor.getEstado()==true){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

#endif // CLSARCHIVOARTICULO_H_INCLUDED
