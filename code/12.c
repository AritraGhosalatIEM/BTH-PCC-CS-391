#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	unsigned int data;
	struct node* after;
} Node;
Node *head,*tail;
void enqueue(int value){
	tail->data=value;
	Node* new=(Node*)malloc(sizeof(Node));
	tail->after=new;
	tail=new;
}
unsigned int dequeue(){
	Node* remove=head;
	unsigned int ret=remove->data;
	head=remove->after;
	free(remove);
	return ret;
}
int main(){
	//input
	unsigned int N;
	printf("Number of nodes: ");
	scanf("%d%*c",&N);
	char name[N];
	bool graph[N][N];//adjacency matrix
	printf("Graph :\n  ");
	for(unsigned int i=0;i<N;i++)
		scanf("%c",&name[i]);
	scanf("%*c");//ignoring newline
	for(unsigned int i=0;i<N;i++){
		printf("%c ",name[i]);
		for(unsigned int j=0;j<N;j++)
			graph[i][j]=getc(stdin)=='t' && i!=j;//disregarding self loop
		scanf("%*c");//ignoring newline
	}
	//BFS
	unsigned int parent[N];
	head=(Node*)malloc(sizeof(Node));
	tail=head;
	find:for(;;){
		for(unsigned int i=0;i<N;i++)parent[i]=i;//re-initialize graph
		char start,end;
		printf("\nStart Node: ");
		scanf("%c%*c",&start);
		printf("\nEnd Node: ");
		scanf("%c%*c",&end);
		unsigned int stop=0;
		for(;name[stop]!=end && stop<N;stop++);//linear search
		unsigned int current;
		for(current=stop;name[current]!=start;current=dequeue()){
			for(unsigned int i=0;i<N;i++)
				if(graph[i][current] && parent[i]==i){
					parent[i]=current;
					enqueue(i);
				}
			if(head==tail){
				printf("No path between %c and %c.\n",start,end);
				goto find;
			}
		}
		for(;current!=stop;current=parent[current])printf("%c->",name[current]);
		printf("%c.\n",end);
	}
	return 0;
}
