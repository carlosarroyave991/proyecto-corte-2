#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Nodo{
 int dato;
 Nodo *siguiente;
};

bool validacion=false;
int contador_pila=0;
int contador_cola=0;

//PROTOTIPOS DE PILA//

FILE *archivo;
void archivopila(Nodo *&);
void cargarpila(Nodo *&);
void insertarpila(Nodo *&, int);
void borrarpila(Nodo *&);
void consultapila(Nodo *&,int);
void modificarpila(Nodo *&,int);
void eliminarpila(Nodo *&,int);
void mostrarElementos(Nodo *&);
void pilas();
void ordenarpila(Nodo *&pila);
void generarpila(Nodo *&, int);
void leerpila(Nodo *&);

//PROTOTIPOS DE COLA //
void colas();
void generarcolas(Nodo *&,Nodo *&,int);
void insertarcolas(Nodo *&,Nodo *&,int);
bool colaVacia(Nodo *);
void insertartxt(Nodo *&,Nodo *&);
void cargarcolas(Nodo *&,Nodo *&);
void leercolas(Nodo *&,Nodo *&);
void buscarnumero(Nodo *&,int);
void burbuja(Nodo *&frente);
void mostrarcolas(Nodo *&,Nodo *&);
void editarelementos(Nodo *&,Nodo *&,int);
void eliminarcola(Nodo *&,Nodo *&, int);
void vaciarcola(Nodo *&,Nodo *&);

int main(int argc, char** argv) {
	int num;
	int i;
	while(num!=3){
	printf("\n\tSEGUNDO PROYECTO DEL SEMESTRE.\n\n");
	printf("Ingrese un digito para escoger una opcion:");
	printf("\n1.)Pilas.");
	printf("\n2.)Colas.");
	printf("\n3.)Salir del programa.");
	printf("\nIngrese una opcion:");
	scanf("%i",&num);
	switch(num){
		case 1:
			pilas();
			system("pause");
			system("cls");
			break;
		case 2:
			colas();
			system("pause");
			system("cls");
			break;
		case 3:
			printf("\n\nEspero haberle ayudado.Vuelva pronto!\n\n");
			system("pause");
			system("cls");
	}
	}
	return 0;
}

void colas(){
	system("cls");
	Nodo *frente=NULL;
	Nodo *fin = NULL;
	int dato;
	int num;
	int i;
	while(num!=9){
	printf("\n\tBIENVENIDO AL MENU DE COLAS.\n\n");
	printf("Escoja una opcion:\n");
	printf("1.)Generar numeros aleatorios.\n");
	printf("2.)Cargar desde un archivo de txt.\n");
	printf("3.)Busqueda secuencial.\n");
	printf("4.)Ordenamiento.\n");
	printf("5.)Imprimir resultados.\n");
	printf("6.)Modificar colas.\n");
	printf("7.)Eliminar dato expecifico.\n");
	printf("8.)Eliminar resultados.\n");
	printf("9.)Salir.\n");
	printf("Digite opcion:");
	scanf("%i",&num);
	switch(num){
		case 1:
			system("cls");
			generarcolas(frente,fin,dato);
			system("pause");
			system("cls");
		break;
		case 2:
			system("cls");
			leercolas(frente,fin);
			system("pause");
			system("cls");
		break;
		case 3:
			system("cls");
			printf("\n\tUSTED DECIDIO HACER UNA BUSQUEDA SECUENCIAL.\n\n");
			if(frente==NULL){
			printf("La cola esta vacia, primero debe de generar informacion.\n");
		}else{
			printf("Digite el elemento que desea buscar en la cola:");
			scanf("%d", &dato);
			buscarnumero(frente,dato);
		}
		system("pause");
		system("cls");
		break;
		case 4:
			system("cls");
			printf("\n\tUSTED DECIDIO HACER UN ORDENAMIENTO DE COLA.\n\n");
			burbuja(frente);
			system("pause");
			system("cls");
		break;
		case 5:
			system("cls");
			printf("\n\tUSTED DECIDIO IMPRIMIR LOS RESULTADOS.\n\n");
			mostrarcolas(frente,fin);
			system("pause");
			system("cls");
		break;
		case 6:
			system("cls");
			printf("\n\tUSTED DECIDIO MODIFICAR LA COLA.\n\n");	
				printf("Digite el dato que desea modificar:");
				scanf("%d",&dato);		
				editarelementos(frente,fin,dato);
				printf("\nEl dato ha sido modificado con exito!\n");
				if(frente==NULL){
				
					printf("El dato no existe!\n");
				}
			system("pause");
			system("cls");
		break;
		case 7:
			system("cls");
			printf("\n\tUSTED DECIDIO ELIMINAR UN DATO EXPECIFICO EN LA COLA.\n\n");
			printf("Digite el dato que desea elimiar:");
			scanf("%d",&dato);
			eliminarcola(frente,fin,dato);
			printf("\nEl dato fue eliminado correctamente.\n");
			if(frente == NULL){
				printf("El dato no existe!\n");
			}
			system("pause");
			system("cls");
		break;
		case 8:
			printf("\n\tUSTED DECIDIO ELIMINAR TODA LA COLA.\n\n");
			vaciarcola(frente,fin);
			printf("La cola se encuentra vacia!\n");
			system("pause");
			system("cls");
		break;
		case 9:
		printf("\nEspero haberle ayudado!\n\n");
		system("pause");
		system("cls");
		break;
		default:
			printf("\nEse numero no esta en el rango. Vuelva a escoger!\n\n");
			system("pause");
			system("cls");
		break;
		}	
	}
	}

/////////////FUNCIONES COLA.//////////////////////////////////////////////

void generarcolas(Nodo *&frente,Nodo *&fin, int dato){
	int i,j,num,n;
	system("cls");
	i=0;
	while(num!=6){
	printf("\n\tUSTED DECIDIO GENERAR INFORMACION DE LA COLA.\n\n");
	printf("Escoja una opcion:\n");
	printf("1.)Generar 100 datos aleatorios.\n");
	printf("2.)Generar 500 datos aleatorios.\n");
	printf("3.)Generar 700 datos aleatorios.\n");
	printf("4.)Generar 1000 datos aleatorios.\n");
	printf("5.)Generar 1200 datos aleatorios.\n");
	printf("6.)Salir.\n");
	printf("Ingrese numero:");
	scanf("%i",&num);
	switch(num){
		case 1:
		srand(time(NULL));
		for (j=1;j<=100;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarcolas(frente,fin,dato);
		//archivopila100(pila);
		//vector[j]=num;
	}
       	insertartxt(frente,fin);
		system("pause");
		system("cls");
		break;
		case 2:
			srand(time(NULL));
		for (j=1;j<=500;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarcolas(frente,fin,dato);
	
		//archivopila500(pila);
		//vector[j]=num;	
	}
		insertartxt(frente,fin);
		system("pause");
		system("cls");
		break;
		case 3:
			srand(time(NULL));
		for (j=0;j<=700;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarcolas(frente,fin,dato);
		//archivopila700(pila);
		//vector[j]=num;
	}
	insertartxt(frente,fin);
		system("pause");
		system("cls");
		break;
		case 4:
		srand(time(NULL));
		for (j=0;j<=1000;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarcolas(frente,fin,dato);
		//archivopila1000(pila);
		//vector[j]=num;
	}
	insertartxt(frente,fin);
		system("pause");
		system("cls");
		break;
		case 5:
		srand(time(NULL));
		for (j=0;j<=1200;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarcolas(frente,fin,dato);
		//archivopila1200(pila);
		//vector[j]=num;
	}
	    insertartxt(frente,fin);
		system("pause");
		system("cls");
		break;
		case 6:
		printf("Espero haberle ayudado. Vuelva pronto!\n\n");
		system("pause");
		system("cls");
		break;
		default:
		printf("Esa opcion no esta en el rango mostrado, vuelva a intentar.\n\n");
		system("pause");
		system("cls");	
	}
	}
}

void insertarcolas(Nodo *&frente,Nodo *&fin,int n){
Nodo *nuevo_nodo = new Nodo();
 nuevo_nodo ->dato = n;
 nuevo_nodo -> siguiente=NULL;
 if(colaVacia(frente)){
 frente=nuevo_nodo;
 }else{
 fin -> siguiente = nuevo_nodo;
 printf(".)El dato %d\n",n );
 }
 fin = nuevo_nodo;
 //printf(".)El dato %d\n",n );

}

void insertartxt(Nodo *&frente, Nodo *&fin){
	Nodo *aux=frente;
 	archivo = fopen("Elementos_Recuperados.txt", "w");
    while(aux!=NULL){
    	fprintf(archivo,"%d\n",aux->dato);
 		
 		aux=aux->siguiente;
	}
 	fclose(archivo);
 	printf("Los datos han sido copiados exitosamente en un archivo de texto!\n");
}

bool colaVacia(Nodo *frente){
 return (frente==NULL)?true : false;
}

void leercolas(Nodo *&frente, Nodo *&fin){
	int i,num,dato;
	//while(num!=2){
	system("cls");
	printf("\n\tUSTED DECIDIO CARGAR INFORMACION DEl TXT.\n\n");			
	cargarcolas(frente,fin);
	system("pause");
	system("cls");
}

 void cargarcolas(Nodo *&frente, Nodo *&fin){
 Nodo *polo = frente;
 int dato,i=0;
 archivo = fopen("Elementos_Recuperados.txt", "W");
 if(frente==NULL){
 	printf("La cola esta vacia!\n");
 }
 else{
 	while(polo!=NULL){
 	fprintf(archivo,"%d\n",&polo->dato);
 	printf("%i.) %d\n",i+=1,polo->dato);
 	polo=polo->siguiente;

 }printf("Cargado con exito\n");
 }
 fflush(archivo);
 fclose(archivo);
 
}

void buscarnumero(Nodo *&frente, int dato){
 	Nodo *act = new Nodo();
 	act = frente;
 	bool x=false;	
 	while(act != NULL){ 		
 			if(act->dato==dato){ 				
 				x=true; 
				contador_cola+=1;					
			 }			 
			 act=act->siguiente;
		}
			 if(!x){
			 	printf("el numero %i no se encuentra en la cola.\n", dato);
			 }
			 else{
			 	printf("\nSe encontro el dato %i veces.",contador_cola);
			 }
	 }

void eliminarcola(Nodo *&frente, Nodo *&fin, int dato){
	int n,nuevo_dato;
	Nodo *aux=frente;
	while(aux!=NULL){
		if(aux->dato==dato){
			contador_cola+=1;
			printf("%i vez que se encuentra el dato.\n",contador_cola);
			aux->dato=NULL;
			aux->dato = aux->dato;;
		}
		aux = aux->siguiente;
	}
	contador_cola=0;
}

void burbuja(Nodo *&frente){
	Nodo *p=frente;
	Nodo *j;
	
	while(p != NULL){
		j=p->siguiente;
		
		while(j != NULL){
			if(p->dato > j->dato){
				int aux = j->dato;
				j->dato = p->dato;
				p->dato = aux;
			}
			j=j->siguiente;
		}
		p=p->siguiente;
	}
	printf("Los datos de la cola han sido ordenados exitosamente!\n");
}

void mostrarcolas(Nodo *&frente, Nodo *&fin){
	Nodo *n_cola = frente;
	Nodo *n2_cola = fin;
 if(frente == NULL){
 printf("La Cola Esta Vacia!\n");
 }else if(n_cola != NULL){
 while(n_cola != NULL){
 printf("-Dato Agregado: %d\n",n_cola->dato);
 n_cola = n_cola->siguiente;
 }
 }else{
 printf("-Dato Agregado: %d",n_cola->dato);
 }printf("\n");
 
 if(fin == NULL){
 printf(".");
 }else if(n_cola != NULL){
 while(n2_cola != NULL){
 printf("-Dato Agregado: %d\n",n2_cola->dato);
 n2_cola = n2_cola->siguiente;
 }
 }
}

void editarelementos(Nodo *&frente, Nodo *&fin, int dato){
	int n,nuevo_dato;
	Nodo *aux=frente;
	while(aux!=NULL){
		if(aux->dato==dato){
			contador_cola+=1;
			printf("%i vez que se encuentra el dato.\n",contador_cola);
			printf("Ingrese el dato por el que desea cambiarlo:");
			scanf("%i",&aux->dato);
			aux->dato = aux->dato;;
		}
		aux = aux->siguiente;
	}
	contador_cola=0;
}

void vaciarcola(Nodo *&frente,Nodo *&fin){
		while(frente != NULL){
				Nodo *aux = frente;
			if(frente==fin){
				
				frente=NULL;				
			}else{
				frente=frente->siguiente;
			}
			delete aux;
		}	
}
////////////FUNCIONES PILA.////////////////////////////////////////////////////////

void pilas(){
	system("cls");
	Nodo *pila= NULL;
	int dato;
	int num;
	int i;
	while(num!=9){
	printf("\n\tBIENVENIDO AL MENU DE PILAS.\n\n");
	printf("Escoja una opcion:\n");
	printf("1.)Generar numeros aleatorios.\n");
	printf("2.)Cargar desde un archivo de txt.\n");
	printf("3.)Busqueda secuencial.\n");
	printf("4.)Ordenamiento.\n");
	printf("5.)Imprimir resultados.\n");
	printf("6.)Modificar pila.\n");
	printf("7.)Eliminar dato expecifico.\n");
	printf("8.)Eliminar resultados.\n");
	printf("9.)Salir.\n");
	printf("Escoja opcion:");
	scanf("%i",&num);
	switch(num){
		case 1:
			system("cls");
			generarpila(pila,dato);
			system("pause");
			system("cls");
		break;
		case 2:
			system("cls");
			leerpila(pila);
			system("pause");
			system("cls");
		break;
		case 3:
			system("cls");
			printf("\n\tUSTED DECIDIO HACER UNA BUSQUEDA SECUENCIAL.\n\n");
			printf("Ingrese dato a buscar:");
			scanf("%i",&dato);
			consultapila(pila,dato);
			if(contador_pila != NULL){
				printf("El dato esta %i veces.\n\n",contador_pila);	
			}else{
				printf("El dato no esta!\n");
			}
			contador_pila=0;
			system("pause");
			system("cls");
		break;
		case 4:
			printf("\n\tUSTED DECIDIO ORDENAR LA PILA.\n\n");
			printf("La pila se ordenara con el Metodo Burbuja.\n");
			ordenarpila(pila);
			
		printf("\nEspero haberle ayudado!\n\n");
		system("pause");
		system("cls");
		break;
		case 5:
			system("cls");
			printf("\n\tUSTED DECIDIO IMPRIMIR LOS RESULTADOS DE LA PILA.\n\n");
			mostrarElementos(pila);
			system("pause");
			system("cls");
		break;
		case 6:
			system("cls");
			printf("\n\tUSTED DECIDIO MODIFICAR LA PILA.\n\n");
			printf("Ingrese dato a buscar:");
			scanf("%i",&dato);
			modificarpila(pila,dato);
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			printf("\n\tUSTED DECIDIO ELIMINAR UN DATO EXPECIFICO.\n\n");
			printf("Ingrese dato a buscar:");
			scanf("%i",&dato);
			eliminarpila(pila,dato);
			system("pause");
			system("cls");	
		break;
		case 8:
			system("cls");
			printf("\n\tUSTED DECIDIO BORRAR LA PILA.\n\n");
			borrarpila(pila);
			system("pause");
			system("cls");
		break;
		case 9:
		printf("\nESpero haberle ayudado!\n\n");
		system("pause");
		system("cls");
		break;
		default:
			printf("\nEse numero no esta en el rango. Vuelva a escoger!\n\n");
			system("pause");
			system("cls");
		break;
	}
	}
}

void generarpila(Nodo *&pila, int dato){
	int i,j,num,n;
	system("cls");
	i=0;
	while(num!=6){
	printf("\n\tUSTED DECIDIO GENERAR INFORMACION DE LA PILA.\n\n");
	printf("Escoja una opcion:\n");
	printf("1.)Generar 100 datos aleatorios.\n");
	printf("2.)Generar 500 datos aleatorios.\n");
	printf("3.)Generar 700 datos aleatorios.\n");
	printf("4.)Generar 1000 datos aleatorios.\n");
	printf("5.)Generar 1200 datos aleatorios.\n");
	printf("6.)Salir.\n");
	printf("Ingrese numero:");
	scanf("%i",&num);
	switch(num){
		case 1:
		
		srand(time(NULL));
		for (j=1;j<=100;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarpila(pila,dato);

		//archivopila100(pila);
		//vector[j]=num;
	}
       	archivopila(pila);
		system("pause");
		system("cls");
		break;
		case 2:
			srand(time(NULL));
		for (j=1;j<=500;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarpila(pila,dato);
	
		//archivopila500(pila);
		//vector[j]=num;	
	}
		archivopila(pila);
		system("pause");
		system("cls");
		break;
		case 3:
			srand(time(NULL));
		for (j=0;j<=700;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarpila(pila,dato);
		//archivopila700(pila);
		//vector[j]=num;
	}
	archivopila(pila);
		system("pause");
		system("cls");
		break;
		case 4:
		srand(time(NULL));
		for (j=0;j<=1000;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarpila(pila,dato);
		//archivopila1000(pila);
		//vector[j]=num;
	}
	archivopila(pila);
		system("pause");
		system("cls");
		break;
		case 5:
		srand(time(NULL));
		for (j=0;j<=1200;j++){
		dato=1 + rand() % ((99999+1)-1);
		i++;
		fflush(stdin);
		printf("%i",i);
		//nuevo_nodo->dato=n;	
		insertarpila(pila,dato);
		//archivopila1200(pila);
		//vector[j]=num;
	}
	    archivopila(pila);
		system("pause");
		system("cls");
		break;
		case 6:
		printf("Espero haberle ayudado. Vuelva pronto!\n\n");
		system("pause");
		system("cls");
		break;
		default:
		printf("Esa opcion no esta en el rango mostrado, vuelva a intentar.\n\n");
		system("pause");
		system("cls");	
	}
	}
}

void leerpila(Nodo *&pila){
	int i,num,dato;
	//while(num!=2){
	system("cls");
	printf("\n\tUSTED DECIDIO CARGAR INFORMACION DEl TXT.\n\n");			
	cargarpila(pila);
	system("pause");
	system("cls");
}

void archivopila(Nodo *&pila){
	FILE *abrir;
	Nodo *aux = pila;
	abrir = fopen("generar_datos.txt","w");
	while(aux!=NULL){
		fprintf(abrir,"%i\n",aux->dato);
		aux=aux->siguiente;
	}
	fclose(abrir);
}

void insertarpila(Nodo *&pila,int n){
Nodo *nuevo_nodo= new Nodo();
nuevo_nodo->dato=n;
nuevo_nodo->siguiente=pila;
pila=nuevo_nodo;
printf(".)El dato %d\n",n );

}

void borrarpila(Nodo *&pila){
int i=0;

 while(pila!=NULL){
i+=1;
  Nodo *aux=pila;
 // n=aux->dato;
  pila=aux->siguiente;
  printf("%i.)%d.\n",i,aux->dato);
  delete aux; 
 }
}

void cargarpila(Nodo *&pila){
	Nodo *polo = pila;
	int dato,i;
	archivo = fopen("generar_datos.txt","r");
	//if(!feof(archivo)){
	if(archivo!=NULL){
		while(!feof(archivo)){
		//dato=polo->dato;
		fscanf(archivo,"%i\n",&dato);
		printf("%i.)%d\n",i+=1,dato);
		//polo = polo->siguiente;
	}	
	}else{
		printf("\nEl documento txt esta vacio!.");
	}
	fclose(archivo);
}

void consultapila(Nodo *&pila, int dato){
	Nodo *Nueva_pila = pila;
	while(Nueva_pila != NULL){
		if(Nueva_pila->dato == dato){
			contador_pila+=1;
		}
		Nueva_pila=Nueva_pila->siguiente;
	}
}

void modificarpila(Nodo *&pila, int dato){
	Nodo *Nueva_pila = pila;
	while(Nueva_pila != NULL){
		if(Nueva_pila->dato == dato){
			contador_pila+=1;
			printf("%i vez que se encuentra el dato.\n",contador_pila);
			printf("Ingrese el dato por el que desea cambiarlo:");
			scanf("%i",&Nueva_pila->dato);
			//delete Nueva_pila->dato;
			//Nueva_pila=Nueva_pila->dato;
		}
			Nueva_pila=Nueva_pila->siguiente;
	}
	contador_pila=0;
}

void eliminarpila(Nodo *&pila, int dato){
	Nodo *Nueva_pila = pila;
	while(Nueva_pila != NULL){
		if(Nueva_pila->dato == dato){
			contador_pila+=1;
			printf("%i vez que se encuentra el dato.\n",contador_pila);
			printf("El dato se ha borrado correctamente.\n");
			Nueva_pila->dato=NULL;
			//Nueva_pila=Nueva_pila->dato;
		}
			Nueva_pila=Nueva_pila->siguiente;
	}
	contador_pila=0;
}

void mostrarElementos(Nodo *&pila){
 Nodo *Nueva_Pila = pila;
 if(pila==NULL){
 printf("\nLa pila esta vacia!\n");
 }else if(Nueva_Pila != NULL){
 while(Nueva_Pila != NULL){
 printf("%d",Nueva_Pila->dato);
 printf("\n");
 Nueva_Pila = Nueva_Pila->siguiente;
 }
 }else{
 printf("%d.",Nueva_Pila->dato);
 }printf("\n");
}

void insercionpila(Nodo *&pila){
	Nodo *Nueva_Pila = pila;
	if(pila == NULL){
		printf("\nLa pila esta vacia!\n");
	}else if(Nueva_Pila !=NULL){
		
	}
}

void ordenarpila(Nodo *&pila) {
            Nodo *Nueva_Pila=pila;
            Nodo *j;
            int contador=1;
            if(Nueva_Pila==NULL){
                  printf("\nDebes ingresar informacion a la pila primero\n");
            }
            while(Nueva_Pila!=NULL)
            {
                    j=Nueva_Pila->siguiente;
                    while(j!=NULL)
                    {
                            if(Nueva_Pila->dato > j->dato)
                            {
                                    int aux=j->dato;
                                    j->dato=Nueva_Pila->dato;
                                    Nueva_Pila->dato=aux;
                            }
                            j=j->siguiente;
                            contador++;
                    }
                    Nueva_Pila=Nueva_Pila->siguiente;
            }
            Nueva_Pila=pila;
            while(Nueva_Pila!=NULL)
            {
                    printf("->%d\n",Nueva_Pila->dato);
                    Nueva_Pila=Nueva_Pila->siguiente;
            }
            printf("\n\n");
            system("pause");
            system("cls");
}


