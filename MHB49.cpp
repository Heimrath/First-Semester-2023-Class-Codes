//MHB49 - Operacao numa string - substituicao de caracteres
//Matheus Heimrath Barbosa - 28/04/2023

/*Entrar com um texto de ate 100 caracteres
apresenta-lo na teka e fazer a seguintes substituicoes 
A por 4
E por 3
I por 1
O por 0
U por 6
usar o comando switch
reciclar o programa saindo apenas ao digitar ENTER */

#include <iostream>

main()
{
	int  i;
	char texto[101];
	
	do
	{
		printf("Digite um texto qualquer (ENTER PARA SAIR): ");
		gets(texto);
		printf("%s\n", texto);
		
		i = 0;
		
		while(texto[i] != '\0')
		   {
		   	switch (texto[i])
		       {
		       	case 'a':
		       	case 'A':
		           texto[i] = '4';
		           break;
		           
		        case 'e':
		        case 'E':
		           texto[i] = '3';
		           break;
		           
		        case 'i':
		        case 'I':
		           texto[i] = '1';
		           break;
		           
		        case 'o':
		        case 'O':
		           texto[i] = '0';
		           break;
		           
		        case 'u':
		        case 'U':
		           texto[i] = '6';
		           break;
			   }
			   i++;
		   }  
		printf("%s\n\n", texto);
	} while (texto[0] != '\0');
}