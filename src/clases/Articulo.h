#ifndef CLSARTICULO_H_INCLUDED
#define CLSARTICULO_H_INCLUDED

class Articulo{
private:
    int id;
    int unidades;
    char descripcion[50];
    float costo;
    int ganancia;
    Fecha ultima_actualizacion_precio;
    int _idProveedor;
    bool estado;

public:
    Articulo(const char *n="NOMBRE"){ //CONSTRUCTOR
        strcpy(descripcion, n); //COPIA EL CONTENIDO DE N EN NOMBRE
    }

    Articulo(Fecha aux){
        ultima_actualizacion_precio=aux;
        estado=true;
    }

    Articulo(int d, int m, int a){ //CONSTRUCTOR
        ultima_actualizacion_precio.setDia(d);
        ultima_actualizacion_precio.setMes(m);
        ultima_actualizacion_precio.setAnio(a);
        estado=true;
    }

    int getId(){return id;}
    int getUnidades(){return unidades;}
    const char* getDescripcion(){return descripcion;}
    float getCosto(){return costo;}
    int getGanancia(){return ganancia;}
    Fecha getUltimaActualizacionPrecio(){return ultima_actualizacion_precio;}
    int getIdProveedor(){return _idProveedor;}
    bool getEstado(){return estado;}

    void setId(const int i){id=i;}
    void setUnidades(const int u){unidades=u;}
    void setDescripcion(const char *d){
        if(strlen(d) < 50){
            strcpy(descripcion, d);
        } else {
            cout << "ERROR: DESCRIPCION DEMASIADO LARGA (MAX 49 CARACTERES)" << endl;
            strcpy(descripcion, "ERROR");
        }
    }
    void setCosto(const float c){costo=c;}
    void setGanancia(const int g){ganancia=g;}
    void setUltimaActualizacionPrecio(Fecha fa){ultima_actualizacion_precio=fa;}
    void setIdProveedor(int idProv){_idProveedor=idProv;}
    void setEstado(bool est){estado=est;}


    bool Cargar(int id);
    bool Cargar(int id, Proveedor auxProveedor);

    void Mostrar();
    void Mostrar(bool);
};

bool Articulo::Cargar(int identificador){
    float precio_venta;
    setId(identificador);

    cout<<"DESCRIPCION DEL ARTICULO: ";
    cargarCadena(descripcion,49);
    cout<<"CANTIDAD DE UNIDADES EN STOCK: ";
    cin>>unidades;
    cout<<"PRECIO DE COSTO: $";
    cin>>costo;
    cout<<"MARGEN DE GANANCIA (%): ";
    cin>>ganancia;
    cout<<"PRECIO VENTA: $";
    precio_venta=costo * (1.0 + ganancia/100.0);
    cout << precio_venta<< endl;
    cout<<"FECHA DE ACTUALIZACION DE PRECIO: ";
    ultima_actualizacion_precio.cargarFechaSistema();
    ultima_actualizacion_precio.Mostrar();

    cout<<"ID DEL PROVEEDOR: ";
    ArchivoProveedor regArchivoProveedor;
    bool existe;
    int id_proveedor;
    cin>>id_proveedor;
    existe = regArchivoProveedor.validarId(id_proveedor);

    while (!existe)
    {
        system ("cls");
        cout<<"ESE ID DE PROVEEDOR NO EXISTE, PRUEBA CON UNO VALIDO"<<endl<<endl;
        cin>>id_proveedor;
        existe = regArchivoProveedor.validarId(id_proveedor);
    }

    _idProveedor = id_proveedor;

    estado=true;
    return true;
}

bool Articulo::Cargar(int identificador, Proveedor auxProveedor){
    float precio_venta;
    setId(identificador);
    cout<<"DESCRIPCION DEL ARTICULO: ";
    cargarCadena(descripcion,49);
    cout<<"CANTIDAD DE UNIDADES EN STOCK: ";
    cin>>unidades;
    cout<<"PRECIO DE COSTO: $";
    cin>>costo;
    cout<<"MARGEN DE GANANCIA (%): "; //PORCENTAJE
    cin>>ganancia;
    cout<<"PRECIO VENTA: $";
    precio_venta=costo * (1+ganancia/100.0);
    cout << precio_venta<< endl;
    cout<<"FECHA DE ACTUALIZACION DE PRECIO: ";
    ultima_actualizacion_precio.cargarFechaSistema();
    ultima_actualizacion_precio.Mostrar();

    _idProveedor = auxProveedor.getId();

    estado=true;
    return true; //TRUE CONFIRMA QUE SE CARGO EL USUARIO
}

void Articulo::Mostrar(){
    if(estado==true)
    {
        cout<<endl;
        cout<<"ID: ";
        cout<<id<<endl;
        cout<<"DESCRIPCION: ";
        cout<<descripcion<<endl;
        cout<<"CANTIDAD DE UNIDADES: ";
        cout<<unidades<<endl;
        cout<<"COSTO: ";
        cout<<costo<<endl;
        cout<<"GANANCIA (%): "; //PORCENTAJE
        cout<<ganancia<<endl;
        cout<<"PRECIO VENTA: ";
        cout<<costo * (1+ganancia/100.0)<<endl;
        cout<<"ULTIMA FECHA ACTUALIZACION DE PRECIO: ";
        ultima_actualizacion_precio.Mostrar();

        ArchivoProveedor archivoProveedor;
        Proveedor proveedor = archivoProveedor.traerProveedor(_idProveedor);
        if(proveedor.getId() > 0) {
            proveedor.Mostrar();
        } else {
            cout<<"PROVEEDOR NO ENCONTRADO (ID: "<<_idProveedor<<")"<<endl;
        }
    }
}

void Articulo::Mostrar(bool){

    if(estado==true){
        ArchivoProveedor archivoProveedor;
        Proveedor proveedor = archivoProveedor.traerProveedor(_idProveedor);
        const char* nombreProveedor = (proveedor.getId() > 0) ? proveedor.getNombre() : "PROVEEDOR NO ENCONTRADO";

        cout << "ID: " << id << "  | DESCRIPCION: " << descripcion << "  | PRECIO VENTA: $" << costo * (1 + ganancia / 100.0) << "  | PROVEEDOR: " << nombreProveedor << "  | ULT. ACTUALIZACION: " << ultima_actualizacion_precio.getDia()<<"/"<<ultima_actualizacion_precio.getMes()<<"/"<<ultima_actualizacion_precio.getAnio() << endl;
    }
}

#endif // CLSARTICULO_H_INCLUDED
