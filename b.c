
#include<stdio.h>
#include<stdlib.h>

int main()
{
		int a=10;
		int b=20;
		*(a<b?&a:&b)=30;
		printf("a=%d,b=%d\n",a,b);
		return 0;
}

