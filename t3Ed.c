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
	struct tp_produto *var=(struct tp_produto*)malloc(tamanho*sizeof(struct tp_produto));
	p->info=var;
}

int pop(){
	
}

void push(struct tp_pilha *p, int tamanho){
	if(p->topo > tamanho-1){
		printf("Pilha cheia\n");
		return;
	}
	else{
		printf("Codigo do produto: ");
		int cod;
		scanf("%d", &cod);
		p->info[p.topo]->cod = cod;
		printf("\nNome do produto: ");
		char nome[TAM];
		scanf("%s", nome);
		strcpy(&p->info[p.topo]->nome[p.topo], nome);
		printf("\nPreco do %s: ", nome);
		float preco;
		scanf("%f", &preco);
		p->info[p.topo]->preco = preco;

		printf("\nAdicionado com sucesso\n");
		p->topo = ++p->topo;
		return;
	}
}

int emptyStack(){
	
}
int showStack(struct tp_pilha *p, int tamanho){
	for(int i=p; p!=NULL; p=p){
		printf("Codigo: %d\n", p->info->cod);
		printf("Nome: %s\n", p->info->nome);
		printf("Preco: %.2f\n", p->info->preco);
	}
}

void main(void){
	struct tp_pilha *ptPilha;
	ptPilha->topo = -1;
	printf("Quantos produtos deseja cadastrar?\n");
	int tamanho;
	scanf("%d", &tamanho);
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