//MHB36 - Calculo dos cubos com reciclagem 
//Matheus Heimrath Barbosa - 05/04/2023

//Entrar com um numeor inteiro qualquer e apresentar o seu cubo
//reciclar o programa saindo somente ao digitar 0

#include <iostream>

main()
{

	int n;
	
	do
	{
		printf("Digite um  numero inteiro para obter seu cubo (0 para sair): ");
		scanf("%d", &n);
		
		if (n != 0)
		   printf("O cubo de %d = %d\n\n", n, n*n*n);
		
	} while (n != 0);
	
	
}