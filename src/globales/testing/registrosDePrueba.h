#ifndef REGISTROSDEPRUEBA_H_INCLUDED
#define REGISTROSDEPRUEBA_H_INCLUDED

void cargarDatosDePrueba();
void borrarDatosActuales();

void borrarDatosActuales(){
    const char* archivos[] = {
        "../../data/articulos.dat",
        "../../data/clientes.dat",
        "../../data/contactos.dat",
        "../../data/proveedores.dat",
        "../../data/vendedores.dat",
        "../../data/facturas.dat"
    };

    int eliminados = 0;
    for(int i = 0; i < 6; i++){
        if(remove(archivos[i]) == 0){
            eliminados++;
        }
    }

    cout << endl;
    if(eliminados > 0){
        cout << "SE ELIMINARON " << eliminados << " ARCHIVO(S) DE DATOS." << endl;
    } else {
        cout << "NO SE ENCONTRARON ARCHIVOS DE DATOS PARA ELIMINAR." << endl;
    }
    cout << endl;
    system("pause");
}

void cargarDatosDePrueba(){

    ArchivoProveedor archivoProveedor;
    ArchivoCliente archivoCliente;
    ArchivoArticulo archivoArticulo;
    ArchivoVendedor archivoVendedor;
    ArchivoContacto archivoContacto;

    // =============================================
    // PROVEEDORES
    // =============================================

    const char* nombresProveedores[] = {"Distribuidora Norte", "Mayorista Sur", "Importadora Este", "Logistica Central", "Insumos Oeste", "Comercial Patagonia", "Suministros Litoral", "Fabrica Nacional", "Deposito Federal", "Materiales Centro"};
    const char* callesProveedores[] = {"Av. Mitre", "Belgrano", "San Martin", "Rivadavia", "Sarmiento", "Av. Corrientes", "Lavalle", "Tucuman", "Alsina", "Moreno"};
    int numerosProveedores[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    const char* localidadesProveedores[] = {"San Miguel", "Lomas", "Quilmes", "Moron", "Merlo", "Avellaneda", "Lanus", "Adrogue", "Temperley", "Berazategui"};
    int cpProveedores[] = {1663, 1832, 1878, 1708, 1722, 1870, 1824, 1846, 1834, 1884};

    int idsProveedores[10];

    for(int i = 0; i < 10; i++){
        Proveedor prov;
        int id = archivoProveedor.obtenerIdDisponible();
        idsProveedores[i] = id;

        Direccion dir;
        dir.setCalle(callesProveedores[i]);
        dir.setNumero(numerosProveedores[i]);
        dir.setLocalidad(localidadesProveedores[i]);
        dir.setCodigoPostal(cpProveedores[i]);
        dir.setProvincia("Buenos Aires");

        prov.setId(id);
        prov.setNombre(nombresProveedores[i]);
        prov.setDireccion(dir);
        prov.setCantidadCompras(0);
        prov.setCantidadUnidades(0);
        prov.setEstado(true);

        archivoProveedor.agregarProveedor(prov);
    }

    // =============================================
    // CONTACTOS DE PROVEEDORES
    // =============================================

    for(int i = 0; i < 10; i++){
        Contacto contacto;
        int idContacto = archivoContacto.obtenerIdDisponible();

        char nombreContacto[30];
        char telefono[20];
        char email[40];

        sprintf(nombreContacto, "Contacto Prov %d", i + 1);
        sprintf(telefono, "11%d%d%d%d0000", i+1, i+1, i+1, i+1);
        sprintf(email, "proveedor%d@test.com", i + 1);

        contacto.setIdContacto(idContacto);
        contacto.setIdEntidad(idsProveedores[i]);
        contacto.setTipoEntidad('P');
        contacto.setNombreContacto(nombreContacto);
        contacto.setNroTelefono(telefono);
        contacto.setEmail(email);
        contacto.setEstado(true);

        archivoContacto.escribirArchivo(contacto);
    }

    // =============================================
    // CLIENTES
    // =============================================

    const char* nombresClientes[] = {"Juan Perez", "Maria Garcia", "Carlos Lopez", "Ana Martinez", "Pedro Gomez", "Lucia Fernandez", "Roberto Sanchez", "Valentina Torres", "Fernando Diaz", "Camila Ruiz"};
    const char* cuitsClientes[] = {"20123456781", "27234567892", "20345678903", "27456789014", "20567890125", "27678901236", "20789012347", "27890123458", "20901234569", "27012345670"};
    int tiposClientes[] = {4, 2, 1, 4, 3, 1, 3, 2, 4, 1};
    int comprasClientes[] = {2, 3, 2, 1, 1, 3, 1, 2, 2, 1};
    const char* callesClientes[] = {"Av. Libertador", "Corrientes", "Santa Fe", "Cordoba", "Mendoza", "Belgrano", "Jujuy", "Entre Rios", "Callao", "Pueyrredon"};
    int numerosClientes[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    const char* localidadesClientes[] = {"CABA", "CABA", "Rosario", "Cordoba", "Mendoza", "La Plata", "Tucuman", "Salta", "CABA", "Mar del Plata"};
    int cpClientes[] = {1001, 1002, 2000, 5000, 5500, 1900, 4000, 4400, 1003, 7600};
    const char* provinciasClientes[] = {"Buenos Aires", "Buenos Aires", "Santa Fe", "Cordoba", "Mendoza", "Buenos Aires", "Tucuman", "Salta", "Buenos Aires", "Buenos Aires"};

    int idsClientes[10];

    for(int i = 0; i < 10; i++){
        Cliente cli;
        int id = archivoCliente.obtenerIdDisponible();
        idsClientes[i] = id;

        Direccion dir;
        dir.setCalle(callesClientes[i]);
        dir.setNumero(numerosClientes[i]);
        dir.setLocalidad(localidadesClientes[i]);
        dir.setCodigoPostal(cpClientes[i]);
        dir.setProvincia(provinciasClientes[i]);

        cli.setId(id);
        cli.setNombre(nombresClientes[i]);
        cli.setCuit(cuitsClientes[i]);
        cli.setTipo(tiposClientes[i]);
        cli.setDireccion(dir);
        cli.setcantidadVentas(comprasClientes[i]);
        cli.setRecaudacion(0);
        cli.setEstado(true);

        archivoCliente.agregarCliente(cli);
    }

    // =============================================
    // CONTACTOS DE CLIENTES
    // =============================================

    for(int i = 0; i < 10; i++){
        Contacto contacto;
        int idContacto = archivoContacto.obtenerIdDisponible();

        char nombreContacto[30];
        char telefono[20];
        char email[40];

        sprintf(nombreContacto, "Contacto Cli %d", i + 1);
        sprintf(telefono, "11%d%d%d%d1111", i+1, i+1, i+1, i+1);
        sprintf(email, "cliente%d@test.com", i + 1);

        contacto.setIdContacto(idContacto);
        contacto.setIdEntidad(idsClientes[i]);
        contacto.setTipoEntidad('C');
        contacto.setNombreContacto(nombreContacto);
        contacto.setNroTelefono(telefono);
        contacto.setEmail(email);
        contacto.setEstado(true);

        archivoContacto.escribirArchivo(contacto);
    }

    // =============================================
    // ARTICULOS
    // =============================================

    const char* descripcionesArticulos[] = {"Articulo 1", "Articulo 2", "Articulo 3", "Articulo 4", "Articulo 5", "Articulo 6", "Articulo 7", "Articulo 8", "Articulo 9", "Articulo 10"};
    int unidadesArticulos[] = {100, 50, 75, 60, 200, 120, 80, 45, 90, 150};
    float costosArticulos[] = {2500, 8000, 3500, 5000, 1500, 4200, 6500, 9000, 1800, 3200};
    int gananciasArticulos[] = {30, 40, 50, 35, 45, 25, 55, 30, 40, 35};

    int idsArticulos[10];

    for(int i = 0; i < 10; i++){
        Articulo art;
        int id = archivoArticulo.obtenerIdDisponible();
        idsArticulos[i] = id;

        art.setId(id);
        art.setDescripcion(descripcionesArticulos[i]);
        art.setUnidades(unidadesArticulos[i]);
        art.setCosto(costosArticulos[i]);
        art.setGanancia(gananciasArticulos[i]);
        art.setIdProveedor(idsProveedores[i]);
        art.setEstado(true);

        Fecha fechaHoy;
        art.setUltimaActualizacionPrecio(fechaHoy);

        archivoArticulo.agregarArticulo(art);
    }

    // =============================================
    // VENDEDORES
    // =============================================

    const char* nombresVendedores[] = {"Roberto Silva", "Laura Fernandez", "Diego Torres", "Sofia Ruiz", "Martin Diaz", "Carolina Mendez", "Alejandro Paz", "Natalia Vargas", "Gonzalo Castro", "Valentina Herrera"};
    int dnisVendedores[] = {30111222, 31222333, 32333444, 33444555, 34555666, 35666777, 36777888, 37888999, 38999000, 39000111};
    int cargosVendedores[] = {1, 1, 2, 1, 3, 2, 1, 1, 3, 1};
    int sueldosVendedores[] = {350000, 350000, 450000, 350000, 550000, 450000, 350000, 350000, 550000, 350000};

    int diasIngreso[] = {15, 20, 10, 1, 5, 12, 8, 25, 3, 18};
    int mesesIngreso[] = {3, 6, 1, 9, 4, 7, 2, 10, 5, 11};
    int aniosIngreso[] = {2020, 2021, 2018, 2022, 2015, 2019, 2023, 2017, 2021, 2020};

    int diasNac[] = {10, 22, 5, 14, 30, 18, 7, 25, 12, 3};
    int mesesNac[] = {5, 8, 11, 2, 7, 4, 10, 1, 6, 9};
    int aniosNac[] = {1990, 1992, 1985, 1995, 1980, 1988, 1994, 1987, 1993, 1982};

    const char* callesVendedores[] = {"Av. Maipu", "Las Heras", "Pueyrredon", "Alvear", "Callao", "Arenales", "Junin", "Ayacucho", "Laprida", "Billinghurst"};
    int numerosVendedores[] = {150, 250, 350, 450, 550, 650, 750, 850, 950, 1050};

    int idsVendedores[10];

    for(int i = 0; i < 10; i++){
        Vendedor vend;
        int id = archivoVendedor.obtenerIdDisponible();
        idsVendedores[i] = id;

        Direccion dir;
        dir.setCalle(callesVendedores[i]);
        dir.setNumero(numerosVendedores[i]);
        dir.setLocalidad("CABA");
        dir.setCodigoPostal(1001);
        dir.setProvincia("Buenos Aires");

        Fecha fechaIngreso(diasIngreso[i], mesesIngreso[i], aniosIngreso[i]);
        Fecha fechaNac(diasNac[i], mesesNac[i], aniosNac[i]);

        vend.setId(id);
        vend.setNombre(nombresVendedores[i]);
        vend.setDni(dnisVendedores[i]);
        vend.setCargo(cargosVendedores[i]);
        vend.setSueldo(sueldosVendedores[i]);
        vend.setventasRealizadas(0);
        vend.setfechaIngreso(fechaIngreso);
        vend.setFechaNacimiento(fechaNac);
        vend.setDireccion(dir);
        vend.setEstado(true);

        archivoVendedor.escribirArchivo(vend);
    }

    // =============================================
    // FACTURAS
    // =============================================

    ArchivoFactura archivoFactura;

    // INDICES SOBRE LOS ARRAYS (0-BASED) PARA CADA UNA DE LAS 18 FACTURAS
    int factCliente[]    = {0, 1, 2, 3, 4, 0, 1, 2, 1,   5, 6, 7, 8, 9, 5, 6, 7, 8};
    int factVendedor[]   = {0, 1, 0, 2, 3, 4, 2, 1, 4,   5, 6, 7, 8, 9, 5, 6, 7, 9};
    int factTipoCompra[] = {1, 1, 2, 1, 1, 2, 1, 1, 2,   1, 1, 2, 1, 1, 2, 1, 1, 2};
    const char* factCondPago[] = {"Efectivo", "Efectivo", "30 dias", "Efectivo", "Efectivo", "30 dias", "Efectivo", "Efectivo", "30 dias", "Efectivo", "Efectivo", "30 dias", "Efectivo", "Efectivo", "30 dias", "Efectivo", "Efectivo", "30 dias"};

    // ARTICULOS POR FACTURA (INDICE 0-BASED SOBRE IDSARTICULOS, -1 = SIN SEGUNDO ARTICULO)
    int factArt1[]  = {0, 1, 2, 3, 0, 1, 4, 0, 1,   5, 6, 7, 8, 9, 5, 6, 7, 9};
    int factCant1[] = {2, 1, 3, 1, 5, 2, 4, 1, 3,   3, 2, 1, 4, 2, 5, 1, 3, 2};
    int factArt2[]  = {-1, -1, -1, 4, -1, 2, -1, 3, -1,   -1, -1, 8, -1, 5, -1, 9, -1, -1};
    int factCant2[] = {0,  0,  0, 2,  0, 1,  0, 2,  0,    0,  0, 2,  0, 3,  0, 1,  0,  0};

    // FECHAS DISTRIBUIDAS DESDE NOVIEMBRE 2025 HASTA ABRIL 2026
    int factDia[]  = { 5, 12, 20, 28,  5, 13, 22,  3, 15,   2, 10, 18, 25,  4, 14, 21,  1, 12};
    int factMes[]  = {11, 11, 11, 11, 12, 12, 12,  1,  1,   2,  2,  2,  2,  3,  3,  3,  4,  4};
    int factAnio[] = {2025, 2025, 2025, 2025, 2025, 2025, 2025, 2026, 2026, 2026, 2026, 2026, 2026, 2026, 2026, 2026, 2026, 2026};

    for(int i = 0; i < 18; i++){
        Factura fact;
        int idFactura = archivoFactura.obtenerIdDisponible();
        int ci = factCliente[i];
        int vi = factVendedor[i];

        fact.setId(idFactura);
        fact.setIdCliente(idsClientes[ci]);
        fact.setCuitCliente(cuitsClientes[ci]);
        fact.setTipoCliente(tiposClientes[ci]);
        fact.setNombreCliente(nombresClientes[ci]);

        Direccion dirCli;
        dirCli.setCalle(callesClientes[ci]);
        dirCli.setNumero(numerosClientes[ci]);
        dirCli.setLocalidad(localidadesClientes[ci]);
        dirCli.setCodigoPostal(cpClientes[ci]);
        dirCli.setProvincia(provinciasClientes[ci]);
        fact.setDireccion(dirCli);

        fact.setIdVendedor(idsVendedores[vi]);
        fact.setNombreVendedor(nombresVendedores[vi]);

        fact.setTipoCompra(factTipoCompra[i]);
        fact.setCondicionPago(factCondPago[i]);

        Detalle detalle;

        Articulo art1 = archivoArticulo.traerArticulo(idsArticulos[factArt1[i]]);
        Item item1(art1, factCant1[i], tiposClientes[ci]);
        item1.setNroItem(1);
        detalle.agregarItem(item1);

        if(factArt2[i] >= 0){
            Articulo art2 = archivoArticulo.traerArticulo(idsArticulos[factArt2[i]]);
            Item item2(art2, factCant2[i], tiposClientes[ci]);
            item2.setNroItem(2);
            detalle.agregarItem(item2);
        }

        fact.setDetalleVenta(detalle);
        fact.calcularImportes();
        fact.setFecha(Fecha(factDia[i], factMes[i], factAnio[i]));
        fact.setEstado(true);

        archivoFactura.agregarRegistro(fact);
    }

    cout << endl;
    cout << "SE CARGARON EXITOSAMENTE LOS DATOS DE PRUEBA:" << endl;
    cout << "- 10 Proveedores con 10 contactos" << endl;
    cout << "- 10 Clientes con 10 contactos" << endl;
    cout << "- 10 Articulos" << endl;
    cout << "- 10 Vendedores" << endl;
    cout << "- 18 Facturas" << endl;
    cout << endl;
    system("pause");
}

#endif // REGISTROSDEPRUEBA_H_INCLUDED
