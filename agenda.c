
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct 
{
	char *nCurso;
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    int nota5;
    int nota6;    
}curso;
curso *cur;
curso *nota;
int tam;

void (*funcPuntero)();
void vaciar(char temp[]){
	for(int i = 0; i < 60;i++){
		*temp = '\0';
		temp++;
	}
}

void llenar(){
	int n;
	int cont=0;
	char linea[200];
	char pal[30];
	char auxi[30];
	char *aux;
	tam = 0;
	char *pa=pal;
	FILE *archivo=NULL;
	archivo = fopen ("curso.txt", "r");

	while(!feof(archivo)){
		fgets(auxi,30,archivo);
		tam++;
	}
	rewind(archivo);

	cur = (curso*)malloc(tam*sizeof(curso));

	cont = 0;
	int j = 0;
	while (fgets(linea, 200, archivo)!=0){
		//int cond = 0;
		char *li=linea;
		aux=&auxi[0];
		vaciar(auxi);
		aux=&auxi[0];
		for (int i = 0; i < 200 && *li!='\0'; i++)
		{
			
			if (*li!='-'){					
					*aux=*li;
					aux++; 
					li++;					
				}	
			else{				
				//printf("%s\n", auxi);
				switch(cont){
						case 0:
							n = strlen(auxi) + 1;
							(cur+j)->nCurso = (char*)malloc(n*sizeof(char));
							strcpy((cur+j)->nCurso,auxi);
							cont++;
							break;
						case 1:							
							(cur+j)->nota1 = atoi(auxi);
							cont++;
							break;
						case 2:							
							(cur+j)->nota2 = atoi(auxi);
							cont++;
							break;
						case 3:							
							(cur+j)->nota3 = atoi(auxi);
							cont++;
							break;
						case 4:							
							(cur+j)->nota4 = atoi(auxi);
							cont++;
							break;
						case 5:							
							(cur+j)->nota5 = atoi(auxi);
							cont++;
							break;
						case 6:
							(cur+j)->nota6 = atoi(auxi);
							cont++;
							break;		
					}

				li++;
				aux=&auxi[0];
				vaciar(auxi);
				aux=&auxi[0];

			}		
		}						
		cont = 0;		
		//printf("%s-%d-%d-%d-%d-%d-%d\n",(cur+j)->nCurso,(cur+j)->nota1,(cur+j)->nota2,(cur+j)->nota3,(cur+j)->nota4,(cur+j)->nota5,(cur+j)->nota6);
		aux=&auxi[0];
		vaciar(auxi);
		aux=&auxi[0];
		j++;
	}
	
	fclose (archivo);
}
void llenarN(){
	int n;
	int cont=0;
	char linea[200];
	char pal[30];
	char auxi[30];
	char *aux;
	tam = 0;
	char *pa=pal;
	FILE *archivo=NULL;
	archivo = fopen ("nota.txt", "r");

	while(!feof(archivo)){
		fgets(auxi,30,archivo);
		tam++;
	}
	rewind(archivo);

	nota = (curso*)malloc(tam*sizeof(curso));

	cont = 0;
	int j = 0;
	while (fgets(linea, 200, archivo)!=0){
		int cond = 0;
		char *li=linea;
		aux=&auxi[0];
		vaciar(auxi);
		aux=&auxi[0];
		for (int i = 0; i < 200 && *li!='\0'; i++)
		{
			
			if (*li!='-'){					
					*aux=*li;
					aux++; 
					li++;					
				}	
			else{				
				//printf("%s\n", auxi);
				switch(cont){
						case 0:
							n = strlen(auxi) + 1;
							(nota+j)->nCurso = (char*)malloc(n*sizeof(char));
							strcpy((nota+j)->nCurso,auxi);
							cont++;
							break;
						case 1:							
							(nota+j)->nota1 = atoi(auxi);
							cont++;
							break;
						case 2:							
							(nota+j)->nota2 = atoi(auxi);
							cont++;
							break;
						case 3:							
							(nota+j)->nota3 = atoi(auxi);
							cont++;
							break;
						case 4:							
							(nota+j)->nota4 = atoi(auxi);
							cont++;
							break;
						case 5:							
							(nota+j)->nota5 = atoi(auxi);
							cont++;
							break;
						case 6:
							(nota+j)->nota6 = atoi(auxi);
							cont++;
							break;		
					}

				li++;
				aux=&auxi[0];
				vaciar(auxi);
				aux=&auxi[0];

			}		
		}						
		cont = 0;		
		//printf("%s-%d-%d-%d-%d-%d-%d\n",(nota+j)->nCurso,(nota+j)->nota1,(nota+j)->nota2,(nota+j)->nota3,(nota+j)->nota4,(nota+j)->nota5,(nota+j)->nota6);
		aux=&auxi[0];
		vaciar(auxi);
		aux=&auxi[0];
		j++;
	}
	
	fclose (archivo);
}
void crearCurso(){
	llenar();
	int cond = 0;
	char cadena[100];
	char cadena2[100];
	char nombre[50];
	char aux[50];
	//char *auxi = aux;
	int nota1;int nota2;
	int nota3;int nota4;
	int nota5;int nota6;
	FILE *archivo=NULL;
	FILE *fp=NULL;
	archivo = fopen ("curso.txt", "a+t");
	fp = fopen("nota.txt","a+t");
	
	while(1>0){
		
		printf("Ingrese nombre del curso: ");
		gets(nombre);
		fflush (stdin); 
		cond = 0;
		for (int i = 0; i < tam; i++)
		{
			sprintf(aux,"%s",(cur+i)->nCurso);
			if (strcmp(nombre,aux) == 0)
			{
				cond = 1;
				break;
			}

		}
		if (cond == 1){
			printf("Ya existe el curso\n");
		}else{
			break;
		}
	}
	while(1 > 0){
		printf("Ingrese porcentaje de examen 1: ");
	
		scanf("%d",&nota1);
		getchar();
		printf("Ingrese porcentaje de nota continua 1: ");
		scanf("%d",&nota2);
		getchar();
		printf("Ingrese porcentaje de examen 2: ");
		scanf("%d",&nota3);
		getchar();
		printf("Ingrese porcentaje de nota continua 2: ");
		scanf("%d",&nota4);
		getchar();

		printf("Ingrese porcentaje de examen 3: ");
		scanf("%d",&nota5);
		getchar();
		printf("Ingrese porcentaje de nota continua 3: ");
		scanf("%d",&nota6);
		getchar();
		if ((nota1 + nota2 + nota3 + nota4 +nota5 +nota6) == 100){
			break;
		}else{
			printf("Los porcentajes no llegan a 100% \n");
		}
	}
	
		
	
	sprintf(cadena, "%s-%d-%d-%d-%d-%d-%d-\n",nombre,nota1,nota2,nota3,nota4,nota5,nota6);
	sprintf(cadena2, "%s-0-0-0-0-0-0-\n",nombre);
	fputs(cadena,archivo);
	fputs(cadena2,fp);
	fclose (archivo);
	fclose (fp);
	free(cur);
}

void modificarNota(){
	llenarN();
	int opcion,cond,salir;
	char nombre[50];
	char aux[50];
	int i;
	printf("Desea buscar(1) o escoger el curso(2): \n");
	scanf("%d",&opcion);
	getchar();
	FILE *archivo=NULL;
    archivo = fopen ("nota.txt", "r+");
	switch(opcion){
		case 1:
			
			while(1 < 2){
				cond = 0;
				printf("Ingrese el curso a buscar: \n");
				gets(nombre);
				for (i = 0; i < tam; i++){
					sprintf(aux,"%s",(nota+i)->nCurso);
					if (strcmp(nombre,aux) == 0){
						cond = 1;
						break;
					}
				}
				if (cond == 1){
					break;
				}else{
					printf("Intente nuevamente(no se econtro el curso)\n");
				}
			}
			//llenarN();
    		while(1 < 2){
    			int nota1,nota2;
    			printf("Que notas desea modificar: 1.Primera subida,2. Segunda subida,3. Tercera subida: \n");
				scanf("%d",&opcion);
				getchar();
				switch(opcion){
					case 1:
						printf("Ingrese nota de examen 1:\n");
						scanf("%d",&nota1);
						getchar();
						printf("Ingrese nota de evaluacion continua 1:\n");
						scanf("%d",&nota2);
						getchar();
						(nota+i)->nota1 = nota1;
						(nota+i)->nota2 = nota2;
						break;
					case 2:
						printf("Ingrese nota de examen 2:\n");
						scanf("%d",&nota1);
						getchar();
						printf("Ingrese nota de evaluacion continua 2:\n");
						scanf("%d",&nota2);
						getchar();
						(nota+i)->nota3 = nota1;
						(nota+i)->nota4 = nota2;
						break;
					case 3:
						printf("Ingrese nota de examen 3:\n");
						scanf("%d",&nota1);
						getchar();
						printf("Ingrese nota de evaluacion continua 3:\n");
						scanf("%d",&nota2);
						getchar();
						(nota+i)->nota5 = nota1;
						(nota+i)->nota6 = nota2;
						break;
				}
				
				printf("Desea modificar algo mas del curso %s (1.salir,0continuar)\n",(nota+i)->nCurso );
				scanf("%d",&salir);
				getchar();
				if(salir == 1){
					break;
				}
    		}
    		printf("%d\n",tam );
    		for (int j = 0; j < tam-1; j++){
				char cadena[100];
				sprintf(cadena,"%s-%d-%d-%d-%d-%d-%d-\n",(nota+j)->nCurso,(nota+j)->nota1,(nota+j)->nota2,(nota+j)->nota3,(nota+j)->nota4,(nota+j)->nota5,(nota+j)->nota6);
				fputs(cadena,archivo);
			}
			fclose(archivo);
			break;
		case 2:
			
			for (int j = 0; j < tam-1; j++){
				printf("%d: %s\n",(j+1),(nota+j)->nCurso);
			}
			printf("Escoja un curso de toda la lista: \n");
			scanf("%d",&i);
			i = i-1;
			while(1 < 2){
    			int nota1,nota2;
    			printf("Que notas desea modificar: 1.Primera subida,2. Segunda subida,3. Tercera subida: \n");
				scanf("%d",&opcion);
				getchar();
				switch(opcion){
					case 1:
						printf("Ingrese nota de examen 1:\n");
						scanf("%d",&nota1);
						getchar();
						printf("Ingrese nota de evaluacion continua 1:\n");
						scanf("%d",&nota2);
						getchar();
						(nota+i)->nota1 = nota1;
						(nota+i)->nota2 = nota2;
						break;
					case 2:
						printf("Ingrese nota de examen 2:\n");
						scanf("%d",&nota1);
						getchar();
						printf("Ingrese nota de evaluacion continua 2:\n");
						scanf("%d",&nota2);
						getchar();
						(nota+i)->nota3 = nota1;
						(nota+i)->nota4 = nota2;
						break;
					case 3:
						printf("Ingrese nota de examen 3:\n");
						scanf("%d",&nota1);
						getchar();
						printf("Ingrese nota de evaluacion continua 3:\n");
						scanf("%d",&nota2);
						getchar();
						(nota+i)->nota5 = nota1;
						(nota+i)->nota6 = nota2;
						break;
				}
				
				printf("Desea modificar algo mas del curso %s (1.salir,0continuar)\n",(nota+i)->nCurso );
				scanf("%d",&salir);
				getchar();
				if(salir == 1){
					break;
				}
    		}
    		for (int j = 0; j < tam-1; j++){
				char cadena[100];
				sprintf(cadena,"%s-%d-%d-%d-%d-%d-%d-\n",(nota+j)->nCurso,(nota+j)->nota1,(nota+j)->nota2,(nota+j)->nota3,(nota+j)->nota4,(nota+j)->nota5,(nota+j)->nota6);
				fputs(cadena,archivo);
			}
    		fclose(archivo);
			break;
	}

	free(nota);
}

void eliminarCurso(){
	llenar();
	llenarN();
	int i;
	int opcion,cond,salir;
	char nombre[50];
	char aux[50];

	FILE *archivo=NULL;
    archivo = fopen ("nota.txt", "w");

    FILE *fp=NULL;
    fp = fopen ("curso.txt", "w");

	printf("Desea buscar(1) o escoger el curso(2): \n");
	scanf("%d",&opcion);
	getchar();

	switch(opcion){
		case 1:
			while(1 < 2){
				cond = 0;
				printf("Ingrese el curso a buscar: \n");
				gets(nombre);
				for (i = 0; i < tam; i++){
					sprintf(aux,"%s",(nota+i)->nCurso);
					if (strcmp(nombre,aux) == 0){
						cond = 1;
						break;
					}
				}
				if (cond == 1){
					break;
				}else{
					printf("Intente nuevamente(no se econtro el curso)\n");
				}
			}

			for (int j = 0; j < tam-1; j++){
				char cadena[100];
				char cadena2[100];
				if (j != i){
					sprintf(cadena2,"%s-%d-%d-%d-%d-%d-%d-\n",(nota+j)->nCurso,(nota+j)->nota1,(nota+j)->nota2,(nota+j)->nota3,(nota+j)->nota4,(nota+j)->nota5,(nota+j)->nota6);
					sprintf(cadena,"%s-%d-%d-%d-%d-%d-%d-\n",(cur+j)->nCurso,(cur+j)->nota1,(cur+j)->nota2,(cur+j)->nota3,(cur+j)->nota4,(cur+j)->nota5,(cur+j)->nota6);
					fputs(cadena2,archivo);
					fputs(cadena,fp);
				}
			}
			fclose(fp);
			fclose(archivo);
			break;
		case 2:
			for (int j = 0; j < tam-1; j++){
				printf("%d: %s\n",(j+1),(nota+j)->nCurso);
			}
			printf("Escoja un curso de toda la lista: \n");
			scanf("%d",&i);
			i = i-1;

			for (int j = 0; j < tam-1; j++){
				char cadena[100];
				char cadena2[100];
				if (j != i){
					sprintf(cadena2,"%s-%d-%d-%d-%d-%d-%d-\n",(nota+j)->nCurso,(nota+j)->nota1,(nota+j)->nota2,(nota+j)->nota3,(nota+j)->nota4,(nota+j)->nota5,(nota+j)->nota6);
					sprintf(cadena,"%s-%d-%d-%d-%d-%d-%d\n",(cur+j)->nCurso,(cur+j)->nota1,(cur+j)->nota2,(cur+j)->nota3,(cur+j)->nota4,(cur+j)->nota5,(cur+j)->nota6);
					fputs(cadena2,archivo);
					fputs(cadena,fp);
				}
			}
			fclose(fp);
			fclose(archivo);
			break;
	}
	free(cur);
	free(nota);
}

void consultar(){
	llenar();
	llenarN();
	char nombre[50];
	char aux[50];
	float aprobado = 10.5;
	float result;
	int opcion,cond,i;
	int n=0,por = 0;
	float final = 0;
	printf("Desea buscar(1) o escoger el curso(2): \n");
	scanf("%d",&opcion);
	getchar();

	switch(opcion){
		case 1:
			while(1 < 2){
				cond = 0;
				printf("Ingrese el curso a buscar: \n");
				gets(nombre);
				for (i = 0; i < tam; i++){
					sprintf(aux,"%s",(nota+i)->nCurso);
					if (strcmp(nombre,aux) == 0){
						cond = 1;
						break;
					}
				}
				if (cond == 1){
					break;
				}else{
					printf("Intente nuevamente(no se econtro el curso)\n");
				}
			}
			printf("                   %s                      \n",(cur+i)->nCurso);
			printf(" -------------------------------------------\n");
			printf("|                                           |\n");
			printf("|     porcentaje             nota           |\n");
			printf("|                                           |\n");
			
			if((nota+i)->nota1 != 0){
				final = (float)(final + (((cur+i)->nota1)*((nota+i)->nota1)));
				
				printf("|         %d                  %d            |\n",(cur+i)->nota1,(nota+i)->nota1);
				
			}else{ 
				por = por + (cur+i)->nota1;
				
				printf("|         %d                  -             |\n",(cur+i)->nota1);
				
			}
			if ((nota+i)->nota2 != 0){
				final = (float)(final + (((cur+i)->nota2)*((nota+i)->nota2)));
				printf("|         %d                  %d            |\n",(cur+i)->nota2,(nota+i)->nota2);
				printf("|                                           |\n");
			}else{
				por = por + (cur+i)->nota2;
				printf("|         %d                  -             |\n",(cur+i)->nota2);
				printf("|                                           |\n");
			}


			if((nota+i)->nota3 != 0){
				final = (float)(final + (((cur+i)->nota3)*((nota+i)->nota3)));
				
				printf("|         %d                  %d            |\n",(cur+i)->nota3,(nota+i)->nota3);
				
			}else{ 
				por = por + (cur+i)->nota3;
				
				printf("|         %d                  -             |\n",(cur+i)->nota3);
				
			}			
			if((nota+i)->nota4 != 0){
				final = (float)(final + (((cur+i)->nota4)*((nota+i)->nota4)));
				printf("|         %d                  %d            |\n",(cur+i)->nota4,(nota+i)->nota4);
				printf("|                                           |\n");
			}else{
				por = por + (cur+i)->nota4;
				printf("|         %d                  -             |\n",(cur+i)->nota4);
				printf("|                                           |\n");
			}


			if((nota+i)->nota5 != 0){
				final = (float)(final + (((cur+i)->nota5)*((nota+i)->nota5)));
				
				printf("|         %d                  %d            |\n",(cur+i)->nota5,(nota+i)->nota5);
				
			}else{ 
				por = por + (cur+i)->nota5;
				
				printf("|         %d                  -             |\n",(cur+i)->nota5);
				
			}
			if((nota+i)->nota6 != 0){
				final = (float)(final + (((cur+i)->nota6)*((nota+i)->nota6)));
				printf("|         %d                  %d            |\n",(cur+i)->nota6,(nota+i)->nota6);
				printf("|                                           |\n");
			}else{
				por = por + (cur+i)->nota6;
				printf("|         %d                  -             |\n",(cur+i)->nota6);
				printf("|                                           |\n");
			}
			printf(" -------------------------------------------\n");
			result = (float)(final + por*n);
			result = (float)result/100;
			//printf("%.2f\n", );
			if(result >= aprobado){
				printf("Lo hiciste :)\n");
				break;
			}else{
				for (int i = 0; i < 20; i++){
					n++;
					result = (float)(final + por*n);
					result = (float)result/100;
					if (result >= aprobado)
					{
						printf("Necesitas %d en las notas faltantes para aprobar\n", n);
						break;
					}
				}
			}
			
			break;
		case 2:
			for (int j = 0; j < tam-1; j++){
				printf("%d: %s\n",(j+1),(nota+j)->nCurso);
			}
			printf("Escoja un curso de toda la lista: \n");
			scanf("%d",&i);
			i = i-1;

			printf("                   %s                      \n",(cur+i)->nCurso);
			printf(" -------------------------------------------\n");
			printf("|                                           |\n");
			printf("|     porcentaje             nota           |\n");
			printf("|                                           |\n");
			
			if((nota+i)->nota1 != 0){
				final = (float)(final + (((cur+i)->nota1)*((nota+i)->nota1)));
				
				printf("|         %d                  %d            |\n",(cur+i)->nota1,(nota+i)->nota1);
				
			}else{ 
				por = por + (cur+i)->nota1;
				
				printf("|         %d                  -             |\n",(cur+i)->nota1);
				
			}
			if ((nota+i)->nota2 != 0){
				final = (float)(final + (((cur+i)->nota2)*((nota+i)->nota2)));
				printf("|         %d                  %d            |\n",(cur+i)->nota2,(nota+i)->nota2);
				printf("|                                           |\n");
			}else{
				por = por + (cur+i)->nota2;
				printf("|         %d                  -             |\n",(cur+i)->nota2);
				printf("|                                           |\n");
			}


			if((nota+i)->nota3 != 0){
				final = (float)(final + (((cur+i)->nota3)*((nota+i)->nota3)));
				
				printf("|         %d                  %d            |\n",(cur+i)->nota3,(nota+i)->nota3);
				
			}else{ 
				por = por + (cur+i)->nota3;
				
				printf("|         %d                  -             |\n",(cur+i)->nota3);
				
			}			
			if((nota+i)->nota4 != 0){
				final = (float)(final + (((cur+i)->nota4)*((nota+i)->nota4)));
				printf("|         %d                  %d            |\n",(cur+i)->nota4,(nota+i)->nota4);
				printf("|                                           |\n");
			}else{
				por = por + (cur+i)->nota4;
				printf("|         %d                  -             |\n",(cur+i)->nota4);
				printf("|                                           |\n");
			}


			if((nota+i)->nota5 != 0){
				final = (float)(final + (((cur+i)->nota5)*((nota+i)->nota5)));
				
				printf("|         %d                  %d            |\n",(cur+i)->nota5,(nota+i)->nota5);
				
			}else{ 
				por = por + (cur+i)->nota5;
				
				printf("|         %d                  -             |\n",(cur+i)->nota5);
				
			}
			if((nota+i)->nota6 != 0){
				final = (float)(final + (((cur+i)->nota6)*((nota+i)->nota6)));
				printf("|         %d                  %d            |\n",(cur+i)->nota6,(nota+i)->nota6);
				printf("|                                           |\n");
			}else{
				por = por + (cur+i)->nota6;
				printf("|         %d                  -             |\n",(cur+i)->nota6);
				printf("|                                           |\n");
			}
			printf(" -------------------------------------------\n");
			result = (float)(final + por*n);
			result = (float)result/100;
			//printf("%.2f\n", );
			if(result >= aprobado){
				printf("Lo hiciste :)\n");
				break;
			}else{
				for (int i = 0; i < 20; i++){
					n++;
					result = (float)(final + por*n);
					result = (float)result/100;
					if (result >= aprobado)
					{
						printf("Necesitas %d en las notas faltantes para aprobar\n", n);
						break;
					}
				}
			}
			break;
	}
}
void main (){
	
	int op;
	int a=0;
	
	
	while (a<1){
		printf("Que desea hacer:1.crear curso, 2.modificar nota,3. eliminar curso, 4. consultar, 5-salir\n");
		scanf("%d", &op);
		getchar();
		switch(op){
			case 1:
				printf("Crear curso\n");
				funcPuntero = crearCurso;
				funcPuntero();
				break;

			case 2:
				printf("Modificar nota\n");
				funcPuntero = modificarNota;
				funcPuntero();
				break;

			case 3:
				printf("eliminar curso\n");
				funcPuntero = eliminarCurso;
				funcPuntero();
				break;
			case 4:
				printf("Consultar\n");
				funcPuntero = consultar;
				funcPuntero();
				break;
			case 5:
				a=1;
				break;
		}
	}
	
}