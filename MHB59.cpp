//MHB59 - consistencia de data
//Matheus Heimrath Barbosa - 10/05/2023

/* Criar uma funcao que verifica validade de uma data
entrar com a data no formato DD/MM/AAAA
verificar se a data esta correta indicando 
todos os erros que possui
o ano deve ser a partir de 1600
os meses 4, 6, 9 e 11 possue, 30 dias 
DICA: programa 25
usar funcao que testa se o ano e bissexto (programa 58)
Reciclar e sair somente quando for digitado dia 0 */

#include <iostream>

int fTestedata(int d, int m, int a);
int fTestebissexto(int num);

main()
{
	int dia, mes, ano;
	
	do
	{
		printf("Digite um data (DD/MM/AAAA) (DD == 0 para sair): ");
		scanf("%d/%d/%d", &dia, &mes, &ano);
		
		if (dia == 0)
		    break;
	    if(fTestedata(dia, mes, ano) == 1)
	        printf("Data correta!\n\n");
		
		
		
	} while(dia != 0);
}



int fTestebissexto(int num)
{
	if (num%400 == 0 || ((num%4 == 0) && (num%100 != 0)))
      	return 1;
	else
	    return 0; 	         
}

int fTestedata(int d, int m, int a)
{
	int ultdia; //ultimo dia do mes
	if (a < 1600)
	{
		printf("Ano invalido!\n\n");
		return 0;
	}	    
	if (m < 1 || m > 12)
	{
		printf("Mes invalido!\n\n");
		return 0;
	}
	   
	if(d < 1 || d > 30)
	{
		printf("Dia invalido!\n\n"); 
		return 0;
	}
	
	ultdia = 31;
	
	if (m == 4 || m == 6 || m == 9 || m == 11)  
	    ultdia = 30;
	    
	if(m == 2)
	{
	    if(fTestebissexto(a) == 1)
	        ultdia = 29;
	    else 
	       ultdia = 28;
	}
	
	if(d < 1 || d > ultdia)
	{
		printf("Dia invalido!\n\n");
		return 0;
	}
	
	return 1;
	 
}




