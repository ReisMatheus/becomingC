#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50

//Criação de uma struct tipo produto
struct tp_produto{
	int cod;
	char nome[TAM];
	float preco;
};

//Criação de uma struct tipo pilha
struct tp_pilha{
	struct tp_produto *info;
	int topo;
};

//Função que reserva memória para variáveis da struct
void cria(struct tp_pilha *p, int tamanho){
	//tp_produto para cada posição da pilha
	p->info=(struct tp_produto*)malloc(tamanho*sizeof(struct tp_produto));
	p->topo = -1;
}

//Retira um Elemento da Pilha
void pop(struct tp_pilha *p){

	//Se a Pilha estiver vazia mostra "Pilha Vazia"
	if(p->topo == -1){
		printf("Pilha Vazia\n");
		return;
	}
	//Se a Pilha NAO estiver vazia, mostra "Elemento retirado com sucesso" e decrementa o valor do topo em 1
	else{
		p->topo--;
		printf("Elemento retirado com sucesso\n");
		return;
	}
}

//Adiciona Elemento dentro da Pilha
void push(struct tp_pilha *p, int tamanho){
	//Se a Pilha estiver cheia, mostra "Pilha Cheia"
	if(p->topo >= tamanho-1){
		printf("Pilha cheia\n");
		return;
	}
	/*Se a Pilha NAO estiver vazia, entra com um novo produto ate que a Pilha esteja cheia
	ou ate que o usuario digite (0) */
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

			p->topo++;

			(p->info+i)->cod = cod;
			strcpy((p->info+i)->nome, nome);
			(p->info+i)->preco = preco;


			printf("\nAdicionado com sucesso\n");

			if(p->topo>=tamanho-1){
				break;
			}
			//Controle de Saida via entrada de Usuario
			int control;
			printf("(1) para SAIR\n(0) para CONTINUAR\n");
			scanf("%d", &control);
			if(control)break;
		}
		return;	
	}	
}

//Funcao que esvazia a Pilha por completo
void emptyStack(struct tp_pilha *p){
	//Se a Pilha estiver vazia mostra "Pilha Vazia"
	if(p->topo == -1){
		printf("Pilha Vazia\n");
		return;
	}
	/*Se a Pilha NAO estiver cheia, mostra "Pilha esvaziada com sucesso" e altera
	variavel(topo) para -1 (inicio da Pilha) */
	else{
		p->topo = -1;
		printf("Pilha esvaziada com sucesso\n");
		return;
	}
	
}

//Funcao que mostra todos os Elementos Validos da Pilha
void showStack(struct tp_pilha *p, int tamanho){
	//Verifica se Pilha esta vazia e mostra "Pilha Vazia"
	if(p->topo == -1){
		printf("Pilha Vazia\n");
		return;
	}
	//Mostra todos os elementos VALIDOS da Pilha (0..topo)
	int i;
	for(i=0; i<=p->topo; i++){
		printf("\nCodigo: %d\n", (p->info+i)->cod);
		printf("Nome: %s\n", (p->info+i)->nome);
		printf("Preco: %.2f\n\n", (p->info+i)->preco);
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
		printf("(1) para INSERIR produtos na pilha\n(2) para EXCLUIR um elemento da pilha\n(3) para ESVAZIAR a pilha\n(4) para LISTAR todos os campos dos elementos da pilha\n(0) para FINALIZAR o programa\n");
		int opt;
		scanf("%d", &opt);
		switch(opt){
			case 1:{
				push(ptPilha, tamanho);
				break;
			}
			case 2:{
				pop(ptPilha);
				break;
			}
			case 3:{
				emptyStack(ptPilha);
				break;
			}
			case 4:{
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