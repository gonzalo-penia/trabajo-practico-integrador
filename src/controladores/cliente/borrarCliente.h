#include "../contacto/borrarContacto.h"

void borrarFisicoCliente();
void borrarLogicoCliente();

void borrarLogicoCliente(){ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL CLIENTE
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    int eliminar;
    cout<<"ELIMINAR UN CLIENTE (LOGICO)."<<endl;
    listarClientesResumido();
    cout<<"---------------------"<<endl;

    cout<<"INGRESE EL ID DEL CLIENTE EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (borrarLogicoCliente)"<<endl;
        system("pause");
        return;
    }
    if(cliente.getId() == -1){
        cout<<"NO ENCONTRAMOS NINGUN CLIENTE REGISTRADO CON ESE ID"<<endl;
        system("pause");
        return;
    }

    system("cls");
    cout<<"SE ENCONTRO UN REGISTRO"<<endl;
    cliente.Mostrar();
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE CLIENTE? (1-SI, 2-NO): ";
    cin>> eliminar;
    if(eliminar==1){
    cliente.setEstado(false);
    bool flag=regCliente.actualizarCliente(cliente);
    if(flag==true)
    {
        eliminarContactosDeEntidad(id, 'C');

        cout<<"REGISTRO BORRADO DE FORMA CORRECTA"<<endl;
        cout<<"CONTACTOS ASOCIADOS ELIMINADOS"<<endl;
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

    system("pause");
    }else {
        cout<<"NO SE BORRO NADA"<<endl;
    }
}

void borrarFisicoCliente(){ //ESTA FUNCION PONDRA TODOS LOS VALORES EN 0 DEL CLIENTE
    system("cls");
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    int opcion;

    cout<<"2-BAJA FISICA."<<endl;
    listarClientesResumido();
    cout<<"---------------------"<<endl;

    cout<<"ELIMINAR UN CLIENTE."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (borrarFisicoCliente)"<<endl;
        return;
    }
    if(cliente.getId() == -1){
        cout<<"NO ENCONTRAMOS NINGUN CLIENTE REGISTRADO CON ESE ID"<<endl;
        return;
    }

    system("cls");
    cout<<"SE ENCONTRO UN REGISTRO"<<endl;
    cliente.Mostrar();
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE CLIENTE? (1-SI, 2-NO)";
    cin>>opcion;
    if(opcion==1){
    cliente.setNombre("Sin datos");
    cliente.setCuit("Sin datos");
    cliente.setcantidadVentas(0);
    cliente.setTipo(0);
    cliente.setEstado(false);
    bool flag=regCliente.actualizarCliente(cliente);
        if(flag==true)
        {
        eliminarContactosDeEntidad(id, 'C');
        cout<<"REGISTRO BORRADO DE FORMA CORRECTA"<<endl;
        cout<<"CONTACTOS ASOCIADOS ELIMINADOS"<<endl;
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
