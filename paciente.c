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
 * Solicita nombre, edad, peso y altura.
 * Edad, peso y altura se leen con las funciones validadas
 * usando paso por referencia (operador &).
 * El id se asigna desde main(), no se pide aqui.
 * --------------------------------------------------------- */
void registrarPaciente(Paciente *p) {
    /* Nombre: se lee directamente (es cadena de caracteres) */
    printf(" Nombre  : ");
    /* Limpia el buffer antes de leer la cadena */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(p->nombre, sizeof(p->nombre), stdin);
    /* Elimina el salto de linea que deja fgets */
    size_t len = strlen(p->nombre);
    if (len > 0 && p->nombre[len - 1] == '\n') {
        p->nombre[len - 1] = '\0';
    }

    /* Edad: entero validado, rango 1-120, via puntero */
    leerEnteroValidado(" Edad    : ", 1, 120, &p->edad);

    /* Peso: decimal validado, rango (0.0, 300.0), via puntero */
    leerDecimalValidado(" Peso    : ", 0.0f, 300.0f, &p->peso);

    /* Altura: decimal validado, rango (0.30, 2.50), via puntero */
    leerDecimalValidado(" Altura  : ", 0.30f, 2.50f, &p->altura);
}

/* ---------------------------------------------------------
 * SECCION 2: Calculo del IMC y asignacion del estado
 * Formula: IMC = peso / (altura * altura)
 * Clasificacion segun tabla del enunciado.
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
 * SECCION 3: Presentacion de un paciente en el reporte
 * Imprime una fila formateada para la tabla del reporte.
 * IMC se muestra con 2 decimales.
 * --------------------------------------------------------- */
void mostrarPaciente(Paciente p) {
    printf(" %-2d | %-20s | %-4d | %6.2f | %s\n",
           p.id, p.nombre, p.edad, p.imc, p.estado);
}
