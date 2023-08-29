#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
} Node;
Node* input(){
	Node* head;
	int input;
	printf("Enter the numbers : \n");
	Node** current=&head;
	while(scanf("%d",&input)){
		*current=(Node*)malloc(sizeof(Node));
		(*current)->data=input;
		current=&((*current)->link);
	}
	scanf("%*s");
	*current=NULL;
	return head;
}
void insert_after(Node* current,int value){
	Node* new=(Node*)malloc(sizeof(Node));
	new->data=value;
	new->link=current->link;
	current->link=new;
}
void delete_after(Node* current,int value){
	Node* remove=current->link;
	current->link=remove->link;
	free(remove);
}
Node* traverse(Node* current,unsigned int index,void(function)(Node*)){
	unsigned int i=0;
	for(;current!=NULL;current=current->link){
		if(i==index)
			return current;
		(*function)(current);
		i++;
	}
	return NULL;
}
void null_function(Node* n){}
void show_node(Node* n){
	printf("%d->",n->data);
}
int main(){
	Node* head=input();
	int value;
	unsigned int index;
	printf("Insert value : ");
	scanf("%d",&value);
	printf("at index : ");
	scanf("%d",&index);
	Node* at=traverse(head,index,null_function);
	if(at!=NULL){
		insert_after(at,value);
		traverse(head,-1,show_node);printf("END\n");//display
	}
	else printf("Node unavailable");
	printf("Delete at index : ");
	scanf("%d",&index);
	if((at=traverse(head,index-1,null_function))!=NULL){
		delete_after(at,value);
		traverse(head,-1,show_node);printf("END\n");//display
	}
	else printf("Node unavailable");
	return 0;
}
