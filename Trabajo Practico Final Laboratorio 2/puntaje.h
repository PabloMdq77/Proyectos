#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED

typedef struct// st_Puntaje
{
    int pasos;
    int caidas;
    int intentos;
    int puntaje_Total;
    int numero_De_Nivel;
    int estado_Del_Nivel;

}st_Puntaje;
typedef struct // lista_Nodo
{
    st_Puntaje dato_Punt;
    struct lista_Nodo * next_Nodo;

}lista_Nodo;

lista_Nodo * agregar_Al_Final(lista_Nodo * lista,lista_Nodo * nuevo);///FUNCION QUE AGREGA AL FINAL DE LA LISTA UN NODO
lista_Nodo * borrado_Total(lista_Nodo * lista);///FUNCION QUE BORRA TODOS LOS NODOS DE LA LISTA
lista_Nodo * borrar_Lista(lista_Nodo * lista, int nivel);///FUNCION QUE QUE BORRA UN NODO DE LA LISTA
lista_Nodo * buscar_Lista(lista_Nodo * lista, int dato);///FUNCION QUE BUSCA UN NODO EN LA LISTA
lista_Nodo * buscar_Ultima(lista_Nodo * lista);///FUNCION QUE BUSCA EL ULTIMO NODO PARA USARLO EN LA FUNCION DE AGREGAR AL FINAL
lista_Nodo * crear_Lista(st_Puntaje punt);///FUNCION QUE CREA UN NUEVO NODO
lista_Nodo * inicializar_Lista();///FUNCION QUE INICIALIZA UN NODO
lista_Nodo * anular(lista_Nodo * lista);///FUNCION QUE ANULA LOS DATOS DEL NODO PARA DARLES UNA BAJA LOGICA
lista_Nodo * resetar(lista_Nodo * lista);///FUNCION QUE RESETEA LOS DATOS DEL NODO PARA DARLES UNA ALTA LOGICA
st_Puntaje ingresar_1_Puntaje();///FUNCION QUE CARGA LOS DATOS EN UNA ESTRUCTURA
void muestra_1_Puntaje(st_Puntaje punt);///FUNCION QUE MUESTRA LOS DATOS DE LA ESTRUCTURA
void muestra_N_Puntaje(lista_Nodo * lista);///FUNCION QUE MUESTRA UN NODO
void recorre_Y_Muestra(lista_Nodo * lista);///FUNCION QUE RECORRE Y MUESTRA UN NODO

#endif // PUNTAJE_H_INCLUDED
