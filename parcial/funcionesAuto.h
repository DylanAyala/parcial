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


/** \brief inicializa la variable isEmpty en 0
 *
 * \param array eAuto
 * \param int largo del arrar
 * \return return 0
 *
 */

int initAutos(eAuto aut[], int leng);

/** \brief agregar un nuevo auto en el array suministrado
 *
 * \param array eAutos
 * \param cadena de caracteres patente
 * \param int indice del lugar en el array autos
 * \param int id del nuevo auto
 * \param int id de la marca
 * \param int id del color
 * \param int modelo
 * \return retorna 1 si logro agregarlo correctamente y -1 si fue cancelado
 *
 */

int addAuto(eAuto aut[],char patente[], int lugar, int id, int idMarca, int idColor, int modelo, int idCliente);

/** \brief imprime por pantalla un auto
 *
 * \param eAuto a imprimir
 * \param array eColores
 * \param int indice del color
 * \param array eMarca
 * \param int indice de la marca
 * \return
 *
 */

void printAuto(eAuto aut, eColor col[],int indexCol, eMarca mar[],int indexMar, eCliente cli[], int indexCliente);

/** \brief valida si el id se encuentra en el array de eAutos suministrado
 *
 * \param array eAutos
 * \param int largo del array
 * \param int id a verificar
 * \return indice del array
 *
 */

int validarIDAuto(eAuto aut[], int lengAuto, int id);

/** \brief cambia el valor de la variable isEmpty a 0
 *
 * \param array eAutos
 * \param indice del lugar del array
 * \return retorna 0
 *
 */

int removeAuto(eAuto aut[], int index);

/** \brief busca en el array suministrado lugares disponibles
 *
 * \param array eAutos
 * \param int largo de array
 * \return retorna indice del array
 *
 */

int findLugar(eAuto aut[], int lenAuto);

/** \brief muestra todo los elementos del array eAutos suministrado
 *
 * \param array eAutos
 * \param int largo de array
 * \param array eMarcas
 * \param int largo array marcas
 * \param array eColores
 * \param int largo del array colores
 * \return retorna 0
 *
 */

int showAutos(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor, eCliente cli[], int lengCli);

/** \brief modifica el color y modelo del auto suministrado
 *
 * \param array eAutos
 * \param int largo del array aAuto
 * \param array eColores
 * \param int largo array colores
 * \param array eMarca
 * \param int largo array marcas
 * \return retorna 0
 *
 */

int modificacionAuto(eAuto aut[], int lengAut, eColor col[], int lengCol, eMarca mar[], int lengMar, eCliente cli[], int lengCli);

/** \brief busca el indice en el array de eAutos con la patente buscada
 *
 * \param cadena de caracteres
 * \param array eAutos
 * \param int largo array autos
 * \return
 *
 */

int indexPatente(char pantente[], eAuto aut[], int lengAut);


void showClientes(eCliente cli[], int lenCli);

int indexCliente(eCliente cli[], int lenCli, eAuto aut);
