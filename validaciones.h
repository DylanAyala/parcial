#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "funcionesAuto.h"

/** \brief valida que el carcter ingresado se 's' o 'n', y en caso de no serlo lo pide nuevamente
 *
 * \param char caracter
 * \param
 * \return retorna el caracter
 *
 */

char validarChar(char character);

/** \brief valida que la patente ingresada no sea igual a una ya ingresada enteriormente
 *
 * \param array eAutos
 * \param int largo del array
 * \param char patente
 * \return retorna el indice del array eAuto
 *
 */

int validoPatente(eAuto aut[], int largAut, char patente[]);

/** \brief valida que el id marca ingresado se encuentre entre 1000 y 1004, en caso de no serlo pide volver a ingresarlo
 *
 * \param int id
 * \param
 * \return retorna el id
 *
 */

int validarMarca(int id);

/** \brief valida que el id color ingresado se encuentre entre 5000 y 1004, en caso de no serlo pide volver a ingresarlo
 *
 * \param int id
 * \param
 * \return retorna el id
 *
 */

int validoColor(int id);

#endif // VALIDACIONES_H_INCLUDED
