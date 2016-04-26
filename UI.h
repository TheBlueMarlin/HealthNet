/*
 * File:   UI.h
 * Author: marlin
 *
 * Created on April 17, 2016, 12:42 AM
 */

#ifndef UI_H
#define	UI_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct
{
	char name[30];
	char pass[5];
	int ID;
	unsigned int hash[5];
	int role;
} User;

User newUser(char[], char[], int, int);

void printUsers(User[]);

/*
 * The displayDoctorOptions function handles the display of all options avaliable
 */
void displayDoctorOptions();

/*
 */
void displayNurseOptions();

/*
 */
void displayPatientOptions();

/*
 */
void displayAdminOptions();

#ifdef	__cplusplus
}
#endif

#endif	/* UI_H */

