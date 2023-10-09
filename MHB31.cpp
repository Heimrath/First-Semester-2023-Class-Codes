//MHB31 - Teste de divisibilidade 
//Matheus Heimrath Barbosa - 31/03/2023

/*Entrar com 2 numeros inteiros quaisquer e informar se o primeiro é divisivel pelo segundo
1. Se for divisivel, mostrar o resultado da divisao dizendo se o resultado é par ou ímpar
2. Se NÃO for divisivel, mostrar o resto da divisao dizendo se esse resto é multiplo de 3 ou não
3. NAO ha divisao por 0. */

#include <iostream>

main()
{
	int n1, n2;
	
	printf("Insira 2 numeros inteiros quaisquer a serem divididos: ");
	scanf("%d %d", &n1, &n2);
	
	if(n2 == 0)
	   printf("NAO HA DIVISAO POR 0 (ZERO)!!!\n");
	   
	else if (n1%n2 == 0)
	
	   if((n1/n2)%2 == 0)
	       printf("%d e' divisivel por %d, o resultado da divisao e': %d. E este resultado e' PAR!.", n1, n2, n1/n2);
	       
	    else
	       printf("%d e' divisivel por %d, o resultado da divisao e': %d. E este resultado e' IMPAR!.", n1, n2, n1/n2);
	       
	else
	{
		printf("Os numeros nao sao divisiveis!\n");
		
		if ((n1%n2)%3 == 0)
		   printf("O resto da divisao e': %d. Esse resto e' multiplo de 3", n1%n2);
		
		else 
		   printf("O resto da divisao e': %d. Esse resto nao e' multiplo de 3", n1%n2);
		   
	}
	
	   
	
}