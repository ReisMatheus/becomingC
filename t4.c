#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 100

//gitSublime
typedef struct produto{
	int codigo;
	char nome[TAM];
	float preco;
}tp_produto;

typedef struct nodo{
	tp_produto produto;
	struct nodo *prox;
}tp_nodo;


void printLista(tp_nodo *ptNodo);
tp_nodo * insereElemento(tp_nodo *ptNodo);
void excluirElemento(tp_nodo *ptNodo, int buscaCodigo);
tp_nodo * apagaLista(tp_nodo *ptNodo);


void printLista(tp_nodo *ptNodo){
	if(ptNodo != NULL){
		printf("Codigo: %d\nNome: %sPreco: %.2f\n", 
				ptNodo->produto.codigo, ptNodo->produto.nome, ptNodo->produto.preco);
		printLista(ptNodo->prox);
	}
}

tp_produto entrada(){
	tp_produto preencheNodo;
	printf("Codigo: \n");
	scanf("%d", &preencheNodo.codigo);
	getchar();
	printf("Nome: \n");
	fgets(preencheNodo.nome, TAM, stdin);
	printf("Preco: \n");
	scanf("%f", &preencheNodo.preco);
	return preencheNodo;
}

tp_nodo * insereElemento(tp_nodo *ptNodo){
	tp_nodo *ultimo;
	tp_nodo *novoNodo;

	if(ptNodo == NULL){
		ptNodo = (tp_nodo*) malloc (sizeof(tp_nodo));
		ptNodo->produto = entrada();
		ptNodo->prox = NULL;
		return ptNodo;
	}
	else{
		for(tp_nodo *nome = ptNodo; nome != NULL; nome = nome->prox){
			ultimo = nome;
		}
		novoNodo = (tp_nodo*) malloc (sizeof(tp_nodo));
		novoNodo->produto = entrada();
		novoNodo->prox = NULL;
		ultimo->prox = novoNodo;
		return ptNodo;
	}
}

void excluirElemento(tp_nodo *ptNodo, int buscaCodigo){
	tp_nodo *f, *f1;
	f = ptNodo;
	f1 = ptNodo->prox;
	while(f1 != NULL && f1->produto.codigo != buscaCodigo){
		f = f1;
		f1 = f1->prox;
	}
	if(f1 != NULL){
		f->prox = f1->prox;
		free(f1);
	}
}

int main(){
	tp_nodo *ponteiroNodo = NULL;

	ponteiroNodo = insereElemento(ponteiroNodo);
	ponteiroNodo = insereElemento(ponteiroNodo);
	ponteiroNodo = insereElemento(ponteiroNodo);
	printLista(ponteiroNodo);
	excluirElemento(ponteiroNodo, 2);
	printf("\nDepois\n\n");
	printLista(ponteiroNodo);
	return 0;

}