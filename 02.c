#include<stdio.h>
#include<stdlib.h>

struct atletas {
	char nome;
	int idade;
};

int main(){
	int tamanho;
	scanf("%d",&tamanho);
	struct atletas *p;
	p = (struct atletas*) malloc(tamanho *sizeof(struct atletas));
	for(int i=0; i<tamanho; i++){
		getchar();
		printf("digite o nome do jogador: ");
		scanf("%c",&(p+i) -> nome);
		printf("digite a idade do jogador: ");
		scanf("%i",&(p+i) -> idade);
	} 
	for(int i=0; i<tamanho; i++){
		printf("\nnome : %c endereco: %p\nidade: %i idade: %p\n",(p+i) -> nome, (void *) p+i,(p+i) -> idade, (void *) p+i);
	}
}

//DONE