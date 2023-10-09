//MHB44 - Contagem dos multiplod de 6
//Matheus Heimrath Barbosa - 19/04/2023

//Apresentar os 100 primeiros multiplod de 6

#include<iostream>
main()
{
	
	int cont, multi;
	
	multi = 6;
	
	for(cont = 1; cont <= 100; cont++)
	{
		printf("%d\t", multi);
		multi = multi + 6;
	}
	
	
	
	
	
}