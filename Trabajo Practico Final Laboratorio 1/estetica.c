#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "gotoxy.h"
#include <windows.h>
#include "Estetica.h"

void bannerRecuadro()
{
    ocultarCursor();
    int a=rand()%10+1;
    int b=rand()%9+1;

    for (int i = 24; i>-1; i--)
    {
        color(14);
        gotoxy(1,i);
        printf("%c",219);

    }
    for (int i =2; i<51; i++)
    {

        gotoxy(i,0);
        printf("%c",223);

    }
    for (int i =0; i<25; i++)
    {

        gotoxy(51,i);
        printf("%c",219);

    }
    for (int i =50; i>1; i--)
    {

        gotoxy(i,24);
        printf("%c",220);

    }
    color(7);


}
void bannerBienvenida()
{
    ocultarCursor();
    for (int h =1; h<2; h++)
    {
        gotoxy(13,1);
        color(6);
        bannerMateria();
        Sleep(8);

        gotoxy(15,3);
        color(6);
        bannerTrabajoPractico();
        Sleep(8);

        gotoxy(15,5);
        color(5);
        bannerIntegrantes();
        Sleep(8);

        gotoxy(19,7);
        color(2);
        bannerAndrea();
        Sleep(8);

        gotoxy(15,9);
        color(2);
        bannerMaximiliano();
        Sleep(8);

        gotoxy(16,11);
        color(2);
        bannerPablo();
        Sleep(8);

        gotoxy(14,13);
        color(2);
        bannerEmiliano();
        Sleep(8);

        color(15);
        gotoxy(11,15);
        printf("Presione una tecla para cargar.");

    }
    getch();

    for (int i =11; i<=41; i++)
    {

        gotoxy(i,17);
        color(2);
        printf("%c",219);
        gotoxy(22,19);
        Sleep(20);
        color(15);
        printf("Cargando ");
        Sleep(2);
        color(15);
    }
    gotoxy(19,21);
    printf("Carga exitosa !!!");
    gotoxy(7,23);
    printf("Presionar un tecla para entrar al menu");
    getch();
    system("cls");
}
void bannerMateria()
{
    ocultarCursor();
    printf("B");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("v");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("d");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("L");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("b");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("1");
    Sleep(25);
}
void bannerTrabajoPractico()
{
    ocultarCursor();

    printf("T");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("b");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("j");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("P");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("c");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("c");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("F");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("l");
    Sleep(25);
}
void bannerIntegrantes()
{
    ocultarCursor();
    printf("I");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("g");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("d");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("q");
    Sleep(25);
    printf("u");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("p");
    Sleep(25);
    printf("o");
    Sleep(25);
}
void bannerAndrea()
{
    ocultarCursor();
    printf("B");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("c");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("A");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("d");
    Sleep(25);
    printf("r");
    Sleep(25);
    printf("e");
    Sleep(25);
    printf("a");
    Sleep(25);
}
void bannerMaximiliano()
{
    ocultarCursor();
    printf("C");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("M");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("x");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("m");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("o");
    Sleep(25);
}
void bannerPablo()
{
    ocultarCursor();
    printf("C");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("v");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("P");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("b");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("D");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("v");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("d");
    Sleep(25);
}
void bannerEmiliano()
{
    ocultarCursor();
    printf("S");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(",");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("E");
    Sleep(25);
    printf("m");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("l");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("a");
    Sleep(25);
    printf("n");
    Sleep(25);
    printf("o");
    Sleep(25);
    printf(" ");
    Sleep(25);
    printf("A");
    Sleep(25);
    printf("g");
    Sleep(25);
    printf("u");
    Sleep(25);
    printf("s");
    Sleep(25);
    printf("t");
    Sleep(25);
    printf("i");
    Sleep(25);
    printf("n");
    Sleep(25);

}
void ocultarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}
void coordenadas(int x,int y)
{
    HANDLE ventana;
    ventana=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenada;
    coordenada .X=x;
    coordenada .Y=y;
    SetConsoleCursorPosition(ventana,coordenada);
}
void fijado(int x,int y,int dim_x,int dim_y)
{
    x=x*10;
    y=y*10;
    dim_x=dim_x*10;
    dim_y=dim_y*10;
    HWND control;
    control=GetConsoleWindow();
    if(control)
    {
        MoveWindow(control,x,y,dim_x,dim_y,1);
    }
}
