#include<stdio.h>

static void swapnum(int *a,int *b);
static int soutarr(int *arr,int n);

int main()
{   
		int i;
		int arr[]={3,2,1,4,5,6,9,7};
		soutarr(arr,sizeof(arr)/sizeof(*arr));
		for(i=0;i<sizeof(arr)/sizeof(*arr);i++ )
		{
				printf("%d",arr[i]);
		}
		printf("\n");
		return 0;
}


static void swapnum(int *a,int *b)
{
		int tmp;
		tmp=*a;
		*a=*b;
		*b=tmp;
}

static int soutarr(int *arr,int n)
{
		int i,j;
		for(i=0;i<n-1;i++)
		{
				for(j=0;j<n-i-1;j++) 
								{
										if(arr[j]>arr[j+1])
										{
												swapnum(arr+j,arr+j+1);
										}
								}
		}
		return 0;
}
