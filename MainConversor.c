#include<stdio.h>
#include<stdlib.h>
#include"Hexadecimal.h"
#include"FloatPoint.h"
#define MAX_MANTISSA 8

void coloca_espacos(int num);
int main()
{
	float valor_calculo;
	int precisao;
	Numero num, copia;
	IEE74 padronizado;
	printf("Calculadora de Ponto Flutuante IEE 754 \n \n");
	printf("Digite um numero decimal para calcular seu ponto flutuante: \n");
	scanf("%f", &valor_calculo);
	coloca_espacos(2);
	printf("Escolha uma precisao do Padrao IEEE 754: \n");
	printf("32 ou 64 bits: \n");
	scanf("%d", &precisao);
	num = converte_numero(valor_calculo, retorna_bits((int)valor_calculo), MAX_MANTISSA);	
	copia = num;
	num =  define_expoente(num);
	coloca_espacos(2);
	printf("Numero em base Binaria: \n");
	printa_numero(num);
	coloca_espacos(2);
	printf("Numero em base Hexadecimal: \n");
	printf("%s , %s", converte_bin_hexa(copia.parteInteira), converte_bin_hexa(copia.parteDecimal));

	coloca_espacos(4);
	printf("Padrao IEEE 754 de ponto flutuante: \n");
	padronizado = padroniza_numero(num, precisao);
	print_numero_padronizado(padronizado);
	

    return 0;
}

void coloca_espacos(int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("\n");
	}
}





