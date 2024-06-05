// TODO1: Add file header documentation ...

/*!
@file   qdriver.c
@author Hafiz (m.mohammadeffendi)
@course RSE
@section None
@tutorial Assignment 7
@date 29/10/2023
@brief This file contains main which recieves file to be encrypted or decrypted. 

*//*_______________________________________________________________________*/



#include "q.h"			// encrypt and decrypt function declarations
#include <stdio.h>
#include <math.h>
#include <stdlib.h> // TODO2: Add necessary C standard library headers ...

char keytext[200];
int counter=0, input=0;
size_t keylength=0;

int main(void) {
#ifdef ENCRYPT

	// TODO3: read characters from input file plain.txt and write the
	// corresponding encrypted characters to output file cipher.txt
	// using the keyword in file key.txt

	FILE *inputxt=fopen("plain.txt","r");
	FILE *keyfile=fopen("key.txt","r");
	FILE *outputfile=fopen("cipher.txt","w");

	if (keyfile == NULL){ fprintf(stderr, "Unable to open file key.txt\n"); return 0;}			
	if (inputxt == NULL){ fprintf(stderr, "Unable to open file plain.txt\n"); return 0;}		
	if (outputfile == NULL){ fprintf(stderr, "Unable to open file cipher.txt\n"); return 0;}	

	

	if(fgets(keytext, sizeof(keytext), keyfile) != NULL )
	{
		keylength = strlen(keytext)-1;
	}
	
	while((input = getc(inputxt)) !=EOF)
	{
		encrypt(&input,keytext[counter++]);
		fputc(input,outputfile);

		if(counter == (int)keylength)
		{
			counter=0;
		}

	}
	

	fclose(inputxt);
	fclose(keyfile);
	fclose(outputfile);

	return 0;



#else

	// TODO4: read characters from input file cipher.txt and write the
	// corresponding decrypted characters to output file out-plain.txt
	// using the keyword in file key.txt
	// TODO5: write count of words into stderr


	FILE *inputxt=fopen("cipher.txt","r");
	FILE *keyfile=fopen("key.txt","r");
	FILE *outputfile=fopen("out-plain.txt","w");

	if (keyfile == NULL){ fprintf(stderr, "Unable to open file key.txt\n"); return 0;}			
	if (inputxt == NULL){ fprintf(stderr, "Unable to open file plain.txt\n"); return 0;}		
	if (outputfile == NULL){ fprintf(stderr, "Unable to open file cipher.txt\n"); return 0;}	

	
	if(fgets(keytext, sizeof(keytext), keyfile))
	{
		keylength = strlen(keytext)-1;
	}
	
	while((input = getc(inputxt)) !=EOF)
	{
		decrypt(&input,keytext[counter++]);
		fputc(input,outputfile);

		if(counter == (int)keylength)
		{
			counter=0;
		}

	}
	

	fclose(inputxt);
	fclose(keyfile);
	fclose(outputfile);

	FILE *alarmfil = fopen("out-plain.txt", "r");								
		
		int ch, wcont = 0, chck = 0;
		
		while((ch = fgetc(alarmfil)) != EOF){										
			if (ch == 9 || ch == 10 || ch == 13 || ch == 32) {						
				chck = 0;
			}
			else if (!chck) {
				chck = 1;
				wcont++;
			}
		}
		fprintf(stderr,"Words: %d\n", wcont);									
		fclose(alarmfil);
		return 0;

#endif

	return 0;
}
