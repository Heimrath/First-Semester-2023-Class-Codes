//MHB10 - Entrada de numeros inteiros pelo teclado 
//Matheus Heimrath Barbosa - 08/03/2023

#include <iostream>
main()
{
	int Num;
	
	printf("Digite um numero inteiro: ");
	scanf("%d", &Num); //scanf = função de scan do teclado //& na frente de um variavel e grudado indica o endereço da variavel
	
	printf("Foi digitado o numero: %d\n", Num);
}