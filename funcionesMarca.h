#ifndef FUNCIONESMARCA_H_INCLUDED
#define FUNCIONESMARCA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define LENGDES 20
#define LENGPATENTE 7
typedef struct
{
    int id;
    char descripcion[LENGDES];

} eMarca;

typedef struct
{
    int id;
    char patente[LENGPATENTE];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;

int indexMarca(eMarca mar[], int lengMar, eAuto aut);
int showMarcar(eMarca mar[], int lenMar);


#endif // FUNCIONESMARCA_H_INCLUDED
