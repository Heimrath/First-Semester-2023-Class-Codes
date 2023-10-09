//MHB18 - Indicar a estacao do ano
//Matheus Heimrath Barbosa - 15/03/2023

/*Entrar com 1 caracter
Indicar qual estação do ano
P = Primavera, V = Verão, O = Outono e I = Inverno
Se for o caso, indicar "caracter invalido"
Usar "if else if else"*/

#include <iostream>

main()
{
	char xcar;  //define uma variavel que pode contem 1 caracter
	
	printf("Digite a estacao do ano (P, V, O ou I): ");
	scanf("%c", &xcar);
	
	
	if (xcar == 'P')
	   printf("QUE LEGAL VOCE ESTA NA PRIMAVERA!\n");
    else if (xcar == 'V')
       printf("QUE LEGAL VOCE ESTA NO VERAO!\n");
    else if (xcar == 'O')
       printf("QUE LEGAL VOCE ESTA NO OUTONO!\n");
    else if (xcar == 'I')
       printf("QUE LEGAL VOCE ESTA NO INVERNO!\n");
    else 
       printf("Caracter Invalido!");

}
