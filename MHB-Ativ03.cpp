//MHB-Ativ03 - Cálculo de IMC
//Matheus Heimrath Barbosa - 06/04/2023

#include <iostream>

main ()
{
	float imc, peso, altura;
	
	do
	{		
	//Primeiro damos uma breve introdução ao usuário sobre do que se trata o progama.
	printf("===========================================================================================================\n");
	printf("Ola! Aqui vamos calcular seu IMC (Indice de massa corporea)! Para isso precisaremos de algumas informacoes. \n\n");
	
	//Agora pedimos as informações necessárias para o cálculo 	
	printf("Por gentileza insira seu peso em quilogramas (Insira 0 para sair): ");
	scanf("%f", &peso);
	
	if (peso != 0) /*Aqui colocamos um condição if para peso diferente de 0, pois assim a partir daqui 
	               as instruções abaixo so serão processadas caso o usuário insira peso diferente de 0 */
		{
	    printf("Muito bem! Agora preciso que insira sua altura em metros: ");
	    scanf("%f", &altura);
	
	    //Definimos a formula para o cálculo
	    imc = peso / (altura*altura);
	    
	    /*E por fim, damos as condições para determinar a classificação do usuário
	    de acordo com o IMC obtido através do cálculo */
	    
	   	if (altura <= 0 || peso < 0)
	    printf("Insira uma altura ou peso validos!\n\n");
	
	    else if (imc < 18.5)
	    printf("-> Seu IMC = %.3f. Portanto, sua classificacao e' -> Peso Baixo!\n\n", imc);
		
	    else if (imc >= 18.5 && imc < 25)
	    printf("-> Seu IMC = %.3f. Portanto, sua classificacao e' -> Peso Normal!\n\n", imc);
	    
	    else if (imc >= 25 && imc < 30)
	    printf("-> Seu IMC = %.3f. Portanto, sua classificacao e' -> Sobrepeso!\n\n", imc);
	    
	    else if (imc >= 30 && imc < 35)
	    printf("-> Seu IMC = %.3f. Portanto, sua classificacao e' -> Obesidade (Grau I)!\n\n", imc);
	
	    else if (imc >= 35 && imc < 40)
	    printf("-> Seu IMC = %.3f. Portanto, sua classificacao e' -> OBesidade Severa (Grau II)!\n\n", imc);
	    
	    else 
	    printf("-> Seu IMC = %.3f. Portanto, sua classificacao e' -> Obesidade Morbida (Grau III)!\n\n", imc);
	   }
	    
	} while (peso != 0);
}
