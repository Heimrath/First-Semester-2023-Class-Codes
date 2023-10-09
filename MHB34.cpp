//MHB34 - multiplos de 9
//Matheus Heimrath Barbosa - 05/04/2023

//apresentar a contagem de 0 a 500 com tabulação 
//indicando com "x" os multiplos de 9 

#include <iostream>

main()
{
	
	int n;
	n = 0;
	
	while(n <= 500)
	{
		if (n%9 == 0)
			printf("%dx\t", n);
		       
		else 
			printf("%d\t", n);
			
			
	    n++;
		
		    
	}
	
}