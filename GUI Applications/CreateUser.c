#include <stdio.h>
#include <stdlib.h>
int main()
{
	int len,i,ascii_val;
	char un[1000];
	char ps[1000];
	char pss[1000];
	FILE *fptr;
	fptr=fopen("passwd.txt","a");
	if(fptr==NULL)
	{
		printf("Error!");
 		exit(1);
	}
	printf("Enter a UserName:\n");
	gets(un);
	printf("Enter a Password:\n");
	gets(ps);
	len = strlen(ps);
	fprintf(fptr,"\n%s-->",un);
	for(i=0;i<len;i++)
	{
		ascii_val=ps[i];
		if(ascii_val>=10)
			ascii_val-=10;
		pss[i]=ascii_val;
		fprintf(fptr,"%c",pss[i]);
	}
	fclose(fptr);
	return 0;
}