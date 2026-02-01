void borrarLogicoVendedor();
void borrarFisicoVendedor();

void borrarLogicoVendedor(){ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL CLIENTE
    system("cls");
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id;
    cout<<"1-BAJA LOGICA."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"ELIMINAR UN VENDEDOR."<<endl;
    cout<<"---------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);
    system("pause");

    if(Vendedor.getId() == -1){
        cout<<"NO ENCONTRAMOS NINGUN VENDEDOR REGISTRADO CON ESE ID"<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (borrarLogicoVendedor)"<<endl;
        return;
    }
    else{
        cout<<"SE ENCONTRO UN REGISTRO"<<endl;
    }

    Vendedor.Mostrar();
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE VENDEDOR? (1-SI, 2-NO)";
    int opcion;
    cin>>opcion;
    if(opcion==1){
    Vendedor.setEstado(false);
    bool flag=regVendedor.actualizarVendedor(Vendedor);
    if(flag==true)
    {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA";
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

    system("pause");
    }else {
        cout<<"NO SE BORRO NADA"<<endl;
    }

}

void borrarFisicoVendedor(){ //ESTA FUNCION PONDRA TODOS LOS VALORES EN 0 DEL CLIENTE
    system("cls");
    ArchivoVendedor regVendedor("../../data/vendedores.dat");
    int id;
    cout<<"2-BAJA FISICA."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"ELIMINAR UN VENDEDOR."<<endl;
    cout<<"---------------------"<<endl;
    listarVendedores();
    cout<<"INGRESE EL ID DEL VENDEDOR EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Vendedor Vendedor = regVendedor.traerVendedor(id);

    if(Vendedor.getId() == -1){
        cout<<"NO ENCONTRAMOS NINGUN VENDEDOR REGISTRADO CON ESE ID"<<endl;
        return;
    }
    else if(Vendedor.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (borrarFisicoVendedor)"<<endl;
        return;
    }
    else{
        cout<<"SE ENCONTRO UN REGISTRO"<<endl;
    }

   Vendedor.Mostrar();
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE VENDEDOR? (1-SI, 2-NO)";
    int opcion;
    cin>>opcion;
    if(opcion==1){
    Vendedor.setCargo(0);
    Vendedor.setventasRealizadas(0);
    Vendedor.setNombre("Sin datos");
    Vendedor.setDni(0);
    Vendedor.setEstado(false);
    bool flag=regVendedor.actualizarVendedor(Vendedor);
        if(flag==true)
        {
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA"<<endl;
        system("pause");
        }
     else
     {
        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
        system("pause");
     }
    }else{
        cout<<"NO SE BORRO NADA"<<endl;
        system("pause");
    }

}
