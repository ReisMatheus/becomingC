#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 20
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
int setUpList(node *checkNode);
void printList(node *displayList);
//Fim dos Headers

int main(){
	node *pointerNode = NULL;
	list *pointerList = NULL;
	int control = 1, opt;
	while(control!=0){
		printf("(1) para inserir produto na cauda da lista\n(2) para inserir produto na cabeca da lista\n(3) Para excluir um elemento da lista\n(4) Para listar todos os elementos da lista\n(0) para sair do programa\n");
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
				if(pointerNode == NULL){
					printf("Lista Vazia\n");
				}
				else{
					printList(pointerNode);
				}
				break;
			}
			case 0:{
				control = 0;
				break;
			}
			default:{
				printf("Opcao Invalida\n");
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
	if(tailNode != NULL){
		tailNode->next = newNode;
		setList->last = newNode;
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
	return newNode;
}

node * insertAtHead(node *headNode, list *setList){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->produto = fillNode();
	newNode->next = headNode;
	newNode->prev = NULL;
	if(headNode != NULL){
		headNode->prev = headNode;
		setList->first = newNode;
		return newNode;
	}
	return newNode;
}

node * deleteNode(node *delNode, list *setList){
	if(setUpList(delNode)){
		printf("Lista vazia\n");
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
		printf("Produto excluido com sucesso\n");
	}
	else{
		realNode->next = tempNode->next;
		printf("Produto excluido com sucesso\n");	
	}
	free(tempNode);
	return delNode;
}

int setUpList(node *checkNode){
	if(checkNode == NULL){
		return 1;
	} 
	else{
		return 0;
	}
}

void printList(node *displayList){
	while(displayList != NULL){
		printf("Codigo: %d\nNome: %s\nPreco: %.2f\n", 
					displayList->produto.codigo, displayList->produto.nome, displayList->produto.preco);
		printList(displayList->next);
	}
}
//Fim da implementacao das funcoes