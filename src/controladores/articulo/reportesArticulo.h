#ifndef REPORTESARTICULO_H_INCLUDED
#define REPORTESARTICULO_H_INCLUDED

///REPORTE 1: TOP 3 ARTICULOS MAS VENDIDOS ULTIMO MES
void reporteTop3ArticulosMasVendidosUltimoMes() {
    dibujarCuadro(1,1,77,3);
    gotoxy(15,2);
    cout << "TOP 3 ARTICULOS MAS VENDIDOS - ULTIMO MES" << endl << endl;

    ArchivoArticulo archivoArticulo;
    int cantArticulos = archivoArticulo.contarArchivo();

    if(cantArticulos <= 0) {
        cout << "No hay articulos registrados." << endl;
        system("pause");
        return;
    }

    // CARGAMOS LOS ARTICULOS DEL REGISTRO EN EL VECTOR articulos.
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArticulo.vectorizarArchivo(articulos, cantArticulos);

    int* ventasTemp = new int[cantArticulos]();

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado() && estaEnUltimoMes(factura.getFecha())) {
            Detalle detalle = factura.getDetalleVenta();
            int cantItems = detalle.getTamActual();

            for(int it = 0; it < cantItems; it++) {
                Item item = detalle.getItem(it);
                int idArticulo = item.getIdArticulo();

                // BUSCAR ARTICULO Y SUMAR CANTIDAD
                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        ventasTemp[a] += item.getCantidad();
                        break;
                    }
                }
            }
        }
    }

    // ORDENAR POR VENTAS (DESCENDENTE)
    for(int i = 0; i < cantArticulos - 1; i++) {
        
        for(int j = i + 1; j < cantArticulos; j++) {
            if(ventasTemp[j] > ventasTemp[i]) {
                int auxVentas = ventasTemp[i];
                ventasTemp[i] = ventasTemp[j];
                ventasTemp[j] = auxVentas;

                Articulo auxArt = articulos[i];
                articulos[i] = articulos[j];
                articulos[j] = auxArt;
            }
        }
    }

    // MOSTRAR ENCABEZADO
    cout << left << setw(8) << "ID"
         << setw(45) << "DESCRIPCION"
         << right << setw(20) << "UNIDADES VENDIDAS" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    // MOSTRAR TOP 3
    int mostrados = 0;
    for(int i = 0; i < cantArticulos && mostrados < 3; i++) {
        if(articulos[i].getEstado() && ventasTemp[i] > 0) {
            cout << left << setw(8) << articulos[i].getId()
                 << setw(45) << articulos[i].getDescripcion()
                 << right << setw(20) << ventasTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron ventas en el ultimo mes." << endl;
    }

    delete[] articulos;
    delete[] ventasTemp;
    cout << endl;
    system("pause");
}

///REPORTE 2: TOP 3 ARTICULOS QUE MAS GANANCIAS DEJAN
void reporteTop3ArticulosMasGanancias() {
    dibujarCuadro(1,1,77,3);
    gotoxy(18,2);
    cout << "TOP 3 ARTICULOS QUE MAS GANANCIAS DEJAN" << endl << endl;

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();

    if(cantArticulos <= 0) {
        cout << "No hay articulos registrados." << endl;
        system("pause");
        return;
    }

    // CARGAR ARTICULOS
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(articulos, cantArticulos);

    // ARRAYS PARALELOS
    int* ventasTemp = new int[cantArticulos]();
    float* gananciasTemp = new float[cantArticulos]();

    // CARGAR FACTURAS Y CONTAR VENTAS (HISTORICO - SIN FILTRO DE FECHA)
    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado()) {
            Detalle detalle = factura.getDetalleVenta();
            int cantItems = detalle.getTamActual();

            for(int it = 0; it < cantItems; it++) {
                Item item = detalle.getItem(it);
                int idArticulo = item.getIdArticulo();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        ventasTemp[a] += item.getCantidad();
                        break;
                    }
                }
            }
        }
    }

    // CALCULAR GANANCIAS: GANANCIA_POR_UNIDAD * UNIDADES_VENDIDAS
    for(int i = 0; i < cantArticulos; i++) {
        float costo = articulos[i].getCosto();
        int porcentajeGanancia = articulos[i].getGanancia();
        float gananciaPorUnidad = costo * (porcentajeGanancia / 100.0);
        gananciasTemp[i] = gananciaPorUnidad * ventasTemp[i];
    }

    // ORDENAR POR GANANCIAS (DESCENDENTE)
    for(int i = 0; i < cantArticulos - 1; i++) {
        for(int j = i + 1; j < cantArticulos; j++) {
            if(gananciasTemp[j] > gananciasTemp[i]) {
                float auxGan = gananciasTemp[i];
                gananciasTemp[i] = gananciasTemp[j];
                gananciasTemp[j] = auxGan;

                int auxVentas = ventasTemp[i];
                ventasTemp[i] = ventasTemp[j];
                ventasTemp[j] = auxVentas;

                Articulo auxArt = articulos[i];
                articulos[i] = articulos[j];
                articulos[j] = auxArt;
            }
        }
    }

    // MOSTRAR ENCABEZADO
    cout << fixed << setprecision(2);
    cout << left << setw(8) << "ID"
         << setw(40) << "DESCRIPCION"
         << right << setw(12) << "VENDIDOS"
         << setw(18) << "GANANCIAS ($)" << endl;
    cout << setfill('-') << setw(78) << "-" << setfill(' ') << endl;

    // MOSTRAR TOP 3
    int mostrados = 0;
    for(int i = 0; i < cantArticulos && mostrados < 3; i++) {
        if(articulos[i].getEstado() && gananciasTemp[i] > 0) {
            cout << left << setw(8) << articulos[i].getId()
                 << setw(40) << articulos[i].getDescripcion()
                 << right << setw(12) << ventasTemp[i]
                 << setw(18) << gananciasTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron ventas." << endl;
    }

    delete[] articulos;
    delete[] ventasTemp;
    delete[] gananciasTemp;
    cout << endl;
    system("pause");
}

///REPORTE 3: TOP 3 ARTICULOS MAS DIFICILES DE VENDER
void reporteTop3ArticulosDificilVenta() {
    dibujarCuadro(1,1,77,3);
    gotoxy(18,2);
    cout << "TOP 3 ARTICULOS MAS DIFICILES DE VENDER" << endl << endl;

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();

    if(cantArticulos <= 0) {
        cout << "No hay articulos registrados." << endl;
        system("pause");
        return;
    }

    // CARGAR TODOS LOS ARTICULOS (INCLUYE ELIMINADOS LOGICAMENTE)
    Articulo* todosArticulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(todosArticulos, cantArticulos);

    // FILTRAR SOLO ARTICULOS ACTIVOS
    int cantActivos = 0;
    for(int i = 0; i < cantArticulos; i++) {
        if(todosArticulos[i].getEstado()) {
            cantActivos++;
        }
    }

    if(cantActivos <= 0) {
        cout << "No hay articulos activos." << endl;
        delete[] todosArticulos;
        system("pause");
        return;
    }

    Articulo* articulos = new Articulo[cantActivos];
    int idx = 0;
    for(int i = 0; i < cantArticulos; i++) {
        if(todosArticulos[i].getEstado()) {
            articulos[idx] = todosArticulos[i];
            idx++;
        }
    }
    delete[] todosArticulos;
    cantArticulos = cantActivos;

    // ARRAY PARALELO PARA FECHA DE ULTIMA VENTA
    // INICIALIZAR CON FECHA MUY ANTIGUA (1/1/1900)
    Fecha* ultimaVentaTemp = new Fecha[cantArticulos];
    bool* tieneVentas = new bool[cantArticulos];
    for(int i = 0; i < cantArticulos; i++) {
        ultimaVentaTemp[i] = Fecha(1, 1, 1900);
        tieneVentas[i] = false;
    }

    // ITERAR FACTURAS PARA ENCONTRAR ULTIMA VENTA DE CADA ARTICULO
    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado()) {
            Fecha fechaFactura = factura.getFecha();
            Detalle detalle = factura.getDetalleVenta();
            int cantItems = detalle.getTamActual();

            for(int it = 0; it < cantItems; it++) {
                Item item = detalle.getItem(it);
                int idArticulo = item.getIdArticulo();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        tieneVentas[a] = true;
                        // ACTUALIZAR SI ESTA FECHA ES MAS RECIENTE
                        if(fechaFactura >= ultimaVentaTemp[a]) {
                            ultimaVentaTemp[a] = fechaFactura;
                        }
                        break;
                    }
                }
            }
        }
    }

    // ORDENAR POR FECHA DE ULTIMA VENTA (ASCENDENTE - MAS ANTIGUA PRIMERO)
    for(int i = 0; i < cantArticulos - 1; i++) {
        for(int j = i + 1; j < cantArticulos; j++) {
            // SI J TIENE FECHA MAS ANTIGUA QUE I, INTERCAMBIAR
            if(ultimaVentaTemp[j] <= ultimaVentaTemp[i] && !(ultimaVentaTemp[i] <= ultimaVentaTemp[j])) {
                Fecha auxFecha = ultimaVentaTemp[i];
                ultimaVentaTemp[i] = ultimaVentaTemp[j];
                ultimaVentaTemp[j] = auxFecha;

                bool auxTieneVentas = tieneVentas[i];
                tieneVentas[i] = tieneVentas[j];
                tieneVentas[j] = auxTieneVentas;

                Articulo auxArt = articulos[i];
                articulos[i] = articulos[j];
                articulos[j] = auxArt;
            }
        }
    }

    // MOSTRAR ENCABEZADO
    cout << left << setw(8) << "ID"
         << setw(45) << "DESCRIPCION"
         << right << setw(20) << "ULTIMA VENTA" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    // MOSTRAR TOP 3 ARTICULOS ACTIVOS
    int mostrar = (cantArticulos < 3) ? cantArticulos : 3;
    for(int i = 0; i < mostrar; i++) {
        cout << left << setw(8) << articulos[i].getId()
             << setw(45) << articulos[i].getDescripcion()
             << right << setw(20);
        if(tieneVentas[i]) {
            cout << ultimaVentaTemp[i].toString();
        } else {
            cout << "SIN VENTAS";
        }
        cout << endl;
    }

    delete[] articulos;
    delete[] ultimaVentaTemp;
    delete[] tieneVentas;
    cout << endl;
    system("pause");
}

///REPORTE 4: ARTICULOS POR AGOTARSE (STOCK < 10)
void reporteArticulosPorAgotarse() {
    dibujarCuadro(1,1,77,3);
    gotoxy(18,2);
    cout << "ARTICULOS POR AGOTARSE (STOCK < 10)" << endl << endl;

    ArchivoArticulo archivo;
    int cant = archivo.contarArchivo();

    if(cant <= 0) {
        cout << "No hay articulos registrados." << endl;
        system("pause");
        return;
    }

    Articulo* articulos = new Articulo[cant];

    //!!
    archivo.vectorizarArchivo(articulos, cant);

    // MOSTRAR ENCABEZADO
    cout << left << setw(8) << "ID"
         << setw(50) << "DESCRIPCION"
         << right << setw(15) << "STOCK ACTUAL" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    bool hayArticulos = false;
    for(int i = 0; i < cant; i++) {
        if(articulos[i].getEstado() && articulos[i].getUnidades() < 10) {
            cout << left << setw(8) << articulos[i].getId()
                 << setw(50) << articulos[i].getDescripcion()
                 << right << setw(15) << articulos[i].getUnidades() << endl;
            hayArticulos = true;
        }
    }

    if(!hayArticulos) {
        cout << "No hay articulos con stock bajo." << endl;
    }

    delete[] articulos;
    cout << endl;
    system("pause");
}

#endif // REPORTESARTICULO_H_INCLUDED
