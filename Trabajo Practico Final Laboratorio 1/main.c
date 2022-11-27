#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "estetica.h"
#include "clientes.h"
#include "menu.h"
#include "consumos.h"


#define CLIENTE"Clientes.dat"
#define CONSUMO"Consumos.dat"

#define PRECIOMB 0.32
#define MANTENIMIENTO 150

#define DIM 1000

int main()
{
   // system ("mode con cols=53 lines=60");


    fijado(50,1,45,46);
    bannerBienvenida();
    menu_Principal();



    return 0;
}

