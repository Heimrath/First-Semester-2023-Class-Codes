//MHB-Ativ02 - Calculo de impressao
//Matheus Heimrath Barbosa - 27/03/2023

#include <iostream>

main()
{
	
	//Damos uma introdução ao usuario
	
	printf("Ola! Sou uma calculadora de tempo de impressao, basta digitar quantas paginas deseja imprimir que irei calcular.\n\n");
	
	/*Primeiro definimos as variaveis de tipo inteiro 
	para todas a informações que queremos. */
	
	int qpag, fv, qh, qm, qs, pag_min, pag_seg; 
	
	/*Agora o campo a ser preenchido com a quantidade de 
	paginas e se é ou nao frente-e-verso. */
	
	printf("Digite a quantidade de paginas que deseja imprimir: ");
	scanf("%d", &qpag);
	
	printf("Digite se deseja frente-e-verso ou nao (1 para sim ou 0 para nao): ");
	scanf("%d", &fv);
	
	/*Agora definimos a condicao caso seja numero negativo, frente-e-verso e junto as formulas. 
	E por fim damos o resultado ao usuario contendo a informação se a impressao foi frente-e-verso ou nao */
	
	if (qpag < 0)
	   {
	   	printf("Insira um numero inteiro positivo!!\n");
	   	 
	   }
	   
	else if (fv == 0)
	   {
	   pag_min = 5;
	   pag_seg = 60/pag_min; //60 segundos divido pela quantidade de paginas por minutos (1 min = 60seg) = 1 pag a cada 12 seg
	   qh = (qpag/pag_min)/60;
	   qm = (qpag/pag_min) - (qh*60);
	   qs = (qpag%pag_min)*pag_seg; 
	
	   printf("A opcao escolhida foi: SEM frente-e-verso. Portanto a impressao de %d paginas ira levar: %d horas %d minutos e %d segundos\n", qpag,qh, qm, qs);
	   }
	   
	else if (fv == 1)
	   {
	   pag_min = 4;
	   pag_seg = 60/pag_min; //60 segundos divido pela quantidade de paginas por minutos (1 min = 60seg) = 1 pag a cada 15 seg
	   qh = (qpag/pag_min)/60;
	   qm = (qpag/pag_min) - (qh*60);
	   qs = (qpag%pag_min)*pag_seg; 
	
	   printf("A opcao escolhida foi: COM frente-e-verso. Portanto a impressao de %d paginas ira levar: %d horas %d minutos e %d segundos\n", qpag, qh, qm, qs);
	   }
	
	else
	   printf("Nao foi inserido um indicador correto!\n");
	   
	return 0;
	
}