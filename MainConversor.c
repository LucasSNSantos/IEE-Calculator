#include<stdio.h>
#include<stdlib.h>
#include"Calculator.h"
#include"Hexadecimal.h"
#include"FloatPoint.h"
#define MAX_MANTISSA 8


int main()
{
	IEE74 val;
	float numero;
	scanf("%f", &numero);
	int bits = retorna_bits((int)numero);
	Numero num = converte_numero(numero,bits,MAX_MANTISSA);
	num =  define_expoente(num);
	printf("\n");
	val = padroniza_numero(num,32);
	print_numero_padronizado(val);
 
 	



    return 0;
}
