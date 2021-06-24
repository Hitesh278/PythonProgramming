#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
void check(char t[]);
char key[24][12]={"int","float","char","double","bool","void","extern","unsigned","goto","static","class","struct","for","if","else","return","register","long","while","do","include","define"};
char header[6][15]={"stdio.h","conio.h","malloc.h","process.h","string.h","ctype.h"};
int numflag=0,f=0;
void main()
{
char ch,token[20];
int i;
//clrscr();
FILE *fp;
clrscr();
fp=fopen("test.c","r");
if(fp==NULL)
{
printf("\n file does not exist");
exit(0);
}
while((ch=fgetc(fp))!=EOF)
{
	if(ch=='/')//checking for comments in the file
	{
	ch=getc(fp);
	if(ch=='/')
		{
		while((ch=getc(fp))!='\n');
		}
	else if(ch=='*')
		{
		while(f==0)
			{
			ch=getc(fp);
			if(ch=='*')
				{
				ch=getc(fp);
				if(ch=='/')
				f=1;
				}
			}
			f=0;
		}
	}
	else if(isalpha(ch))
		{
		i=0;
		token[i++]=ch;

		while(isalpha(ch=fgetc(fp))||isdigit(ch)||ch=='_'||ch=='.')
			{

			token[i++]=ch;

			}
		token[i]='\0';
		check(token);
		fseek(fp,-1,1);
		}
	else if(isdigit(ch))
		{
		i=0;
		token[i++]=ch;
		while(isdigit(ch=fgetc(fp))||ch=='.')
			{
			token[i++]=ch;
			}
		token[i]='\0';
		numflag=1;
		check(token);
		fseek(fp,-1,1);
		}
	else if(ch==' '||ch=='\n'||ch=='\t'|ch==','||ch==';'||ch=='('||ch==')'||ch=='{'|| ch=='}'||ch=='['||ch==']'||ch=='#')
		{
		printf("\n Spacial Character\t%c",ch);
		continue;
		}
	else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='='||ch=='!'|| ch=='<'||ch=='>')
		{
		printf("\nOperator\t%c",ch);
		continue;
		}
	else
		{
		i=0;
		token[i++]=ch;
		token[i]='\0';
		check(token);
		}
	}
	getch();
}
void check(char t[])
{
 int i;
 if(numflag==1)
	{
	printf("\nConstant \t %s",t);
	return;
	}
 for(i=0;i<6;i++)
	{
	if(strcmp(t,header[i])==0)
		{
		printf("\nHeader file\t %s",t);
		return;
		}
	}
 for(i=0;i<21;i++)
	{
	if(strcmp(key[i],t)==0)
		{
		printf("\nKeyword\t\t %s", key[i]);
		return;
		}
	}
 printf("\nIdentifier\t %s", t);
}
