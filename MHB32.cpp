//MHB32 - contagem numerica 
//Matheus Heimrath Barbosa - 31/03/2023

//contar de 0 a 200 usando o comando "while"

#include <iostream>

main() 
{
	int n;
	n = 0;
	
	while(n <= 200)
	{
		printf("%d\t", n);
		n = n + 1; //ou usar a formula abreviada: n++
	}
}