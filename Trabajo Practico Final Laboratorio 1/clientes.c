#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "estetica.h"
#include "clientes.h"

#define CLIENTE"Clientes.dat"
#define CONSUMO"Consumo.dat"

stCliente cargaUnCliente()///FUNCION PARA LA CARGA INDIVIDUAL DE UN CLIENTE (RETORNA LA ESTRUCTURA)
{

    stCliente a;
    int existe = 1;
    printf("\nNumero del cliente: ");
    fflush(stdin);
    scanf("%d", &a.nroCliente);
    printf("Nombre del cliente: ");
    fflush(stdin);
    gets(a.nombre);
    printf("Apellido del cliente: ");
    fflush(stdin);
    gets(a.apellido);
    printf("Email del cliente: ");
    fflush(stdin);
    gets(a.email);
    printf("Domicilio del cliente: ");
    fflush(stdin);
    gets(a.domicilio);
    printf("Movil del cliente: ");
    fflush(stdin);
    gets(a.movil);
    printf("El usuario se encuentra activo? (0 por si, 1 por no): ");
    fflush(stdin);
    scanf("%d", &a.eliminado);
    system("cls");

    return a;
}
void muestraUnCliente(stCliente a)///FUNCION PARA LA MUESTRA INDIVIDUAL DE UN CLIENTE (RETORNA LA ESTRUCTURA)
{
    if(a.eliminado == 0)
    {
        color(15);
        printf("\n\t============== %10s ==============", a.apellido);
        printf("\n\t ID cliente:            %15d", a.idCliente);
        printf("\n\t Datos del Cliente N%c   %15d",248, a.nroCliente);
        printf("\n\t Apellido:         %20s", a.apellido);
        printf("\n\t Nombre:           %20s", a.nombre);
        printf("\n\t DNI:                   %15s", a.dni);
        printf("\n\t Email:  %30s", a.email);
        printf("\n\t Domicilio:        %20s", a.domicilio);
        printf("\n\t Movil:                 %15s", a.movil);
        printf("\n\t Activo:\t\t\t     Si\n");
        printf("\t========================================\n");
        color(15);
    }
    else
    {
        color(8);
        printf("\n\t============== %10s ==============", a.apellido);
        printf("\n\t ID cliente:            %15d", a.idCliente);
        printf("\n\t Datos del Cliente N%c   %15d",248, a.nroCliente);
        printf("\n\t Apellido:         %20s", a.apellido);
        printf("\n\t Nombre:           %20s", a.nombre);
        printf("\n\t DNI:                   %15s", a.dni);
        printf("\n\t Email:  %30s", a.email);
        printf("\n\t Domicilio:        %20s", a.domicilio);
        printf("\n\t Movil:                 %15s", a.movil);
        color(4);
        printf("\n\t Activo:\t\t\t     No\n");
        color(8);
        printf("\t========================================\n");
        color(15);
    }
}
void cargaArchivoCliente(char nombreArchivo[])///CARGA DE ARCHIVO DE CLIENTES CON VERIFICACION DE DNI
{
     stCliente a;

    static int i = 0;
    i = ultimoIdCliente(nombreArchivo);
    int existe = 1;
    char dni[50];
    char opcion = 0;
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi)
    {
        printf("\nVerifiquemos que el dni no exista en la base de datos\n");
        do
        {
            while(existe == 1){
            printf("\nIngrese un DNI: ");

            gets(dni);

            existe = comprobacionDni(nombreArchivo, dni);

            if(existe == 1){
                printf("\nEl cliente ya existe, ingrese otro dni\n");
            }else{
                printf("\nNo se ha encontrado al cliente, prosiga con la carga\n");
                }
            }
            a = cargaUnCliente();
            i++;
            strcpy(a.dni,dni);
            a.idCliente = i;
            fwrite(&a, sizeof(stCliente), 1, archi);
            existe =1;
            fclose(archi);
            printf("\nDesea seguir cargando clientes? ESC PARA SALIR: ");
            opcion = getch();
            FILE *archi = fopen(nombreArchivo, "ab");
            fflush(stdin);

        }while(opcion != 27);

    fclose(archi);
    }
}
void muestraArchivoClientes(char nombreArchivo[])///MUESTRA LISTADO DE ARCHIVO DE CLIENTES
{
    FILE *archi = fopen(nombreArchivo,"rb");
    stCliente a;
    if(archi)
    {
        while(fread(&a, sizeof(stCliente),1,archi)>0)
        {
            muestraUnCliente(a);
        }
    }
    fclose(archi);
}
stCliente busquedaClientes()///FUNCION PARA LA BUSQUEDA DE UN CLIENTE MEDIANTE DNI (RETORNA LA ESTRUCTURA)
{
    stCliente b;

   printf("\nDNI del cliente: ");
    fflush(stdin);
    gets(b.dni);

    return b;
}
void bajaDeCliente(char nombreArchivo[])///FUNCION PARA DAR DE BAJA UN CLIENTE ACTIVO
{
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                fseek(archi, -1*sizeof(stCliente), 1);
                a.eliminado = 1;
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void altaClienteInactivo(char nombreArchivo[])///FUNCION PARA DAR EL ALTA DE UN CLIENTE INACTIVO QUE SE HABIA DADO DE BAJA
{
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;

    FILE*archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                fseek(archi, -1*sizeof(stCliente), 1);
                a.eliminado = 0;
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void cambioDeTitularidad(char nombreArchivo[])///FUNCION PARA REALIZAR UN CAMBIO DE TITULARIDAD ,(MODIFICACION DE TODOS LOS DATOS EXCEPTO EL NUMERO DE MOVIL)
{
    printf("\nElija el cliente para hacer el cambio de titularidad\n");
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;
    char dni[50];
    int existe = 1;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                while(existe == 1)
                {
                    printf("\nIngrese el nuevo DNI: ");

                    gets(dni);

                    existe = comprobacionDni(nombreArchivo, dni);

                    if(existe == 1)
                    {
                        printf("\nEl cliente ya existe, ingrese otro dni\n");
                    }
                    else
                    {
                        printf("\nNo se ha encontrado al cliente, prosiga con la carga\n");
                    }
                }

                printf("\nNombre actual: %s\n", a.nombre);
                fseek(archi, -1*sizeof(stCliente), 1);
                printf("\nIngrese el nuevo nombre: ");
                fflush(stdin);
                gets(a.nombre);
                printf("\nApellido actual: %s\n", a.apellido);
                printf("\nIngrese el nuevo apellido: ");
                fflush(stdin);
                gets(a.apellido);
                printf("\nEmail actual: %s\n", a.email);
                printf("\nIngrese el nuevo Email: ");
                fflush(stdin);
                gets(a.email);
                printf("\nDomicilio actual: %s\n", a.domicilio);
                printf("\nIngrese el nuevo Domicilio: ");
                fflush(stdin);
                gets(a.domicilio);
                printf("\nNumero Movil actual: %s\n", a.movil);
                strcpy(a.dni, dni);
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
int comprobacionDni(char nombreArchivo [], char dni[])///FUNCION PARA LA COMPARACION DE DNI CON UNO EXISTENTE, RECIBIENDO EL DNI POR PARAMETRO (RETORNA UNA BANDERA)
{
    stCliente a;
    int flag = 0;
    FILE *archi = fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, dni) == 0)
            {
                flag=1;
            }
        }
        fclose(archi);
            }
    return flag;
}
void modificacionNombreCliente(char nombreArchivo[])///FUNCION PARA LA MODIFICACION DEL NOMBRE DE UN CLIENTE
{
    printf("\nElija el cliente al que quiera modificar el nombre\n");
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                printf("\nNombre actual: %s", a.nombre);
                fseek(archi, -1*sizeof(stCliente), 1);
                printf("\nIngrese el nuevo nombre: ");
                fflush(stdin);
                gets(a.nombre);
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void modificacionApellidoCliente(char nombreArchivo[])///FUNCION PARA LA MODIFICACION DEL APELLIDO DE UN CLIENTE
{
    printf("\nElija el cliente al que quiera modificar el apellido\n");
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                printf("\nApellido actual: %s", a.apellido);
                fseek(archi, -1*sizeof(stCliente), 1);
                printf("\nIngrese el nuevo apellido: ");
                fflush(stdin);
                gets(a.apellido);
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void modificacionDniCliente(char nombreArchivo[])///FUNCION PARA LA MODIFICACION DEL DNI DE UN CLIENTE
{
    printf("\nElija el cliente para hacer el cambio de D.N.I.\n");
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;
    char dni[50];
    int existe = 1;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                while(existe == 1)
                {
                    printf("\nIngrese el nuevo DNI: ");
                    gets(dni);
                    existe = comprobacionDni(nombreArchivo, dni);

                    if(existe == 1)
                    {
                        printf("\nEl cliente ya existe, ingrese otro dni\n");
                    }

                    fseek(archi, -1*sizeof(stCliente), 1);
                    strcpy(a.dni, dni);muestraUnCliente(a);
                    fwrite(&a, sizeof(stCliente), 1, archi);
                    flag++;

                }
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }

}
void modificacionEmailCliente(char nombreArchivo[])///FUNCION PARA LA MODIFICACION DEL EMAIL DE UN CLIENTE
{
    printf("\nElija el cliente al que quiera modificar el Email\n");
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                printf("\nEmail actual: %s", a.email);
                fseek(archi, -1*sizeof(stCliente), 1);
                printf("\nIngrese el nuevo Email: ");
                fflush(stdin);
                gets(a.email);
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void modificacionDomicilioCliente(char nombreArchivo[])///FUNCION PARA LA MODIFICACION DEL DOMICILIO DE UN CLIENTE
{
    printf("\nElija el cliente al que quiera modificar el Domicilio\n");
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                printf("\nDomicilio actual: %s", a.domicilio);
                fseek(archi, -1*sizeof(stCliente), 1);
                printf("\nIngrese el nuevo Domicilio: ");
                fflush(stdin);
                gets(a.domicilio);
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void modificacionNumMovilCliente(char nombreArchivo[])///FUNCION PARA LA MODIFICACION DEL NUMERO MOVIL DE UN CLIENTE
{
    printf("\nElija el cliente al que quiera modificar el Numero Movil\n");
    stCliente b = busquedaClientes();
    stCliente a;
    int flag = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente), 1, archi) > 0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                printf("\nNumero Movil actual: %s", a.movil);
                fseek(archi, -1*sizeof(stCliente), 1);
                printf("\nIngrese el nuevo Numero Movil: ");
                fflush(stdin);
                gets(a.movil);
                fwrite(&a, sizeof(stCliente), 1, archi);
                flag++;
                muestraUnCliente(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
int pasarArchivo2ArregloClientes(char nombreArchivo[], stCliente c[], int dim)///FUNCION DE PASAJE DE DATOS DE UN ARCHIVO A UN ARREGLO
{
        FILE *archi = fopen(nombreArchivo, "rb");

    int i=0;
    stCliente aux;
    if(archi)
    {
        while(i<dim && fread(&aux, sizeof(stCliente), 1, archi) > 0)
        {
            c[i]=aux;
            i++;
        }

        fclose(archi);
    }
    return i;
}
int buscarMenorPosicionPorApellido (stCliente ape[], int val, int pos)///BUSQUEDA DE MENOR POSICION POR ORDEN DE APELLIDO (RETORNA MENOR POSICION)
{
    int menorPocicion=pos;
    int resultado;
    pos++;
    while (pos<val)
    {
        resultado=strcmpi(ape[menorPocicion].apellido, ape[pos].apellido);
        if (resultado>0)
        {
            menorPocicion=pos;
        }
        pos++;
    }

    return menorPocicion;
}
void ordearAgendaPorApellido (stCliente a[], int val)///ORDENA LISTA DE CLIENTES ALFABEICAMENTE POR APELLIDO
{
    int i=0;
    int posicion;
    stCliente aux;
    while(i<val)
    {
        posicion=buscarMenorPosicionPorApellido(a, val, i);
        intercambioStCliente(&a[i], &a[posicion]);

        i++;
    }
}
int buscaMenorPosicionNroCliente (stCliente c[], int val, int pos)///BUSCA LA MENOR POSICION POR NUMERO DE CLIENTE (RETORNA LA MENOR POSICION)
{
    int menorPosicion = pos;
    pos++;
        while (pos<val){
                 if (c[menorPosicion].nroCliente > c[pos].nroCliente){
                menorPosicion=pos;
            }
            pos ++;
        }
return menorPosicion;
}
void ordearAgendaNroCliente (stCliente c[], int v)///ORDENA LISTA DE CLIENTES POR NUMERO DE CLIENTE
{
    int i=0;
    int posMenor;
    stCliente aux;
        while (i<v-1){
            posMenor=buscaMenorPosicionNroCliente(c, v, i);
            intercambioStCliente(&c[i], &c[posMenor]);
            i++;
        }
}
void intercambioStCliente(stCliente *a, stCliente *b)///FUNCION DE INTERCAMBIO DE POSICION DE ESTRUCTURAS
{
    stCliente aux = *a;
    *a =*b;
    *b = aux;
}
void muestraArregloClientes(stCliente c[], int v)///MUESTRA LISTADO DE ARREGLO DE CLIENTES
{
    for(int i = 0; i<v; i++)
    {
        muestraUnCliente(c[i]);
    }
}
int busquedaDNI(char nombreArchivo[])///FUNCION PARA LA COMPARACION DE DNI CON UNO EXISTENTE (RETORNA UNA BANDERA)
{
    stCliente b = busquedaClientes();
    int flag = 0;
    stCliente a;

    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}
int ultimoIdCliente(char nombreArchivo[])///CONTADOR UNICO E INCREMENTAL DE ID DE CLIENTES (RETORNA EL ULTIMO ID)
{
    int id = 0;
    stCliente e;
    FILE *arch = fopen(nombreArchivo, "rb");
    if(arch)
    {
        fseek(arch, -1*sizeof(stCliente), SEEK_END);
        if(fread(&e, sizeof(stCliente), 1, arch)>0)
        {
            id = e.idCliente;
        }
        fclose(arch);
    }

    return id;
}


