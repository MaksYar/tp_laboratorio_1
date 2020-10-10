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

int initEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

int auxiliarAdd(Employee *Aux) {
	int retorno = -1;

	if (Aux != NULL) {

		if (utn_getString(Aux->name, "Ingrese nombre: ",
				"El nombre ingresado no es valido. Reingrese", 1, LEN, 2) == 0
				&& utn_getString(Aux->lastName, "Ingrese apellido: ",
						"El apellido ingresado no es valido. Reingrese", 1, LEN,
						2) == 0
				&& utn_getNumeroFlotante(&Aux->salary,
						"Ingrese salario (u$s): ",
						"El numero ingresado no es valido. Reingrese", 0, 10000,
						2) == 0
				&& utn_getNumero(&Aux->sector, "Ingrese sector: ",
						"El numero ingresado no es valido. Reingrese", 1, 50, 2)
						== 0) {
			retorno = 0;
		} else {
			printf("Error en la carga. Reintente \n");
			retorno = -1;
			system("pause");
		}

	}
	return retorno;
}

int addEmployee(Employee *list, int len, int id, char *name, char *lastName,
		float salary, int sector) {
	int retorno = -1;
	int i = 0;

	if (list != NULL && len > 0) {

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == TRUE) {

				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].salary = salary;
				list[i].sector = sector;
				list[i].isEmpty = FALSE;
				retorno = 0;
				break;
			}
		}
	}

	if (retorno == -1) {
		printf("No hay lugar disponible");
	}

	return retorno;
}

int printEmployees(Employee *list, int len) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {

		printf("\n\t| %5s | %8s | %8s | %8s | %5s |\n", "ID", "Nombre",
				"Apellido", "Salario", "Sector");

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == FALSE) {

				printf("\t| %5d | %8s | %8s | %8.2f | %6d |\n", list[i].id,
						list[i].name, list[i].lastName, list[i].salary,
						list[i].sector);
			}

		}
		retorno = 0;
	}

	return retorno;
}

int printEmployee(Employee *list, int len, int id) {

	int retorno = -1;
	int indice;
	if (list != NULL && len > 0) {
		indice = findEmployeeById(list, len, id);
		printf("\n\t| %5s | %8s | %8s | %8s | %5s |\n", "ID", "Nombre",
				"Apellido", "Salario", "Sector");

		printf("\t| %5d | %8s | %8s | %8.2f | %6d |\n", list[indice].id,
				list[indice].name, list[indice].lastName, list[indice].salary,
				list[indice].sector);

		retorno = 0;
	}
	return retorno;
}

int findEmployeeById(Employee *list, int len, int id) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				continue;
			} else if (list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int updateEmployee(Employee *list, int len) {
	int retorno = -1;
	int resultado;
	int id;
	int menu;
	int indice;

	resultado = utn_getNumero(&id, "Ingrese el ID: ",
			"El ID no es valido. Reingrese", 1, 4096, 2);
	indice = findEmployeeById(list, len, id);

	if (list != NULL && len > 0 && resultado == 0 && indice != -1) {

		utn_getNumero(&menu,
				"\nIngrese el campo a modificar: \n\n1-Nombre \n2-Apellido \n3-Salario \n4-Sector \n\nIngrese una opcion: ",
				"La opcion no es valida. Reingrese\n", 1, 4, 2);

		switch (menu) {
		case 1:
			if (utn_getString(list[indice].name, "Ingrese nombre: ",
					"El nombre ingresado no es valido. Reingrese\n", 1, LEN, 2)
					== 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		case 2:
			if (utn_getString(list[indice].lastName, "Ingrese apellido: ",
					"El apellido ingresado no es valido. Reingrese\n", 1, LEN,
					2) == 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		case 3:
			if (utn_getNumeroFlotante(&list[indice].salary,
					"Ingrese salario (u$s): ",
					"El numero ingresado no es valido. Reingrese\n", 0, 10000,
					2) == 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;

		case 4:
			if (utn_getNumero(&list[indice].sector, "Ingrese sector: ",
					"El numero ingresado no es valido. Reingrese\n", 1, 50, 2)
					== 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		}
		printEmployee(list, len, id);
		retorno = 0;
	}
	return retorno;
}

int removeEmployee(Employee *list, int len) {
	int retorno = -1;
	int id;
	int indice;

	utn_getNumero(&id, "\nIngrese el ID a eliminar: ",
			"\nEl ID no es valido. Reingrese", 1, 4096, 2);
	indice = findEmployeeById(list, len, id);

	if (list != NULL && len > 0 && indice > 0) {
		list[indice].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

int sortEmployees(Employee *list, int len, int order) {
	int retorno = -1;
	int i;
	int j;
	Employee aux;

	if (list != NULL && len > 0) {

		switch (order) {
		case 0: //Orden ascendente
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {

					if (strcmp(list[i].lastName, list[j].lastName) < 0) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					} else if (strcmp(list[i].lastName, list[j].lastName) == 0
							&& list[i].sector < list[j].sector) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		case 1: //Orden descendente
			for (i = 0; i < len - 1; i++) {
				for (j = i + 1; j < len; j++) {

					if (strcmp(list[i].lastName, list[j].lastName) > 0) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					} else if (strcmp(list[i].lastName, list[j].lastName) == 0
							&& list[i].sector > list[j].sector) {
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		}
	}

	return retorno;
}

int acumularSalario(Employee *list, int len, float *acumulador) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				*acumulador += list[i].salary;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int calcularPromedioSalario(Employee *list, int len, float *promedio) {

	float acumulador = 0;
	int i;
	int retorno = -1;
	int contador = 0;

	if (list != NULL && len > 0) {
		acumularSalario(list, len, &acumulador);

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				contador++;
			}
		}
		if (contador == 0) {
			retorno = -1;
		} else {
			*promedio = acumulador / contador;
			retorno = 0;
		}
	}
	return retorno;
}

int cuentaSuperaSalarioPromedio(Employee *list, int len, float promedio,
		int *contador) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].salary > promedio) {
				(*contador)++;
			}
		}
		retorno = 0;
	}
	return retorno;
}

int hayAltasEmpleados(Employee *list, int len) {
	int i;
	int retorno = 0;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == FALSE) {
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

