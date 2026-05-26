/* =========================================================
 * paciente.c
 * Implementacion de las funciones relacionadas con Paciente
 * ISWZ1102 - Programacion I - Unidad 4
 * ========================================================= */

#include <stdio.h>
#include <string.h>
#include "paciente.h"
#include "validaciones.h"

/* ---------------------------------------------------------
 * SECCION 1: Registro de paciente
 * Solicita al usuario los cuatro datos editables:
 *   - nombre : cadena de solo letras y espacios (no vacia).
 *   - edad   : entero en [1, 120].
 *   - peso   : decimal en (0.0, 300.0).
 *   - altura : decimal en (0.30, 2.50).
 *
 * Para edad, peso y altura se pasa la DIRECCION DE MEMORIA
 * del campo de la estructura (&p->campo) a las funciones
 * leerEnteroValidado / leerDecimalValidado, que modifican
 * el valor directamente via el puntero recibido.
 * El id ya viene asignado desde main(); no se pide aqui.
 * --------------------------------------------------------- */
void registrarPaciente(Paciente *p) {
    /* Nombre: solo letras y espacios, rechaza digitos y simbolos */
    leerNombreValidado(" Nombre  : ", p->nombre, sizeof(p->nombre));

    /* Edad: entero validado en [1, 120]; se pasa &p->edad (puntero) */
    leerEnteroValidado(" Edad    : ", 1, 120, &p->edad);

    /* Peso: decimal validado en (0.0, 300.0); se pasa &p->peso (puntero) */
    leerDecimalValidado(" Peso    : ", 0.0f, 300.0f, &p->peso);

    /* Altura: decimal validado en (0.30, 2.50); se pasa &p->altura (puntero) */
    leerDecimalValidado(" Altura  : ", 0.30f, 2.50f, &p->altura);
}

/* ---------------------------------------------------------
 * SECCION 2: Calculo del IMC y asignacion del estado
 * Formula exacta del enunciado: IMC = peso / (altura * altura)
 * Tabla de clasificacion (enunciado pag. 2):
 *   IMC < 18.5              -> "Bajo peso"
 *   18.5 <= IMC < 25.0      -> "Normal"
 *   25.0 <= IMC < 30.0      -> "Sobrepeso"
 *   IMC >= 30.0             -> "Obesidad"
 * --------------------------------------------------------- */
void calcularIMC(Paciente *p) {
    p->imc = p->peso / (p->altura * p->altura);

    if (p->imc < 18.5f) {
        strcpy(p->estado, "Bajo peso");
    } else if (p->imc < 25.0f) {
        strcpy(p->estado, "Normal");
    } else if (p->imc < 30.0f) {
        strcpy(p->estado, "Sobrepeso");
    } else {
        strcpy(p->estado, "Obesidad");
    }
}

/* ---------------------------------------------------------
 * SECCION 3: Presentacion formateada de un paciente
 * Imprime una fila alineada para la tabla del reporte final.
 * El IMC se muestra con exactamente 2 decimales (%.2f),
 * tal como exige el enunciado.
 * Recibe el struct por valor (copia): no modifica el original.
 * --------------------------------------------------------- */
void mostrarPaciente(Paciente p) {
    printf(" %-2d | %-20s | %-4d | %6.2f | %s\n",
           p.id, p.nombre, p.edad, p.imc, p.estado);
}
