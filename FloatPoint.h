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
		3 bits destinados para a mantissa.
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
	printf("Precisao escolhida: ");
	if(val.precisao == SIMPLES)
	{
		printf("Precisao Simples: 32bits");
	}else
	{
		printf("Precisao Dupla: 64bits");
	}
	printf("\n");
	printf("Sinal | Expoente| Magnitude \n");
	printf("%d |", val.sinal);
	printf("%s |", val.Expoente);
	printf("\n");
	
}



IEE74 inicia_padrao(int sinal, int precisao)
{
	IEE74 novo;
	if(sinal == 0)
	{
		novo.sinal = 0;
	}else
	{
		novo.sinal = 1;
	}
	if(precisao == SIMPLES)
	{
		novo.precisao = SIMPLES;
		novo.Expoente = (char*) malloc(sizeof(char) * 9);
		novo.Magnitude = (char*) malloc(sizeof(char) * 24);
		novo.Expoente[9] = '\0';
		novo.Magnitude[24] = '\0';
		return novo;
	}else
	{
		novo.precisao = DUPLA;
		novo.Expoente = (char*) malloc(sizeof(char) * 11);
		novo.Magnitude = (char*) malloc(sizeof(char) * 52);
		novo.Expoente[11] = '\0';
		novo.Magnitude[52] = '\0';
		return novo;
		
	}
}







#endif
