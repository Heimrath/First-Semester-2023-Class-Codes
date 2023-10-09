//MHB19 - Calculo da diviao e resto
//Matheus Heimrath Barbosa - 15/03/2023

/*Entrar com dois numeros inteiros: o dividendo e o divisor
Calcular o resultado e o resto da divisao entre eles
Avisar que nao existe divisao por 0*/

#include <iostream>

main()
{
	int n1, n2, result, resto;
	
    printf("Digite dois numeros inteiros (Dividendo e Divisor): ");
    scanf("%d %d", &n1, &n2);
    
    if (n2 == 0)
        printf("Nao ha operacao valida!");
    else
        {
           result = n1/n2;
	       resto = n1%n2;
		   printf("Aqui esta o resultado: %d\nE o resto: %d\n", result, resto); 
		}
}
    
    
  
    
    
    
    
    
    

