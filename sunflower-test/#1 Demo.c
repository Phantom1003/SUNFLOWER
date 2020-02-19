#include <stdio.h>
#include "enclave.h"

int secret_key = 1;

void SFUNC encryption (char *text){
	for (int i = 0; text[i] != 0; i++ )
	    text[i] += secret_key;
	return;
}


void SFUNC decryption (char *text){
	for (int i = 0; text[i] != 0; i++ )
	    text[i] -= secret_key;
	return;
}


int main (){

	char text[] = "This is a demo for 12th National College Student Information Security Contest.";

	printf("Add secret data\n");
	add_data(&secret_key, sizeof(secret_key));
	
	printf("Before encryption: %s\n", text);
	encryption (text);
	printf("After encryption:  %s\n", text);
	decryption (text);
	printf("After decryption:  %s\n", text);
        
	return 1;
}

