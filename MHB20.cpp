//MHB20 - Divisao de uma herança
//Matheus Heimrath Barbosa - 17/03/2023

/*Dividir o valor monetario de uma heranca
entre uma quantidade definida de herdeiros
Quanto leva cada herdeiro?
O que acontece se digitarmos 0 herdeiros? Como prevenir isso?
E se os numeros digitados forem negativos?
Lembre-se nao existe valor inferior ao centavo
e nao existe fracao de quantidade de herdeiro*/

#include <iostream>

main()
{
	
	int herd;
	float valor;
	
	printf("Digite o valor da heranca: \n");
	scanf("%f", &valor);
	
	printf("Digite a quantidade de herdeiros: \n");
	scanf("%d", &herd);
	
	if (valor >= 0 && herd > 0)
		printf("Aqui esta a quantidade a ser entregue aos %d herdeiros: %.2f", herd, valor/herd);
	
	else 
		printf("Nao existe heranca ou herdeiros negativos, verifique as informacoes inseridas!");
	
	return 0;
}