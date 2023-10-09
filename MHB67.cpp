//MHB67 - tabela de multiplicacao 20 x 20 
//Matheus Heimrath Barbosa - 19/05/2023

/*criar uma tabela 20x20 contendo:
em cada linha os multiplos de seu primeiro elemento, por ex:
a linha 1 apresenta os elementos 1, 2, 3... 20
a linha 2: 2, 4, 6, 8, ..., 40
a linha 3: 3, 6, 9, ..., 60 */

#include <iostream>

main()
{
	 
	int mat[20][20]; //reserva espaco para 5 * 10 = 50 numeros inteiros
	int i, j, pri;       //i = linha   j = coluna   pri = primeiro elemento 
	
	for(i = 0; i < 20; i++)
	{
		pri = i+1; 
		for(j = 0; j <20; j++)
	    {
	    	mat[i][j] = pri;	    	
			printf("%4d\t", mat[i][j]);					    
		    pri+=(i+1);
		} 
		printf("\n");
	}
	   				
}





















