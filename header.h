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


