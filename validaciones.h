#ifndef VALIDACIONES_H
#define VALIDACIONES_H

/* =========================================================
 * validaciones.h
 * Libreria de validacion de datos de entrada
 * ISWZ1102 - Programacion I - Unidad 4
 * ========================================================= */

/* ---------------------------------------------------------
 * SECCION 1: Validadores de rango
 * Reciben el valor YA convertido y retornan 1=valido, 0=invalido.
 * Son funciones puras: no hacen I/O.
 * --------------------------------------------------------- */
int validarEntero(int valor, int minimo, int maximo);
int validarDecimal(float valor, float minimo, float maximo);

/* ---------------------------------------------------------
 * SECCION 2: Validador de cadena de caracteres
 * Verifica que el texto contenga SOLO letras y espacios.
 * Retorna 1 si es valida, 0 si contiene digitos, simbolos
 * o si la cadena esta vacia / es solo espacios.
 * --------------------------------------------------------- */
int validarSoloLetras(const char *cadena);

/* ---------------------------------------------------------
 * SECCION 3: Lectores validados con punteros (paso por ref.)
 * Leen la linea completa con fgets (no con scanf) para
 * evitar que entradas como "2s2" o "2.s2" sean aceptadas
 * parcialmente. Validan tipo Y rango antes de convertir.
 * Escriben el resultado en la variable original via (*).
 * NUNCA usan return para devolver el valor leido.
 * --------------------------------------------------------- */
void leerEnteroValidado(const char *mensaje, int minimo, int maximo, int *resultado);
void leerDecimalValidado(const char *mensaje, float minimo, float maximo, float *resultado);
void leerNombreValidado(const char *mensaje, char *resultado, int tamMax);

#endif /* VALIDACIONES_H */
