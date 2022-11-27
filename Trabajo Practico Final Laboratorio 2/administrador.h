#ifndef ADMINISTRADOR_H_INCLUDED
#define ADMINISTRADOR_H_INCLUDED

typedef struct //st_Login_Admin
{
    char usuario[30];
    char password[30];

} st_Login_Admin;

int comprob_Login_Admin_P(int x, int y);///FUNCION QUE COMPRUEBA EL LOGIN DEL ADMINISTRADOR SECUNDARIO
int comprob_Login_Admin_S(int x, int y);///FUNCION QUE COMPRUEBA EL LOGIN DEL ADMINISTRADOR PRINCIPAL
int validar_Login_Admin_P(char user[], char pass[]);///FUNCION QUE VALIDA EL LOGIN DEL ADMINISTRADOR SECUNDARIO
int validar_Login_Admin_S(char pass[], char user[]);///FUNCION QUE VALIDA EL LOGIN DEL ADMINISTRADOR PRINCIPAL
void cargaPass_Admin(char * clave, int x, int y);///FUNCION QUE CARGA EL PASSWORD DEL ADMINISTRADOR OCULTANDO LOS DATOS MOSTRANDO ASTERISCOS
void cargaUser_Admin(char * dato, int x, int y);///FUNCION QUE CARGA EL USERNAME DEL ADMINISTRADOR
void login_Administradores_P(int x, int y);///FUNCION QUE LOGUEA AL ADMINISTRADOR PRINCIPAL
void login_Administradores_S(int x, int y);///FUNCION QUE LOGUEA AL ADMINISTRADOR SECUNDARIO
void validar_Intent_Admin_P(int intentos, int x, int y);///FUNCION QUE VALIDA LOS INTENTOS DEL ADMINISTRADOR PRINCIPAL AL INICIAR SESION
void validar_Intent_Admin_S(int intentos, int x, int y);///FUNCION QUE VALIDA LOS INTENTOS DEL ADMINISTRADOR SECUNDARIO AL INICIAR SESION

#endif // ADMINISTRADOR_H_INCLUDED
