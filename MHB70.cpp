//MHB70 - matriz bidimensional - passagem para funcao
//Matheus Heimrath Barbosa - 26/05/2023

/*Criar uma tabela 5x10
com numeracao sequencial a partir de 1
apresentar  a matriz numa funcao
Criar uma funcao para dobrar todos esses valores */

#include <iostream>

void fMostra(int M[5][10]);
void fDobra(int M[5][10]);

main()
{
	int Mat[5][10];
	int i, j; //i = linha j= coluna
	int n = 1;
	
	for(i=0; i<5; i++)
	    for(j=0; j<10; j++) 
	    {
	    	Mat[i][j] = n;
	    	n++;
		}
	
	//o nome da matriz SEM suas dimensoes, representa o endereco do primeiro elemento
	//no caso da matriz temos: Mat é o mesmo que &Mat[0][0]
	
	fMostra(Mat);
	fDobra(Mat);
	printf("\nA matriz original foi alterada\n");
	fMostra(Mat);
	
	
}


//No caso da matriz a sua passagem para a funcao 
//apresentacao da matriz
void fMostra(int M[5][10])
{
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<10; j++) 
	    
	    	printf("%2d ",M[i][j]);
	    printf("\n");
	}
	printf("\n\n");    
}

//dobra os valores da matriz
void fDobra(int M[5][10])
{
	for(int i=0; i<5; i++)
		for(int j=0; j<10; j++) 
		    M[i][j] = M[i][j]*2;
}









