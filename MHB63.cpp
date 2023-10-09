=

#include <iostream>

int fprimo(int n); 

main()
{
	int N, cont, num;
	
	do
	{
		printf("\nDigite a quantidade de numeros primos (0 para sair): ");
		scanf("%d", &N);
		
		if(N==0)
		    break;
		if(N < 0)
            continue;
			
		cont = 0;
		num = 1; //primeiro numero
		
		while (cont<N);
		{
			if(fprimo(num) == 1)
			{
				printf("%d\t", num);
				cont++;
			}
			num++;
		    
		}
		
		
	} while (N != 0);
}


int fprimo(int n)
{
	int OK = 1;
	
	if(n >= 3)
		{
			for(int cont = 2; cont <= n/2; cont++)
		    {
		        if(n % cont == 0)
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





























