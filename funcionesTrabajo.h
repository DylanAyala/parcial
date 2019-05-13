#ifndef FUNCIONESTRABAJO_H_INCLUDED
#define FUNCIONESTRABAJO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funcionesMarca.h"
#include "funcionesServicios.h"
#define LENGSEVICIOS 4

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char patente[LENGPATENTE];
    int idServcion;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

int initTrabajos(eTrabajo tra[], int lengTra);
int addTrabajo(eTrabajo tra[],int id,int index, char patente[], int idSer, eFecha fecha);
int findLugarTrabajo(eTrabajo tra[], int lengTra);
int showTrabajos(eTrabajo tra[], int lengTra, eServicio ser[], int lengSer);
int mostrarTrabajo(eTrabajo tra, eServicio ser);


#endif // FUNCIONESTRABAJO_H_INCLUDED
