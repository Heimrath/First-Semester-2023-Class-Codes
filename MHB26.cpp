//MHB26 - Indicar a estacao do ano (Switch)
//Matheus Heimrath Barbosa - 29/03/2023

/*Entrar com 1 caracter
Indicar qual estação do ano
P = Primavera, V = Verão, O = Outono e I = Inverno
Se for o caso, indicar "caracter invalido"
Usar "switch case"*/

#include <iostream>

main()
{
	char xcar;  //define uma variavel que pode contem 1 caracter
	
	printf("Digite a estacao do ano (P, V, O ou I): ");
	scanf("%c", &xcar);
	
	switch (xcar)
	{
		case 'V':
			printf("QUE LEGAL VOCE ESTA NO VERAO!\n");
			break;
			
		case 'P':
			printf("QUE LEGAL VOCE ESTA NA PRIMAVERA!\n");
			break; 
			
		case 'I':
			printf("QUE LEGAL VOCE ESTA NO INVERNO!\n");
			break;
			
		case 'O':
			printf("QUE LEGAL VOCE ESTA NO OUTONO!\n");
			break;
			
		default:
			printf("Caracter Invalido!");
	}

}