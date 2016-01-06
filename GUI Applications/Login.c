#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int lenun,lenline,i,j,ascii_val,line_num,cmp=0,len,len1;
	char line[1000];
	char un[1000];
	char ps[1000];
	char pso[1000];
	char psc[1000];
	char pss[1000];
	FILE *fptr;
	fptr=fopen("passwd.txt","r");
	if(fptr==NULL)
	{
		printf("Error!");
 		exit(1);
	}
	printf("Enter UserName:\n");
	gets(un);
	printf("Enter Password:\n");
	gets(ps);
	lenun=strlen(un)+3;
	while ( fgets ( line, 1000, fptr ) != NULL ) /* read a line */
        {
                if(strstr(line,un))
                {
                	strncpy(pss,line,1000);
                }
        }
        lenline=strlen(line);
        for(i=lenun;i<lenline;i++)
        {
        	ascii_val=ps[i-lenun];
        	if(ascii_val>=10)
      			ascii_val-=10;
			psc[i-lenun]=ascii_val;  	
			pso[i-lenun]=pss[i];
        }
        len=strlen(pso);
		len1=strlen(psc)-2;
		if(len!=len1)
			cmp++;
       	for(j=0;j<len;j++)
       	{
			if(pso[j]!=psc[j])
			{
				cmp++;	
			}
       	}
       	if(cmp==0)
       		printf("Welcome %s\n",un);
        else
        	printf("Wrong Password\n");
		fclose ( fptr );
}