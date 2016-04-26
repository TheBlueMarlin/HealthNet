#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "fileio-funcdecs.h"

#define TRUE 1
#define FALSE 0

#define SIZEOF_PATIENTID 3
#define SIZEOF_FILENUMBER 2

#define FILETYPE_INPROCESSING 1
#define FILETYPE_OUTPROCESSING 2
#define FILETYPE_IMMUNIZATIONS 3
#define FILETYPE_MEDICATIONS 4

#define NUMBEROF_FILETYPES 4

#define IMMUNIZATIONS_PATH_LENGTH 29 // .././immunizations/000/

int main()
{
    printf("----Start of FileIO----\n");

    appendFile("This is Patrick's Append",0,1,0); // function tester

    // createFile(0,FILETYPE_INPROCESSING,0); // function tester
    // readFile(0,FILETYPE_INPROCESSING,0); // function tester
    // editFile("This is some data from the user",0,FILETYPE_INPROCESSING,0); // function tester
    // readFile(0,FILETYPE_INPROCESSING,0); // function tester
    // appendFile("--Let\'s append some more data!",0,FILETYPE_INPROCESSING,0); // function tester
    // readFile(0,FILETYPE_INPROCESSING,0); // function tester
    // deleteFile(0,FILETYPE_INPROCESSING,0); // function tester

    // printf("\n");
    // for(int i=0;i<10;i++) createFile(0,FILETYPE_IMMUNIZATIONS,i);
    // printf("\n");

    // showRecords(0);
    
    // sendImmmunizations(000); // function tester
    printf("---- End of FileIO ----\n");
    return 0;
}

void readFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    char *fileTypeExplicit = malloc(1000); // buffer for Explicit fileType
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    if(fileExists(filePath))
    {
        FILE *filePointer = fopen(filePath,"r");
        char c;
        while((c=fgetc(filePointer))!=EOF) printf("%c",c); // output char by char to EOF
        fclose(filePointer); // close file
    }
    else fprintf(stderr,"file \"%s\" does not exist\n",filePath);
    free(filePath); // free filePath malloc
    free(fileTypeExplicit);
    printf("\n");
}
void createFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    char *fileTypeExplicit = malloc(1000); // buffer for Explicit fileType
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    FILE *filePointer = fopen(filePath,"w");
    if(fileExists(filePath))
    {
        fprintf(filePointer,"default contents of \"%s\"",filePath);
        fclose(filePointer);
        printf("\"%s\" created w/o issue\n",filePath);
    }
    else fprintf(stderr, "unable to create \"%s\"\n", filePath);
    free(filePath);
    free(fileTypeExplicit);
}
void deleteFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    char *fileTypeExplicit = malloc(1000); // buffer for Explicit fileType
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    if(remove(filePath)) fprintf(stderr, "unable to delete file\n");
    else fprintf(stderr, "\"%s\" deleted\n", filePath);
    free(filePath);
    free(fileTypeExplicit);
}
void showRecords(unsigned int patientid)
{
    char *filePath = malloc(1000); // buffer for filePath   
    char *fileTypeExplicit = malloc(1000); // buffer for explicit fileType
    unsigned int fileType = 1; // id of filetype
    unsigned int fileNumber = 0; // file number in order
    free(filePath);
    free(fileTypeExplicit);
}
void editFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    char *fileTypeExplicit = malloc(1000); // buffer for Explicit fileType
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    FILE *filePointer = fopen(filePath,"w");
    if(fileExists(filePath))
    {
        fprintf(filePointer,data);
        fclose(filePointer);
        printf("\"%s\" written to \"%s\" w/o issue\n",data,filePath);
    }
    else fprintf(stderr, "unable to create \"%s\"\n", filePath);
    free(filePath);
    free(fileTypeExplicit);
}
void appendFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(1000); // buffer for filePath
    char *fileTypeExplicit = malloc(1000); // buffer for Explicit fileType
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    printf("%s",filePath);
    FILE *filePointer = fopen(filePath,"a");
    if(filePointer==NULL) filePointer = fopen(filePath,"w");
    if(filePointer==NULL) fprintf(stderr, "unable to create \"%s\"\n", filePath);
    else
    {
        fprintf(filePointer,data);
        fclose(filePointer);
        printf("\"%s\" appended to \"%s\" w/o issue\n",data,filePath);
    } 
    free(filePath);
    free(fileTypeExplicit);
}
void sendImmmunizations(unsigned int patientid)
{
    char *filePath = malloc(1000); // buffer for filePath
    char *movePath = malloc(1000); // buffer for movePath
    char *fileTypeExplicit = malloc(1000); // buffer for Explicit fileType
    char mkdirPath[IMMUNIZATIONS_PATH_LENGTH];
    unsigned int immunizations = 0; // number of immunizations records in the file
    int renameFailed = 0; // boolean for testing rename function
    FILE *filePointer;
    do {
        concatFilePath(filePath,fileTypeExplicit,patientid,FILETYPE_IMMUNIZATIONS,immunizations); // generate filePath using params
        sprintf(movePath,".././immunizationsclinic/%03d/%03d%s%02d",patientid,patientid,fileTypeExplicit,immunizations); // generate movePath using params
        // printf("\n\nYOU MADE IT!!!!!!!\n\n");
        strncpy(mkdirPath,movePath,IMMUNIZATIONS_PATH_LENGTH);
        mkdir(mkdirPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if(rename(filePath,movePath)) fprintf(stderr, "\"%s\" cannot be copied to \"%s\"\n",filePath,movePath); // copy file to immunizations clinic
        concatFilePath(filePath,fileTypeExplicit,patientid,FILETYPE_IMMUNIZATIONS,++immunizations); // generate filePath using params
        filePointer = fopen(filePath,"r"); // try to open file
    } while(filePointer!=NULL); // check for null pointer
    fclose(filePointer); // close file
    free(filePath);
    free(movePath);
    free(fileTypeExplicit);
}
void concatFilePath(char *filePath,char *fileTypeExplicit,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{   
    char *filePathRoot = ".././patients/"; // basic root for all patient files
    getExplicitFileType(fileTypeExplicit,fileType);
    sprintf(filePath,"%s%03d/%03d%s%02d",filePathRoot,patientid,patientid,fileTypeExplicit,fileNumber); // concatenate filePath
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
void getExplicitFileType(char *fileTypeExplicit,unsigned int fileType)
{
    if(fileType==FILETYPE_INPROCESSING) fileTypeExplicit="inprocessing";
    else if(fileType==FILETYPE_OUTPROCESSING) fileTypeExplicit="outprocessing";
    else if(fileType==FILETYPE_IMMUNIZATIONS) fileTypeExplicit="immunizations";
    else if(fileType==FILETYPE_MEDICATIONS) fileTypeExplicit="medications";
    else fprintf(stderr, "incorrect fileType\n");
}