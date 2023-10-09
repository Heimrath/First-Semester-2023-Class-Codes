//MHB28 - Calculo da divisao e resto
//Matheus Heimrath Barbosa - 29/03/2023

/*Entrar com dois numeros inteiros: divisor e dividendo
Calcular o resultado da divisao entre eles e o resto
Avisar que nao existe divisao por 0 */

#include <iostream>

main()
{
	
	int x, y;
	
	printf("Insira dois numeros inteiros a serem divididos: ");
	scanf("%d %d", &x, &y);
	
	switch (y)
	{
	
	    case 0:
	    	printf("Nao ha divisao por zero!");
	    	break;
	    	
	    default:
	    	printf("Aqui esta a divisao entre os numeros: %d\nAqui esta o resto da divisao entre os numeros: %d\n", x/y, x%y);
	
	}
	
	
	
}