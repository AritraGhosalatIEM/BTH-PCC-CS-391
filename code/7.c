#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 10
typedef struct node{
	int data;
	struct node* below;
} Node;
typedef struct resp{
	int data;
	bool error;
} Response;
int top;
int arr[MAX];
Node* head;
bool push_arr(int value){
	if(top+1==MAX)
		return 0;
	arr[++top]=value;
	return 1;
}
bool push_list(int value){
	Node* new=(Node*)malloc(sizeof(Node));
	new->data=value;
	new->below=head;
	head=new;
	return 1;
}
Response pop_arr(){
	Response r;
	if(top==-1){
		r.error=1;
		return r;
	}
	r.error=0;
	r.data=arr[top--];
	return r;
}
Response pop_list(){
	Response r;
	if(head==NULL){
		r.error=1;
		return r;
	}
	r.error=0;
	r.data=head->data;
	Node* remove=head;
	head=remove->below;
	free(remove);
	return r;
}
int main(){
	top=-1;
	head=NULL;
	bool(*push)(int);Response(*pop)(void);
	printf("Enter 'a' to use an array or 'l' to use a list.\n");
	char c=getchar();
	if(c=='a'){
		printf("Array!\n");
		push=&push_arr;
		pop=&pop_arr;
	}
	else if(c=='l'){
		printf("List!\n");
		push=&push_list;
		pop=&pop_list;
	}
	else
		return 1;
	int value;
	Response resp;
	for(;;){
		while(scanf("%d",&value))
			if(!push(value))
				printf("Stack overflow.\n");
		scanf("%*s");
		if((resp=pop()).error)
			printf("Stack underflow");
		else
			printf("Popped : %d.\n",resp.data);
	}
	return 0;
}
