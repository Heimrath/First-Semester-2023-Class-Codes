//MHB11 - Entrada de numero ponto-flutuante pelo teclado 
//Matheus Heimrath Barbosa - 10/03/2023

#include <iostream>

main()
{
	float n1, n2, n3, n4, media, nt;
	
	printf("Insira sua nota do PRIMEIRO bimestre: ");
	scanf("%f", &n1);
	
	printf("Insira sua nota do SEGUNDO bimestre: ");
	scanf("%f", &n2);
	
	printf("Insira sua nota do TERCEIRO bimestre: ");
	scanf("%f", &n3);
	
	printf("Insira sua nota do QUARTO bimestre: ");
	scanf("%f", &n4);
	
	nt = n1 + n2 + n3 + n4;
	media = nt / 4;
	
	printf("Sua media final: %.0f\n", media);
}