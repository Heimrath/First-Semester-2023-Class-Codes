//MMM54 - tabuada do 7 com for
//Manoela Martedi - 05/05/2023

#include <stdio.h>

main() 
{
	int n, i;
	
	do 
		{
		
		printf("Digite o indicador da tabuada (0 para sair): ");
		scanf("%d", &n);
		
		if (n == 0)
			{
			break;
			}
		
		for (i=0; i <= 20; i++)
			printf("%5d x %d = %d\n", i, n, i*n);
		
		printf("\n");
		
		} while (n != 0);
		
}