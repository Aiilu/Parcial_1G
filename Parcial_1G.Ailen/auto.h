#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "marca.h"
#include "color.h"
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
    int id;
    char patente[7];
    int idMarca;
    int idColor;
    int modelo;
    int idCliente;
    int ocupado;

} eAuto;


/** \brief inicializa a los empleados
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \return void
 *
 */
void inicializarAutos(eAuto aut[], int tamAut);

/** \brief muestra las opciones al usuario
 *
 * \return int
 *
 */
int menu();

/** \brief busca espacio libre, y lo devuelve si esta vacio, si no, salta un mensaje de error
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \return int
 *
 */
int buscarLibreAuto(eAuto aut[], int tamAut);

/** \brief permite encontrar un auto mediante su ID
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param idAuto int
 * \return int
 *
 */
int buscarAuto(eAuto aut[], int tamAut, int idAuto);

/** \brief permite encontrar una patente comparando con el ingresado
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param idPatente[] int
 * \return int
 *
 */
int buscarPatente(eAuto aut[], int tamAut, int idPatente[]);

/** \brief ingresa los datos del auto a dar de alta
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \return void
 *
 */
void altaAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);

/** \brief muestra los datos de un auto
 *
 * \param aut eAuto
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \param cli[] eCliente
 * \param tamCli int
 * \return void
 *
 */
void mostrarAuto(eAuto aut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);

/** \brief muestra los datos de todos los autos mediante un recorrido de todo el array
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \param cli[] eCliente
 * \param tamCli int
 * \return void
 *
 */
void mostrarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);

/** \brief da de baja un auto, segun su patente
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
* \param cli[] eCliente
 * \param tamCli int
 * \return void
 *
 */
void bajaAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);

/** \brief modifica los valores a elegir por parte del usuario
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
* \param cli[] eCliente
 * \param tamCli int
 * \return void
 *
 */
void ModificacionAuto(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);

/** \brief lista los autos por marca y patente
 *
 * \param aut[] eAuto
 * \param tamAut int
 * \param mar[] eMarca
 * \param tamMar int
 * \param col[] eColor
 * \param tamCol int
 * \param cli[] eCliente
 * \param tamCli int
 * \return void
 *
 */
void listarAutos(eAuto aut[], int tamAut, eMarca mar[], int tamMar, eColor col[], int tamCol, eCliente cli[], int tamCli);

/** \brief harcodea datos de los autos
 *
 * \param
 * \param
 * \return
 *
 */

void harcodeAutos(eAuto aut[], int tamAut);
#endif // AUTO_H_INCLUDED
