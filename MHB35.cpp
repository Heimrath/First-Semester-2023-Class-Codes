//MHB35 - Contagem com do-while
//Matheus Heimrath Barbosa - 05/04/2023

//Contagem de 1600 até 2023 de 10 em 10
//usando tabulação e o comando do-while()

#include <iostream>

main()
{
	
	int n;
	n = 1600; 
	
	do //SEMPRE executa o bloco de codigo pelo menos 1 vez
	   //mesmo que a expressao do while for falsa
	{
		printf("%d\t", n);
		n = n + 10;
		
	} while (n <= 2023); //caso o 1600 fosse trocado por 5000, ele iria aparecer, e so ele
	
}