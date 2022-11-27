#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "puntaje.h"
#include "usuario.h"
#include "archivo.h"
#include "menu.h"

#define ARCHIVO"registro_Alegory.bin"

st_Archivo_Juego get_Archivo(st_Usuario user,st_Puntaje punt)///FUNCION QUE COPIA LOS DATOS DE LAS SUB ESTRUCTURAS PARA UNIRLAS EN LA ESTRUCTURA DEL ARCHIVO
{
    st_Archivo_Juego arc;

    ///ESTRUCTURA USUARIO

    strcpy(arc.apellido,user.apellido);
    strcpy(arc.nombre,user.nombre);
    arc.dni=user.dni;
    strcpy(arc.correo,user.correo);
    strcpy(arc.username,user.dato_Log.username);
    strcpy(arc.password,user.dato_Log.password);

    ///ESTRUCTURA PUNTAJE
    arc.numero_De_Nivel=punt.numero_De_Nivel;
    arc.estado_Del_Nivel=punt.estado_Del_Nivel;
    arc.pasos=punt.pasos;
    arc.caidas=punt.caidas;
    arc.intentos=punt.intentos;
    arc.puntaje_Total=punt.puntaje_Total;

    return arc;
}
st_Usuario get_Usuario(st_Archivo_Juego arc)///FUNCION QUE COPIA LOS DATOS  DE LA ESTRUCTURA DEL ARCHIVO PARA SEPARARLA EN SUB ESTRUCTURAS
{
    st_Usuario user;
    strcpy(user.nombre,arc.nombre);
    strcpy(user.apellido,arc.apellido);
    strcpy(user.correo,arc.correo);
    user.dni=arc.dni;
    user.eliminado=arc.eliminado;
    strcpy(user.dato_Log.username,arc.username);
    strcpy(user.dato_Log.password,arc.password);
    return user;
}
st_Puntaje get_Puntaje(st_Archivo_Juego arc)///FUNCION QUE COPIA LOS DATOS  DE LA ESTRUCTURA DEL ARCHIVO PARA SEPARARLA EN SUB ESTRUCTURAS
{
    st_Puntaje punt;
    punt.numero_De_Nivel=arc.numero_De_Nivel;
    punt.estado_Del_Nivel=arc.estado_Del_Nivel;
    punt.pasos=arc.pasos;
    punt.caidas=arc.caidas;
    punt.intentos=arc.intentos;
    punt.puntaje_Total=arc.puntaje_Total;
    return punt;
}
void cargar_To_Modificacion(celda_Array adl[],int val, char archivo[])///FUNCION QUE GUARDA EN UN ARCHIVO LAS MODIFICADIONES REALIZADAS EN EL ARREGLO DE LISTAS
{
    int iter=0;
    st_Archivo_Juego arc;
    lista_Nodo * aux;
    FILE * buffer = fopen(archivo,"r+b");
    if(buffer)
    {
        while(iter<val)
        {
            aux=adl[iter].puntaje;
            strcpy(arc.apellido,adl[iter].dato_User.apellido);
            strcpy(arc.nombre,adl[iter].dato_User.nombre);
            arc.dni=adl[iter].dato_User.dni;
            strcpy(arc.correo,adl[iter].dato_User.correo);
            strcpy(arc.username,adl[iter].dato_User.dato_Log.username);
            strcpy(arc.password,adl[iter].dato_User.dato_Log.password);
            arc.eliminado=adl[iter].dato_User.eliminado;

            while(aux)
            {
                arc.numero_De_Nivel=aux->dato_Punt.numero_De_Nivel;
                arc.estado_Del_Nivel=aux->dato_Punt.estado_Del_Nivel;
                arc.pasos=aux->dato_Punt.pasos;
                arc.caidas=aux->dato_Punt.caidas;
                arc.intentos=aux->dato_Punt.intentos;
                arc.puntaje_Total=aux->dato_Punt.puntaje_Total;
                aux=aux->next_Nodo;
            }
            fwrite(&arc,sizeof(st_Archivo_Juego),1,buffer);
            iter++;
        }
        fclose(buffer);
    }
}
void cargar_To_Archivo(celda_Array adl[],int val, char archivo[])///FUNCION QUE GUARDA LA CARGA DE USUARIOS DE UN ARREGLO DE LISTA EN UN ARCHIVO
{
    int iter=0;
    st_Archivo_Juego arc;
    lista_Nodo * aux;
    FILE * buffer = fopen(archivo,"ab");
    if(buffer)
    {
        while(iter<val)
        {
            aux=adl[iter].puntaje;
            strcpy(arc.apellido,adl[iter].dato_User.apellido);
            strcpy(arc.nombre,adl[iter].dato_User.nombre);
            arc.dni=adl[iter].dato_User.dni;
            strcpy(arc.correo,adl[iter].dato_User.correo);
            strcpy(arc.username,adl[iter].dato_User.dato_Log.username);
            strcpy(arc.password,adl[iter].dato_User.dato_Log.password);
            arc.eliminado=adl[iter].dato_User.eliminado;

            while(aux)
            {
                arc.numero_De_Nivel=aux->dato_Punt.numero_De_Nivel;
                arc.estado_Del_Nivel=aux->dato_Punt.estado_Del_Nivel;
                arc.pasos=aux->dato_Punt.pasos;
                arc.caidas=aux->dato_Punt.caidas;
                arc.intentos=aux->dato_Punt.intentos;
                arc.puntaje_Total=aux->dato_Punt.puntaje_Total;
                aux=aux->next_Nodo;
            }
            fwrite(&arc,sizeof(st_Archivo_Juego),1,buffer);
            iter++;
        }
        fclose(buffer);
    }
}
int cargar_To_Adl(celda_Array adl[],int dim,char archivo[])///FUNCION QUE PASA LOS DATOS DEL ARCHIVO AL ARREGLO DE LISTAS
{
    FILE * buffer = fopen (archivo,"rb");
    st_Archivo_Juego arc;
    int val=0;
    if(buffer)
    {
        while(val<dim&&fread(&arc,sizeof(st_Archivo_Juego),1,buffer)>0)
        {
            val=alta(adl,val,get_Usuario(arc),get_Puntaje(arc));
        }
        fclose(buffer);
    }
    return val;
}
st_Archivo_Juego buscar_Usuario(char archi[],char username[])///FUNCION QUE BUSCA EN EL ARCHIVO UN DATO PARA VALIDARLO
{
    int flag=0;
    st_Archivo_Juego aux;
    st_Archivo_Juego encontrado;
    FILE*buffer=fopen(archi,"rb");
    if(buffer)
    {
        while(fread(&aux,sizeof(st_Archivo_Juego),1,buffer)>0)
        {
            if(strcmpi(aux.username,username)==0)
            {
                encontrado=aux;
            }
        }
        fclose(buffer);
    }
    return encontrado;
}
