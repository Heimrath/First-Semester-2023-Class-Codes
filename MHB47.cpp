//MHB47 - Vetor com seleção
//Matheus Heimrath Barbosa - 26/04/2023

//entrar com 20 numeros inteiros quaisquer e DEPOIS;
//apresenta-los separando os pares e os impares

#include <iostream>

main()
{
	int N[20], i;
	
	for(i = 0; i < 20; i++)
	{
		printf("%.2d - Digite um numero inteiro: ", i+1);
	    scanf("%d", &N[i]);
	}
	
	printf("\nOs numeros pares: ");
	for (i = 0; i < 20; i++)
    {
		if (N[i] % 2 == 0)
            printf("%d\t", N[i]);   
	}  
	    
    printf("\nOs numeros impares: ");
	for (i = 0; i < 20; i++)
    {
		if (N[i] % 2 != 0)
            printf("%d\t", N[i]);   
	} 
}