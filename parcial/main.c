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
#define LENGAUTOS 24
#define LENGTRABAJOS 37
#define LENGFECHAS 10
#define LENGCOLORES 5
#define LENGMARCAS 5
#define LENGCLIENTES 5


int menu(void);
int menuInforme();
int autosColorNegro(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor, eCliente cli[], int lengCli);
int autosColorNegro(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor, eCliente cli[], int lengCli);
int autosMarcaSeleccionada(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor, eCliente cli[], int lengCli, int marca);
int trabajosAutoSelecionado(char patente[], eTrabajo tra[], int lengTra, eServicio ser[], int lengSer);
int autosSinTrabajos(eAuto aut[], int lengAut, eMarca mar[], int lengMar, eColor col[], int lengCol, eTrabajo tra[], int lengTra, eCliente cli [], int lengCli);
int indexPatenteTrabajos(eTrabajo tra[], int lengTra, char patente[]);


int main()
{
    eCliente clientes[LENGCLIENTES]=
    {
        {1, "Dylan", 'm'},
        {2, "Juan", 'm'},
        {3, "Lourdes", 'f'},
        {4, "Andres", 'm'},
        {5, "Rodrigo", 'm'}
    };

    eServicio sevicios[] =
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600},
        {20004, "Teflonado", 800}
    };

    eMarca marcas[] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    eColor colores[] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eAuto autos[LENGAUTOS]=
    {
        {1, "AAA201", 1000, 5001, 1995, 1, 1},
        {2, "DFR234", 1003, 5000, 2002, 2,1},
        {3, "GFT564", 1002, 5003, 2007, 3,1},
        {4, "ACD321", 1002, 5003, 1995, 2,1},
        {5, "HTD656", 1004, 5002, 2008, 5, 1},
        {6, "QSZ435", 1003, 5001, 1994, 2, 1},
        {7, "LGX201", 1001, 5000, 2012, 1, 1},
        {8, "SUZ324", 1001, 5002, 1991, 2,1},
        {9, "HCU762", 1000, 5003, 2008, 3,1},
        {10, "DYC735", 1003, 5001, 2002,4,1},
        {11, "JJK879", 1003, 5001, 2010,2, 1},
        {12, "FED322", 1004, 5002, 2006,3,1},
        {13, "GHV332", 1001, 5003, 2007,1,1},
        {14, "BDE221", 1000, 5004, 1996,1,1},
        {15, "OPD332", 1000, 5001, 2014,4,1},
        {16, "PPD121", 1002, 5001, 2015,5,1},
        {17, "IIT230", 1001, 5000, 2009,3,1},
        {18, "KOD220", 1004, 5002, 2011,1,1},
        {19, "QSZ305", 1004, 5002, 1993,3,1},
        {20, "SSD128", 1002, 5003, 1992,1,1},
        {21, "SSD240", 1003, 5004, 1992, 4, 1},
        {22, "EDF213", 1001, 5000, 2001,2,1},
    };

    eTrabajo trabajos[LENGTRABAJOS] =
    {

        {1, "AAA201", 20000, {12,3,2019}, 1},
        {2, "DFR234", 20000, {2,4,2019}, 1},
        {3, "GFT564", 20001, {7,1,2019}, 1},
        {4, "ACD321", 20002, {9,11,2019}, 1},
        {5, "HTD656", 20003, {12,12,2019}, 1},
        {6, "QSZ435", 20001, {21,7,2019}, 1},
        {7, "LGX201", 20001, {29,8,2019}, 1},
        {8, "SUZ324", 20004, {31,5,2019}, 1},
        {9, "HCU762", 20004, {2,2,2019}, 1},
        {10, "DYC735", 20000, {18,2,2019}, 1},
        {11, "JJK879", 20001, {17,3,2019}, 1},
        {12, "AAA201", 20000, {17,4,2019}, 1},
        {13, "DFR234", 20000, {2,6,2019}, 1},
        {14, "GFT564", 20001, {7,3,2019}, 1},
        {15, "ACD321", 20002, {21,7,2019}, 1},
        {16, "HTD656", 20003, {11,9,2019}, 1},
        {17, "QSZ435", 20001, {3,7,2019}, 1},
        {18, "LGX201", 20001, {21,8,2019}, 1},
        {19, "SUZ324", 20004, {28,5,2019}, 1},
        {20, "HCU762", 20004, {2,8,2019}, 1},
        {21, "DYC735", 20000, {8,2,2019}, 1},
        {22, "JJK879", 20001, {17,3,2019}, 1},
        {23, "KOD220", 20003, {17,4,2019}, 1},
        {24, "QSZ305", 20000, {21,3,2019}, 1},
        {25, "SSD128", 20002, {16,4,2019}, 1},
        {26, "SSD240", 20000, {17,4,2019}, 1},
        {27, "EDF213", 20001, {23,3,2019}, 1},
        {28, "AAA201", 20000, {12,2,2019}, 1},
        {29, "DFR234", 20000, {2,3,2019}, 1},
        {30, "GFT564", 20001, {7,2,2019}, 1},
        {31, "ACD321", 20002, {9,12,2019}, 1},
        {32, "HTD656", 20003, {12,9,2019}, 1},
        {33, "QSZ435", 20001, {21,5,2019}, 1},
        {34, "HTD656", 20002, {12,2,2019}, 1},
        {35, "QSZ435", 20000, {21,1,2019}, 1},
    };
    eFecha fechas;



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
    int idCliente;
    int choiceInforme;
    char patente[7];

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

                showClientes(clientes, LENGCLIENTES);
                printf("Igrese cliente: ");
                fflush(stdin);
                scanf("%d", &idCliente);
                idCliente =validoCliente(idCliente);
                addAuto(autos, patente, indexLugar, id, idMarca, idColor, modelo, idCliente);
                id++;
                addAutos = 1;
            }
            break;
        case 2:
            if(addAutos)
                modificacionAuto(autos, LENGAUTOS, colores, LENGCOLORES, marcas, LENGMARCAS, clientes, LENGCLIENTES);
            else
                printf("Se debe ingresar un auto primero\n");
            break;
        case 3:
            if(addAutos)
            {
                system("cls");
                printf("BAJA DE AUTO\n\n");
                showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES, clientes, LENGCLIENTES);
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
                showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES, clientes, LENGCLIENTES);
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
            system("cls");
            printf("LISTA DE CLIENTES\n");
            showClientes(clientes, LENGCLIENTES);
            break;
        case 9:
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
                    showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES, clientes, LENGCLIENTES);
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
        case 10:
            if(addTrabajoOk)
            {
                system("cls");
                printf("LISTADO DE TRABAJOS\n\n");
                showTrabajos(trabajos, LENGTRABAJOS, sevicios, LENGSEVICIOS);
            }
            else
            {
                printf("Se debe ingresar un trabajo primero\n");
            }

            break;
        case 11:

            choiceInforme = menuInforme();
            switch(choiceInforme)
            {
            case 1:
                autosColorNegro(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES, clientes, LENGCLIENTES);
                break;
            case 2:
                system("cls");
                showMarcar(marcas, LENGMARCAS);
                printf("Ingrese marca: ");
                fflush(stdin);
                scanf("%d", &idMarca);
                idMarca = validarMarca(idMarca);
                autosMarcaSeleccionada(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES, clientes, LENGCLIENTES, idMarca);
                break;
            case 3:
                system("cls");
                showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES, clientes, LENGCLIENTES);
                printf("Ingrese patente: ");
                fflush(stdin);
                scanf("%s", patente);
                patenteOk = indexPatente(patente, autos, LENGAUTOS);
                if(patenteOk ==-1)
                {
                    printf("No hay autos con la patente ingresada\n");
                }
                else
                {
                    trabajosAutoSelecionado(patente, trabajos, LENGTRABAJOS, sevicios, LENGSERVICIO);
                }


                break;
            case 4:
                system("cls");
                printf("Autos que no tuvieron Trabajos\n\n");

                autosSinTrabajos(autos, LENGAUTOS, marcas,LENGMARCAS, colores, LENGCOLORES, trabajos, LENGTRABAJOS, clientes, LENGCLIENTES);

                break;
            case 6:

                break;
            case 0:
                break;

            default:
                printf("Opcion incorrecta\n");
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
    printf("8- LISTAR CLIENTES\n");
    printf("9- ALTA TRABAJOS\n");
    printf("10- LISTAR TRABAJOS\n");
    printf("11- MENU DE INFORMES\n");
    printf("0- SALIR\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&choice);
    return choice;

}


int menuInforme()
{
    int choice;

    system("cls");
    printf("MENU DE INFORMES\n\n");
    printf("1- MOSTRAR AUTOS DE COLOR NEGOR\n");
    printf("2- MOSTRAR  AUTOS DE UNA MARCA SELECIONADA\n");
    printf("3- MOSTRAR TODOS LOS TRABAJOS EFECTUADOS AL AUTO SELECIONADO\n");
    printf("4- LISTAR LOS AUTOS QUE NO TUVIERON TRABAJOS\n");
    printf("5- INFORMAR UN IMPORTE TOTAL DE LOS TRABAJOS REALIZADOS A UN AUTO SELECIONADO\n");
    printf("6- MOSTRAR SERVICIO MAS RAPIDO\n");
    printf("0- VOLVER AL MENU ANTERIOR\n");

    fflush(stdin);
    scanf("%d", &choice);

    return choice;
}

int autosColorNegro(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor, eCliente cli[], int lengCli)
{
    int idexColor;
    int idexMarca;
    int idexCliente;

    for(int i=0; i<lengAuto; i++)
    {
        if(aut[i].isEmpty == 1 && aut[i].idColor==5000)
        {
            idexColor = indexColor(col, lengColor, aut[i]);
            idexMarca = indexMarca(mar,lengMar, aut[i]);
            idexCliente = indexCliente(cli, lengCli, aut[i]);
            printAuto(aut[i], col, idexColor, mar, idexMarca, cli, idexCliente );
        }
    }
    return 0;
}


int autosMarcaSeleccionada(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor, eCliente cli[], int lengCli, int marca)
{
    int idexColor;
    int idexMarca;
    int idexCliente;

    for(int i=0; i<lengAuto; i++)
    {
        if(aut[i].isEmpty == 1 && aut[i].idMarca==marca)
        {
            idexColor = indexColor(col, lengColor, aut[i]);
            idexMarca = indexMarca(mar,lengMar, aut[i]);
            idexCliente = indexCliente(cli, lengCli, aut[i]);
            printAuto(aut[i], col, idexColor, mar, idexMarca, cli, idexCliente );
        }
    }
    return 0;
}


int trabajosAutoSelecionado(char patente[], eTrabajo tra[], int lengTra, eServicio ser[], int lengSer)
{
    int idexSer;

    for(int i=0; i<lengTra; i++)
    {
        if(tra[i].isEmpty ==1 && strcmp(tra[i].patente,patente)==0)
        {
            idexSer = indexServicio(ser, LENGSEVICIOS, tra[i].idServcion);
            mostrarTrabajo(tra[i],ser[idexSer]);
        }
    }
    return 0;
}

int autosSinTrabajos(eAuto aut[], int lengAut, eMarca mar[], int lengMar, eColor col[], int lengCol, eTrabajo tra[], int lengTra, eCliente cli [], int lengCli)
{

    int idexColor;
    int idexMarca;
    int idexCliente;

    for(int i=0; i<lengAut; i++)
    {

        if(aut[i].isEmpty == 1 && indexPatenteTrabajos(tra, lengTra, aut[i].patente)==-1)
        {
            idexColor = indexColor(col, lengCol, aut[i]);
            idexMarca = indexMarca(mar,lengMar, aut[i]);
            idexCliente = indexCliente(cli, lengCli, aut[i]);
            printAuto(aut[i], col, idexColor, mar, idexMarca, cli, idexCliente );
        }

    }

    return 0;
}

int indexPatenteTrabajos(eTrabajo tra[], int lengTra, char patente[])
{
    int index = -1;
    for(int i= 0; i<lengTra; i++)
    {
        if(strcmp(patente, tra[i].patente)==0)
        {
            index = i;
        }
    }
    return index;
}
