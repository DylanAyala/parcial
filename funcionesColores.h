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

/** \brief busca el indice en el array de eColores suministrado segun el eAuto suministrado
 *
 * \param array eColores
 * \param int largo de los colores
 * \param eAuto
 * \return retorna indice del color
 *
 */

int indexColor(eColor col[], int lengCol, eAuto aut);

/** \brief muestra todos los colores del array eColores suministrado
 *
 * \param array eCOlores
 * \param int largo de colores
 * \return retorna 0
 *
 */

int showColores(eColor col[], int lengCol);

#endif // FUNCIONESCOLORES_H_INCLUDED
