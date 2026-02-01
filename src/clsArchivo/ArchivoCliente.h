#pragma once

//CLIENTES

class ArchivoCliente:public Entidad{

private:

    char nombre[30];

public:
    ArchivoCliente(const char *n="../../data/clientes.dat"){ //CONSTRUCTOR
        strcpy(nombre, n); 
    }
    const char *getNombre(){return nombre;}

    bool agregarCliente(Cliente regCliente);

    bool actualizarCliente(Cliente regCliente);

    Cliente traerCliente(int id);
    
    int buscarRegistro(const char* cuit);
    void encontrarClienteNombre(const char* nombre);
    void encontrarClienteCuit(const char* cuit);

    int contarArchivo();
    bool validarIdCliente(int id);
    int obtenerIdDisponible();
    void vectorizarArchivo(Cliente registros[],int cantidad);
    void encontrarClienteRecaudacion(int id);

};


Cliente ArchivoCliente::traerCliente(int id){
    Cliente regCliente;
    Cliente cliente;

    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoCliente-traerCliente)"<<endl;
        cliente.setId(-2);  // -2 = ERROR DE ARCHIVO
        return cliente;
    }

    while(fread(&regCliente,sizeof (regCliente),1,p)==1){
        if(regCliente.getId()==id){
            if(regCliente.getEstado()){
                cliente=regCliente;
                fclose(p);
                return cliente;
            }else{
                cliente.setId(-1);  // -1 = INACTIVO
                fclose(p);
                return cliente;
            }
        }
    }
    fclose(p);
    cliente.setId(-1);  // -1 = NO ENCONTRADO
    return cliente;
}

bool ArchivoCliente::actualizarCliente(Cliente regCliente){
    int id = regCliente.getId();
    int pos = id - 1;  // ASUME IDS SECUENCIALES DESDE 1

    if(pos < 0) {
        cout << "ERROR: NO EXISTE UN CLIENTE CON ESE ID PARA ACTUALIZAR" << endl;
        return false;
    }

    FILE *p = fopen(nombre, "rb+");
    if(p == NULL) {
        cout << "FALLO EN EL ACCESO AL ARCHIVO (ArchivoCliente-actualizarCliente)" << endl;
        return false;
    }

    fseek(p, sizeof(Cliente) * pos, 0);
    bool confirmacion = fwrite(&regCliente, sizeof(Cliente), 1, p);
    fclose(p);

    return confirmacion;
}

int ArchivoCliente::obtenerIdDisponible(){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        // SI NO EXISTE EL ARCHIVO, EL PRIMER ID DISPONIBLE ES 1
        return 1;
    }
    int contador = 0;
    while(fread(&regCliente,sizeof regCliente,1,p)==1){
        contador++;
    }
    fclose(p);
    return contador + 1;
}

int ArchivoCliente::buscarRegistro(const char* cuit){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoCliente-buscarRegistro)"<<endl;
        return -2;
    }
    int contador=0;
    while(fread(&regCliente,sizeof (regCliente),1,p)==1){
        if(strcmp(regCliente.getCuit(),cuit)==0 && regCliente.getEstado()==true){
            cout<<endl<<"SE ENCONTRO UN CLIENTE CON ESE ID: "<<endl<<endl;
            cout << left << setw(5) << "ID" << setw(55) << "Razon Social" << setw(15) << "CUIT" << endl;
            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            cout << left << setw(5) << regCliente.getId() << setw(55) << regCliente.getNombre() << setw(15) << regCliente.getCuit() << endl << endl;
            fclose(p);
            return contador;
        }
        contador++;
    }
    fclose(p);
    return -1;
}

bool ArchivoCliente::agregarCliente(Cliente regCliente){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoCliente-agregarCliente)"<<endl;
        return false;
    }
    bool confirmacion = fwrite(&regCliente,sizeof (regCliente),1,p);
    fclose(p);
    return confirmacion;
}

int ArchivoCliente::contarArchivo(){ //DEVUELVE LA CANTIDAD DE ELEMENTOS DENTRO DEL ARCHIVO
    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL)
    {
    cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoCliente-contarArchivo)"<<endl;
    return false;
    }
    int contador = 0;
    while(fread(&regCliente,sizeof (regCliente),1,p)==1){contador++;}
    fclose(p);
    return contador;
}

void ArchivoCliente::vectorizarArchivo(Cliente registros[],int cantidad){
    FILE *p;

    p = fopen(nombre, "rb");

    if(p == nullptr){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (ArchivoCliente-vectorizarArchivo)"<<endl;
        return;
    }
    fread(registros, sizeof(Cliente), cantidad, p);
    fclose(p);
}

void ArchivoCliente::encontrarClienteNombre(const char* nombre){
    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }



    while(fread(&regCliente,sizeof (regCliente),1,p)==1){

        if(strcmp(regCliente.getNombre(),nombre)==0){
            if(regCliente.getEstado()){
                regCliente.Mostrar();
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE NOMBRE"<<endl;
            }
        }


    }
    fclose(p);
}

void ArchivoCliente::encontrarClienteCuit(const char* cuit){
    Cliente regCliente;
    FILE *p=fopen("../../data/clientes.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }



    while(fread(&regCliente,sizeof (regCliente),1,p)==1){

        if(strcmp(regCliente.getCuit(),cuit)==0){
            if(regCliente.getEstado()){
                regCliente.Mostrar();
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE CUIT"<<endl;
            }
        }


    }
    fclose(p);
}

void ArchivoCliente::encontrarClienteRecaudacion(int id){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&regCliente,sizeof (regCliente),1,p)==1){

        if(regCliente.getId()==id){
            if(regCliente.getEstado()){
                cout << left << setw(25) << "Nombre o Razon Social" << setw(35) << "Recaudacion" << endl;
                cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
                cout << left << setw(25) << regCliente.getNombre() << setw(35) << regCliente.getRecaudacion() << endl;
            }else{
                cout<<"NO HAY NADIE REGISTRADO CON ESE ID"<<endl;
            }
        }
    }
    fclose(p);
}

bool ArchivoCliente::validarIdCliente(int id){
    Cliente regCliente;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        return false;
    }

    while(fread(&regCliente,sizeof (regCliente),1,p)==1){
        if(regCliente.getId()==id && regCliente.getEstado()==true){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}
