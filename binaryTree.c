#include<stdio.h>
#include<stdlib.h>
/*
Criar funcao que delete um nodo;
Criar funcao que imprima em Pre-Order;
Criar funcao que imprima em Post-Order;
*/

typedef struct BinaryTree {
    int key;
    struct BinaryTree *left;
    struct BinaryTree *right;
} NO;

NO * deleteNode(NO *root, int key);
NO * minTreeValue(NO *root);
void preOrder(NO *root);
void postOrder(NO *root);

// Uma função para criar um novo nó na Árvore de Busca Binária 
NO *newNode(int item) {
    NO *temp =  (NO *)malloc(sizeof(NO));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Uma função para fazer o percurso inOrder na Árvore de Busca Binária
void inOrder(NO *root) {
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Uma função para inserir um novo nó com uma dada chave (key) na Árvore de Busca Binária
NO *insert(NO *no, int key) {
    // Se a árvore estiver vazia, retorne um novo nó
    if (no == NULL) return newNode(key);

    // Caso contrário, volte pela árvore 
    if (key < no->key)
        no->left  = insert(no->left, key);
    else if (key > no->key)
        no->right = insert(no->right, key);

    // retorna o ponteiro do nó (inalterado)
    return no;
}

// Teste das funções
void main(void)
{
    /* Criar a seguinte Árvore de Busca Binária
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */

    NO *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("\nÁrvore de Busca Binária: Inserção e Percurso;\n\n");
    printf("\nValores inseridos: 50, 30, 20, 40, 70, 60 e 80.\n\n");

    // Imprimir o percurso inOrder da Árvore de Busca Binária
    printf("\nPercurso Em Ordem: ");
    inOrder(root);
    printf("\nPRE-ORDER: \n");
    preOrder(root);
    printf("\nPOST-ORDER: \n");
    postOrder(root);
    printf("\n");
    while(1){
        int key;
        printf("type key to delete\n");
        scanf("%d", &key);
        root = deleteNode(root, key);
        inOrder(root);
        if(!root) break;
    }
}
NO * deleteNode(NO * root, int key){
    //If tree's empty
    if(root == NULL) return root;
    //If key's value is lower than tree's root
    if(key < root->key) root->left = deleteNode(root->left, key);
    //If key's value is bigger than tree's root
    else if(key > root->key) root->right = deleteNode(root->right, key);
    //If key's same as root's key, delete actual root
    else{
        //Node with a single child or none
        if(root->left == NULL){
            NO *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            NO *temp = root->left;
            free(root);
            return temp;
        }
        //Node with two children: (take inOrder sucessor (smallest in the right subtree))
        NO *temp = minTreeValue(root->right);
        //Transfer inOrder successor's content to current root
        root->key = temp->key;
        //Delete inOrder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
NO * minTreeValue(NO *given){
    NO * current = given;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}
void postOrder(NO *root){
    if(root != NULL){
        postOrder(root->left); //traverse till has a leaf on the left edge
        postOrder(root->right); //traverse when left recursion has come to an end
        printf("%d ", root->key); //print current node
    }
}

void preOrder(NO *root){
    if(root != NULL){
        printf("%d ", root->key); //print current node and head first, since it's pre order 
        preOrder(root->left); //traverse to the left node till finds a leaf
        preOrder(root->right); //traverse when left recursion has come to an end
    }
}