//MHB25 - Dias do mes
//Matheus Heimrath Barbosa - 24/03/2023

/*Entrar com o mes e o ano entre 1600 e 5000
dizer quantos dias esse mes tem.
Considerar que os meses: 4, 6, 9 e 11 possuem 30 dias
Considerar que o mes 2 pode ter 28 ou 29 conforme teste de ano bissexto
Os meses restantes, possuem todos 31 dias */

#include <iostream>

main()
{
	int ano, mes, dias;
	 
	printf("Insira um ano entre 1600 a 5000: ");
	scanf("%d", &ano);
	 
	if (ano < 1600 || ano > 5000)
	{
	    printf("Foi inserido um ano invalido!\n");
	    exit(0);
	}    
	
	printf("Insira um mes (numero): ");
	scanf("%d", &mes);
	
	if (mes < 1 || mes > 12)
	{
		printf("Foi inserido um mes invalido!\n");
        exit(0);
	}    
	
	if (mes == 2)	
	{
		if ((ano%400 == 0) || ((ano%4 == 0) && (ano%100 != 0)))
	        dias = 29;
	    
	    else
	        dias = 28;
	}    
	
	else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
		dias = 30;

	else 
		dias = 31;
		
	printf("O mes %d do ano %d possuem %d dias!", mes, ano, dias);
		
	 
}