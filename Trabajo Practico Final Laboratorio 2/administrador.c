#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "administrador.h"
#include "gotoxy.h"

#define USER_1 "1234"
#define USER_2 "1234"
#define PASS_1 "1234"
#define PASS_2 "1234"
#define LIMITE 9
#define INTENTOS 3
#define ARCHIVO"registro_Alegory.bin"

void cargaUser_Admin(char * dato, int x, int y)///FUNCION QUE CARGA EL USERNAME DEL ADMINISTRADOR
{
    gotoxy(x+28,y+24);
    printf("               ");
    gotoxy(x+31,y+24);
    printf("Username");
    gotoxy(x+28,y+22);
    printf("Iniciar sesion");
    fflush(stdin);

  gotoxy(x+30,y+26);
  printf("               ");
  gotoxy(x+32,y+26);
  gets(dato);
    gotoxy(x+28,y+22);
    printf("               ");
  gotoxy(x+30,y+26);
  printf("               ");
}
void cargaPass_Admin(char * clave, int x, int y)///FUNCION QUE CARGA EL PASSWORD DEL ADMINISTRADOR OCULTANDO LOS DATOS MOSTRANDO ASTERISCOS
{
  int i = 0;
  char caracter;
  i = 0;
  gotoxy(x+28,y+24);
  printf("                    ");
  gotoxy(x+31,y+24);
  printf("Password", 164);
  fflush(stdin);
  gotoxy(x+31,y+26);
  while (caracter = getch())
  {
    if (caracter == 13)
    {
      clave[i] = '\0';
      break;
    }
    else if (caracter == 8)
    {
      if (i > 0)
      {
        i--;
        printf("\b \b");
      }
    }
    else
    {
      if (i < LIMITE)
      {
        printf("*");
        clave[i] = caracter;
        i++;
      }
    }
  }
}
void validar_Intent_Admin_P(int intentos, int x, int y)///FUNCION QUE VALIDA LOS INTENTOS DEL ADMINISTRADOR PRINCIPAL AL INICIAR SESION
{
  if (intentos <= 2)
  {
        gotoxy(x + 22, y + 22);
        printf("                             ");
        gotoxy(x + 22, y + 28);
        printf("                             ");
        Sleep(1);
        cargando(x, y);
        menu_Control_Total(x, y);
  }
  else
  {
    gotoxy(x+21,y+28);
    Beep(13000, 200);
    gotoxy(x+21,y+24);color(12);
    printf("Excedio el numero de intentos");color(15);
  }
}
void validar_Intent_Admin_S(int intentos, int x, int y)///FUNCION QUE VALIDA LOS INTENTOS DEL ADMINISTRADOR SECUNDARIO AL INICIAR SESION
{
  if (intentos <= 2)
  {
        gotoxy(x + 22, y + 22);
        printf("                             ");
        gotoxy(x + 22, y + 28);
        printf("                             ");
        Sleep(1);
        cargando(x, y);
    menu_Control_Parcial(x, y);
  }
  else
  {
    Beep(13000, 200);
    gotoxy(x+21,y+24);color(12);
    printf("Excedio el numero de intentos");color(15);
  }
}
int validar_Login_Admin_P(char user[], char pass[])///FUNCION QUE VALIDA EL LOGIN DEL ADMINISTRADOR SECUNDARIO
{
  int flag = 0;
  if ((strcmpi(user, USER_1) == 0) && (strcmpi(pass, PASS_1) == 0))
  {
    flag = 1;
  }
  return flag;
}
int comprob_Login_Admin_P(int x, int y)///FUNCION QUE COMPRUEBA EL LOGIN DEL ADMINISTRADOR SECUNDARIO
{
  st_Login_Admin aux;
  int flag = 0;
  int intentos = 0;
  do
  {
    cargaUser_Admin(&aux.usuario, x, y);
    cargaPass_Admin(&aux.password, x, y);
    flag = validar_Login_Admin_P(aux.usuario, aux.password);
    if(flag==1)
    {
      gotoxy(x + 22, y + 24);
      printf("                          ");
      gotoxy(x + 29, y + 24);
      Sleep(1);
    }
    if (flag == 0)
    {
      Beep(13000, 200);
      gotoxy(x + 22, y + 28);color(12);
      printf("Usuario invalido");
      intentos++;
      gotoxy(x + 39, y + 28);
      printf("%d%c intento", intentos, 167);color(15);
    }
  } while (intentos < INTENTOS && flag == 0);
  return intentos;
}
int validar_Login_Admin_S(char pass[], char user[])///FUNCION QUE VALIDA EL LOGIN DEL ADMINISTRADOR PRINCIPAL
{
  int flag = 0;
  if ((strcmpi(user, USER_2) == 0) && (strcmpi(pass, PASS_2) == 0))
  {
    flag = 1;
  }
  return flag;
}
int comprob_Login_Admin_S(int x, int y)///FUNCION QUE COMPRUEBA EL LOGIN DEL ADMINISTRADOR PRINCIPAL
{
  st_Login_Admin aux;
  int flag = 0;
  int intentos = 0;
  do
  {
    cargaUser_Admin(&aux.usuario, x, y);
    cargaPass_Admin(&aux.password, x, y);
    flag = validar_Login_Admin_S(aux.usuario, aux.password);
    if(flag==1)
    {
      gotoxy(x + 22, y + 24);
      printf("                          ");
      gotoxy(x + 29, y + 24);
      Sleep(1);

    }
    if (flag == 0)
    {
      Beep(13000, 200);
      gotoxy(x + 22, y + 28);color(12);
      printf("Usuario invalido");
      intentos++;
      gotoxy(x + 39, y + 28);
      printf("%d%c intento", intentos, 167);color(15);
    }
  } while (intentos < INTENTOS && flag == 0);
  return intentos;
}
void login_Administradores_P(int x, int y)///FUNCION QUE LOGUEA AL ADMINISTRADOR PRINCIPAL
{
  int tipo_admin = 0;
  int intento = 0;
  intento = comprob_Login_Admin_P(x, y);
  validar_Intent_Admin_P(intento, x, y);
}
void login_Administradores_S(int x, int y)///FUNCION QUE LOGUEA AL ADMINISTRADOR SECUNDARIO
{
  int tipo_admin = 0;
  int intento = 0;
  intento = comprob_Login_Admin_S(x, y);
  validar_Intent_Admin_S(intento, x, y);
}
