#include "listadoFactura.h"
#include "../articulo/listadoArticulo.h"

Factura cargarDatos(Factura factura, Cliente cliente, Vendedor vendedor, int tipoCompra, char* condicionPago);
Factura cargarItemEnFactura(Factura& factura, Item& nuevoItem);

void descontarStockPorFactura(Factura& factura){
    ArchivoArticulo archivoArticulo;
    Detalle detalle = factura.getDetalleVenta();
    int cantidadItems = detalle.getTamActual();

    for(int i = 0; i < cantidadItems; i++){

        Item itemActual = detalle.getItem(i);
        int idArticulo = itemActual.getIdArticulo();
        int cantidadVendida = itemActual.getCantidad();

        Articulo articulo = archivoArticulo.traerArticulo(idArticulo);

        if(articulo.getId() == -1){
            cout << "ADVERTENCIA: NO SE PUDO ENCONTRAR EL ARTICULO ID " << idArticulo << " PARA DESCONTAR STOCK." << endl;
            continue;
        }
        else if(articulo.getId() == -2){
            cout << "ADVERTENCIA: ERROR DE ACCESO AL ARCHIVO AL BUSCAR ARTICULO ID " << idArticulo << endl;
            continue;
        }

        int stockActual = articulo.getUnidades();
        int nuevoStock = stockActual - cantidadVendida;

        articulo.setUnidades(nuevoStock);
        
        archivoArticulo.actualizarArticulo(articulo);

    }
}

Factura cargarDatos(Factura factura, Cliente cliente, Vendedor vendedor, int tipoCompra, char* condicionPago){
        factura.setIdVendedor    ( vendedor.getId() );
        factura.setNombreVendedor( vendedor.getNombre() );
        factura.setIdCliente     ( cliente.getId() );
        factura.setCuitCliente   ( cliente.getCuit() );
        factura.setTipoCliente   ( cliente.getTipo() );
        factura.setNombreCliente ( cliente.getNombre() );
        factura.setDireccion     ( cliente.getDireccion() );
        factura.setTipoCompra    (tipoCompra);
        factura.setCondicionPago (condicionPago);
        Fecha fechaActual;
        factura.setFecha(fechaActual);
        factura.setEstado(true);
        return factura;
}

Factura cargarItemEnFactura(Factura& factura, Item& nuevoItem) {
    Detalle detalleTemp = factura.getDetalleVenta();

    nuevoItem.setNroItem(detalleTemp.getTamActual() + 1);

    detalleTemp.agregarItem(nuevoItem);

    factura.setDetalleVenta(detalleTemp);

    factura.calcularImportes();

    cout << endl << "Articulo agregado exitosamente al carrito!" << endl;

    return factura;
}

void generarFactura(Factura& factura){
    ArchivoFactura ArchivoFactura("../../data/facturas.dat");
    int id;
    int verificacion = ArchivoFactura.verificarArchivoExistente();

    if (verificacion == 0) {
        ArchivoFactura.crearArchivoVacio();
    }

    id = ArchivoFactura.obtenerIdDisponible();
    factura.setId(id);

    if ( ArchivoFactura.agregarRegistro(factura) ){
        descontarStockPorFactura(factura);

        cout << endl << "==================================================" << endl;
        cout << "LA FACTURA NRO. " << id << " HA SIDO EMITIDA CORRECTAMENTE." << endl;
        cout << "==================================================" << endl << endl;
        system("pause");
    }
    else{
        cout << endl << "ERROR: HUBO UN ERROR AL MOMENTO DE INTENTAR GUARDAR LA FACTURA." << endl;
        system("pause");
    }
}

