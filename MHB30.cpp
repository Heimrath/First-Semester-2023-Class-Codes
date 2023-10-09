//MHB30 - calculo da circunferencia 
//Matheus Heimrath Barbosa - 31/03/2023

/*Entrar com o diametro de um circulo em metro
Calcular a area e o perimetro
Usar 4 casas decimais em todas as medidas
PI = 3.1415 */

#include <iostream>

main()
{
	
	float diam, raio, area, perim, pi;
	
	pi = 3.1415;
	
	printf("Digite o diametro em metros: ");
	scanf("%f", &diam);
	
	raio = diam/2;
	
	printf("Raio: %10.4f\n", raio);
	printf("Area: %10.4f\n", 2*(raio*raio));
	printf("Perimetro: %10.4f\n", pi*2*raio);
	
	
}