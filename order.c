#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void swapnum(void *arr,int size,int i,int j);
int soutarr(void *arr,int n,int size);

int (*cmp)(const void *data1,const void *data2)
{
		const int *d1=data1;
		const int *d2=data2;

		return *d1-*d2;
}

int main()
{   
		int i;
		int arr[]={3,2,1,4,5,6,9,7};
		soutarr(arr,sizeof(arr)/sizeof(*arr),sizeof(*arr));
		for(i=0;i<sizeof(arr)/sizeof(*arr);i++ )
		{
				printf("%d",arr[i]);
		}
		printf("\n");
		return 0;
}


void swapnum(void *arr,int size,int i,int j)
{
		char *tmp=malloc(size);
		memcpy(tmp,(char *)arr+j*size,size);
		memcpy((char *)arr+j*size,(char *)arr+(j+1)*size,size);
		memcpy((char *)arr+(j+1)*size,tmp,size);
}

int soutarr(void *arr,int n,int size)
{

		int i,j;
		for(i=0;i<n-1;i++)
		{
				for(j=0;j<n-i-1;j++) 
								{
										if(cmp((char *)arr+j*size,(char *)arr+(j+1)*size)>0)
										{
												swapnum(arr,size,i,j);
										}
								}
		}
		return 0;
}
