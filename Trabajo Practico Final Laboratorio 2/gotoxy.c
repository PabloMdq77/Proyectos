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

#define USER_1 "1234"
#define USER_2 "1234"
#define PASS_1 "1234"
#define PASS_2 "1234"
#define LIMITE "9"
#define INTENTOS "3"
#define ARCHIVO"registro_Alegory.bin"

void color(int x){                                                              /// Cambia la combinacion de color de fondo y frente
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}

void gotoxy(int X,int Y){                                                       /// Cambia las coordenadas del cursor
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X=X;
      dwPos.Y=Y;
      SetConsoleCursorPosition(hcon,dwPos);
}

int whereX(){                                                                     /// Devuelve la posicion de X
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.X;
}

int whereY(){                                                                   /// Devuelve la posicion de Y
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
    return sbi.dwCursorPosition.Y;
}

void hidecursor(int ver){                                                       /// funcion para mostrar o esconder el cursor
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 1;
   info.bVisible = ver;
   SetConsoleCursorInfo(consoleHandle, &info);
}
