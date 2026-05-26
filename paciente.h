#ifndef PACIENTE_H
#define PACIENTE_H

/* =========================================================
 * paciente.h
 * Definicion de la estructura Paciente y prototipos
 * ISWZ1102 - Programacion I - Unidad 4
 * ========================================================= */

/* ---------------------------------------------------------
 * SECCION 1: Definicion de la estructura con typedef
 * Declarada UNA SOLA VEZ aqui; cualquier archivo que
 * incluya este header conoce el tipo Paciente completo.
 * Los 7 atributos son exactamente los del enunciado.
 * --------------------------------------------------------- */
typedef struct {
    int   id;           /* Identificador unico; asignado desde main() (1-5)      */
    char  nombre[51];   /* Nombre completo: hasta 50 caracteres + '\0'            */
    int   edad;         /* Edad en anos: rango valido 1 a 120 (inclusive)         */
    float peso;         /* Peso en kg: rango valido mayor a 0.0 y menor a 300.0   */
    float altura;       /* Altura en m: rango valido mayor a 0.30 y menor a 2.50  */
    float imc;          /* IMC calculado con la formula: peso / (altura * altura)  */
    char  estado[20];   /* Clasificacion nutricional: Bajo peso / Normal /
                           Sobrepeso / Obesidad                                   */
} Paciente;

/* ---------------------------------------------------------
 * SECCION 2: Prototipos de las funciones de paciente
 * --------------------------------------------------------- */
void registrarPaciente(Paciente *p);   /* solicita datos al usuario y los guarda */
void calcularIMC(Paciente *p);         /* calcula IMC y asigna el estado          */
void mostrarPaciente(Paciente p);      /* imprime una fila del reporte final      */

#endif /* PACIENTE_H */
