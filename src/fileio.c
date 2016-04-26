#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "fileio-funcdecs.h"

#define TRUE 1
#define FALSE 0

int main()
{
    printf("----Start of FileIO----\n");
    createFile(000,'1',0); // function tester
    readFile(000,'1',00); // function tester
    editFile("This is some data from the user",000,'1',00); // function tester
    readFile(000,'1',00); // function tester
    appendFile("--Let\'s append some more data!",000,'1',00); // function tester
    readFile(000,'1',00); // function tester
    deleteFile(000,'1',0); // function tester
    // sendImmmunizations(000); // function tester
    printf("---- End of FileIO ----\n");
    return 0;
}

void readFile(unsigned int patientid,char fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    concatFilePath(filePath,patientid,fileType,fileNumber); // generate filePath using params
    if(fileExists(filePath))
    {
        FILE *filePointer = fopen(filePath,"r");
        char c;
        while((c=fgetc(filePointer))!=EOF) printf("%c",c); // output char by char to EOF
        fclose(filePointer); // close file
    }
    else fprintf(stderr,"file \"%s\" does not exist\n",filePath);
    free(filePath); // free filePath malloc
    printf("\n");
}
void createFile(unsigned int patientid,char fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    concatFilePath(filePath,patientid,fileType,fileNumber); // generate filePath using params
    FILE *filePointer = fopen(filePath,"w");
    if(fileExists(filePath))
    {
        fprintf(filePointer,"default contents of \"%s\"",filePath);
        fclose(filePointer);
        printf("\"%s\" created w/o issue\n",filePath);
    }
    else fprintf(stderr, "unable to create \"%s\"\n", filePath);
}
void deleteFile(unsigned int patientid,char fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    concatFilePath(filePath,patientid,fileType,fileNumber); // generate filePath using params
    if(remove(filePath)) fprintf(stderr, "unable to delete file\n");
    else fprintf(stderr, "\"%s\" deleted\n", filePath);
}
void editFile(char *data,unsigned int patientid,char fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    concatFilePath(filePath,patientid,fileType,fileNumber); // generate filePath using params
    FILE *filePointer = fopen(filePath,"w");
    if(fileExists(filePath))
    {
        fprintf(filePointer,data);
        fclose(filePointer);
        printf("\"%s\" written to \"%s\" w/o issue\n",data,filePath);
    }
    else fprintf(stderr, "unable to create \"%s\"\n", filePath);
}
void appendFile(char *data,unsigned int patientid,char fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    concatFilePath(filePath,patientid,fileType,fileNumber); // generate filePath using params
    FILE *filePointer = fopen(filePath,"a");
    if(fileExists(filePath))
    {
        fprintf(filePointer,data);
        fclose(filePointer);
        printf("\"%s\" appended to \"%s\" w/o issue\n",data,filePath);
    }
    else fprintf(stderr, "unable to create \"%s\"\n", filePath);   
}
void sendImmmunizations(unsigned int patientid)
{

}
void concatFilePath(char *filePath,unsigned int patientid,char fileType,unsigned int fileNumber)
{   
    char *filePathRoot = ".././patients/"; // basic root for all patient files
    char *fileTypeExplicit; // container for explicit name of fileType
    if(fileType=='1') fileTypeExplicit="inprocessing";
    else if(fileType=='2') fileTypeExplicit="outprocessing";
    else if(fileType=='3') fileTypeExplicit="immunizations";
    else if(fileType=='4') fileTypeExplicit="medications";
    else fprintf(stderr, "incorrect fileType\n");
    sprintf(filePath,"%s%03d%c%03d%s%02d",filePathRoot,patientid,'/',patientid,fileTypeExplicit,fileNumber); // concatenate filePath
    // printf("%s",filePath);
}
char fileExists(char *filePath)
{
    FILE *filePointer = fopen(filePath,"r"); // try to open file
    if(filePointer==NULL) // check for null pointer
    {
        fprintf(stderr, "NULL filePointer\n");
        return FALSE; 
    }
    fclose(filePointer); // close file
    return TRUE;
}