//MHB62 - funcao teste numero primos
//Matheus Heimrath Barbosa - 12/05/2023

/*Transformar o programa 45 em uma funcao: fprimo que devoleve 0 ou 1
0 se nao for primo
1 se for primo
Reciclar o programa aceitando apenas positivos 
Sair com 0 */

#include <iostream>

int fprimo(int num);

main()
{
	int N; 
	do
	{
		printf("Insira um numero inteiro positivo (0 para sair): ");
	    scanf("%d", &N);
	    
	    if(N == 0)
		    break; 
	    
	    if(N < 0)
		{
			printf("Insira um numero inteiro POSITIVO\n\n");
			continue;  
		}
		
		else
		{
			if(fprimo(N) == 1) 
		       printf("%d EH PRIMO\n\n", N);
		    
		    else
		       printf("%d NAO EH PRIMO\n\n", N);
		}
		    
		       
		
		
	} while (N != 0);
    
	
	
	
		
}

int fprimo(int num)
{
	int OK = 1;
	
	if(num >= 3)
		{
			for(int cont = 2; cont <= num/2; cont++)
		    {
		        if(num % cont == 0)
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









