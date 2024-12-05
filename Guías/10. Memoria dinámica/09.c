/*
9) Reservar memoria para almacenar una palabra ingresada por el usuario, es
leída en una cadena auxiliar, luego copiada a memoria dinámica, recordando que
se requiere adicionar un carácter de fin de cadena '\n'.

Ejemplo:
"hola mundo" + '\0' -> requiere espacio para 11 caracteres.

char* cadena_aux = "hola mundo";
char* cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char cadena_aux[100];
	char *cadena;

	printf("Ingrese una frase o palabra: ");
	fgets(cadena_aux, 100, stdin);
	fflush(stdin);

	cadena = malloc(strlen(cadena_aux) * sizeof(char) + 1);

	if (cadena != NULL)
	{
		strcpy(cadena, cadena_aux);

		cadena[strlen(cadena) - 1] = '\n';
		printf("%s", cadena);

		free(cadena);
	}
	else
	{
		printf("No se pudo reservar memoria\n");
	}

	return 0;
}
