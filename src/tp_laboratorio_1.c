/*
 ============================================================================
 Name        : tp_laboratorio_1.c
 Author      : Tenti Villarreal Jer�nimo
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Trabajo Pr�ctico N�1 - Laboratorio y Programaci�n I
 ============================================================================
 */

#include "FuncionesMatematicas.h"

int main(void)
{
    setbuf(stdout, NULL);
    float unNumero;
    float otroNumero;
    float retornoDeSumar;
    float retornoDeRestar;
    float retornoDeDividir;
    float retornoDeMultiplicar;
    int retornoPrimerFactorial;
    int retornoSegundoFactorial;
    int opcion;

    do
    {
        printf("\n***Calculadora***\n");
        printf("1- Ingresar 1er operando: %.2f\n", unNumero);
        printf("2- Ingresar 2do operando %.2f\n", otroNumero);
        printf("3- Calcular todas las operaciones\n");
        printf("4- Mostrar resultados\n");
        printf("5- Salir\n");
        printf("Elija una opci�n: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese un n�mero: ");
                scanf("%f", &unNumero);
            break;
            case 2:
                printf("Ingrese otro n�mero: ");
                scanf("%f", &otroNumero);
            break;
            case 3:
                retornoDeSumar = sumar(unNumero, otroNumero);
                retornoDeRestar = restar(unNumero, otroNumero);
                if(otroNumero != 0)
                {
                    retornoDeDividir = dividir(unNumero, otroNumero);
                }
                retornoDeMultiplicar = multiplicar(unNumero, otroNumero);
                factorial(unNumero, otroNumero, &retornoPrimerFactorial, &retornoSegundoFactorial);
            break;
            case 4:
                printf("El resultado de la suma de %.2f + %.2f es: %.2f", unNumero, otroNumero, retornoDeSumar);
                printf("\nEl resultado de la resta de %.2f - %.2f es: %.2f", unNumero, otroNumero, retornoDeRestar);
                if(otroNumero != 0)
                {
                    printf("\nEl resultado de la divisi�n de %.2f / %.2f es: %.2f", unNumero, otroNumero, retornoDeDividir);
                }
                else
                {
                    printf("\nEl resultado de la divisi�n es: No es posible dividir por cero");
                }
                printf("\nEl resultado de la multiplicaci�n de %.2f * %.2f es: %.2f", unNumero, otroNumero, retornoDeMultiplicar);
                printf("\nEl factorial de %.0f es: %d. Y el factorial de %.0f es: %d\n", unNumero, retornoPrimerFactorial, otroNumero, retornoSegundoFactorial);
            break;
            case 5:
                printf("Usted ha finalizado el programa.");
            break;
            default:
                printf("La opci�n elegida es incorrecta.\n");
            break;
        }
    }
    while(opcion != 5);

    return 0;
}
