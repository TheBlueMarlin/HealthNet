#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "fileio-funcdecs.h"

#define TRUE 1
#define FALSE 0
#define FN_CREDENTIALS ".././accounts/credentials.txt"
#define FN_ASSIGNMENTS "assignments.txt"
#define SIZEOF_CREDENTIAL 18 // user(8),delimiter(1),pass(8),newline(1)
#define SIZEOF_USERNAME 8
#define SIZEOF_PASSWORD 8

int main()
{
    printf("----Start of FileIO----\n");
    if(userExists("pst7")) printf("USER \"pst7\" EXISTS\n");
    if(userExists("ach40")) printf("USER \"ach40\" EXISTS\n");
    printf("\n---- End of FileIO ----\n");
    return 0;
}

void createAccount(char role, char username[SIZEOF_USERNAME], char password[SIZEOF_PASSWORD]) {

}
void assignPatient(char parent[SIZEOF_USERNAME], char patient[SIZEOF_USERNAME]) {

}
void unassignPatient(char parent[SIZEOF_USERNAME], char patient[SIZEOF_USERNAME]) {

}
void viewAssignments(char username[SIZEOF_USERNAME]) {

}
char getRole(char username[SIZEOF_USERNAME]) {
    return FALSE;
}
char userExists(char username[SIZEOF_USERNAME]) {
    FILE *fp = fopen(FN_CREDENTIALS,"r"); // credentials file
        if(fp==NULL) return FALSE;
    char c; // current character from file
    char buffer[SIZEOF_USERNAME]; // current username from file
    int i = 0; // general index
    while((c=fgetc(fp))!=EOF && c!=',' && i<sizeof(buffer)) // run while not EOF, delimiter, or size > username
    {
        // printf("%c",c);
        buffer[i++] = c;
        if(!strncmp(buffer,username,i-1))
        {
            fclose(fp);
            return TRUE;
        }
    }
    fclose(fp);
    return FALSE;
}
void deleteAccount(char username[SIZEOF_USERNAME]) {

}
void createRecord(char username[SIZEOF_USERNAME]) {

}
void editRecordField(char username[SIZEOF_USERNAME], char field) {

}
void viewRecordField(char username[SIZEOF_USERNAME], char field) {

}
void viewRecord(char username[SIZEOF_USERNAME]) {

}
void deleteRecord(char username[SIZEOF_USERNAME]) {

}