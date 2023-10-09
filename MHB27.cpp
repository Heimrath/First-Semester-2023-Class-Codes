//MHB27 - Dias da semana
//Matheus Heimrath Barbosa - 29/03/2023

/*Entrar com um numero inteiro qualquer
Indicar o dia da semana
1 = domingo, 2 = segunda ... 
Caso necessario indicar numero invalido
Usar comando switch */

#include <iostream>

main()
{
	
	int dia;
	
	printf("Insira um numero de 1 a 7 para saber o dia da semana: ");
	scanf("%d", &dia);
	
	switch (dia)
	{
		case 1:
			printf("Domingo!\n");
			break;
			
		case 2:
			printf("Segunda!\n");
			break;
			
		case 3:
			printf("Terca!\n");
			break;
			
		case 4:
			printf("Quarta!\n");
			break;
			
		case 5:
			printf("Quinta!\n");
			break;
			
		case 6:
			printf("Sexta!\n");
			break;
			
		case 7:
			printf("Sabado!\n");
			break;
			
		default:
			printf("Nao foi inserido um numero valido!");
			
		
		
		
	}
	
	
	
	
	
	
	
	
	
}





