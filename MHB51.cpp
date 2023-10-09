//MHB51 - Geracao de uma string invertido
//Matheus Heimrath Barbosa - 03/05/2023

//Entrar com uma string de ate 100 caracteres
//e gerar outra string invertida

#include <iostream>

main()
{
	char texto[100];  //tipo agregado homogeneo (so contem tipo caracter)
	                  //indexados de 0 a 99. SE FOR UMA STRING, ultimo caracter sera '\0' (NULL)
	                  //a responsabilidade de nao ultrapassar o limite e do progamador 
    char inv[100];
    int i, j;
    
    printf("Digite um texto qualquer: ");
    gets(texto);
    puts(texto);
    
    i=0;
    while(texto[i] != '\0') //posiciona no final da string
        i++;
         
    i--; //posiciona o indice no ultimo caracter da string
    
    j=0;
    
    //avanca j e retocede i para a inversao 
    for(i; i>=0; i--)
       {
	    inv[j] = texto[i];
		j++;			    
	   }
	    	  
	   inv[j] = '\0'; //indicador de final de string
	   puts(inv);
      
         
        
    
    
}