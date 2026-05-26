#ifndef VALIDACIONES_H
#define VALIDACIONES_H

/* =========================================================
 * validaciones.h
 * Libreria de validacion de datos numericos
 * ISWZ1102 - Programacion I - Unidad 4
 * ========================================================= */

/* ---------------------------------------------------------
 * SECCION 1: Validadores de rango (retornan 1=valido, 0=invalido)
 * --------------------------------------------------------- */
int validarEntero(int valor, int minimo, int maximo);
int validarDecimal(float valor, float minimo, float maximo);

/* ---------------------------------------------------------
 * SECCION 2: Lectores validados con punteros (paso por referencia)
 * NO usan return para devolver el valor leido;
 * modifican la variable original a traves del puntero.
 * --------------------------------------------------------- */
void leerEnteroValidado(const char *mensaje, int minimo, int maximo, int *resultado);
void leerDecimalValidado(const char *mensaje, float minimo, float maximo, float *resultado);

#endif /* VALIDACIONES_H */
