void modificarDescripcion();
void modificarProveedor();
void modificarGanancia();
void modificarCostoVenta();

void modificarDescripcion(){
    system("cls");
    ArchivoArticulo Archivo("../../data/articulos.dat");
    
    int id;
    listaArticulosSimplificada();

    cout<<"MODIFICACION DE DESCRIPCION"<<endl;
    cout<<"------------------------------------"<<endl;

    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Articulo Articulo = Archivo.traerArticulo(id);
    
    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    cout<<"USTED ELIGIO EL ARTICULO: "<<Articulo.getDescripcion()<<endl;
    cout<<"INGRESE LA NUEVA DESCRIPCION QUE SE LE ASIGNARA AL ARTICULO: "<<endl;

    char x[50];
    cargarCadena(x,50);
    Articulo.setDescripcion(x);
    Fecha fechaActual;
    fechaActual.cargarFechaSistema();
    Articulo.setUltimaActualizacionPrecio(fechaActual);

    Archivo.actualizarArticulo(Articulo);

}

void modificarProveedor(){
    system("cls");
    ArchivoArticulo ArchivoArticulo("../../data/articulos.dat");
    ArchivoProveedor regArchivoProveedor("../../data/proveedores.dat");
    Proveedor actualProveedor;
    Proveedor nuevoProveedor;
    Articulo Articulo;

    int idArticulo;
    bool proveedor_existe;
    int  id_proveedor;

    cout<<"MODIFICACION DE PROVEEDOR"<<endl;

    listaArticulosSimplificada();

    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA MODIFICAR"<<endl;
    cin>>idArticulo;

    Articulo = ArchivoArticulo.traerArticulo(idArticulo);

    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    cout<<"USTED ELIGIO EL ARTICULO: "<< Articulo.getDescripcion() <<endl;

    actualProveedor = regArchivoProveedor.traerProveedor( Articulo.getIdProveedor() );
    
    do{
        cout<<"PROVEEDOR ACTUAL: "<< actualProveedor.getNombre() <<endl;
        cout<<"INGRESE EL NUEVO PROVEEDOR: "<<endl;
        cout<<"--------------------------- "<<endl;
        listaDeProveedores();

        cin>>id_proveedor;

        proveedor_existe = regArchivoProveedor.validarId(id_proveedor);

    } while(!proveedor_existe);

    nuevoProveedor = regArchivoProveedor.traerProveedor( id_proveedor ) ;

    if(nuevoProveedor.getId() <=0) {
    manejoExcepciones( nuevoProveedor.getId() );
    return;
    }
    
    Articulo.setIdProveedor( nuevoProveedor.getId() );

    Fecha fechaActual;
    fechaActual.cargarFechaSistema();
    Articulo.setUltimaActualizacionPrecio(fechaActual);

    ArchivoArticulo.actualizarArticulo(Articulo);

}

void modificarGanancia(){
    system("cls");
    ArchivoArticulo ArchivoArticulo("../../data/articulos.dat");
    int id;
    float ganancia;

    listaArticulosSimplificada();
    cout<<endl;
    cout<<endl;

    cout<<"INGRESE EL ID DEL ARTICULO CUYA GANANCIA DESEA MODIFICAR:"<<endl;
    cin>>id;

    Articulo Articulo = ArchivoArticulo.traerArticulo(id);
    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
    cout<<"-----------------------"<<endl;

    cout<<"USTED ELIGIO EL ARTICULO: "<<Articulo.getDescripcion()<<endl;

    cout<<"INGRESE LA NUEVA GANANCIA: "<<endl;
    cin>>ganancia;

    Articulo.setGanancia(ganancia);
    Fecha fechaActual;
    fechaActual.cargarFechaSistema();

    Articulo.setUltimaActualizacionPrecio(fechaActual);

    ArchivoArticulo.actualizarArticulo(Articulo);
    
}

void modificarCostoVenta(){
    system("cls");
    ArchivoArticulo ArchivoArticulo("../../data/articulos.dat");
    int id;
    float precio;

    listaArticulosSimplificada();
    cout<<endl;
    cout<<endl;

    cout<<"INGRESE EL ID DEL ARTICULO CUYO PRECIO DE VENTA DESEA MODIFICAR:"<<endl;
    cin>>id;

    Articulo Articulo = ArchivoArticulo.traerArticulo(id);
    
    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    cout<<"USTED ELIGIO EL ARTICULO: "<<Articulo.getDescripcion()<<endl;

    cout<<"INGRESE EL NUEVO PRECIO: "<<endl;
    cin>>precio;

    Articulo.setCosto(precio);
    Fecha fechaActual;
    fechaActual.cargarFechaSistema();
    Articulo.setUltimaActualizacionPrecio(fechaActual);

    ArchivoArticulo.actualizarArticulo(Articulo);


}
