#include"Employee.h"

Employee* employee_new(){
	Employee* nuevoEmpleado;
	nuevoEmpleado=(Employee*)malloc(sizeof(Employee));
	return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
	Employee* nuevoEmpleado;
	int id;
	char nombre[LEN];
	int horas;
	float sueldo;
	nuevoEmpleado=employee_new();
	if(nuevoEmpleado!=NULL){
		id=atoi(idStr);
		strcpy(nombre,nombreStr);
		horas=atoi(horasTrabajadasStr);
		sueldo=atof(sueldoStr);
		employee_setId(nuevoEmpleado,id);
		employee_setNombre(nuevoEmpleado,nombre);
		employee_setHorasTrabajadas(nuevoEmpleado,horas);
		employee_setSueldo(nuevoEmpleado,sueldo);
	}
	return nuevoEmpleado;
}

int employee_delete(Employee* this){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		free(this);
		retorno=0;
	}
	return retorno;
}

int employee_setId(Employee* this,int id){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,float sueldo){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		this->sueldo=sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo){
	int retorno;
	retorno=ERROR;
	if(this!=NULL){
		*sueldo=this->sueldo;
		retorno=0;
	}
	return retorno;
}

int employee_compareName(void* empleado,void* empleado2){
	Employee* aux;
	Employee* aux2;
	char nombre1[LEN];
	char nombre2[LEN];
	int retorno;
	retorno=ERROR;
	aux=(Employee*)empleado;
	aux2=(Employee*)empleado2;
	if(aux!=NULL&&aux2!=NULL){
		employee_getNombre(aux,nombre1);
		employee_getNombre(aux2,nombre2);
		retorno=strcmp(nombre1,nombre2);
	}
	return retorno;
}

int employee_compareId(void* empleado,void* empleado2){
	Employee* aux;
	Employee* aux2;
	int id1;
	int id2;
	int retorno;
	retorno=ERROR;
	aux=(Employee*)empleado;
	aux2=(Employee*)empleado2;
	if(aux!=NULL&&aux2!=NULL){
		employee_getId(aux,&id1);
		employee_getId(aux2,&id2);
		if(id1>id2){
			retorno=1;
		}
		else{
			retorno=-1;
		}
	}
	return retorno;
}

int employee_compareHoras(void* empleado,void* empleado2){
	Employee* aux;
	Employee* aux2;
	int horas1;
	int horas2;
	int retorno;
	retorno=ERROR;
	aux=(Employee*)empleado;
	aux2=(Employee*)empleado2;
	if(aux!=NULL&&aux2!=NULL){
		employee_getHorasTrabajadas(aux,&horas1);
		employee_getHorasTrabajadas(aux2,&horas2);
		if(horas1>horas2){
			retorno=1;
		}
		else{
			retorno=-1;
		}
	}
	return retorno;
}

int employee_compareSueldo(void* empleado,void* empleado2){
	Employee* aux;
	Employee* aux2;
	float sueldo1;
	float sueldo2;
	int retorno;
	retorno=ERROR;
	aux=(Employee*)empleado;
	aux2=(Employee*)empleado2;
	if(aux!=NULL&&aux2!=NULL){
		employee_getSueldo(aux,&sueldo1);
		employee_getSueldo(aux2,&sueldo2);
		if(sueldo1>sueldo2){
			retorno=1;
		}
		else{
			retorno=-1;
		}
	}
	return retorno;
}
