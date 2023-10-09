//MHB09 - Calculando notas de alunos
//Matheus Heimrath Barbosa - 08/03/2023

//Dadas 3 notas de aluno, calcular a media aritmetica
/*Mostrar a media nos seguintes casos:
sem edição de valor;
com 1 e 3 casas decimais;
sem casas decimais.*/

#include <iostream>

main()
{
	float nota1, nota2, nota3, media;
	nota1 = 8.52;
	nota2 = 4.30;
	nota3 = 6.00;
	media = (nota1 + nota2 + nota3)/3;
	
	printf("Media: %f\n", media); //apenas %f para a nota sem edição 
	printf("Media: %.1f\n", media); //.1 para 1 casa decimal
	printf("Media: %.3f\n", media); //.3 para 3 casas decimais
	printf("Media: %.0f\n", media); //.0 para nenhuma casa decimal
}



