#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct // stLoggin
{
    char username[30];
    char password[30];

} st_Login_User;
typedef struct // st_Usuario
{
    st_Login_User dato_Log;
    char nombre[30];
    char apellido[30];
    char correo[30];
    int dni;
    int eliminado;
} st_Usuario;
typedef struct // celda_Nodo
{
    st_Usuario dato_User;
    struct lista_Nodo * puntaje;
} celda_Array;

int agregar_Usuario(celda_Array adl[],int val,st_Usuario user);///FUNCION QUE AGREGA UN USUARIO SI ESTE NO EXISTE
int alta(celda_Array adl[],int val,st_Usuario user,st_Puntaje punt);///FUNCION DE ALTA QUE DA DE ALTA LOS DATOS EN UN ARREGLO DE LISTAS
int alta_Usuario(celda_Array adl[],int val);///FUNCION QUE DA DE BAJA DE MANERA LOGICA A UN USUARIO Y SU PUNTAJE
int baja_Usuario(celda_Array adl[],int val);///FUNCION QUE DA DE ALTA DE MANERA LOGICA A UN USUARIO Y SU PUNTAJE
int buscar_Pos(celda_Array adl[],int val,int dni);///FUNCION QUE BUSCA LA POSIDION DE UN DATO DETERMINADO EN UN ARREGLO
int cargar_Adl(celda_Array adl[],int dim,int val,int x,int y);///FUNCION QUE CARGA VARIOS USUARIOS CON SUS PUNTAJES INICIALIZADOS EN CERO EN UN ARREGLO DE LISTA
int comp_Usuario(int x,int y);///FUNCION QUE COMPRUEBA EL LOGIN DEL USUARIO
int registrarse(celda_Array adl[],int dim,int val,int x,int y);///FUNCION QUE CARGA UN USUARIO CON SUS PUNTAJES INICIALIZADOS EN CERO EN UN ARREGLO DE LISTA
int validar_Usuario(char archi[],char username[],char password[]);///FUNCION QUE VALIDA EL LOGIN DEL USUARIO
int validarDatoArch(char archi[],char dato[],int x, int y);///FUNCION QUE VALIDA LOS DATOS BUSCADOS EN UN ARCHIVO
st_Usuario ingresar_1_Usuario();///FUNCION QUE LOS DATOS EN UNA ESTRUCTURA VALIDANDO UN DATO EN EL ARCHIVO
void buscar_Mostrar(celda_Array adl[],int val);///FUNCION QUE BUSCA UN USUARIO EN EL ARCHIVO PARA VALIDARLO
void cargaPass_User (char * clave,int x,int y);///FUNCION QUE CARGA EL PASSWORD DEL USUARIO OCULTANDO LOS DATOS MOSTRANDO ASTERISCOS
void cargaUser_User(char * dato,int x,int y );///FUNCION QUE CARGA EL USERNAME DEL USUARIO
void login_Usuario(int x,int y);///FUNCION QUE LOGUEA AL USUARIO
void modificar_Apellido(celda_Array adl[],int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL APELLIDO DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Caidas(celda_Array adl[],lista_Nodo * lista,int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA LAS CAIDAS DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Correo(celda_Array adl[],int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL CORREO DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Dni(celda_Array adl[],int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL DNI DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Estado_del_Nivel(celda_Array adl[],lista_Nodo * lista,int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL ESTADO DEL NIVEL DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Intentos(celda_Array adl[],lista_Nodo * lista,int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NUMERO DE INTENTOS DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Nombre(celda_Array adl[],int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NOMBRE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Numero_de_nivel(celda_Array adl[],lista_Nodo * lista,int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NUMERO DE NIVEL DEL PUNTAJEDEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Pasos(celda_Array adl[],lista_Nodo * lista,int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NUMERO DE PASOS DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Password(celda_Array adl[],int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL PASSWORD DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Puntaje_Total(celda_Array adl[],lista_Nodo * lista,int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL PUNTAJE TOTAL DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void modificar_Username(celda_Array adl[],int val);///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL USERNAME DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
void muestra_1_Usuario(st_Usuario user);///FUNCION QUE MUESTRA UN USUARIO
void muestra_A_Usuario(celda_Array celda);///FUNCION QUE UNE EN UNA FUNCION LAS FUNCIONES DE MOSTRAR UN USUARIO Y MOSTRAR Y RECORRER UN NODO
void muestra_Validacion(int flag);///FUNCION QUE MUESTRA SI UN USUARIO ESTA REPETIDO O NO
void recorre_Y_Muestra_Adl(celda_Array adl[],int val);///FUNCION QUE RECORRE Y MUESTRA UN ARREGLO DE LISTAS
void valid_Intent_User(int intentos,int x,int y);///FUNCION QUE VALIDA LOS INTENTOS DEL USUARIO AL INICIAR SESION

#endif // USUARIO_H_INCLUDED

