#pragma once

class ArchivoVendedor{
private:

    char nombre[30];

public:
    ArchivoVendedor(const char *n="../../data/vendedores.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); //COPIA EL CONTENIDO DE N EN NOMBRE
    }
    const char *getNombre(){return nombre;}

    bool escribirArchivo(Vendedor regVendedor);

    Vendedor traerVendedor(int id);

    void leerArchivo();

    int obtenerIdDisponible();

    bool actualizarVendedor(Vendedor regVendedor);
    
    int contarArchivo();

    void vectorizarArchivo(Vendedor registros[],int cantidad);
    

};

int ArchivoVendedor::obtenerIdDisponible(){
    Vendedor regVendedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        // SI NO EXISTE EL ARCHIVO, EL PRIMER ID DISPONIBLE ES 1
        return 1;
    }
    int contador = 0;
    while(fread(&regVendedor,sizeof regVendedor,1,p)==1){
        contador++;
    }
    fclose(p);
    return contador + 1;
}

bool ArchivoVendedor::escribirArchivo(Vendedor regVendedor){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fwrite(&regVendedor,sizeof (regVendedor),1,p);
    fclose(p);
    return true;
}

Vendedor ArchivoVendedor::traerVendedor(int id){
    Vendedor regVendedor;
    Vendedor vendedor;

    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO AL MOMENTO DE INTENTAR ACCEDER AL ARCHIVO VENDEDOR"<<endl;
        return vendedor;
    }

    while(fread(&regVendedor,sizeof (regVendedor),1,p)==1){
        if(regVendedor.getId()==id){
            if(regVendedor.getEstado()){
                vendedor=regVendedor;
            }else{
                vendedor.setId(-1);
                fclose(p);
                return vendedor;
            }
        }
    }
    fclose(p);

    return vendedor;
}

void ArchivoVendedor::leerArchivo(){
    Vendedor regVendedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoVendedor-leerArchivo)"<<endl;
        return ;
    }

    cout << left << setw(15) << "ID" << setw(10) << "Cargo" << setw(25) << "Nombre" << setw(15) << "Sueldo" << endl;
    while(fread(&regVendedor, sizeof (regVendedor),1,p)==1){
        
        if(regVendedor.getEstado()){
        cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
        cout << left << setw(15) << regVendedor.getId() << setw(10) << regVendedor.getCargo() << setw(25) << regVendedor.getNombre() << setw(15) << regVendedor.getSueldo() << endl << endl;
        }
        
    }
    fclose(p);
    return;
}

bool ArchivoVendedor::actualizarVendedor(Vendedor regVendedor){
    int id = regVendedor.getId();

    FILE *p=fopen(nombre,"rb+");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoVendedor-actualizarVendedor)"<<endl;
        return false;
    }

    // BUSCAR LA POSICION DEL REGISTRO CON EL ID ESPECIFICADO
    Vendedor temp;
    int pos = 0;
    bool encontrado = false;

    while(fread(&temp, sizeof(Vendedor), 1, p) == 1){
        if(temp.getId() == id){
            encontrado = true;
            break;
        }
        pos++;
    }

    if(!encontrado){
        cout << "ERROR: No se encontro un vendedor con ID " << id << endl;
        fclose(p);
        return false;
    }

    // POSICIONAR Y ESCRIBIR
    fseek(p, sizeof(Vendedor) * pos, 0);
    bool confirmacion = fwrite(&regVendedor, sizeof(Vendedor), 1, p);
    fclose(p);
    return confirmacion;
}

int ArchivoVendedor::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Vendedor regVendedor;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoVendedor-contarArchivo)"<<endl;
    return false;
    }
    int contador = 0;
    while(fread(&regVendedor,sizeof (regVendedor),1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoVendedor::vectorizarArchivo(Vendedor registros[],int cantidad){
    FILE *p;

    p = fopen(nombre, "rb");

    if(p == nullptr){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoVendedor-vectorizarArchivo)"<<endl;
        return;
    }
    fread(registros, sizeof(Vendedor), cantidad, p);
    fclose(p);
}

