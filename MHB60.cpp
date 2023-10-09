//MHB60 - funcao fatorial
//Matheus Heimrath Barbosa - 12/05/2023
/*Implementar a funcao fatorial(N)
onde N e´ um numero inteiro entre 1 e 12
por definicao 0! = 1
Testar a funcao reciclando o programa (sair se digitar 0) */

#include <iostream>

int fatorial(int N);
main()
{
	int n1;
	
	do
	{
		printf("Digite um numero inteiro de 1 a 12 (0 para sair): ");
		scanf("%d", &n1);
		
		if(n1 ==  0)
		    break;
		
		else if(n1 > 12 || n1 < 0)
		    printf("Numeor invalido!\n\n");
		    
		    printf("Fatorial de %d = %d\n\n", n1, fator		else
ial(n1));				
		
	}while (n1 != 0);	
	
	
}


int fatorial(int N)
{
	int i = N;
	for(--i; i >0; i--)
	    N = N*i;
    return N;
}




