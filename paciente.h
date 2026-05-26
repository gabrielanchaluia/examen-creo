#ifndef PACIENTE_H
#define PACIENTE_H

/* =========================================================
 * paciente.h
 * Definicion de la estructura Paciente y prototipos
 * ISWZ1102 - Programacion I - Unidad 4
 * ========================================================= */

/* ---------------------------------------------------------
 * SECCION 1: Definicion de la estructura
 * Se define una sola vez aqui; todos los archivos que
 * incluyan este header la conoceran.
 * --------------------------------------------------------- */
typedef struct {
    int   id;            /* Identificador unico (1-5) */
    char  nombre[51];    /* Nombre completo (max 50 chars + '\0') */
    int   edad;          /* Edad en anos (1-120) */
    float peso;          /* Peso en kg (0.0 < peso < 300.0) */
    float altura;        /* Altura en m (0.30 < altura < 2.50) */
    float imc;           /* IMC calculado: peso / (altura * altura) */
    char  estado[20];    /* Clasificacion: Bajo peso/Normal/Sobrepeso/Obesidad */
} Paciente;

/* ---------------------------------------------------------
 * SECCION 2: Prototipos de funciones de paciente
 * --------------------------------------------------------- */
void registrarPaciente(Paciente *p);   /* solicita datos al usuario */
void calcularIMC(Paciente *p);         /* calcula IMC y asigna estado */
void mostrarPaciente(Paciente p);      /* imprime los datos del paciente */

#endif /* PACIENTE_H */
