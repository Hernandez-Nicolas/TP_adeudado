#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"parser.h"

#define ERROR -1
#define LEN 128

typedef struct
{
    int id;
    char nombre[LEN];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
/** \brief Reserva espacio para un nuevo empleado
 *
 * \return Employee* devuelve un puntero que apunta hacia el nuevo empleado
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
/** \brief Reserva espacio en memoria para un nuevo empleado y los cargacon los datos del archivo
 *
 * \param char* idStr			Puntero a la cadena que contiene el dato del texto
 * \param char* nombreStr		Puntero a la cadena que contiene el dato del texto
 * \param char* horas trabajadasStr Puntero a la cadena que contiene el dato del texto
 * \param char* sueldoStr		Puntero a la cadena que contiene el dato del texto
 * \return int
 *
 */

int employee_delete(Employee* this);
/** \brief Elimina un empleado
 *
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_setId(Employee* this,int id);
/** \brief Se pasa un ID y luego lo coloca en el campo
 *			correspondiente del empleado que se paso
 *
 * \param int id		Pasa el id a colocar en el empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_getId(Employee* this,int* id);
/** \brief Se pasa un ID por referencia y con este se extrae el ID del empleado
 *
 * \param int id		Pasa por referencia el id a obtener del empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_setNombre(Employee* this,char* nombre);
/** \brief Se pasa un nombre y luego lo coloca en el campo
 * 		correspondiente del empleado que se paso
 *
 * \param int id		Pasa el nombre a colocar en el empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_getNombre(Employee* this,char* nombre);
/** \brief Se pasa un nombre y con este se extrae el nombre del empleado
 *
 * \param int id		Pasa el nombre a obtener del empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Se pasa las horas de trabajo y luego lo coloca en el campo
 * correspondiente del empleado que se paso
 *
 * \param int id		Pasa las horas de trabajo a colocar en el empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Se pasa las horas de trabajo por referencia y con este se extrae las del empleado
 *
 * \param int id		Pasa por referencia las horas de trabajoa obtener del empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_setSueldo(Employee* this,float sueldo);
/** \brief Se pasa el sueldo y luego lo coloca en el campo
 * correspondiente del empleado que se paso
 *
 * \param int id		Pasa el sueldo a colocar en el empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_getSueldo(Employee* this,float* sueldo);
/** \brief Se pasa el sueldo por referencia y con este se extrae el sueldo del empleado
 *
 * \param int id		Pasa por referencia el sueldo a obtener del empleado
 * \param pArrayListEmployee LinkedList* Puntero hacia la lista de nodos
 * \return int 			Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_compareName(void* empleado,void* empleado2);
/** \brief Compara por nombre a los empleados
 *
 * \param void*		Pasa uno de los parametros a comparar
 * \param void*		Pasa uno de los parametros a comparar
 * \return int Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_compareId(void* empleado,void* empleado2);
/** \brief compara por id a los emplados
 *
 * \param void*		Pasa uno de los parametros a comparar
 * \param void*		Pasa uno de los parametros a comparar
 * \return int Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_compareHoras(void* empleado,void* empleado2);
/** \brief compara por horas de trabajo a los empleados
 *
 * \param void*		Pasa uno de los parametros a comparar
 * \param void*		Pasa uno de los parametros a comparar
 * \return int Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

int employee_compareSueldo(void* empleado,void* empleado2);
/** \brief compara por sueldo a los empleados
 *
 * \param void*		Pasa uno de los parametros a comparar
 * \param void*		Pasa uno de los parametros a comparar
 * \return int Retorna ERROR en caso de error y 0 en caso de exito
 *
 */

#endif // employee_H_INCLUDED
