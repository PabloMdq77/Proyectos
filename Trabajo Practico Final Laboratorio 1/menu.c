
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "estetica.h"
#include "clientes.h"
#include "consumos.h"
#include "menu.h"

#define CLIENTE"Clientes.dat"
#define CONSUMO"Consumos.dat"



void menu_Principal()
{
    stCliente lista1[100];
    stConsumos lista2[10000];
    int validos=0;
    int opcion=0;
    do
    {
        system("cls");
        color(15);
        printf("\n       Menu de opciones con cual desea trabajar ?\n\n");
        printf("\n       1 - Clientes\n");
        printf("\n       2 - Consumos\n");
        printf("\n       3 - Imprimir factura\n");
        printf("\n       0 - Salir\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();
        opcion=getch();
        int validos=0;
        stCliente lista1[100];
        stConsumos lista2[10000];
        switch(opcion)
        {
        case 49:
            menu_Clientes();
            break;
        case 50:
            menu_Consumos();
            break;
        case 51:
            color(15);
            printf("\n\t\n\tIMPRIMIR FACTURA\n\n");
            color(15);
            mostrarFactura(CONSUMO,CLIENTE);
            getch();
            break;
        case 48:
            break;
        default:
            color(4);
            printf("\n\n\t\t    Selecciono [%c], \n\n\t\tLa tecla es incorrecta\n",opcion);Sleep(1000);
            color(15);
            Sleep(350);
            break;
        }
    }
    while(opcion!=48);
}
void menu_Clientes()
{
    stCliente lista1[100];
    stConsumos lista2[10000];
    int validos=0;
    int opcion=0;
    do
    {
        system("cls");
        color(15);
        printf("\n       CLIENTES\n\n");
        printf("\n       1 - Alta de clientes\n");
        printf("\n       2 - Baja de cliente \n");
        printf("\n       3 - Alta de cliente inactivos\n");
        printf("\n       4 - Modificacion de datos\n");
        printf("\n       5 - Listados de Clientes\n");
        printf("\n       0 - Volver menu anterior\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();
        opcion=getch();
        switch(opcion)
        {
        case 49:
            color(15);
            printf("\n\t\n\tALTA DE CLIENTES\n\n");
            color(15);

            cargaArchivoCliente(CLIENTE);
            getch();
            break;
        case 50:
            color(15);
            printf("\n\t\n\tBAJA DE CLIENTES\n\n");
            color(15);

            bajaDeCliente(CLIENTE);
            getch();
            break;
        case 51:
            color(15);
            printf("\n\t\n\tALTA DE CLIENTE INACTIVOS\n\n");
            color(15);

            altaClienteInactivo(CLIENTE);
            getch();
            break;
        case 52:
            menu_Modificacion_De_Datos();
        case 53:
            menu_Listado_De_Clientes();
        case 48:
            break;
        default:
            color(4);
            printf("\n\n\t\t    Selecciono [%c], \n\n\t\tLa tecla es incorrecta\n",opcion);Sleep(1000);
            color(15);
            Sleep(350);
            break;
        }
    }
    while(opcion!=48);
}
void menu_Consumos()
{
    stCliente lista1[100];
    stConsumos lista2[10000];
    int validos=0;
    int opcion=0;
    do
    {
        system("cls");
        color(15);
        printf("\n       CONSUMOS\n\n");
        printf("\n       1 - Alta de Consumo\n");
        printf("\n       2 - Baja de Consumo\n");
        printf("\n       3 - Alta de Consumo inactivo\n");
        printf("\n       4 - Modificacion de Consumo\n");
        printf("\n       5 - Listados de consumo\n");
        printf("\n       0 - Volver menu anterior\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();
        opcion=getch();
        switch(opcion)
        {
        case 49:
            menu_Alta_De_Consumos();

            break;
        case 50:
            color(15);
            printf("\n\t\n\tBAJA DE CONSUMO\n\n");
            color(15);

            bajaConsumo(CONSUMO);
            getch();
            break;
        case 51:
            color(15);
            printf("\n\t\n\tALTA DE CONSUMO INACTIVO\n\n");
            color(15);

            altaConsumoInactivo(CONSUMO);
            getch();
            break;
        case 52:
            color(15);
            printf("\n\t\n\tMODIFICACION DE CONSUMO\n\n");
            color(15);

            modificacionDeConsumo(CONSUMO);
            getch();
            break;
        case 53:
            menu_Listado_De_Consumos();
            break;
        case 48:
            break;
        default:
            color(4);
            printf("\n\n\t\t    Selecciono [%c], \n\n\t\tLa tecla es incorrecta\n",opcion);Sleep(1000);
            color(15);
            Sleep(350);
            break;
        }
    }
    while(opcion!=48);
}
void menu_Alta_De_Consumos()
{
    stCliente lista1[100];
    stConsumos lista2[10000];
    int validos=0;
    int opcion=0;
    do
    {
        system("cls");
        color(15);
        printf("\n       ALTA DE CONSUMO\n\n");
        printf("\n       1 - Carga manual\n");
        printf("\n       2 - Carga automatica\n");
        printf("\n       0 - Volver menu anterior\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();

        opcion=getch();
        switch(opcion)
        {
        case 49:
            color(15);
            printf("\n\t\n\tCARGA MANUAL\n\n");
            color(15);

            cargaArchivoConsumosFinal(CONSUMO,CLIENTE);
            getch();
            break;
        case 50:
            color(15);
            printf("\n\t\n\tCARGA AUTOMATICA\n\n");
            color(15);

            cargaArchivoConsumosRandom(CONSUMO,CLIENTE);

            getch();
            break;
        case 48:
            break;
        default:
            color(4);
            printf("\n\n\t\t    Selecciono [%c], \n\n\t\tLa tecla es incorrecta\n",opcion);Sleep(1000);
            color(15);
            Sleep(350);
            break;
        }
    }
    while(opcion!=48);
}
void menu_Listado_De_Consumos()
{
    stCliente lista1[100];
    stConsumos lista2[10000];
    int validos=0;
    int opcion=0;
    do
    {
        system("cls");
        color(15);
        printf("\n       LISTADOS DE CONSUMO\n\n");
        printf("\n       1 - Id de consumo\n");
        printf("\n       2 - Fecha\n");
        printf("\n       0 - Volver al menu anterior\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();
        opcion=getch();
        switch(opcion)
        {
        case 49:
            color(15);
            printf("\n\t\n\tLISTADOS DE CONSUMO ORDENADO POR ID CONSUMO\n\n");
            color(15);

            validos=pasarArchivo2ArregloConsumos(CONSUMO,lista2,10000);
            ordenarConsumosPorIdConsumo(lista2,validos);
            muestraArregloConsumos(lista2,validos);
            getch();
            break;
        case 50:
            color(15);
            printf("\n\t\n\tLISTADOS DE CONSUMO ORDENADO POR FECHA\n\n");
            color(15);

            validos=pasarArchivo2ArregloConsumos(CONSUMO,lista2,10000);
            ordenarConsumosPorFecha(lista2,validos);
            muestraArregloConsumos(lista2,validos);
            getch();
            break;
        case 48:
            break;
        default:
            color(4);
            printf("\n\n\t\t    Selecciono [%c], \n\n\t\tLa tecla es incorrecta\n",opcion);Sleep(1000);
            color(15);
            Sleep(350);
            break;
        }
    }
    while(opcion!=48);
}
void menu_Modificacion_De_Datos()
{
    stCliente lista1[100];
    stConsumos lista2[10000];
    int validos=0;
    int opcion=0;
    do
    {
        system("cls");
        color(15);
        printf("\n       MODIFICACION DE DATOS\n\n");
        printf("\n       1 - Cambio titularidad\n");
        printf("\n       2 - Nombre\n");
        printf("\n       3 - Apellido\n");
        printf("\n       4 - Dni\n");
        printf("\n       5 - Email\n");
        printf("\n       6 - Domiciilo\n");
        printf("\n       7 - Movil\n");
        printf("\n       0 - Volver menu anterior\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();
        opcion=getch();
        switch(opcion)
        {
        case 49:
            color(15);
            printf("\n\t\n\tCAMBIO DE TITULARIDAD\n\n");
            color(15);

            cambioDeTitularidad(CLIENTE);
            getch();
            break;
        case 50:
            color(15);
            printf("\n\t\n\tNOMBRE\n\n");
            color(15);

            modificacionNombreCliente(CLIENTE);
            getch();
            break;
        case 51:
            color(15);
            printf("\n\t\n\tAPELLIDO\n\n");
            color(15);

            modificacionApellidoCliente(CLIENTE);
            getch();
            break;
        case 52:
            color(15);
            printf("\n\t\n\tDNI\n\n");
            color(15);

            modificacionDniCliente(CLIENTE);
            getch();
            break;
        case 53:
            color(15);
            printf("\n\t\n\tEMAIL\n\n");
            color(15);

            modificacionEmailCliente(CLIENTE);
            getch();
            break;
        case 54:
            color(15);
            printf("\n\t\n\tDOMICILIO\n\n");
            color(15);

            modificacionDomicilioCliente(CLIENTE);
            getch();
            break;
        case 55:
            color(15);
            printf("\n\t\n\tMOVIL\n\n");
            color(15);

            modificacionNumMovilCliente(CLIENTE);
            getch();
            break;
        case 48:
            break;
        default:
            color(4);
            printf("\n\n\t\t    Selecciono [%c], \n\n\t\tLa tecla es incorrecta\n",opcion);Sleep(1000);
            color(15);
            Sleep(350);
            break;
        }
    }
    while(opcion!=48);
}
void menu_Listado_De_Clientes()
{
    stCliente lista1[100];
    stConsumos lista2[10000];
    int validos=0;
    int opcion=0;
    do
    {
        system("cls");
        color(15);
        printf("\n       LISTADOS DE CLIENTES\n\n");
        printf("\n       1 - Mostrar clientes\n");
        printf("\n       2 - Ordenar clientes por Apellido\n");
        printf("\n       3 - Ordenar clientes por Numero de cliente\n");
        printf("\n       0 - Volver menu anterior\n");
        printf("\n\n       Ingrese una opcion\n\n       ");
        color(15);
        bannerRecuadro();
        opcion=getch();
        switch(opcion)
        {
        case 49:
            color(15);
            printf("\n\t\n\tMOSTRANDO CLIENTES\n\n");
            color(15);

            muestraArchivoClientes(CLIENTE);
            getch();
            break;
        case 50:
            color(15);
            printf("\n\t\n\tLISTADO ORDENADO POR APELLIDO\n\n");
            color(15);

            validos=pasarArchivo2ArregloClientes(CLIENTE,lista1,100);
            ordearAgendaPorApellido(lista1,validos);
            muestraArregloClientes(lista1,validos);

            getch();
            break;
        case 51:
            color(15);
            printf("\n\t\n\tLISTADO ORDENADO POR NUMERO DE CLIENTE\n\n");
            color(15);


            validos=pasarArchivo2ArregloClientes(CLIENTE,lista1,100);
            ordearAgendaNroCliente(lista1,validos);
            muestraArregloClientes(lista1,validos);
            getch();
            break;
        case 48:
            break;
        default:
            color(4);
            printf("\n\n\t\t    Selecciono [%c], \n\n\t\tLa tecla es incorrecta\n",opcion);Sleep(1000);
            color(15);
            Sleep(350);
            break;
        }
    }
    while(opcion!=48);
}

