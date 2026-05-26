/* =========================================================
 * main.c
 * Programa principal - Centro de Salud UDLA
 * ISWZ1102 - Programacion I - Unidad 4
 *
 * Compilar con el comando exacto del enunciado:
 *   gcc main.c paciente.c validaciones.c -o examen
 * ========================================================= */

#include <stdio.h>
#include "paciente.h"      /* incluye la definicion de Paciente y prototipos */
#include "validaciones.h"  /* incluye los prototipos de validacion           */

#define TOTAL_PACIENTES 5

int main(void) {
    int i;

    /* ---- Arreglo de estructuras para los 5 pacientes ---- */
    Paciente pacientes[TOTAL_PACIENTES];

    /* ---- Contadores por categoria de estado nutricional ---- */
    int cBajoPeso  = 0;
    int cNormal    = 0;
    int cSobrepeso = 0;
    int cObesidad  = 0;

    /* ====================================================
     * BLOQUE 1: Registro de los 5 pacientes
     * El id se asigna automaticamente (1, 2, 3, 4, 5)
     * desde main(), sin pedirlo al usuario.
     * ==================================================== */
    printf("=== Centro de Salud UDLA - Registro de Pacientes ===\n\n");

    for (i = 0; i < TOTAL_PACIENTES; i++) {
        pacientes[i].id = i + 1;              /* asignacion automatica del id */
        printf("Paciente #%d\n", pacientes[i].id);

        registrarPaciente(&pacientes[i]);     /* pide nombre, edad, peso, altura */
        calcularIMC(&pacientes[i]);           /* calcula IMC y determina estado  */

        printf("\n");
    }

    /* ====================================================
     * BLOQUE 2: Reporte final con todos los pacientes
     * IMC mostrado con 2 decimales (responsabilidad de
     * mostrarPaciente, que usa %.2f).
     * ==================================================== */
    printf("============== REPORTE FINAL ==============\n");
    printf(" %-2s | %-20s | %-4s | %-6s | %s\n",
           "ID", "Nombre", "Edad", "IMC", "Estado");
    printf("----+----------------------+------+--------+-----------\n");

    for (i = 0; i < TOTAL_PACIENTES; i++) {
        mostrarPaciente(pacientes[i]);

        /* Acumula el contador de la categoria correspondiente */
        if      (pacientes[i].imc < 18.5f) cBajoPeso++;
        else if (pacientes[i].imc < 25.0f) cNormal++;
        else if (pacientes[i].imc < 30.0f) cSobrepeso++;
        else                               cObesidad++;
    }

    /* ====================================================
     * BLOQUE 3: Resumen de contadores por categoria
     * Formato exacto del ejemplo del enunciado (pag. 4).
     * ==================================================== */
    printf("\nResumen: Bajo peso: %d  Normal: %d  Sobrepeso: %d  Obesidad: %d\n",
           cBajoPeso, cNormal, cSobrepeso, cObesidad);

    return 0;
}
