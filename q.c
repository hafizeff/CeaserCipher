// TODO1: add file header documentation!!!

/*!
@file   q.c
@author Hafiz (m.mohammadeffendi)
@course RSE
@section None
@tutorial Assignment 7
@date 29/10/2023
@brief This file contains the definitions of functions encrypt and decrypt.

*//*_______________________________________________________________________*/

#include "q.h" // included because q.c requires access to ASCII_COUNT

// TODO2: include other C standard library headers. for reasons 
// explained in previous assignments/labs, think carefully about 
// the need to add an include file before you do so ...

// TODO3: define functions encrypt and decrpyt ...

/*!
@brief This function encrypts the input characters using key.

@para key and input characters.
@return encrypted characters.

*//*______________________________________________________________________*/

void encrypt(int *letter, char key){
    
    int ASCII_letter = *letter;
    ASCII_letter += key;

    if(ASCII_letter > ASCII_COUNT){
        ASCII_letter -= ASCII_COUNT;
    }
    
    *letter = ASCII_letter;
}

/*!
@brief This function decrypts the input characters using key.

@para key and encrypted characters.
@return decrypted characters.

*//*______________________________________________________________________*/

void decrypt(int *letter, char key){
    
    int ASCII_letter = *letter;

    ASCII_letter -= key;
    if(ASCII_letter < 0){
        ASCII_letter += ASCII_COUNT;
    }
   
    *letter = ASCII_letter;
}
