#ifndef REPORTESVENDEDOR_H_INCLUDED
#define REPORTESVENDEDOR_H_INCLUDED

void reporteTop3VendedoresUltimoMesCantidad() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 MEJORES VENDEDORES ULTIMO MES (CANTIDAD VENTAS)" << endl << endl;

    ArchivoVendedor archivoVend;
    int cantVendedores = archivoVend.contarArchivo();

    if(cantVendedores <= 0) {
        cout << "No hay vendedores registrados." << endl;
        system("pause");
        return;
    }

    Vendedor* vendedores = new Vendedor[cantVendedores];
    archivoVend.vectorizarArchivo(vendedores, cantVendedores);

    int* ventasTemp = new int[cantVendedores];
    for(int i = 0; i < cantVendedores; i++) {
        ventasTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado() && estaEnUltimoMes(factura.getFecha())) {
            int idVendedor = factura.getIdVendedor();

            for(int v = 0; v < cantVendedores; v++) {
                if(vendedores[v].getId() == idVendedor) {
                    ventasTemp[v]++;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantVendedores - 1; i++) {
        for(int j = i + 1; j < cantVendedores; j++) {
            if(ventasTemp[j] > ventasTemp[i]) {
                int auxVentas = ventasTemp[i];
                ventasTemp[i] = ventasTemp[j];
                ventasTemp[j] = auxVentas;

                Vendedor auxVend = vendedores[i];
                vendedores[i] = vendedores[j];
                vendedores[j] = auxVend;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "CANT. VENTAS" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantVendedores && mostrados < 3; i++) {
        if(vendedores[i].getEstado() && ventasTemp[i] > 0) {
            cout << left << setw(8) << vendedores[i].getId()
                 << setw(45) << vendedores[i].getNombre()
                 << right << setw(20) << ventasTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron ventas en el ultimo mes." << endl;
    }

    delete[] vendedores;
    delete[] ventasTemp;
    cout << endl;
    system("pause");
}

void reporteTop3VendedoresHistoricoCantidad() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 MEJORES VENDEDORES HISTORICO (CANTIDAD VENTAS)" << endl << endl;

    ArchivoVendedor archivoVend;
    int cantVendedores = archivoVend.contarArchivo();

    if(cantVendedores <= 0) {
        cout << "No hay vendedores registrados." << endl;
        system("pause");
        return;
    }

    Vendedor* vendedores = new Vendedor[cantVendedores];
    archivoVend.vectorizarArchivo(vendedores, cantVendedores);

    int* ventasTemp = new int[cantVendedores];
    for(int i = 0; i < cantVendedores; i++) {
        ventasTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado()) {
            int idVendedor = factura.getIdVendedor();

            for(int v = 0; v < cantVendedores; v++) {
                if(vendedores[v].getId() == idVendedor) {
                    ventasTemp[v]++;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantVendedores - 1; i++) {
        for(int j = i + 1; j < cantVendedores; j++) {
            if(ventasTemp[j] > ventasTemp[i]) {
                int auxVentas = ventasTemp[i];
                ventasTemp[i] = ventasTemp[j];
                ventasTemp[j] = auxVentas;

                Vendedor auxVend = vendedores[i];
                vendedores[i] = vendedores[j];
                vendedores[j] = auxVend;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "CANT. VENTAS" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantVendedores && mostrados < 3; i++) {
        if(vendedores[i].getEstado() && ventasTemp[i] > 0) {
            cout << left << setw(8) << vendedores[i].getId()
                 << setw(45) << vendedores[i].getNombre()
                 << right << setw(20) << ventasTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No hay vendedores con ventas registradas." << endl;
    }

    delete[] vendedores;
    delete[] ventasTemp;
    cout << endl;
    system("pause");
}

void reporteTop3VendedoresUltimoMesDinero() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 MEJORES VENDEDORES ULTIMO MES (DINERO GENERADO)" << endl << endl;

    ArchivoVendedor archivoVend;
    int cantVendedores = archivoVend.contarArchivo();

    if(cantVendedores <= 0) {
        cout << "No hay vendedores registrados." << endl;
        system("pause");
        return;
    }

    Vendedor* vendedores = new Vendedor[cantVendedores];
    archivoVend.vectorizarArchivo(vendedores, cantVendedores);

    float* dineroTemp = new float[cantVendedores];
    for(int i = 0; i < cantVendedores; i++) {
        dineroTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado() && estaEnUltimoMes(factura.getFecha())) {
            int idVendedor = factura.getIdVendedor();

            for(int v = 0; v < cantVendedores; v++) {
                if(vendedores[v].getId() == idVendedor) {
                    dineroTemp[v] += factura.getImporteTotal();
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantVendedores - 1; i++) {
        for(int j = i + 1; j < cantVendedores; j++) {
            if(dineroTemp[j] > dineroTemp[i]) {
                float auxDinero = dineroTemp[i];
                dineroTemp[i] = dineroTemp[j];
                dineroTemp[j] = auxDinero;

                Vendedor auxVend = vendedores[i];
                vendedores[i] = vendedores[j];
                vendedores[j] = auxVend;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "DINERO GENERADO ($)" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantVendedores && mostrados < 3; i++) {
        if(vendedores[i].getEstado() && dineroTemp[i] > 0) {
            cout << left << setw(8) << vendedores[i].getId()
                 << setw(45) << vendedores[i].getNombre()
                 << right << setw(20) << dineroTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron ventas en el ultimo mes." << endl;
    }

    delete[] vendedores;
    delete[] dineroTemp;
    cout << endl;
    system("pause");
}

void reporteTop3VendedoresHistoricoDinero() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 MEJORES VENDEDORES HISTORICO (DINERO GENERADO)" << endl << endl;

    ArchivoVendedor archivoVend;
    int cantVendedores = archivoVend.contarArchivo();

    if(cantVendedores <= 0) {
        cout << "No hay vendedores registrados." << endl;
        system("pause");
        return;
    }

    Vendedor* vendedores = new Vendedor[cantVendedores];
    archivoVend.vectorizarArchivo(vendedores, cantVendedores);

    float* dineroTemp = new float[cantVendedores];
    for(int i = 0; i < cantVendedores; i++) {
        dineroTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado()) {
            int idVendedor = factura.getIdVendedor();

            for(int v = 0; v < cantVendedores; v++) {
                if(vendedores[v].getId() == idVendedor) {
                    dineroTemp[v] += factura.getImporteTotal();
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantVendedores - 1; i++) {
        for(int j = i + 1; j < cantVendedores; j++) {
            if(dineroTemp[j] > dineroTemp[i]) {
                float auxDinero = dineroTemp[i];
                dineroTemp[i] = dineroTemp[j];
                dineroTemp[j] = auxDinero;

                Vendedor auxVend = vendedores[i];
                vendedores[i] = vendedores[j];
                vendedores[j] = auxVend;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE"
         << right << setw(20) << "DINERO GENERADO ($)" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantVendedores && mostrados < 3; i++) {
        if(vendedores[i].getEstado() && dineroTemp[i] > 0) {
            cout << left << setw(8) << vendedores[i].getId()
                 << setw(45) << vendedores[i].getNombre()
                 << right << setw(20) << dineroTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No hay vendedores con ventas registradas." << endl;
    }

    delete[] vendedores;
    delete[] dineroTemp;
    cout << endl;
    system("pause");
}

#endif // REPORTESVENDEDOR_H_INCLUDED
