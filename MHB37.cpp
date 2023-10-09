//MHB37 - contagem de multiplos
//Matheus Heimrath Barbosa - 12/04/2023

//A partir de 250, apresentar os 100 primeiros
//numeros multiplos de 7 que sao divisiveis por 3

#include <iostream>

main()
{
	int n, cont;
	n = 250;
	cont = 0;
	
	while (cont <= 100)
	   {
	   	if (n % 7 == 0 && n % 3 == 0)
	   	   {
	   	   	printf("%d\t",n);
	   	   	cont++;
		   }
		n++;
	   }
	
	
	
	
	
	
}