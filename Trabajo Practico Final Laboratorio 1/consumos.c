#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "estetica.h"
#include "clientes.h"
#include "consumos.h"



#define PRECIOMB 0.32
#define MANTENIMIENTO 150

stConsumos cargaUnConsumoAnioActual()
{

    stConsumos a;
    time_t t =time(NULL);
    struct tm tiempoLocal = *localtime(&t);

    a.anio = tiempoLocal.tm_year + 1900;
    a.mes = rand()%(tiempoLocal.tm_mon+1) +1;
    if(a.mes == tiempoLocal.tm_mon+1)
    {
        a.dia = rand()%(tiempoLocal.tm_mday - 1) + 1;
    }
    else if(a.mes == 1)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 2 && (a.anio%4 == 0) )
    {
        a.dia = rand()%(29 - 1) + 1;
    }
    else if(a.mes == 2 && (a.anio%4 != 0))
    {
        a.dia = rand()%(28-1)+1;
    }
    else if(a.mes == 3)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 4)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 5)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 6)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 7)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 8)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 9)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 10)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    else if(a.mes == 11)
    {
        a.dia = rand()%(30 - 1) + 1;
    }
    else if(a.mes == 12)
    {
        a.dia = rand()%(31 - 1) + 1;
    }
    a.datosConsumidos = rand()%(2000-5)+5;
    a.baja = 0;
    return a;
}
void cargaArchivoConsumosRandom(char nombreArchivoConsumos[], char nombreArchivoClientes[])///CARGA ARCHIVO CONSUMOS RANDOM
{
    stConsumos a;
    stConsumos b;
    static int i = 0;
    i=ultimoIdConsumo(nombreArchivoConsumos);
    int iClientes = 0;
    int pos = 0;
    iClientes = ultimoIdCliente(nombreArchivoClientes);
    int flag = 0;
    int sumarDatos = 0;
    int idConsumo = 0;

    FILE *archi = fopen(nombreArchivoConsumos, "r+b");

    if(archi == NULL)
    {
        FILE *archi = fopen(nombreArchivoConsumos, "ab");
        fclose(archi);
        fopen(nombreArchivoConsumos, "r+b");
    }
    if(archi != NULL)
    {
        for(int j = 0; j <1000; j++)
        {
            a = cargaUnConsumoAnioActual();
            a.idCliente = rand()%iClientes+1;
            a.id = 0;
            while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
            {
                flag = comprobarConsumo2(nombreArchivoConsumos, a);
                if(flag == 1)
                {
                    pos =buscarPosID(nombreArchivoConsumos,a);
                    flag = 1;
                    sumarDatos = obtenerConsumo(nombreArchivoConsumos, a);
                    a.datosConsumidos = a.datosConsumidos + sumarDatos;
                    idConsumo = obtenerIdConsumo(nombreArchivoConsumos,a);
                    a.id = idConsumo;
                    fseek(archi,sizeof(stConsumos)*(pos-1),SEEK_SET);
                }
                else
                {
                    fseek(archi,0,SEEK_END);
                    i++;
                    a.id = i;
                }
            }
            fwrite(&a,sizeof(stConsumos),1,archi);
            flag = 0;
            fclose(archi);
            archi = fopen(nombreArchivoConsumos, "r+b");
        }
        fclose(archi);
    }

}
stConsumos cargaUnConsumo(char nombreArchivo[])/// CARGA UN CONSUMO MANUAL
{

    stConsumos a;
    a.idCliente = busquedaID(nombreArchivo);
    printf("\nIngrese el año de consumo: ");
    scanf("%d", &a.anio);
    printf("Ingrese el mes de consumo: ");
    scanf("%d", &a.mes);

    if(a.mes >12)
    {
        while(a.mes >12)
        {
            printf("\nMes no valido, ingreselo nuevamente: \n");
            scanf("%d", &a.mes);
        }
    }
    printf("Ingrese el dia de consumo: ");
    scanf("%d", &a.dia);

    if(a.dia >29 && a.mes == 2 && (a.anio%4 == 0))
    {
        while(a.dia > 29)
        {
            printf("\nFecha invalida. Valida hasta el 29. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if(a.dia>28 && a.mes == 2 && (a.anio%4 != 0))
    {
        while(a.dia > 28)
        {
            printf("\nFecha invalida. Valida hasta el 28. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if((a.mes == 1|| a.mes == 3 || a.mes == 5|| a.mes == 7|| a.mes == 8|| a.mes == 10|| a.mes == 12 )&& a.dia>31)
    {
        while(a.dia > 31)
        {
            printf("\nFecha invalida. Valida hasta 31. Ingresela nuevamante: ");
            scanf("%d", &a.dia);
        }
    }
    else
    {
        while(a.dia > 30 )
        {
            printf("\nFecha invalida. Valida hasta 30. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    printf("\nIngrese la cantidad de MB consumidos: ");
    scanf("%d", &a.datosConsumidos);
    a.baja = 0;

    return a;
}
void cargaArchivoConsumosFinal(char nombreArchivoConsumos[], char nombreArchivoClientes[])///CARGA ARCHIVO DE CONSUMOS MANUAL.
{
    stConsumos a;
    stConsumos b;
    static int i = 0;
    i=ultimoIdConsumo(nombreArchivoConsumos);

    int pos = 0;

    int flag = 0;
    int sumarDatos = 0;
    int idConsumo = 0;
    char opcion = 0;

    FILE *archi = fopen(nombreArchivoConsumos, "r+b");
    if(archi == NULL)
    {
        FILE *archi = fopen(nombreArchivoConsumos, "ab");
        fclose(archi);
        archi = fopen(nombreArchivoConsumos, "r+b");
    }
    if(archi != NULL)
    {
        do
        {

            a = cargaUnConsumo(nombreArchivoClientes);
            a.id = 0;
            while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
            {
                flag = comprobarConsumo2(nombreArchivoConsumos, a);
                if(flag == 1)
                {
                    pos =buscarPosID(nombreArchivoConsumos,a);
                    flag = 1;
                    sumarDatos = obtenerConsumo(nombreArchivoConsumos, a);
                    a.datosConsumidos = a.datosConsumidos + sumarDatos;
                    idConsumo = obtenerIdConsumo(nombreArchivoConsumos,a);
                    a.id = idConsumo;
                    fseek(archi,sizeof(stConsumos)*(pos-1),SEEK_SET);

                }
                else
                {
                    fseek(archi,0,SEEK_END);
                    i++;
                    a.id = i;
                }
            }
            fwrite(&a,sizeof(stConsumos),1,archi);
            printf("\nDesea seguir cargando consumos? ESC PARA SALIR: ");
            opcion = getch();
            fflush(stdin);
            flag = 0;
            if(opcion !=27)
            {
                fclose(archi);

                archi = fopen(nombreArchivoConsumos, "r+b");

            }
        }
        while(opcion != 27);
        fclose(archi);
    }

}
int comprobarConsumo2(char nombreArchivo[], stConsumos a)///COMPROBAR UN CONSUMO
{

    stConsumos b;
    int flag = 0;
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;
            }
        }
        fclose(archi);
    }

    return flag;
}
int obtenerConsumo(char nombreArchivo [], stConsumos a)///OBTENER UN CONSUMO
{

    stConsumos b;
    int flag = 0;
    int datosConsumidos = 0;

    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;

            }
        }
        fclose(archi);
    }
    fseek(archi,sizeof(stConsumos)*-1,SEEK_CUR);
    datosConsumidos = b.datosConsumidos;
    return datosConsumidos;
}
int obtenerIdConsumo(char nombreArchivo [], stConsumos a)///OBTENER EL ID DE UN CONSUMO
{

    stConsumos b;
    int flag = 0;
    int idConsumo = 0;

    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&b,sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;

            }
        }
        fclose(archi);
    }
    fseek(archi,sizeof(stConsumos)*-1,SEEK_CUR);
    idConsumo = b.id;

    return idConsumo;
}
int buscarPosID(char nombreArchivo[], stConsumos b)///OBTENER POSICION DE UN ID DE CONSUMO
{

    stConsumos a;
    int posicion = 0;
    int flag = 0;
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stConsumos),1,archi)>0)
        {
            if(a.dia == b.dia && a.mes == b.mes && a.anio == b.anio && a.idCliente == b.idCliente)
            {
                flag = 1;
                posicion =ftell(archi)/sizeof(stConsumos);
            }

        }
        fclose(archi);
    }
    return posicion;
}
int busquedaID(char nombreArchivo[])///BUSQUEDA ID CLIENTE
{
    stCliente b = busquedaClientesParaConsumos(nombreArchivo);
    int id = 0;
    stCliente a;

    FILE *archi = fopen(nombreArchivo, "rb");

    if(archi)
    {
        while(fread(&a, sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, b.dni) == 0)
            {

                id = a.idCliente;

            }

        }
        fclose(archi);
    }


    return id;
}
int comprobacionDniParaConsumoCliente(char nombreArchivo [], char dni[])///FUNCION PARA COMPARACION DE DNI  DE CLIENTES (RETORNA UNA BANDERA)
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
stCliente busquedaClientesParaConsumos(char nombreArchivo[])///FUNCION PARA LA BUSQUEDA DE CLIENTES EN ARCHIVO (RETORNA LA ESTRUCTURA)
{
    stCliente b;
    int flag = 0;
    printf("\nIngrese el dni del cliente: ");
    fflush(stdin);
    gets(b.dni);

    while(flag == 0)
    {
        flag = comprobacionDniParaConsumoCliente(nombreArchivo, b.dni);
        if(flag == 0)
        {
            printf("\nEl cliente no existe, ingrese otro DNI");
            fflush(stdin);
            gets(b.dni);
        }
        else
        {
            printf("\nMuy bien ahora busquemos el mes");
        }
    }


    return b;
}
int ultimoIdConsumo(char nombreArchivo[])///CONTADOR UNICO E INCREMENTAL DE ID (RETORNA EL ULTIMO ID)
{
    int id = 0;
    stConsumos e;
    FILE *arch = fopen(nombreArchivo, "rb");
    if(arch)
    {
        fseek(arch, -1*sizeof(stConsumos), SEEK_END);
        if(fread(&e, sizeof(stConsumos), 1, arch)>0)
        {
            id = e.id;
        }
        fclose(arch);
    }

    return id;
}
int funcionAcumulador(char nombreArchivo[])///FUNCION DE ACUMULADOR DE CONSUMOS (RETORNA EL CONSUMO ACUMULADO)
{

    FILE *archi = fopen(nombreArchivo, "rb");
    stConsumos a;
    stConsumos b = seleccionaUnaFecha();
    int consumo = 0;
    if(archi)
    {
        while(fread(&a,sizeof(stConsumos), 1,archi) >0)
        {
            if(b.anio == a.anio && b.dia == a.dia && b.mes == a.mes)
            {
                consumo = a.datosConsumidos + consumo;
            }
        }
    }
    return consumo;
}
stConsumos seleccionaUnaFecha()///FUNCION PARA VALIDACION DE FECHA (RETORNA ESTRUCTURA DE CONSUMOS)
{

    stConsumos a;

    printf("\nIngrese el anio de consumo: ");
    scanf("%d", &a.anio);
    printf("Ingrese el mes de consumo: ");
    scanf("%d", &a.mes);
    if(a.mes >12)
    {

        while(a.mes >12)
        {
            printf("\nMes no valido, ingreselo nuevamente: \n");
            scanf("%d", &a.mes);
        }
    }
    printf("Ingrese el dia de consumo: ");
    scanf("%d", &a.dia);

    if(a.dia >29 && a.mes == 2 && (a.anio%4 == 0))
    {
        while(a.dia > 29)
        {
            printf("\nFecha invalida. Valida hasta el 29. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if(a.dia>28 && a.mes == 2 && (a.anio%4 != 0))
    {
        while(a.dia > 28)
        {
            printf("\nFecha invalida. Valida hasta el 28. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    else if((a.mes == 1|| a.mes == 3 || a.mes == 5|| a.mes == 7|| a.mes == 8|| a.mes == 10|| a.mes == 12) && a.dia>31)
    {
        while(a.dia > 31)
        {
            printf("\nFecha invalida. Valida hasta 31. Ingresela nuevamante: ");
            scanf("%d", &a.dia);
        }
    }
    else
    {
        while(a.dia > 30)
        {
            printf("\nFecha invalida. Valida hasta 30. Ingresela nuevamente: ");
            scanf("%d", &a.dia);
        }
    }
    return a;
}
void muestraUnConsumo(stConsumos a)///MUESTRA INDIVIDUAL DE CONSUMO
{
    if(a.baja == 0)
    {
        color(15);
        printf("\n\t========================================");
        printf("\n\tID Consumo:\t\t\t   %4d", a.id);
        printf("\n\tID cliente:\t\t\t     %2d", a.idCliente);
        printf("\n\tFecha del consumo:\t     %2d/%2d/%4d", a.dia,a.mes,a.anio);
        printf("\n\tCantidad de datos consumidos:\t%4d MB", a.datosConsumidos);
        printf("\n\tActivo:\t\t\t\t     Si\n");
        printf("\t========================================\n");
        color(15);
    }
    else
    {
        color(8);
        printf("\n\t========================================");
        printf("\n\tID Consumo:\t\t\t   %4d", a.id);
        printf("\n\tID cliente:\t\t\t     %2d", a.idCliente);
        printf("\n\tFecha del consumo:\t     %2d/%2d/%4d", a.dia,a.mes,a.anio);
        printf("\n\tCantidad de datos consumidos:\t%4d MB", a.datosConsumidos);
        color(4);
        printf("\n\tActivo:\t\t\t\t     No\n");
        color(8);
        printf("\t========================================\n");
        color(15);
    }
}
void muestraArchivoConsumos(char nombreArchivo[])///MUETRA LISTA DE ARCHIVO DE CONSUMOS
{
    FILE *archi = fopen(nombreArchivo, "rb");
    stConsumos a;
    if(archi)
    {
        while(fread(&a,sizeof(stConsumos),1,archi)>0)
        {
            muestraUnConsumo(a);
        }
    }
    fclose(archi);
}
int pasarArchivo2ArregloConsumos(char nombreArchivo[], stConsumos c[], int dim)///FUNCION DE PASAJE DE DATOS DE UN ARCHIVO A UN ARREGLO
{
    FILE *archi = fopen(nombreArchivo, "rb");

    int i=0;
    stConsumos aux;
    if(archi)
    {
        while(i<dim && fread(&aux, sizeof(stConsumos), 1, archi) > 0)
        {
            c[i]=aux;
            i++;
        }

        fclose(archi);
    }
    return i;
}
void muestraArregloConsumos(stConsumos c[], int v)///MUESTRA EL ARREGLO DE CONSUMOS
{
    for(int i = 0; i<v; i++)
    {
        muestraUnConsumo(c[i]);
    }
}
void intercambioStConsumo(stConsumos *a, stConsumos *b)///FUNCION DE INTERCAMBIO DE POSICION DE ESTRUCTURAS
{
    stConsumos aux = *a;
    *a =*b;
    *b = aux;
}
int buscaMenorPosicionCliente (stConsumos c[], int val, int pos)///BUSQUEDA DE MENOR POSICION POR ID DE CLIENTE(RETORNA LA MENOR POSICION)
{
    int menorPosicion = pos;
    pos++;
    while (pos<val)
    {
        if (c[menorPosicion].id > c[pos].id)
        {
            menorPosicion=pos;
        }
        pos ++;
    }
    return menorPosicion;
}
void ordenarConsumosPorIdConsumo(stConsumos c[], int v)///ORDENA LISTA DE CONSUMOS MEDIANTE ID DEL CONSUMO
{
    int i=0;
    int posMenor;
    while (i<v-1)
    {
        posMenor=buscaMenorPosicionCliente(c, v, i);
        intercambioStConsumo(&c[i], &c[posMenor]);
        i++;
    }
}
int buscaMenorPosicionFecha (stConsumos c[], int val, int pos)///BUSQUEDA DE MENOR POSICION DE FECHA(RETORNA LA MENOR POSICION)
{
    int menorPosicion = pos;
    pos++;
    while (pos<val)
    {
        if (c[menorPosicion].anio > c[pos].anio)
        {
            menorPosicion=pos;
        }
        else if (c[menorPosicion].mes > c[pos].mes && c[menorPosicion].anio == c[pos].anio)
        {
            menorPosicion=pos;
        }
        else if (c[menorPosicion].dia > c[pos].dia && c[menorPosicion].mes == c[pos].mes && c[menorPosicion].anio == c[pos].anio)
        {
            menorPosicion=pos;
        }
        pos ++;
    }
    return menorPosicion;
}
void ordenarConsumosPorFecha (stConsumos c[], int v)///ORDENA LISTA DE CONSUMOS POR FECHA DE ALTA DEL CONSUMO
{
    int i=0;
    int posMenor;
    while (i<v-1)
    {
        posMenor=buscaMenorPosicionFecha(c, v, i);
        intercambioStConsumo(&c[i], &c[posMenor]);
        i++;
    }

}
stConsumos busquedaConsumo()///FUNCION PARA LA BUSQUEDA DE CONSUMOS
{
    stConsumos b;
    printf("\nBusqueda de cliente\n\n");
    printf("Id del cliente        : ");
    scanf("%2d",&b.idCliente);
    printf("Dia del consumo       : ");
    scanf("%2d",&b.dia);
    printf("Mes del consumo       : ");
    scanf("%2d",&b.mes);
    printf("Anio del consumo      : ");
    scanf("%4d",&b.anio);

    return b;
}
void bajaConsumo(char nombreArchivo[])///FUNCION PARA DAR LA BAJA DE UN CONSUMO ERRONEO
{
    stConsumos b = busquedaConsumo();
    stConsumos a;
    int flag = 0;

    FILE*archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stConsumos), 1, archi) > 0)
        {
            if(a.idCliente==b.idCliente&&a.dia==b.dia&&a.mes==b.mes&&a.anio==b.anio)
            {
                fseek(archi, -1*sizeof(stConsumos), 1);
                a.baja = 1;
                fwrite(&a, sizeof(stConsumos), 1, archi);
                flag++;
                muestraUnConsumo(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void altaConsumoInactivo(char nombreArchivo[])///FUNCION PARA EL ALTA DE UN COSUMO INACTIVO
{
    stConsumos b = busquedaConsumo();
    stConsumos a;
    int flag = 0;

    FILE*archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stConsumos), 1, archi) > 0)
        {
            if(a.idCliente==b.idCliente&&a.dia==b.dia&&a.mes==b.mes&&a.anio==b.anio)
            {
                fseek(archi, -1*sizeof(stConsumos), 1);
                a.baja = 0;
                fwrite(&a, sizeof(stConsumos), 1, archi);
                flag++;
                muestraUnConsumo(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
void modificacionDeConsumo(char nombreArchivo[])///FUNCION PARA LA MODIFICACION DE UN CONSUMO EQUIVOCADO
{
    printf("\nElija el cliente para hacer\nLa modificacion del consumo\n");
    stConsumos b = busquedaConsumo();
    stConsumos a;
    int flag = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi)
    {
        while(flag == 0 && fread(&a, sizeof(stConsumos), 1, archi) > 0)
        {
            if(a.idCliente==b.idCliente&&a.dia==b.dia&&a.mes==b.mes&&a.anio==b.anio)
            {
                muestraUnConsumo(a);
                printf("\n\nNumero del Id actual: %d\n\n", a.idCliente);
                fseek(archi, -1*sizeof(stConsumos), 1);
                printf("\nIngrese la fecha a modificar\n\n");
                printf("Ingrese el dia a modificar           : ");
                scanf("%d",&a.dia);
                printf("Ingrese el mes a modificar           : ");
                scanf("%d",&a.mes);
                printf("Ingrese el anio a modificar          : ");
                scanf("%d",&a.anio);
                printf("\nFecha del consumo:\t     %2d/%2d/%4d\n\n", a.dia,a.mes,a.anio);
                printf("Ingrese el consumo a modificar en MB : ");
                scanf("%d",&a.datosConsumidos);
                printf("El consumo modificado es %5d MB", a.datosConsumidos);
                fwrite(&a, sizeof(stConsumos), 1, archi);
                flag++;
                muestraUnConsumo(a);
            }
        }
        fclose(archi);
    }
    if(flag == 0)
    {
        printf("\n El cliente no se encuentra en la base de datos.");
    }
}
stConsumos seleccionMes()///SELECCIONAR UN MES DE CONSUMO
{

    stConsumos a;
    printf("\nIngrese el mes de consumo: ");
    scanf("%d", &a.mes);
    while(a.mes >12){
        printf("\nMes no valido, ingreselo nuevamente.");
        scanf("%d", &a.mes);
    }

    return a;
}
int funcionAcumuladorXMes(char nombreArchivo[],char nombreArchivoC [],int idCliente,int mes)///ACUMULADOR POR MES
{

    FILE *archi = fopen(nombreArchivo, "rb");
    stConsumos a;

    int consumo = 0;
    if(archi)
    {
        while(fread(&a,sizeof(stConsumos), 1,archi) >0)
        {
            if(mes == a.mes && idCliente == a.idCliente)
            {
                consumo = a.datosConsumidos + consumo;
            }
        }
    }
    return consumo;
}
stCliente busquedaClienteXDni(char nombreArchivo[])///Buscar un cliente por DNI
{
    stCliente a;

    char dni[30];
    int flag = 0;
    int pos =0;

    FILE *archi = fopen(nombreArchivo,"rb");
    if(archi)
    {
        do
        {
            printf("\nDni del cliente: ");
            fflush(stdin);
            gets(dni);
            flag = comprobacionDni(nombreArchivo,dni);
            if(flag == 1)
            {
                pos = posComprobacion(nombreArchivo,dni);
                fseek(archi,(pos-1)*sizeof(stCliente),SEEK_SET);
                fread(&a,sizeof(stCliente),1,archi);
            }
            else
            {
                printf("\nEl Dni no existe, ingrese nuevamente");
            }
        }
        while(flag == 0);
    }
    fclose(archi);

    return a;
}
int posComprobacion(char nombreArchivo [], char dni[])///Encontrar Posicion por DNI
{
    stCliente a;
    int pos = 0;
    FILE *archi = fopen(nombreArchivo,"rb");
    if(archi)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(a.dni, dni) == 0)
            {
                pos = ftell(archi)/sizeof(stCliente);
            }
        }
        fclose(archi);

    }
    return pos;
}
void mostrarFactura(char nombreArchivoConsumo[], char nombreArchivoCliente[])///MUESTRA LA FACTURA
{

    stCliente a;
    a = busquedaClienteXDni(nombreArchivoCliente);
    stConsumos b;
    b = seleccionMes();
    float costoTotal = 0;
    int datosConsumidos =funcionAcumuladorXMes(nombreArchivoConsumo,nombreArchivoCliente,a.idCliente,b.mes);

    costoTotal = (float)datosConsumidos * PRECIOMB + MANTENIMIENTO;
    system("cls");
    color(14);
    printf("\n=================================================");
    printf("\nApellido y Nombre..........:%10s, %s", a.apellido, a.nombre);
    printf("\nNumero de telefono.........:%20s",a.movil);
    printf("\nPeriodo de factura.........:%20d",b.mes);
    printf("\nDatos Consumidos...........:%20d",datosConsumidos);
    printf("\nPrecio por MB..............:%20.2f",PRECIOMB);
    printf("\nPrecio por MANTENIMIENTO...:%20d",MANTENIMIENTO);
    printf("\nTotal......................:%20.2f",costoTotal);
    printf("\n=================================================");
    color(15);
}


