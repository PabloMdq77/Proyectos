#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>

#include "puntaje.h"

st_Puntaje ingresar_1_Puntaje()///FUNCION QUE CARGA LOS DATOS EN UNA ESTRUCTURA
{
    st_Puntaje punt;
    punt.numero_De_Nivel=0;
    punt.pasos=0;
    punt.estado_Del_Nivel=0;
    punt.caidas=0;
    punt.intentos=0;
    punt.puntaje_Total=0;
    return punt;
}
void muestra_1_Puntaje(st_Puntaje punt)///FUNCION QUE MUESTRA LOS DATOS DE LA ESTRUCTURA
{
    if(punt.numero_De_Nivel!=-1)
    {
        color(15);
        printf("\n\t   ==================================================");
        printf("\n\t   | N%c de nivel ........ |%25d|",167,punt.numero_De_Nivel);
        printf("\n\t   | Estado del nivel ... |%25d|",punt.estado_Del_Nivel);
        printf("\n\t   | N%c de pasos ........ |%25d|",167,punt.pasos);
        printf("\n\t   | N%c de caidas ....... |%25d|",167,punt.caidas);
        printf("\n\t   | N%c de intentos ..... |%25d|",167,punt.intentos);
        printf("\n\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\t   | Puntaje total ...... |%25d|",punt.puntaje_Total);
        printf("\n\t   ==================================================\n");
        color(15);
    }
    else
    {
        color(12);
        printf("\n\t   ==================================================");
        printf("\n\t   | N%c de nivel ........ |%25d|",167,punt.numero_De_Nivel);
        printf("\n\t   | Estado del nivel ... |%25d|",punt.estado_Del_Nivel);
        printf("\n\t   | N%c de pasos ........ |%25d|",167,punt.pasos);
        printf("\n\t   | N%c de caidas ....... |%25d|",167,punt.caidas);
        printf("\n\t   | N%c de intentos ..... |%25d|",167,punt.intentos);
        printf("\n\t   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\t   | Puntaje total ...... |%25d|",punt.puntaje_Total);
        printf("\n\t   ==================================================\n");
        color(15);
    }
}
lista_Nodo * inicializar_Lista()///FUNCION QUE INICIALIZA UN NODO
{
    return NULL;
}
lista_Nodo * crear_Lista(st_Puntaje punt)///FUNCION QUE CREA UN NUEVO NODO
{
    lista_Nodo * aux=(lista_Nodo*)malloc(sizeof(lista_Nodo));
    aux->dato_Punt=punt;
    aux->next_Nodo=NULL;
    return aux;
}
lista_Nodo * buscar_Lista(lista_Nodo * lista, int dato)///FUNCION QUE BUSCA UN NODO EN LA LISTA
{
    lista_Nodo * aux=lista;
    if(aux && aux->dato_Punt.numero_De_Nivel!=dato)
    {
        aux=aux->next_Nodo;
    }
    return aux;
}
lista_Nodo * buscar_Ultima(lista_Nodo * lista)///FUNCION QUE BUSCA EL ULTIMO NODO PARA USARLO EN LA FUNCION DE AGREGAR AL FINAL
{
    lista_Nodo * ultimo=lista;
    if(ultimo!=NULL)
    {
        while(ultimo->next_Nodo!=NULL)
        {
            ultimo=ultimo->next_Nodo;
        }
    }
    return ultimo;
}
lista_Nodo * agregar_Al_Final(lista_Nodo * lista,lista_Nodo * nuevo)///FUNCION QUE AGREGA AL FINAL DE LA LISTA UN NODO
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        lista_Nodo * ultimo=buscar_Ultima(lista);
        ultimo->next_Nodo=nuevo;
    }
    return lista;
}
lista_Nodo * borrar_Lista(lista_Nodo * lista, int nivel)///FUNCION QUE QUE BORRA UN NODO DE LA LISTA
{
    lista_Nodo * seg;
    lista_Nodo * ante;
    if((lista != NULL) && (nivel == lista->dato_Punt.numero_De_Nivel))
    {
        lista_Nodo * aux = lista;
        lista = lista->next_Nodo;
        free(aux);
    }
    else
    {
        seg = lista;
        while((seg != NULL) && (nivel != lista->dato_Punt.numero_De_Nivel))
        {
            ante = seg;
            seg = seg->next_Nodo;
        }
        if(seg!=NULL)
        {
            ante->next_Nodo = seg->next_Nodo;
            free(seg);
        }
    }
    return lista;
}
lista_Nodo * borrado_Total(lista_Nodo * lista)///FUNCION QUE BORRA TODOS LOS NODOS DE LA LISTA
{
    lista_Nodo * prox;
    lista_Nodo * seg=lista;
    while(seg != NULL)
    {
        prox=seg->next_Nodo;
        free(seg);
        seg=prox;
    }
    return seg;
}
lista_Nodo * resetar(lista_Nodo * lista)///FUNCION QUE RESETEA LOS DATOS DEL NODO PARA DARLES UNA ALTA LOGICA
{
    lista->dato_Punt.numero_De_Nivel=0;
    lista->dato_Punt.pasos=0;
    lista->dato_Punt.estado_Del_Nivel=0;
    lista->dato_Punt.caidas=0;
    lista->dato_Punt.intentos=0;
    lista->dato_Punt.puntaje_Total=0;
    return lista;
}
lista_Nodo * anular(lista_Nodo * lista)///FUNCION QUE ANULA LOS DATOS DEL NODO PARA DARLES UNA BAJA LOGICA
{

    lista->dato_Punt.numero_De_Nivel=-1;
    lista->dato_Punt.pasos=-1;
    lista->dato_Punt.estado_Del_Nivel=-1;
    lista->dato_Punt.caidas=-1;
    lista->dato_Punt.intentos=-1;
    lista->dato_Punt.puntaje_Total=-1;
    return lista;
}
void muestra_N_Puntaje(lista_Nodo * lista)///FUNCION QUE MUESTRA UN NODO
{
    lista_Nodo * aux=lista;
    if(lista)
    {
        muestra_1_Puntaje(aux->dato_Punt);
    }
}
void recorre_Y_Muestra(lista_Nodo * lista)///FUNCION QUE RECORRE Y MUESTRA UN NODO
{
    lista_Nodo * aux=lista;
    if(lista)
    {
        muestra_1_Puntaje(aux->dato_Punt);
        aux=aux->next_Nodo;
    }
}
