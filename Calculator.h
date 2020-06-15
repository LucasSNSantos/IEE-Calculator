#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

typedef char*  Binario;
typedef char* FloatBinario;
typedef int Sinal;

typedef struct numero{
	Sinal sinal;
	Binario parteInteira;// parte inteira do numero
	FloatBinario parteDecimal;//parte decimal
} Numero;

printa_numero(Numero num, int bits, int mantissa)
{
	int aux = bits;
	printf("%d   ", num.sinal);
	int i = 0;
	for(i; i < aux; i++)
	{
		printf("%c", num.parteInteira[i]);
	}
	
	printf(" , ");
	aux = mantissa;
	for(i = 0; i < aux; i++)
	{
		printf("%c", num.parteDecimal[i]);
	}
}

char parseChar(int val)
{
	return val + '0';
}

//definindo um numero binario com a parte inteira e a parte decimal
Numero inicializa_numero(int bits, int mantissa, int sinal)
{
	Numero novo;
	novo.parteInteira = (Binario) malloc(sizeof(char) * bits);
	novo.parteDecimal = (FloatBinario) malloc(sizeof(char) * mantissa);
	if(sinal == 0)
	{
		novo.sinal = 0;
	}else
	{
		novo.sinal = 1;
	}
	return novo;
}


//funcao que converte um numero decimal em um numero binario
Binario converte_bin(int decimal, int max_bits)
{
	int i = max_bits - 1;
	int rest;
	Binario index = (Binario) malloc(sizeof(char) * max_bits);
		
	for(i;i >= 0; i--)
	{
		if(decimal%2 == 0)
		{
			index[i] = '0';
		}
		else
		{
			index[i] = '1';
		}
		decimal /= 2;
	}	
	return index;
}

//converte a parte decimal de um numero em um numero binario
FloatBinario converte_dec(float dec, int mantissa)
{
	int i = 0;
	int inteiro;
	FloatBinario novo = (FloatBinario) malloc(sizeof(char) * mantissa);
	
	for(i ; i < mantissa; i++)
	{
		inteiro = dec * 2;
		novo[i] = parseChar(inteiro);
		dec = dec * 2 - inteiro; 
	}
	return novo;
}


Numero converte_numero(float val, int bits, int mantissa)
{
	int sinal, parte_inteira;
	float parte_decimal;
	if(val < 0)
	{
		sinal = 1;
		val *= -1;
	}else
	{
		sinal = 0;
	}
	
	//
	parte_inteira = val;
	parte_decimal = val - parte_inteira;
	Numero novo = inicializa_numero(bits, mantissa, sinal);
	novo.parteInteira = converte_bin(parte_inteira, bits);
	novo.parteDecimal = converte_dec(parte_decimal, mantissa);
	return novo;
}

int retorna_bits(int value)
{
	if(value < 0)
	{
		value *= -1;
	}
	
	if(value <= 1) // 2 ^ 1
	{
		return 1;
	}
	if(value <= 3) // 2 ^ 2
	{
		return 2;
	}
	if(value <= 7) // 2 ^ 3
	{
		return 3;
	}
	if(value <= 15) // 2 ^ 4
	{
		return 4;
	}
	if(value <= 31) // 2 ^ 5
	{
		return 5;
	}
	if(value <= 63) // 2 ^ 6
	{
		return 6;
	}
	if(value <= 127) // 2 ^ 7
	{
		return 7;
	}
	if(value <= 255)
	{
		return 8;
	}
}






#endif
