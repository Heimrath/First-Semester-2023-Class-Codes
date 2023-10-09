//MHB-Ativ01 - Conversão de Fahrenheit para Celsius
//Matheus Heimrath Barbosa - 10/03/2023

#include <iostream>

main()
{
/*Primeiro, criamos como se fosse um portal de acesso,
com uma senha qualquer (qualquer numero serve...*/

	int senha;
	printf("Digite sua senha de acesso (numeros): ");
	scanf("%d", &senha);
	
	printf("\nSeja Bem vindo!\n\n"); 
	
/*Depois, o local para inserir a temperatura
em fahrenheit a ser convertida*/
    
    float fahrenheit, celsius;
    
    printf("Para obter o valor em Graus Celsius, digite o valor da temperatura em fahrenheit a seguir: ");
    scanf("%f", &fahrenheit);
    
    printf("\n");
    
//Agora definimos a formula
    
    celsius = (fahrenheit - 32) / 1.8;
    
    
    printf("Muito bem! Aqui esta a conversao para Graus Celsius: %.6f\n\n", celsius);
    
/*Para que haja certeza quanto ao resultado, 
damos a opção de conversão para fahrenheit novamente*/

    printf("Para que haja certeza do resultado, insira o valor obtido em Graus Celsius para ser transformado em fahrenheit novamente: ");
    scanf("%f", &celsius);
    
    printf("\n");
    
    fahrenheit = (celsius * 1.8) + 32;
    
    printf("Muito bem! Agora certifique-se que os resultados sao iguais: %.2f\n", fahrenheit);
    
}
