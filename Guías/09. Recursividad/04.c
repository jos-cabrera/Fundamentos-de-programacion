/*
4) Desarrollar un programa que calcule y muestre por pantalla la división de
2 números mediante restas sucesivas en forma recursiva.
Ambos números deben ser ingresados por el usuario.
*/

#include <stdio.h>

int division(int dividendo, int divisor)
{
    int resultado = 0;

    if (dividendo >= divisor)
    {
        dividendo -= divisor;
        resultado = 1 + division(dividendo, divisor);
    }

    return resultado;
}

int main()
{
    int numero_1, numero_2;
    printf("Ingrese dos números para calcular su división ");
    printf("Ingrese un número: ");
    scanf("%d", &numero_1);
    printf("Ingrese otro número: ");
    scanf("%d", &numero_2);

    if (numero_2 == 0)
        printf("No se puede dividir por cero");
    else
        printf("%d / %d = %d", numero_1, numero_2, division(numero_1, numero_2));

    return 0;
}
