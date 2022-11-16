#include "xil_io.h"
#include "xparameters.h"

//***************************
//READ AND WRITE TO STATE REG
//***************************
//Write state register
void writeState(int loc, u64 hex){
	if(loc >= 0 && loc <= 4)
		Xil_Out64(XPAR_BRAM_0_BASEADDR + (loc * 8), hex);
}

//Read state register
u64 readState(int loc){
	u64 data;
	if(loc >= 0 && loc <= 4)
		data = Xil_In64(XPAR_BRAM_0_BASEADDR + (loc * 8));
	return data;
}

//***************************
//READ AND WRITE TO KEY REG
//***************************
//Write key register
void writeKey(int loc, u64 hex){
	if(loc >= 0 && loc <= 1)
		Xil_Out64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 40, hex);
}

//Read key register
u64 readKey(int loc){
	u64 data;
	if(loc >= 0 && loc <= 1)
		data = Xil_In64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 40);
	return data;
}

//***************************
//READ AND WRITE TO NONCE REG
//***************************
//Write nonce register
void writeNonce(int loc, u64 hex){
	if(loc >= 0 && loc <= 1)
		Xil_Out64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 56, hex);
}

//Read nonce register
u64 readNonce(int loc){
	u64 data;
	if(loc >= 0 && loc <= 1)
		data = Xil_In64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 56);
	return data;
}

//***************************
//READ AND WRITE TO PLAINTEXT REG
//***************************
//Write plain text register
void writePlainTxt(int loc, u64 hex){
	if(loc >= 0 && loc <= 1)
		Xil_Out64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 72, hex);
}
//Read plain text register
u64 readPlainTxt(int loc){
	u64 data;
	if(loc >= 0 && loc <= 1)
		data = Xil_In64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 72);
	return data;
}

//***************************
//READ AND WRITE TO CIPHER REG
//***************************
//Write cipher register
void writeCipher(int loc, u64 hex){
	if(loc >= 0 && loc <= 1)
		Xil_Out64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 88, hex);
}
//Read cipher register
u64 readCipher(int loc){
	u64 data;
	if(loc >= 0 && loc <= 1)
		data = Xil_In64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 88);
	return data;
}

//***************************
//READ AND WRITE TO TAG REG
//***************************
//Write cipher register
void writeTag(int loc, u64 hex){
	if(loc >= 0 && loc <= 1)
		Xil_Out64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 104, hex);
}
//Read cipher register
u64 readTag(int loc){
	u64 data;
	if(loc >= 0 && loc <= 1)
		data = Xil_In64(XPAR_BRAM_0_BASEADDR + (loc * 8) + 104);
	return data;
}


//print method for 64 bit hex
void printData(u64 data){
	printf("%016llX\n",data);
}


//print state register
void printState(){
	u64 x;
	for(int i = 0; i < 5; i++){
		x = readState(i);
		printData(x);
	}
}

//print cipher register
void printCipher(){
	u64 x;
	for(int i = 0; i < 2; i++){
		x = readCipher(i);
		printData(x);
	}
}

//print tag register
void printTag(){
	u64 x;
	for(int i = 0; i < 2; i++){
		x = readTag(i);
		printData(x);
	}
}
