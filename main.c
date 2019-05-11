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
#define LENGSEVICIOS 5
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



int main()
{
    eFecha fechas[LENGFECHAS];
    eMarca marcas[LENGMARCAS]= {{1, "Renault"}, {2,"Fiat"}, {3,"Ford"}, {4,"Checrolet"}, {5, "Peugeot"}};
    eColor colores[LENGCOLORES] = {{1,"NEGRO"}, {2,"Blanco"}, {3,"Gris"}, {4, "Rojo"}, {5, "Azul"}};
    eAuto autos[LENGAUTOS];
    eServicio sevicios[LENGSERVICIO]= {{1,"Lavado", 250}, {2,"Pulido", 300}, {3, " Encerado", 400},{4,"Completo", 600}};
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

                printf("ingrese marca: \n");
                for(int i=0; i<LENGMARCAS; i++)
                {
                    printf("%d- %s\n", marcas[i].id,marcas[i].descripcion);
                }
                fflush(stdin);
                scanf("%d", &idMarca);

                idMarca = validarMarca(idMarca);
                printf("ingrese Color:  \n");
                for(int i=0; i<LENGCOLORES; i++)
                {
                    printf("%d- %s\n", colores[i].id,colores[i].nombreColor);
                }
                fflush(stdin);
                scanf("%d", &idColor);
                printf("Ingrese modelo: ");
                fflush(stdin);
                scanf("%d", &modelo);

                addAuto(autos, patente, indexLugar, id, idMarca, idColor, modelo );
                id++;
                addAutos = 1;
            }
            break;

        case 3:
            if(addAutos)
            {
               system("cls");
                printf("BAJA DE AUTO\n\n");
                showAutos(autos, LENGAUTOS, marcas, LENGMARCAS, colores, LENGCOLORES);
                printf("Igrese ID del auto: ");
                scanf("%d", &idAuto);
                indexAuto = validarIDAuto(autos, LENGAUTOS, idAuto);
                if(indexAuto ==-1)
                {
                    printf("No hay un auto con el Id ingresado");
                }else
                {
                    removeAuto(autos, indexAuto);
                    printf("%d\n", indexAuto);
                    printf("Se dio la baja correctamente\n");
                }

            }else
            {
                printf("No se Ingreso ningun auto\n");
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
    printf("2-MODIFICACION AUTO\n");
    printf("3-BAJA AUTO\n");
    printf("4- LISTAR AUTOS\n");
    printf("5- LISTAR MARCAS\n");
    printf("6- LISTAR COLORES\n");
    printf("7- LISTAR SERVICION\n");
    printf("8- ALTA TRANAJOS\n");
    printf("9- LISTAR TRANAJOS\n");
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
    while(id<0 || id>5)
    {
        printf("Opcion incorrecta, reingrese");
        fflush(stdin);
        scanf("%d", &id);
    }
    return id;
}

int validarIDAuto(eAuto aut[], int lengAuto, int id)
{
    int index=-1;

    for(int i=0; i<lengAuto;i++)
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
