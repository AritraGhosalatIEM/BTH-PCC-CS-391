#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node* after;
	struct node* before;
} Node;
Node *head,*tail;
void enqueue(int value){
	Node* new=(Node*)malloc(sizeof(Node));
	new->data=value;
	if(head==NULL)head=new;
	else tail->after=new;
	new->before=tail;
	new->after=NULL;
	tail=new;
}
typedef struct resp{
	int data;
	bool underflow;
} Response;
Response dequeue(){
	Response ret;
	if(head==NULL){
		ret.underflow=true;
		return ret;
	}
	ret.underflow=false;
	Node* remove=head;
	ret.data=remove->data;
	head=remove->after;
	if(head!=NULL)
		head->before=NULL;
	free(remove);
	return ret;
}
int main(){
	head=tail=NULL;
	Response deq;
	int value;
	puts("Enter integer values to add to queue and enter any string to remove from queue");
	for(;;){
		while(scanf("%d",&value))enqueue(value);
		scanf("%*s");
		if((deq=dequeue()).underflow)
			printf("No items in queue.\n");
		else
			printf("Dequeued : %d\n",deq.data);
	}
	return 0;
}