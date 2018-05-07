#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

typedef struct data{
	int info;
}data;

typedef struct node{
	data realData;
	struct node *next;
}node;

node *headRef;

void push(node **headRef);
void pop(node **headRef, int rmNode);
void display(node *headRef);
//End HEADERS

int main(){
	headRef = NULL;
	int out = 1;
	while(out != 0){
		printf("\n(1) push\n(2) pop\n(3) display\n(0) exit\n");
		int opt;
		scanf("%d", &opt);
		switch(opt){
			case 1:{
				push(&headRef);
				break;
			}
			case 2:{
				if(headRef == NULL){
					printf("\t\tLista Vazia\n\n"); 
					break;
				}
				printf("Digite o codigo que deseja excluir\n");
				int rmNode;
				scanf("%d", &rmNode);
				pop(&headRef, rmNode);
				break;
			}
			case 3:{
				display(headRef);
				break;
			}
			case 0:{
				out = 0;
				break;
			}
			default:{
				printf("Again\n");
				break;
			}
		}
	}
}

data fillData(){
	data data;
	printf("Digite o codigo:\n");
	scanf("%d", &data.info);
	return data;
}

void push(node **headRef){
	node *temp = *headRef;
	node *newNode = (node*) malloc (sizeof(node));
	newNode->realData = fillData();
	newNode->next = *headRef;
	if(*headRef != NULL){
		while(temp->next != *headRef){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	else{
		newNode->next = newNode;
	}
	*headRef = newNode;
}

void pop(node **headRef, int rmNode){
	node *temp = *headRef;
	node *aux = NULL;
	while(temp->realData.info != rmNode && temp->next != *headRef){
		aux = temp;
		temp = temp->next;
	}
	if(temp == *headRef && temp->next == *headRef){
		free(*headRef);
		*headRef = NULL;
		return;
	}
	if(temp == *headRef){
		*headRef = temp->next;
	}
	/*if(temp == *headRef){
		*headRef = temp->next;
	}*/
	else{
		aux->next = temp->next;
	}
	free(temp);
}

void display(node *headRef){
	node *temp = headRef;
	if(headRef != NULL){
		do{
			printf("\t\tCodigo: %d\n", temp->realData.info);
			temp = temp->next;
		}while(temp != headRef);
	}
	else{
		printf("\t\tLista Vazia\n");
	}
}