//MHB48 - Uma string e seu tamanho
//Matheus Heimrath Barbosa - 26/04/2023

/*Entrar com um texto ate 200 caracteres
apresenta-lo em seguida na tela e
calcular o seu tamanho (isso é possivel, porque a string comeca com '0' */

#include <iostream>

main()
{
	int i;
	char texto[201];
	
	printf("Digite um texto qualquer: ");
	gets(texto);
	
	printf("O texto digitado foi:\n");
	printf("%s\n", texto); //%s para string
	
	printf("\nOutra forma de apresentar uma string\n");
	puts(texto);
	
	//calculo do tamanho
	
	i = 0;
	while(texto[i] != 0)
	     i++;
	    
    printf("O texto possui %d caracteres", i);
	
	
	
	



}