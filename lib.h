#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#define ERROR -1
#define ALLOK 1

#define AMOLADORA 10
#define MEZCLADORA 11
#define TALADRO 12

#define ALQUILADO 13
#define FINALIZADO -13

#include "Genericas.h"


typedef struct
{
    int id;
    int dni;
    char nombre[24];
    char apellido[24];
    int isEmpty;

}eCliente;

typedef struct
{
    int id;
    int idCliente;
    int idEquipo;
    int idTiempo;
    char operador[24];
    int estado;
    int isEmpty;

}eAlquiler;

int menu();
int menu2();
int inicializarArray(eCliente list[],int len);
int buscarLibre(eCliente list[],int len);
int altaCliente(eCliente list[],int len,int* idPtr);
int modificarCliente(eCliente list[],int len);
int bajaCliente(eCliente list[],int len);
int retornarIndicePorID(eCliente list[],int len,int idValidar);
int validarIDCliente(eCliente list[],int len,int idValidar);

int mostrarListaClientes(eCliente list[],int len);
int mostrarUnaCliente(eCliente* unCliente);

//----//
int validarIDAlquiler(eAlquiler list[],int len,int idValidar);
int inicializarArrayAlquiler(eAlquiler list[],int len);
void mostrarListaEquipos();
int altaAlquiler(eAlquiler list[],int len,int* idPtr,eCliente listCliente[],int lenCliente);
int buscarLibreAlquiler(eAlquiler list[],int len);
void mostrarTiempoEstimado();
int cargarNombreCliente(eCliente list[],int len,int idCliente,char* nombre);
int cargarApellidoCliente(eCliente list[],int len,int idCliente,char* apellido);
int cargarNombreEquipo(int id,char* equipo);
int cargarTiempoEstimado(int id,char* tiempo);
int mostrarUnAlquiler(eAlquiler* UnAlquiler,eCliente listCliente[],int lenCliente);
int mostrarListaAlquiler(eAlquiler list[], int len,eCliente listCliente[],int lenCliente);
int finAlquiler(eAlquiler list[],int len,eCliente listCliente[],int lenCliente);
int equipoMasAlquilado(eAlquiler listAl[],int lenAl,eCliente listCl[],int lenCl);


#endif // LIB_H_INCLUDED
