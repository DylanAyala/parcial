#include "funcionesAuto.h"

int initAutos(eAuto aut[], int leng)
{
    for(int i=0; i<leng; i++)
    {
        aut[i].isEmpty = 0;
    }
    return 0;
}

int addAuto(eAuto aut[],char patente[], int lugar, int id, int idMarca, int idColor, int modelo, int idCliente)
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
        aut[lugar].idCliente = idCliente;
        aut[lugar].isEmpty = 1;
        return 1;
    }
    else
    {
        printf("Canselado\n");
        return -1;
    }

}



void printAuto(eAuto aut, eColor col[],int indexCol, eMarca mar[],int indexMar, eCliente cli[], int indexCliente)
{
    printf("%d   %s  %s  %s  %d %s %c\n", aut.id, aut.patente, mar[indexMar].descripcion, col[indexCol].nombreColor, aut.modelo
           , cli[indexCliente].nombre,cli[indexCliente].sexo );
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

int showAutos(eAuto aut[], int lengAuto, eMarca mar[], int lengMar, eColor col[], int lengColor, eCliente cli[], int lengCli)
{
    int idexColor;
    int idexMarca;
    int idexCliente;

    for(int i=0; i<lengAuto; i++)
    {
        if(aut[i].isEmpty == 1)
        {
            idexColor = indexColor(col, lengColor, aut[i]);
            idexMarca = indexMarca(mar,lengMar, aut[i]);
            idexCliente = indexCliente(cli, lengCli, aut[i]);
            printAuto(aut[i], col, idexColor, mar, idexMarca, cli, idexCliente );
        }
    }
    return 0;
}

int modificacionAuto(eAuto aut[], int lengAut, eColor col[], int lengCol, eMarca mar[], int lengMar, eCliente cli[], int lengCli)
{
    char patente[LENGPATENTE];
    int idexPat;
    int choice;
    int idColor;
    int modelo;
    system("cls");
    printf("Modificacion de Auto\n\n");

    showAutos(aut, lengAut, mar, lengMar, col, lengCol, cli, lengCli);

    printf("Ingrese Patente: ");
    fflush(stdin);
    scanf("%s", patente);
    idexPat = indexPatente(patente, aut, lengAut);
    if(idexPat == -1)
    {
        printf("No se encontro la patente ingresada\n");
    }
    else
    {
        system("cls");
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
    return 0;
}


int indexPatente(char pantente[], eAuto aut[], int lengAut)
{
    int index = -1;
    for(int i= 0; i<lengAut; i++)
    {
        if(strcmp(pantente, aut[i].patente)==0 && aut[i].isEmpty==1)
        {
            index = i;
        }
    }
    return index;
}

int indexCliente(eCliente cli[], int lenCli, eAuto aut)
{
    int index = -1;
    for(int i=0; i<lenCli;i++)
    {
        if(cli[i].id == aut.idCliente)
        {
            index= i;
            break;
        }
    }
    return index;
}

void showClientes(eCliente cli[], int lenCli)
{
    for(int i=0;i<lenCli;i++)
    {
        printf("%d- %s %c\n", cli[i].id, cli[i].nombre, cli[i].sexo);
    }
}
