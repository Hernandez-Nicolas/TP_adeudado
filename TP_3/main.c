#include <stdio.h>
#include <stdlib.h>
#include"inputs.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main(){
	setbuf(stdout,NULL);
	int salida;
	int contadorId;
    int eleccion;
    int bandera;
    int bandera2;
    int error;
    int len;
    bandera2=0;
    salida=1;
    contadorId=0;
    LinkedList* listaEmpleados;
    listaEmpleados=ll_newLinkedList();
    len=ll_len(listaEmpleados);
    do{
    	printf("1) Cargar los datos desde archivo(modo texto)\n2) Cargar los datos desde archivo(modo binario)\n"
    			"3) Alta de empleado\n4) Modificar datos del empleado\n5) Baja de empleado\n6) Listar empleados\n"
    			"7)Ordenar empleados\n8) Guardar los datos de los empleados en archivo(modo texto)\n"
    			"9) Guardar los datos de los empleados en archivo(modo binario)\n10) Salir\n");
    	eleccion=inputs_entero("Ingrese su eleccion: ",1,10);
        switch(eleccion){
        case 1:
        	error=controller_loadFromText("data.csv",listaEmpleados);
        	if(error==0){
        		contadorId=controller_tomarId(listaEmpleados);
        		bandera=1;
        	}
        	else{
        		if(error==1){
        			printf("Un archivo fue creado\n\n");
        		}
        	}
        	break;
        case 2:
        	error=controller_loadFromBinary("data.bin",listaEmpleados);
        	if(error==0){
        		bandera=1;
        	}
        	else{
        		if(error==1){
        			printf("Un archivo fue creado\n\n");
        		}
        	}
        	break;
        case 3:
        	error=controller_addEmployee(listaEmpleados,contadorId);
        	len=ll_len(listaEmpleados);
        	if(len>0){
        		bandera=1;
        	}
        	break;
        case 4:
        	if(bandera==1){
        		error=controller_editEmployee(listaEmpleados);
        	}
        	break;
        case 5:
        	if(bandera==1){
        		error=controller_removeEmployee(listaEmpleados);
        	}
        	break;
        case 6:
        	if(bandera==1){
        		error=controller_ListEmployee(listaEmpleados);
        	}
        	break;
        case 7:
        	if(bandera==1){
        		error=controller_sortEmployee(listaEmpleados);
        	}
        	break;
        case 8:
        	if(bandera==1){
        		error=controller_saveAsText("data.csv",listaEmpleados);
        		if(error==0){
        			bandera2=1;
        		}
        		else{
        			if(error==1){
        				printf("Un archivo fue creado\n\n");
        			}
        		}
        	}
        	break;
        case 9:
        	if(bandera==1){
        		error=controller_saveAsBinary("data.bin",listaEmpleados);
        		if(error==0){
        			bandera2=1;
        		}
        		else{
        			if(error==1){
        				printf("Un archivo fue creado\n\n");
        			}
        		}
        	}
        	break;
        default:
        	if(bandera==1&&bandera2==0){
        		eleccion=inputs_entero("Los cambios aun no fueron guardados en los archivos\n"
        				"Todos los datos que no fueron guardados seran eliminados\n"
        				"¿Seguro quiere salir?\n1) Si\n2) No\n",1,2);
        		if(eleccion==1){
        			salida=0;
        			error=0;
        			conrtroller_eliminarLista(listaEmpleados);
        		}
        	}
        	else{
        		eleccion=inputs_entero("¿Seguro quiere salir?\n1) Si\n2) No\n",1,2);
        		if(eleccion==1){
        			salida=0;
        			error=0;
        			conrtroller_eliminarLista(listaEmpleados);
        		}
        	}
        }
        if(error==ERROR){
        	printf("\tOCURRIO UN ERROR\n\n");
        }
    }while(salida);
    return EXIT_SUCCESS;
}

