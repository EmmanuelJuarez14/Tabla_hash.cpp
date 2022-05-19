//Autor: Juarez Palma Emmanuel
//Intrucciones: funciones del usuario metodo del residuo, genera n aleatorios, arreglo dinamico, colisiones, despues de efectuar k pruebas sacar el promedio y orden computacional, sacar n datos
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct dinamic_arr{
    int tam_arr=0;
    int *arr;
};

int main(){
	srand(time(NULL));
	int i,num_val,valor;
	
	//Creacion de valores aleatorios para ingresar a la tabla hash
	printf("Cuantos valores aleatorios deseas crear\n");
	scanf("%d",&num_val);
	
	int *arr_aux=(int*)malloc(num_val*sizeof(int));
	
	for(i=0;i<num_val;i++){
		arr_aux[i]=1+rand()%100;
	}
	
	printf("\n Arreglo generado: \n");
	
	for(i=0;i<num_val;i++){
		printf("[%d]: %d\t",i,arr_aux[i]);
	}
	
	//Creamos un arreglo que contenga una serie de estructuras que a su vez contienen arreglos dinamicos
	dinamic_arr * arr_of_arr = (dinamic_arr*)malloc(sizeof(dinamic_arr)*num_val);
	
	for(i=0;i<num_val;i++){
	    arr_of_arr[i].arr=NULL;
	}
	
	int indice_arreglo,j;
	for(i=0;i<num_val;i++){
	    indice_arreglo = arr_aux[i]%num_val;
	    if(arr_of_arr[indice_arreglo].arr==NULL){
	        arr_of_arr[indice_arreglo].tam_arr=arr_of_arr[indice_arreglo].tam_arr+1;
	        arr_of_arr[indice_arreglo].arr=(int*)malloc(sizeof(int)*arr_of_arr[indice_arreglo].tam_arr);
	        arr_of_arr[indice_arreglo].arr[arr_of_arr[indice_arreglo].tam_arr-1]=arr_aux[i];
	    }else{
	        arr_of_arr[indice_arreglo].tam_arr=arr_of_arr[indice_arreglo].tam_arr+1;
	        realloc(arr_of_arr[indice_arreglo].arr,arr_of_arr[indice_arreglo].tam_arr);
            arr_of_arr[indice_arreglo].arr[arr_of_arr[indice_arreglo].tam_arr-1]=arr_aux[i];	        
	    }
	}
	
	for (i=0;i<num_val;i++){
	    if(arr_of_arr[indice_arreglo].arr==NULL){
	        printf("Arreglo vacio\n");
	    }else{
	        for(j=0;j<arr_of_arr[i].tam_arr;j++){
	            printf("[%d]: %d\t",j,arr_of_arr[i].arr[j]);
	        }
	    }
	}
	return 0;
}

