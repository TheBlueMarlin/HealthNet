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
	unsigned char name[5];
	unsigned char pass[5];
	int ID;
	unsigned int* hash;
	int role;
} User;

User newUser(unsigned char[], unsigned char[], int, int);

void printUsers(User[]);

/*
 * The displayDoctorOptions function handles the display of all options avaliable
 */
void displayDoctorOptions();


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

