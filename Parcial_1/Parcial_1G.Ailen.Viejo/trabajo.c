#include "trabajo.h"
#include "servicio.h"
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "validaciones.h"
#include "cliente.h"

void harcodeTrabajos(eTrabajo tra[], int tamTra)
{
    eTrabajo hardcode[]=
    {
        {1, "AAA201", 20000, {12,3,2019}, 1},
        {2, "DFR234", 20000, {2,4,2019}, 1},
        {3, "GFT564", 20001, {7,1,2019}, 1},
        {4, "ACD321", 20002, {9,11,2019}, 1},
        {5, "HTD656", 20003, {12,12,2019}, 1},
        {6, "QSZ435", 20001, {21,7,2019}, 1},
        {7, "LGX201", 20001, {29,8,2019}, 1},
        {8, "SUZ324", 20004, {31,5,2019}, 1},
        {9, "HCU762", 20004, {2,2,2019}, 1},
        {10, "DYC735", 20000, {18,2,2019}, 1},
        {11, "JJK879", 20001, {17,3,2019}, 1},
        {12, "AAA201", 20000, {17,4,2019}, 1},
        {13, "DFR234", 20000, {2,6,2019}, 1},
        {14, "GFT564", 20001, {7,3,2019}, 1},
        {15, "ACD321", 20002, {21,7,2019}, 1},
        {16, "HTD656", 20003, {11,9,2019}, 1},
        {17, "QSZ435", 20001, {3,7,2019}, 1},
        {18, "LGX201", 20001, {21,8,2019}, 1},
        {19, "SUZ324", 20004, {28,5,2019}, 1},
        {20, "HCU762", 20004, {2,8,2019}, 1},
        {21, "DYC735", 20000, {8,2,2019}, 1},
        {22, "JJK879", 20001, {17,3,2019}, 1},
        {23, "KOD220", 20003, {17,4,2019}, 1},
        {24, "QSZ305", 20000, {21,3,2019}, 1},
        {25, "SSD128", 20002, {16,4,2019}, 1},
        {26, "SSD240", 20000, {17,4,2019}, 1},
        {27, "EDF213", 20001, {23,3,2019}, 1},
        {28, "AAA201", 20000, {12,2,2019}, 1},
        {29, "DFR234", 20000, {2,3,2019}, 1},
        {30, "GFT564", 20001, {7,2,2019}, 1},
        {31, "ACD321", 20002, {9,12,2019}, 1},
        {32, "HTD656", 20003, {12,9,2019}, 1},
        {33, "QSZ435", 20001, {21,5,2019}, 1},
        {34, "HTD656", 20002, {12,2,2019}, 1},
        {35, "QSZ435", 20000, {21,1,2019}, 1},
        {36, "GFT564", 20003, {21,1,2019}, 0},
        {37, "QSZ435", 20000, {21,1,2019}, 0},
        {38, "QSZ435", 20000, {21,1,2019}, 0},
    };

    for(int i=0; i<tamTra; i++)
    {
        tra[i]=hardcode[i];
    }
}


void inicializarTrabajo(eTrabajo tra[], int tamTra)
{

    for(int i=0; i < tamTra; i++)
    {
        tra[i].ocupado = VACIO;
    }
}



int buscarLibreTrabajo(eTrabajo tra[], int tamTra)
{

    int indice = -1;

    for(int i=0; i < tamTra; i++)
    {
        if(tra[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarTrabajo(eTrabajo tra[], int tamTra, int idTrabajo)
{
    int indice= -1;

    for(int i=0; i<tamTra; i++)
    {
        if(tra[i].id == idTrabajo && tra[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;

}


void altaTrabajo(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    char patente[7];
    int idServicio;
    char valServicio[5];
    int indice;
    char seguir;
    char valDia[2];
    char valMes[2];
    char valAnio[4];

    do
    {

        system("cls");
        printf("Alta Trabajo\n");


        indice = buscarLibreTrabajo(tra,tamTra);


        if(indice == -1)
        {
            printf("No hay mas espacio para cargar trabajos\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {

            mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);

            printf("Ingrese patente: ");
            fflush(stdin);
            gets(patente);

            if(buscarPatente(aut,tamAut,patente)== -1)
            {
                printf("Esta patente no existe\n");
                system("pause");
                break;
            }
            else
            {
                strcpy(tra[indice].patente,patente);
            }

            listarServicios(serv,tamServ);

            printf("Ingrese ID Servicio: ");
            fflush(stdin);
            gets(valServicio);

            idServicio = validarEnteroRango(valServicio,20000,20003);

            tra[indice].idServicio = idServicio;

            printf("Fecha de Inicio\n");

            printf("Ingrese anio: ");
            fflush(stdin);
            gets(valAnio);

            tra[indice].fechaTrabajo.anio = validarEnteroRango(valAnio,2019,2080);

            printf("Ingrese mes: ");
            fflush(stdin);
            gets(valMes);

            tra[indice].fechaTrabajo.mes = validarEnteroRango(valMes,1,12);

            printf("Ingrese dia: ");
            fflush(stdin);
            gets(valDia);

            if (tra[indice].fechaTrabajo.mes == 4 ||tra[indice].fechaTrabajo.mes == 6 || tra[indice].fechaTrabajo.mes == 9 || tra[indice].fechaTrabajo.mes == 11)
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,30);
            }
            else if(tra[indice].fechaTrabajo.mes == 2)
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,28);
            }
            else
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,31);
            }

            tra[indice].id = cargarIdTrabajo();

            tra[indice].ocupado = OCUPADO;


            printf("El Trabajo se ha registrado con exito!!\n");


            seguir = validarSeguir();

        }
    }
    while(seguir == 'S' || seguir == 's');
}


void mostrarTrabajo(eTrabajo tra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ)
{
    char marca[20];
    char servicio[20];
    int loMuestro;

    for(int i=0; i<tamAut; i++)
    {
        if(stricmp(aut[i].patente,tra.patente) == 0)
        {
            for(int j=0; j<tamMar; j++)
            {
                if(mar[j].id == aut[i].idMarca)
                {
                    strcpy(marca,mar[j].descripcion);
                    loMuestro = aut[i].ocupado;
                    break;
                }
            }
        }
    }

    for(int k=0; k<tamServ; k++)
    {
        if(serv[k].id == tra.idServicio)
        {
            strcpy(servicio,serv[k].descripcion);
            break;
        }
    }

    if(loMuestro)
    {
        printf("%5d %9s %9s %9s %02d/%02d/%d\n", tra.id, servicio, marca, tra.patente, tra.fechaTrabajo.dia, tra.fechaTrabajo.mes, tra.fechaTrabajo.anio);
    }

}



void mostrarTrabajos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ)
{
    int flag = 0;


    system("cls");
    printf("  ID   Servicio   Marca  Patente  Fecha\n\n");


    for(int i=0; i<tamTra; i++)
    {
        if(tra[i].ocupado == OCUPADO)
        {
            mostrarTrabajo(tra[i],aut,tamAut,mar,tamMar,col,tamMar,serv,tamServ);
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("No hay trabajos cargados\n");
    }

}

