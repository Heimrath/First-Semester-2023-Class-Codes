//MHB40 - 
//Matheus Heimrath Barbosa - 14/04/2023

/*Reciclar o seguinte progama 
Entrar com dois numeros do tipo flutuante
Apresentar um menu com as opções
0 - saida para outro numero 
1 - soma
2 - subtração
3 - multiplicação
4 - divisão
usando o comando "Switch" para executar a operação selecionada
com 4 casas decimais, retornando sempre para o menu
Na opção "0" do menu, o progama retorna a pedir os dois numeros iniciais
Sair do progama se os ambos numeros forem 0 */

#include <iostream>

main()
{
	float n1, n2;
	int oper;
	
	do
	{
		printf("Insira 2 numeros quaisquer: ");
		scanf("%f %f", &n1, &n2);
		
		if ((n1 == 0) && (n2 == 0))
		    break;
		do 
		{
			printf(" 0 - saida para outro numero\n 1 - soma\n 2 - subtracao\n 3 - multiplicacao\n 4 - divisao\nDigite sua opcao: ");
			scanf("%d", &oper);
			
			if (oper > 4 || oper < 0)
					printf("Operador invalido, leia novamente para ter certeza que inseriu um numero de operacao valido!\n\n");
					
			switch(oper)
			{
				case 1:
					printf("%f + %f = %.4f\n\n", n1, n2, n1+n2);
					break;
					
				case 2:
					printf("%f - %f = %.4f\n\n", n1, n2, n1-n2);
					break;
				
				case 3:
				    printf("%f * %f = %.4f\n\n", n1, n2, n1*n2);
					break;
					
				case 4:
					if (n2 == 0)
					{
						printf("Operacao invalida! Nao ha divisao por 0!\n\n");
					}
					else
					printf("%f / %f = %.4f\n\n", n1, n2, n1/n2);
					break;
			} 
			
			 
		} while (oper != 0);
		
	} while ((n1 != 0) || (n2 != 0));
	
	
	
	
	
	
}