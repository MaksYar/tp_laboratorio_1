#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TAM 1000
#define LEN 51
#define TRUE 0
#define FALSE 1
#define UP 1
#define DOWN 0

struct {
	int id;
	char name[LEN];
	char lastName[LEN];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

/**
 * @brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL ] - 0 si OK
 */
int initEmployees(Employee *list, int len);

/**
 * @brief Pide nombrea, apellido, salario y sector a dar de alta
 *
 * @param Aux puntero a estructura
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int auxiliarAdd(Employee *Aux);

/**
 * @brief Agrega en un array de empleados existente los valores recibidos como parámetro en la primer posición libre.
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @param name nombre a dar de alta
 * @param lastName apellido a dar de alta
 * @param salary salario a dar de alta
 * @param sector sector a dar de alta
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int addEmployee(Employee *list, int len, int id, char *name, char *lastName,float salary, int sector);

/**
 * @brief Imprime el array de empleados de forma encolumnada.
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int printEmployees(Employee *list, int len);

/**
 * @brief Busca un empleado recibiendo como parámetro de búsqueda su Id
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @param id id del empleado
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int findEmployeeById(Employee *list, int len, int id);

/**
 * @brief Modifica o nombre o apellido o salario o sector de un empleado
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int updateEmployee(Employee *list, int len);

/**
 * @brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int removeEmployee(Employee *list, int len);

/**
 * @brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @param order (0) orden descendente - (1) orden ascendente
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int sortEmployees(Employee *list, int len, int order);

/**
 * @brief Acumula el salario de todos los empleados
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @param acumulador puntero a variable que guardara el total acumulado
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int acumularSalario(Employee *list, int len, float *acumulador);

/**
 * @brief Calcula y pasa por parametro el promedio del salario de empleados
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @param promedio puntero a variable que guardara el salario promedio
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int calcularPromedioSalario(Employee *list, int len, float* promedio);

/**
 * @brief Cuenta la cantidad de empleados que superan el sueldo promedio
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @param promedio salario promedio
 * @param contador puntero a variable que guardara la cantidad de empleados
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int cuentaSuperaSalarioPromedio(Employee *list, int len, float promedio, int* contador);

/**
 * @brief Verifica si hay al menos una bandera isEmpty en FALSE
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @return int Retorna(0) si todas las banderas estan en TRUE - (1) al menos una esta en FALSE
 */
int hayAltasEmpleados(Employee *list, int len);

/**
 * @brief Imprime un empleado de forma encolumnada.
 *
 * @param list puntero a estructura
 * @param len tamaño del array
 * @param id id del empleado
 * @return int Retorna (-1) si hay Error [tamaño invalido o puntero a NULL] - 0 si OK
 */
int printEmployee(Employee *list, int len, int id);


#endif /* ARRAYEMPLOYEES_H_ */
