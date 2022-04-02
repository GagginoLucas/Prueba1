/******************************************************************************
 LUCAS GAGGINO DIVISION 1-F
 Ejercicio 2-3:
 Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo de personas, de cada persona debemos obtener los siguientes datos:
 número de cliente,
 estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
 edad( solo mayores de edad, más de 17),
 temperatura corporal (validar por favor)
 y genero('f' para femenino, 'm' para masculino, 'o' para no binario).
 NOTA: El precio por pasajero es de $600.
 Se debe informar (solo si corresponde):
 a) La cantidad de personas con estado "viudo" de más de 60 años.
 b) el número de cliente y edad de la mujer soltera más joven.
 c) cuánto sale el viaje total sin descuento.
 d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final tiene un descuento del 25%, que solo mostramos si corresponde.

 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


int main() {
	setbuf(stdout, NULL);

	char estadoCivilIngresado;
	int edadIngresada;
	int temperaturaIngresada;
	char generoIngresado;
	char pasajerosIngresados;
	int numeroDeCliente;

	int contadorViudosMayores;

	int nroClienteMujerJoven;
	int edadMujerJoven;
	int flagMujerJovenSoltera;

	int contadorPasajerosConMasDe60;
	int contadorPasajerosIngresados;
	int totalSinDescuento;

	int descuento;
	float totalConDescuento;

	contadorPasajerosIngresados = 0;
	contadorPasajerosConMasDe60 = 0;

	flagMujerJovenSoltera = 0;
	contadorViudosMayores = 0;

	pasajerosIngresados = 'S';

	while (pasajerosIngresados == 'S') {

		printf("INGRESE NUMERO DE CLIENTE\n");
		scanf("%d", &numeroDeCliente);

		printf(
				"Ingrese estado civil 'S' para soltero 'C' para casado o 'V' para viudo\n");
		fflush(stdin);
		scanf("%c", &estadoCivilIngresado);
		estadoCivilIngresado = toupper(estadoCivilIngresado);

		while (estadoCivilIngresado != 'S' && estadoCivilIngresado != 'C'
				&& estadoCivilIngresado != 'V') {
			printf(
					"ERROR, vuelva a ingresar estado civil 'S' para soltero 'C' para casado o 'V' para viudo\n");
			fflush(stdin);
			scanf("%c", &estadoCivilIngresado);
			estadoCivilIngresado = toupper(estadoCivilIngresado);

		}

		printf(
				"Ingrese ingresar GENERO 'F' para femenino 'M' para masculino o 'N' para no binario2\n");
		fflush(stdin);
		scanf("%c", &generoIngresado);
		generoIngresado = toupper(generoIngresado);

		while (generoIngresado != 'F' && generoIngresado != 'M'
				&& generoIngresado != 'N') {
			printf(
					"ERROR, vuelva a ingresar GENERO 'F' para femenino 'M' para masculino o 'N' para no binario\n");
			fflush(stdin);
			scanf("%c", &generoIngresado);
			generoIngresado = toupper(generoIngresado);
		}

		printf("INGRESE EDAD\n");
		scanf("%d", &edadIngresada);
		while (isalpha(edadIngresada) || edadIngresada < 18 || edadIngresada > 105) {
			printf("ERROR, INGRESE EDAD\n");
			scanf("%d", &edadIngresada);
		}

		printf("INGRESE TEMPERATURA\n");
		scanf("%d", &temperaturaIngresada);
		while (temperaturaIngresada < 35 || temperaturaIngresada > 43) {
			printf("ERROR, INGRESE TEMPERATURA VALIDA\n");
			scanf("%d", &temperaturaIngresada);
		}

		switch (estadoCivilIngresado){

		case 'V':
			if (edadIngresada > 60) {
				contadorViudosMayores++;
			}

			break;
		case 'S':
			if ((flagMujerJovenSoltera == 0 || edadIngresada < edadMujerJoven)
					&& generoIngresado == 'F') {
				edadMujerJoven = edadIngresada;
				nroClienteMujerJoven = numeroDeCliente;
				flagMujerJovenSoltera = 1;
			}
			break;
		}

		if(edadIngresada>60) {
			contadorPasajerosConMasDe60++;
		}

		contadorPasajerosIngresados++;

		printf("SI DESEA SEGUIR INGRESANDO PASAJEROS PRESIONE S/N \n");
		fflush(stdin);
		scanf("%c", &pasajerosIngresados);
		pasajerosIngresados = toupper(pasajerosIngresados);

	}

	totalSinDescuento = contadorPasajerosIngresados * 600;

	descuento = (contadorPasajerosConMasDe60*100)/contadorPasajerosIngresados;

	if(descuento>50) {

		totalConDescuento = totalSinDescuento - ((float)totalSinDescuento*0.25);
	}


	printf("A) SE INGRESARON %d PERSONAS VIUDAS CON MAS DE 60 AÑOS\n",
			contadorViudosMayores);
	if (flagMujerJovenSoltera == 0) {
		printf("B) NO SE INGRESARON MUJERES SOLTERAS\n");
	} else {
		printf(
				"B) LA EDAD DE LA MUJER SOLTERA MAS JOVEN ES DE %d AÑOS Y SU NUMERO DE CLIENTE ES %d\n",
				edadMujerJoven, nroClienteMujerJoven);
	}
	printf("C) EL VIAJE EN TOTAL SIN DESCUENTO CUESTA $%d\n",
			totalSinDescuento);
	if(descuento>50) {
		printf("D) TOTAL CON DESCUENTO: %.2f",totalConDescuento);
	}else
	{
		printf("D) NO HUBO SUFICIENTES PERSONAS CON MÁS DE 60 PARA APLICAR EL DESCUENTO");
	}

	return 0;
}




