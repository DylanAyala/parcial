#include "funcionesTrabajo.h"


int addTrabajo(eTrabajo tra[],int id,int index, char patente[], int idSer, eFecha fecha)
{
    char confirm;

    printf("\n\nConfirma el alta del Trabajo? s/n: ");
    fflush(stdin);
    confirm=getche();
    confirm=validarChar(confirm);
    if(confirm =='s')
    {
        tra[index].id = id;
        strcpy(tra[index].patente, patente);
        tra[index].idServcion = idSer;
        tra[index].fecha.dia = fecha.dia;
        tra[index].fecha.mes = fecha.mes;
        tra[index].fecha.anio = fecha.anio;
        tra[index].isEmpty = 1;
    }
    else
    {
        printf("Se cancelos el Alta\n");
    }
    return 0;
}


int initTrabajos(eTrabajo tra[], int lengTra)
{
    for(int i=0; i<lengTra; i++)
    {
        tra[i].isEmpty = 0;
    }
    return 0;
}

int findLugarTrabajo(eTrabajo tra[], int lengTra)
{
    int index = -1;
    for(int i=0; i<lengTra; i++)
    {
        if(tra[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}



int mostrarTrabajo(eTrabajo tra, eServicio ser)
{
    printf("%d  %s  %s  %d/%d/%d\n", tra.id, tra.patente, ser.descripcion, tra.fecha.anio, tra.fecha.mes, tra.fecha.dia);
    return 0;
}


int showTrabajos(eTrabajo tra[], int lengTra, eServicio ser[], int lengSer)
{
    int idexSer;

    for(int i=0;i<lengTra;i++)
    {
        if(tra[i].isEmpty ==1)
        {
            idexSer = indexServicio(ser, LENGSEVICIOS, tra[i].idServcion);
            mostrarTrabajo(tra[i],ser[idexSer]);
        }
    }
    return 0;
}
