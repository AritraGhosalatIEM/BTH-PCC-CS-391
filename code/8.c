#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node{
	char op;
	struct node* next;
} Node;
unsigned int precedence(char operator){
	switch(operator){
		case '-':
		case '+':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '(':
			return 3;
	}
	return 0;
}
int main(int argc,char** argv){
	unsigned int len=strlen(argv[1]);
	Node* top=(Node*)malloc(sizeof(Node));
	top->next=NULL;
	top->op='(';
	Node* expression;
	Node **tail=&expression;
	char c;unsigned int p;Node* new;
	for(unsigned int i;i<len;i++){
		c=argv[1][i];
		if(isalpha(c)){
			*tail=(Node*)malloc(sizeof(Node));
			(*tail)->op=c;
			(*tail)->next=NULL;
			tail=&((*tail)->next);
		}
		else if(isblank(c))continue;
		else if(c==')'){
			while(top->op!='('){
				*tail=top;
				top=top->next;
				(*tail)->next=NULL;
				tail=&((*tail)->next);
			}
			new=top;
			top=new->next;
			free(new);
		}
		else{
			while(top->op!='(' && precedence(c)<=precedence(top->op)){
				*tail=top;
				top=top->next;
				(*tail)->next=NULL;
				tail=&((*tail)->next);
			}
			new=(Node*)malloc(sizeof(Node));
			new->op=c;
			new->next=top;
			top=new;
		}
	}
	while(top->op!='('){
		*tail=top;
		top=top->next;
		(*tail)->next=NULL;
		tail=&((*tail)->next);
	}
	for(;expression!=NULL;expression=expression->next)
		printf("%c",expression->op);
	printf("\n");
	return 0;
}
