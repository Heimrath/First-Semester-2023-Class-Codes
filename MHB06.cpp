//MHB06 - Calculo da area de um retangulo 
//Matheus Heimrath Barbosa - 03/03/2023

/*Dados os lados de um retangulo, calcular a sua area e o seu perimetro usando variaveis proprias*/

#include <iostream>

main()
{
	int ladoA = 45;
	int ladoB = 379;
	int perimetro, area;
	
	perimetro = 2*ladoA + 2*ladoB;
	area = ladoA * ladoB;
	
	printf("Perimetro = %d + %d + %d + %d = %d\n", ladoA, ladoA, ladoB, ladoB, perimetro);
	printf("Area = %d x %d = %d\n", ladoA, ladoB, area);
	
	system("pause");
}