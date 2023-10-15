#define MAX 100
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* right;
	struct node* left;
}Node;
Node* generate_tree(){
	if(rand()%2==0)//stop
		return NULL;
	Node* current=(Node*)malloc(sizeof(Node));
	current->data=rand()%MAX;
	current->left=generate_tree();
	current->right=generate_tree();
	return current;
}
void preorder(Node* current){
	if(current==NULL)
		return;
	printf("%d,",current->data);
	preorder(current->left);
	preorder(current->right);
}
void inorder(Node* current){
	if(current==NULL)
		return;
	inorder(current->left);
	printf("%d,",current->data);
	inorder(current->right);
}
void postorder(Node* current){
	if(current==NULL)
		return;
	postorder(current->left);
	postorder(current->right);
	printf("%d,",current->data);
}
int main(){
	Node* head=generate_tree();
	printf("Preorder:\n");
	preorder(head);
	printf("\nInorder:\n");
	inorder(head);
	printf("\nPostorder:\n");
	postorder(head);
	printf("\n");
	return 0;
}
