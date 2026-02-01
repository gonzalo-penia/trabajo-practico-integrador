#include "../contacto/borrarContacto.h"

void borrarProveedorLogico();
void borrarProveedorFisico();

inline void borrarProveedorLogico(){ //ESTA FUNCION SOLO DARA DE BAJA EL ESTADO DEL ARTICULO
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    int id;
    cout<<"ELIMINAR UN PROVEEDOR."<<endl;
    cout<<"---------------------"<<endl;
    listarProveedoresResumido();
    cout<<"INGRESE EL ID DEL PROVEEDOR EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Proveedor Proveedor = Archivo.traerProveedor(id);

    if(Proveedor.getId() <= 0){
        manejoExcepciones(Proveedor.getId());
        return;
    }

    cout<<"SE ENCONTRO UN REGISTRO"<<endl;
    Proveedor.Mostrar();
    Proveedor.setEstado(false);

    bool flag = Archivo.actualizarProveedor(Proveedor);
    if(flag==true)
    {
        eliminarContactosDeEntidad(id, 'P');

        cout<<"REGISTRO BORRADO DE FORMA CORRECTA"<<endl;
        cout<<"CONTACTOS ASOCIADOS ELIMINADOS"<<endl;
        system("pause");
    }
    else{
        cout<<"NO SE PUDO BORRAR EL REGISTRO";
    }

}

inline void borrarProveedorFisico(){ //ESTA FUNCION ADEMAS DE DAR DE BAJA, SOBREESCRIBIR� LOS DATOS
    ArchivoProveedor Archivo("../../data/proveedores.dat");
    int id;
    cout<<"BORRAR FISICO PROVEEDOR."<<endl;
    cout<<"---------------------"<<endl;
    listarProveedoresResumido();
    cout<<"INGRESE EL ID DEL ARTICULO EL CUAL DESEA ELIMINAR:"<<endl;
    cin>> id;

    Proveedor Proveedor = Archivo.traerProveedor(id);

    if(Proveedor.getId() <= 0){
        manejoExcepciones(Proveedor.getId());
        return;
    }

    cout<<"SE ENCONTRO UN REGISTRO"<<endl;
    Proveedor.Mostrar();
    cout<<"ESTA SEGURO QUE QUIERE ELIMINAR ESTE PROVEEDOR? (1-SI, 2-NO)";
    int opcion;
    cin>>opcion;
    if(opcion==1){
    //Proveedor.setId(0);
    Proveedor.setNombre("Sin datos");
    Proveedor.setCantidadCompras(0);
    Proveedor.setCantidadUnidades(0);
    Proveedor.setEstado(false);
    bool flag = Archivo.actualizarProveedor(Proveedor);
    if(flag==true)
    {   
        eliminarContactosDeEntidad(id, 'P');
        cout<<"CONTACTOS ASOCIADOS ELIMINADOS"<<endl;
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
