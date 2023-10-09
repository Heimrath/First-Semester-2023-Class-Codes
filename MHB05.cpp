//MHB05 - Aritmetica com variaveis do tipo inteiro 
//Matheus Heimrath Barbosa - 03/03/2023
#include <iostream>

main ()
{
	int x = 350; //define e carrega a variavel
	int y = 20;
	
	printf("Soma: %d + %d = %d\n", x, y, x+y);
	printf("Subtraia: %d - %d = %d\nSubtraia: %d - %d = %d\n", x, y, x-y, y, x, y-x);
	printf("Multiplique: %d x %d = %d\n", x, y, x*y);
	printf("Divida: %d / %d = %d\n", x, y, x/y); //por ser numeros inteiros, não é mostrado o resto
	printf("Resto da divisao: %d / %d = %d\n", x, y, x%y);
	
}
