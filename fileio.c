#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "users.h"
#include "linkedList.h"

char exists(char *fn);
void initDataFile();
void readFile(char *fn);
char getData(char *input, int count);

int main()
{
    char *fn = "data.dat";
    int count = 0;
    while(!exists(fn))
        initDataFile(fn);
    readFile(fn);
    printf("\n");
    getData("PAT",count++);
    getData("1234",count++);
    getData("name",count++);
    printf("\n");
    return 0;
}
// true if data file exists
char exists(char *fn)
{
    FILE *fp = fopen(fn,"r");
    if(fp==NULL)
        return 0;
    fclose(fp);
    return 1;
}
// creates new data file
void initDataFile(char *fn)
{
    FILE *fp = fopen(fn,"w");
    fprintf(fp,"CONTENTS OF DATA FILE");
    fclose(fp);
}
// reads contents of data file
void readFile(char *fn)
{
    char buffer = 0;
    FILE *fp = fopen(fn,"r");
    if(fp==NULL)
        printf("file does not exist");
    else {
        while((buffer = getc(fp))!=EOF)
            putchar(buffer);
    }
    fclose(fp);
}
char getData(char *input, int count)
{
    if(count==0)
    {
        if(!strncmp(input,"pat",3))
        {
            return 1;
        }
    }  
    else if(count==1)
    {
        if(!strncmp(input,"1234",4))
        {
            return 1;
        }
    }
    else if(count==2)
    {
        if(!strncmp(input,"name",4))
        {
            printf("Patrick");
            return 1;
        }
    }
    return 0;
}