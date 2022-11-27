#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "administrador.h"
#include "puntaje.h"
#include "usuario.h"
#include "archivo.h"
#include <windows.h>
#include "gotoxy.h"

#define LIMITE 9
#define INTENTOS 3
#define ARCHIVO"registro_Alegory.bin"
#define DIM 100

st_Usuario ingresar_1_Usuario()///FUNCION QUE CARGA LOS DATOS EN UNA ESTRUCTURA
{
    st_Usuario user;
    printf("\n\tIngresar el nombre .......... : ");
    fflush(stdin);
    gets(user.nombre);
    printf("\tIngresar el apellido ........ : ");
    fflush(stdin);
    gets(user.apellido);

    strcpy(user.correo,user.apellido);
    strcat(user.correo,"_alegory@game.net");

    printf("\tIngresar el dni ............. : ");
    fflush(stdin);
    scanf("%d",&user.dni);
    char username[30];

    int flag;
    char usuario_C[30];
    do
    {

        printf("\tIngrese su username ......... : ");
        fflush(stdin);
        gets(usuario_C);
        flag=validarDatoArch(ARCHIVO,usuario_C,1,1);
        muestra_Validacion(flag);
    }
    while(flag==1);
    strcpy(user.dato_Log.username,usuario_C);
    printf("\tIngrese su password ......... : ");
    fflush(stdin);
    int i = 0;

    char caracter;
    char clave[30];

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
    strcpy(user.dato_Log.password, clave);
    printf("\n\tIngresar el 0 Alta 1 Baja ... : ");
    fflush(stdin);
    scanf("%d",&user.eliminado);


    return user;
}
void muestra_1_Usuario(st_Usuario user)///FUNCION QUE MUESTRA UN USUARIO
{

    if(user.eliminado==0)
    {
        color(15);
        printf("\n\t   ==================================================");
        printf("\n\t   | Apellido ........... |%25s|",user.apellido);
        printf("\n\t   | Nombre ............. |%25s|",user.nombre);
        printf("\n\t   | Correo ............. |%25s|",user.correo);
        printf("\n\t   | Dni ................ |%25d|",user.dni);
        printf("\n\t   | Eliminado .......... |                       NO|");
        printf("\n\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\t   | Username ........... |%25s|",user.dato_Log.username);
        printf("\n\t   | Password ........... |%25s|",user.dato_Log.password);
        printf("\n\t   ==================================================");
        color(15);
    }
    else
    {
        color(12);
        printf("\n\t   ==================================================");
        printf("\n\t   | Apellido ........... |%25s|",user.apellido);
        printf("\n\t   | Nombre ............. |%25s|",user.nombre);
        printf("\n\t   | Correo ............. |%25s|",user.correo);
        printf("\n\t   | Dni ................ |%25d|",user.dni);
        printf("\n\t   | Eliminado .......... |                       SI|");
        printf("\n\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\t   | Username ........... |%25s|",user.dato_Log.username);
        printf("\n\t   | Password ........... |%25s|",user.dato_Log.password);
        printf("\n\t   ==================================================");
        color(15);
    }
}
void muestra_A_Usuario(celda_Array celda)///FUNCION QUE UNE EN UNA FUNCION LAS FUNCIONES DE MOSTRAR UN USUARIO Y MOSTRAR Y RECORRER UN NODO
{
    muestra_1_Usuario(celda.dato_User);
    recorre_Y_Muestra(celda.puntaje);
}
void recorre_Y_Muestra_Adl(celda_Array adl[],int val)///FUNCION QUE RECORRE Y MUESTRA UN ARREGLO DE LISTAS
{
    gotoxy(6,32);
    for(int iter=0; iter<val; iter++)
    {
        muestra_A_Usuario(adl[iter]);
    }
}
int buscar_Pos(celda_Array adl[],int val,int dni)///FUNCION QUE BUSCA LA POSIDION DE UN DATO DETERMINADO EN UN ARREGLO
{
    int pos=-1;
    int iter=0;
    while(iter<val && pos==-1)
    {
        if(adl[iter].dato_User.dni==dni)
        {
            pos=iter;
        }
        iter++;
    }
    return pos;
}
int agregar_Usuario(celda_Array adl[],int val,st_Usuario user)///FUNCION QUE AGREGA UN USUARIO SI ESTE NO EXISTE
{
    adl[val].dato_User=user;
    adl[val].puntaje=inicializar_Lista();
    val++;
return val;
}
int alta(celda_Array adl[],int val,st_Usuario user,st_Puntaje punt)///FUNCION DE ALTA QUE DA DE ALTA LOS DATOS EN UN ARREGLO DE LISTAS
{
    int pos = buscar_Pos(adl,val,user.dni);
    if(pos==-1)
    {
        val=agregar_Usuario(adl,val,user);
        pos=val-1;
    }
    adl[pos].puntaje=agregar_Al_Final(adl[pos].puntaje,crear_Lista(punt));

    return val;
}
int registrarse(celda_Array adl[],int dim,int val,int x,int y)///FUNCION QUE CARGA UN USUARIO CON SUS PUNTAJES INICIALIZADOS EN CERO EN UN ARREGLO DE LISTA
{
    st_Usuario user;
    st_Puntaje punt;
    char opcion=0;
    user=ingresar_1_Usuario();
    punt=ingresar_1_Puntaje();
    val=alta(adl,val,user,punt);
    return val;
}
int cargar_Adl(celda_Array adl[],int dim,int val,int x,int y)///FUNCION QUE CARGA VARIOS USUARIOS CON SUS PUNTAJES INICIALIZADOS EN CERO EN UN ARREGLO DE LISTA
{

    st_Usuario user;
    st_Puntaje punt;
    char opcion=0;

    while(opcion!=27 && val<dim)
    {
        user=ingresar_1_Usuario();
        punt=ingresar_1_Puntaje();
        val=alta(adl,val,user,punt);
        printf("\n\tPress ESC para salir");
        fflush(stdin);
        opcion=getch();

    }

    return val;
}
void modificar_Apellido(celda_Array adl[],int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL APELLIDO DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    int pos;
    int dni;
    {
        val=cargar_To_Adl(adl,DIM,ARCHIVO);
        printf("\nIngrese el documento que desea buscar ... : ");
        fflush(stdin);
        scanf("%d",&dni);
        pos = buscar_Pos(adl,val,dni);
        printf("\nEl apellido de la persona a modificar es %s ", adl[pos].dato_User.apellido);
        muestra_1_Usuario(adl[pos].dato_User);
        printf("\nIngrese el nuevo apellido ................. : ");
        fflush(stdin);
        gets(adl[pos].dato_User.apellido);
        muestra_1_Usuario(adl[pos].dato_User);
        cargar_To_Modificacion(adl,val,ARCHIVO);
    }

}
void modificar_Nombre(celda_Array adl[],int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NOMBRE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    int pos;
    int dni;
    {
        val=cargar_To_Adl(adl,DIM,ARCHIVO);
        printf("\nIngrese el documento que desea buscar ... : ");
        fflush(stdin);
        scanf("%d",&dni);
        pos = buscar_Pos(adl,val,dni);
        printf("\nEl Nombre de la persona a modificar es %s ", adl[pos].dato_User.nombre);
        muestra_1_Usuario(adl[pos].dato_User);
        printf("\nIngrese el nuevo nombre ................. : ");
        fflush(stdin);
        gets(adl[pos].dato_User.nombre);
        muestra_1_Usuario(adl[pos].dato_User);
        cargar_To_Modificacion(adl,val,ARCHIVO);
    }

}
void modificar_Correo(celda_Array adl[],int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL CORREO DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    int pos;
    int dni;
    {
        val=cargar_To_Adl(adl,DIM,ARCHIVO);
        printf("\nIngrese el documento que desea buscar ... : ");
        fflush(stdin);
        scanf("%d",&dni);
        pos = buscar_Pos(adl,val,dni);
        printf("\nEl correo de la persona a modificar es %s ", adl[pos].dato_User.correo);
        muestra_1_Usuario(adl[pos].dato_User);
        printf("\nIngrese el nuevo correo ................. : ");
        fflush(stdin);
        gets(adl[pos].dato_User.correo);
        muestra_1_Usuario(adl[pos].dato_User);
        cargar_To_Modificacion(adl,val,ARCHIVO);
    }

}
void modificar_Dni(celda_Array adl[],int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL DNI DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    int pos;
    int dni;
    {
        val=cargar_To_Adl(adl,DIM,ARCHIVO);
        printf("\nIngrese el documento que desea buscar ... : ");
        fflush(stdin);
        scanf("%d",&dni);
        pos = buscar_Pos(adl,val,dni);
        printf("\nEl dni de la persona a modificar es %d ", adl[pos].dato_User.dni);
        muestra_1_Usuario(adl[pos].dato_User);
        printf("\nIngrese el nuevo dni ................. : ");
        fflush(stdin);
        scanf("%d",&adl[pos].dato_User.dni);
        muestra_1_Usuario(adl[pos].dato_User);
        cargar_To_Modificacion(adl,val,ARCHIVO);
    }

}
void modificar_Username(celda_Array adl[],int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL USERNAME DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    int pos;
    int comp;
    char usuario_C[30];
    int dni;
    {
        val=cargar_To_Adl(adl,DIM,ARCHIVO);
        printf("\nIngrese el documento que desea buscar ... : ");
        fflush(stdin);
        scanf("%d",&dni);
        pos = buscar_Pos(adl,val,dni);
        printf("\nEl username de la persona a modificar es %s ", adl[pos].dato_User.dato_Log.username);
        muestra_1_Usuario(adl[pos].dato_User);
            printf("\n");

        do
        {
            printf("Ingrese el nuevo username ................. : ");
            fflush(stdin);

            gets(usuario_C);
            comp=validarDatoArch(ARCHIVO,usuario_C,1,1);
            muestra_Validacion(comp);
        }
        while(comp==1);
        strcpy(adl[pos].dato_User.dato_Log.username,usuario_C);
        muestra_1_Usuario(adl[pos].dato_User);
        cargar_To_Modificacion(adl,val,ARCHIVO);
    }

}
void modificar_Password(celda_Array adl[],int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL PASSWORD DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    int pos;
    int i = 0;
    int dni;
    char caracter;
    char clave[30];
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    fflush(stdin);
    scanf("%d",&dni);
    pos = buscar_Pos(adl,val,dni);
    printf("\nEl password de la persona a modificar es %s ", adl[pos].dato_User.dato_Log.password);
    muestra_1_Usuario(adl[pos].dato_User);
    printf("\nIngrese el nuevo password ................. : ");
    fflush(stdin);
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
    strcpy(adl[pos].dato_User.dato_Log.password, clave);
    muestra_1_Usuario(adl[pos].dato_User);
    cargar_To_Modificacion(adl,val,ARCHIVO);
}
void modificar_Caidas(celda_Array adl[],lista_Nodo * lista,int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA LAS CAIDAS DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    lista_Nodo * aux=lista;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido de la persona a encontrada es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    aux=adl[pos].puntaje;

    printf("\nIngrese el Nivel a buscar ... : ");
    scanf("%d", &nivel);
    aux = buscar_Lista(aux,nivel);

    printf("\nEl puntaje del usuario encontrado es");
    muestra_1_Puntaje(aux->dato_Punt);
    printf("\nIngrese el nuevo nro de caidas ................. : ");
    scanf("%d", &aux->dato_Punt.caidas);

    muestra_1_Puntaje(aux->dato_Punt);
    cargar_To_Modificacion(adl,val,ARCHIVO);
}
void modificar_Intentos(celda_Array adl[],lista_Nodo * lista,int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NUMERO DE INTENTOS DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    lista_Nodo * aux=lista;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido de la persona a encontrada es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    aux=adl[pos].puntaje;

    printf("\nIngrese el Nivel a buscar ... : ");
    scanf("%d", &nivel);
    aux = buscar_Lista(aux,nivel);

    printf("\nEl puntaje del usuario encontrado es");
    muestra_1_Puntaje(aux->dato_Punt);
    printf("\nIngrese el nuevo nro de intentos ................. : ");
    scanf("%d", &aux->dato_Punt.intentos);

    muestra_1_Puntaje(aux->dato_Punt);
    cargar_To_Modificacion(adl,val,ARCHIVO);
}
void modificar_Pasos(celda_Array adl[],lista_Nodo * lista,int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NUMERO DE PASOS DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
    gotoxy(6,32);
    lista_Nodo * aux=lista;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido de la persona a encontrada es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    aux=adl[pos].puntaje;

    printf("\nIngrese el Nivel a buscar ... : ");
    scanf("%d", &nivel);
    aux = buscar_Lista(aux,nivel);

    printf("\nEl puntaje del usuario encontrado es");
    muestra_1_Puntaje(aux->dato_Punt);
    printf("\nIngrese el nuevo nro de pasos ................. : ");
    scanf("%d", &aux->dato_Punt.pasos);

    muestra_1_Puntaje(aux->dato_Punt);
    cargar_To_Modificacion(adl,val,ARCHIVO);
}
void modificar_Puntaje_Total(celda_Array adl[],lista_Nodo * lista,int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL PUNTAJE TOTAL DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
     gotoxy(6,32);
    lista_Nodo * aux=lista;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido de la persona a encontrada es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    aux=adl[pos].puntaje;

    printf("\nIngrese el Nivel a buscar ... : ");
    scanf("%d", &nivel);
    aux = buscar_Lista(aux,nivel);

    printf("\nEl puntaje del usuario encontrado es");
    muestra_1_Puntaje(aux->dato_Punt);
    printf("\nIngrese el nuevo puntaje total ................. : ");
    scanf("%d", &aux->dato_Punt.puntaje_Total);

    muestra_1_Puntaje(aux->dato_Punt);
    cargar_To_Modificacion(adl,val,ARCHIVO);
}
void modificar_Estado_del_Nivel(celda_Array adl[],lista_Nodo * lista,int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL ESTADO DEL NIVEL DEL PUNTAJE DEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
     gotoxy(6,32);
    lista_Nodo * aux=lista;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido de la persona a encontrada es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    aux=adl[pos].puntaje;

    printf("\nIngrese el Nivel a buscar ... : ");
    scanf("%d", &nivel);
    aux = buscar_Lista(aux,nivel);

    printf("\nEl puntaje del usuario encontrado es");
    muestra_1_Puntaje(aux->dato_Punt);
    printf("\nIngrese el nuevo estado del nivel ................. : ");
    scanf("%d", &aux->dato_Punt.estado_Del_Nivel);

    muestra_1_Puntaje(aux->dato_Punt);
    cargar_To_Modificacion(adl,val,ARCHIVO);
}
void modificar_Numero_de_nivel(celda_Array adl[],lista_Nodo * lista,int val)///FUNCION QUE CARGA LOS DATOS EN EL ARREGLO DE LISTAS MODIFICA EL NUMERO DE NIVEL DEL PUNTAJEDEL USUARIO Y LUEGO LO GUARDA EN EL ARCHIVO
{
     gotoxy(6,32);
    lista_Nodo * aux=lista;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido de la persona a encontrada es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    aux=adl[pos].puntaje;

    printf("\nIngrese el Nivel a buscar ... : ");
    scanf("%d", &nivel);
    aux = buscar_Lista(aux,nivel);

    printf("\nEl puntaje del usuario encontrado es");
    muestra_1_Puntaje(aux->dato_Punt);
    printf("\nIngrese el nuevo nro de nivel ................. : ");
    scanf("%d", &aux->dato_Punt.numero_De_Nivel);

    muestra_1_Puntaje(aux->dato_Punt);
    cargar_To_Modificacion(adl,val,ARCHIVO);
}
void cargaUser_User(char * dato,int x,int y )///FUNCION QUE CARGA EL USERNAME DEL USUARIO
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
void cargaPass_User (char * clave,int x,int y)///FUNCION QUE CARGA EL PASSWORD DEL USUARIO OCULTANDO LOS DATOS MOSTRANDO ASTERISCOS
{
    int i = 0;
    char caracter;
    i = 0;
    gotoxy(x+28,y+24);
    printf("                    ");
    gotoxy(x+31,y+24);
    printf("Contrase%ca", 164);
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
int comp_Usuario(int x,int y)///FUNCION QUE COMPRUEBA EL LOGIN DEL USUARIO
{
    st_Login_Admin aux;
    int flag=0;
    int intentos=0;
    do
    {
        cargaUser_User(&aux.usuario,x,y);
        cargaPass_User(&aux.password,x,y);
        flag=validar_Usuario(ARCHIVO,aux.usuario,aux.password);

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
            gotoxy(x + 22, y + 28);
            color(12);
            printf("Usuario invalido");
            intentos++;
            gotoxy(x + 39, y + 28);
            printf("%d%c intento", intentos, 167);
            color(15);
        }
    }
    while(intentos<INTENTOS && flag==0);
    return intentos;
}
void valid_Intent_User(int intentos,int x,int y)///FUNCION QUE VALIDA LOS INTENTOS DEL USUARIO AL INICIAR SESION
{
    if(intentos<=2)
    {
        gotoxy(x + 22, y + 22);
        printf("                             ");
        gotoxy(x + 22, y + 28);
        printf("                             ");
        Sleep(1);
        cargando(x, y);
        menu_Juego(x,y);
    }
    else
    {
        gotoxy(x+21,y+28);
        Beep(13000, 200);
        gotoxy(x+21,y+24);
        color(12);
        printf("Excedio el numero de intentos");
        color(15);
    }
}
void login_Usuario(int x,int y)///FUNCION QUE LOGUEA AL USUARIO
{
    int intento = 0;
    intento= comp_Usuario(x,y);
    valid_Intent_User(intento,x,y);

}
int validarDatoArch(char archi[],char dato[],int x, int y)///FUNCION QUE VALIDA LOS DATOS BUSCADOS EN UN ARCHIVO
{
    int flag=0;
    st_Archivo_Juego aux;
    FILE*buffer=fopen(archi,"rb");
    if(buffer)
    {
        while(fread(&aux,sizeof(st_Archivo_Juego),1,buffer)>0)
        {
            if(strcmpi(aux.username,dato)==0)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    return flag;
}
void muestra_Validacion(int flag)///FUNCION QUE MUESTRA SI UN USUARIO ESTA REPETIDO O NO
{
    if(flag==1)
    {color(12);
        printf("\tUsuario Repetido\n");color(15);
    }
    if(flag==0)
    {color(10);
        printf("\tUsuario inexistente\n");color(15);
    }
}
int validar_Usuario(char archi[],char username[],char password[])///FUNCION QUE VALIDA EL LOGIN DEL USUARIO
{
    int flag=0;
    st_Archivo_Juego aux=buscar_Usuario(ARCHIVO,username);
    if(aux.nombre)
    {
        if(strcmpi(aux.password,password)==0)
        {
            flag=1;
        }
    }
    return flag;
}
int baja_Usuario(celda_Array adl[],int val)///FUNCION QUE DA DE ALTA DE MANERA LOGICA A UN USUARIO Y SU PUNTAJE
{
    gotoxy(6,32);
    st_Puntaje punt;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido del usuario que quiere dar de baja es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    adl[pos].dato_User.eliminado=1;

    punt=ingresar_1_Puntaje();

    adl[pos].puntaje=anular(adl[pos].puntaje);
    muestra_1_Usuario(adl[pos].dato_User);
    cargar_To_Modificacion(adl,val,ARCHIVO);

    return val;
}
int alta_Usuario(celda_Array adl[],int val)///FUNCION QUE DA DE BAJA DE MANERA LOGICA A UN USUARIO Y SU PUNTAJE
{
    gotoxy(6,32);
    st_Puntaje punt;
    int dni;
    int nivel;
    val=cargar_To_Adl(adl,DIM,ARCHIVO);
    printf("\nIngrese el documento que desea buscar ... : ");
    scanf("%d",&dni);
    int pos = buscar_Pos(adl,val,dni);

    printf("\nEl apellido del usuario que quiere dar de alta es %s ", adl[pos].dato_User.apellido);
    muestra_1_Usuario(adl[pos].dato_User);
    adl[pos].dato_User.eliminado=0;

//    muestra_1_Usuario(adl[pos].dato_User);
//    cargar_To_Modificacion(adl,val,ARCHIVO);
punt=ingresar_1_Puntaje();

    adl[pos].puntaje=resetar(adl[pos].puntaje);
    muestra_1_Usuario(adl[pos].dato_User);
    cargar_To_Modificacion(adl,val,ARCHIVO);

    return val;
}
void buscar_Mostrar(celda_Array adl[],int val)///FUNCION QUE BUSCA UN USUARIO EN EL ARCHIVO PARA VALIDARLO
{
    gotoxy(6,32);
    int pos;
    int dni;
    {
        val=cargar_To_Adl(adl,DIM,ARCHIVO);
        printf("\nIngrese el documento que desea buscar ... : ");
        fflush(stdin);
        scanf("%d",&dni);
        pos = buscar_Pos(adl,val,dni);
        printf("\nEl apellido de la persona a buscada es %s ", adl[pos].dato_User.apellido);
        muestra_1_Usuario(adl[pos].dato_User);
    }
}
