/* =========================================================
 * validaciones.c
 * Implementacion de la libreria de validaciones
 * ISWZ1102 - Programacion I - Unidad 4
 * ========================================================= */

#include <stdio.h>
#include "validaciones.h"

/* ---------------------------------------------------------
 * SECCION 1: Validadores de rango
 * Reciben el valor ya leido y comprueban si esta en rango.
 * Retornan 1 si el dato es valido, 0 si no lo es.
 * --------------------------------------------------------- */

/* Valida que un entero este dentro de [minimo, maximo] */
int validarEntero(int valor, int minimo, int maximo) {
    return (valor >= minimo && valor <= maximo);
}

/* Valida que un decimal este dentro de (minimo, maximo) exclusivo */
int validarDecimal(float valor, float minimo, float maximo) {
    return (valor > minimo && valor < maximo);
}

/* ---------------------------------------------------------
 * SECCION 2: Lectores validados con punteros
 * Piden el dato al usuario, validan con la funcion
 * correspondiente y, si es correcto, escriben el valor
 * en la variable original a traves del puntero.
 * El bucle repite hasta que el dato sea valido.
 * NO se usa return para devolver el valor leido.
 * --------------------------------------------------------- */

/* Lee y valida un entero; guarda el resultado via puntero */
void leerEnteroValidado(const char *mensaje, int minimo, int maximo, int *resultado) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
        if (!validarEntero(valor, minimo, maximo)) {
            printf(" >> Error: dato fuera de rango, intente de nuevo\n");
        }
    } while (!validarEntero(valor, minimo, maximo));

    *resultado = valor;   /* modificacion via desreferenciacion */
}

/* Lee y valida un decimal; guarda el resultado via puntero */
void leerDecimalValidado(const char *mensaje, float minimo, float maximo, float *resultado) {
    float valor;
    do {
        printf("%s", mensaje);
        scanf("%f", &valor);
        if (!validarDecimal(valor, minimo, maximo)) {
            printf(" >> Error: dato fuera de rango, intente de nuevo\n");
        }
    } while (!validarDecimal(valor, minimo, maximo));

    *resultado = valor;   /* modificacion via desreferenciacion */
}
