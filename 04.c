#include<stdio.h>
#include<stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
	int *v3 = (int *) malloc(n1+n2 * (sizeof(int)));

	for(int i=0;i<n1-1;i++){
		*(v3+i) = *(v1+i);
	};

	for(int i=5;i<n2+6;i++){
		*(v3+i) = *(v2+i);
	};

	return v3;
};

int main(){
	int v1[] = {2,4,5,7,8}; 
	int v2[] = {20,25,98,77,31,24,54};
	int n1 = 5, n2 = 7;
	int *v3 = uniao(&v1,n1,&v2,n2);

	for(int i=0; i<n1+n2; i++){
		printf("%i",*(v3+i));
	};

};
//int* uniao(int *v1, int n1, int *v2, int n2);
//para facilitar, é melhor percorrer o maior vetor primeiro
// vc pega o v1[0] e percorre todo o v2 de 0 a n2-1;

// quando encontra uma ocorrencia de v1[x] = v2[y]
// v3[] recebe um realloc de tam_atual+1; e  recebe v1[x]
//aí continua o for até chegar em v1[n1-1]
