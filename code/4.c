#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct matrix{
	int** elements;
	unsigned int m,n;
} Matrix;
Matrix transpose(Matrix in){
	Matrix t;
	t.m=in.n;
	t.n=in.m;
	t.elements=(int**)malloc(t.m*sizeof(int*));
	for(unsigned int i=0;i<in.m;i++){
		t.elements[i]=(int*)malloc(t.n*sizeof(int));
		for(unsigned int j=0;j<in.n;j++)
			t.elements[i][j]=in.elements[j][i];
	}
	return t;
}
Matrix add(Matrix a,Matrix b){
	Matrix sum;
	if(a.m!=b.m || b.m!=b.n){
		sum.elements=NULL;
		return sum;
	}
	sum.m=a.m;sum.n=a.n;
	sum.elements=(int**)malloc(sum.m*sizeof(int));
	for(unsigned int i=0;i<sum.m;i++){
		sum.elements[i]=(int*)malloc(sum.n*sizeof(int));
		for(unsigned int j=0;j<sum.n;j++)
			sum.elements[i][j]=a.elements[i][j]+b.elements[i][j];
	}
	return sum;
}
Matrix multiply(Matrix a,Matrix b){
	Matrix product;
	if(a.n!=b.m){
		product.elements=NULL;
		return product;
	}
	product.m=a.m;product.n=a.n;
	product.elements=(int**)malloc(product.m*sizeof(int));
	for(unsigned int i=0;i<product.m;i++){
		product.elements[i]=(int*)malloc(product.n*sizeof(int));
		for(unsigned int j=0;j<product.n;j++){
			product.elements[i][j]=0;
			for(unsigned int k=0;k<a.n;k++)
				product.elements[i][j]+=a.elements[i][k]*b.elements[k][j];
		}
	}
	return product;
}
Matrix input(char name){
	Matrix a;
	printf("Enter the dimensions of a matrix :");
	scanf("%dx%d",&a.m,&a.n);
	printf("%c = ",name);
	a.elements=(int**)malloc(a.m*sizeof(int*));
	for(unsigned int i=0;i<a.m;i++){
		a.elements[i]=(int*)malloc(a.n*sizeof(int));
		for(unsigned int j=0;j<a.n;j++)
			scanf("%d,",&a.elements[i][j]);
		printf("    ");
	}
	printf("\n");
	return a;
}
void print(Matrix a,const char* name){
	if(a.elements==NULL){
		printf("INVALID\n");
		return;
	}
	int l=strlen(name)+3;
	printf("%s = ",name);
	for(unsigned int i=0;i<a.m;i++){
		printf("%d",a.elements[i][0]);
		for(unsigned int j=1;j<a.n;j++)
			printf(",%d",a.elements[i][j]);
		printf("\n");
		for(unsigned int j=0;j<l;j++)
			printf(" ");
	}
	printf("\n");
}
int main(){
	Matrix a=input('A'),b=input('B');
	print(transpose(a),"Aᵗ");
	print(add(a,b),"A+B");
	print(multiply(a,b),"AxB");
	return 0;
}
