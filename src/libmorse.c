/*
 * morse.c
 *
 *  Created on: 19 Feb 2013
 *      Author: noel
 */

#include <stdio.h>
#include <string.h>
#include "libmorse.h"


unsigned char morse[43] = {
                                                0b10111111, // 0
                                                0b10101111, // 1
                                                0b10100111, // 2
                                                0b10100011, // 3
                                                0b10100001, // 4
                                                0b10100000, // 5
                                                0b10110000, // 6
                                                0b10111000, // 7
                                                0b10111100, // 8
                                                0b10111110, // 9
                                                0b00000000, // :
                                                0b00000000, // ;
                                                0b00000000, // <
                                                0b00000000, // =
                                                0b00000000, // >
                                                0b00000000, // ?
                                                0b00000000, // @
                                                0b01001000, // A
                                                0b10010000, // B
                                                0b10010100, // C
                                                0b01110000, // D
                                                0b00100000, // E
                                                0b10000100, // F
                                                0b01100100, // G
                                                0b10000000, // H
                                                0b01000000, // I
                                                0b10001110, // J
                                                0b01110100, // K
                                                0b10001000, // L
                                                0b01011000, // M
                                                0b01010000, // N
                                                0b01111100, // O
                                                0b10001100, // P
                                                0b10011010, // Q
                                                0b01101000, // R
                                                0b01100000, // S
                                                0b00110000, // T
                                                0b01100100, // U
                                                0b10000010, // V
                                                0b01101100, // W
                                                0b10010010, // X
                                                0b10010110, // Y
                                                0b10011000  // Z

};


extern void sendMessage(char *msg) {


	int i=0;



	/*
	 * Iterate through ascii char set from 0 (at 0x30) to Z (at 0x5A) to print out alphabet
	 *
	 * Don't forget that characters have to be cast to the morse array by -0x30h from them
	 *
	 * unsigned char compound = morse[(i-0x30)];
	 *
	 * */

	for(i=0;i<strlen(msg);i++) {

		/* Retieve the morse character that represents the msg[i] message character */
		/* -0x30 to rebase the char to the morse range  as 0 = character 0x30, 1 = character 0x31 etc..*/
	    unsigned char compound = morse[(unsigned int)msg[i]-0x30];


		/*
		 * Shift 5 to the right to leave most significant 3 bits
		 * This reveals the length in morse elements of the letter
		 * */
		unsigned int element_length = compound >> 5;


		/*
		 * To start processing the morse elements,
		 * shift off the 3 msb to get rid of the length info
		 */
		compound = compound << 3;

		printf("ID [%i] Len [%i]: ",i,element_length);

		/* Iterate through the number of morse elements */
		int j = 0;
		for(j=0;j<element_length;j++) {
			/* if MSB is a 1 (i.e.num >= 127) then it's a DAH */
			if(compound >= 127) {
				printf("_");
			} else {
				printf(".");
			}
			/* Shift morse character to the left, and if more chars loop */
			compound = compound << 1;

		}
		printf("\n");

	}
}



