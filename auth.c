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

int main() {

	UserList list;

	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));
	addUser(&list, createUserP("lfisher", "12345%%^Fg"));




	return 0;
}

void addUser(UserList* list, User* user) {
	if (list->head == 0)
		list->head = user;
	else
		addUserR(list->head->next, user);

}

void addUserR(User * p, User * user) {

	if (p->next == 0)
		p->next = user;
	else
		addUserR(p->next, user);

}

User* createUserP(char* userString, char* passString) {
	User* newUser = malloc(sizeof(User));
	newUser->userName = userString;
	newUser->authToken = createToken(userString, passString);
	newUser->next = 0;
	return newUser;
}

User* createUserT(char* userString, unsigned* authToken) {
	User* newUser = malloc(sizeof(User));
	newUser->userName = userString;
	newUser->authToken = authToken;
	newUser->next = 0;
	return newUser;
}

unsigned* createToken(char* userString, char* passString) {

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

	/*
	 printf("%20s", "USER HASH : ");
	 for (i = 0; i < 5; i++)
	 printf("%08X ", u->Message_Digest[i]);
	 printf("\n");

	 printf("%20s", "PWD HASH : ");
	 for (i = 0; i < 5; i++)
	 printf("%08X ", p->Message_Digest[i]);
	 printf("\n");

	 printf("%20s", "AUTH TOKEN (XOR) : ");
	 for (i = 0; i < 5; i++)
	 printf("%08X ", authToken[i]);
	 printf("\n");
	 */

	return authToken;
}
int main() {

	UserList list;



	return 0;
}

int addUser(UserList* list, User* user) {
	if (list->head == 0) {
		list->head = user;
		return list;
	} else {
		return addUser(list->head->next, user);
	}
}

int addUser(User * p, User * user) {

	if (p->next == 0) {
		p->next == user;
		return 0;
	} else {
		return addUser(p->next, user);
	}
}



User* createUser(char* userString, char* passString) {
	User* newUser = malloc(sizeof(User));
	newUser->userName = userString;
	newUser->authToken =  createToken(userString, passString);
	newUser->next = 0;
	return newUser;
}

User* createUser(char* userString, unsigned* authToken) {
	User* newUser = malloc(sizeof(User));
	newUser->userName = userString;
	newUser->authToken =  authToken;
	newUser->next = 0;
	return newUser;
}

unsigned* createToken(char* userString, char* passString) {

	unsigned short i = 0;
	unsigned short count = 0;

	unsigned* authToken = malloc(sizeof(unsigned) * 5);
	for (i = 0; i < 5; i++)authToken[i] = 0;

	unsigned short userLen = 0;
	unsigned short passLen = 0;
	while (userString[count++] != 0) userLen++;
	count = 0;
	while (passString[count++] != 0) passLen++;

	SHA1Context* u = malloc(sizeof(SHA1Context));
	SHA1Context* p = malloc(sizeof(SHA1Context));

	SHA1Reset(u);
	SHA1Input(u, userString, userLen);
	SHA1Result(u);

	SHA1Reset(p);
	SHA1Input(p, passString, passLen);
	SHA1Result(p);

	for (i = 0; i < 5; i++) authToken[i] ^= u->Message_Digest[i];
	for (i = 0; i < 5; i++) authToken[i] ^= p->Message_Digest[i];

	/*
		printf("%20s", "USER HASH : ");
		for (i = 0; i < 5; i++)
			printf("%08X ", u->Message_Digest[i]);
		printf("\n");

		printf("%20s", "PWD HASH : ");
		for (i = 0; i < 5; i++)
			printf("%08X ", p->Message_Digest[i]);
		printf("\n");

		printf("%20s", "AUTH TOKEN (XOR) : ");
		for (i = 0; i < 5; i++)
			printf("%08X ", authToken[i]);
		printf("\n");
	*/

	return authToken;
}
