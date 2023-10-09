//MHB - Operações com variaveis do tipo ponto-flutuante
//Matheus Heimrath Barbosa - 08/03/2023

#include <iostream>

main()
{
	float a1, a2;
	a1 = 123.12445;
	a2 = 12.213;
	
	printf("Some: %f + %f = %f\n", a1, a2, a1+a2);
	printf("Some: %f + %f = %10.2f\n", a1, a2, a1+a2);
	
	printf("Subtraia: %f - %f = %f\n", a1, a2, a1-a2);
	printf("Subtraia: %f - %f = %5.10f\n", a1, a2, a1-a2);
	
	printf("Multiplique: %f - %f = %f\n", a1, a2, a1-a2);
	printf("Multiplique: %f - %f = %10.20f\n", a1, a2, a1-a2);
	
	printf("Divida: %f / %f = %f\n", a1, a2, a1/a2);
	printf("Divida: %f / %f = %0.15f\n", a1, a2, a1/a2);
	printf("Divida: %f / %f = %2.0f\n", a1, a2, a1/a2);
	//NAO EXISTE RESTO EM DIVISAO DE VARIAVEIS PONTO-FLUTUANTE 
	
}