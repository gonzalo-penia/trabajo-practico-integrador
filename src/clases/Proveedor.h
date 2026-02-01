#ifndef CLSPROVEEDOR_H_INCLUDED
#define CLSPROVEEDOR_H_INCLUDED


void listarContactosPorEntidadAux(int idEntidad, char tipoEntidad);

class Proveedor: public Entidad{
    private:
        int _id;
        int _cantidad_compras;
        int _cantidad_unidades;
    public:

    Proveedor(){}

    Proveedor(char,Direccion, Contacto, bool , int, int, bool); //CONSTRUCTOR DE LA CLASE PROVEEDOR

    Proveedor(int id, int cantidad_compras, int cantidad_unidades, const char* nombre, Direccion direccion){
        _id=id;
        _cantidad_compras=cantidad_compras;
        _cantidad_unidades=cantidad_unidades;
        strcpy(_nombre, nombre);
        _direccion=direccion;
        _estado=true;
    }

    //////INICIO DE SETS Y GETS

    int getId(){return _id;}
    int getCantidadCompras(){return _cantidad_compras;}
    int getCantidadUnidades(){return _cantidad_unidades;}

    void setId(const int p){_id=p;}
    void setCantidadCompras(const int cc){_cantidad_compras=cc;}
    void setCantidadUnidades(const int cu){_cantidad_unidades=cu;}
    void setEstado(const bool e){_estado=e;}

    void Mostrar();
    void Mostrar(bool);
    void Cargar(int identificador);
};

void Proveedor::Cargar(int identificador){
    setId(identificador);

    Entidad::Cargar();

    cout<<"CANTIDAD DE COMPRAS REALIZADAS A ESTE PROVEEDOR: ";
    cin>>_cantidad_compras;
    setCantidadCompras(_cantidad_compras);

    cout<<"CANTIDAD DE UNIDADES COMPRADAS A ESTE PROVEEDOR: ";
    cin>>_cantidad_unidades;
    setCantidadUnidades(_cantidad_unidades);

    setEstado(true);
}

void Proveedor::Mostrar(){

    cout<<"ID PROVEEDOR: "<<_id<<endl;
    cout<<"NOMBRE PROVEEDOR: "<<_nombre<<endl;
    cout<<"CANTIDAD DE COMPRAS REALIZADAS: "<<_cantidad_compras<<endl;
    cout<<"CANTIDAD DE UNIDADES COMPRADAS: "<<_cantidad_unidades<<endl;
    cout<<endl;
    cout<<"DIRECCION DEL PROVEEDOR: ";
    _direccion.Mostrar();
    cout<<endl;
    cout<<"CONTACTOS DEL PROVEEDOR:"<<endl;
    listarContactosPorEntidadAux(_id, 'P');
    cout<<endl;
}
void Proveedor::Mostrar(bool){
    cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;
    cout << left << setw(5) << _id << setw(40) << _nombre << setw(20) << _cantidad_compras << setw(20) << _cantidad_unidades << endl << endl;

}
#endif // CLSPROVEEDOR_H_INCLUDED
