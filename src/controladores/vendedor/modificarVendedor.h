void modificarNombreVendedor();
void modificarVentasVendedor();
void modificarSueldoVendedor();
void modificarAntiguedadVendedor();
void modificarFechaNacimientoVendedor();
void modificarDomicilioVendedor();


void modificarNombreVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id;
    system("cls");
    cout<<"MODIFICACION DE NOMBRE"<<endl;
    cout<<"------------------------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);

    if(Vendedor.getId() == -1){
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarNombreVendedor)"<<endl;
        return;
    }
    else{
        cout<<"ENCONTRAMOS UN VENDEDOR"<<endl;
        cout<<"-----------------------"<<endl;
    }

    cout<<"INGRESE EL NUEVO NOMBRE QUE SE LE ASIGNARA AL VENDEDOR: "<<endl;
    char nuevoNombre[50];
    cargarCadena(nuevoNombre,50);
    Vendedor.setNombre(nuevoNombre);
    bool flag= regVendedor.actualizarVendedor(Vendedor);
    if(flag==true)
    {
        cout<<endl;
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarVentasVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id;
    system("cls");
    cout<<"MODIFICACION DE VENTAS REALIZADAS"<<endl;
    cout<<"------------------------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);

    if(Vendedor.getId() == -1){
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarVentasVendedor)"<<endl;
        return;
    }

    cout<<"INGRESE LA NUEVA CANTIDAD DE VENTAS DEL VENDEDOR "<<endl;
    int cantidadVentas;
    cin>>cantidadVentas;
    Vendedor.setventasRealizadas(cantidadVentas);
    bool flag= regVendedor.actualizarVendedor(Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarSueldoVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id;
    system("cls");
    cout<<"MODIFICACION DE SUELDO DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);

    if(Vendedor.getId() == -1){
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarSueldoVendedor)"<<endl;
        return;
    }

    cout<<"INGRESE EL NUEVO SUELDO DEL VENDEDOR "<<endl;
    int nuevoSueldo;
    cin>>nuevoSueldo;
    Vendedor.setSueldo(nuevoSueldo);
    bool flag= regVendedor.actualizarVendedor(Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarAntiguedadVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    Fecha nuevaFechaIngreso;
    int id;
    system("cls");
    cout<<"MODIFICACION FECHA DE INGRESO DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);

    if(Vendedor.getId() == -1){
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarAntiguedadVendedor)"<<endl;
        return;
    }

    cout<<"INGRESE LA NUEVA FECHA DE INGRESO DEL VENDEDOR"<<endl;
    nuevaFechaIngreso.Cargar();
    Vendedor.setfechaIngreso(nuevaFechaIngreso);
    cout<<"NUEVA ANTIGUEDAD CALCULADA: "<<Vendedor.getaniosAntiguedad()<<" anios"<<endl;
    bool flag= regVendedor.actualizarVendedor(Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;

    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarFechaNacimientoVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    Fecha nuevaFechaNacimiento;
    int id;
    system("cls");
    cout<<"MODIFICACION FECHA DE NACIMIENTO DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);

    if(Vendedor.getId() == -1){
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarFechaNacimientoVendedor)"<<endl;
        return;
    }

    cout<<"INGRESE LA NUEVA FECHA DE NACIMIENTO DEL VENDEDOR"<<endl;
    nuevaFechaNacimiento.Cargar();
    Vendedor.setFechaNacimiento(nuevaFechaNacimiento);
    cout<<"NUEVA EDAD CALCULADA: "<<Vendedor.getEdad()<<endl;
    bool flag= regVendedor.actualizarVendedor(Vendedor);
    system("cls");
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;

    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}

void modificarDomicilioVendedor(){
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    Direccion regDireccion;
    int id;
    system("cls");
    cout<<"MODIFICACION DE DOMICILIO DE VENDEDOR"<<endl;
    cout<<"------------------------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);

    if(Vendedor.getId() == -1){
        cout<<"NO HAY NINGUN VENDEDOR REGISTRADO CON ESE ID."<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarDomicilioVendedor)"<<endl;
        return;
    }

    cout<<"INGRESE EL NUEVO DOMICILIO"<<endl;
    regDireccion.Cargar();
    Vendedor.setDireccion(regDireccion); // HEREDADO DE ENTIDAD

    bool flag= regVendedor.actualizarVendedor(Vendedor);
    if(flag==true)
    {
        cout<<"EL VENDEDOR HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
        
    }
    else{
        cout<<"FALLO AL MODIFICAR EL VENDEDOR";
    }

}
