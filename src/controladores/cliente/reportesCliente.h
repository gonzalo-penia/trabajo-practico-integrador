#ifndef REPORTESCLIENTE_H_INCLUDED
#define REPORTESCLIENTE_H_INCLUDED

void reporteTop3ClientesUltimoMesCantidad() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 MEJORES CLIENTES ULTIMO MES (CANTIDAD COMPRAS)" << endl << endl;
    cout << "CLIENTES QUE MAS COMPRAS REALIZARON DURANTE EL ULTIMO MES" << endl << endl;

    ArchivoCliente archivoCli;
    int cantClientes = archivoCli.contarArchivo();

    if(cantClientes <= 0) {
        cout << "No hay clientes registrados." << endl;
        system("pause");
        return;
    }

    Cliente* clientes = new Cliente[cantClientes];
    archivoCli.vectorizarArchivo(clientes, cantClientes);

    int* comprasTemp = new int[cantClientes];
    for(int i = 0; i < cantClientes; i++) {
        comprasTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado() && estaEnUltimoMes(factura.getFecha())) {
            int idCliente = factura.getIdCliente();

            for(int c = 0; c < cantClientes; c++) {
                if(clientes[c].getId() == idCliente) {
                    comprasTemp[c]++;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantClientes - 1; i++) {
        for(int j = i + 1; j < cantClientes; j++) {
            if(comprasTemp[j] > comprasTemp[i]) {
                int auxCompras = comprasTemp[i];
                comprasTemp[i] = comprasTemp[j];
                comprasTemp[j] = auxCompras;

                Cliente auxCli = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCli;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE/RAZON SOCIAL"
         << right << setw(20) << "CANT. COMPRAS" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantClientes && mostrados < 3; i++) {
        if(clientes[i].getEstado() && comprasTemp[i] > 0) {
            cout << left << setw(8) << clientes[i].getId()
                 << setw(45) << clientes[i].getNombre()
                 << right << setw(20) << comprasTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron compras en el ultimo mes." << endl;
    }

    delete[] clientes;
    delete[] comprasTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ClientesHistoricoCantidad() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 MEJORES CLIENTES HISTORICO (CANTIDAD COMPRAS)" << endl << endl;
    cout << "CLIENTES QUE MAS COMPRAS REALIZARON DURANTE TODO EL HISTORICO" << endl << endl;

    ArchivoCliente archivoCli;
    int cantClientes = archivoCli.contarArchivo();

    if(cantClientes <= 0) {
        cout << "No hay clientes registrados." << endl;
        system("pause");
        return;
    }

    Cliente* clientes = new Cliente[cantClientes];
    archivoCli.vectorizarArchivo(clientes, cantClientes);

    int* comprasTemp = new int[cantClientes];
    for(int i = 0; i < cantClientes; i++) {
        comprasTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado()) {
            int idCliente = factura.getIdCliente();

            for(int c = 0; c < cantClientes; c++) {
                if(clientes[c].getId() == idCliente) {
                    comprasTemp[c]++;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantClientes - 1; i++) {
        for(int j = i + 1; j < cantClientes; j++) {
            if(comprasTemp[j] > comprasTemp[i]) {
                int auxCompras = comprasTemp[i];
                comprasTemp[i] = comprasTemp[j];
                comprasTemp[j] = auxCompras;

                Cliente auxCli = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCli;
            }
        }
    }

    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE/RAZON SOCIAL"
         << right << setw(20) << "CANT. COMPRAS" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantClientes && mostrados < 3; i++) {
        if(clientes[i].getEstado() && comprasTemp[i] > 0) {
            cout << left << setw(8) << clientes[i].getId()
                 << setw(45) << clientes[i].getNombre()
                 << right << setw(20) << comprasTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No hay clientes con compras registradas." << endl;
    }

    delete[] clientes;
    delete[] comprasTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ClientesUltimoMesDinero() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "TOP 3 CLIENTES QUE MAS DINERO GASTARON DURANTE EL ULTIMO MES" << endl << endl;

    ArchivoCliente archivoCli;
    int cantClientes = archivoCli.contarArchivo();

    if(cantClientes <= 0) {
        cout << "No hay clientes registrados." << endl;
        system("pause");
        return;
    }

    Cliente* clientes = new Cliente[cantClientes];
    archivoCli.vectorizarArchivo(clientes, cantClientes);

    float* dineroTemp = new float[cantClientes];
    for(int i = 0; i < cantClientes; i++) {
        dineroTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado() && estaEnUltimoMes(factura.getFecha())) {
            int idCliente = factura.getIdCliente();

            for(int c = 0; c < cantClientes; c++) {
                if(clientes[c].getId() == idCliente) {
                    dineroTemp[c] += factura.getImporteTotal();
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantClientes - 1; i++) {
        for(int j = i + 1; j < cantClientes; j++) {
            if(dineroTemp[j] > dineroTemp[i]) {
                float auxDinero = dineroTemp[i];
                dineroTemp[i] = dineroTemp[j];
                dineroTemp[j] = auxDinero;

                Cliente auxCli = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCli;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE/RAZON SOCIAL"
         << right << setw(20) << "DINERO GASTADO ($)" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantClientes && mostrados < 3; i++) {
        if(clientes[i].getEstado() && dineroTemp[i] > 0) {
            cout << left << setw(8) << clientes[i].getId()
                 << setw(45) << clientes[i].getNombre()
                 << right << setw(20) << dineroTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No se registraron compras en el ultimo mes." << endl;
    }

    delete[] clientes;
    delete[] dineroTemp;
    cout << endl;
    system("pause");
}

void reporteTop3ClientesHistoricoDinero() {
    dibujarCuadro(1,1,77,3);
    gotoxy(10,2);
    cout << "CLIENTES QUE MAS DINERO GASTARON DURANTE TODO EL HISTORICO" << endl << endl;

    ArchivoCliente archivoCli;
    int cantClientes = archivoCli.contarArchivo();

    if(cantClientes <= 0) {
        cout << "No hay clientes registrados." << endl;
        system("pause");
        return;
    }

    Cliente* clientes = new Cliente[cantClientes];
    archivoCli.vectorizarArchivo(clientes, cantClientes);

    float* dineroTemp = new float[cantClientes];
    for(int i = 0; i < cantClientes; i++) {
        dineroTemp[i] = 0;
    }

    ArchivoFactura archivoFact;
    int cantFacturas = archivoFact.contarRegistros();

    for(int f = 0; f < cantFacturas; f++) {
        Factura factura = archivoFact.leerRegistro(f);

        if(factura.getEstado()) {
            int idCliente = factura.getIdCliente();

            for(int c = 0; c < cantClientes; c++) {
                if(clientes[c].getId() == idCliente) {
                    dineroTemp[c] += factura.getImporteTotal();
                    break;
                }
            }
        }
    }

    for(int i = 0; i < cantClientes - 1; i++) {
        for(int j = i + 1; j < cantClientes; j++) {
            if(dineroTemp[j] > dineroTemp[i]) {
                float auxDinero = dineroTemp[i];
                dineroTemp[i] = dineroTemp[j];
                dineroTemp[j] = auxDinero;

                Cliente auxCli = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = auxCli;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << left << setw(8) << "ID"
         << setw(45) << "NOMBRE/RAZON SOCIAL"
         << right << setw(20) << "DINERO GASTADO ($)" << endl;
    cout << setfill('-') << setw(73) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cantClientes && mostrados < 3; i++) {
        if(clientes[i].getEstado() && dineroTemp[i] > 0) {
            cout << left << setw(8) << clientes[i].getId()
                 << setw(45) << clientes[i].getNombre()
                 << right << setw(20) << dineroTemp[i] << endl;
            mostrados++;
        }
    }

    if(mostrados == 0) {
        cout << "No hay clientes con compras registradas." << endl;
    }

    delete[] clientes;
    delete[] dineroTemp;
    cout << endl;
    system("pause");
}

#endif // REPORTESCLIENTE_H_INCLUDED
