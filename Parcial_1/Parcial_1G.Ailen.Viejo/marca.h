#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

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

} eMarca;

/** \brief harcodea las marcas
 *
 * \param mar[] eMarca
 * \param tamMar int
 * \return void
 *
 */
void harcodeMarcas(eMarca mar[], int tamMar);

/** \brief lista las marcas
 *
 * \param mar[] eMarca
 * \param tamMar int
 * \return void
 *
 */
void listarMarcas(eMarca mar[], int tamMar);

/** \brief obtiene la descripcion de la marca segun su ID, recorriendo toda la cadena
 *
 * \param mar[] eMarca
 * \param tamMar int
 * \param idMarca int
 * \param cadena[] char
 * \return void
 *
 */
void ObtenerMarcas(eMarca mar[], int tamMar, int idMarca, char cadena[]);
#endif // MARCA_H_INCLUDED
