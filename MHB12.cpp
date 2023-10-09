//MHB12 - Entrada de 3 numeros inteiros  
//Matheus Heimrath Barbosa - 10/03/2023
//Na entrada, os numeros devem ser deparados por 1 ou mais espaco ou tabulação

#include <iostream>

main()
{
	int n1, n2, n3;
	
	printf("Digite 3 numeros inteiros, separados por espaco: ");
	scanf("%d %d %d", &n1, &n2, &n3);
	
	printf("Foi digitado: %d %d %d\n", n1, n2, n3);
	printf("Sua soma: %d\n", n1+n2+n3);
	printf("Sua subtracao: %d\n", n1-n2-n3);
	printf("Sua multiplicacao: %.2d\n", n1*n2*n3);
}