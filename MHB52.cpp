//MHB52 - Localizar um elemento numa string
//Matheus Heimrath Barbosa - 03/05/2023

/*Entrar inicialmente com um texto (uma string de ate 100 caracteres)
Depois, de forma reciclavel, digitar 1 caracter
Localizar tofas as ocorrencias desse caracter no texto indicado
quantas vezes ocorre e as suas respectivas posicoes 
ou a mensagem caracter inexistente no texto 
sair somente quando digitado "@"
DICA: considerar o caracter a ser pesquisado como uma string de 1 caracter */

#include <iostream>

main()
{
	char texto[101], carac[2];
	int i, cont;
	
	
	printf("Digite um texto: ");
	gets(texto);
	
	do
	{
	    printf("\nCaracter a pesquisar (@ para sair): ");
	    gets(carac);
	    
	    
	    
		cont=0;
		
		printf("Posicoes: ");
		for(i=0; texto[i] != '\0'; i++)
		{
		    if(texto[i] == carac[cont])
		       {
		        printf("%d\t", i);
					
			   }    
		}
		      
		printf("total: %d ocorrencias", cont);
		
		   
		
		
	} while (carac[0] != '@');
}

