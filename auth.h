#ifndef _AUTH_H
#define _AUTH_H





unsigned* createToken(char*, char*);
unsigned* createToken_UP(unsigned char*, unsigned char*);
void addUsers();
User* login_S(unsigned char*, unsigned char*);
char* s_fget(char*);


#endif

