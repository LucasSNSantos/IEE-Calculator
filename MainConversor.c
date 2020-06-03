#include<stdio.h>
#include<stdlib.h>
#include"Calculator.h"


int main()
{

    int* Binario;
    int inteiro = 10;
    Binario = inicializa_bin(4);
    Binario = converte_bin(10,4);
    printa_bin(Binario,4);
	 
    


    return 0;
}
