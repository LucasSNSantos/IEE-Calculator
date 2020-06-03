#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<string.h>
#include<stdlib.h>
#include<stdio.h>


//definindo um numero binario como um vetor de inteiros
int* inicializa_bin(int bit_size)
{
	int* temp;
	temp = (int*) malloc(sizeof(int) * bit_size);
	return temp;
}


//funcao que printa um numero binario
void printa_bin(int* num, int max_bits)
{
	int i = 0;
	for(i ; i < max_bits; i++)
	{
		printf("%d", num[i]);
	}
}

//funcao para inverter um vetor, usado na conversao
void inverte_num(int* num, int max_bits)
{
	int* aux = inicializa_bin(max_bits);
	int i;
	int k;
	for(i = max_bits - 1, k = 0; i > 0 ; i--, k++)
	{
		aux[k] = num[i]; 
	}
	for(i = 0; i < max_bits; i++)
	{
		num[i] = aux[i];
	}
	free(aux);
	aux = NULL;
}

//funcao que converte um numero decimal em um numero binario
int* converte_bin(int decimal, int max_bits)
{
	int i = 0;
	int rest;
	int* index = (int*) malloc(sizeof(int) * max_bits);
	
	while(decimal != 1)
	{
		index[i] = decimal%2;
		decimal /= 2;
		i++;
		if(i > max_bits) return NULL;
		if(decimal == 1)
		{
			index[i] = decimal;
		}
	}
	inverte_num(index, max_bits);
	return index;
}


#endif
