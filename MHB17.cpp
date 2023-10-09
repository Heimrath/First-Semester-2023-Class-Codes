//MHB17 - teste par ou impar
//Matheus Heimrath Barbosa - 15/03/2023

//Entrar com um numero inteiro e dizer se é PAR ou IMPAR

#include <iostream>

main()
{
	int N;
	printf("Digite um numero inteiro: ");
	scanf("%d", &N);
	
	if(N % 2 == 0)
	   printf("%d PAR\n", N);
	else
	   printf("%d IMPAR\n", N);
	
}