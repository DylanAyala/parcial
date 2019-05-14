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
#include "validaciones.h"
#define LENGSEVICIOS 5

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


/** \brief inicializa el array eTrabajos suministrado con 0 en la variable isEmpty
 *
 * \param array eTrabajo
 * \param int largo del array
 * \return retorna 0
 *
 */

int initTrabajos(eTrabajo tra[], int lengTra);

/** \brief agrega un nuevo tranajo en el array eTranajo sumnistrado
 *
 * \param array eTrabajo
 * \param int id
 * \param int index del lugar en el array eTranajo
 * \param char patente
 * \param int id Servicio
 * \param eFecha
 * \return retorna 0
 *
 */

int addTrabajo(eTrabajo tra[],int id,int index, char patente[], int idSer, eFecha fecha);

/** \brief busca en el array eTrabajo un lugar disponible
 *
 * \param array eTrabajo
 * \param int lago del array
 * \return retorna el indice del array eTrabajo
 *
 */

int findLugarTrabajo(eTrabajo tra[], int lengTra);

/** \brief muestra todos los elementos del array eTrabajo suministrado
 *
 * \param array eTrabajo
 * \param int largo del array trabajo
 * \param array eServicion
 * \param int largo del array servicio
 * \return retorna 0
 *
 */

int showTrabajos(eTrabajo tra[], int lengTra, eServicio ser[], int lengSer);

/** \brief muetra por pantalla un eTrabajo
 *
 * \param eTrabajo
 * \param eServicio
 * \return retorna 0
 *
 */

int mostrarTrabajo(eTrabajo tra, eServicio ser);


#endif // FUNCIONESTRABAJO_H_INCLUDED
