#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "puntaje.h"
#include "usuario.h"
#include "archivo.h"
#include "administrador.h"
#include "menu.h"
#include "estetica.h"
#include <windows.h>
#include "gotoxy.h"

#define ARCHIVO"registro_Alegory.bin"
#define DIM 100

void menu_Principal(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES PARA INICIAR COMO ADMINISTRADOR O COMO USUARIO
{
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+28,y+1);
        color(128);
        printf(" MEN%C PRINCIPAL ", 233);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+17,y+20);
        printf("1 - Administrador");
        gotoxy(x+45,y+20);
        printf("2 - Usuario");
        gotoxy(x+58,y+1);
        printf("3 - Creditos");
        gotoxy(x+2,y+29);
        printf("0 - Salir");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - Administrador
            gotoxy(x+36,y+20);
            printf("%c", 17);
            gotoxy(x+45,y+20);
            printf("           ");
            Sleep(100);
            menu_Administrador(x,y);
            getch();
            break;
        case 50://2 - Usuario
            gotoxy(x+43,y+20);
            printf("%c", 16);
            gotoxy(x+17,y+20);
            printf("                 ");
            Sleep(100);
            menu_Usuario(x,y);
            getch();
            break;
        case 51://3 - Creditos
            gotoxy(x+55,y+1);
            printf("%c", 16);
            Sleep(50);
            getch();
            break;
        case 48://0 - Salir
            gotoxy(x+13,y+29);
            printf("%c", 17);
            Sleep(50);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }

    while (touch != 48);
}
void menu_Administrador(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES DE ELECCION ENTRE LOS TIPOS DE ADMINISTRADORES
{
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);

        gotoxy(x+26,y+1);
        color(128);
        printf(" MEN%C ADMINISTRADOR ", 233);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+15,y+20);
        printf("1 - Control total");
        gotoxy(x+38,y+20);
        printf("2 - Control parcial");
        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - Control total
            gotoxy(x+33,y+20);
            printf("%c", 17);
            gotoxy(x+38,y+20);
            printf("                   ");
            Sleep(100);
            login_Administradores_P(x,y);

            getch();
            break;
        case 50://2 - Control parcial
            gotoxy(x+36,y+20);
            printf("%c", 16);
            gotoxy(x+15,y+20);
            printf("                 ");
            Sleep(100);
            login_Administradores_S(1,1);

            getch();
            break;
        case 48://0 - ATRAS
            gotoxy(x+13,y+29);
            printf("%c", 17);
            Sleep(50);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
void menu_Usuario(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES DE INICIO DE SESION Y LA OPCION DE REGISTRO DE UN USUARIO
{
    celda_Array user[DIM];
    lista_Nodo * lista=user[DIM].puntaje;
    int val=0;
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+29,y+1);
        color(128);
        printf(" MEN%C USUARIO ", 233);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+17,y+20);
        printf("1 - Iniciar sesion");
        gotoxy(x+39,y+20);
        printf("2 - Registrarse");
        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - Iniciar sesion
            gotoxy(x+37,y+20);
            printf("%c", 17);
            gotoxy(x+39,y+20);
            printf("               ");
            Sleep(100);
            login_Usuario(x,y);

            getch();
            break;
        case 50://2 - Registrarse
            gotoxy(x+37,y+20);
            printf("%c", 16);
            gotoxy(x+17,y+20);
            printf("                  ");
            Sleep(100);
            gotoxy(x+1,y+31);
            val=registrarse(user,DIM,val,x,y);
            cargar_To_Archivo(user,val,ARCHIVO);
            recorre_Y_Muestra_Adl(user,val);

            getch();
            break;
        case 48://0 - Atras
            gotoxy(x+13,y+29);
            printf("%c", 17);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
void menu_Juego(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES DEL JUEGO
{
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+30,y+1);
        color(128);
        printf(" MEN%C JUEGO ",233);
        color(15);
        gotoxy(x+25,y+18);
        printf("Opciones para elegir");
        gotoxy(x+30,y+20);
        color(128);
        printf(" 1 - PLAY ");
        color(15);

        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - PLAY
            gotoxy(x+28,y+20);;
            printf("%c", 16);



            getch();
            break;
        case 48://0 - Atras
            gotoxy(x+13,y+29);
            printf("%c", 17);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
void menu_Control_Total(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES QUE CORRESPONDEN AL ADMINISTRADOR PRINCIPAL
{
    celda_Array user[DIM];
    lista_Nodo * lista=user[DIM].puntaje;
    int val=0;
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+27,y+1);
        color(128);
        printf(" MEN%C MODIFICACI%CN ", 233, 224);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+21,y+20);
        printf("1 - Alta");
        gotoxy(x+43,y+20);
        printf("2 - Baja");
        gotoxy(x+29,y+22);
        printf("3 - Modificacion");
        gotoxy(x+21,y+24);
        printf("4 - Listado");
        gotoxy(x+39,y+24);
        printf("5 - Busqueda");
        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - Alta
            gotoxy(x+31,y+20);
            printf("%c", 17);
            gotoxy(x+43,y+20);//Baja
            printf("               ");
            gotoxy(x+21,y+22);//Segunda linea
            printf("                               ");
            gotoxy(x+21,y+24);//Tercera linea
            printf("                               ");

            gotoxy(x+1,y+31);
            alta_Usuario(user,lista);
            Sleep(100);

            getch();
            break;
        case 50://2 - Baja
            gotoxy(x+41,y+20);
            printf("%c", 16);
            gotoxy(x+21,y+20);
            printf("                  ");
            gotoxy(x+21,y+22);//Segunda linea
            printf("                               ");
            gotoxy(x+21,y+24);//Tercera linea
            printf("                               ");
            Sleep(100);
            val=baja_Usuario(user,lista);

            getch();
            break;
        case 51://1 - Modificacion
            gotoxy(x+27,y+22);
            printf("%c", 16);
            gotoxy(x+21,y+20);//Primera linea
            printf("                               ");
            gotoxy(x+21,y+24);//Tercera linea
            printf("                               ");
            Sleep(100);
            menu_Modificaciones_Selector(x,y);

            getch();
            break;
        case 52://2 - Listado
            gotoxy(x+34,y+24);
            printf("%c", 17);
            gotoxy(x+21,y+20);
            printf("                               ");//Primera linea
            gotoxy(x+21,y+22);
            printf("                               ");//Segunda linea
            gotoxy(x+39,y+24);
            printf("                  ");
            val=cargar_To_Adl(user,DIM,ARCHIVO);
            recorre_Y_Muestra_Adl(user,val);
            Sleep(100);

            getch();
            break;
        case 53://1 - Busqueda
            gotoxy(x+37,y+24);
            printf("%c", 16);
            gotoxy(x+21,y+20);
            printf("                               ");//Primera linea
            gotoxy(x+21,y+22);
            printf("                               ");//Segunda linea
            gotoxy(x+21,y+24);
            printf("               ");
            Sleep(100);
            buscar_Mostrar(user,val);
            getch();
            break;
        case 54://2 - -----------------------
            gotoxy(x+39,y+20);
            printf("%c", 16);
            gotoxy(x+21,y+20);
            printf("                  ");
            Sleep(100);

            getch();
            break;
        case 48://0 - Atras
            gotoxy(x+13,y+29);
            printf("%c", 17);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
void menu_Control_Parcial(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES QUE CORRESPONDEN AL ADMINISTRADOR SECUNDARIO
{
    celda_Array user[DIM];
    lista_Nodo * lista=user[DIM].puntaje;
    int val=0;
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+27,y+1);
        color(128);
        printf(" MEN%C MODIFICACI%CN ", 233, 224);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+21,y+20);
        printf("1 - Listado");
        gotoxy(x+39,y+20);
        printf("2 - Busqueda");
        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://2 - Listado
            gotoxy(x+34,y+20);
            printf("%c", 17);
            gotoxy(x+39,y+20);
            printf("                  ");

            val=cargar_To_Adl(user,DIM,ARCHIVO);
            recorre_Y_Muestra_Adl(user,val);
            Sleep(100);

            getch();
            break;
        case 50://1 - Busqueda
            gotoxy(x+37,y+20);
            printf("%c", 16);
            gotoxy(x+21,y+20);
            printf("               ");
            buscar_Mostrar(user,val);
            Sleep(100);

            getch();
            break;
        case 48://0 - Atras
            gotoxy(x+13,y+29);
            printf("%c", 17);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
void menu_Modificaciones_Selector(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES SOBRE LO QUE SE DESEA MODIFICAR
{
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+27,y+1);
        color(128);
        printf(" MEN%C MODIFICACI%CN ", 233, 224);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+21,y+20);
        printf("1 - Usuario");
        gotoxy(x+41,y+20);
        printf("2 - Puntaje");
        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - Usuario
            gotoxy(x+34,y+20);
            printf("%c", 17);
            gotoxy(x+41,y+20);
            printf("               ");
            Sleep(100);
            menu_Modificacion_Usuario(x,y);

            getch();
            break;
        case 50://2 - Puntaje
            gotoxy(x+39,y+20);
            printf("%c", 16);
            gotoxy(x+21,y+20);
            printf("                  ");
            menu_Modificacion_Puntaje(x,y);
            Sleep(100);

            getch();
            break;
        case 48://0 - Atras
            gotoxy(x+13,y+29);
            printf("%c", 17);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
void menu_Modificacion_Usuario(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES DE MODIFICACION DEL USUARIO
{
    celda_Array user[DIM];
    lista_Nodo * lista=user[DIM].puntaje;
    int val=0;
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+27,y+1);
        color(128);
        printf(" MEN%C MODIFICACI%CN ", 233, 224);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+19,y+20);
        printf("1 - Nombre");
        gotoxy(x+41,y+20);
        printf("2 - Apellido");
        gotoxy(x+19,y+22);
        printf("3 - DNI");
        gotoxy(x+43,y+22);
        printf("4 - Correo");
        gotoxy(x+19,y+24);
        printf("5 - Username");
        gotoxy(x+41,y+24);
        printf("6 - Password");
        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - Nombre
            gotoxy(x+31,y+20);
            printf("%c", 17);
            gotoxy(x+41,y+20);//Primera linea
            printf("               ");
            gotoxy(x+19,y+22);//Segunda linea
            printf("                                  ");
            gotoxy(x+19,y+24);//Tercera linea
            printf("                                  ");
            modificar_Nombre(user,val);


            Sleep(100);

            getch();
            break;
        case 50://2 - Apellido
            gotoxy(x+39,y+20);
            printf("%c", 16);
            gotoxy(x+17,y+20);//Primera linea
            printf("                    ");
            gotoxy(x+19,y+22);//Segunda linea
            printf("                                  ");
            gotoxy(x+19,y+24);//Tercera linea
            printf("                                  ");
            modificar_Apellido(user,val);
            Sleep(100);
            getch();
            break;
        case 51://1 - DNI Segunda linea
            gotoxy(x+28,y+22);
            printf("%c", 17);
            gotoxy(x+19,y+20);//Primera linea
            printf("                                  ");
            gotoxy(x+43,y+22);//Segunda linea
            printf("                    ");
            gotoxy(x+19,y+24);//Tercera linea
            printf("                                  ");
            modificar_Dni(user,val);
            Sleep(100);


            getch();
            break;
        case 52://2 - Correo
            gotoxy(x+41,y+22);
            printf("%c", 16);
            gotoxy(x+19,y+20);//Primera linea
            printf("                                  ");
            gotoxy(x+19,y+22);//Segunda linea
            printf("                  ");
            gotoxy(x+19,y+24);//Tercera linea
            printf("                                  ");

            modificar_Correo(user,val);

            Sleep(100);

            getch();
            break;
        case 53://1 - Username
            gotoxy(x+33,y+24);
            printf("%c", 17);
            gotoxy(x+19,y+20);//Primera linea
            printf("                                  ");
            gotoxy(x+19,y+22);//Segunda linea
            printf("                                  ");
            gotoxy(x+41,y+24);//Tercera linea
            printf("                  ");

            modificar_Username(user,val);

            Sleep(100);

            getch();
            break;
        case 54://2 - Password
            gotoxy(x+39,y+24);
            printf("%c", 16);
            gotoxy(x+19,y+20);//Primera linea
            printf("                                  ");
            gotoxy(x+19,y+22);//Segunda linea
            printf("                                  ");
            gotoxy(x+19,y+24);//Tercera linea
            printf("                  ");

            modificar_Password(user,val);
            Sleep(100);

            getch();
            break;
        case 48://0 - Atras
            gotoxy(x+13,y+29);
            printf("%c", 17);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
void menu_Modificacion_Puntaje(int x, int y)///FUNCION QUE ORGANIZA EN UN MENU LAS OPCIONES DE MODIFICACION DEL PUNTAJE DEL USUARIO
{
    celda_Array user[DIM];
    lista_Nodo * lista=user[DIM].puntaje;
    int val=0;
    int touch;
    do
    {
        system("cls");
        logo_Juego(x,y);
        gotoxy(x+27,y+1);
        color(128);
        printf(" MEN%C MODIFICACI%CN ", 233, 224);
        color(15);
        gotoxy(x+26,y+18);
        printf("Opciones para elegir");
        gotoxy(x+14,y+20);
        printf("1 - Nro de nivel");
        gotoxy(x+38,y+20);
        printf("2 - Estado del Nivel");
        gotoxy(x+14,y+22);
        printf("3 - Caidas");
        gotoxy(x+46,y+22);
        printf("4 - Intentos");
        gotoxy(x+14,y+24);
        printf("5 - Pasos");
        gotoxy(x+41,y+24);
        printf("6 - Puntaje Total");
        gotoxy(x+2,y+29);
        printf("0 - Atras");
        logo_Recuadro_G(x,y);
        touch = getch();
        switch (touch)
        {
        case 49://1 - Nro de nivel
            gotoxy(x+32,y+20);
            printf("%c", 17);
            gotoxy(x+38,y+20);//Primera linea
            printf("                      ");
            gotoxy(x+14,y+22);//Segunda linea
            printf("                                            ");
            gotoxy(x+14,y+24);//Tercera linea
            printf("                                            ");
            modificar_Numero_de_nivel(user,lista,val);

            Sleep(100);

            getch();
            break;
        case 50://2 - Estado del Nivel
            gotoxy(x+36,y+20);
            printf("%c", 16);
            gotoxy(x+14,y+20);//Primera linea
            printf("                      ");
            gotoxy(x+14,y+22);//Segunda linea
            printf("                                            ");
            gotoxy(x+14,y+24);//Tercera linea
            printf("                                            ");

            modificar_Estado_del_Nivel(user,user->puntaje,val);

            Sleep(100);
            getch();
            break;
        case 51://1 - Caidas
            gotoxy(x+25,y+22);
            printf("%c", 17);
            gotoxy(x+14,y+20);//Primera linea
            printf("                                            ");
            gotoxy(x+46,y+22);//Segunda linea
            printf("                      ");
            gotoxy(x+14,y+24);//Tercera linea
            printf("                                            ");
            Sleep(100);

            modificar_Caidas(user,user->puntaje,val);


            getch();
            break;
        case 52://2 - Intentos
            gotoxy(x+44,y+22);
            printf("%c", 16);
            gotoxy(x+14,y+20);//Primera linea
            printf("                                            ");
            gotoxy(x+14,y+22);//Segunda linea
            printf("                      ");
            gotoxy(x+14,y+24);//Tercera linea
            printf("                                            ");

            modificar_Intentos(user,user->puntaje,val);

            Sleep(100);

            getch();
            break;
        case 53://1 - Pasos
            gotoxy(x+25,y+24);
            printf("%c", 17);
            gotoxy(x+14,y+20);//Primera linea
            printf("                                            ");
            gotoxy(x+14,y+22);//Segunda linea
            printf("                                            ");
            gotoxy(x+41,y+24);//Tercera linea
            printf("                      ");

            modificar_Pasos(user,user->puntaje,val);

            Sleep(100);

            getch();
            break;
        case 54://2 - Puntaje Total
            gotoxy(x+39,y+24);
            printf("%c", 16);
            gotoxy(x+14,y+20);//Primera linea
            printf("                                            ");
            gotoxy(x+14,y+22);//Segunda linea
            printf("                                            ");
            gotoxy(x+14,y+24);//Tercera linea
            printf("                      ");

            modificar_Puntaje_Total(user,user->puntaje,val);
            Sleep(100);

            getch();
            break;
        case 48://0 - Atras
            gotoxy(x+13,y+29);
            printf("%c", 17);
            break;
        default:
        {
            Beep(13000, 200);
            gotoxy(x+26,y+27);
            color(12);
            printf("Preciono la tecla !!!");
            Sleep(1);
            gotoxy(x+34,y+28);
            printf("[ %c ]", touch);
            Sleep(1);
            gotoxy(x+18, y+29);
            printf("Opcion invalida, vuelva a intentarlo");
            color(15);
            Sleep(600);
        }
        }
    }
    while (touch != 48);
}
