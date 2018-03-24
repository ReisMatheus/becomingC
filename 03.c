#include<stdlib.h>
#include<stdio.h>


typedef struct{
}strutura;

void main(){
	int valor;
	int *p;
	int a = 0;
	int contador = 5;
	p = (int *) malloc(5* sizeof(int));
	do{
		scanf("%i",p+a);
		valor = *(p+a);

		if(contador-1 == a){
			contador+=5;
			printf("realloc %d\n",contador);
			p = realloc(p, contador*sizeof(int));
			if(p){
				printf("realocado\n");
			}
			else{
				printf("memoria insuficiente\n");
			}
		};

		printf("A == %i ;; *P+A == %i\n", a,*(p+a));
		a++;

	}while(valor != 0);

	for(int i=0; i<contador; i++){
		printf("valor: %i [%i] endereco -> %p\n", *(p+i),i, p+i);
	};
};