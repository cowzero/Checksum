#include <stdio.h>
#include "checksum.h"

void main()
{
	unsigned short message[] = {0x466f,0x726f,0x757a,0x616e,0x0000};
	int len = sizeof(message)/sizeof(unsigned short);

	printf("-------------Before checksum------------\n");
	for(int i = 0 ; i < len ; i++)
		printf("%x\n",message[i]);
	printf("----------------------------------------\n\n");
	
	message[len-1] = cal_checksum(message,len);
	
	printf("--------------After checksum------------\n");
	for(int i = 0 ; i < len ; i++)
		printf("%x\n",message[i]);
	printf("----------------------------------------\n\n");

	if(check_checksum(message,len))
		printf("no error\n");
	else
		printf("error detected\n");
}
