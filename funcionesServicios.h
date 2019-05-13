#ifndef FUNCIONESSERVICIOS_H_INCLUDED
#define FUNCIONESSERVICIOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define LENGSERVICIO 25

typedef struct
{
    int id;
    char descripcion[LENGSERVICIO];
    float precio;

} eServicio;

int showServicio(eServicio ser[], int lengSer);
int validarServicio(eServicio ser[], int lengSer, int id);
int indexServicio(eServicio ser[], int lengSer, int id);


#endif // FUNCIONESSERVICIOS_H_INCLUDED
