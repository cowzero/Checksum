#include "checksum.h"

unsigned short cal_checksum(unsigned short* message, int len)
{

	unsigned int sum = 0;
	unsigned int sum_partial = 0;
	unsigned short checksum;

	for (int i = 0 ; i < len ; i++)
		sum += message[i];

	sum_partial = (0xffff & sum);

	printf("-----------Calculate checksum-----------\n");
	printf("sum(partial) : %x\n",sum_partial);
	printf("carry : %x\n", sum>>16);


	if(sum >> 16)
		sum = sum_partial + (sum >> 16);

	printf("sum : %x\n",sum);
	sum = (~sum & 0x0000ffff);

	checksum = (unsigned short)sum;
	printf("checksum : %x\n",checksum);
	printf("----------------------------------------\n\n");

	return checksum;
}

int check_checksum(unsigned short* message, int len)
{
	if(!cal_checksum(message,len))
		return 1;
	else
		return 0;
}

/*
unsigned short cal_checksum2(unsigned short* message)
{

	unsigned int sum = 0;
	unsigned short checksum;
	int i = 0;
	int len = 0;

	while(*(message+i) != NULL)
	{
		len++;
		i++;
	}

	printf("%x\n",*(message));
	printf("%x\n",*(message+1));
	printf("%x\n",*(message+2));
	printf("%x\n",*(message+3));

	if(*(message+4)==NULL)	printf("NULL\n");
	else	printf("not NULL\n");

	printf("len = %d\n",len);

	for (i = 0 ; i < len ; i++)
		sum += message[i];

	printf("sum(partial) : %x\n",sum);
	printf("carry : %x\n", sum>>16);


	if(sum >> 16)
		sum = (sum & 0xffff) + (sum >> 16);

	sum = ~sum;
	printf("sum : %x\n",sum);

	checksum = (unsigned short)(sum & 0x0000ffff);
	printf("checksum : %x\n",checksum);

	return checksum;
}
*/
