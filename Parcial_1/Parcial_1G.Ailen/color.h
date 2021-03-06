#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

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
#define SERV 5
#define TRA 38
#define CLI 6

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

void listarColores(eColor col[], int tamCol);
void harcodeColores(eColor col[], int tamCol);
void obtenerColor(eColor col[], int tamCol, int idColor, char cadena[]);
#endif // COLOR_H_INCLUDED
