#include "estetica.h"
#include <windows.h>
#include "gotoxy.h"

void logo_Recuadro_G(int x, int y)///FUNCION QUE MUESTRA EL RECUADRO DEL MENU
{
ocultarCursor();
  do
  {
    int a = rand() % (16 - 1) + 1;
    int b = 3; // rand() % 9 + 1;
    int c = rand() % (100 - 1) + 1;
    int e = rand() % (50 - 48) + 48;
    for (int i = y + 30; i > y - 1; i--)
    {
      color(a);
      gotoxy(x, i);
      printf("%c", 219); // Linea_vertica_izq - 219
    }
    for (int i = x + 1; i < x + 71; i++)
    {
      gotoxy(i, y);
      printf("%c", 223); // Linea_horizontal_ar - 223
    }
    for (int i = y; i < y + 31; i++)
    {
      gotoxy(x + 71, i);
      printf("%c", 219); // Linea_vertica_der - 219
    }
    for (int i = x + 70; i > x; i--)
    {
      gotoxy(i, y + 30);
      printf("%c", 220); // Linea_horizontal_abaj - 220
    }
    Sleep(300);
  } while (!kbhit());
  color(15);
}
void logo_Juego(int x, int y)///FUNCION QUE MUESTRA EL LOGO DEL JUEGO
{
    x += 13;
    y += 1;
    gotoxy(x, y);
    printf("%c%c%c%c%c%c                          %c   ", 201, 205, 205, 205, 205, 187, 186);
    gotoxy(x, y + 1);
    printf("%c    %c                          %c   ", 186, 186, 186);
    gotoxy(x, y + 2);
    printf("%c    %c        %c                 %c   ", 186, 186, 186, 186);
    gotoxy(x, y + 3);
    printf("%c    %c                          %c   ", 186, 186, 186);
    gotoxy(x, y + 4);
    printf("%c%c%c%c%c%c  %c%c%c%c  %c  %c%c%c%c%c%c%c  %c%c%c%c  %c   ", 204, 205, 205, 205, 205, 188, 204, 205, 205, 187, 186, 204, 205, 205, 203, 205, 205, 187, 201, 205, 205, 187, 186);
    gotoxy(x, y + 5);
    printf("%c       %c     %c  %c  %c  %c     %c  %c   ", 186, 186, 186, 186, 186, 186, 186, 186);
    gotoxy(x, y + 6);
    printf("%c       %c     %c  %c  %c  %c  %c%c%c%c  %c   ", 186, 186, 186, 186, 186, 186, 201, 205, 205, 185, 186);
    gotoxy(x, y + 7);
    printf("%c       %c     %c  %c  %c  %c  %c  %c  %c   ", 186, 186, 186, 186, 186, 186, 186, 186, 186);
    gotoxy(x, y + 8);
    printf("%c       %c     %c  %c  %c  %c  %c%c%c%c  %c   ", 186, 186, 186, 186, 186, 186, 200, 205, 205, 202, 186);
    gotoxy(x + 8, y + 5);
    gotoxy(x + 8, y + 6);
    gotoxy(x + 8, y + 7);
    gotoxy(x + 8, y + 9);
    printf("%c%c%c%c  %c  %c%c%c%c  %c%c%c%c  %c%c%c%c  %c%c%c%c  %c  %c ", 201, 205, 205, 187, 186, 201, 205, 205, 187, 201, 205, 205, 187, 201, 205, 205, 187, 204, 205, 205, 187, 186, 186);
    gotoxy(x + 8, y + 10);
    printf("   %c  %c  %c  %c  %c  %c  %c  %c  %c     %c  %c ", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);
    gotoxy(x + 8, y + 11);
    printf("%c%c%c%c  %c  %c%c%c%c  %c  %c  %c  %c  %c     %c  %c ", 201, 205, 205, 185, 186, 204, 205, 205, 188, 186, 186, 186, 186, 186, 186, 186);
    gotoxy(x + 8, y + 12);
    printf("%c  %c  %c  %c     %c  %c  %c  %c  %c     %c  %c ", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);
    gotoxy(x + 8, y + 13);
    printf("%c%c%c%c  %c  %c%c%c%c  %c%c%c%c  %c%c%c%c  %c     %c%c%c%c ", 200, 205, 205, 202,186, 200, 205, 205, 188, 200, 205, 205, 185, 200, 205, 205, 188, 186, 200, 205, 205, 185);
    gotoxy(x + 8, y + 14);
    printf("                  %c                 %c ", 186, 186);
    gotoxy(x + 8, y + 15);
    printf("                  %c                 %c ", 186, 186);
    gotoxy(x + 8, y + 16);
    printf("               %c%c%c%c              %c%c%c%c ", 200, 205, 205, 188, 200, 205, 205, 188);
}
void cargando(int x, int y)///FUNCION QUE MUESTRA UNA BARRA DE CARGA CON SU PORCENTAJE
{
  x += 17;
  y += 24;

  for (int i = x; i < x + 38; i++)
  {

    gotoxy(x + 12, y + 2);
    printf("Cargando %2d %%", ((i + 13) - x) * 2);
    color(2);
    gotoxy(i, y + 4);
    printf("%c", 219);
    Sleep(75);
    color(15);
  }
  Sleep(75);
  gotoxy(x + 12, y + 2);
  printf("Carga exitosa!!!");
  Sleep(500);

  system("cls");
}
void ocultarCursor()///FUNCION QUE OCULTA EL CURSOR
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}
void coordenadas(int x,int y)///FUNCION QUE UBICA LOS DATOS EN CONSOLA CON LAS CORDENADAS DADAS
{
    HANDLE ventana;
    ventana=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenada;
    coordenada .X=x;
    coordenada .Y=y;
    SetConsoleCursorPosition(ventana,coordenada);
}
void fijado(int x,int y,int dim_x,int dim_y)///FUNCION QUE FIJA LA CONSOLA EN UNA POSICION DADA
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
