#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(FILE *);
void copy_into_other_file(FILE *, FILE *);
int f_size(FILE *);
void copy_into_string(FILE *,char *);
char *remove_comment(char *,FILE *,int);
void fetch_word(char *, char *);
void header_include(char *, char *, char *);
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
	fputs(temporary,fp3);
	fclose(fp3);
	free(temporary);
	// free(temp);

	// remove("dev");
	// rename("deva","dev");
/////////////////////////////////////////////////////////-end comment remove 
////////////////////////////////////////////////////////-start header file insertion
	
	fp1=fopen("deva","r+");
	temp=malloc(sizeof(char)*fsize);
	for(int i=0;i<fsize;i++)
		temp[i]=0;
	copy_into_string(fp1,temp);
	rewind(fp1);
	char header[100];
	fetch_word(temp,header);
	printf("%s\n",header);

	fp2=fopen("/usr/include/stdio.h","r");
	int header_size=f_size(fp2);
	rewind(fp2);
	char *temp_header=malloc(header_size+10);
	copy_into_string(fp2,temp_header);
	rewind(fp2);

	temp=realloc(temp,header_size);

	header_include(temp,header,temp_header);
	rewind(fp2);

	printf("%s\n",temp);


}

/*----------------print content of the file-------------*/
void print(FILE *fp)
{
	char ch;
	while((ch=fgetc(fp)) != EOF)
		printf("%c",ch);
}


/*----------copy the data into another file------------*/
void copy_into_other_file(FILE *fp1,FILE *fp2)
{
	char ch;
	while((ch=fgetc(fp1)) != EOF)
	{
		fputc(ch,fp2);
	}
}


/*------------find the size of file--------------------*/
int f_size(FILE *fp)
{
	char ch;
	int count=0;
	while((ch=fgetc(fp)) != EOF)
		count++;

	return count;

}


/*------------copy file data into string----------------*/
void copy_into_string(FILE *fp,char *temp)
{
	char ch;
	int i=0;
	while((ch=fgetc(fp)) != EOF)
		temp[i++]=ch;
}



/*------------remove comment from code-----------------*/
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



/*-------------fetch_header_word----------------------------*/
void fetch_word(char *temp, char *header)
{
	int i,j,k,l,h;

	for(i=0;temp[i];i++)
	{
		if(temp[i]=='#')
			k=i;
		if(temp[i]=='>')
			l=i;
	}
	for(j=k,h=0;j<=l;j++,h++)
		header[h]=temp[j];

}

/*---------------header file include------------------------*/
void header_include(char *temp, char *header, char *temp_header)
{
	char *addr=strstr(temp,header);
	if(addr==NULL)
		exit(1);
	
	else
	{
		memmove(addr+strlen(temp_header),addr+strlen(header),strlen(addr)-strlen(header)+1);
		memcpy(addr,temp_header,strlen(temp_header));
	}
	printf("%s\n",temp);
}