//MHB13 - Entrada de 3 numeros ponto-flutuante  
//Matheus Heimrath Barbosa - 10/03/2023
/*apresentar os numeros com apenas 2 casas decimais
1. separados por tabulação
2. encolunados com o ponto decimal alinhado e com a soma calculada
3. idem com 5 casas decimais
*/

#include <iostream>

main()
{
	float n1, n2, n3;
	
	printf("Digite 3 numeros ponto-flutuante, separados por espaco: ");
	scanf("%f %f %f", &n1, &n2, &n3);
	
	printf("Os numeros digitados foram: %.2f %.2f %.2f\n", n1, n2, n3);
	
	printf("Somando obtemos\n");
	printf("%20.2f\n", n1);
	printf("%20.2f\n", n2);
	printf("%20.2f\n", n3);
	printf("--------------------\n");
	printf("%20.2f\n\n", n1+n2+n3);
	
	printf("Somando obtemos\n");
	printf("%20.5f\n", n1);
	printf("%20.5f\n", n2);
	printf("%20.5f\n", n3);
	printf("--------------------\n");
	printf("%20.5f\n", n1+n2+n3);
	
}