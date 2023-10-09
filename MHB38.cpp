//MHB38 - Faixa de peso ideial com reciclagem DO-WHILE
//Matheus Heimrath Barbosa - 12/04/2023


/*Dada a sua altura em metros, calcule a faixa de seu peso ideial
Em Kg com 1 casa decimal
Considerando que seu IMC deve estar entre 18.5 e 24.9999... */

#include <iostream>

main()
{
	
	float peso1, peso2, altura, imc1, imc2;
	
	do 
	{
		printf("Digite sua altura (em metros) (0 para sair): ");
		scanf("%f", &altura);
		
		
		if (altura < 0)
		    printf("Nao existe altura negativa!\n\n");
		    
		else if (altura != 0)
		{
		    imc1 = 18.5;
		    peso1 = imc1 * (altura * altura);
		
		    imc2 = 24.9999;
		    peso2 = imc2 * (altura * altura);
		
		    printf("Seu peso deve estar entre %.1f e %.1f\n\n", peso1, peso2);
		}   
	} while (altura != 0);
	
	
	
	
	
}