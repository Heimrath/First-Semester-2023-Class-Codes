//MHB07 - Variaveis do tipo ponto-flutuante
//Matheus Heimrath Barbosa - 08/03/2023

//%f para numeros nao inteiros, numeros quebrados   a
#include <iostream>

main()
{
	float Valor, Taxa;
	Valor = 245.79;
	Taxa = 14.613847;
	
	printf("A variavel Valor contem: %f\n", Valor);
	printf("A variavel Taxa contem: %f\n", Taxa);
	printf("A variavel Valor contem: %10.2f\n",Valor); //"10.2" significa as casas do numero, apos o ponto determiamos as casa decimais 
	printf("A variavel Taxa contem: %2.3f\n",Taxa);
	
}