// TODO1: provide file header documentation

/*!
@file   q.h
@author Hafiz (m.mohammadeffendi)
@course RSE
@section None
@tutorial Assignment 7
@date 29/10/2023
@brief This file contains the declarations of functions, encrypt and decrypt

*//*_______________________________________________________________________*/

#ifndef Q_H
#define Q_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Don't remove!!!
// We're limiting ASCII set to the basic character set
// with encoding from 0 to 127
#define ASCII_COUNT 128

// TODO2: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function encrypt
// TODO3: declaration for function encrypt

/*!
@brief This function encrypts the input characters using key.

@para key and input characters.
@return encrypted characters.

*//*______________________________________________________________________*/

void encrypt(int *letter, char key);

// TODO4: your clients will be given this header file since they
// will have no access to the definitions of functions
// encrypt and decrypt - therefore, provide header documentation
// for function decrypt
// TODO5: declaration for function decrypt

/*!
@brief This function decrypts the input characters using key.

@para key and encrypted characters.
@return decrypted characters.

*//*______________________________________________________________________*/


void decrypt(int *letter, char key);

#endif // Q_H
