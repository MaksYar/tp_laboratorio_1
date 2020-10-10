
#ifndef UTN_H_
#define UTN_H_

/**
 * @brief Solicita un texto, lo valida, verifica y devuelve el resultado
 *
 * @param pResultado Puntero al resultado. Alli se dejará el número ingresado por el usuario
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mesnsaje a ser mostrado en caso de error
 * @param minimo Valor minimo aceptado
 * @param maximo Valor máximo aceptado
 * @param reintentos Cantidad de reintentos en el caso de error
 * @return En caso de exito (0), en caso de error(-1)
 */
int utn_getString(char *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/**
 * @brief Solicita un caracter al usuario, lo valida, verifica y devuelve el resultado
 *
 * @param pResultado Puntero al resultado. Alli se dejará el número ingresado por el usuario
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mesnsaje a ser mostrado en caso de error
 * @param minimo Valor minimo aceptado
 * @param maximo Valor máximo aceptado
 * @param reintentos Cantidad de reintentos en el caso de error
 * @return En caso de exito (0), en caso de error(-1)
 */

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,char minimo, char maximo, int reintentos);

/**
 * @brief Solicita un numero entero al usuario, lo valida, verifica y devuelve el resultado
 *
 * @param pResultado Puntero al resultado. Alli se dejará el número ingresado por el usuario
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mesnsaje a ser mostrado en caso de error
 * @param minimo Valor minimo aceptado
 * @param maximo Valor máximo aceptado
 * @param reintentos Cantidad de reintentos en el caso de error
 * @return En caso de exito (0), en caso de error(-1)
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);

/**
 * @brief Solicita un numero flotante al usuario, lo valida, verifica y devuelve el resultado
 *
 * @param pResultado Puntero al resultado. Alli se dejará el número ingresado por el usuario
 * @param mensaje Es el mensaje a ser mostrado
 * @param mensajeError Es el mesnsaje a ser mostrado en caso de error
 * @param minimo Valor minimo aceptado
 * @param maximo Valor máximo aceptado
 * @param reintentos Cantidad de reintentos en el caso de error
 * @return En caso de exito (0), en caso de error(-1)
 */

int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos);

#endif /* UTN_H_ */
