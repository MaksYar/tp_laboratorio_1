/*
 ============================================================================
 Name        : Maksym.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcionestp1.h"

int main(void) {

	setbuf(stdout, NULL);

	float a;
	float b;
	float suma;
	float resta;
	float producto;
	float cociente;
	double factorial1;
	double factorial2;
	int opcion;
	char respuesta;
	int validado1;
	int validado2;
	int banderaOp1 = 0;
	int banderaOp2 = 0;
	int banderaCalc = 0;

	do {

		printf("\n Trabajo practico N1, Calculadora: \n\n");
		if (banderaOp1 == 0) {
			printf("=> 1. Ingresar el 1er operando\n");
		} else {
			printf("(Ok) 1. Ingresar el 1er operando (A = %.2f)\n", a);
		}
		if (banderaOp1 == 1 && banderaOp2 == 0) {
			printf("=> ");
		}
		if (banderaOp2 == 0) {
			printf("2. Ingresar el 2do operando\n");
		} else {
			printf("(Ok) 2. Ingresar el 2do operando (B = %.2f) \n", b);
		}
		if (banderaOp1 == 1 && banderaOp2 == 1 && banderaCalc == 0) {
			printf("=> ");
		}
		else if(banderaCalc == 1){
			printf("(Ok) ");
		}

		printf("3. Calcular todas las operaciones \n");
		if (banderaCalc == 1) {
			printf("=> ");
		}

		printf("4. Informar resultados \n");
		printf("5. Salir \n");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);

		while (!(opcion >= 1 && opcion <= 5)) {
			printf(
					"\nLa opcion ingresada no es valida. Ingrese una opcion valida: ");
			scanf("%d", &opcion);
		}

		switch (opcion) {
		case 1:
			system("cls");
			if (banderaOp2 == 1 && banderaOp1 == 1) {
				printf("Este operando ya fue ingresado\n");
				system("pause");
				break;
			}

			printf("\nPor favor, ingrese el primer operando: ");
			scanf("%f", &a);
			system("pause");
			banderaOp1 = 1;
			break;

		case 2:
			system("cls");
			if (banderaOp1 == 0) {
				printf("\nPor favor, primero ingrese el primer operando\n");
				system("pause");
				break;
			}
			printf("\nPor favor, ingrese el segundo operando: ");
			scanf("%f", &b);
			system("pause");
			banderaOp2 = 1;
			break;

		case 3:
			system("cls");
			if (banderaOp2 == 0) {
				printf("\nDebe ingresar los operandos primero\n");
				system("pause");
				break;
			}

			suma = sumarNumeros(a, b);
			resta = restarNumeros(a, b);
			producto = multiplicarNumeros(a, b);
			cociente = dividirNumeros(a, b);
			factorial1 = factorial(a);
			factorial2 = factorial(b);
			printf("Calculo realizado con exito \n ");
			system("pause");
			banderaCalc = 1;

			break;
		case 4:

			system("cls");
			if (banderaCalc == 0) {
				printf("\nDebe ingresar los operandos y calcular primero\n");
				system("pause");
				break;
			}

			printf("El resultado de (A+B) es = %.2f \n", suma); // Suma

			printf("El resultado de (A-B) es = %.2f \n", resta); //Resta

			if (b == 0) {
				printf("Error. No es posible la division por cero \n"); //Division
			} else {
				printf("El resultado de (A/B) es = %.2f \n", cociente);
			}

			printf("El resultado de (A*B) es = %.2f \n", producto); //Multiplicacion

			validado1 = validarNatural(a); //Factorial de A

			if (validado1 == 1) {
				printf(
						"Error. No se puede calcular el factorial para el numero ingresado \n");
			} else {
				printf("El factorial de A es: %.2lf \n", factorial1);
			}

			validado2 = validarNatural(b); // Factorial de B

			if (validado2 == 1) {
				printf(
						"Error. No se puede calcular el factorial para el numero ingresado \n");
			} else {
				printf("El factorial de B es: %.2lf \n", factorial2);
			}
			banderaOp1 = 0;
			banderaOp2 = 0;
			banderaCalc = 0;
			system("pause");
			break;

		case 5:
			system("cls");
			printf("\n ¿Desea salir? s/n ");
			fflush(stdin);
			scanf("%c", &respuesta);
			if (respuesta == 's') {
				break;
			}
		}
		system("cls");

	} while (respuesta != 's');

	return EXIT_SUCCESS;
}

float pedirNumero(char texto[]) {
	float numero;
	printf(texto);
	scanf("%f", &numero);
	return numero;

}

