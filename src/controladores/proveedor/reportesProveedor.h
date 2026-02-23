#ifndef REPORTESPROVEEDOR_H_INCLUDED
#define REPORTESPROVEEDOR_H_INCLUDED

void reporteTop3ProveedoresUltimoMesVeces() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 PROVEEDORES ULTIMO MES (VECES QUE LES COMPRE)" << endl << endl;

    ArchivoProveedor archivoProv;
    int cantProveedores = archivoProv.contarArchivo();

    if(cantProveedores <= 0) {
        cout << "No hay proveedores registrados." << endl;
        system("pause");
        return;
    }

    Proveedor* proveedores = new Proveedor[cantProveedores];
    archivoProv.vectorizarArchivo(proveedores, cantProveedores);

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(articulos, cantArticulos);

    int* vecesTemp = new int[cantProveedores];
    for(int i = 0; i < cantProveedores; i++) {
        vecesTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado() && estaEnUltimoMes(factura.getFecha())) {
            bool* proveedorEnFactura = new bool[cantProveedores];
            for(int p = 0; p < cantProveedores; p++) {
                proveedorEnFactura[p] = false;
            }

            Detalle detalle = factura.getDetalleVenta();
            int cantItems = detalle.getTamActual();

            for(int it = 0; it < cantItems; it++) {
                Item item = detalle.getItem(it);
                int idArticulo = item.getIdArticulo();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        int idProveedor = articulos[a].getIdProveedor();

                        for(int p = 0; p < cantProveedores; p++) {
                            if(proveedores[p].getId() == idProveedor) {
                                proveedorEnFactura[p] = true;
                                break;
                            }
                        }
                        break;
                    }
                }
            }

            for(int p = 0; p < cantProveedores; p++) {
                if(proveedorEnFactura[p]) {
                    vecesTemp[p]++;
                }
            }

            delete[] proveedorEnFactura;
        }
    }

    for(int i = 0; i < cantProveedores - 1; i++) {
        for(int j = i + 1; j < cantProveedores; j++) {
            if(vecesTemp[j] > vecesTemp[i]) {
                int auxVeces = vecesTemp[i];
                vecesTemp[i] = vecesTemp[j];
                vecesTemp[j] = auxVeces;

                Proveedor auxProv = proveedores[i];
                proveedores[i] = proveedores[j];
                proveedores[j] = auxProv;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "VECES COMPRADO" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantProveedores && mostrados < 3; i++) {
        if(proveedores[i].getEstado() && vecesTemp[i] > 0) {
            cout << left << setw(8) << proveedores[i].getId()
                 << setw(45) << proveedores[i].getNombre()
                 << right << setw(20) << vecesTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron compras en el ultimo mes." << endl;
    }

    delete[] proveedores;
    delete[] articulos;
    delete[] vecesTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ProveedoresHistoricoVeces() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 PROVEEDORES HISTORICO (VECES QUE LES COMPRE)" << endl << endl;

    ArchivoProveedor archivoProv;
    int cantProveedores = archivoProv.contarArchivo();

    if(cantProveedores <= 0) {
        cout << "No hay proveedores registrados." << endl;
        system("pause");
        return;
    }

    Proveedor* proveedores = new Proveedor[cantProveedores];
    archivoProv.vectorizarArchivo(proveedores, cantProveedores);

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(articulos, cantArticulos);

    int* vecesTemp = new int[cantProveedores];
    for(int i = 0; i < cantProveedores; i++) {
        vecesTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado()) {
            bool* proveedorEnFactura = new bool[cantProveedores];
            for(int p = 0; p < cantProveedores; p++) {
                proveedorEnFactura[p] = false;
            }

            Detalle detalle = factura.getDetalleVenta();
            int cantItems = detalle.getTamActual();

            for(int it = 0; it < cantItems; it++) {
                Item item = detalle.getItem(it);
                int idArticulo = item.getIdArticulo();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        int idProveedor = articulos[a].getIdProveedor();

                        for(int p = 0; p < cantProveedores; p++) {
                            if(proveedores[p].getId() == idProveedor) {
                                proveedorEnFactura[p] = true;
                                break;
                            }
                        }
                        break;
                    }
                }
            }

            for(int p = 0; p < cantProveedores; p++) {
                if(proveedorEnFactura[p]) {
                    vecesTemp[p]++;
                }
            }

            delete[] proveedorEnFactura;
        }
    }

    for(int i = 0; i < cantProveedores - 1; i++) {
        for(int j = i + 1; j < cantProveedores; j++) {
            if(vecesTemp[j] > vecesTemp[i]) {
                int auxVeces = vecesTemp[i];
                vecesTemp[i] = vecesTemp[j];
                vecesTemp[j] = auxVeces;

                Proveedor auxProv = proveedores[i];
                proveedores[i] = proveedores[j];
                proveedores[j] = auxProv;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "VECES COMPRADO" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantProveedores && mostrados < 3; i++) {
        if(proveedores[i].getEstado() && vecesTemp[i] > 0) {
            cout << left << setw(8) << proveedores[i].getId()
                 << setw(45) << proveedores[i].getNombre()
                 << right << setw(20) << vecesTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No hay proveedores con compras registradas." << endl;
    }

    delete[] proveedores;
    delete[] articulos;
    delete[] vecesTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ProveedoresUltimoMesDinero() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 PROVEEDORES ULTIMO MES (DINERO QUE LES DEJE)" << endl << endl;

    ArchivoProveedor archivoProv;
    int cantProveedores = archivoProv.contarArchivo();

    if(cantProveedores <= 0) {
        cout << "No hay proveedores registrados." << endl;
        system("pause");
        return;
    }

    Proveedor* proveedores = new Proveedor[cantProveedores];
    archivoProv.vectorizarArchivo(proveedores, cantProveedores);

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(articulos, cantArticulos);

    float* dineroTemp = new float[cantProveedores];
    for(int i = 0; i < cantProveedores; i++) {
        dineroTemp[i] = 0;
    }

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
                int cantidad = item.getCantidad();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        int idProveedor = articulos[a].getIdProveedor();
                        float costo = articulos[a].getCosto();

                        for(int p = 0; p < cantProveedores; p++) {
                            if(proveedores[p].getId() == idProveedor) {
                                dineroTemp[p] += costo * cantidad;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < cantProveedores - 1; i++) {
        for(int j = i + 1; j < cantProveedores; j++) {
            if(dineroTemp[j] > dineroTemp[i]) {
                float auxDinero = dineroTemp[i];
                dineroTemp[i] = dineroTemp[j];
                dineroTemp[j] = auxDinero;

                Proveedor auxProv = proveedores[i];
                proveedores[i] = proveedores[j];
                proveedores[j] = auxProv;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "DINERO GASTADO ($)" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantProveedores && mostrados < 3; i++) {
        if(proveedores[i].getEstado() && dineroTemp[i] > 0) {
            cout << left << setw(8) << proveedores[i].getId()
                 << setw(45) << proveedores[i].getNombre()
                 << right << setw(20) << dineroTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron compras en el ultimo mes." << endl;
    }

    delete[] proveedores;
    delete[] articulos;
    delete[] dineroTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ProveedoresHistoricoDinero() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 PROVEEDORES HISTORICO (DINERO QUE LES DEJE)" << endl << endl;

    ArchivoProveedor archivoProv;
    int cantProveedores = archivoProv.contarArchivo();

    if(cantProveedores <= 0) {
        cout << "No hay proveedores registrados." << endl;
        system("pause");
        return;
    }

    Proveedor* proveedores = new Proveedor[cantProveedores];
    archivoProv.vectorizarArchivo(proveedores, cantProveedores);

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(articulos, cantArticulos);

    float* dineroTemp = new float[cantProveedores];
    for(int i = 0; i < cantProveedores; i++) {
        dineroTemp[i] = 0;
    }

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
                int cantidad = item.getCantidad();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        int idProveedor = articulos[a].getIdProveedor();
                        float costo = articulos[a].getCosto();

                        for(int p = 0; p < cantProveedores; p++) {
                            if(proveedores[p].getId() == idProveedor) {
                                dineroTemp[p] += costo * cantidad;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < cantProveedores - 1; i++) {
        for(int j = i + 1; j < cantProveedores; j++) {
            if(dineroTemp[j] > dineroTemp[i]) {
                float auxDinero = dineroTemp[i];
                dineroTemp[i] = dineroTemp[j];
                dineroTemp[j] = auxDinero;

                Proveedor auxProv = proveedores[i];
                proveedores[i] = proveedores[j];
                proveedores[j] = auxProv;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "DINERO GASTADO ($)" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantProveedores && mostrados < 3; i++) {
        if(proveedores[i].getEstado() && dineroTemp[i] > 0) {
            cout << left << setw(8) << proveedores[i].getId()
                 << setw(45) << proveedores[i].getNombre()
                 << right << setw(20) << dineroTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No hay proveedores con compras registradas." << endl;
    }

    delete[] proveedores;
    delete[] articulos;
    delete[] dineroTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ProveedoresUltimoMesItems() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 PROVEEDORES ULTIMO MES (CANTIDAD ITEMS)" << endl << endl;

    ArchivoProveedor archivoProv;
    int cantProveedores = archivoProv.contarArchivo();

    if(cantProveedores <= 0) {
        cout << "No hay proveedores registrados." << endl;
        system("pause");
        return;
    }

    Proveedor* proveedores = new Proveedor[cantProveedores];
    archivoProv.vectorizarArchivo(proveedores, cantProveedores);

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(articulos, cantArticulos);

    int* itemsTemp = new int[cantProveedores];
    for(int i = 0; i < cantProveedores; i++) {
        itemsTemp[i] = 0;
    }

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
                int cantidad = item.getCantidad();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        int idProveedor = articulos[a].getIdProveedor();

                        for(int p = 0; p < cantProveedores; p++) {
                            if(proveedores[p].getId() == idProveedor) {
                                itemsTemp[p] += cantidad;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < cantProveedores - 1; i++) {
        for(int j = i + 1; j < cantProveedores; j++) {
            if(itemsTemp[j] > itemsTemp[i]) {
                int auxItems = itemsTemp[i];
                itemsTemp[i] = itemsTemp[j];
                itemsTemp[j] = auxItems;

                Proveedor auxProv = proveedores[i];
                proveedores[i] = proveedores[j];
                proveedores[j] = auxProv;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "CANTIDAD ITEMS" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantProveedores && mostrados < 3; i++) {
        if(proveedores[i].getEstado() && itemsTemp[i] > 0) {
            cout << left << setw(8) << proveedores[i].getId()
                 << setw(45) << proveedores[i].getNombre()
                 << right << setw(20) << itemsTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron compras en el ultimo mes." << endl;
    }

    delete[] proveedores;
    delete[] articulos;
    delete[] itemsTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ProveedoresHistoricoItems() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 PROVEEDORES HISTORICO (CANTIDAD ITEMS)" << endl << endl;

    ArchivoProveedor archivoProv;
    int cantProveedores = archivoProv.contarArchivo();

    if(cantProveedores <= 0) {
        cout << "No hay proveedores registrados." << endl;
        system("pause");
        return;
    }

    Proveedor* proveedores = new Proveedor[cantProveedores];
    archivoProv.vectorizarArchivo(proveedores, cantProveedores);

    ArchivoArticulo archivoArt;
    int cantArticulos = archivoArt.contarArchivo();
    Articulo* articulos = new Articulo[cantArticulos];
    archivoArt.vectorizarArchivo(articulos, cantArticulos);

    int* itemsTemp = new int[cantProveedores];
    for(int i = 0; i < cantProveedores; i++) {
        itemsTemp[i] = 0;
    }

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
                int cantidad = item.getCantidad();

                for(int a = 0; a < cantArticulos; a++) {
                    if(articulos[a].getId() == idArticulo) {
                        int idProveedor = articulos[a].getIdProveedor();

                        for(int p = 0; p < cantProveedores; p++) {
                            if(proveedores[p].getId() == idProveedor) {
                                itemsTemp[p] += cantidad;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < cantProveedores - 1; i++) {
        for(int j = i + 1; j < cantProveedores; j++) {
            if(itemsTemp[j] > itemsTemp[i]) {
                int auxItems = itemsTemp[i];
                itemsTemp[i] = itemsTemp[j];
                itemsTemp[j] = auxItems;

                Proveedor auxProv = proveedores[i];
                proveedores[i] = proveedores[j];
                proveedores[j] = auxProv;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "CANTIDAD ITEMS" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantProveedores && mostrados < 3; i++) {
        if(proveedores[i].getEstado() && itemsTemp[i] > 0) {
            cout << left << setw(8) << proveedores[i].getId()
                 << setw(45) << proveedores[i].getNombre()
                 << right << setw(20) << itemsTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No hay proveedores con compras registradas." << endl;
    }

    delete[] proveedores;
    delete[] articulos;
    delete[] itemsTemp;
    cout << endl;
    system("pause");
}

#endif // REPORTESPROVEEDOR_H_INCLUDED
