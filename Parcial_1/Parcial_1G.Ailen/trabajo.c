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
    char patente[6];
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


void menuInformes(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    char seguir = 's';
    char valOpcion[2];
    int opcion;

    do
    {

        system("cls");
        printf("     ===================================================\n");
        printf("     #           >>>> MENU DE INFORMES <<<<            #\n");
        printf("     ===================================================\n");
        printf("      1- Mostrar Autos sg ID Color                      \n");
        printf("      2- Mostrar Autos sg ID Marca                      \n");
        printf("      3- Trabajos efectuados x Auto                     \n");
        printf("      4- Autos sin ningun trabajo                       \n");
        printf("      5- Importe total sg Auto                          \n");
        printf("      6- Servicio + pedido                              \n");
        printf("      7- Recaudacion x Fecha                            \n");
        printf("      8- Autos y Fecha de los que realizaron encerados  \n");
        printf("      9- Trabajos realizados a autos blancos            \n");
        printf("      10- Importe Total x Pulidos                       \n");
        printf("      11- Marca que efectuo + lavados completos         \n");
        printf("      12- Autos con trabajos en una fecha determinada   \n");
        printf("      13- Salir                                         \n");
        printf("     ===================================================\n");
        printf("                                                        \n");
        printf("     Ingrese opcion: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {

        case 1:
            autosXcolor(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);
            system("pause");
            break;

        case 2:
            autosXmarca(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);
            system("pause");
            break;

        case 3:
            trabajosXauto(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 4:
            autosSinTrabajo(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 5:
            importesXauto(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 6:
            servicioMasPedido(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 7:
            importesXfecha(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 8:
            autosEncerados(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 9:
            trabajosAutosBlancos(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 10:
            importeXpulido(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 11:
            marcasConMasLavadosCompletos(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 12:
            trabajosXfecha(tra,tamTra,aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ,cli,tamCli);
            system("pause");
            break;

        case 13:
            seguir = 'n';
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }

        system("cls");
    }
    while(seguir == 's');
}


void autosXmarca(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{
    int flag = 0;
    int idMarca;
    char valMarca[4];

    listarMarcas(mar,tamMar);
    printf("Ingrese un ID Marca: ");
    fflush(stdin);
    gets(valMarca);

    idMarca = validarEnteroRango(valMarca,1000,1004);

    for(int i=0; i<tamAut; i++)
    {
        if(aut[i].idMarca == idMarca && aut[i].ocupado == OCUPADO)
        {
            mostrarAuto(aut[i],mar,tamMar,col,tamCol,cli,tamCli);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Nadie dio de Alta esta marca\n");
    }
}


void autosXcolor(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli)
{
    int flag = 0;
    int idColor;
    char valColor[4];

    listarColores(col,tamCol);
    printf("Ingrese un ID Color: ");
    fflush(stdin);
    gets(valColor);

    idColor = validarEnteroRango(valColor,5000,5004);

    for(int i=0; i<tamAut; i++)
    {
        if(aut[i].idColor == idColor && aut[i].ocupado == OCUPADO)
        {
            mostrarAuto(aut[i],mar,tamMar,col,tamCol,cli,tamCli);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Nadie dio de Alta este color\n");
    }
}


void trabajosXauto(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int flag = 0;
    char patente[6];

    mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);

    printf("Ingrese Patente: ");
    fflush(stdin);
    gets(patente);

    ValidarPatente(patente);

    if(buscarPatente(aut,tamAut,patente)==-1)
    {
        printf("Esta patente no existe\n");
    }
    else
    {
        for(int i=0; i<tamTra; i++)
        {
            if(tra[i].ocupado == OCUPADO)
            {
                for(int j=0; j<tamAut; j++)
                {
                    if(stricmp(tra[i].patente,patente) == 0 && aut[j].ocupado == OCUPADO)
                    {
                        mostrarTrabajo(tra[i],aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ);
                        flag = 1;
                    }
                }
            }
        }

        if(flag == 0)
        {
            printf("Este auto no esta trabajando\n");
        }
    }


}


void autosSinTrabajo(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int flag;

    for(int i=0; i<tamAut; i++)
    {
        flag = 0;

        for(int j=0; j<tamTra; j++)
        {
            if(strcmp(aut[i].patente,tra[j].patente) == 0 && aut[i].ocupado == OCUPADO && tra[j].ocupado == OCUPADO)
            {
                for(int k=0; k<tamServ; k++)
                {
                    if(serv[k].id == tra[j].idServicio)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
        }

        if(flag == 0 && aut[i].ocupado == OCUPADO)
        {
            printf("Autos que no tuvieron trabajos\n");

            mostrarAuto(aut[i],mar,tamMar,col,tamCol,cli,tamCli);

        }

    }

    if(flag == 1)
    {
        printf("Todos tienen algun servicio\n");
    }

}


void importesXauto(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int total = 0;
    char patente[6];

    mostrarAutos(aut,tamAut,mar,tamMar,col,tamCol,cli,tamCli);

    printf("Ingrese Patente: ");
    fflush(stdin);
    gets(patente);

    ValidarPatente(patente);

    if(buscarPatente(aut,tamAut,patente)==-1)
    {
        printf("Esta patente no existe\n");
    }
    else
    {
        for(int i=0; i<tamTra; i++)
        {

            if(stricmp(tra[i].patente,patente) == 0 && tra[i].ocupado == OCUPADO)
            {

                for(int j=0; j<tamServ; j++)
                {
                    if(serv[j].id == tra[i].idServicio)
                    {
                        total+=serv[j].precio;
                        break;
                    }
                }
            }
        }


        printf("Total recaudado: %d\n",total);
    }

}


void servicioMasPedido(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int cont[tamServ];
    int flag = 0;
    int mayor;

    for(int i=0; i<tamServ; i++)
    {
        cont[i] = 0;

        for(int j=0; j<tamTra; j++)
        {
            if(serv[i].id == tra[j].idServicio && tra[i].ocupado == OCUPADO)
            {
                for(int k=0; k<tamAut; k++)
                {
                    if(aut[k].ocupado == OCUPADO && strcmp(tra[j].patente,aut[k].patente)==0)
                    {
                        cont[i]++;

                    }
                }
            }
        }
    }


    for(int i=0; i<tamServ; i++)
    {
        if(flag == 0 || cont[i]>mayor)
        {
            mayor =  cont[i];

            flag = 1;
        }
    }


    printf("Servicio mas pedido:\n");


    for(int i=0; i<tamServ; i++)
    {
        if(cont[i] == mayor)
        {
            printf("%s\n",serv[i].descripcion);
        }
    }
}


void importesXfecha(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int total = 0;
    int flag = 0;

    eFecha fecha;

    char valDia[2];
    char valMes[2];
    char valAnio[4];

    printf("Ingrese anio: ");
    fflush(stdin);
    gets(valAnio);

    fecha.anio = validarEnteroRango(valAnio,2019,2080);

    printf("Ingrese mes: ");
    fflush(stdin);
    gets(valMes);

    fecha.mes = validarEnteroRango(valMes,1,12);

    printf("Ingrese dia: ");
    fflush(stdin);
    gets(valDia);

    if (fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11)
    {
        fecha.dia = validarEnteroRango(valDia,1,30);
    }
    else if(fecha.mes == 2)
    {
        fecha.dia = validarEnteroRango(valDia,1,28);
    }
    else
    {
        fecha.dia = validarEnteroRango(valDia,1,31);
    }


    for(int i=0; i<tamTra; i++)
    {
        if(compararFechas(tra[i].fechaTrabajo,fecha))
        {
            for(int j=0; j<tamAut; j++)
            {
                if(aut[j].ocupado == OCUPADO && strcmp(tra[i].patente,aut[j].patente) == 0 && tra[i].ocupado == OCUPADO)
                {
                    for(int k=0; k<tamServ; k++)
                    {
                        if(serv[k].id == tra[i].idServicio)
                        {
                            total+=serv[k].precio;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }


    if(flag == 0)
    {
        printf("No hay importes acumulados en esta fecha\n");
    }
    else
    {
        printf("Total recaudado en la fecha %0d/%0d/%d: %d\n",fecha.dia,fecha.mes,fecha.anio,total);
    }
}


void trabajosXfecha(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int flag = 0;

    eFecha fecha;

    char valDia[2];
    char valMes[2];
    char valAnio[4];

    printf("Ingrese anio: ");
    fflush(stdin);
    gets(valAnio);

    fecha.anio = validarEnteroRango(valAnio,2019,2080);

    printf("Ingrese mes: ");
    fflush(stdin);
    gets(valMes);

    fecha.mes = validarEnteroRango(valMes,1,12);

    printf("Ingrese dia: ");
    fflush(stdin);
    gets(valDia);

    if (fecha.mes == 4 || fecha.mes == 6 || fecha.mes == 9 || fecha.mes == 11)
    {
        fecha.dia = validarEnteroRango(valDia,1,30);
    }
    else if(fecha.mes == 2)
    {
        fecha.dia = validarEnteroRango(valDia,1,28);
    }
    else
    {
        fecha.dia = validarEnteroRango(valDia,1,31);
    }


    for(int i=0; i<tamTra; i++)
    {
        if(compararFechas(tra[i].fechaTrabajo,fecha))
        {
            for(int j=0; j<tamAut; j++)
            {
                if(aut[j].ocupado == OCUPADO && strcmp(tra[i].patente,aut[j].patente) == 0 && tra[i].ocupado == OCUPADO)
                {
                    for(int k=0; k<tamServ; k++)
                    {
                        if(serv[k].id == tra[i].idServicio)
                        {
                            mostrarAuto(aut[j],mar,tamMar,col,tamCol,cli,tamCli);
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }


    if(flag == 0)
    {
        printf("No hay trabajos en esta fecha\n");
    }
}


void autosEncerados(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    for(int i=0; i<tamTra; i++)
    {
        for(int j=0; j<tamAut; j++)
        {
            if(aut[j].ocupado == OCUPADO && tra[i].ocupado == OCUPADO && strcmp(tra[i].patente, aut[j].patente)==0)
            {
                for(int k=0; k<tamServ; k++)
                {
                    if(tra[i].idServicio == 20003)
                    {
                        printf("%s  %0d/%0d/%d\n",aut[j].patente,tra[i].fechaTrabajo.dia,tra[i].fechaTrabajo.mes,tra[i].fechaTrabajo.anio);
                        break;
                    }
                }
            }
        }
    }
}


void trabajosAutosBlancos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    for(int i=0; i<tamAut; i++)
    {
        if(aut[i].ocupado == OCUPADO && aut[i].idColor == 5001)
        {
            for(int j=0; j<tamTra; j++)
            {
                if(tra[j].ocupado == OCUPADO && strcmp(aut[i].patente,tra[j].patente)==0)
                {
                    mostrarTrabajo(tra[i],aut,tamAut,mar,tamMar,col,tamCol,serv,tamServ);
                    break;
                }
            }
        }
    }
}


void importeXpulido(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int flag = 0;
    int total = 0;

    for(int i=0; i<tamTra; i++)
    {
        if(tra[i].idServicio == 20001)
        {
            for(int j=0; j<tamAut; j++)
            {
                if(aut[j].ocupado == OCUPADO && strcmp(tra[i].patente,aut[j].patente) == 0 && tra[i].ocupado == OCUPADO)
                {
                    for(int k=0; k<tamServ; k++)
                    {
                        if(serv[k].id == tra[i].idServicio)
                        {
                            total+=serv[k].precio;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }


    if(flag == 0)
    {
        printf("No hay trabajos de pulido\n");
    }
    else
    {
        printf("Total acumulado x pulidos: %d\n",total);
    }
}


void marcasConMasLavadosCompletos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli)
{
    int cont[tamMar];
    int flag = 0;
    int mayor;

    for(int i=0; i<tamMar; i++)
    {
        cont[i] = 0;

        for(int j=0; j<tamTra; j++)
        {
            if(tra[j].idServicio == 20003)
            {
                for(int k=0; k<tamAut; k++)
                {
                    if(strcmp(tra[j].patente,aut[k].patente)==0 && mar[i].id == aut[k].idMarca)
                    {
                        cont[i]++;
                    }
                }
            }
        }
    }


    for(int i=0; i<tamMar; i++)
    {
        if(flag == 0 || cont[i]>mayor)
        {
            mayor =  cont[i];

            flag = 1;
        }
    }


    printf("Marca con + lavados completos:\n");


    for(int i=0; i<tamMar; i++)
    {
        if(cont[i] == mayor)
        {
            printf("%s\n",mar[i].descripcion);
        }
    }
}
