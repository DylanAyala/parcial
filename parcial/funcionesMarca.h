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
#define LENGNAME 25

typedef struct{
    int id;
    char nombre[LENGNAME];
    char sexo;

}eCliente;

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
    int idCliente;
    int isEmpty;
} eAuto;

/** \brief busca el indice del array eMarca suministrado segun el eAuto suministrado
 *
 * \param array eMarca
 * \param int largo del array
 * \param eAuto
 * \return indice del array eColores
 *
 */

int indexMarca(eMarca mar[], int lengMar, eAuto aut);

/** \brief muestra todos los elementos del array eMarca suministrado
 *
 * \param array eMarca
 * \param int largo del array
 * \return retorna 0
 *
 */

int showMarcar(eMarca mar[], int lenMar);


#endif // FUNCIONESMARCA_H_INCLUDED
