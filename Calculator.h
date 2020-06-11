#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef int*  Binario;
typedef char* FloatBinario;


char parseChar(int val)
{
	return val + '0';
}

//definindo um numero binario como um vetor de int
Binario inicializa_bin(int bit_size)
{
	Binario temp;
	temp = (Binario) malloc(sizeof(int) * bit_size);
	return temp;
}


//funcao que printa um numero binario
void printa_bin(Binario num, int max_bits)
{
	int i = 0;
	for(i ; i < max_bits; i++)
	{
		printf("%d", num[i]);
	}
}

//funcao que converte um numero decimal em um numero binario
Binario converte_bin(int decimal, int max_bits)
{
	int i = max_bits - 1;
	int rest;
	Binario index = (Binario) malloc(sizeof(int) * max_bits);
		
	for(i;i >= 0; i--)
	{
		if(decimal%2 == 0)
		{
			index[i] = 0;
		}
		else
		{
			index[i] = 1;
		}
		decimal /= 2;
	}	
//	inverte_num(index, max_bits);
	return index;
}



FloatBinario converte_float_bin(float numero, int max_bits, int mantissa_bits)
{
	int _inteiro = numero;
	float _decimal = numero - _inteiro;
	
	int size_binario_decimal = max_bits + mantissa_bits + 1;
	FloatBinario novo = (char*) malloc(sizeof(char) * size_binario_decimal); 
	if(numero < 0)
	{
		strcpy(novo, "1");
		numero *= -1;
	}else
	{
		strcpy(novo, "0");
	}
	
	
	Binario parte_inteira = converte_bin(_inteiro,max_bits);
	Binario parte_decimal = inicializa_bin(mantissa_bits);
	int i = 0;
	int aux;
	
	for(i = 0; i < mantissa_bits; i++)
	{
		_decimal *= 2;
		aux = _decimal;
		parte_decimal[i] = aux;	
		_decimal = _decimal - aux;
	}
	
	FloatBinario auxiliar = (char*) malloc(sizeof(char) * size_binario_decimal); 
	for(i = 0; i < max_bits; i++)
	{
		auxiliar[i] = parseChar(parte_inteira[i]);
	}
	i++;
	auxiliar[i] = ',';
	for(i; i < mantissa_bits; i++)
	{
		auxiliar[i] = parseChar(parte_decimal[i]);
	}
	
	strcat(novo, auxiliar);
	return novo;
}



void printa_float_bin(char* elem)
{
	int i = 0;
	
	for(i; i < strlen(elem); i++)
	{
		printf("%c ", elem[i]);
	}
}








#endif
