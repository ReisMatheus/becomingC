#include<stdlib.h>
#include<stdio.h>

typedef struct{
}strutura;

void main(){
	int tamanho;
	scanf("%d",&tamanho);
	int *p;
	p = (int *) malloc(tamanho*sizeof(int));
	for(int i=0; i<tamanho; i++){
		scanf("%d",p+i);
	}
	for(int i=0; i<tamanho; i++){
		printf("valor: %i [] endereco -> %p\n", *(p+i), p+i);
	}

}

//DONE 