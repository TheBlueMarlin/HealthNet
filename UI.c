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
#include "auth.h"

User newUser(unsigned char newName[], unsigned char newPass[], int newID, int newRole)
{
	User myUser;
	int i = 0;
	for(i = 0; i < 5; i++) myUser.name[i] = newName[i];
	for(i = 0; i < 5; i++) myUser.pass[i] = newPass[i];
	myUser.hash = createToken_UP(myUser.name, myUser.pass);
	myUser.ID = newID;
	myUser.role = newRole;
	return myUser;
}



void printUsers(User myArray[])
{
	int i = 0;
	while(i < sizeof(myArray))
	{
		printf("%s\n", myArray[i].name);
		i++;
	}
	return;
}

void displayDoctorOptions()
{
	int task = 0;
	int done = -1;
	char term = '0';
	char filename[20]  = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
	                      '\0', '\0', '\0', '\0', '\0', '\0', '\0'
	                     };
	int PID = 0;
	printf("Welcome to HealthNet.\n");
	while(done < 0)
	{
		printf("Select a Task: "
		       "\nCreate           -0"
		       "\nView             -1"
		       "\nSend IMM request -2"
		       "\nDelete File      -3"
		       "\nDone- Log out    -4\n:");
		//Validate input:
		if(scanf("%d%c", &task, &term) != 2 || term != '\n')
		{
			printf("\nImproper Input, type number of selection and press enter...");
		}
		switch(task)
		{
		case 0: //Write new file
			printf("Enter patient ID: ");
			if(scanf("%d%c", &PID, &term) != 2 || term != '\n')
			{
				printf("\nImproper Input, type number of selection and press enter...");
			}
			//TODO make call to create_S
			break;
		case 2: //Read file
			break;
		case 3: //Delete file
			printf("Enter Filename of File you wish to delete: ");
			scanf("%19s", filename);
			filename[19] = 0;
			//TODO: make call to destroy_S
			break;
		case 4: //break loop and log out
			printf("Logging you out...");
			done = 1;
			exit(-1);
			break;
		default: //improper input run again
			break;
		}
	}
}

void displayPatientOptions()
{
	char fileName[20] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
	                     '\0', '\0', '\0', '\0', '\0', '\0', '\0'
	                    };
	printf("Welcome to HealthNet.");
	printf("Enter the name of the File you want to view");
	scanf("%19s", fileName);
	fileName[19] = 0;
	if(fileName[0] == -1)
	{
		exit(-1);
	}
	//TODO: make call to read_S
	return;
}

void displayAdminOptions()
{
	int task = 0;
	char term = '0';
	int done = -1;
	char fileName[20] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
	                     '\0', '\0', '\0', '\0', '\0', '\0', '\0'
	                    };
	printf("Welcome to HealthNet.");
	while(done < 0)
	{
		printf("Select Task: "
		       "\nDelete              -1"
		       "\nCreate new User     -2"
		       "\nLog out             -3");
		//Validate input:
		if(scanf("%d%c", &task, &term) != 2 || term != '\n')
		{
			printf("Improper Input, type number of selection and press enter...");
		}
		switch(task)
		{
		case 1: //Delete file
			printf("Welcome to HealthNet.");
			printf("Enter the name of the File you want to delete");
			scanf("%19s", fileName);
			fileName[19] = 0;
			//TODO: make call to destroy_S();
			break;
		case 2: //Add new user:
			printf("Simulating adding a user...");
			break;
		case 3:
			printf("Logging you out...");
			done = 1;
			exit(-1);
			break;
		default: //improper input run again
			break;
		}
	}
}

