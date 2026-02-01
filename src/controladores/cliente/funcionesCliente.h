#ifndef FUNCIONESCONTACTO_H_INCLUDED
    #include "../contacto/funcionesContacto.h"
#endif

#include "listadoCliente.h"

void aumentarVentas();
void buscarCliente();
void cargarCliente();
Cliente elegirCliente();

void recaudacionCredito(float recaudacion, int idCliente);
void recaudacionFactura(float recaudacion, int idCliente);


void cargarCliente(){
    Cliente regCliente;
    ArchivoCliente regArchivoCliente;
    int id;
    
    cout<<"AGREGAR CLIENTE."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"CARGA DE NUEVO CLIENTE."<<endl<<endl;
    cout<<"INGRESE LOS SIGUIENTES DATOS QUE LE SERAN SOLICITADOS."<<endl<<endl;
    bool continuar;
    do{ 
        id = regArchivoCliente.obtenerIdDisponible();
        cout<<"ID ASIGNADO AL CLIENTE "<< id <<"." <<endl;
        regCliente.Cargar(id);
        agregarContacto(id, 'C');
        regCliente.Mostrar();
        continuar = confirmacion();
    }while(!continuar);
        
    if(regArchivoCliente.agregarCliente(regCliente)==true){
        cout << endl;
        cout << "EL CLIENTE SE AGREGÓ EXITOSAMENTE" << endl;
    }else{
        cout<<"NO SE PUDO AGREGAR EL CLIENTE"<<endl;
    }
}

void buscarCliente(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;

    cout<<"BUSCAR UN CLIENTE."<<endl<<endl;
    cout<<"------------------"<<endl;
    listarClientesResumido();
    cout<<"INGRESE EL ID DEL CLIENTE A BUSCAR: ";
    cin>>id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    if(cliente.getId() == -1){
        cout<<"NO HAY NADIE REGISTRADO CON ESE ID"<<endl;
        return;
    }

    cliente.Mostrar();
    system("pause");
}

void aumentarVentas(){
    ArchivoCliente regCliente("../../data/clientes.dat");
    int id;
    cout<<"AUMENTAR VENTAS DE UN CLIENTE."<<endl;
    cout<<"---------------------"<<endl;
    cout<<"INGRESE EL ID DEL CLIENTE EL CUAL DESEA AUMENTAR VENTAS: ";
    cin>> id;

    Cliente cliente = regCliente.traerCliente(id);

    if(cliente.getId() == -2){
        cout<<"FALLO EN EL ACCESO AL ARCHIVO (aumentarVentas)"<<endl;
        return;
    }
    if(cliente.getId() == -1){
        cout<<"NO ENCONTRAMOS NINGUN CLIENTE REGISTRADO CON ESE ID"<<endl;
        return;
    }

    cout<<"SE ENCONTRO UN REGISTRO"<<endl;

    cout<<"INGRESE LA CANTIDAD DE VENTAS QUE QUIERE AUMENTAR: ";
    int aux;
    cin>>aux;
    cliente.setcantidadVentas(cliente.getcantidadVentas()+aux);
    bool flag=regCliente.actualizarCliente(cliente);
    if(flag==true)
    {
        cout<<"REGISTRO AUMENTADO DE FORMA CORRECTA";
    }
    else
    {
        cout<<"NO SE PUDO AUMENTAR EL REGISTRO";
    }
}

void recaudacionFactura(float recaudacion, int idCliente){
    ArchivoCliente regArchivoCliente("../../data/clientes.dat");
    Cliente cliente;

    int recaudacionaux;
    system("cls");

    cliente = regArchivoCliente.traerCliente(idCliente);

    if(cliente.getId() <= 0){
        cout<<"ERROR: Cliente no encontrado o inactivo (id: "<<idCliente<<")"<<endl;
        return;
    }

    recaudacionaux=cliente.getRecaudacion();
    cliente.setRecaudacion(recaudacionaux+recaudacion);

    regArchivoCliente.actualizarCliente(cliente);
    system("cls");

}

void recaudacionCredito(float recaudacion, int idCliente){
    ArchivoCliente regArchivoCliente("../../data/clientes.dat");
    Cliente cliente;

    int recaudacionaux;
    system("cls");

    cliente = regArchivoCliente.traerCliente(idCliente);

    if(cliente.getId() <= 0){
        cout<<"ERROR: Cliente no encontrado o inactivo (id: "<<idCliente<<")"<<endl;
        return;
    }

    recaudacionaux=cliente.getRecaudacion();
    cliente.setRecaudacion(recaudacionaux-recaudacion);
    regArchivoCliente.actualizarCliente(cliente);
    system("cls");

}
Cliente elegirCliente(){
    Cliente cliente;
    ArchivoCliente archivoCliente;
    int idCliente;

    cout << "PARA CONTINUAR DEBE SELECCIONAR UN CLIENTE." << endl << endl;

    do {

        listarClientesResumido();

        cout << endl << "INGRESE EL ID DEL CLIENTE AL QUE SE LE VA A VENDER: ";
        cin >> idCliente;

        cliente = archivoCliente.traerCliente(idCliente);


        if (cliente.getId() <= 0) {
            cout << endl << "ERROR: NO SE ENCONTRO UN CLIENTE CON EL ID " << idCliente << endl;
            cout << "POR FAVOR, INTENTE NUEVAMENTE." << endl << endl;
            system("pause");
            system("cls");
        }
    } while (cliente.getId() <= 0);

    system("cls");
    cout << endl << "Cliente seleccionado: " << cliente.getNombre() << endl;

    return cliente;
}

//FIN
