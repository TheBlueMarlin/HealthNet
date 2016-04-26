/*
 * File:   healthNetDriver.c
 * Author: marlin, fisher
 *
 * Created on April 24, 2016, 10:07 PM
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "auth.h"

void addUsers();

void displayLogin();


//***NOTE!!***: for an actual implementation a dynamic allocation would be required
User doctors[5];
User patients[20];
User admins[2];

User* currentUser;
/*
 *
 */
int main(int argc, char** argv)
{
	int done = -1;
	addUsers();
	displayLogin();
	while(done < 0)
	{
		switch((*currentUser).role)
		{
		case 0: //NO login detected login should FAIL
			printf("Invalid login status detected: terminating program");
			break;
		case 1: //Doctors case:
			displayDoctorOptions();
			break;
		case 2:
			displayPatientOptions();
			break;
		case 3:
			displayAdminOptions();
			break;
		default:
			printf("Invalid login status detected: terminating program");
			exit(1);
			break;
		}
	}
	return (EXIT_SUCCESS);
}



void displayLogin()
{
	char userName[6];
	char password[6];
	printf("Please enter Username: ");
	s_fget(userName);
	printf("\nEnter Password: ");
	s_fget(password);
	currentUser = login_S((unsigned char*)userName, (unsigned char*)password);
	if(currentUser == NULL)
	{
		printf("Invalid login. \n");
		displayLogin();
	}
}



