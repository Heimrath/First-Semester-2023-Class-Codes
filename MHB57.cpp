//MHB57 - DESAFIO
//Manoela Martedi - 05/05/2023

#include <stdio.h>

char check(int num);

main() 
{
	int n;
	
	do
		{
		printf("Digite um numero inteiro (0 para sair): ");
		scanf("%d", &n);
		
		if (n != 0)
			if (check(n) == 'p')
				{
				printf("O numero %d e par.\n\n", n);
				}
			else
				printf("O numero %d e impar.\n\n", n);
		
		} while (n != 0);
		
}

char check(int num)
{
	if (num%2 == 0)
		return 'p';
	else
		return 'i';

}

