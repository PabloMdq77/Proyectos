#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

typedef struct // stArchivo
{
    char username[30];
    char password[30];

    char nombre[30];
    char apellido[30];
    char correo[30];
    int dni;
    int eliminado;

    int pasos;
    int caidas;
    int intentos;
    int numero_De_Nivel;
    int estado_Del_Nivel;
    int puntaje_Total;
} st_Archivo_Juego;

void cargar_To_Modificacion(celda_Array adl[],int val, char archivo[]);///FUNCION QUE GUARDA EN UN ARCHIVO LAS MODIFICADIONES REALIZADAS EN EL ARREGLO DE LISTAS
void cargar_To_Archivo(celda_Array adl[],int val, char archivo[]);///FUNCION QUE GUARDA LA CARGA DE USUARIOS DE UN ARREGLO DE LISTA EN UN ARCHIVO
st_Usuario get_Usuario(st_Archivo_Juego arc);///FUNCION QUE COPIA LOS DATOS  DE LA ESTRUCTURA DEL ARCHIVO PARA SEPARARLA EN SUB ESTRUCTURAS
st_Puntaje get_Puntaje(st_Archivo_Juego arc);///FUNCION QUE COPIA LOS DATOS  DE LA ESTRUCTURA DEL ARCHIVO PARA SEPARARLA EN SUB ESTRUCTURAS
st_Archivo_Juego get_Archivo(st_Usuario user,st_Puntaje punt);///FUNCION QUE COPIA LOS DATOS DE LAS SUB ESTRUCTURAS PARA UNIRLAS EN LA ESTRUCTURA DEL ARCHIVO
int cargar_To_Adl(celda_Array adl[],int dim,char archivo[]);///FUNCION QUE PASA LOS DATOS DEL ARCHIVO AL ARREGLO DE LISTAS
st_Archivo_Juego buscar_Usuario(char archi[],char username[]);///FUNCION QUE BUSCA EN EL ARCHIVO UN DATO PARA VALIDARLO

#endif // ARCHIVO_H_INCLUDED
