#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "trabajo.h"

/** \brief carga el id incrementalmente
 *
 * \return int
 *
 */
int cargarId();

/** \brief carga el id trabajo incrementalmente
 *
 * \return int
 *
 */
int cargarIdTrabajo();

/** \brief pregunta si desea continuar
 *
 * \return char
 *
 */
char validarSeguir();

/** \brief compara que las fechas sean iguales
 *
 * \param
 * \param
 * \return
 *
 */
int compararFechas(eFecha fech, eFecha fecha);

/** \brief recorre la cadena buscando que cada uno de sus chars sea igual a positivo o cero
 *
 * \param entero[] char
 * \return int
 *
 */
int validarEntero(char entero[]);

/** \brief valida que lo ingresado sea alfanumerico, solo letras, numero o un espacio entre ellos
 *
 * \param x[] char
 * \param largo int
 * \return void
 *
 */
void validarAlfaNum(char x[], int largo);

/** \brief valida que la patente sea alfanumerica
 *
 * \param x[] char
 * \return void
 *
 */
void ValidarPatente(char x[]);
int validarEnteroRango(char entero[], int corto, int largo);
int validarEnteroTam(char entero[], int largo);
void validarStringTam(char x[], int largo);

#endif // VALIDACIONES_H_INCLUDED
