#include "funcionesColores.h"

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


int showColores(eColor col[], int lengCol)
{
    for(int i=0; i<lengCol; i++)
    {
        printf("%d- %s\n", col[i].id,col[i].nombreColor);
    }
    return 0;
}

