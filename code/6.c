#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node* after;
} Node;
Node *head,*tail;
void enqueue(int value){
	tail->data=value;
	Node* new=(Node*)malloc(sizeof(Node));
	tail->after=new;
	tail=new;
}
typedef struct resp{
	int data;
	bool underflow;
} Response;
Response dequeue(){
	Response ret;
	if(head==tail){
		ret.underflow=true;
		return ret;
	}
	ret.underflow=false;
	Node* remove=head;
	ret.data=remove->data;
	head=remove->after;
	free(remove);
	return ret;
}
int main(){
	head=(Node*)malloc(sizeof(Node));
	tail=head;
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
