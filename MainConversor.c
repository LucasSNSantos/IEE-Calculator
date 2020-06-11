#include<stdio.h>
#include<stdlib.h>
#include"Calculator.h"
#include"FloatPoint.h"
#define MAX_BIT_SIZE 8


int main()
{

	float entrada;
	FloatBinario convertido;
//	scanf("%f", &entrada);
	convertido = converte_float_bin(9.7,4,8);
	printa_float_bin(convertido);
	
	
    


    return 0;
}
