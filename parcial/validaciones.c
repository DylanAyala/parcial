#include "validaciones.h"



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



int validoPatente(eAuto aut[], int largAut, char patente[])
{
    int index = -1;

    for(int i=0; i<largAut; i++)
    {
        if(strcmp(aut[i].patente, patente)==0 && aut[i].isEmpty==1)
        {
            printf("La pantente ingresada ya existe\n");

            index =1;
        }
    }
    return index;
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

int validoCliente(int id)
{
    while(id<1 || id>5)
    {
        printf("\nOpcion incorrecta, reingrese: ");
        fflush(stdin);
        scanf("%d", &id);
    }
    return id;
}
