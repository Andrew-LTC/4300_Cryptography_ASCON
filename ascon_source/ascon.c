#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"
#include "ascon_methods_64bit.h"

u64 IV = 0x80400c0600000000;
u64 consts[12] = {
		0xf0, 0xe1, 0xd2, 0xc3, 0xb4, 0xa5,
		0x96, 0x87, 0x78, 0x69, 0x5a, 0x4b
		};

//PRIMITIVES
void linearDiff(){
	u64 t0, t1;

	//read 64 bit values from state register and put them into an array
	u64 state[5] = {0};
	for(int i = 0; i < 5; i++)
		state[i] = readState(i);

	//diffuse state 0
	t0 = state[0] >> 19;
	t1 = state[0] >> 28;
	state[0] ^= t0 ^ t1;

	//diffuse state 1
	t0 = state[1] >> 61;
	t1 = state[1] >> 39;
	state[1] ^= t0 ^ t1;

	//diffuse state 2
	t0 = state[2] >> 1;
	t1 = state[2] >> 6;
	state[2] ^= t0 ^ t1;

	//diffuse state 3
	t0 = state[3] >> 10;
	t1 = state[3] >> 17;
	state[3] ^= t0 ^ t1;

	//diffuse state 4
	t0 = state[4] >> 7;
	t1 = state[4] >> 41;
	state[4] ^= t0 ^ t1;

	//write new states into state register
	for(int i = 0; i < 5; i++)
		writeState(i, state[i]);

}
void sbox(){
	u64 t[5] = {0};
	u64 x[5] = {0};

	//read 64 bit values from state register and put them into an array
	for(int i = 0; i < 5; i++)
		x[i] = readState(i);

	//taken from ascon specification
	x[0] ^= x[4]; x[4] ^= x[3]; x[2] ^= x[1];
	t[0] = x[0]; t[1] = x[1]; t[2] = x[2]; t[3] = x[3]; t[4] = x[4];
	t[0] =~ t[0]; t[1] =~ t[1]; t[2] =~ t[2]; t[3] =~ t[3]; t[4] =~ t[4];
	t[0] &= x[1]; t[1] &= x[2]; t[2] &= x[3]; t[3] &= x[4]; t[4] &= x[0];
	x[0] ^= t[1]; x[1] ^= t[2]; x[2] ^= t[3]; x[3] ^= t[4]; x[4] ^= t[0];
	x[1] ^= x[0]; x[0] ^= x[4]; x[3] ^= x[2]; x[2] =~ x[2];

	//write new states into state register
	for(int i = 0; i < 5; i++)
		writeState(i, x[i]);
}
void addConst(int rounds, int offset){
	//constant is added to the middle word
	u64 state2 = readState(2);

	//xor constant value with middle word
	state2 ^= consts[12 - offset + rounds];

	//rewrite middle word value
	writeState(2,state2);
}
void permutations(int rounds){
	for(int i = 0; i < rounds; i++){
		addConst(i, rounds);
		sbox();
		linearDiff();
	}
}

//MODES
void initialization(){
	//concatenate IV, Key, and Nonce for initial internal state
	writeState(0,IV);
	writeState(1,readKey(0));
	writeState(2,readKey(1));
	writeState(3,readNonce(0));
	writeState(4,readNonce(1));

	//perform 12 rounds of permutations
	permutations(12);

	//xor the key value to the last two words of the state
	writeState(3, readKey(0) ^ readState(3));
	writeState(4, readKey(1) ^ readState(4));
}
void encryption(){
	writeCipher(0,readPlainTxt(0) ^ readState(0));
	for(int i = 0; i < 2; i++){
		permutations(6);
		writeCipher(i, readPlainTxt(i) ^ readState(0));
		writeState(0,readCipher(i));
	}
}
void finalization(){
	writeState(0, readState(0) ^ readKey(0));
	writeState(1, readState(1) ^ readKey(1));
	permutations(12);

	writeTag(0, readState(3) ^ readKey(0));
	writeTag(1, readState(4) ^ readKey(1));
}

//MAIN
int main(){
	init_platform();

	u64 Key[2] = {0};
	u64 Nonce[2] = {0};
	u64 PlainText[2] = {0x0123456789abcedf, 0x82187};

	for(int i = 0; i < 2; i++){
		writeKey(i,Key[i]);
		writeNonce(i, Nonce[i]);
		writePlainTxt(i,PlainText[i]);
	}

	initialization();

	printf("Initialization\n");
	printState();

	encryption();

	printf("Encryption\n");
	printCipher();

	finalization();

	printf("Tag\n");
	printTag();

	cleanup_platform();
	return 0;
}
