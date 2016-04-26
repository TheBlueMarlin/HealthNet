#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "fileio-funcdecs.h"

#define TRUE 1
#define FALSE 0

#define SIZEOF_PATIENTID 3
#define SIZEOF_FILENUMBER 2
#define STD_BUFFER_LENGTH 1000

#define FILETYPE_INPROCESSING 1
#define FILETYPE_OUTPROCESSING 2
#define FILETYPE_IMMUNIZATIONS 3
#define FILETYPE_MEDICATIONS 4

#define NUMBEROF_FILETYPES 4

#define IMMUNIZATIONS_PATH_LENGTH 24 // .././immunizations/000/
#define PATIENTS_PATH_LENGTH 18 // .././patients/000/

int main()
{
    printf("----Start of FileIO----\n");

    createFile(0,1,0);
    readFile(0,1,0);
    deleteFile(0,1,0);
    editFile("might want to get that looked at...",0,2,0);
    appendFile("you've got aids!",0,3,0);
    // showRecords(0);
    sendImmmunizations(0);
    
    printf("---- End of FileIO ----\n");
    return 0;
}

void readFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(STD_BUFFER_LENGTH); // buffer for filePath
    char *fileTypeExplicit = malloc(STD_BUFFER_LENGTH); // buffer for Explicit fileType
    char c;
    FILE *filePointer;
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    if(fileExists(filePath))
    {
        filePointer = fopen(filePath,"r");
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
    char *filePath = malloc(STD_BUFFER_LENGTH); // buffer for filePath
    char *fileTypeExplicit = malloc(STD_BUFFER_LENGTH); // buffer for Explicit fileType
    char *mkdirPath = malloc(STD_BUFFER_LENGTH); // buffer for mkdir path;
    sprintf(mkdirPath,".././patients/%03d/",patientid);
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    mkdir(mkdirPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    FILE *filePointer = fopen(filePath,"w");
    if(fileExists(filePath))
    {
        fprintf(filePointer,"default contents of \"%s\"",filePath);
        fclose(filePointer);
        printf("\"%s\" created w/o issue\n",filePath);
    }
    else fprintf(stderr, "unable to create \"%s\"\n", filePath);
    free(mkdirPath);
    free(filePath);
    free(fileTypeExplicit);
}
void deleteFile(unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(STD_BUFFER_LENGTH); // buffer for filePath
    char *fileTypeExplicit = malloc(STD_BUFFER_LENGTH); // buffer for Explicit fileType
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    if(remove(filePath)) fprintf(stderr, "unable to delete file\n");
    else fprintf(stderr, "\"%s\" deleted\n", filePath);
    free(filePath);
    free(fileTypeExplicit);
}
void showRecords(unsigned int patientid)
{/*
    char *filePath = malloc(STD_BUFFER_LENGTH); // buffer for filePath   
    char *fileTypeExplicit = malloc(STD_BUFFER_LENGTH); // buffer for explicit fileType
    unsigned int fileType = 1; // id of filetype
    unsigned int fileNumber = 0; // file number in order
    free(filePath);
    free(fileTypeExplicit);
*/}
void editFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(STD_BUFFER_LENGTH); // buffer for filePath
    char *fileTypeExplicit = malloc(STD_BUFFER_LENGTH); // buffer for explicit file type
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    // printf("%s",filePath);
    FILE *filePointer = fopen(filePath,"w");
    if(filePointer==NULL) createFile(patientid,fileType,fileNumber);
    filePointer = fopen(filePath,"w");
    if(filePointer==NULL) fprintf(stderr, "unable to create \"%s\"\n", filePath);
    else
    {
        fprintf(filePointer,data);
        fclose(filePointer);
        printf("\"%s\" written to \"%s\" w/o issue\n",data,filePath);
    } 
    free(filePath);
    free(fileTypeExplicit);
}
void appendFile(char *data,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{
    char *filePath = malloc(STD_BUFFER_LENGTH); // buffer for filePath
    char *fileTypeExplicit = malloc(STD_BUFFER_LENGTH); // buffer for explicit file type
    concatFilePath(filePath,fileTypeExplicit,patientid,fileType,fileNumber); // generate filePath using params
    // printf("%s",filePath);
    FILE *filePointer = fopen(filePath,"a");
    if(filePointer==NULL) createFile(patientid,fileType,fileNumber);
    filePointer = fopen(filePath,"a");
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
    char *filePath = malloc(STD_BUFFER_LENGTH); // buffer for filePath
    char *movePath = malloc(STD_BUFFER_LENGTH); // buffer for movePath
    char *fileTypeExplicit = malloc(STD_BUFFER_LENGTH); // buffer for Explicit fileType
    char *mkdirPath = malloc(STD_BUFFER_LENGTH); // buffer for mkdir path;

    unsigned int immunizations = 0; // number of immunizations records in the file
    int renameFailed = 0; // boolean for testing rename function
    FILE *filePointer;
    do {
        concatFilePath(filePath,fileTypeExplicit,patientid,FILETYPE_IMMUNIZATIONS,immunizations); // generate filePath using params    
        sprintf(mkdirPath,".././immunizationsclinic/%03d/",patientid);
        mkdir(mkdirPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        sprintf(movePath,"%s%03d%s%02d",mkdirPath,patientid,"immunizations",immunizations); // generate movePath using params
        if(rename(filePath,movePath)) fprintf(stderr, "\"%s\" cannot be copied to \"%s\"\n",filePath,movePath); // copy file to immunizations clinic
        concatFilePath(filePath,fileTypeExplicit,patientid,FILETYPE_IMMUNIZATIONS,++immunizations); // generate filePath using params
        filePointer = fopen(filePath,"r"); // try to open file
    } while(filePointer!=NULL); // check for null pointer
    fclose(filePointer); // close file
    free(filePath);
    free(movePath);
    free(mkdirPath);
    free(fileTypeExplicit);
}
void concatFilePath(char *filePath,char *fileTypeExplicit,unsigned int patientid,unsigned int fileType,unsigned int fileNumber)
{   
    char *filePathRoot = ".././patients/"; // basic root for all patient files
    
    if(fileType==FILETYPE_INPROCESSING) fileTypeExplicit="inprocessing";
    else if(fileType==FILETYPE_OUTPROCESSING) fileTypeExplicit="outprocessing";
    else if(fileType==FILETYPE_IMMUNIZATIONS) fileTypeExplicit="immunizations";
    else if(fileType==FILETYPE_MEDICATIONS) fileTypeExplicit="medications";
    else fprintf(stderr, "incorrect fileType\n");

    // printf("%s",fileTypeExplicit);
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