//MHB65 - Matriz bidemensional
//Matheus Heimrath Barbosa - 19/05/2023

/*Criar uma tabela 5 linhas 10 colunas
com numeracao sequencial a partir de 1 */

#include <iostream>

main()
{
	 
	int mat[5][10]; //reserva espaco para 5 * 10 = 50 numeros inteiros
	int i, j, n = 1;       //i = linha   j = coluna
	
	for(i = 0; i <5; i++)
	    for(j = 0; j < 10; j++)
	    {
	    	mat[i][j] = n;
	    	n++;
		} 
		
	//apresentacao da matriz
	for(i=0; i<5; i++)
	{
	    for(j = 0; j < 10; j++)
	    	printf("%4d\t", mat[i][j]);			
		printf("\n");
	}
		   		
		
		
}