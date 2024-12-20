/*
31) En una competencia de salto en largo, se presentaron 20 participantes.
De cada uno se ingresa: Numero de participante, fecha de nacimiento (dd/mm/aaaa)
y los alcances de sus 3 saltos expresados en metros.

El mejor de los 3 saltos se considera como la mejor marca obtenida.

Se pide:
a) Para cada participante mostrar por pantalla el Numero de participante, la
edad y la marca obtenida.

b) Informar el Numero de participante del atleta que obtuvo la mejor marca.
*/

#include <stdio.h>

#define FECHA_ACTUAL 4122024
#define CANTIDAD_PARTICIPANTES 3
#define CANTIDAD_SALTOS 3

int obtener_edad(int fecha_nacimiento)
{
	int dia_nacimiento, mes_nacimiento, año_nacimiento, dia_actual, mes_actual, año_actual, edad;

	dia_actual = FECHA_ACTUAL / 1000000;
	mes_actual = (FECHA_ACTUAL / 10000) % 100;
	año_actual = FECHA_ACTUAL % 10000;

	dia_nacimiento = fecha_nacimiento / 1000000;
	mes_nacimiento = (fecha_nacimiento / 10000) % 100;
	año_nacimiento = fecha_nacimiento % 10000;

	edad = (año_actual - año_nacimiento) * 365;
	edad += (mes_actual - mes_nacimiento) * 30; // puede traer cierto grado de error
	edad += dia_actual - dia_nacimiento;

	edad /= 365;

	return edad;
}

void imprimir_participante_y_mejor_marca()
{
	int mejor_marca, mejor_marca_participante, participante, fecha_nacimiento, salto, marca, i, j;

	mejor_marca = 0;

	for (i = 0; i < CANTIDAD_PARTICIPANTES; i++)
	{
		marca = 0;

		printf("Ingrese el numero de participante: ");
		scanf("%d", &participante);

		printf("Ingrese la fecha de nacimiento (dd/mm/aaaa): ");
		scanf("%d", &fecha_nacimiento);

		for (j = 0; j < CANTIDAD_SALTOS; j++)
		{
			printf("Ingrese la cantidad en metros del salto %d: ", j + 1);
			scanf("%d", &salto);

			marca += salto;
		}

		if (marca > mejor_marca)
		{
			mejor_marca = marca;
			mejor_marca_participante = participante;
		}

		printf("Participante: %d\n", participante);
		printf("Edad: %d\n", obtener_edad(fecha_nacimiento));
		printf("Marca total: %d\n", marca);
	}

	printf("\nEl mejor participante es: %d\n", mejor_marca_participante);
}

int main()
{
	imprimir_participante_y_mejor_marca();

	return 0;
}
