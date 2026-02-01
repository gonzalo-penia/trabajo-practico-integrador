#ifndef FUNCIONES_CARRITO_H_INCLUDED
#define FUNCIONES_CARRITO_H_INCLUDED

int pedirCantidad(Articulo& articulo);
Item conversionArticuloItem(Articulo& articulo, int cantidad, int tipoCliente);
void mostrarMenu();

Factura eliminarItemDelCarrito(Factura& factura) {
    systemClsEmisionFactura();
    cout << "ELIMINAR ITEM DEL CARRITO" << endl;   
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;

    Detalle detalleActual = factura.getDetalleVenta();

    if (detalleActual.getTamActual() == 0) {
        cout << endl << "EL CARRITO ESTA VACIO. No hay items para modificar." << endl;
        return factura;
    }

    cout << endl << "ITEMS EN EL CARRITO:" << endl;
    factura.mostrarDetalleCompleto();

    int nroItem;
    cout << endl << "Ingrese el numero de item que desea eliminar (1-" << detalleActual.getTamActual() << "): ";
    cin >> nroItem;

    if (nroItem < 1 || nroItem > detalleActual.getTamActual()) {
        cout << endl << "ERROR: Numero de item invalido." << endl;
        return factura;
    }

    int posItem = nroItem - 1;
    Item itemActual = detalleActual.getItem(posItem);

    ArchivoArticulo archivoArticulo;
    Articulo articulo = archivoArticulo.traerArticulo(itemActual.getIdArticulo());

    cout << endl << "Item seleccionado: " << articulo.getDescripcion() << endl;
    cout << "Cantidad: " << itemActual.getCantidad() << endl;

    cout << endl << "Esta seguro que desea eliminar este item? (1-SI, 0-NO): ";
    int confirmar;
    cin >> confirmar;

    if (confirmar == 1) {
        detalleActual.borrarItem(posItem);

        factura.setDetalleVenta(detalleActual);

        factura.calcularImportes();

        cout << endl << "Item eliminado exitosamente!" << endl;
    } else {
        cout << endl << "Eliminacion cancelada." << endl;
    }
    
    
    return factura;
}

Factura modificarCarrito(Factura& factura) {
    systemClsEmisionFactura();
    cout << "MODIFICAR CANTIDAD DE ITEM EN EL CARRITO" << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;

    Detalle detalleActual = factura.getDetalleVenta();

    if (detalleActual.getTamActual() == 0) {
        cout << endl << "EL CARRITO ESTA VACIO. No hay items para modificar." << endl;
        return factura;
    }

    cout << endl << "ITEMS EN EL CARRITO:" << endl;
    factura.mostrarDetalleCompleto();

    int nroItem;
    cout << endl << "Ingrese el numero de item que desea modificar (1-" << detalleActual.getTamActual() << "): ";
    cin >> nroItem;

    if (nroItem < 1 || nroItem > detalleActual.getTamActual()) {
        cout << endl << "ERROR: Numero de item invalido." << endl;
        return factura;
    }

    int posItem = nroItem - 1;
    Item itemActual = detalleActual.getItem(posItem);

    ArchivoArticulo archivoArticulo;
    Articulo articulo = archivoArticulo.traerArticulo(itemActual.getIdArticulo());

    cout << endl << "Item seleccionado: " << articulo.getDescripcion() << endl;
    cout << "Cantidad actual: " << itemActual.getCantidad() << endl;

    int nuevaCantidad = pedirCantidad(articulo);

    Item itemModificado = conversionArticuloItem(articulo, nuevaCantidad, factura.getTipoCliente());
    itemModificado.setNroItem(nroItem);

    detalleActual.modificarItem(posItem, itemModificado);

    factura.setDetalleVenta(detalleActual);

    factura.calcularImportes();

    cout << endl << "Cantidad modificada exitosamente!" << endl;

    return factura;
}

void elegirDatosVenta(int& tipoCompra, char* condicionPago) {
    cout << endl << "DATOS DE LA VENTA" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Seleccione el tipo de compra:" << endl;
    cout << "1 - Contado Directo" << endl;
    cout << "2 - Cuenta Corriente" << endl;
    cout << "Ingrese una opcion (1 o 2): ";

    do {
        cin >> tipoCompra;
        if (tipoCompra != 1 && tipoCompra != 2) {
            cout << "Opcion invalida. Ingrese 1 o 2: ";
        }
    } while (tipoCompra != 1 && tipoCompra != 2);

    cout << endl << "Ingrese la condicion de pago (ej: Contado, 30 dias, 60 dias): ";
    cin.ignore();
    cin.getline(condicionPago, 35);

    cout << endl << "Datos de venta configurados correctamente." << endl;
    system("pause");
}

void vaciarCarrito(Factura& factura) {
    int confirmacion;
    cout << "VACIAR CARRITO" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;
    cout << "Esta seguro que desea vaciar todo el carrito? (1-SI, 2-NO): ";
    cin >> confirmacion;


    if (confirmacion == 1) {
        Detalle detalleVacio;
        factura.setDetalleVenta(detalleVacio);
        factura.calcularImportes();
        cout << "Carrito vaciado exitosamente." << endl;
    }
}

bool validarStockDisponible(Articulo& articulo, float cantidad) {
    if (articulo.getUnidades() < cantidad) {
        cout << endl << "ERROR: Stock insuficiente!" << endl;
        cout << "Stock disponible: " << articulo.getUnidades() << endl;
        cout << "Cantidad solicitada: " << cantidad << endl << endl;
        return false;
    }
    return true;
}

Item conversionArticuloItem(Articulo& articulo, int cantidad, int tipoCliente) {
    int CantidadDeItems = cantidad;
    
    Item item(articulo, CantidadDeItems, tipoCliente);

    return item;
}

int pedirCantidad(Articulo& articulo) {
    int cantidad;
    bool cantidadValida = false;

    do {
        cout << endl << "Ingrese la cantidad deseada: ";
        cin >> cantidad;

        if (cantidad <= 0) {
            cout << "La cantidad debe ser mayor a 0. Intente nuevamente." << endl;
        } else if (!validarStockDisponible(articulo, cantidad)) {
            cout << "Intente nuevamente con una cantidad valida." << endl;
        } else {
            cantidadValida = true;
        }
    } while (!cantidadValida);
    return cantidad;
}

void mostrarResumenCarrito(Detalle& detalle, float importeTotal) {
    int cantidadItems = detalle.getTamActual();
    float importe = importeTotal;
    cout << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << " RESUMEN DEL CARRITO" << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << " Cantidad de items: " << cantidadItems << endl;
    cout << fixed << setprecision(2);
    cout << " Total: $" << importe << endl;
    cout << setfill('=') << setw(78) << "=" << setfill(' ') << endl;
    cout << endl;
}

void gestionCarrito() {
    cout<<"EMISION DE FACTURA."<<endl;
    cout<<"---------------------"<<endl;
    int opcion = 1;
    Factura factura;
    Cliente cliente = elegirCliente();
    Vendedor vendedor = elegirVendedor();

    int tipoCompra;
    char condicionPago[35];
    
    while (opcion != 0) {
        systemClsEmisionFactura();
        
        cout<<"CLIENTE: "<< cliente.getNombre() <<endl;
        cout<<"VENDEDOR: "<< vendedor.getNombre() <<endl;
        Detalle detalleActual = factura.getDetalleVenta();

        if (detalleActual.getTamActual() > 0) {
            factura.mostrarDetalleCompleto();
            cout << endl;
        }
        
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
                case 1: {
                    //LOOP PARA AGREGAR ARTICULOS HASTA CONFIRMAR
                    systemClsEmisionFactura();
                    Articulo articulo = elegirArticulo();
                    int cantidad = pedirCantidad(articulo);

                    Item nuevoItem = conversionArticuloItem( articulo, cantidad, factura.getTipoCliente() );

                    if (nuevoItem.getIdArticulo() != 0) factura = cargarItemEnFactura(factura, nuevoItem);
                    else cout << "Estas intentando ingresar un articulo con un ID inválido." << endl;

                    break;
                }
                
                case 2: modificarCarrito(factura); break;

                case 3: eliminarItemDelCarrito(factura); break;
                
                case 4: {
                    systemClsEmisionFactura();
                    vaciarCarrito(factura);
                    break;
                }

                // CONFIRMAR Y CONTINUAR
                case 5:
                    if (factura.getDetalleVenta().getTamActual() == 0) {
                        cout << endl << "EL CARRITO ESTA VACIO AGREGUE AL MENOS UN ARTICULO." << endl;
                        cout << endl << "TOQUE ENTER PARA CONTINUAR..." << endl;
                        system("pause");
                        opcion = 1;

                    } else {
                        // CARGAR DATOS DE LA VENTA
                        elegirDatosVenta(tipoCompra, condicionPago);
                        factura = cargarDatos( factura, cliente, vendedor, tipoCompra, condicionPago );
                        
                        ArchivoVendedor regArchivoVendedor;                        
                        ArchivoCliente regArchivoCliente;

                        int ventasClientes = cliente.getcantidadVentas();
                        cliente.setcantidadVentas(ventasClientes +1);
                        regArchivoCliente.actualizarCliente(cliente);

                        int ventasVendedor = vendedor.getventasRealizadas();
                        vendedor.setventasRealizadas(ventasVendedor +1);

                        regArchivoVendedor.actualizarVendedor(vendedor);

                        generarFactura(factura);

                        opcion = 0; // SALIR DEL MENU
                    }
                    break;

                case 0:
                    cout << endl << "Carrito cancelado." << endl;
                    system("pause");
                    break;

                default:
                    cout << endl << "Opcion invalida." << endl;
                    system("pause");
                    break;
        }
    }
}

#endif // FUNCIONES_CARRITO_H_INCLUDED
