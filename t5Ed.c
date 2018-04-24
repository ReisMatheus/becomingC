#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 20
//sublimetxt
typedef struct produto{
	int codigo;
	char nome[TAM];
	float preco;
}produto;

typedef struct node{
	produto produto;
	struct node *next;
	struct node *prev;
}node;

typedef struct lista{
	int nItens;
	node *first;
	node *last;
}list;

produto fillNode();
node * insertAtTail(node *tailNode, list *setList);
node * insertAtHead(node *headNode, list *setList);
node * deleteNode(node *delNode, list *setList);
int checkList(node *checkNode);
void printListFoward(node *fwdList);
void printListBackwards(node *bkwList);
//Fim dos Headers

int main(){
	node *pointerNode = NULL;
	list *pointerList = (list*)malloc(sizeof(list));
	int control = 1, opt;
	while(control!=0){
		printf("\n\n(1) para inserir produto na cauda da lista\n(2) para inserir produto na cabeca da lista\n(3) Para excluir um elemento da lista\n(4) Para listar elementos\n(5) Para listar elementos inversamente\n\t(0) para sair do programa\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:{
				pointerNode = insertAtTail(pointerNode, pointerList);
				break;
			}
			case 2:{
				pointerNode = insertAtHead(pointerNode, pointerList);
				break;
			}
			case 3:{
				pointerNode = deleteNode(pointerNode, pointerList);
				break;
			}
			case 4:{
				if(checkList(pointerNode)){
					printf("\t\tLista Vazia\n\n");
				}
				else{
					printf("Elemento cabeca (codigo): %d\nElemento cauda (codigo): %d\nQtd elementos: %d\n", pointerList->first->produto.codigo, pointerList->last->produto.codigo, pointerList->nItens);
					printListFoward(pointerNode);
				}
				break;
			}
			case 5:{
				if(checkList(pointerNode)){
					printf("\t\tLista vazia\n\n");
				}
				else{
					printf("Elemento cabeca (codigo): %d\nElemento cauda (codigo): %d\nQtd elementos: %d\n", pointerList->first->produto.codigo, pointerList->last->produto.codigo, pointerList->nItens);
					printListBackwards(pointerNode);
				}
				break;
			}
			case 0:{
				control = 0;
				break;
			}
			default:{
				printf("Opcao Invalida\n\n");
			}
		}
	}
	return 0;
}
//Implementacao das Funcoes
produto fillNode(){
	produto preencheNodo;
	printf("Codigo: \n");
	scanf("%d", &preencheNodo.codigo);
	getchar();
	printf("Nome: \n");
	fgets(preencheNodo.nome, TAM, stdin);
	printf("Preco: \n");
	scanf("%f", &preencheNodo.preco);
	return preencheNodo;
}

node * insertAtTail(node *tailNode, list *setList){
	node *temp = tailNode;
	node *newNode = (node*)malloc(sizeof(node));
	newNode->produto = fillNode();
	newNode->next = NULL;
	newNode->prev = tailNode;
	if(tailNode == NULL){
		tailNode = (node*)malloc(sizeof(node));//Aloca Nodo, pois o mesmo eh NULL
		tailNode = newNode;
		tailNode->next = NULL;
		setList->last = tailNode;
		setList->first = tailNode;
		setList->nItens = 0;
		setList->nItens++;
		return tailNode;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	setList->last = newNode;
	setList->nItens++;
	return tailNode;
}

node * insertAtHead(node *headNode, list *setList){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->produto = fillNode();
	newNode->next = headNode;
	newNode->prev = NULL;
	if(headNode == NULL){
		headNode = (node*)malloc(sizeof(node));//Aloca Nodo, pois o mesmo eh NULL
		headNode = newNode;
		headNode->prev = NULL;
		setList->first = newNode;
		setList->last = newNode;
		setList->nItens = 0;
		setList->nItens++;
		return headNode;
	}
	headNode->prev = newNode;
	newNode->next = headNode;
	setList->first = newNode;
	setList->nItens++;
	return newNode;
}

node * deleteNode(node *delNode, list *setList){
	if(checkList(delNode)){
		printf("\t\tLista vazia\n\n");
		return delNode;
	}
	node *realNode = NULL, *tempNode = delNode;
	int codNode;
	printf("Digite o codigo do produto que deseja excluir\n");
	scanf("%d", &codNode);
	while(tempNode != NULL && tempNode->produto.codigo != codNode){
		realNode = tempNode;
		tempNode = tempNode->next;
	}
	if(tempNode == NULL){
		printf("Produto nao encontrado\n");
		return delNode;
	}
	if(realNode == NULL){
		delNode = tempNode->next;
		setList->first = delNode;
		printf("Produto excluido com sucesso\n");
	}
	else{
		realNode->next = tempNode->next;
		printf("Produto excluido com sucesso\n");	
	}
	free(tempNode);
	setList->nItens--;
	return delNode;
}

int checkList(node *checkNode){
	if(checkNode == NULL){
		return 1;
	} 
	else{
		return 0;
	}
}

void printListFoward(node *fwdList){
	if(fwdList != NULL){
		printf("Codigo: %d\nNome: %sPreco: %.2f\n", 
					fwdList->produto.codigo, fwdList->produto.nome, fwdList->produto.preco);
		printListFoward(fwdList->next);
	}
}

void printListBackwards(node *bkwList){
	node *aux = bkwList;
	while(aux->next != NULL){
		aux = aux->next;
	}
	while(aux != NULL){
		printf("Codigo: %d\nNome: %sPreco: %.2f\n", 
					aux->produto.codigo, aux->produto.nome, aux->produto.preco);
		aux = aux->prev;	
	}
}
//Fim da implementacao das funcoes