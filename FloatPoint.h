#ifndef FLOAT_POINT_H
#define FLOAT_POINT_H
#include<stdlib.h>
#include<string.h>
#include"Calculator.h"
#define SIMPLES 32
#define DUPLA   64


/*
	32 bits:
		1 bit para o sinal.
		8 bits destinados para o expoente.
		23 bits destinados para a mantissa.
	64 bits:
		1 bit destinado para o sinal;
		11 bits destinados para o expoente;
		52 bits destinados para a mantissa.	
Dupla
 */


typedef struct patternIEE
{
	int precisao;
	int sinal;
	char* Expoente;
	char* Magnitude;
}IEE74;

void print_numero_padronizado(IEE74 val)
{
	printf("Precisao escolhida: \n");
	if(val.precisao <= 32)
	{
		printf("Precisao Simples: 32bits");
	}else
	{
		printf("Precisao Dupla: 64bits");
	}
	printf("\n");
	printf("| Sinal | Expoente| Magnitude | \n");
	printf("| %d |", val.sinal);
	printf(" %s |", val.Expoente);
	printf(" %s |", val.Magnitude);
	printf("\n");
	
}


char* completa_os_zeros(char* mantissa, int zeros)
{
	int size = strlen(mantissa);
	char* nova_mag = (char*) malloc(sizeof(char) * zeros);
	nova_mag[zeros] = '\0';
	strcpy(nova_mag, mantissa);
	while(size < zeros)
	{
		nova_mag[size] = '0';
		size++;
	}
	return nova_mag;
}

IEE74 padroniza_numero(Numero num, int precisao)
{
	IEE74 novo;
	int offset;
	int size;
	if(num.sinal == 1)
	{
		novo.sinal = 1;
	}else
	{
		novo.sinal = 0;
	}	
	if(precisao <= 32)
	{
		offset = 127 + num.Expoente;
		novo.Expoente = (char*) malloc(sizeof(char) * 8);
		novo.Expoente = converte_bin(offset, retorna_bits(offset));
		
		novo.Magnitude = (char*) malloc(sizeof(char) * 23);
		novo.Magnitude = completa_os_zeros(num.parteDecimal, 23);
		novo.precisao = 32;
	}else
	{
		offset = 1023 + num.Expoente;
		novo.Expoente = (char*) malloc(sizeof(char) * 11);
		novo.Expoente = converte_bin(offset, retorna_bits(offset));
		
		novo.Magnitude = (char*) malloc(sizeof(char) * 52);
		novo.Magnitude = completa_os_zeros(num.parteDecimal, 52);
		novo.precisao = 64;
	}
	return novo;
}





#endif
