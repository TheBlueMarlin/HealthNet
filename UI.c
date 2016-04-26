/*
 * File:   UI.c
 * Author: marlin
 *
 * Created on April 17, 2016, 12:42 AM
 * The UI class handles the interface the user will use calls to the security
 *      shell.
 * This class will handle all front facing UI commands based on user access level
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UI.h"


User newUser(char newName[], char newPass[], int newID, int newRole) {
    User myUser;

    strncpy(myUser.name, newName, 30);
    strncpy(myUser.pass, newPass, 5);
    getHash(myUser.hash);
    myUser.ID = newID;
    myUser.role = newRole;

    return myUser;
}

unsigned int getHash() {
    unsigned int hash[5];

    hash = {0, 0, 0, 0, 0};


    return hash;
}

void printUsers(User myArray[]) {
    int i = 0;

    while (i < sizeof(myArray)) {
        printf("%s\n", myArray[i].name);

        i++;
    }
    return;
}



void displayDoctorOptions() {
    int task = 0;
    char term = '0';

    printf("Welcome to HealthNet.");
    printf("Select Task: "
           "\nCreate   -0"
           "\nView     -1");

    //Validate input:
    if (scanf("%d%c", &task, &term) != 2 || term != '\n') {
        printf("Improper Input, type number of selection and press enter...");
    }

    switch (task) {
    case 0:
        break;

    case 1:
        break;

    default:
        break;
    }

}


void displayNurseOptions() {

}


void displayPatientOptions() {

}


void displayAdminOptions() {

}
