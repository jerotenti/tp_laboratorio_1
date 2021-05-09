/*
 * FuncionesMatematicas.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Tenti Villarreal Jerónimo
 */

#include "FuncionesMatematicas.h"

float sumar(float numero1, float numero2)
{
    float resultadoSuma;

    resultadoSuma = numero1 + numero2;

    return resultadoSuma;
}

float restar(float numero1, float numero2)
{
    float resultadoResta;

    resultadoResta = numero1 - numero2;

    return resultadoResta;
}

float dividir(float numero1, float numero2)
{
    float resultadoDivision;

    resultadoDivision = numero1 / numero2;

    return resultadoDivision;
}

float multiplicar(float numero1, float numero2)
{
    float resultadoMultiplicacion;

    resultadoMultiplicacion = numero1 * numero2;

    return resultadoMultiplicacion;
}

int factorial(int numero1, int numero2, int* retornoPrimerFactorial, int* retornoSegundoFactorial)
{
    int i;

    *retornoPrimerFactorial = 1;
    *retornoSegundoFactorial = 1;

    if(numero1 > 0)
    {
        for(i = numero1; i > 1; i--)
        {
            *retornoPrimerFactorial *= i;
        }
    }

    if(numero2 > 0)
    {
        for(i = numero2; i > 1; i--)
        {
            *retornoSegundoFactorial *= i;
        }
    }

    return 0;
}
