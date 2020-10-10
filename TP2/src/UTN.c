#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

static int myGets(char *cadena, int longitud) {
	int retorno = -1;

	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
			retorno = 0;
		}
	}
	return retorno;
}

static int esNumerica(char *cadena) {
	int retorno = 1;
	int i = 0;

	if (cadena[0] == '-') {
		i = 1;
	}
	for (; cadena[i] != '\0'; i++) {

		if (cadena[i] > '9' || cadena[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int esNumeroDecimal(char *cadena) {
	int retorno = 1;
	int i = 0;
	int flagPunto = 0;

	if (cadena[0] == '-') {
		i = 1;
	}
	for (; cadena[i] != '\0'; i++) {
		if (cadena[i] == '.' && flagPunto == 0) {
			flagPunto = 1;
			continue;
		}

		if (cadena[i] > '9' || cadena[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int esTexto(char *cadena) {
	int i;
	int retorno = 1;

	if (isspace(cadena[0])) {
		retorno = 0;
	}
	for (i = 0; cadena[i] != '\0'; i++) {

		if (!(isspace(cadena[i]) || isalpha(cadena[i]))) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esNumerica(buffer)) {
		*pResultado = atoi(buffer);
		retorno = 0;
	}
	return retorno;
}

static int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esNumeroDecimal(buffer)) {
		*pResultado = atof(buffer);
		retorno = 0;
	}
	return retorno;
}

static int getString(char *pResultado) {
	int retorno = -1;
	char buffer[4096];

	fflush(stdin);

	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esTexto(buffer)) {
		strcpy(pResultado, buffer);
		retorno = 0;
	}

	return retorno;

}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int buffer; //espacios de intercambio con el usuario
	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {

		do {
			printf("%s", mensaje);
			fflush(stdin);
			if (getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			fflush(stdin);
			printf("%s \n", mensajeError);
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {

	char buffer; //espacios de intercambio con el usuario
	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%c", &buffer);
			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}

			printf("%s \n", mensajeError);
			reintentos--;
		} while (reintentos >= 0);

	}

	return retorno;
}

int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {

	float buffer; //espacios de intercambio con el usuario
	int retorno = -1;

	do {
		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& minimo <= maximo && reintentos >= 0) {
			printf("%s", mensaje);
			if (getFloat(&buffer) == 0 && buffer >= minimo
					&& buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s \n", mensajeError);
			reintentos--;
		}

	} while (reintentos >= 0);

	return retorno;
}

int utn_getString(char *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	char buffer[4096]; //espacios de intercambio con el usuario
	int retorno = -1;

	do {
		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& minimo <= maximo && reintentos >= 0) {

			printf("%s", mensaje);
			if (getString(buffer) == 0 && strlen(buffer) >= minimo
					&& strlen(buffer) <= maximo) {

				strcpy(pResultado, buffer);
				retorno = 0;
				break;

			}
			printf("%s \n", mensajeError);
			reintentos--;
		}

	} while (reintentos >= 0);

	return retorno;
}

