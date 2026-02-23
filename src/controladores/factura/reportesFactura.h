#ifndef REPORTESFACTURA_H_INCLUDED
#define REPORTESFACTURA_H_INCLUDED

void reporteTop3FacturasMayorDinero() {
    dibujarCuadro(1,1,92,3);
    gotoxy(20,2);
    cout << "TOP 3 FACTURAS QUE MAS DINERO DEJARON" << endl << endl;

    ArchivoFactura archivo;
    int cant = archivo.contarRegistros();

    if(cant <= 0) {
        cout << "No hay facturas registradas." << endl;
        system("pause");
        return;
    }

    Factura* facturas = new Factura[cant];
    for(int i = 0; i < cant; i++) {
        facturas[i] = archivo.leerRegistro(i);
    }

    int cantActivas = 0;
    for(int i = 0; i < cant; i++) {
        if(facturas[i].getEstado()) {
            cantActivas++;
        }
    }

    if(cantActivas == 0) {
        cout << "No hay facturas activas." << endl;
        delete[] facturas;
        system("pause");
        return;
    }

    for(int i = 0; i < cant - 1; i++) {
        for(int j = i + 1; j < cant; j++) {
            if(facturas[j].getImporteTotal() > facturas[i].getImporteTotal()) {
                Factura aux = facturas[i];
                facturas[i] = facturas[j];
                facturas[j] = aux;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << left << setw(12) << "FACTURA #"
         << setw(15) << "FECHA"
         << setw(25) << "CLIENTE"
         << setw(25) << "VENDEDOR"
         << right << setw(15) << "IMPORTE TOTAL" << endl;
    cout << setfill('-') << setw(92) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cant && mostrados < 3; i++) {
        if(facturas[i].getEstado()) {
            cout << left << setw(12) << facturas[i].getId()
                 << setw(15) << facturas[i].getFecha().toString()
                 << setw(25) << facturas[i].getNombreCliente()
                 << setw(25) << facturas[i].getNombreVendedor()
                 << right << setw(15) << facturas[i].getImporteTotal() << endl;
            mostrados++;
        }
    }

    delete[] facturas;
    cout << endl;
    system("pause");
}

void reporteTop3FacturasMasItems() {
    dibujarCuadro(1,1,92,3);
    gotoxy(20,2);
    cout << "TOP 3 FACTURAS CON MAS ITEMS VENDIDOS" << endl << endl;

    ArchivoFactura archivo;
    int cant = archivo.contarRegistros();

    if(cant <= 0) {
        cout << "No hay facturas registradas." << endl;
        system("pause");
        return;
    }

    Factura* facturas = new Factura[cant];
    int* cantidadItems = new int[cant];

    for(int i = 0; i < cant; i++) {
        facturas[i] = archivo.leerRegistro(i);
        int totalItems = 0;
        Detalle detalle = facturas[i].getDetalleVenta();
        for(int j = 0; j < detalle.getTamActual(); j++) {
            totalItems += detalle.getItem(j).getCantidad();
        }
        cantidadItems[i] = totalItems;
    }

    int cantActivas = 0;
    for(int i = 0; i < cant; i++) {
        if(facturas[i].getEstado()) {
            cantActivas++;
        }
    }

    if(cantActivas == 0) {
        cout << "No hay facturas activas." << endl;
        delete[] facturas;
        delete[] cantidadItems;
        system("pause");
        return;
    }

    for(int i = 0; i < cant - 1; i++) {
        for(int j = i + 1; j < cant; j++) {
            if(cantidadItems[j] > cantidadItems[i]) {
                int auxCant = cantidadItems[i];
                cantidadItems[i] = cantidadItems[j];
                cantidadItems[j] = auxCant;

                Factura auxFact = facturas[i];
                facturas[i] = facturas[j];
                facturas[j] = auxFact;
            }
        }
    }

    cout << left << setw(12) << "FACTURA #"
         << setw(15) << "FECHA"
         << setw(25) << "CLIENTE"
         << setw(25) << "VENDEDOR"
         << right << setw(15) << "CANT. ITEMS" << endl;
    cout << setfill('-') << setw(92) << "-" << setfill(' ') << endl;

    int mostrados = 0;
    for(int i = 0; i < cant && mostrados < 3; i++) {
        if(facturas[i].getEstado()) {
            cout << left << setw(12) << facturas[i].getId()
                 << setw(15) << facturas[i].getFecha().toString()
                 << setw(25) << facturas[i].getNombreCliente()
                 << setw(25) << facturas[i].getNombreVendedor()
                 << right << setw(15) << cantidadItems[i] << endl;
            mostrados++;
        }
    }

    delete[] facturas;
    delete[] cantidadItems;
    cout << endl;
    system("pause");
}

#endif // REPORTESFACTURA_H_INCLUDED
