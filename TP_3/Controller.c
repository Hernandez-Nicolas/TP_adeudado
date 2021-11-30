#include"Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
	FILE* archivo;
	int retorno;
	retorno=ERROR;
	if(pArrayListEmployee!=NULL){
		archivo=fopen(path,"r");
		if(archivo!=NULL){
			retorno=parser_EmployeeFromText(archivo,pArrayListEmployee);
		}
		fclose(archivo);
	}
    return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
	FILE* archivo;
	int retorno;
	retorno=ERROR;
	if(pArrayListEmployee!=NULL){
		archivo=fopen(path,"rb");
		if(archivo!=NULL){
			retorno=parser_EmployeeFromBinary(archivo,pArrayListEmployee);
		}
		fclose(archivo);
	}
    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee,int id){
	Employee* nuevoEmpleado;
	char nombre[LEN];
	int horasTrabajadas;
	float sueldo;
	int error;
	int retorno;
	error=0;
	retorno=ERROR;
	nuevoEmpleado=employee_new();
	if(pArrayListEmployee!=NULL&&nuevoEmpleado!=NULL){
		inputs_nombre("Ingrese su nombre completo: ",nombre,LEN);
		horasTrabajadas=inputs_entero("Ingrese las horas trabajadas: ",1,999);
		sueldo=inputs_flotante("Ingrese el sueldo: ",10000,100000);
		error+=employee_setId(nuevoEmpleado,id);
		error+=employee_setNombre(nuevoEmpleado,nombre);
		error+=employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas);
		error+=employee_setSueldo(nuevoEmpleado,sueldo);
		if(error==0){
			ll_add(pArrayListEmployee,(Employee*)nuevoEmpleado);
			retorno=0;
		}
	}
    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
	Employee* empleado;
	char nuevoNombre[LEN];
	float sueldo;
	int eleccion;
	int pocicion;
	int len;
	int retorno;
	retorno=ERROR;
	len=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL&&len!=0){
		controller_ListEmployee(pArrayListEmployee);
		pocicion=inputs_entero("Ingrese el empleado que quiera modificar: ",1,len);
		empleado=(Employee*)ll_get(pArrayListEmployee,pocicion-1);
		printf("1) Cambiar nombre\n2) Sumar horas de trabajo\n"
				"3) Restar horas de trabajo\n4) Cambiar sueldo\n5) Nomodificar nada\n");
		eleccion=inputs_entero("Ingrese que dato quiere modificar: ",1,5);
		switch(eleccion){
		case 1:
			inputs_nombre("Ingrese nombre completo: ",nuevoNombre,LEN);
			retorno=employee_setNombre(empleado,nuevoNombre);
			break;
		case 2:
			printf("Horas actuales: %d\n",empleado->horasTrabajadas);
			empleado->horasTrabajadas+=inputs_entero("Ingrese las horas a sumar: ",1,999);
			break;
		case 3:
			printf("Horas actuales: %d\n",empleado->horasTrabajadas);
			empleado->horasTrabajadas-=inputs_entero("Ingrese las horas a restar: ",1,empleado->horasTrabajadas);
			break;
		case 4:
			sueldo=inputs_flotante("Ingrese el nuevo sueldo: ",10000,100000);
			retorno=employee_setSueldo(empleado,sueldo);
			break;
		default:
			printf("No hubo cambios\n\n");
			retorno=0;
		}
	}
    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee){
	Employee* empleado;
	int id;
	char nombre[LEN];
	int horas;
	float sueldo;
	int eleccion;
	int pocicion;
	int len;
	int retorno;
	retorno=ERROR;
	len=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL&&len!=0){
		printf("1) Eliminar un empleado\n2) Limpiar la lista\n3) No hacer cambios\n");
		eleccion=inputs_entero("Ingrese su eleccion: ",1,3);
		switch(eleccion){
		case 1:
			controller_ListEmployee(pArrayListEmployee);
			pocicion=inputs_entero("Ingrese el empleado que quiera eliminar: ",1,len);
			empleado=(Employee*)ll_get(pArrayListEmployee,pocicion);
			employee_getId(empleado,&id);
			employee_getNombre(empleado,nombre);
			employee_getHorasTrabajadas(empleado,&horas);
			employee_getSueldo(empleado,&sueldo);
			printf("¿Realmente quiere eliminar al empleado?:\n"
					"%5d %20s %5d %10.2f\n"
					"1) Si\t2) No\n",id,nombre,horas,sueldo);
			eleccion=inputs_entero("Ingrese su eleccion: ",1,2);
			if(eleccion==1){
				ll_remove(pArrayListEmployee,pocicion);
				free(empleado);
				printf("Se elimino el empleado\n\n");
			}
			break;
		case 2:
			printf("¿Realmente quiere eliminar a todos los empleados de la lista?\n"
					"1) Si\t2) No\n");
			eleccion=inputs_entero("ingrese su eleccion: ",1,2);
			if(eleccion==1){
				for(int i=0;i<len;i++){
					empleado=(Employee*)ll_get(pArrayListEmployee,i);
					free(empleado);
				}
				ll_clear(pArrayListEmployee);
				printf("Se eliminaron los empleados\n\n");
			}
			break;
		default:
			printf("No hubo cambios\n\n");
		}
		retorno=0;
	}
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
	Employee* empleado;
	int id;
	char nombre[LEN];
	int horas;
	float sueldo;
	int len;
	int retorno;
	retorno=ERROR;
	len=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL&&len!=0){
		printf("Texto de prueba de impresion de datos\n");
		for(int i=0;i<len;i++){
			empleado=(Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(empleado,&id);
			employee_getNombre(empleado,nombre);
			employee_getHorasTrabajadas(empleado,&horas);
			employee_getSueldo(empleado,&sueldo);
			printf("%d)%5d %20s %5d %10.2f\n",i+1,id,nombre,
					horas,sueldo);
		}
		retorno=0;
	}
    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee){
	int eleccion;
	int eleccion2;
	int retorno;
	retorno=ERROR;
	if(pArrayListEmployee!=NULL){
		printf("1) Ordenar por Nombre\n2) Ordenar por ID\n"
				"3) ordenar por horas de trabajo\n4) Ordenar por sueldo\n"
				"5) No hacer cambios\n");
		eleccion=inputs_entero("Ingrese su eleccion: ",1,5);
		eleccion2=inputs_entero("Ingrese el orden para ordenar la lista\n"
				"1) Decendente\n2) Acendente\n",1,2);
		switch(eleccion){
		case 1:
			retorno=ll_sort(pArrayListEmployee,employee_compareName,eleccion2-1);
			break;
		case 2:
			retorno=ll_sort(pArrayListEmployee,employee_compareId,eleccion2-1);
			break;
		case 3:
			retorno=ll_sort(pArrayListEmployee,employee_compareHoras,eleccion2-1);
			break;
		case 4:
			retorno=ll_sort(pArrayListEmployee,employee_compareSueldo,eleccion2-1);
			break;
		default:
			printf("No hubo cambios\n\n");
			retorno=0;
		}
	}
    return retorno;
}

int controller_tomarId(LinkedList* listaEmpleados){
	Employee* empleado;
	int pocicion;
	int id;
	int retorno;
	retorno=ERROR;
	if(listaEmpleados!=NULL){
		pocicion=ll_len(listaEmpleados);
		empleado=(Employee*)ll_get(listaEmpleados,pocicion);
		employee_getId(empleado,&id);
		retorno=id;
	}
	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee){
	FILE* archivo;
	Employee* empleado;
	int id;
	char nombre[LEN];
	int horas;
	float sueldo;
	int len;
	int retorno;
	retorno=ERROR;
	len=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL&&len!=0){
		archivo=fopen(path,"w");
		if(archivo==NULL){
			retorno=1;
		}
		else{
			for(int i=0;i<len;i++){
				empleado=(Employee*)ll_get(pArrayListEmployee,i);
				employee_getId(empleado,&id);
				employee_getNombre(empleado,nombre);
				employee_getHorasTrabajadas(empleado,&horas);
				employee_getSueldo(empleado,&sueldo);
				fprintf(archivo,"%d,%s,%d,%f\n",id,nombre,horas,sueldo);
			}
		}
		fclose(archivo);
		retorno=0;
	}
    return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee){
	FILE* archivo;
	Employee* empleado;
	int len;
	int retorno;
	retorno=ERROR;
	len=ll_len(pArrayListEmployee);
	if(pArrayListEmployee!=NULL&&len!=0){
		archivo=fopen(path,"wb");
		if(archivo==NULL){
			retorno=1;
		}
		else{
			for(int i=0;i<len;i++){
				empleado=(Employee*)ll_get(pArrayListEmployee,i);
				fwrite(empleado,sizeof(Employee),1,archivo);
			}
		}
		fclose(archivo);
		retorno=0;
	}
    return retorno;
}

int conrtroller_eliminarLista(LinkedList* listaEmpleados){
	Employee* empleado;
	int len;
	int retorno;
	retorno=ERROR;
	len=ll_len(listaEmpleados);
	if(listaEmpleados!=NULL&&len!=0){
		for(int i=0;i<len;i++){
			empleado=(Employee*)ll_get(listaEmpleados,i);
			free(empleado);
		}
		ll_deleteLinkedList(listaEmpleados);
	}
    return retorno;
}
