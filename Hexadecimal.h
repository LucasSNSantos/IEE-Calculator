#ifndef HEXADECIMAL_H
#define HEXADECIMAL_H
#include<string.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


typedef char* Hexadecimal;



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


char* acrescenta_zeros (char* binario)
{
	char* novo_numero;
	int n_size = strlen(binario) + 1;
	novo_numero = (char*) malloc(sizeof(char) * n_size);
	strcpy(novo_numero,"0");
	strcat(novo_numero,binario);
	return novo_numero;
}


Hexadecimal converte_bin_hexa(char* bin)
{
	int tamanho = strlen(bin);
	char aux[4];
	int count_aux = 0;
	if(tamanho%4 != 0)
	{
		while(tamanho%4 != 0)
		{
			bin = acrescenta_zeros(bin);
			tamanho = strlen(bin);
		}
	}
	int i;
	int aux_index = 0;
	int index = 0;
	char* hexa = (char*) malloc(sizeof(char) * (tamanho/4) ); 
	for(i = tamanho - 1; i >= 0; i--)
	{
		aux[aux_index] = bin[i];
		if(aux_index < 3)
		{
			aux_index++;
		}else
		{
			strrev(aux);
			hexa[index] = hexa_convert(aux);
			index++;
			aux_index = 0;
		}
	}
	strrev(hexa);
	return hexa;
}












#endif
