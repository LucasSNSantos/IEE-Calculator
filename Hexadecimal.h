#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#include<string.h>
#include<stdlib.h>
#include<string.h>


typedef char* Hexadecimal;


split(4);

Hexadecimal converte_bin_hexa(Binario bin)
{
	int tamanho = strlen(bin);
	if(tamanho%4 == 0)
	{
		
	}else
	{
		
	}
	
	
}





char hexa_convert(char* binario)
{
	if(!strcmp(binario,"0001")) return '1';
	if(!strcmp(binario,"0010")) return '2';
	if(!strcmp(binario,"0011")) return '3';
	if(!strcmp(binario,"0100")) return '4';
	if(!strcmp(binario,"0101")) return '5';
	if(!strcmp(binario,"0110")) return '6';
	if(!strcmp(binario,"0111")) return '7';
	if(!strcmp(binario,"1000")) return '8';
	if(!strcmp(binario,"1001")) return '9';
	if(!strcmp(binario,"1010")) return 'A';
	if(!strcmp(binario,"1011")) return 'B';
	if(!strcmp(binario,"1100")) return 'C';
	if(!strcmp(binario,"1101")) return 'D';
	if(!strcmp(binario,"1110")) return 'E';
	if(!strcmp(binario,"1111")) return 'F';	
	return '0';
}















#endif
