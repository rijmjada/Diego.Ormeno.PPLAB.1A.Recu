

#include "hardcodeo.h"

int idClient[10]={1,2,3,4,5,6,7,8,9,10};
int idEquip[10]={10,12,11,10,11,12,10,11,12,10};
int idtiemp[10]={10,12,11,10,11,12,10,11,12,10};
char operador[10][24]=
{
    {"Carlos"},
    {"juan"},
    {"ricardo"},
    {"gabriel"},
    {"Malena"},
    {"Cecilia"},
    {"Alberto"},
    {"Jorge"},
    {"Javier"},
    {"Luciana"}
};

int hardcodearAlquiler(eAlquiler list[],int len,int* id,int cant)
{
    int ret = ERROR;

    if(list != NULL && len >0 && id != NULL)
    {
        for(int i=0; i<cant; i++)
        {
            list[i].id = *id;
            *id = *id + 1;
            strcpy(list[i].operador,operador[i]);
            list[i].idEquipo = idEquip[i];
            list[i].idCliente = idClient[i];
            list[i].idTiempo = idtiemp[i];
            list[i].estado = 13;
            list[i].isEmpty = 0;
        }
        ret = ALLOK;
    }
    return ret;
}

//--------------------//

char nombreaux[10][24]=
{
    {"Carlos"},
    {"juan"},
    {"ricardo"},
    {"gabriel"},
    {"Malena"},
    {"Cecilia"},
    {"Alberto"},
    {"Jorge"},
    {"Javier"},
    {"Luciana"}
};
char apellidoaux[10][24]=
{
    {"Lopez"},
    {"Miranda"},
    {"Chavez"},
    {"Centurion"},
    {"Arriga"},
    {"Lopez"},
    {"Miranda"},
    {"Chavez"},
    {"Arriga"},
    {"Chavez"}
};

int dniAux[10]={33295789,21195789,33295789,32195789,32195789,32195789,32195789,32195789,32195789,32195789};

int hardcodearClientes(eCliente listClient[],int lenClient,int* idC,int canti)
{
    int ret = ERROR;

    if(listClient != NULL && lenClient >0 && idC != NULL)
    {
        for(int i=0; i<canti; i++)
        {
            listClient[i].id = *idC;
            *idC = *idC + 1;
            strcpy(listClient[i].nombre,nombreaux[i]);
            strcpy(listClient[i].apellido,apellidoaux[i]);
            listClient[i].dni = dniAux[i];
            listClient[i].isEmpty = 0;
        }
        ret = ALLOK;
    }
    return ret;
}
