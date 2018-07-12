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
void insertionSort(node **headRef);
void auxInsert(node **headRef, node *newNode);
node * selectionSort(node *headRef);
void auxSelection(node **headRef, node *current, node *min, node *beforeMin);
node *merge(node *first, node *second);
node *split(node *head);
node *mergeSort(node *head);
node * deleteNode(node *delNode, list *setList);
int checkList(node *checkNode);
void printList(node *fwdList);
//Fim dos Headers

int main(){
	node *pointerNode = NULL;
	list *pointerList = (list*)malloc(sizeof(list));
	int control = 1, opt;
	while(control!=0){
		printf("\n\n(1) para inserir produto na lista\n(2) Para excluir um elemento da lista\n(3) Para listar elementos\n(4) Insertion Sort\n(5) Selection Sort\n(6) Merge Sort\n\t(0) para sair do programa\n");
		scanf("%d", &opt);
		switch(opt){
			case 1:{
				pointerNode = push(pointerNode, pointerList);
				break;
			}
			case 2:{
				pointerNode = deleteNode(pointerNode, pointerList);
				break;
			}
			case 3:{
				if(checkList(pointerNode)){
					printf("\t\tLista Vazia\n\n");
				}
				else{
					node *aux = pointerNode;
					while(aux != NULL){
						if(aux->prev == NULL) pointerList->first = aux;
						if(aux->next == NULL) pointerList->last = aux;
						aux = aux->next;
					}
					printf("Elemento cabeca (codigo): %d\nElemento cauda (codigo): %d\nQtd elementos: %d\n", pointerList->first->produto.codigo, pointerList->last->produto.codigo, pointerList->nItens);
					printList(pointerNode);
				}
				break;
			}
			case 4:{
				insertionSort(&pointerNode);
				break;
			}
			case 5:{
				pointerNode = selectionSort(pointerNode);
				break;
			}
			case 6:{
				pointerNode = mergeSort(pointerNode);
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
	free(pointerNode);
	free(pointerList);
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
void insertionSort(node **headRef){
	node *sorted = NULL; //Nova lista que recebera os nodos de forma ordenada
	//itera pela lista recebida 
	//e insere em sorted;
	
	node *current = *headRef;
	while(current != NULL){
		//guarda nodo seguinte para proxima iteracao
		node *next = current->next;
		//remove todos os ponteiros
		//e cria um novo nodo(current) para insercao
		current->prev = current->next = NULL;
		//insere current dentro da lista ordenada(sorted)
		auxInsert(&sorted, current);
		current = next;
	}
	*headRef = sorted;
}
void auxInsert(node **headRef, node *newNode){
	node *current;
	//se a lista ordenada estiver vazia;
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
node * selectionSort(node *headRef){
    if (headRef->next == NULL)	return headRef;
    node * min = headRef;
    node * beforeMin = NULL;
    node * aux;
    for(aux = headRef; aux->next != NULL; aux = aux->next){
	   	if (aux->next->produto.codigo < min->produto.codigo){
	       min = aux->next;
	       beforeMin = aux;
	    }
	}
    if(min != headRef)	auxSelection(&headRef, headRef, min, beforeMin);
    headRef->next = selectionSort(headRef->next);
    return headRef;
}
void auxSelection(node **headRef, node *current, node *min, node *beforeMin){
	//nova cabeca
    *headRef = min;
    //reajusta ponteiros
    beforeMin->next = current;
    node *temp = min->next;
    min->next = current->next;
    min->next->prev = min;
    current->next = temp;
}
node *merge(node *first, node *second){
    // se a primeira lista estiver vazia
    if (first == NULL) return second;
    // se a segunda lista estiver vazia
    if (second == NULL) return first;
    // busca o menor valor
    if (first->produto.codigo < second->produto.codigo){
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else{
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}
node *mergeSort(node *head){
    if (head == NULL || head->next == NULL) return head;
    node *second = split(head);
    // Recursao para metades esquerda e direita
    head = mergeSort(head);
    second = mergeSort(second);
    // merge nas duas metades;
    return merge(head,second);
}
node *split(node *head){
    node *fast = head,*slow = head;
    while (fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    node *temp = slow->next;
    slow->next = NULL;
    return temp;
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