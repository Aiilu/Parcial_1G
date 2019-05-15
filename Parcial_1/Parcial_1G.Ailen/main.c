#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "validaciones.h"
#include "cliente.h"

#define VACIO 0
#define OCUPADO 1

#define TAM 24
#define MAR 5
#define COL 5
#define SERV 4
#define TRA 38
#define CLI 6

int main()
{
    char seguir = 's';
    //int flagAuto = 0;
    //int flagTrabajo = 0;
    //int flagNoTrabajo = 0;

    eAuto autos[TAM];
    eMarca marca[MAR];
    eColor color[COL];
    eServicio servicio[SERV];
    eTrabajo trabajo[TRA];
    eCliente cliente[CLI];

    //inicializarAutos(autos,TAM);
    //inicializarTrabajo(trabajo,TRA);

    harcodeAutos(autos,TAM);
    harcodeColores(color,COL);
    harcodeMarcas(marca,MAR);
    harcodeServicios(servicio,SERV);
    harcodeTrabajos(trabajo,TRA);
    harcodeoClientes(cliente,CLI);

    do
    {
        switch(menu())
        {


        case 1:
            altaAutos(autos,TAM,marca,MAR,color,COL,cliente,CLI);
            system("pause");
            break;


        case 2:
            ModificacionAuto(autos,TAM,marca,MAR,color,COL,cliente,CLI);
            system("pause");
            break;


        case 3:
            bajaAuto(autos,TAM,marca,MAR,color,COL,cliente,CLI);
            system("pause");
            break;


        case 4:

            listarAutos(autos,TAM,marca,MAR,color,COL,cliente,CLI);
            system("pause");
            break;


        case 5:
            system("cls");
            printf("LISTA MARCAS\n");
            listarMarcas(marca,MAR);
            system("pause");
            break;


        case 6:
            system("cls");
            printf("LISTA COLORES\n");
            listarColores(color,COL);
            system("pause");
            break;


        case 7:
            system("cls");
            printf("LISTA SERVICIOS\n");
            listarServicios(servicio,SERV);
            system("pause");
            break;


        case 8:
            altaTrabajo(trabajo,TRA,autos,TAM,marca,MAR,color,COL,servicio,SERV,cliente,CLI);
            system("pause");
            break;

        case 9:
            mostrarTrabajos(trabajo,TRA,autos,TAM,marca,MAR,color,COL,servicio,SERV);
            system("pause");
            break;


        case 10:
            menuInformes(trabajo,TRA,autos,TAM,marca,MAR,color,COL,servicio,SERV,cliente,CLI);
            system("pause");
            break;

            case 11:
            system("cls");
            printf("Hasta luego");
            seguir = 'n';
            break;


        default:
            printf("\n     Opcion invalida\n\n");
            system("pause");
            break;
        }

    }
    while(seguir == 's');

    return 0;
}
