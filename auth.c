/*
use : Authentication
auth: L Fisher
date: 15 APR 2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auth.h"
#include "sha1.h"
#include "UI.h"

User doctors[5];
User nurses[5];
User patients[20];
User admins[2];


User* login_S(char* username, char* password)
{

	int i = 0;
	int k = 0;
	unsigned* hash = createToken_UP(username, password);

//Check Doctors
	for (i = 0; i < 5; i++)
		for (k = 0; k < 5; k++) {
			if (doctors[i]->hash[k] != hash[k]) break;
			if (k == 4) return &doctors[i];
		}

//Check Nurses
	for (i = 0; i < 5; i++)
		for (k = 0; k < 5; k++) {
			if (nurses[i]->hash[k] != hash[k]) break;
			if (k == 4) return &nurses[i];
		}

//Check Patients
	for (i = 0; i < 5; i++)
		for (k = 0; k < 5; k++) {
			if (patients[i]->hash[k] != hash[k]) break;
			if (k == 4) return &patients[i];
		}

//Check Admins
	for (i = 0; i < 5; i++)
		for (k = 0; k < 5; k++) {
			if (admins[i]->hash[k] != hash[k]) break;
			if (k == 4) return &admins[i];
		}

	printf("==INVALID CREDENTIALS==\n");
	return NULL;
}





void displayDoctorOptions_S(User* loggedUser)
{
	if (loggedUser->role == 1) displayDoctorOptions();
	else printf("== INVALID USER ==");

}

void displayNurseOptions_S(User* loggedUser)
{
	if (loggedUser->role == 2) displayNurseOptions();
	else printf("== INVALID USER ==");

}

void displayPatientOptions_S(User* loggedUser)
{
	if (loggedUser->role == 3) displayPatientOptions();
	else printf("== INVALID USER ==");

}

void displayAdminOptions_S(User* loggedUser)
{
	if (loggedUser->role == 4) displayAdminOptions();
	else printf("== INVALID USER ==");

}



unsigned createToken_U(User* user) {

	unsigned short i = 0;
	unsigned short count = 0;

	unsigned* authToken = malloc(sizeof(unsigned) * 5);
	for (i = 0; i < 5; i++)
		authToken[i] = 0;

	unsigned short userLen = 0;
	unsigned short passLen = 0;
	while (user->name[count++] != 0)
		userLen++;
	count = 0;
	while (user->pass[count++] != 0)
		passLen++;

	SHA1Context* u = malloc(sizeof(SHA1Context));
	SHA1Context* p = malloc(sizeof(SHA1Context));

	SHA1Reset(u);
	SHA1Input(u, user->name, userLen);
	SHA1Result(u);

	SHA1Reset(p);
	SHA1Input(p, user->pass, passLen);
	SHA1Result(p);

	for (i = 0; i < 5; i++)
		authToken[i] ^= u->Message_Digest[i];
	for (i = 0; i < 5; i++)
		authToken[i] ^= p->Message_Digest[i];


	return authToken;
}

unsigned createToken_UP(char* userString, char* passString) {

	unsigned short i = 0;
	unsigned short count = 0;

	unsigned* authToken = malloc(sizeof(unsigned) * 5);
	for (i = 0; i < 5; i++)
		authToken[i] = 0;

	unsigned short userLen = 0;
	unsigned short passLen = 0;
	while (userString[count++] != 0)
		userLen++;
	count = 0;
	while (passString[count++] != 0)
		passLen++;

	SHA1Context* u = malloc(sizeof(SHA1Context));
	SHA1Context* p = malloc(sizeof(SHA1Context));

	SHA1Reset(u);
	SHA1Input(u, userString, userLen);
	SHA1Result(u);

	SHA1Reset(p);
	SHA1Input(p, passString, passLen);
	SHA1Result(p);

	for (i = 0; i < 5; i++)
		authToken[i] ^= u->Message_Digest[i];
	for (i = 0; i < 5; i++)
		authToken[i] ^= p->Message_Digest[i];

	return authToken;
}

void addUsers() {
	doctors[0] = newUser("Doc0", "doc0", 000, 1);
	doctors[1] = newUser("Doc1", "doc1",  001, 1);

	nurses[0] = newUser("Nurse0", "nurs0", 002, 2);
	nurses[1] = newUser("Nurse1", "nurs1", 003, 2);

	patients[0] = newUser("Pat0", "pat0", 000, 3);
	patients[1] = newUser("Pat1", "pat1", 001, 3);
	patients[2] = newUser("Pat2", "pat2", 002, 3);

	admins[0] = newUser("Admin0", "admn0", 000, 4);
	admins[1] = newUser("Admin1", "admn1", 000, 4);
	return;
}

