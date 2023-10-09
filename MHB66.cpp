//MHB66 - Matriz bidimensional variaceis globais
//Matheus Heimrath Barbosa - 19/05/2023

/*Criar uma tabela 5 por 20
com numeracao sequencial a partir de 1
usar variaveis globais para a qtde de linha e coluna */

#include <iostream>

//variaveis globais (antes do main())
int QTLINHAS = 5;
int QTCOLUNAS = 20;

main()
{
	int mat[QTLINHAS][QTCOLUNAS]; //reserva espaco para 5 * 10 = 50 numeros inteiros
	int i, j, n = 1;       //i = linha   j = coluna
	
	for(i = 0; i <QTLINHAS; i++)
	    for(j = 0; j < QTCOLUNAS; j++)
	    {
	    	mat[i][j] = n;
	    	n++;
		} 
		
	//apresentacao da matriz
	for(i=0; i<QTLINHAS; i++)
	{
	    for(j = 0; j < QTCOLUNAS; j++)
	    	printf("%4d\t", mat[i][j]);			
		printf("\n");
	}
}