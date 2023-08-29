#include<stdio.h>
int linearsearch(int arr[],int len,int element){
	for(len--;len>=0;len--)
		if(arr[len]==element)
			return len;
	return -1;
}
int binarysearch(int arr[],unsigned int len,int element){
	unsigned int beg=0,m;
	int e;
	while(beg<=len){
		m=(beg+len)/2;
		e=arr[m];
		if(e==element)
			return m;
		else if(e>element)
			len=m-1;
		else
			beg=m+1;
	}
	return -1;
}
int main(){
	unsigned int len;
	printf("Enter number of elements (positive integer) : ");
	scanf("%d",&len);
	int arr[len];
	printf("Enter of elements (integer - comma separated) : ");
	for(unsigned int i=0;i<len;i++)
		scanf("%d,",&arr[i]);
	printf("Enter the element to be searched (integer) : ");
	int e;
	scanf("%d",&e);
	int index=linearsearch(arr,len,e);
	if(index==-1)
		printf("%d not found in array.\n",e);
	else
		printf("%d found in array at index %d.\n",e,index);
	printf("Enter of elements in ASCENDING ORDER (integer - comma separated) : ");
	for(unsigned int i=0;i<len;i++)
		scanf("%d,",&arr[i]);
	printf("Enter the element to be searched (integer) : ");
	scanf("%d",&e);
	if((index=binarysearch(arr,len,e))==-1)
		printf("%d not found in array.\n",e);
	else
		printf("%d found in array at index %d.\n",e,index);
	return 0;
}
