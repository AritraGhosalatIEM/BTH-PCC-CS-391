#include<stdio.h>
#include<string.h>
void display(int arr[],unsigned int len){
	printf("%d",arr[0]);
	for(unsigned int i=1;i<len;i++)
		printf(",%d",arr[i]);
	printf("\n");
}
void mergesort(int arr[],unsigned int len){
	if(len==1)
		return;
	unsigned int mid=len/2;
	unsigned int rest=len-mid;
	int left[mid],right[rest];
	memcpy(left,arr,mid*sizeof(int));
	memcpy(right,&arr[mid],rest*sizeof(int));
	mergesort(left,mid);mergesort(right,rest);
	unsigned int i=0,j=0,k=0;
	for(;i<mid && j<rest;k++)
		if(left[i]<right[j])
			arr[k]=left[i++];
		else
			arr[k]=right[j++];
	for(;j<rest;j++)
		arr[k++]=right[j];
	for(;i<mid;i++)
		arr[k++]=left[i];
}
void quicksort(int arr[],unsigned int begin,unsigned int len){
	if(begin==len)return;
	unsigned int from_left=begin,from_right;
	int pivot=arr[from_right=len-1],t;
	while(from_left<from_right){
		for(;arr[from_left]<=pivot && from_left<from_right;from_left++);
		for(;arr[from_right]>pivot && from_left<from_right;from_right--);
		t=arr[from_left];
		arr[from_left]=arr[from_right];
		arr[from_right]=t;
	}
	quicksort(arr,begin,from_right);
	quicksort(arr,from_right+1,len);
}
int main(){
	unsigned int len;
	printf("Enter the number of elements (positive integer) : ");
	scanf("%d",&len);
	int arr[len];
	printf("Enter the elements (integer - comma separated) : ");
	for(unsigned int i=0;i<len;i++)
		scanf("%d,",&arr[i]);
	int sorted[len];
	printf("Merge Sort: ");
	memcpy(sorted,arr,len*sizeof(int));
	mergesort(sorted,len);
	display(sorted,len);
	printf("Quick Sort: ");
	memcpy(sorted,arr,len*sizeof(int));
	quicksort(sorted,0,len);
	display(sorted,len);
	return 0;
}
