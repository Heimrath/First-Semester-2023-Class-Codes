//MHB50 - criptografia "Cesar"
//Matheus Heimrath Barbosa - 28/04/2023

/* Entrar com um texto de ate 50 caracteres apresentando-o na tela
Criptografa-lo acrescentando o valo de deslocamento 10
apresentar o texto criptografado
descriptografado
reciclar */

#include <iostream>

main()
{
	int i;
	char texto[50];
	
	do
	{
		printf("Digite um texto qualquer (ENTER PARA SAIR): ");
		gets(texto);
		printf("%s\n", texto);
		
		i = 0;
		
		while(texto[i] != '\0')
		    {
		    	texto[i] = texto[i] + 10;
			    i++;
			}
		    
		printf("O texto criptografado:\n");    
		puts(texto);
		
		i = 0;
		
		while(texto[i] != '\0')
		{
			texto[i] = texto[i] - 10;
		    i++;
		}
		       
		printf("O texto descriptografado:\n");
		puts(texto);
		printf("\n");
	 
	} while(texto[0] != 0);
}