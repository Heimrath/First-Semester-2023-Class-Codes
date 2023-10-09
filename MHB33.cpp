//MHB33 - contagem recressiva 
//Matheus Heimrath Barbosa - 05/04/2023

//contar de 2000 a 500 de 25 a 25
//usar tabulação e o comando "while"

#include <iostream>

main()
{
	
	int n;
	n = 2000;
	
	while (n >= 500)
	{
		printf("%d\t", n);
		n = n - 25;
	}
	
}