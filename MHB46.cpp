//MHB46 - Matriz unidimensional (vetor ou array)
//Matheus Heimrath Barbosa - 26/04/2023

//Entrar com 12 numeros inteiros e DEPOIS apresenta-los
//na ordem de entrada e em ordem inversa

#include <iostream>

main()
{
	int N[12];  //reserva espaço para 12 numeros inteiros
	            //(indexados de 0 a 11)
	            
	int i;
	//entrada dos numeros
	for (i = 0; i < 12; i++)
	{
	    printf("%d - Digite um numero inteiro: ", i+1);
	    scanf("%d", &N[i]);
	}
	
	printf("\nEm ordem de entrada\n");
	for (i = 0; i < 12; i++)
	    printf("-> %d\n", N[i]);
	    
	printf("\nEm ordem inversa de entrada\n");
	for (i = 11; i >= 0; i--)
	    printf("-> %d\n", N[i]);    
	
	
	
}