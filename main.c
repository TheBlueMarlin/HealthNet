/*
 * main.c
 *COMMAND LINE: Input the following command to run this program on the rose machine.

gcc -o (output name) (file name).c -lcrypto

 *  Created on: Apr 19, 2016
 *      Author: Batgirl
 */
#include <stdio.h>
#include <openssl/sha.h>
#include <string.h>
/*
print_hash()
Can be used for file I/O
Prints out the pointer value to standard i/o.
*/
void print_hash( const unsigned char* c)
{
	printf("The hash is: ");
	int index = 0;
	for (index = 0; index < SHA_DIGEST_LENGTH; index++)
	{
		printf("%X", *c++);//%X is used to print out the value of a pointer
	}
	printf("\n");
}

/*
create_key()
Takes two character arrays and converts each character array into a hash. Then takes both hashes to create a key.
Implementation: Use the print_hash function to write the key to memory (file i/o). There is no data storage in this function. Only use this function to create/verify the key.
WARNING: Does not account for the length of the user name/password. Verify input prior would not exceed 50 per array.
*/
void create_key(unsigned char* user, unsigned char* pw)
{
	//variables
	unsigned char uHash[SHA_DIGEST_LENGTH];//The hash of the user name
	unsigned char pHash[SHA_DIGEST_LENGTH];//The hash of the password
	unsigned char key[SHA_DIGEST_LENGTH * 2 + 1]; //The hash of the combination of

	//Functions to calculate hash
	SHA1(user, strlen((char*)user), uHash);
	SHA1(pw, strlen((char*)pw), pHash);

	//Adding both hashes to the same character array to create key
	printf("Your Hash key is: ");
	int index = 0;
	int index2 = 0;
	for (index = 0; index < SHA_DIGEST_LENGTH; index++)
	{
		key[index] = uHash[index];
		printf("%X", key[index]);
	}
	for (index2 = 0; index2 < SHA_DIGEST_LENGTH; index2++)
	{
		key[index] = pHash[index2];
		printf("%X", key[index]);
		index++;
	}
	key[index] = '\0';
	printf("\n");

}







/*Test case

int main(int argc, char* argv[])
{
	unsigned char user[25];//string for the user name
	unsigned char pw[25];//string for the password

	scanf("%s", user);//input into the char array
	scanf("%s", pw);//input into the char array

	create_key(user, pw);
}

*/