#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void display(int arr[],unsigned int len){
	printf("%d",arr[0]);
	for(unsigned int i=1;i<len;i++)
		printf(",%d",arr[i]);
	printf("\n");
}
void bubblesort(int arr[],unsigned int len){
	bool sorted=false;
	int t;
	do{
		sorted=true;
		for(unsigned int i=1;i<len;i++){
			if(arr[i]<(t=arr[i-1])){
				sorted=false;
				arr[i-1]=arr[i];
				arr[i]=t;
			}
		}
	}while(!sorted);
}
void selectionsort(int arr[],unsigned int len){
	int min;unsigned int min_index;
	for(unsigned int i=0;i<len;i++){
		min=arr[i];
		min_index=i;
		for(unsigned int j=i;j<len;j++)
			if(arr[j]<min){
				min_index=j;
				min=arr[j];
			}
		arr[min_index]=arr[i];
		arr[i]=min;
	}
}
void insertionsort(int arr[],unsigned int len){
	int e;int j;
	for(unsigned int i=1;i<len;i++){
		e=arr[i];
		for(j=i-1;j>=0;j--){
			if(arr[j]<e)
				break;
			arr[j+1]=arr[j];
		}
		arr[j+1]=e;
	}
}
int main(){
	unsigned int len;
	printf("Enter number of elements (positive integer) : ");
	scanf("%d",&len);
	int arr[len];
	printf("Enter of elements (integer - comma separated) : ");
	for(unsigned int i=0;i<len;i++)
		scanf("%d,",&arr[i]);
	int sorted[len];
	printf("Bubble Sort: ");
	memcpy(sorted,arr,len*sizeof(int));
	bubblesort(sorted,len);
	display(sorted,len);
	printf("Selection Sort: ");
	memcpy(sorted,arr,len*sizeof(int));
	selectionsort(sorted,len);
	display(sorted,len);
	printf("Insertion Sort: ");
	memcpy(sorted,arr,len*sizeof(int));
	insertionsort(sorted,len);
	display(sorted,len);
	return 0;
}
