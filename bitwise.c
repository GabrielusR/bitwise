#include <stdio.h>
#include <stdint.h>

#include "dbg.h"

uint8_t is_in_use(uint8_t byte, int bit)
{
	return  ( byte & (1<<bit) );
}

void set_in_use(uint8_t *byte, int bit)
{
	*byte |= (1<<bit);
}

void set_unused(uint8_t *byte, int bit)
{
	*byte &= ~(1<<bit);
}

void flip_bit(uint8_t *byte, int bit)
{
	*byte ^= (1<<bit);
}

int main (int argc, char *argv[])
{
	uint8_t byte = 0;	
	uint8_t bit = 0;

	printf("Enter a number: ");
	scanf("%hhu", &byte);
		
	printf("byte: %08b\n\n", byte);

	while(bit != 8){
		
		printf("Enter a bit (or 8 to quit): ");
		scanf("%hhu", &bit);

		TEST( (bit >= 0 && bit <= 8), "Number entered is invalid" );
		
		/*
		 
		if( is_in_use(byte, bit) ){
			printf("Bit in use. Setting bit down.\n\n");
			set_unused(&byte, bit);
		} else {
			printf("Bit not in use. Setting bit up.\n\n");
			set_in_use(&byte, bit);
		}
				OR

			We can just do... flip_bit
		*/	

		flip_bit(&byte, bit);

		printf("byte: %08b\n\n", byte);
	}

	printf("byte decimal: %d \n", byte);

	return 0;
}
