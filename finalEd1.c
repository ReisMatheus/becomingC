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
node * push(node *headNode, list *setList);
void insertionSort(node **headRef, list *setList);
void auxInsert(node **headRef, node *newNode);
void selectionSort(node **headRef, list *setList);
node * deleteNode(node *delNode, list *setList);
int checkList(node *checkNode);
void printList(node *fwdList);
//Fim dos Headers

int main(){
	node *pointerNode = NULL;
	list *pointerList = (list*)malloc(sizeof(list));
	int control = 1, opt;
	while(control!=0){
		printf("\n\n(2) para inserir produto na lista\n(3) Para excluir um elemento da lista\n(4) Para listar elementos\n(6) Insertion Sort\n(7) Selection Sort\n(8) Merge Sort\n\t(0) para sair do programa\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:{
				//pointerNode = insertAtTail(pointerNode, pointerList);
				break;
			}
			case 2:{
				pointerNode = push(pointerNode, pointerList);
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
					printList(pointerNode);
				}
				break;
			}
			case 5:{
				/*if(checkList(pointerNode)){
					printf("\t\tLista Vazia\n\n");
				}
				else{
					printf("Elemento cabeca (codigo): %d\nElemento cauda (codigo): %d\nQtd elementos: %d\n", pointerList->first->produto.codigo, pointerList->last->produto.codigo, pointerList->nItens);
					printListBackwards(pointerNode);
				}*/
				break;
			}
			case 6:{
				insertionSort(&pointerNode, pointerList);
				break;
			}
			case 7:{
				selectionSort(&pointerNode, pointerList);
				break;
			}
			case 8:{
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
void insertionSort(node **headRef, list *setList){
	node *sorted = NULL; //Nova lista que recebe os nodos de forma sortida
	/*itera pela lista recebida 
	e insere em sorted;
	*/
	printf("size headRef %lo\n", sizeof(headRef));
	node *current = *headRef;
	while(current != NULL){
		//guarda proximo para proxima iteracao
		node *next = current->next;
		/*remove todos os ponteiros
		e cria um 'current' como novo nodo para insercao
		*/
		current->prev = current->next = NULL;
		//insere current dentro da lista sortida (sorted)
		auxInsert(&sorted, current);
		//update current
		current = next;
	}
	//update cabeca da lista para lista sortida
	*headRef = sorted;
}
void auxInsert(node **headRef, node *newNode){
	node *current;
	//se a lista estiver vazia;
	if(*headRef == NULL){
		*headRef = newNode;
	}
	//se o nodo a ser inserido for primeiro da lista
	else if((*headRef)->produto.codigo >= newNode->produto.codigo){
		newNode->next = *headRef;
		newNode->next->prev = newNode;
		*headRef = newNode;
	}
	else{
		current = *headRef;
		//localiza o nodo a frente do novo nodo que sera inserido
		while(current->next != NULL && current->next->produto.codigo < newNode->produto.codigo){
			current = current->next;
		}
		newNode->next = current->next;
		//se o novo nodo nao for inserido no fim da lista
		if(current->next != NULL){
			newNode->next->prev = newNode;
		}
		current->next = newNode;
		current->prev = current;
	}
}
void selectionSort(node **headRef, list *setList){
	int i, j;
	node *sorted = NULL;
	node *temp = *headRef;
	for(i = 0; i < setList->nItens - 1; i++){
		int min = i;
		for(j = i+1; j < setList->nItens; j++){
			if(*(temp+i)->produto.codigo < *(temp+min)->produto.codigo){
				min = j;
			}
		}
		if(min != i){
			sorted = temp;
			temp = *(headRef+i);
			*(headRef+i) = *(headRef+min);
			*(headRef+min) = temp;
			*headRef = sorted;
		}
	}
}
node * push(node *headNode, list *setList){
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
	//Deleta primeiro elemento
	if(realNode == NULL){
		if(tempNode->next == NULL){
			free(delNode);
			printf("Produto excluido com sucesso\n");
			return NULL;
		}
		delNode = tempNode->next;
		delNode->prev = NULL;
		setList->first = delNode;
		printf("Produto excluido com sucesso\n");
		free(tempNode);
		setList->nItens--;
		return delNode;
	}
	//Deleta ultimo elemento
	if(tempNode->next == NULL){
		realNode->next = NULL;
		setList->last = realNode;
		printf("Produto excluido com sucesso\n");
	}
	//Deleta elemento no meio da lista
	else{
		node *aux = tempNode->next;
		realNode->next = tempNode->next;
		aux->prev = realNode;
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
void printList(node *fwdList){
	if(fwdList != NULL){
		printf("Codigo: %d\nNome: %sPreco: %.2f\n", 
					fwdList->produto.codigo, fwdList->produto.nome, fwdList->produto.preco);
		printList(fwdList->next);
	}
}
//Fim da implementacao das funcoes