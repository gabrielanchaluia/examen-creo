/* =========================================================
 * main.c
 * Programa principal - Centro de Salud UDLA
 * ISWZ1102 - Programacion I - Unidad 4
 *
 * Compilar con:
 *   gcc main.c paciente.c validaciones.c -o examen
 * ========================================================= */

#include <stdio.h>
#include "paciente.h"
#include "validaciones.h"

#define TOTAL_PACIENTES 5

int main(void) {
    /* ---- Declaracion del arreglo de estructuras ---- */
    Paciente pacientes[TOTAL_PACIENTES];

    /* ---- Contadores por estado (para el resumen final) ---- */
    int cBajoPeso  = 0;
    int cNormal    = 0;
    int cSobrepeso = 0;
    int cObesidad  = 0;

    /* ================================================
     * BLOQUE 1: Registro de los 5 pacientes
     * ============================================== */
    printf("=== Centro de Salud UDLA - Registro de Pacientes ===\n\n");

    for (int i = 0; i < TOTAL_PACIENTES; i++) {
        /* El id se asigna automaticamente (1 a 5), no se pide al usuario */
        pacientes[i].id = i + 1;

        printf("Paciente #%d\n", pacientes[i].id);

        /* Solicita y guarda nombre, edad, peso y altura */
        registrarPaciente(&pacientes[i]);

        /* Calcula el IMC y asigna el estado nutricional */
        calcularIMC(&pacientes[i]);

        printf("\n");
    }

    /* ================================================
     * BLOQUE 2: Reporte final
     * ============================================== */
    printf("============== REPORTE FINAL ==============\n");
    printf(" %-2s | %-20s | %-4s | %-6s | %s\n",
           "ID", "Nombre", "Edad", "IMC", "Estado");
    printf("----+----------------------+------+--------+----------\n");

    for (int i = 0; i < TOTAL_PACIENTES; i++) {
        mostrarPaciente(pacientes[i]);

        /* Acumula contadores para el resumen */
        if      (pacientes[i].imc < 18.5f) cBajoPeso++;
        else if (pacientes[i].imc < 25.0f) cNormal++;
        else if (pacientes[i].imc < 30.0f) cSobrepeso++;
        else                               cObesidad++;
    }

    /* ================================================
     * BLOQUE 3: Resumen de categorias
     * ============================================== */
    printf("\nResumen: Bajo peso: %d  Normal: %d  Sobrepeso: %d  Obesidad: %d\n",
           cBajoPeso, cNormal, cSobrepeso, cObesidad);

    return 0;
}
