#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "auto.h"
#include "marca.h"
#include "color.h"
#include "servicio.h"
#include "cliente.h"

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
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char patente[7];
    int idServicio;
    eFecha fechaTrabajo;
    int ocupado;

} eTrabajo;

/** \brief inicializa los trabajos
 *
 * \param tra[] eTrabajo
 * \param tamTra int
 * \return void
 *
 */
void inicializarTrabajo(eTrabajo tra[], int tamTra);

/** \brief busca espacio libre, y lo devuelve si esta vacio, si no, salta un mensaje de error
 *
 * \param tra[] eTrabajo
 * \param tamTra int
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo tra[], int tamTra);

/** \brief permite encontrar un trabajo mediante su ID
 *
 * \param tra[] eTrabajo
 * \param tamTra int
 * \param idTrabajo int
 * \return int
 *
 */
int buscarTrabajo(eTrabajo tra[], int tamTra, int idTrabajo);

/** \brief ingresa los datos del trabajo a dar de alta
 *
 * \param tra[] eTrabajo
 * \param tamTra int
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \param serv[] eServicio
 * \param tamServ int
 * \return void
 *
 */
void altaTrabajo(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);

/** \brief muestra datos de un trabajo
 *
 * \param tra eTrabajo
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \param serv[] eServicio
 * \param tamServ int
 * \param cli[] eCliente
 * \param tamCli int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo tra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ);

/** \brief muestra los datos de todos los trabajos mediante un recorrido de todo el array
 *
 * \param tra[] eTrabajo
 * \param tamTra int
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \param serv[] eServicio
 * \param tamServ int
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ);

/** \brief harcodea trabajos
 *
 * \param tra[] eTrabajo
 * \param tamTra int
 * \return void
 *
 */
void harcodeTrabajos(eTrabajo tra[],int tamTra);

void menuInformes(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void autosXmarca(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);
void autosXcolor(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);
void trabajosXauto(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void autosSinTrabajo(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void importesXauto(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void servicioMasPedido(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void importesXfecha(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void trabajosXfecha(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void autosEncerados(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void trabajosAutosBlancos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void importeXpulido(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
void marcasConMasLavadosCompletos(eTrabajo tra[], int tamTra, eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eServicio serv[], int tamServ, eCliente cli[], int tamCli);
#endif // TRABAJO_H_INCLUDED
