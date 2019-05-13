#ifndef FUNCIONESCOLORES_H_INCLUDED
#define FUNCIONESCOLORES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define LENGDES 20
#include "funcionesMarca.h"

typedef struct
{

    int id;
    char nombreColor[LENGDES];
} eColor;

int indexColor(eColor col[], int lengCol, eAuto aut);
int showColores(eColor col[], int lengCol);
int validoColor(int id);

#endif // FUNCIONESCOLORES_H_INCLUDED
