void modificarCantidadVentas();
void modificarDireccion();
void modificarNombreCliente();
void modificarTipo();



void modificarTipo(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    system("cls");
    cout<<"MODIFICACION DE TIPO DE CLIENTE"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<endl;
    listarClientes();
    cout<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2)
    {
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarTipo)"<<endl;
        return;
    }
    if(cliente.getId() == -1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }

    cout<<"SE ENCONTRO UN CLIENTE"<<endl;

    cout<<"INGRESE EL NUEVO TIPO QUE SE LE ASIGNARA AL CLIENTE "<<endl;
    cout<<"(0- Sin tipo, 1-Responsable Inscripto, 2-Monotributo, 3-Exento, 4-Cons.Final): ";
    int tipoCliente;
    cin>>tipoCliente;
    cliente.setTipo(tipoCliente);
    bool flag= regCliente.actualizarCliente(cliente);
    system("cls");
    if(flag==true)
    {
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;

    }
    else{
        cout<<"FALLO AL MODIFICAR EL CLIENTE";
    }

}

void modificarDireccion(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    Direccion regDireccion;
    Contacto regContacto;
    int id;
    system("cls");
    cout<<"MODIFICACION DE DIRECCION"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<endl;
    listarClientes();
    cout<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2)
    {
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarDireccion)"<<endl;
        return;
    }
    if(cliente.getId() == -1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }

    cout<<"SE ENCONTRO UN CLIENTE"<<endl;

    system("cls");
    cout<<"INGRESE LA NUEVA DIRECCION"<<endl;
    regDireccion.Cargar();
    cliente.setDireccion(regDireccion);

    bool flag= regCliente.actualizarCliente(cliente);
    if(flag==true)
    {
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;
    }
    else{
        cout<<"FALLO AL MODIFICAR EL CLIENTE";
    }

}

void modificarCantidadVentas(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    system("cls");
    cout<<"MODIFICACION DE CANTIDAD DE VENTAS"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<endl;
    listarClientes();
    cout<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2)
    {
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarCantidadVentas)"<<endl;
        return;
    }
    if(cliente.getId() == -1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }

    cout<<"SE ENCONTRO UN CLIENTE"<<endl;

    cout<<"INGRESE LA NUEVA CANTIDAD DE VENTAS DEL CLIENTE "<<endl;
    int cantidadVentas;
    cin>>cantidadVentas;
    cliente.setcantidadVentas(cantidadVentas);
    bool flag= regCliente.actualizarCliente(cliente);
    system("cls");
    if(flag==true)
    {
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA"<<endl;

    }
    else{
        cout<<"FALLO AL MODIFICAR EL CLIENTE";
    }

}

void modificarNombreCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    cout<<"MODIFICACION DE NOMBRE"<<endl;
    cout<<"------------------------------------"<<endl;
    cout<<endl;
    listarClientes();
    cout<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2)
    {
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (modificarNombreCliente)"<<endl;
        return;
    }
    if(cliente.getId() == -1)
    {
        cout<<"NO HAY NINGUN CLIENTE REGISTRADO CON ESE ID."<<endl;
        return;
    }

    cout<<"SE ENCONTRO UN CLIENTE"<<endl;

    cout<<"INGRESE EL NUEVO NOMBRE QUE SE LE ASIGNARA AL CLIENTE: "<<endl;
    char nuevoNombre[50];
    cargarCadena(nuevoNombre,50);
    cliente.setNombre(nuevoNombre);
    bool flag= regCliente.actualizarCliente(cliente);
    if(flag==true)
    {
        cout<<endl;
        cout<<"EL CLIENTE HA SIDO MODIFICADO DE FORMA CORRECTA";
    }
    else{
        cout<<"FALLO AL MODIFICAR EL CLIENTE";
    }

}
