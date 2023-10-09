 //MMM56 - funcao externa
//Manoela Martedi - 05/05/2023

#include <stdio.h>

int quartaPot(int num);

main() 
{
	int n;
	
	do
		{
		printf("Digite um numero inteiro (0 para sair): ");
		scanf("%d", &n);
		
		if (n != 0)
			printf("\nA quarta potencia de %d e %d.\n\n", n, quartaPot(n));
		
		} while (n != 0);
		
}

int quartaPot(int num)
{
	return num*num*num*num;
}

