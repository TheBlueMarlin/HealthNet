#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void createAccount(char role, char *username, char *password);
void assignPatient(char *parent, char *patient);
void unassignPatient(char *parent, char *patient);
void viewAssignments(char *username);
char getRole(char *username);
char userExists(char *username);
void deleteAccount(char *username);
void createRecord(char *username);
void editRecordField(char *username, char field);
void viewRecordField(char *username, char field);
void viewRecord(char *username);
void deleteRecord(char *username);

int main()
{
    printf("\n----Start of FileIO----\n");
    printf("\n---- End of FileIO ----\n");
    return 0;
}