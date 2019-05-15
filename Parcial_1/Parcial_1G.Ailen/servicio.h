#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

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
    char descripcion[20];
    int precio;

} eServicio;

/** \brief harcodea los servicios
 *
 * \param serv[] eServicio
 * \param tamServ int
 * \return void
 *
 */
void harcodeServicios(eServicio serv[], int tamServ);

/** \brief lista los servicios
 *
 * \param serv[] eServicio
 * \param tamServ int
 * \return void
 *
 */
void listarServicios(eServicio serv[], int tamServ);

/** \brief obtiene la descripcion de servicios segun su ID, recorriendo toda la cadena
 *
 * \param serv[] eServicio
 * \param tamServ int
 * \param idServicio int
 * \param cadena[] char
 * \return void
 *
 */
void ObtenerServicios(eServicio serv[], int tamServ, int idServicio, char cadena[]);
#endif // SERVICIO_H_INCLUDED
