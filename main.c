#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib.h"
#include "hardcodeo.h"

#define TAM_C 100
#define TAM_A 100

int main()
{
    eCliente listCliente[TAM_C];
    eAlquiler listAlquiler[TAM_A];

    inicializarArray(listCliente,TAM_C);
    inicializarArrayAlquiler(listAlquiler,TAM_A);

    char salir = 'n';
    int idCliente = 1;
    int idAlquiler = 1;

    hardcodearClientes(listCliente,TAM_C,&idCliente,10);
    hardcodearAlquiler(listAlquiler,TAM_A,&idAlquiler,10);

    do
    {
        switch(menu())
        {
            case 1:
                altaCliente(listCliente,TAM_C,&idCliente);
                break;

            case 2:
                modificarCliente(listCliente,TAM_C);
                break;

            case 3:
                bajaCliente(listCliente,TAM_C);
                break;

            case 4:
                altaAlquiler(listAlquiler,TAM_A,&idAlquiler,listCliente,TAM_C);
                break;

            case 5:
                finAlquiler(listAlquiler,TAM_A,listCliente,TAM_C);
                break;

            case 6:
                switch(menu2())
                {
                case 1:
                    break;
                case 2:
                    equipoMasAlquilado(listAlquiler,TAM_A,listCliente,TAM_C);
                    break;
                case 3:
                    break;
                case 4:
                    mostrarListaClientes(listCliente,TAM_C);
                    break;
                case 5:
                    mostrarListaAlquiler(listAlquiler,TAM_A,listCliente,TAM_C);
                    break;

                }
                break;

            case 7:
                break;
        }

        system("pause");

    }
    while(salir == 'n');


    return 0;
}
