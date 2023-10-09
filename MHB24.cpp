//MHB24 - Teste de ano bissexto
//Matheus Heimrath Barbosa - 22/03/2023

/*Entrar com um ano no intervalo de 1600 a 5000
dizer se o ano é bissexto ou não
Um ano é bissexto quando:
-É divisivel por 4 e não divisivel por 100
OU 
-É divisivel por 400 */

#include <iostream>

main()
{
	int ano;
	
	printf("Insira um ano entre 1600 a 5000 para saber se foi ou sera ano bissexto: ");
	scanf("%d", &ano);
	
	if (ano < 1600 || ano > 5000)
	    printf("Foi inserido um ano invalido!");
	
	else 
       {
      	if (ano%400 == 0)
      	    printf("%d eh um ano bissexto!", ano);
      	      
      	else if (ano%4 == 0 && ano%100 != 0)
      	    printf("%d eh um ano bissexto!", ano);
      	    
      	else 
      	    printf("%d nao eh um ano bissexto", ano);
	   }
	   
    return 0;
}
