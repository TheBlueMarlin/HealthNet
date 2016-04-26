/*
 * File:   main.c
 * Author: marlin
 *
 * Created on April 26, 2016, 2:46 AM
 */

#include <stdio.h>
#include <stdlib.h>

void create(char*, char*);
void append();
void read();

/*
 *

int main( int argc, char** argv )
	{
	char fileName[4] = "test";
	char fileType[3] = "med";
	char name[11] = "testmed.txt";
	create( fileName, fileType );
	append( name );
	return ( EXIT_SUCCESS );
	}
*/

void create(char* fname, char* ftype)
{
	char fileName[11] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
	char ext[4] = ".txt";
	strncat(fileName, fname, 4);
	strncat(fileName, ftype, 3);
	strncat(fileName, ext, 4);
	fprintf(stderr, "%s", fileName);
	FILE* fout = fopen(fileName, "a");
	fprintf(fout, "%s", "fuck this shit\n");
	fclose(fout);
}


void append(char* fname)
{
	FILE* fout = fopen(fname, "a");
	fprintf(fout, "%s", "fuck all of this shit\n");
	fclose(fout);
}

