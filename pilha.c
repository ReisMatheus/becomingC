#include<stdio.h>
#include<stdlib.h>
#define MAX 5
/*int pop(struct _pilha, valor){
	_pilha = valor;
}*/
struct _pilha{
	int info[MAX];
	int topo;
};



int push(struct _pilha* pt, int valor){

	int verifySize(struct _pilha* pt){
		if(pt->topo == MAX-1){
			return 5;
		}
		else{
			return 1;
		} 
	}

	int aux = verifySize(pt);

	if(aux!=5){
		pt->info[pt->topo] = valor;
		pt->topo = ++pt->topo;
		return 1;
	}
	else{
		return 2;
	}
}

int pop(struct _pilha* pt){
	if(pt->topo == -1){
		return 1;
	}
	else{
		pt->topo = --pt->topo;
		return 2;
	}
}

int emptyList(struct _pilha* pt){
	if(pt->topo == -1){
		return 1;
	}
	else{
		pt->topo = -1;
		return 2;
	}
}


void main(){
	struct _pilha *pt;
	int y = 1;

	pt = (struct _pilha*) malloc(MAX*sizeof(struct _pilha));
	pt->topo = -1;

	while(y!=0){
		printf("Preencher Pilha (1)\nEsvaziar Pilha (2)\nRetirar elemento da Pilha (3)\n\n");
		int opt, pilhaLoop = 1;
		scanf("%d", &opt);
		switch(opt){
			//Preenche a Pilha
			case 1:{
					while(pilhaLoop!=0){
						printf("Preencha os valores e descubra o fim da pilha\n");
						printf("Posicao do TOPO: %d\n", pt->topo+1);
						int valor;
						scanf("%i",&valor);
						int pushSaida = push(pt, valor);
						if(pushSaida!=1){
							printf("Pilha cheia\n");
							pilhaLoop = 0;
						}
						else{
							printf("%d alocado na posicao %d\n", valor, pt->topo+1);
						}
					}
				break;
			}
			//Esvazia a Pilha e verifica se ja esta vazia
			case 2:{
					int emptyListSaida = emptyList(pt);
					if(emptyListSaida == 1){
						printf("Pilha ja esta vazia\n");
					}
					if(emptyListSaida == 2){
						printf("A Pilha foi esvaziada com sucesso\n");
					}
				break;
			}
			//Retira apenas um elemento da pilha
			case 3:{
					int popSaida = pop(pt);
					if(popSaida == 1){
						printf("Pilha ja esta vazia\n");
					}
					if(popSaida == 2){
						printf("Elemente %d retidado da pilha\nTamanho atual da pilha: %d\n", pt->info[pt->topo-1], pt->topo+1);
					}
				break;
			}
			default:
				printf("Opcao invalida\n");
				break;
		}
		printf("Digite (0) para sair do programa; Digite (1) para continuar no programa\n");
		scanf("%i", &y);
	}
	free (pt);
}