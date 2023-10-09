//MHB21 - Comparar 2 numeros inteiros
//Matheus Heimrath Barbosa - 17/03/2023

/*Entrar com 2 numeros inteiros e dizer se:
Sao igual ou qual o mais e qual menor */

#include <iostream>

main()
{
	int n1, n2;
	
	printf("Digite 2 numeros a serem comparados: \n");
	scanf("%d %d", &n1, &n2);
	
	if (n1 == n2)
	    printf("%d e %d sao iguais!", n1, n2); 
	    
	else if (n1 < n2)
	    printf("%d eh menor do que %d", n1, n2);
	    
	else 
	    printf("%d eh maior do que %d", n1, n2);
	    
	return 0;
}
                                                                                       
                