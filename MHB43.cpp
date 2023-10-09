//MHB43 - Contagens usando "For"
//Matheus Heimrath Barbosa - 14/04/2023

/*Contar de 1 a 100
Contar de 50 a 300 de 3 em 3
Contar de 1000 a 200 descendo de 5 em 5
Utilizar system("pause") entre as contagens */

#include <iostream>

main()
{
	int cont;
	
	for(cont = 1; cont <= 100; cont++)
	    printf("%d\t",cont);
	printf("\n");
	system("pause");
	    
	for(cont = 50; cont <= 300; cont = cont+3)
	    printf("%d\t",cont);
	printf("\n");
	system("pause");
	
	    
	for(cont = 1000; cont >= 200; cont = cont - 5)
	    printf("%d\t",cont);
	
	printf("\n");
	system("pause");
	
}