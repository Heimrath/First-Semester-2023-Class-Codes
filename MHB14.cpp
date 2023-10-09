//MHB14 - teste de presição numerica
//Matheus Heimrath Barbosa - 10/03/2023

#include <iostream>

main()
{
	float Num, Num3, Soma3;
	//Num = 1.0/3.0;
	//Num = 0.333333; //6 casas decimais
	Num = 0.3333333;
	
	Num3 = 3*Num;
	Soma3 = Num + Num + Num;
	
	printf("Num = %f\n", Num);
	
	printf("3 x Num = %f\n", Num3);
	
	printf("Num + Num + Num = %f\n", Soma3);
}