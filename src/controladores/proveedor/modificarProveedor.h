void modificarNombreProveedor();
void modificarDireccionProveedor();


inline void modificarNombreProveedor(){
    system("cls");
    
    ArchivoProveedor ArchivoProveedor("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");
    int id, confirmacion;
    
    cout<<"MODIFICACION DE NOMBRE DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    listarProveedoresResumido();
    
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    system("cls");

    Proveedor regProveedor = ArchivoProveedor.traerProveedor(id);

    if(regProveedor.getId() <= 0){
        manejoExcepciones(regProveedor.getId());
        return;
    }

    regProveedor.Mostrar();

    cout<<"ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
    cout<<endl;

    cin>>confirmacion;

    if(confirmacion == 1){
        system("cls");
        cout<<"ACTUALMENTE EL NOMBRE DEL PROVEEDOR ES: "<< regProveedor.getNombre()<<endl;
        cout<<"INGRESE EL NUEVO NOMBRE QUE SE LE ASIGNARA AL PROVEEDOR: "<<endl;
        char nuevoNombre[30];
        cargarCadena(nuevoNombre,30);
        regProveedor.setNombre(nuevoNombre);

        bool modificacionCorrecta = ArchivoProveedor.actualizarProveedor(regProveedor);
        if( modificacionCorrecta ){
            cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
            cout<<"NOTA: Los articulos con este proveedor mostraran automaticamente el nuevo nombre."<<endl;
            return;
        }
        
        else{
            cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
            return;
        }   
    }
}

inline void modificarDireccionProveedor(){
    system("cls");

    ArchivoProveedor Archivo("../../data/proveedores.dat");
    ArchivoArticulo regArchivoArticulo("../../data/articulos.dat");

    int id, confirmacion;

    cout<<"MODIFICACION DE LA DIRECCION DEL PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    listarProveedoresResumido();
    
    cout<<"INGRESE EL ID DEL PROVEEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;
    system("cls");

    Proveedor regProveedor = Archivo.traerProveedor(id);

    if(regProveedor.getId() <= 0){
        manejoExcepciones(regProveedor.getId());
        return;
    }

    regProveedor.Mostrar();

    cout<<"ESTE ES EL PROVEEDOR QUE DESEA MODIFICAR? CONFIRME CON 1, CANCELE CON 0";
    cout<<endl;

    cin>>confirmacion;

    if(confirmacion==1){
        system("cls");
        cout<<"INGRESE LOS NUEVOS QUE IRAN EN LA DIRECCION DE: "<< regProveedor.getNombre();
        cout<<endl;
        Direccion regDireccion = regProveedor.getDireccion();

        regDireccion.Cargar();

        regProveedor.setDireccion(regDireccion);

        bool modificacionCorrecta = Archivo.actualizarProveedor(regProveedor);
        if(modificacionCorrecta){
            cout<<"EL PROVEEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
            cout<<"NOTA: Los articulos con este proveedor mostraran automaticamente la nueva direccion."<<endl;
            return;
        }
        
        else{
            cout<<"FALLO AL MOMENTO DE MODIFICAR EL ARCHIVO";
            return;
        } 
    }
}
