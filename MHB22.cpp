//MHB22 - comparacao entre numeros inteiros
//Matheus Heimrath Barbosa - 17/03/2023

/*Entrar com 5 numeros inteiros quaisquer (pode ser negativo)
Dizer qual o maior e qual o menor */

#include <iostream>

main()
{
	int n1, n2, n3, n4, n5;
	int maior, menor;
	
	printf("Digite 5 numeros inteiros: ");
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	
	maior = n1;
	
	if (n2 > maior)
	   maior = n2;
	
	if (n3 > maior)
	   maior = n3;
	   
	if (n4 > maior)
	   maior = n4;
	   
	if (n5 > maior)
	   maior = n5;
	   
	printf("O numero maior eh: %d\n", maior);
	   
    menor = n1;
    
    if (n2 < menor)
	   menor = n2;

    if (n3 < menor)
	   menor = n3;
	   
  	if (n4 < menor)
	   menor = n4;

	if (n1 < menor)
	   menor = n5;	 
	   
	printf("O menor numero eh: %d", menor);
 
	
	
}