#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int idCliente;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[50];
    char domicilio[45];
    char movil [12];
    int eliminado;
} stCliente;
int buscaMenorPosicionNroCliente (stCliente c[], int val, int pos);
int buscarMenorPosicionPorApellido (stCliente ape[], int val, int pos);
int busquedaDNI(char nombreArchivo[]);
int comprobacionDni(char nombreArchivo [], char dni[]);
int pasarArchivo2ArregloClientes(char nombreArchivo[], stCliente c[], int dim);
int ultimoIdCliente(char nombreArchivo[]);
stCliente busquedaClientes();
stCliente cargaUnCliente();
void altaClienteInactivo(char nombreArchivo[]);
void bajaDeCliente(char nombreArchivo[]);
void cambioDeTitularidad(char nombreArchivo[]);
void cargaArchivoCliente(char nombreArchivo[]);
void intercambioStCliente(stCliente *a, stCliente *b);
void modificacionApellidoCliente(char nombreArchivo[]);
void modificacionDniCliente(char nombreArchivo[]);
void modificacionDomicilioCliente(char nombreArchivo[]);
void modificacionEmailCliente(char nombreArchivo[]);
void modificacionNombreCliente(char nombreArchivo[]);
void modificacionNumMovilCliente(char nombreArchivo[]);
void muestraArchivoClientes(char nombreArchivo[]);
void muestraArregloClientes(stCliente c[], int v);
void muestraUnCliente(stCliente a);
void ordearAgendaNroCliente (stCliente c[], int v);
void ordearAgendaPorApellido (stCliente a[], int val);

#endif // CLIENTES_H_INCLUDED
