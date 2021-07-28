#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"

int menu()
{
    int ret = ERROR;

    system("cls");
    printf("\n**Menu Principal**");
    printf("\n---------------------\n\n");
    printf("1- ALTA DEL CLIENTE.\n");
    printf("2- MODIFICAR DATOS DEL CLIENTE.\n");
    printf("3- BAJA DEL CLIENTE.\n");
    printf("4- NUEVO ALQUILER.\n");
    printf("5- FIN DEL ALQUILER.\n");
    printf("6- INFORMAR.\n");
    printf("7- Salir.\n");

    getInt(&ret,"\nIngrese una opcion [1-7]: ","\nDato Invalido. Reingrese: \n",1,7,10);

    return ret;
}
int menu2()
{
    int ret = ERROR;

    system("cls");
    printf("\n**Menu Principal**");
    printf("\n---------------------\n\n");
    printf("1- El nombre y apellido del asociado con más alquileres.\n");
    printf("2- El o los equipo/s más alquilado/s y su cantidad.\n");
    printf("3- El tiempo promedio real de alquiler de los equipos.\n");
    printf("4- Mostrar lista clientes.\n");
    printf("5- Mostrar lista alquileres.\n");


    getInt(&ret,"\nIngrese una opcion [1-7]: ","\nDato Invalido. Reingrese: \n",1,5,10);

    return ret;
}
int inicializarArray(eCliente list[],int len)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        ret = ALLOK;
    }
    return ret;
}

int buscarLibre(eCliente list[],int len)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                ret = i; //ret indice libre
                break;
            }
        }
    }
    return ret;
}

int altaCliente(eCliente list[],int len,int* idPtr)
{
    int index = ERROR, ret = ERROR;

    if(list != NULL && len >0 && idPtr != NULL )
    {
        index = buscarLibre(list,len);

        if(index != ERROR)
        {
            system("cls");
            printf("\n**Alta Cliente**\n");
            printf("***********************\n\n");

            getString(list[index].nombre,"\nIngrese nombre [Max 20 caract.]: ","\nDato invalido!.Reingrese!\n",1,24,10);
            getString(list[index].apellido,"\nIngrese apellido [Max 20 caract.]: ","\nDato invalido!.Reingrese!\n",1,24,10);
            getInt(&list[index].dni,"\nIngrese dni: \n","\nDato invalido.Reingrese.\n",1000000,99000000,5);

            list[index].id = *idPtr;
            *idPtr = *idPtr + 1;
            list[index].isEmpty = 0;
            ret = ALLOK;
        }
    }
    return ret;
}

int modificarCliente(eCliente list[],int len)
{
    int opcion,idClienteAux,index,ret = ERROR;

    if(list != NULL && len >0)
    {
        do
        {
            mostrarListaClientes(list,len);
            getInt(&idClienteAux,"\nIngrese id a modificar: ","\nDato Invalido!",1,100,1);
            index = retornarIndicePorID(list,len,idClienteAux);

            if(index != ERROR)
            {

                getInt(&opcion,"\n1-Modificar Nombre.\n2-Modificar Apellido\n","\nDato invalido.Reingrese\n",1,2,10);

                if(opcion == 1)
                {
                    getString(list[index].nombre,"\nIngrese nombre [Max 20 caract.]: ","\nDato invalido!.Reingrese!\n",1,24,10);
                }
                else
                {
                    getString(list[index].apellido,"\nIngrese apellido [Max 20 caract.]: ","\nDato invalido!.Reingrese!\n",1,24,10);
                }

                ret = ALLOK;
            }
        }
        while(index == ERROR);
    }
    return ret;
}

int bajaCliente(eCliente list[],int len)
{
    int index = ERROR, idBaja = ERROR, ret = ERROR;
    char confirma;
    if( list != NULL && len >0 )
    {
        mostrarListaClientes(list,len);
        getInt(&idBaja,"\nIngrese un ID a dar de baja: \n","\nDato Invalido.Reingrese: \n",1,100,10);
        index = retornarIndicePorID(list,len,idBaja);
        if(index != ERROR)
        {
            validarSioNo(&confirma,"\nConfirma baja? [s/n]:\n","\nDato Invalido.Reingrese:\n",3);

            if(confirma == 's')
            {
                list[index].isEmpty = 1;
                printf("\nBaja exitosa!.\n");
                ret = ALLOK;
            }
            else
            {
                printf("\nBaja cancelada por el usuario!.\n");
            }
        }
    }
    return ret;
}

int retornarIndicePorID(eCliente list[],int len,int idValidar)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idValidar && list[i].isEmpty == 0)
            {
                ret = i; // si lo encuentro ret retorna el indice!
                break;
            }
        }
    }
    return ret;
}

int validarIDCliente(eCliente list[],int len,int idValidar)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idValidar && list[i].isEmpty == 0)
            {
                ret = ALLOK;
                break;
            }
        }
    }
    return ret;
}


int mostrarListaClientes(eCliente list[],int len)
{
    int ret = ERROR;
    if(list != NULL && len >0)
    {
        system("cls");
        printf("\n**Lista motos**\n");
        printf("\n[ID]       [Nombre]     [Apellido]     [DNI]   \n");
        printf("___________________________________________________\n");
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                mostrarUnaCliente(&list[i]);
            }
        }
        printf("___________________________________________________\n");
        printf("\n\n");
        ret = ALLOK;
    }
    return ret;
}

int mostrarUnaCliente(eCliente* unCliente)
{
    int ret = ERROR;

    if(unCliente != NULL)
    {

        printf("%2d  %12s  %12s   %d\n"
               ,unCliente->id
               ,unCliente->nombre
               ,unCliente->apellido
               ,unCliente->dni);
    }
    return ret;
}


//-------------------------------------------------------------------------------------//


int inicializarArrayAlquiler(eAlquiler list[],int len)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        ret = ALLOK;
    }
    return ret;
}

int buscarLibreAlquiler(eAlquiler list[],int len)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                ret = i; //ret indice libre
                break;
            }
        }
    }
    return ret;
}

int validarIDAlquiler(eAlquiler list[],int len,int idValidar)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idValidar && list[i].isEmpty == 0)
            {
                ret = ALLOK;
                break;
            }
        }
    }
    return ret;
}

int altaAlquiler(eAlquiler list[],int len,int* idPtr,eCliente listCliente[],int lenCliente)
{
    int idClienteAux,index = ERROR, ret = ERROR;

    if(list != NULL && len >0 && idPtr != NULL )
    {
        index = buscarLibreAlquiler(list,len);

        if(index != ERROR)
        {
            system("cls");
            printf("\n**Alta Alquiler**\n");
            printf("***********************\n\n");
            mostrarListaClientes(listCliente,lenCliente);
            getInt(&idClienteAux,"\nIngrese id Cliente: \n","\nError.",1,100,5);
            if(validarIDCliente(listCliente,lenCliente,idClienteAux)==ALLOK)
            {
                list[index].idCliente = idClienteAux;
                mostrarListaEquipos();
                getInt(&list[index].idEquipo,"\nIngrese codigo Equipo: \n","\nError.",10,12,10);
                mostrarTiempoEstimado();
                getInt(&list[index].idTiempo,"\nIngrese codigo tiempo estimado alquiler: \n","\nError.",10,12,10);
                getNombreOApellido(list[index].operador,"\nIngrese el nombre del operador:\n","\nDato invalido.Reingrese\n",3,12,10);

                list[index].isEmpty = 0;
                list[index].estado = ALQUILADO;
                list[index].id = *idPtr;
                *idPtr += 1;
            }
        }
    }
    return ret;
}

int mostrarListaAlquiler(eAlquiler list[], int len,eCliente listCliente[],int lenCliente)
{
    int ret = ERROR;
    if(list != NULL && len >0 && listCliente != NULL && lenCliente >0)
    {

        system("cls");
        printf("\n**Lista Alquiler**\n");
        printf("\n[ID]        [Nombre/C]  [Apellido/C]     [Equipo]    [Tiempo]   [operador]  \n");
        printf("________________________________________________________________________________\n\n");

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                mostrarUnAlquiler(&list[i],listCliente,lenCliente);
            }
        }
        printf("________________________________________________________________________________\n\n");
        printf("\n\n");
        ret = ALLOK;
    }
    return ret;
}

int mostrarUnAlquiler(eAlquiler* UnAlquiler,eCliente listCliente[],int lenCliente)
{
    int ret = ERROR;
    char nombreCliente[24];
    char apellidoCliente[24];
    char nombreEquipo[24];
    char tiempoAux[24];

    if( UnAlquiler != NULL && listCliente != NULL && lenCliente >0 )
    {
        if(cargarNombreCliente(listCliente,lenCliente,UnAlquiler->idCliente,nombreCliente) &&
                cargarApellidoCliente(listCliente,lenCliente,UnAlquiler->idCliente,apellidoCliente) &&
                cargarNombreEquipo(UnAlquiler->idEquipo,nombreEquipo) &&
                cargarTiempoEstimado(UnAlquiler->idTiempo,tiempoAux)==ALLOK)
        {
            printf("%4d  %12s %12s %12s %12s %12s \n"
                   ,UnAlquiler->id
                   ,nombreCliente
                   ,apellidoCliente
                   ,nombreEquipo
                   ,tiempoAux
                   ,UnAlquiler->operador
                  );
        }
        else
        {
            printf("\nErro al intentar cargar descripciones!\n");
        }
    }

    return ret;
}

int retornarIndicePorIDAlquiler(eAlquiler list[],int len,int idValidar)
{
    int ret = ERROR;

    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idValidar && list[i].isEmpty == 0)
            {
                ret = i; // si lo encuentro ret retorna el indice!
                break;
            }
        }
    }
    return ret;
}

int finAlquiler(eAlquiler list[],int len,eCliente listCliente[],int lenCliente)
{
    int index,ret = ERROR;
    int idAlquilerAux;
    char tiempoAux[24];

    if(list != NULL && len >0 && listCliente != NULL && lenCliente >0)
    {
        mostrarListaAlquiler(list,len,listCliente,lenCliente);
        getInt(&idAlquilerAux,"\nIngrese id Alquiler: \n","\nError.",1,100,5);
        if(validarIDAlquiler(list,len,idAlquilerAux)==ALLOK)
        {
            getString(tiempoAux,"\nIngrese el tiempo real del alquiler:\n","\nDato Invalido.Reingrse\n",3,20,5);
            index = retornarIndicePorIDAlquiler(list,len,idAlquilerAux);
            list[index].estado = FINALIZADO;
        }
    }

    return ret;
}


void mostrarListaEquipos()
{
    system("cls");
    printf("-Equipo      Codigo\n");
    printf("-------------------\n");
    printf("-Amoladora      10\n");
    printf("-MEZCLADORA     11\n");
    printf("-TALADRO        12\n");
}
void mostrarTiempoEstimado()
{
    system("cls");
    printf("-Tiempo Estimado  Codigo\n");
    printf("-------------------------\n");
    printf("-Una semana           10\n");
    printf("-Dos semanas          11\n");
    printf("-Tres semanas         12\n");
}

int cargarNombreCliente(eCliente list[],int len,int idCliente,char* nombre)
{
    int ret = ERROR;

    if( list != NULL && len >0 && nombre != NULL )
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idCliente)
            {
                strcpy(nombre,list[i].nombre);
                break;
            }
        }
        ret = ALLOK;
    }
    return ret;
}

int cargarApellidoCliente(eCliente list[],int len,int idCliente,char* apellido)
{
    int ret = ERROR;

    if( list != NULL && len >0 && apellido != NULL )
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == idCliente)
            {
                strcpy(apellido,list[i].apellido);
                break;
            }
        }
        ret = ALLOK;
    }
    return ret;
}

int cargarNombreEquipo(int id,char* equipo)
{
    int ret = ERROR;

    if(id == 10)
    {
        strcpy(equipo,"Amoladora");
        ret = ALLOK;
    }
    else
    {
        if(id==11)
        {
            strcpy(equipo,"Mezcladora");
            ret = ALLOK;
        }
        else
        {
            if(id==12)
            {
                strcpy(equipo,"Taladro");
                ret = ALLOK;
            }
            else
            {
                ret = ERROR;
            }
        }
    }
    return ret;
}

int cargarTiempoEstimado(int id,char* tiempo)
{
    int ret = ERROR;

    if(id == 10)
    {
        strcpy(tiempo,"1 semana");
        ret = ALLOK;
    }
    else
    {
        if(id==11)
        {
            strcpy(tiempo,"2 semanas");
            ret = ALLOK;
        }
        else
        {
            if(id==12)
            {
                strcpy(tiempo,"3 semanas");
                ret = ALLOK;
            }
            else
            {
                ret = ERROR;
            }
        }
    }
    return ret;
}

int equipoMasAlquilado(eAlquiler listAl[],int lenAl,eCliente listCl[],int lenCl)
{
    int ret = ERROR;
    int mola =0;
    int mezc = 0;
    int tala = 0;

    if (listAl != NULL && lenAl >0 && listCl != NULL && lenCl >0)
    {
        for(int i=0; i<lenAl; i++)
        {
            if(listAl[i].isEmpty == 0)
            {
                if(listAl[i].idEquipo == 10)
                {
                    mola++;
                }
                if(listAl[i].idEquipo == 11)
                {
                    mezc++;
                }
                if(listAl[i].idEquipo == 12)
                {
                    tala++;
                }
            }
        }
        if(mola >mezc && mola >tala)
        {
            printf("\nLa amoladora es la q mas se alquilo.Cantidad: %d\n",mola);
        }
        else
        {
            if(mezc > mola && mezc >tala)
            {
                printf("\nLa mezcladora es la q mas se alquilo.Cantidad: %d\n",mezc);
            }
            else
            {
                printf("\nEl taladro es la q mas se alquilo.Cantidad: %d\n",tala);
            }
        }
        ret = ALLOK;
    }

    return ret;
}

int nombreClienteMasAlquileres(eAlquiler listAl[],int lenAl,eCliente listCl[],int lenCl)
{
    int ret = ERROR;

    if (listAl != NULL && lenAl >0 && listCl != NULL && lenCl >0)
    {
        for(int i=0; i<lenAl; i++)
        {
            if(listAl[i].isEmpty == 0)
            {

            }
        }
        ret = ALLOK;
    }
    return ret;
}


