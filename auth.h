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
User* createUser(char*, char*);
User* createUser(char*, unsigned*);
int addUser(UserList*, User*);
int addUser(User* , User*);



#endif