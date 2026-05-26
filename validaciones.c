/* =========================================================
 * validaciones.c
 * Implementacion de la libreria de validaciones
 * ISWZ1102 - Programacion I - Unidad 4
 * ========================================================= */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "validaciones.h"

/* =========================================================
 * FUNCION INTERNA (static): leerLinea
 * Lee una linea completa de stdin con fgets y elimina el
 * '\n' final. Al leer TODA la linea de golpe, nada queda
 * en el buffer y se evita el bug de scanf que acepta "2s2"
 * leyendo solo el "2" y dejando "s2" pendiente.
 * Es static: invisible fuera de este archivo.
 * ========================================================= */
static void leerLinea(char *buffer, int tam) {
    fgets(buffer, tam, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

/* =========================================================
 * FUNCION INTERNA (static): esSoloEntero
 * Recorre la cadena caracter a caracter y verifica que:
 *   - Sea no vacia.
 *   - Contenga UNICAMENTE digitos (0-9).
 *   - Opcionalmente un signo '-' o '+' al inicio.
 * Retorna 1 si es un entero puro, 0 si contiene cualquier
 * letra, punto, coma u otro simbolo (ej: "2s2", "2.5").
 * ========================================================= */
static int esSoloEntero(const char *cadena) {
    int i = 0;
    if (cadena == NULL || cadena[0] == '\0') return 0;

    /* Permite signo opcional al inicio */
    if (cadena[0] == '-' || cadena[0] == '+') i = 1;

    /* Debe haber al menos un digito despues del signo */
    if (cadena[i] == '\0') return 0;

    for (; cadena[i] != '\0'; i++) {
        if (!isdigit((unsigned char)cadena[i])) return 0;
    }
    return 1;
}

/* =========================================================
 * FUNCION INTERNA (static): esSoloDecimal
 * Verifica que la cadena sea un numero decimal valido:
 *   - Solo digitos, con UN punto decimal opcional.
 *   - Signo '-' o '+' opcional al inicio.
 *   - Rechaza: "2s2", "2.s2", "1.2.3", "abc", "".
 * ========================================================= */
static int esSoloDecimal(const char *cadena) {
    int i = 0;
    int puntos = 0;
    if (cadena == NULL || cadena[0] == '\0') return 0;

    /* Permite signo opcional al inicio */
    if (cadena[0] == '-' || cadena[0] == '+') i = 1;

    /* Debe haber al menos un caracter despues del signo */
    if (cadena[i] == '\0') return 0;

    for (; cadena[i] != '\0'; i++) {
        if (cadena[i] == '.') {
            puntos++;
            if (puntos > 1) return 0;  /* mas de un punto: invalido */
        } else if (!isdigit((unsigned char)cadena[i])) {
            return 0;  /* cualquier letra u otro simbolo: invalido */
        }
    }
    return 1;
}

/* ---------------------------------------------------------
 * SECCION 1: Validadores de rango
 * Reciben el valor ya convertido y comprueban el rango.
 * Retornan 1=valido, 0=invalido.
 * Funciones puras: no hacen I/O.
 * --------------------------------------------------------- */

int validarEntero(int valor, int minimo, int maximo) {
    return (valor >= minimo && valor <= maximo);
}

int validarDecimal(float valor, float minimo, float maximo) {
    return (valor > minimo && valor < maximo);
}

/* ---------------------------------------------------------
 * SECCION 2: Validador de cadena de caracteres
 * Verifica que el texto contenga SOLO letras y espacios.
 * Rechaza digitos, simbolos y cadenas vacias/solo espacios.
 * --------------------------------------------------------- */
int validarSoloLetras(const char *cadena) {
    int i;
    int tieneLetra = 0;
    if (cadena == NULL || cadena[0] == '\0') return 0;

    for (i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == ' ') {
            continue;  /* espacio permitido para nombres compuestos */
        }
        if (!isalpha((unsigned char)cadena[i])) {
            return 0;  /* digito, simbolo u otro: invalido */
        }
        tieneLetra = 1;
    }
    return tieneLetra;  /* 0 si era solo espacios, 1 si habia al menos una letra */
}

/* ---------------------------------------------------------
 * SECCION 3: Lectores validados con punteros (paso por ref.)
 *
 * ESTRATEGIA ANTI-BUG:
 * Se usa fgets (via leerLinea) para capturar TODA la linea
 * de una vez. Luego se verifica con esSoloEntero /
 * esSoloDecimal que NO haya letras ni simbolos mezclados.
 * Solo si pasa esa prueba se convierte con atoi / atof y
 * se comprueba el rango con validarEntero / validarDecimal.
 * Esto evita el bug de scanf que acepta "2s2" como 2.
 *
 * NUNCA se usa return para devolver el valor; se escribe
 * en la variable original via desreferenciacion (*resultado).
 * --------------------------------------------------------- */

void leerEnteroValidado(const char *mensaje, int minimo, int maximo, int *resultado) {
    char buffer[64];
    int  valor  = 0;
    int  valido = 0;

    do {
        printf("%s", mensaje);
        leerLinea(buffer, sizeof(buffer));

        if (!esSoloEntero(buffer)) {
            /* Contiene letras, puntos u otros simbolos */
            printf(" >> Error: dato fuera de rango, intente de nuevo\n");
            valido = 0;
        } else {
            valor = atoi(buffer);  /* conversion segura: ya sabemos que es entero puro */
            if (!validarEntero(valor, minimo, maximo)) {
                printf(" >> Error: dato fuera de rango, intente de nuevo\n");
                valido = 0;
            } else {
                valido = 1;
            }
        }
    } while (!valido);

    *resultado = valor;  /* escribe en la variable original via puntero */
}

void leerDecimalValidado(const char *mensaje, float minimo, float maximo, float *resultado) {
    char  buffer[64];
    float valor  = 0.0f;
    int   valido = 0;

    do {
        printf("%s", mensaje);
        leerLinea(buffer, sizeof(buffer));

        if (!esSoloDecimal(buffer)) {
            /* Contiene letras u otros simbolos invalidos */
            printf(" >> Error: dato fuera de rango, intente de nuevo\n");
            valido = 0;
        } else {
            valor = (float)atof(buffer);  /* conversion segura */
            if (!validarDecimal(valor, minimo, maximo)) {
                printf(" >> Error: dato fuera de rango, intente de nuevo\n");
                valido = 0;
            } else {
                valido = 1;
            }
        }
    } while (!valido);

    *resultado = valor;  /* escribe en la variable original via puntero */
}

void leerNombreValidado(const char *mensaje, char *resultado, int tamMax) {
    char buffer[51];
    int  valido = 0;

    do {
        printf("%s", mensaje);
        leerLinea(buffer, tamMax);

        if (!validarSoloLetras(buffer)) {
            printf(" >> Error: el nombre solo puede contener letras y espacios, intente de nuevo\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while (!valido);

    strcpy(resultado, buffer);  /* escribe en la variable original via puntero */
}
