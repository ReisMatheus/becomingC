#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50

struct tp_produto{//criação de uma struct tipo produto
	int cod;
	char nome[TAM];
	float preco;
};

struct tp_pilha{//criação de uma struct tipo pilha
	struct tp_produto *info;
	int topo;
};

void cria(struct tp_pilha *p, int tamanho){//função que reserva memória para variáveis da struct
	//tp_produto para cada posição da pilha
	p->info=(struct tp_produto*)malloc(tamanho*sizeof(struct tp_produto));
	p->topo = -1;
}

//Retira um Elemento da Pilha
int pop(){
	
}

//Adiciona Elemento dentro da Pilha
void push(struct tp_pilha *p, int tamanho){
	if(p->topo >= tamanho-1){
		printf("Pilha cheia\n");
		return;
	}
	else{
		for(int i=0; i<=tamanho-1; i++){
			
			printf("Codigo do produto: ");
			int cod;
			scanf("%d", &cod);

			printf("\nNome do produto: ");
			char nome[TAM];
			scanf("%s", nome);

			printf("\nPreco do %s: ", nome);
			float preco;
			scanf("%f", &preco);


			p->info[p->topo].cod = cod;
			strcpy(p->info[p->topo].nome, nome);
			p->info[p->topo].preco = preco;

			p->topo++;

			printf("\nAdicionado com sucesso\n");

			if(p->topo>=tamanho){
				break;
			}
			printf("(%d) para sair\n(0) para continuar\n", tamanho);
			scanf("%d", &i);
		}
		return;	
	}	
}

//Esvazia a Pilha por completo
int emptyStack(){
	
}

//Mostra todos os Elementos Validos da Pilha
void showStack(struct tp_pilha *p, int tamanho){
	int i;
	for(i=p->topo; i>=0; i--){
		printf("Codigo: %d\n", p->info[i-1].cod);
		printf("Nome: %s\n", p->info[i-1].nome);
		printf("Preco: %.2f\n", p->info[i-1].preco);
	}
}

void main(void){

	printf("Quantos produtos deseja cadastrar?\n");
	int tamanho;
	scanf("%d", &tamanho);

	//Aloca (struct tp_pilha) para o proprio tamanho
	struct tp_pilha *ptPilha;
	ptPilha = (struct tp_pilha*) malloc(sizeof(struct tp_pilha));

	cria(ptPilha, tamanho);
	int sair = 1;

	while(sair!=0){
		printf("(1) para inserir produtos na pilha\n(2) para excluir um elemento da pilha\n(3) para listar todos os campos dos elementos da pilha\n(0) para finalizar o programa\n");
		int opt;
		scanf("%d", &opt);
		switch(opt){
			case 1:{
				push(ptPilha, tamanho);
				break;
			}
			/*case 2:{
				break;
			}*/
			case 3:{
				showStack(ptPilha, tamanho);
				break;
			}
			case 0:{
				sair = opt;
				break;
			}
			default:{
				printf("Opcao invalida\n");
				break;
			}
		}
	}

}