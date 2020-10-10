/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"
#include "ArrayEmployees.h"

#define TAM 1000
#define LEN 51
#define TRUE 0
#define FALSE 1
#define UP 1
#define DOWN 0


int main(void) {

	setbuf(stdout, NULL);

	Employee arrayEmployees[TAM];
	Employee Aux;
	int option;
	int subOption;
	int replySubMenu;
	int order;
	int counterId = 0;
	int resultSubMenuOp4;
	int replyMenu;
	int counterEmployee = 0;
	char replyContinue = 's';
	float iWantSalami = 0;  // no se como llamar el acumulador de salario en ingles
	float iWantMoreSalami;  // idem con el promedio de salario


	initEmployees(arrayEmployees, TAM);

	do {
		system("cls");
		replyMenu = utn_getNumero(&option, "\nMENU DE OPCIONES: \n\n"
				"==>1.ALTA \n"
				"==>2.MODIFICAR \n"
				"==>3.BAJA \n"
				"==>4.INFORMAR \n"
				"\nIngrese una opcion: ",
				"\nLa opcion es invalida. Ingrese \n", 1, 4, 2);

		if (!replyMenu) {
			system("cls");
			switch (option) {
			case 1:
				printf("====> Alta de empleado\n\n");
				counterId++;
				if (auxiliarAdd(&Aux)==0 && addEmployee(arrayEmployees, TAM, counterId, Aux.name,
						Aux.lastName, Aux.salary, Aux.sector)==0) {
					printf("\nAlta exitosa \n\n");
				} else {
					printf("\nError. Reintente\n");
				}
				system("pause");
				break;
			case 2:
				if (hayAltasEmpleados(arrayEmployees, TAM) == 1) {
					printf("====> Modificar empleado\n\n");
					printEmployees(arrayEmployees, TAM);

					if (updateEmployee(arrayEmployees, TAM) == 0) {
						printf("\n\nModificacion exitosa \n\n");
						system("pause");
					} else {
						printf("\nError. Reintente\n");
					}
					system("cls");
				} else {
					printf(
							"\nNo hay empleados a modificar. Ingrese en Opcion 1. \n");
				}
				break;
			case 3:
				if (hayAltasEmpleados(arrayEmployees, TAM) == 1) {
					printf("----BAJA EMPLEADO----\n\n");
					printEmployees(arrayEmployees, TAM);
					if (removeEmployee(arrayEmployees, TAM) == 0) {
						printf("\nBaja exitosa \n\n");
						system("pause");
					} else {
						printf("\nError. Reintente\n");
					}
					system("cls");
				} else {
					printf(
							"\nNo hay empleados a bajar. Ingrese en Opcion 1. \n");
				}
				break;
			case 4:
				if (hayAltasEmpleados(arrayEmployees, TAM) == 1) {
					printf("----INFORMES----\n\n");
					printEmployees(arrayEmployees, TAM);
					replySubMenu =
							utn_getNumero(&subOption,
									"\n1. Listado de empleados ordenados alfabeticamente por Apellido y Sector \n"
											"2. Total y promedio de salarios, y cantidad de empleados que superan el salario promedio \n3. Volver al Menu principal \n\n Ingrese una opcion: ",
									"La opcion ingresada no es valida \n", 1, 3,
									2);
					if (replySubMenu == 0) {
						switch (subOption) {
						case 1:
							resultSubMenuOp4 =
									utn_getNumero(&order,
											"\nIngrese el orden: ascendente(1) o desdendente (0) \n\nIngrese una opcion: ",
											"\nEl numero es invalido. Reingrese \n",
											0, 1, 2);
							if (resultSubMenuOp4 == 0) {
								sortEmployees(arrayEmployees, TAM, order);
								printEmployees(arrayEmployees, TAM);
								system("pause");
							}
							break;
						case 2:
							acumularSalario(arrayEmployees, TAM,
									&iWantSalami);
							calcularPromedioSalario(arrayEmployees, TAM,
									&iWantMoreSalami);
							cuentaSuperaSalarioPromedio(arrayEmployees, TAM,
									iWantMoreSalami, &counterEmployee);
							printf(
									"\nLa suma total de salarios de empleados es: %.2f \n",
									iWantSalami);
							printf("\nEl salario promedio es: %.2f \n",
									iWantMoreSalami);
							printf(
									"\nLa cantidad de empleados que supera el sueldo promedio es: %d \n",
									counterEmployee);
							system("pause");
							break;

						case 3:
							break;
						}
					}
				} else {
					printf(
							"\nNo hay empleados a informar. Ingrese en Opcion 1. \n");
				}

				break;
			}
		} else {
			printf("Se terminaron los intentos. Reinicie");
		}
	} while (replyContinue == 's');

	return EXIT_SUCCESS;
}

