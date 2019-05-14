#include "auto.h"
#include "marca.h"
#include "color.h"
#include "validaciones.h"
#include "cliente.h"

void inicializarAutos(eAuto aut[], int tamAut)
{
    for(int i=0; i < tamAut; i++)
    {
        aut[i].ocupado = VACIO;
    }
}



int menu()
{
    int opcion;
    char valOpcion[2];

    system("cls");
    system("COLOR F0");
    printf("     =================================================\n");
    printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
    printf("     =================================================\n");
    printf("     |                                               |\n");
    printf("                  1- Alta Auto                        \n");
    printf("     |                                               |\n");
    printf("                  2- Modificacion Auto                \n");
    printf("     |                                               |\n");
    printf("                  3- Baja Auto                        \n");
    printf("     |                                               |\n");
    printf("                  4- Listar x Marca/Patente           \n");
    printf("     |                                               |\n");
    printf("                  5- Listar Marcas                    \n");
    printf("     |                                               |\n");
    printf("                  6- Listar Colores                   \n");
    printf("     |                                               |\n");
    printf("                  7- Listar Servicios                 \n");
    printf("     |                                               |\n");
    printf("                  8- Alta Trabajo                     \n");
    printf("     |                                               |\n");
    printf("                  9- Listar Trabajos                  \n");
    printf("     |                                               |\n");
    printf("                  10- Informes                        \n");
    printf("     |                                               |\n");
    printf("                  11- Salir                           \n");
    printf("     |                                               |\n");
    printf("     =================================================\n");
    printf("                                                      \n");
    printf("     Ingrese opcion: ");
    fflush(stdin);
    gets(valOpcion);

    opcion = validarEntero(valOpcion);

    return opcion;
}



int buscarLibreAuto(eAuto aut[], int tamAut)
{

    int indice = -1;

    for(int i=0; i < tamAut; i++)
    {
        if(aut[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int buscarAuto(eAuto aut[], int tamAut, int idAuto)
{

    int indice = -1;

    for(int i=0; i < tamAut; i++)
    {
        if( aut[i].id == idAuto && aut[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarPatente(eAuto aut[], int tamAut, int idPatente[])
{

    int indice = -1;

    for(int i=0; i < tamAut; i++)
    {
        if( stricmp(aut[i].patente,idPatente) == 0 && aut[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void altaAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{
    char patente[6];
    int idMarca;
    char valMarca[4];
    int idColor;
    char valColor[4];
    int modelo;
    char valModelo[4];
    int idCliente;
    int indice;
    char seguir;

    do
    {

        system("cls");
        printf("Alta Auto\n");


        indice = buscarLibreAuto(aut,tamAut);

        if(indice == -1)
        {
            printf("No hay mas espacio para cargar autos\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(patente);

            ValidarPatente(patente);

            if(buscarPatente(aut,tamAut,patente)!=-1)
            {
                printf("La patente %s ya esta en uso\n",patente);
                system("pause");
                break;
            }
            else
            {
                strcpy(aut[indice].patente,patente);

                listarMarcas(mar,tamMar);
                printf("Ingrese ID Marca: ");
                fflush(stdin);
                gets(valMarca);

                idMarca = validarEnteroRango(valMarca,1000,1004);

                aut[indice].idMarca = idMarca;

                listarColores(col,tamCol);
                printf("Ingrese ID Color: ");
                fflush(stdin);
                gets(valColor);

                idColor = validarEnteroRango(valColor,5000,5004);

                aut[indice].idColor = idColor;

                printf("Ingrese modelo (anio de fabricacion): ");
                fflush(stdin);
                gets(valModelo);

                modelo = validarEnteroRango(valModelo,1970,2019);

                mostrarClientes(cli,tamCli);
                printf("Ingrese ID cliente: ");
                scanf("%d",&idCliente);

                aut[indice].idCliente = idCliente;

                aut[indice].id = cargarId();

                aut[indice].modelo = modelo;

                aut[indice].ocupado = OCUPADO;


                printf("El Auto se ha registrado con exito!!\n");


                seguir = validarSeguir();

            }
        }
    }
    while(seguir == 'S' || seguir == 's');
}



void mostrarAuto(eAuto aut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{
    char marca[20];
    char color[20];
    char nombre[10];
    char sexo;
    int id;

    for(int i=0; i<tamMar; i++)
    {
        if(mar[i].id == aut.idMarca)
        {
            strcpy(marca,mar[i].descripcion);
            break;
        }
    }

    for(int j=0; j<tamCol; j++)
    {
        if(col[j].id == aut.idColor)
        {
            strcpy(color,col[j].nombreColor);
            break;
        }
    }

    for(int k=0; k<tamCli; k++)
    {
        if(cli[k].id == aut.idCliente)
        {
            id = cli[k].id;
            strcpy(nombre,cli[k].nombre);
            sexo = cli[k].sexo;
            break;
        }
    }

    printf("%4d %8s %9s %6s %6d  %6d  %10s  %6c\n", aut.id, aut.patente, marca, color, aut.modelo, id, nombre, sexo);

}



void mostrarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{
    int flag = 0;

    system("cls");
    printf("  ID   Patente   Marca   Color   Modelo   idCliente   Nombre   Sexo\n\n");


    for(int i=0; i<tamAut; i++)
    {
        if(aut[i].ocupado == OCUPADO)
        {
            mostrarAuto(aut[i],mar,tamMar,col,tamCol,cli,tamCli);
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("No hay autos cargados\n");

    }
}


void bajaAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{

    char patente[6];
    char seguir;
    int esta;

    printf("Baja Auto\n");
    printf("\n\n");

    mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);

    printf("Ingrese patente: ");
    fflush(stdin);
    gets(patente);

    esta = buscarPatente(aut,tamAut,patente);

    if( esta == -1)
    {

        printf("\nLa patente %s no esta registrada en el sistema\n", patente);
    }
    else
    {
        printf("Auto a eliminar\n");

        mostrarAuto(aut[esta],mar,tamMar,col,tamCol,cli,tamCli);

        seguir = validarSeguir();

        if(seguir == 's' || seguir == 'S')
        {
            aut[esta].ocupado = VACIO;
            printf("\nAuto eliminado con exito\n");
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }


    }



void ModificacionAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{

    char patente[6];
    int idColor;
    char valColor[4];
    int idModelo;
    char valModelo[4];
    int opcion;
    char valOpcion[2];
    int esta;
    char seguir;

    printf("Modificacion Auto\n");
    printf("\n\n");

    mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);

    printf("Ingrese patente: ");
    fflush(stdin);
    gets(patente);

    esta = buscarPatente(aut,tamAut,patente);


    if( esta == -1)
    {

        printf("\nLa patente %s no esta registrada en el sistema\n", patente);
    }
    else
    {
        printf("\n\n");
        system("cls");
        printf("Auto a modificar\n");
        mostrarAuto(aut[esta],mar,tamMar,col,tamCol,cli,tamCli);

        printf("     Que desea modificar?\n");
        printf("     1. Color\n     2. Modelo\n");
        printf("     Ingrese opcion: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            system("cls");

            printf("Modificar Color\n");

            listarColores(col,tamCol);

            printf("Ingrese un nuevo color: ");
            fflush(stdin);
            gets(valColor);

            idColor = validarEnteroRango(valColor,5000,5004);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                aut[esta].idColor = idColor;

                printf("\n\n");
                printf("     Modificacion exitosa!\n");

            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        case 2:
            system("cls");

            printf("Modificar Modelo\n");

            printf("Ingrese un nuevo modelo: ");
            fflush(stdin);
            gets(valModelo);

            idModelo = validarEnteroRango(valModelo,1970,2019);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                aut[esta].modelo = idModelo;

                printf("\n\n");
                printf("     Modificacion exitosa!\n");

            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        default:
            printf("Esta opcion no existe\n");
            break;

        }
    }

}


void listarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{
   eAuto aux;

   for(int i=0; i<tamAut-1; i++)
   {
       for(int j=i+1; j<tamAut; j++)
       {
           if(aut[i].idMarca > aut[j].idMarca)
           {
               aux = aut[i];
               aut[i] = aut[j];
               aut[j] = aux;
           }
           else if(aut[i].idMarca == aut[j].idMarca && stricmp(aut[i].patente,aut[j].patente)>0)
           {
               aux = aut[i];
               aut[i] = aut[j];
               aut[j] = aux;
           }
       }
   }

   mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);

}


void harcodeAutos(eAuto aut[], int tamAut)
{
    eAuto hardcode[]=
    {
       {1, "AAA201", 1000, 5001, 1995,1, 1},
       {2, "DFR234", 1003, 5000, 2002,2, 1},
       {3, "GFT564", 1002, 5003, 2007,3, 1},
       {4, "ACD321", 1002, 5003, 1995,4, 1},
       {5, "HTD656", 1004, 5002, 2008,5, 1},
       {6, "QSZ435", 1003, 5001, 1994,6, 1},
       {7, "LGX201", 1001, 5000, 2012,1, 1},
       {8, "SUZ324", 1001, 5002, 1991,1, 1},
       {9, "HCU762", 1000, 5003, 2008,2, 1},
       {10, "DYC735", 1003, 5001, 2002,3, 1},
       {11, "JJK879", 1003, 5001, 2010,3, 1},
       {12, "FED322", 1004, 5002, 2006,4, 1},
       {13, "GHV332", 1001, 5003, 2007,5, 1},
       {14, "BDE221", 1000, 5004, 1996,6, 1},
       {15, "OPD332", 1000, 5001, 2014,2, 1},
       {16, "PPD121", 1002, 5001, 2015,6, 1},
       {17, "IIT230", 1001, 5000, 2009,2, 1},
       {18, "KOD220", 1004, 5002, 2011,3, 1},
       {19, "QSZ305", 1004, 5002, 1993,4, 1},
       {20, "SSD128", 1002, 5003, 1992,1, 1},
       {21, "SSD240", 1003, 5004, 1992,5, 1},
       {22, "EDF213", 1001, 5000, 2001,2, 1},
       {23, "EDF213", 1001, 5000, 2001,6, 0},
       {24, "EDF213", 1001, 5000, 2001,5, 0}

    };


    for(int i=0; i<tamAut; i++)
    {
        aut[i]=hardcode[i];
    }
}
