#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "parser.h"

#define ERROR -1

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Pasa el nombre del archivo
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error, 1 en caso de no existir el archivo y 0 si lo abrio correctamente
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* Pasa el nombre del archivo
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error, 1 en caso de no existir el archivo y 0 si lo abrio correctamente
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee,int id);
/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int controller_tomarId(LinkedList* listaEmpleados);
/** \brief Toma el id del ultimo elemento en la lista
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error y el id en caso de exito
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados hacia el archivo data.csv (modo texto).
 *
 * \param path char* Pasa el nombre del archivo
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error, 1 en caso de no existir el archivo y 0 si lo abrio correctamente
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Carga los datos de los empleados hacia el archivo data.csv (modo biario).
 *
 * \param path char* Pasa el nombre del archivo
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error, 1 en caso de no existir el archivo y 0 si lo abrio correctamente
 *
 */

int conrtroller_eliminarLista(LinkedList* listaEmpleados);
/** \brief Elimina todos los nodos y la lista, tambien libera todo el espacio en memoria
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int		Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

#endif
