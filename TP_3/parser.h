#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*  Pasa el puntero que apunta hacia el FILE que abrio el archivo
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int			En caso de error retorna ERROR, en caso de exito retorna 0
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*		Pasa el puntero que apunta hacia el FILE que abrio el archivo
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int				En caso de error retorna ERROR, en caso de exito retorna 0
 *
 */

#endif /* PARSER_H_ */
