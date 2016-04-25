#ifndef _AUTH_H
#define _AUTH_H

typedef struct User {

	char* userName;
	unsigned* authToken;
	struct User* next;
} User;

typedef struct UserList {

	struct User* head;

} UserList;

unsigned* createToken(char*, char*);
User* createUserP(char*, char*);
User* createUserT(char*, unsigned*);
void addUser(UserList*, User*);
void addUserR(User*, User*);

#endif
