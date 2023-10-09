//MHB64 - Numeros primos em pesquisa I
//Matheus Heimrath Barbosa - 17/05/2023

/*Apresentar os N primeiros numeros primos em 4 colunas
- um contador de 1 a N,
- a diferenca desse primo com o primo anterior
- um grafico referente a essa diferenca.
Reciclar saindo apenas com 0 */

#include <iostream>
#include <math.h>

int fprimo(int N); 
void fGraf(int n);

main()
{
	int N1, num, cont, dif, ant;
	do
	{
		printf("\nDigite a quantide de numeros primos (0 para sair): ");
		scanf("%d", &N1);
		
		if(N1 == 0)
		   break;
		if(N1 < 0)
		   continue;
		
		printf("Cont: Primo: Diferenca: Grafico:\n");   
		cont = 1;
		num = 1;
		ant = 0;
		
		while(cont <= N1)
		{   
		    
			if(fprimo(num) == 1)
			{
				printf("%d\t%d\t%d\t", cont, num, num-ant);
				fGraf(num-ant); 
				printf("\n");
				cont++;	
				ant = num;
				 
						
			}
			
			num++;
		}   
		   
		   
		   
		   
	} while (N1 != 0);
}

int fprimo(int N)
{
	int OK = 1;
	
	if(N >= 3)
		{
			for(int cont = 2; cont <= sqrt(N); cont++) //substituindo a funcao > for(int cont = 2; cont <= N/2; cont++), ao inves de N/2, colocaremos sqrt(N) (raiz quadrada do numero)
		    {
		        if(N % cont == 0)
		        {
		        	OK = 0;
		        	break;
				}
		    }
		    return OK;
		}
		
	else
	    return OK;
}

void fGraf(int n)
{
	for(int i = 1; i<=n; i++)
	    printf("*", i);
}









