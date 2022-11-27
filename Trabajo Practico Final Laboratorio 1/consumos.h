#ifndef CONSUMOS_H_INCLUDED
#define CONSUMOS_H_INCLUDED

typedef struct
{
    int id;
    int idCliente;
    int anio;
    int mes;
    int dia;
    int datosConsumidos;
    int baja;
} stConsumos;
stConsumos cargaUnConsumoAnioActual();
void cargaArchivoConsumosRandom(char nombreArchivoConsumos[], char nombreArchivoClientes[]);
stConsumos cargaUnConsumo(char nombreArchivo[]);
int ultimoIdConsumo(char nombreArchivo[]);
int funcionAcumulador(char nombreArchivo[]);
stConsumos seleccionaUnaFecha();
void muestraUnConsumo(stConsumos a);
void muestraArregloConsumos(stConsumos c[], int v);
void muestraArchivoConsumos(char nombreArchivo[]);
int buscaMenorPosicionCliente (stConsumos c[], int val, int pos);
int buscaMenorPosicionFecha (stConsumos c[], int val, int pos);
void ordenarConsumosPorIdConsumo(stConsumos c[], int v);
void ordenarConsumosPorFecha(stConsumos c[], int v);
void intercambioStConsumo(stConsumos *a, stConsumos *b);
int pasarArchivo2ArregloConsumos(char nombreArchivo[], stConsumos c[], int dim);
stConsumos busquedaConsumo();
void bajaConsumo(char nombreArchivo[]);
void altaConsumoInactivo(char nombreArchivo[]);
void modificacionDeConsumo(char nombreArchivo[]);
void cargaArchivoConsumosFinal(char nombreArchivoConsumos[], char nombreArchivoClientes[]);
int comprobarConsumo2(char nombreArchivo[], stConsumos a);
int obtenerConsumo(char nombreArchivo [], stConsumos a);
int obtenerIdConsumo(char nombreArchivo [], stConsumos a);
int buscarPosID(char nombreArchivo[], stConsumos b);
int busquedaID(char nombreArchivo[]);
stCliente busquedaClientesParaConsumos(char nombreArchivo[]);
int comprobacionDniParaConsumoCliente(char nombreArchivo [], char dni[]);
stConsumos seleccionMes();
int funcionAcumuladorXMes(char nombreArchivo[],char nombreArchivoC [],int idCliente,int mes);
stCliente busquedaClienteXDni(char nombreArchivo[]);
int posComprobacion(char nombreArchivo [], char dni[]);
void mostrarFactura(char nombreArchivoConsumo[], char nombreArchivoCliente[]);

#endif // CONSUMOS_H_INCLUDED
