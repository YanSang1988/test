#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void freemem3(char ***p,int count)
{
		int i=0;
		char **myp=NULL;
		if(p=NULL)
		{
				return;
		}
		myp=*p;
		for(i=0;i<count;i++)
		{
				if(myp[i]!=NULL)
				{
						free(myp[i]);
				}
		}
		if(myp!=NULL)
		{
				free(myp);
		}
		*p=NULL;
}

int spitstring( char *buf1,char c,char ***myp3,int *count)
{
		int ret=0;
		char *p=NULL,*ptmp=NULL;
		int tmpcount=0;
		char **myp=NULL;
		p=buf1;
		ptmp=buf1;
		do
		{
				p=strchr(p,c);
				if(p!=NULL)
				{
						if(p-ptmp>0)
						{
								tmpcount++;
								ptmp=p=p+1;
						}
				}
				else
				{
						break;
				}
		}while(*p!='\0');


*count=tmpcount;//间接赋值是指针存在的最大意义！
myp=(char **)malloc(tmpcount*sizeof(char *));

if(myp==NULL)
{
		ret=-1;
		printf("function error!\n");
		goto END;
}
memset(myp,0,tmpcount&sizeof(char *));

tmpcount=0;
p=buf1;
ptmp=buf1;

do
{
		p=strchr(p,c);
		if(p!=NULL)
		{
				if(p-ptmp>0)
				{
						int len=p-ptmp+1;
						myp[tmpcount]=(char *)malloc(len);
						if(myp[tmpcount]==NULL)
						{
								ret=-1;
								printf("function error!\n");
								goto END;
						}
						strncpy(myp[tmpcount],ptmp,p-ptmp);
						myp[tmpcount][p-ptmp]='\0';
						tmpcount++;
						ptmp=p=p+1;
				}
		}
		else
		{
				break;
		}
}while(*p!='\0');

END:
		if(ret!=0)
		{
				freemem3(&myp,*count);												
		}
		else
		{
				*myp3=myp;
		}
		return ret;		
}

void main()
{
		int ret=0,i=0;
		char *p1="abcdef,acv";
		char ctem=',';
		int ncount;
		char **p=NULL;
		
		ret=spitstring(p1,ctem,&p,&ncount);
		if(ret!=0)
		{
				printf("function error!\n");
		}
		for(i=0;i<ncount;i++)
		{
				printf("%s\n",p[i]);
		}
		for(i=0;i<ncount;i++)
		{
				free(p[i]);
		}
		free(p);
}
