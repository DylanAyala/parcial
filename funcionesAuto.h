#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funcionesMarca.h"
#include "funcionesColores.h"
#include "validaciones.h"
#define LENGPATENTE 7

int initAutos(eAuto aut[], int leng);
int addAuto(eAuto aut[],char patente[], int lugar, int id, int idMarca, int idColor, int modelo);
void printAuto(eAuto aut, eColor col[], int indexCol, eMarca mar[], int indexMar);
int validarIDAuto(eAuto aut[], int lengAuto, int id);
int removeAuto(eAuto aut[], int index);
int findLugar(eAuto aut[], int lenAuto);
int showAutos(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor);
int modificacionAuto(eAuto aut[], int lengAut, eColor col[], int lengCol, eMarca mar[], int lengMar);
int indexPatente(char pantente[], eAuto aut[], int lengAut);
