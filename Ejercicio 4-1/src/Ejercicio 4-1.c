/*
 ============================================================================
 LUCAS GAGGINO DIVISION 1-F

Ejercicio 4-1:
Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número. Utilizar la función PedirNumero de la ejercitación 3-4.
Por ejemplo:
5! = 5*4*3*2*1 = 120


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


int main(void) {

	setbuf(stdout, NULL);

	int numero;
	double factorial;
	int b;

	factorial = 1;

	numero = funcionPedirNumero();

	b = numero;

	while(b > 1)
	{
		factorial = factorial*b;
		b--;
	}

	  printf("El factorial de %d es %.0lf\n", numero, factorial);



	return EXIT_SUCCESS;
}

