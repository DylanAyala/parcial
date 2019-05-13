#include "funcionesMarca.h"

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

int showMarcar(eMarca mar[], int lenMar)
{
    for(int i=0; i<lenMar; i++)
    {
        printf("%d- %s\n", mar[i].id,mar[i].descripcion);
    }
    return 0;
}
