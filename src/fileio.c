#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "fileio-funcdecs.h"

#define TRUE 1
#define FALSE 0

int main()
{
    printf("----Start of FileIO----\n");
    readFile("000",'1',"00"); // function tester
    printf("\n---- End of FileIO ----\n");
    return 0;
}

void readFile(char patientid[SIZEOF_PATIENTID],char fileType,char fileNumber[SIZEOF_FILENUMBER])
{
    char *filePathRoot = ".././patients/"; // basic root for all patient files
    char *fileTypeExplicit; // container for explicit name of fileType
    if(fileType=='1') fileTypeExplicit="inprocessing";
    else if(fileType=='2') fileTypeExplicit="outprocessing";
    else if(fileType=='3') fileTypeExplicit="immunizations";
    else if(fileType=='4') fileTypeExplicit="medications";
    else fprintf(stderr, "incorrect fileType");
    char filePath[1000]; // buffer for filePath
    sprintf(filePath,"%s%s%c%s%s%s",filePathRoot,patientid,'/',patientid,fileTypeExplicit,fileNumber); // concatenate filePath
    // printf("%s",filePath);
    FILE *filePointer = fopen(filePath,"r"); // open file
    if(filePointer==NULL) fprintf(stderr, "NULL filePointer"); // check for null pointer
    char c;
    while((c=fgetc(filePointer))!=EOF) printf("%c",c); // output char by char to EOF
    fclose(filePointer); // close file
}
void createFile(char patientid[SIZEOF_PATIENTID],char fileType,char fileNumber[SIZEOF_FILENUMBER])
{

}
void deleteFile(char patientid[SIZEOF_PATIENTID],char fileType,char fileNumber[SIZEOF_FILENUMBER])
{

}
void sendImmmunizations(char patientid[SIZEOF_PATIENTID])
{

}