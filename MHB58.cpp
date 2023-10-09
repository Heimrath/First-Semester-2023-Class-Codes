//MHB58 - Funcao de ano bissexto
//Matheus Heimrath Barbosa - 10/05/2023

/*Criar uma funcao que testa de um ano e bissexto 
usar esse funcao de forma recursiva, saindo somente quando o ano for 0
o ano deve estar mo intervalo de 1600 a 3000 (Formulas no programa 24 */


#include<iostream>

int bissexto(int num);

main()
{
	int ano;
	
	do
	{
		printf("Digite um ano entre 1600 a 3000 (0 para sair): ");
		scanf("%d", &ano);
		
		if(ano == 0)
		    break;
		else if(bissexto(ano) == 1 )
		    printf("Foi inserido um ano invalido!\n\n");
		else if (bissexto(ano) == 2)
		    printf("%d eh um ano bissexto!\n\n", ano);
		else
		    printf("%d nao eh um ano bissexto\n\n", ano);
		    
    } while (ano != 0);
} 
 
int bissexto(int num)
{	    
	if (num < 1600  || num > 3000)
	    return 1;	
	else 
       {    
        if (num%400 == 0 || ((num%4 == 0) && (num%100 != 0)))
      	    return 2; 	         
        else 
      	    return 3;
	   }
}