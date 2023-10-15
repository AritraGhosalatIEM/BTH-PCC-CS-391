#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;
void insert(Node** current,int value){
	if(*current==NULL){
		*current=(Node*)malloc(sizeof(Node));
		(*current)->left=(*current)->right=NULL;
		(*current)->data=value;
	}
	else if(value<(*current)->data)
		insert(&((*current)->left),value);
	else if(value>(*current)->data)
		insert(&((*current)->right),value);
}
void print(Node* current,unsigned int spacing){
	if(current==NULL)return;
	unsigned int new_spacing=spacing+1+(int)log10(abs(current->data))+(current->data<0);
	print(current->left,new_spacing);
	for(unsigned int i=0;i<spacing;i++)printf(" ");
	printf("%d\n",current->data);
	print(current->right,new_spacing);
}
int main(){
	printf("Enter integers one after the other and enter string when done: \n");
	Node* head=NULL;
	int u;
	while(scanf("%d",&u))insert(&head,u);
	print(head,0);
}
