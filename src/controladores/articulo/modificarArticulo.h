void modificarDescripcion();
void modificarProveedor();
void modificarGanancia();
void modificarCostoVenta();

void modificarDescripcion(){
    system("cls");
    ArchivoArticulo Archivo("../../data/articulos.dat");
    
    int id;
    listaArticulosSimplificada();
    cout<<endl;
    cout<<endl;
    cout<<"MODIFICACION DE DESCRIPCION"<<endl;
    cout<<"------------------------------------"<<endl;

    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Articulo Articulo = Archivo.traerArticulo(id);
    
    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    system("cls");
    cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
    cout<<"-----------------------"<<endl;
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
    cout<<endl;
    cout<<endl;
    cout<<"MODIFICACION DE PROVEEDOR"<<endl;
    cout<<"------------------------------------"<<endl;

    listaArticulosSimplificada();

    cout<<"------------------------------------"<<endl;
    cout<<"INGRESE EL ID DEL ARTICULO QUE DESEA MODIFICAR"<<endl;
    cin>>idArticulo;

    Articulo = ArchivoArticulo.traerArticulo(idArticulo);

    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    system("cls");
    cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
    cout<<"-----------------------"<<endl;
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
    system("cls");
    cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
    cout<<"-----------------------"<<endl;

    cout<<"USTED ELIGIO EL ARTICULO: "<<Articulo.getDescripcion()<<endl;

    cout<<"EL COSTO DE VENTA ES $"<<Articulo.getCosto()<<endl;
    cout<<"LA GANANCIA: "<<Articulo.getGanancia()<<"%"<<endl;
    cout<<"EL PRECIO DE VENTA ACTUAL ES: $"<<Articulo.getCosto() * (1 + Articulo.getGanancia() / 100.0)<<endl;
    cout<<endl;
    cout<<"INGRESE LA NUEVA GANANCIA: "<<endl;
    cin>>ganancia;

    Articulo.setGanancia(ganancia);
    Fecha fechaActual;
    fechaActual.cargarFechaSistema();

    Articulo.setUltimaActualizacionPrecio(fechaActual);

    ArchivoArticulo.actualizarArticulo(Articulo);

    system("cls");
    cout<<"ARTICULO ACTUALIZADO CORRECTAMENTE!"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"EL COSTO DE VENTA ES $"<<Articulo.getCosto()<<endl;
    cout<<"LA NUEVA GANANCIA ES: "<<Articulo.getGanancia()<<"%"<<endl;
    cout<<"EL NUEVO PRECIO DE VENTA ES: $"<<Articulo.getCosto() * (1 + Articulo.getGanancia() / 100.0)<<endl;
    system("pause");
    
}

void modificarCostoVenta(){
    system("cls");
    ArchivoArticulo ArchivoArticulo("../../data/articulos.dat");
    int id;
    float precio;

    listaArticulosSimplificada();
    cout<<endl;
    cout<<endl;

    cout<<"INGRESE EL ID DEL ARTICULO CUYO COSTO DE VENTA DESEA MODIFICAR:"<<endl;
    cin>>id;

    Articulo Articulo = ArchivoArticulo.traerArticulo(id);
    
    if(Articulo.getId() <=0) {
    manejoExcepciones( Articulo.getId() );
    return;
    }

    system("cls");
    cout<<"ENCONTRAMOS UN ARTICULO"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"USTED ELIGIO EL ARTICULO: "<<Articulo.getDescripcion()<<endl;
    cout<<endl;
    cout<<"EL COSTO DE VENTA ES $"<<Articulo.getCosto()<<endl;
    cout<<"LA GANANCIA: "<<Articulo.getGanancia()<<"%"<<endl;
    cout<<"EL PRECIO DE VENTA ACTUAL ES: $"<<Articulo.getCosto() * (1 + Articulo.getGanancia() / 100.0)<<endl;


    cout<<"INGRESE EL NUEVO COSTO DE VENTA: "<<endl;
    cin>>precio;

    Articulo.setCosto(precio);
    Fecha fechaActual;
    fechaActual.cargarFechaSistema();
    Articulo.setUltimaActualizacionPrecio(fechaActual);

    ArchivoArticulo.actualizarArticulo(Articulo);

    system("cls");
    cout<<"ARTICULO ACTUALIZADO CORRECTAMENTE!"<<endl;
    cout<<"-----------------------"<<endl;
    cout<<"EL NUEVO COSTO DE VENTA ES $"<<Articulo.getCosto()<<endl;
    cout<<"LA GANANCIA: "<<Articulo.getGanancia()<<"%"<<endl;
    cout<<"EL NUEVO PRECIO DE VENTA ES: $"<<Articulo.getCosto() * (1 + Articulo.getGanancia() / 100.0)<<endl;
    system("pause");

}
