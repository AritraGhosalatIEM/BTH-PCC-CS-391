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
	Node* remove;
	char c;unsigned int p;Node* new;
	for(unsigned int i;i<len;i++){
		c=argv[1][i];
		if(isalpha(c)){
			printf("%c",c);
		}
		else if(isblank(c))continue;
		else if(c==')'){
			while(top->op!='('){
				remove=top;
				printf("%c",top->op);
				top=top->next;
				free(remove);
			}
			new=top;
			top=new->next;
			free(new);
		}
		else{
			while(top->op!='(' && precedence(c)<=precedence(top->op)){
				remove=top;
				printf("%c",top->op);
				top=top->next;
				free(remove);
			}
			new=(Node*)malloc(sizeof(Node));
			new->op=c;
			new->next=top;
			top=new;
		}
	}
	while(top->op!='('){
		printf("%c",top->op);
		top=top->next;
	}
	printf("\n");
	return 0;
}
