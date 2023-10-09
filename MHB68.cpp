//MHB68 - Tabela com cabecalhos numericos
//Matheus Heimrath Barbosa - 24/05/2023

/*Criar uma tabela de caracteres 'x' 22 x 26
Apresentar  a tabela acrescentando uma linha superior
e uma coluna a esquerda com os respectivos indicadores */

#include <iostream>

main()
{
	char Tab[22][26];
	int i, j; //i = linha ; j = coluna 
	
	Tab[i][j] = 'x'; 
	
	for(j = 0; j < 26; j++)
	    printf("\t%2d", j);
	    
	printf("\n\n");
	
	for(i= 0; i<22; i++)
	{
		printf("%2d", i);
		for(j = 0; j < 26; j++)
	    {
	    	Tab[i][j] = 'x';
	    	printf("\t %c",Tab[i][j]);
		}
	    printf("\n");
	}
       
	        
	    
	
	
	
	
	
	
	
	
	
}