#include <stdio.h>
#include <stdlib.h>
void print(FILE *);
void copy_into_other_file(FILE *, FILE *);
int f_size(FILE *);
void copy_into_string(FILE *,char *);
char *remove_comment(char *,FILE *,int);
void main()
{
	char fname[100];
	printf("Enter the file name:");
	scanf("%s",fname);

//////////////////////////////////////////////////////////////
	
	FILE *fp1=fopen(fname,"r");
	// print(fp1);
	rewind(fp1);
/////////////////////////////////////////////////////////////

	FILE *fp2=fopen("dev","w");
	copy_into_other_file(fp1,fp2);
	fclose(fp1);
	fclose(fp2);
////////////////////////////////////////////////////////////

	fp2=fopen("dev","r+");
	int fsize=f_size(fp2);
	rewind(fp2);
////////////////////////////////////////////////////////////

	char *temp=malloc(sizeof(char)*fsize);

	copy_into_string(fp2,temp);
	rewind(fp2);
///////////////////////////////////////////////////////////

	FILE *fp3=fopen("deva","w");
	char *temporary=remove_comment(temp,fp2,fsize);
	rewind(fp2);
//////////////////////////////////////////////////////////
	printf("%s\n",temporary);
	fputs(temporary,fp3);

	free(temporary);
	free(temp);

	remove("dev");
	rename("deva","dev");
}

//========================================================
//========================================================
void print(FILE *fp)
{
	char ch;
	while((ch=fgetc(fp)) != EOF)
		printf("%c",ch);
}
//========================================================

void copy_into_other_file(FILE *fp1,FILE *fp2)
{
	char ch;
	while((ch=fgetc(fp1)) != EOF)
	{
		fputc(ch,fp2);
	}
}
//========================================================

int f_size(FILE *fp)
{
	char ch;
	int count=0;
	while((ch=fgetc(fp)) != EOF)
		count++;

	return count;

}
//=========================================================

void copy_into_string(FILE *fp,char *temp)
{
	char ch;
	int i=0;
	while((ch=fgetc(fp)) != EOF)
		temp[i++]=ch;
}
//=========================================================

char *remove_comment(char *temp, FILE *fp,int fsize)
{
	char *temporary=malloc(sizeof(char)*fsize);
	int i=0,k=0;
	while(temp[i])
	{
		if(temp[i]=='/' && temp[i+1]=='/')
		{
			while(1)
			{
				if(temp[i]=='\n')
					break;
				i++;
			}
		}
		else
		{
			temporary[k]=temp[i];
			i++;
			k++;
		}
	}
	return temporary;
}
/*	
  /\
 //\\
//==\\==========================================================

*/