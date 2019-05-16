#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define VACIO 0
#define OCUPADO 1

#define TAM 24
#define MAR 5
#define COL 5
#define SERV 4
#define TRA 38
#define CLI 6

typedef struct
{
    int id;
    char nombre[10];
    char sexo;
}eCliente;

void harcodeoClientes(eCliente cli[], int tamCli);
void mostrarCliente(eCliente cliente);
void mostrarClientes(eCliente x[], int tam);

#endif // CLIENTE_H_INCLUDED
