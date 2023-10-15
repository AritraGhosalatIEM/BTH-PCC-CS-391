#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
unsigned int dfs(unsigned int size,char name[],bool** graph,unsigned int parent[],char stop,unsigned int current){
	if(name[current]==stop)return current;
	unsigned int ret=0;
	for(unsigned int i=0;i<size;i++)
		if(graph[i][current] && parent[i]==i){
			parent[i]=current;
			ret+=dfs(size,name,graph,parent,stop,i);
		}
	return ret;
}
int main(){
	//input
	unsigned int N;
	printf("Number of nodes: ");
	scanf("%d%*c",&N);
	char name[N];
	bool** graph=(bool**)malloc(N*sizeof(bool*));//adjacency matrix
	printf("Graph :\n  ");
	for(unsigned int i=0;i<N;i++)
		scanf("%c",&name[i]);
	scanf("%*c");//ignoring newline
	for(unsigned int i=0;i<N;i++){
		printf("%c ",name[i]);
		graph[i]=(bool*)malloc(N*sizeof(bool));
		for(unsigned int j=0;j<N;j++)
			graph[i][j]=getc(stdin)=='t' && i!=j;//disregarding self loop
		scanf("%*c");//ignoring newline
	}
	//DFS
	unsigned int parent[N];
	for(;;){
		for(unsigned int i=0;i<N;i++)parent[i]=i;//re-initialize graph
		char start,end;
		printf("\nStart Node: ");
		scanf("%c%*c",&start);
		printf("\nEnd Node: ");
		scanf("%c%*c",&end);
		unsigned int stop=0;
		for(;name[stop]!=end && stop<N;stop++);//linear search
		unsigned int begin=dfs(N,name,graph,parent,start,stop);
		for(;begin!=stop;begin=parent[begin])printf("%c->",name[begin]);
		printf("%c.\n",end);
	}
	return 0;
}
