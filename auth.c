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

	unsigned authToken[5] = {0, 0, 0, 0, 0};
	int i = 0;

	int count = 0;

	char* userString = "Lance Fisher";
	char* passString = "Test123$%^";

	unsigned userLen = 0;
	unsigned passLen = 0;
	while (userString[count++] != 0) userLen++;
	count = 0;
	while (passString[count++] != 0) passLen++;

	SHA1Context* p = malloc(sizeof(SHA1Context));


	printf("%20s", "USER HASH : ");
	SHA1Reset(p);
	SHA1Input(p, userString, userLen);
	SHA1Result(p);
	for (i = 0; i < 5; i++)
		printf("%08X ", p->Message_Digest[i]);
	printf("\n");
	for (i = 0; i < 5; i++) authToken[i] ^= p->Message_Digest[i];


	printf("%20s", "PWD HASH : ");
	SHA1Reset(p);
	SHA1Input(p, passString, passLen);
	SHA1Result(p);
	for (i = 0; i < 5; i++)
		printf("%08X ", p->Message_Digest[i]);
	printf("\n");
	for (i = 0; i < 5; i++) authToken[i] ^= p->Message_Digest[i];


	printf("%20s", "AUTH TOKEN (XOR) : ");
	for (i = 0; i < 5; i++)
		printf("%08X ", authToken[i]);
	printf("\n");
}

