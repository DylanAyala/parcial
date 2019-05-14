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

/** \brief muestra todos los elementes del array eServicion suministrado
 *
 * \param array eServicios
 * \param int largo del array
 * \return retorna 0
 *
 */

int showServicio(eServicio ser[], int lengSer);

/** \brief valida que el id del servicios ingresado se encuentre en el array servicio suministrado
 *
 * \param array eServicio
 * \param int largo servicio
 * \param int id
 * \return retorna el id
 *
 */

int validarServicio(eServicio ser[], int lengSer, int id);

/** \brief busca el indice en el array eServicio con el id ingresado
 *
 * \param array eServicion
 * \param int largo del array
 * \param int id
 * \return retorna el indice
 *
 */

int indexServicio(eServicio ser[], int lengSer, int id);


#endif // FUNCIONESSERVICIOS_H_INCLUDED
