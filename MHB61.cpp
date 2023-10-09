//MHB61 - apresentacao fatorial de 1 a 12
//Matheus Heimrath Barbosa - 12/05/2023

//Apresentar os 12 fatoriais
//usar funcao que calcula o fatorial

#include <iostream>

int fatorial(int N);

main()
{
    int n = 1;
    
    for(n; n<13; n++)
		printf("Fatorial de %d = %d\n\n", n, fatorial(n));
	
}

int fatorial(int N)
{
	int i = N;
	for(--i; i >0; i--)
	    N = N*i;
    return N;
}