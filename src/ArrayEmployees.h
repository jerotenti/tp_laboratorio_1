#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LENGHT_DATA 51
#define EMPTY 0
#define FULL 1
#define REMOVED -1

typedef struct
{
	int id;
	char name[LENGHT_DATA];
	char lastName[LENGHT_DATA];
	float salary;
	char description[LENGHT_DATA];
	int idSector;
	int isEmpty;
}Employee;

typedef struct
{
	int idSector;
	char sectorDescription[LENGHT_DATA];
	int isEmpty;
}Sector;

/**
 * @fn int initEmployees([], int)
 * @brief Inicializar el array de empleados
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @return int - "0"
 */
/** */
int initEmployees(Employee list[], int len);

/**
 * @fn int addEmployees(Employee[], int, Sector[], int)
 * @brief
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @param listOfSector[] Sector - Array de tipo Sector
 * @param lenSector int - Indica el tamaño de "listSector"
 * @return int - "0"
 */
int addEmployees(Employee list[], int len, Sector listOfSector[], int lenSector);

/**
 * @fn int findEmployeeById(Employee[], int, int)
 * @brief Encontrar un empleado a través de su ID
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @param ID - El ID del empleado
 * @return returnValue int - "0" si se encontró el ID o "-1" si hubo un error
 */
int findEmployeeById(Employee list[], int len, int ID);

/**
 * @fn int removeEmployee(Employee[], int)
 * @brief Dar de baja a un empleado
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @return returnValue int - "0" si se pudo dar de baja o "-1" si hubo un error
 */
int removeEmployee(Employee list[], int len);

/**
 * @fn int sortEmployees(Employee[], int, int)
 * @brief Ordenar el array de empleados por apellido y sector de manera ascendente o descendente.
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @param order int - "1" y se ordenará de forma ascendente o "0" si es de forma descendente
 * @return returnValue int - "0" si se pudo ordenar o "-1" si hubo un error
 */
int sortEmployees(Employee list[], int len, int order);

/**
 * @fn int printEmployees(Employee[], int)
 * @brief Imprimir en pantalla la lista de empleados con sus datos
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @return returnValue int - "0" si se pudo listar o "-1" si hubo un error
 */
int printEmployees(Employee list[], int len);

/**
 * @fn int getEmptyIndex(Employee[], int)
 * @brief Tomar el índice del array de empleados
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @return returnValue int - Retorna el indice del array Employee o "-1" si hubo un error
 */
int getEmptyIndex(Employee list[], int len);

/**
 * @fn int employee_getID(void)
 * @brief Crea un ID para un empleado
 *
 * @return Un acumulador del ID empleado
 */
int employee_getID(void);

/**
 * @fn int sector_getID(void)
 * @brief Crea un ID para un sector
 *
 * @return Un acumulador del ID sector
 */
int sector_getID(void);

/**
 * @fn Employee requestEmployeeData(Employee[], int, Sector[], int)
 * @brief Pide los datos de un empleado
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @param listSector[] Sector - Array de tipo Sector
 * @param lenSector int - Indica el tamaño de "listSector"
 * @return myEmployee Employee - La estructura de tipo Employee
 */
Employee requestEmployeeData(Employee list[], int len, Sector listSector[], int lenSector);

/**
 * @fn int Employee_modify(Employee[], int)
 * @brief Modificar datos de un empleado
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @return returnValue int - "0" si la modificación fue exitosa o "-1" si hubo un error
 */
int Employee_modify(Employee list[], int len);

/**
 * @fn void printOneEmployee(Employee)
 * @brief Imprimir en pantalla un empleado
 *
 * @param myEmployee Employee - Array de tipo Employee
 */
void printOneEmployee(Employee myEmployee);

/**
 * @fn int calculateAverageSalary(Employee[], int)
 * @brief Calcular y mostrar el total, el promedio y la cantidad de empleados que superan el promedio de salarios
 *
 * @param list[] Employee - Array de tipo Employee
 * @param len int - Indica el tamaño de "list"
 * @return returnValue int - "0" si el calculo fue exitoso o "-1" si hubo un error
 */
int calculateAverageSalary(Employee list[], int len);

#endif /* ARRAYEMPLOYEES_H_ */
