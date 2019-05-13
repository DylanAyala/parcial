#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funcionesAuto.h"
#include "funcionesMarca.h"
#include "funcionesColores.h"
#include "funcionesServicios.h"
#include "funcionesTrabajo.h"
#define LENGAUTOS 5
#define LENGTRABAJOS 10
#define LENGFECHAS 10
#define LENGCOLORES 5
#define LENGMARCAS 5


int menu(void);


int main()
{
    eFecha fechas;
    eMarca marcas[LENGMARCAS]= {{1000, "Renault"}, {1001,"Fiat"}, {1002,"Ford"}, {1003,"Checrolet"}, {1004, "Peugeot"}};
    eColor colores[LENGCOLORES] = {{5000,"NEGRO"}, {5001,"Blanco"}, {5002,"Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    eAuto autos[LENGAUTOS];
    eServicio sevicios[LENGSERVICIO]= {{20000,"Lavado", 250}, {20001,"Pulido", 300}, {20002, " Encerado", 400},{20003,"Completo", 600}};
    eTrabajo trabajos[LENGTRABAJOS];

    int exit= 0;
    int indexLugar;
    int idMarca;
    int idColor;
    int modelo;
    int addAutos = 0;
    int id= 1;
    int idAuto;
    int indexAuto;
    int patenteOk;
    int indexTrabajo;
    int idServicio;
    int idTrabajo= 1;
    int addTrabajoOk = 0;
    char patente[7];
    initAutos(autos, LENGAUTOS);
    initTrabajos(trabajos, LENGTRABAJOS);

    do
    {


        switch(menu())
        {
        case 0:
            exit=1;
            break;
        case 1:
            system("cls");
            indexLugar = findLugar(autos, LENGAUTOS);
            if(indexLugar == -1)
            {
                printf("No hay lugares disponibles\n");
            }
            else
            {
                printf("ALTA AUTO\n\n");
                printf("Ingrese Patente: ");
                scanf("%s", patente);

                patenteOk = validoPatente(autos, LENGAUTOS, patente);

                while(patenteOk == 1)
                {
                    printf("Ingrese Patente: ");
                    scanf("%s", patente);
                    patenteOk = validoPatente(autos, LENGAUTOS, patente);
                }

                printf("ingrese marca: \n");
                showMarcar(marcas, LENGMARCAS);

                fflush(stdin);
                scanf("%d", &idMarca);

                idMarca = validarMarca(idMarca);
                printf("ingrese Color:  \n");
                showColores(colores, LENGCOLORES);
                fflush(stdin);
                scanf("%d", &idColor);
                idColor = validoColor(idColor);

                printf("Ingrese modelo: ");
                fflush(stdin);
                scanf("%d", &modelo);

                addAuto(autos, patente, indexLugar, id, idMarca, idColor, modelo );
                id++;
                addAutos = 1;
            }
            break;
        case 2:
            if(addAutos)
                modificacionAuto(autos, LENGAUTOS, colores, LENGCOLORES, marcas, LENGMARCAS);
            else
                printf("Se debe ingresar un auto primero\n");
            break;
        case 3:
            if(addAutos)
            {
                system("cls");
                printf("BAJA DE AUTO\n\n");
                showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES);
                printf("0- Volver al menu anterior\n");
                printf("Igrese ID del auto: ");
                scanf("%d", &idAuto);
                if(idAuto==1)
                {
                    indexAuto = validarIDAuto(autos, LENGAUTOS, idAuto);
                    if(indexAuto ==-1)
                    {
                        printf("No hay un auto con el Id ingresado");
                    }
                    else
                    {
                        removeAuto(autos, indexAuto);
                        printf("%d\n", indexAuto);
                        printf("Se dio la baja correctamente\n");
                    }
                }

            }
            else
            {
                printf("No se Ingreso ningun auto\n");
            }

            break;
        case 4:
            if(addAutos)
            {
                showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES);
            }
            else
            {
                printf("Se debe ingresar un auto primero\n");
            }
            break;
        case 5:
            system("cls");
            printf("LISTA DE MARCAS\n");
            showMarcar(marcas, LENGMARCAS);
            break;
        case 6:
            system("cls");
            printf("LISTA DE COLORES\n");
            showColores(colores, LENGCOLORES);
            break;
        case 7:
            system("cls");
            printf("LISTA DE SERVICIOS\n");
            showServicio(sevicios, LENGSEVICIOS);
            break;
        case 8:
            if(addAutos)
            {
                indexTrabajo = findLugarTrabajo(trabajos, LENGTRABAJOS);
                if(indexTrabajo == -1)
                {
                    printf("No Hay lugares para mas trabajos\n");
                }
                else
                {
                    system("cls");
                    printf("ALTA DE TRABAJOS\n\n");
                    showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES);
                    printf("Ingrese patente del auto: ");
                    fflush(stdin);
                    scanf("%s", patente);
                    patenteOk = indexPatente(patente, autos, LENGAUTOS);
                    if(patenteOk ==-1)
                    {
                        printf("No hay autos con la patente ingresada\n");
                    }
                    else
                    {
                        showServicio(sevicios, LENGSEVICIOS);
                        fflush(stdin);
                        scanf("%d", &idServicio);
                        idServicio = validarServicio(sevicios, LENGSEVICIOS, idServicio);
                        while(idServicio == -1)
                        {
                            printf("Opcion incorrecta, reingrese: ");
                            idServicio = validarServicio(sevicios, LENGSEVICIOS, idServicio);
                        }
                        printf("\nIngrese anio: ");
                        fflush(stdin);
                        scanf("%d", &fechas.anio);
                        printf("\nIngrese mes: ");
                        fflush(stdin);
                        scanf("%d", &fechas.mes);
                        printf("\nIngrese dia: ");
                        fflush(stdin);
                        scanf("%d", &fechas.dia);

                        addTrabajo(trabajos, idTrabajo, indexTrabajo, patente, idServicio, fechas);
                        idTrabajo++;
                        addTrabajoOk = 1;

                    }

                }


            }
            else
            {
                printf("Primero se debe ingresar un auto\n");
            }
            break;
        case 9:
            if(addTrabajoOk){
                system("cls");
                printf("LISTADO DE TRABAJOS\n\n");
                showTrabajos(trabajos, LENGTRABAJOS, sevicios, LENGSEVICIOS);
            }else
            {
                printf("Se debe ingresar un trabajo primero\n");
            }

            break;
        default:
            printf("Opcion no valida\n");
        }
        system("pause");
    }
    while(exit==0);
}

int menu()
{
    int choice;
    system("cls");
    printf("*******MENU*****\n\n");
    printf("1- ALTA AUTO\n");
    printf("2- MODIFICACION AUTO\n");
    printf("3- BAJA AUTO\n");
    printf("4- LISTAR AUTOS\n");
    printf("5- LISTAR MARCAS\n");
    printf("6- LISTAR COLORES\n");
    printf("7- LISTAR SERVICIOS\n");
    printf("8- ALTA TRABAJOS\n");
    printf("9- LISTAR TRABAJOS\n");
    printf("0- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&choice);
    return choice;

}
