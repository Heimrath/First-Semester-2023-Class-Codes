//MHB45 - 
//Matheus Heimrath Barbosa - 19/04/2023

/* Entrar com um inteiro positivo qualquer e
Verificar se é numero primo (nao aceitar numeros negativos)
O progama deve reciclar saindo apenas quando for digitado 0 ou negativo
Numero primo: é aquele que somente é divisivel por ele mesmo e pela unidade
DICA: partir sempre que o numeor é primo
1 e 2 sao primos
Se o numero for negativo avisar e retornar usando o comando "continue" */

#include<iostream>

main()
{
	
	int N, cont;
	int OK; //1 = primo e 0 = nao primo
	
	
	
	do
	{
		printf("Insira um numero inteiro positivo (0 para sair): ");
		scanf("%d", &N);
		
		if(N == 0)
		    break; //sai do loop
		    
		if(N < 0)
		{
			printf("Insira um numero inteiro POSITIVO\n\n");
			continue; //volta pro comeco do loop
		}
		
		OK = 1;
		
		if(N >= 3)
		{
			for(cont = 2; cont <= N/2; cont++)
		    {
		        if(N % cont == 0)
		        {
		        	OK = 0;
		        	break;
				}
		    }
		
		}
		
		if(OK == 1)
			printf("PRIMO\n");
			   
	    else 
	    {
	    	printf("o numero %d NAO E' PRIMO\t", N);
	    	printf("(pois eh divisivel pelo menos por %d)\n)", cont);
		}
	           
		
		      
	} while (N != 0);
	
}
