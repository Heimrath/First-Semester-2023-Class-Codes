//MHB39 - Conversao em temperaturas
//Matheus Heimrath Barbosa - 12/04/2023

/*Informar uma temperatura, indicando a unidade
C = Celsius ou F = Farenheit
Fazer a conversao para a outra unidade e apresenta-la
F = (9 * C/5) + 32;
Reciclar o programa e sair quando for digitado "X" na unidade */ 

#include <iostream>

main()
{
	float temp1, temp2;
	char unid;
	
	do 
	{
		printf("Digite a temperatura e sua unidade (C = Celsius ou F = Farenheit) (X na unidade para sair): ");
		scanf("%f %c", &temp1, &unid);
		
		if ((unid == 'X') || (unid == 'x'))
		    break;
		
		if(unid == 'c' || unid == 'C')
		{
		   	temp2 = (9 * temp1/5) + 32;
		   	printf("%.6f C -------> %.6f F\n", temp1, temp2);
		}
	
		else if(unid == 'f' || unid == 'F')
		{
			temp2 = ((temp1 - 32)*5)/9;
			printf("%.6f F -------> %.6f C\n", temp1, temp2);
		}
		
		else 
		    printf("Unidade invalida!\n");
		
	} while (unid != 'X' && unid != 'x');
	

}