#include "funcionesServicios.h"

int indexServicio(eServicio ser[], int lengSer, int id)
{
    int index = -1;
    for(int i=0; i<lengSer;i++)
    {
        if(ser[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}


int showServicio(eServicio ser[], int lengSer)
{

    for(int i=0; i<lengSer; i++)
    {
        printf("%d- %s %.2f\n", ser[i].id, ser[i].descripcion, ser[i].precio);
    }
    return 0;
}

int validarServicio(eServicio ser[], int lengSer, int id)
{
    int idOk = -1;

    for(int i=0;i<lengSer;i++)
    {
        if(ser[i].id == id)
        {
            idOk = id;
            break;
        }
    }
    return idOk;
}
