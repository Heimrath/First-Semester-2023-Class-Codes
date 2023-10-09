//MHB23 - Calculadora aritmetica
//Matheus Heimrath Barbosa - 22/03/2023

#include <iostream>

main ()
{
	int x, y, result;
	char ope;
	
	printf("Digite a operacao aritmetica: ");
	scanf("%d %c %d", &x, &ope, &y);
	
	//executar as consistencias
	
	if ((ope != '+') && (ope != '-') && (ope != '*') && (ope != '/') && (ope != '%'))
	    printf("Codigo de operacao invalido!\n");
	    
	else if ((ope == '/') || (ope == '%') && (y == 0))
	    printf("Nao existe divisao por zero!\n");
	    
	else
       {
       	//executar as operacoes
       	
       	if (ope == '+')
       	    result = x + y;
       	    
       	else if (ope == '-')
       	    result = x - y;
       	    
       	else if (ope == '*')
       	    result = x * y;    
       	    
       	else if (ope == '/')
       	    result = x / y;
			   
		else 
       	    result = x % y; 
       	
       	printf("%d %c %d = %d\n", x, ope, y, result);
			   
	   
       	    
	   }

}