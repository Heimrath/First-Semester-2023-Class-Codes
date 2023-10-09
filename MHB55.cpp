//MMM55 - funcao externa
//Manoela Martedi - 05/05/2023

#include <stdio.h>

void dobro(int num);

main() 
{
	int n;
	
	do
		{
		printf("Digite um numero inteiro (0 para sair): ");
		scanf("%d", &n);
		
		if (n != 0)
			dobro(n);
		
		} while (n != 0);
		
}

void dobro(int num)
{
	printf("\nO dobro de %d e %d.\n\n", num, num*2);
}

