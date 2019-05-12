#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define LENGDES 20
#define LENGPATENTE 7
#define LENGSERVICIO 25
#define LENGAUTOS 5
#define LENGSEVICIOS 4
#define LENGTRABAJOS 10
#define LENGFECHAS 10
#define LENGCOLORES 5
#define LENGMARCAS 5

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[LENGDES];

} eMarca;

typedef struct
{

    int id;
    char nombreColor[LENGDES];
} eColor;

typedef struct
{
    int id;
    char patente[LENGPATENTE];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;

typedef struct
{
    int id;
    char descripcion[LENGSERVICIO];
    float precio;

} eServicio;

typedef struct
{
    int id;
    char patente;
    int idServcion;
    eFecha fecha;
} eTrabajo;

int initAutos(eAuto aut[], int leng);
int indexMarca(eMarca mar[], int lengMar, eAuto aut);
int indexColor(eColor col[], int lengCol, eAuto aut);
int menu(void);
int addAuto(eAuto aut[],char patente[], int lugar, int id, int idMarca, int idColor, int modelo);
void printAuto(eAuto aut, eColor col[], int indexCol, eMarca mar[], int indexMar);
char validarChar(char character);
int validarIDAuto(eAuto aut[], int lengAuto, int id);
int removeAuto(eAuto aut[], int index);
int findLugar(eAuto aut[], int lenAuto);
int validarMarca(int id);
int showAutos(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor);
int validoPatente(eAuto aut[], int largAut, char patente[]);
int showMarcar(eMarca mar[], int lenMar);
int showColores(eColor col[], int lengCol);
int showServicio(eServicio ser[], int lengSer);
int validoColor(int id);
int modificacionAuto(eAuto aut[], int lengAut, eColor col[], int lengCol, eMarca mar[], int lengMar);
int indexPatente(char pantente[], eAuto aut[], int lengAut);

int main()
{
    eFecha fechas[LENGFECHAS];
    eMarca marcas[LENGMARCAS]= {{1000, "Renault"}, {1001,"Fiat"}, {1002,"Ford"}, {1003,"Checrolet"}, {1004, "Peugeot"}};
    eColor colores[LENGCOLORES] = {{5000,"NEGRO"}, {5001,"Blanco"}, {5002,"Gris"}, {5003, "Rojo"}, {5004, "Azul"}};
    eAuto autos[LENGAUTOS];
    eServicio sevicios[LENGSERVICIO]= {{20000,"Lavado", 250}, {20001,"Pulido", 300}, {20002, " Encerado", 400},{20003,"Completo", 600}};
    eTrabajo trabajos[LENGTRABAJOS];

    int initAutoOk;
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
    char patente[7];
    initAutoOk = initAutos(autos, LENGAUTOS);

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
    fflush(stdin);
    scanf("%d",&choice);
    return choice;

}


int initAutos(eAuto aut[], int leng)
{
    for(int i=0; i<leng; i++)
    {
        aut[i].isEmpty = 0;
    }
    return 0;
}

int showAutos(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor)
{
    int idexColor;
    int idexMarca;

    for(int i=0; i<lengAuto; i++)
    {
        if(aut[i].isEmpty == 1)
        {
            idexColor = indexColor(col, lengColor, aut[i]);
            idexMarca = indexMarca(mar,lengMar, aut[i]);
            printAuto(aut[i], col, idexColor, mar, idexMarca );
        }
    }
    return 0;
}

int indexMarca(eMarca mar[], int lengMar, eAuto aut)
{
    int index = -1;

    for(int i=0; i<lengMar; i++)
    {
        if(aut.idMarca==mar[i].id)
        {
            index=i;
            break;
        }
    }
    return index;
}

int indexColor(eColor col[], int lengCol, eAuto aut)
{
    int index = -1;

    for(int i=0; i<lengCol; i++)
    {
        if(aut.idColor==col[i].id)
        {
            index=i;
            break;
        }

    }
    return index;
}


void printAuto(eAuto aut, eColor col[],int indexCol, eMarca mar[],int indexMar)
{
    printf("%d   %s  %s  %s  %d\n", aut.id, aut.patente, mar[indexMar].descripcion, col[indexCol].nombreColor, aut.modelo);
}

int findLugar(eAuto aut[], int lenAuto)
{
    int index= -1;

    for(int i=0; i<lenAuto; i++)
    {
        if(aut[i].isEmpty==0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int addAuto(eAuto aut[],char patente[], int lugar, int id, int idMarca, int idColor, int modelo)
{
    char confirm;

    printf("\n\nConfirma el alta del auto? s/n: ");
    fflush(stdin);
    confirm=getche();
    confirm=validarChar(confirm);
    if(confirm =='s')
    {
        aut[lugar].id= id;
        strcpy(aut[lugar].patente, patente);
        aut[lugar].idMarca = idMarca;
        aut[lugar].idColor=idColor;
        aut[lugar].modelo= modelo;
        aut[lugar].isEmpty = 1;
        return 1;
    }
    else
    {
        printf("Canselado\n");
        return -1;
    }

}

char validarChar(char character)
{
    while(character!='s' && character!='n')
    {
        printf("Opcion incorrecta, reingrese s/n: ");
        fflush(stdin);
        scanf("%c",&character);
        character=tolower(character);
    }
    return character;
}

int validarMarca(int id)
{
    while(id<1000 || id>1004)
    {
        printf("\nOpcion incorrecta, reingrese: ");
        fflush(stdin);
        scanf("%d", &id);
    }
    return id;
}

int validarIDAuto(eAuto aut[], int lengAuto, int id)
{
    int index=-1;

    for(int i=0; i<lengAuto; i++)
    {
        if(aut[i].isEmpty == 1 && aut[i].id == id)
        {
            index= i;
        }
    }
    return index;
}

int removeAuto(eAuto aut[], int index)
{
    aut[index].isEmpty = 0;
    return 0;
}

int validoPatente(eAuto aut[], int largAut, char patente[])
{
    int index = -1;

    for(int i=0; i<largAut; i++)
    {
        if(strcmp(aut[i].patente, patente)==0)
        {
            printf("La pantente ingresada ya existe\n");

            index =1;
        }
    }
    return index;
}

int showMarcar(eMarca mar[], int lenMar)
{
    for(int i=0; i<lenMar; i++)
    {
        printf("%d- %s\n", mar[i].id,mar[i].descripcion);
    }
    return 0;
}
int showColores(eColor col[], int lengCol)
{
    for(int i=0; i<lengCol; i++)
    {
        printf("%d- %s\n", col[i].id,col[i].nombreColor);
    }
    return 0;
}

int showServicio(eServicio ser[], int lengSer)
{

    for(int i=0; i<lengSer; i++)
    {
        printf("%d- %s %.2f\n", ser[i].id, ser[i].descripcion, ser[i].precio);
    }
    return 0;
}

int validoColor(int id)
{
    while(id<5000 || id>5004)
    {
        printf("\nOpcion incorrecta, reingrese: ");
        fflush(stdin);
        scanf("%d", &id);
    }
    return id;
}

int modificacionAuto(eAuto aut[], int lengAut, eColor col[], int lengCol, eMarca mar[], int lengMar)
{
    char patente[LENGPATENTE];
    int idexPat;
    int choice;
    int idColor;
    int modelo;
    system("cls");
    printf("Modificacion de Auto\n\n");

    showAutos(aut, lengAut, mar, lengMar, col, lengCol);

    printf("Ingrese Patente: ");
    fflush(stdin);
    scanf("%s", patente);
    idexPat = indexPatente(patente, aut, lengAut);
    if(idexPat == -1)
    {
        printf("No se encontro la patente ingresada\n");
    }
    else
    {   system("cls");
        printf("MENU DE MODIFICACION\n\n");
        printf("1- COLOR\n");
        printf("2- Modelos\n");
        fflush(stdin);
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            system("cls");
            printf("COLORES A ELEGIR\n\n");
            showColores(col, lengCol);
            printf("Ingrese el color: ");
            fflush(stdin);
            scanf("%d", &idColor);
            idColor = validoColor(idColor);
            aut[idexPat].idColor = idColor;
            break;
        case 2:
            system("cls");
            printf("Ingrese Modelo: ");
            fflush(stdin);
            scanf("%d", &modelo);
            aut[idexPat].modelo = modelo;
            break;
        default:
            printf("Opcion incorrecta \n");
        }
    }
}


int indexPatente(char pantente[], eAuto aut[], int lengAut)
{
    int index = -1;
    for(int i= 0; i<lengAut; i++)
    {
        if(strcmp(pantente, aut[i].patente)==0)
        {
            index = i;
        }
    }
    return index;
}
