#include <stdio.h>
#include "enclave.h"

int secret_key = 1;

void SFUNC encryption (char *text){
	for (int i = 0; text[i] != 0; i++ )
	    text[i] += secret_key;
        int tmp;
        asm volatile ("lwct ut, %0, (%1)\n"
                      : "=r"(tmp) : "r"(&secret_key) : "memory");
        asm volatile ("swct ut, n, %0, (%1)\n"
                      : "+r"(tmp) : "r"(&secret_key) : "memory");
	return;
}

void SFUNC decryption (char *text){
	for (int i = 0; text[i] != 0; i++ )
	    text[i] -= secret_key;
	return;
}

int main (){

	char text[] = "This is a demo for 12th National College Student Information Security Contest.";

	printf("Before secret data @ %p\n", &secret_key);
	add_data(&secret_key, sizeof(secret_key));
        
	printf("Before encryption: %s\n", text);
        printf("In this function, we set our secret key to normal tag\n", text);
	encryption (text);
	
	// Try to reuse the security data
	printf("The security data is: %x @ %p\n", secret_key, &secret_key);
	
        
	return 1;
}
