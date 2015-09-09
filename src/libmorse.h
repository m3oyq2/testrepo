/*
 * morse.h
 *
 *  Created on: 18 Feb 2013
 *      Author: noel
 */

#ifndef _MORSE_H_
#define _MORSE_H_


/*
 *
 * A ._			P .__.		1 .____
 * B _...		Q __._		2 ..___
 * C _._.		R ._.		3 ...__
 * D _..		S ...		4 ...._
 * E .			T _		5 .....
 * F .._.		U .._		6 _....
 * G __.		V ..._		7 __...
 * H ....		W .__		8 ___..
 * I ..			X _.._		9 ____.
 * J .___		Y _.__		0 _____
 * K _._		Z __..
 * L ._..
 * M __
 * N _.
 * O ___
 *
 *
 * Dit 				= 1
 * Dah 				= 3
 * space between elements 	= 2
 * space between chars 		= 3
 * space between words		= 7
 */

/* How to store morse */

/*
 * first three bits of byte are length, last 5 bits are morse code
 * and a dit is a 0 and a dah is a 1
 *
 * A = 01001000		P = 10001100
 * B = 10010000		Q = 10011010
 * C = 10010100		R = 01101000
 * D = 01110000		S = 01100000
 * E = 00100000		T = 00110000
 * F = 10000100		U = 01100100
 * G = 01100100		V = 10000010
 * H = 10000000		W = 01101100
 * I = 01000000		X = 10010010
 * J = 10001110		Y = 10010110
 * K = 01110100		Z = 10011000
 * L = 10001000		1 = 10101111
 * M = 01011000		2 = 10100111
 * N = 01010000		3 = 10100011
 * O = 01111100		4 = 10100001
 * 			5 = 10100000
 * 			6 = 10101111
 * 			7 = 10100111
 * 			8 = 10100011
 * 			9 = 10100001
 * 			0 = 10100000
 */


/* Functions */

extern void sendMessage(char *msg);



#endif /* _MORSE_H_ */
