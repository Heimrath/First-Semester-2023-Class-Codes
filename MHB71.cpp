//MHB71 - Estrutura de alunos
//Matheus Heimrath Barbosa - 26/05/2023

/* Solicitar os seguintes dados de um aluno
nome, sexo, idade e media final
(usamos neste teste 4 dados de tipos diferentes)
Criar uma estrutura contendo esses tipos
Criar uma funcao que recebe e apresenta esses 4 dados
Reciclar saindo apenas com Enter */

#include <iostream>

void funcAluno(char n[40], char s, int i, float md);
void fclear();

main()
{
	struct staluno  //staluno é apenas o nome da estrutura (nao aloca espaço na memoria)
	{
		char nome[40];
		char sexo;
		int idade; 
		float media;
	};
	
	struct staluno aluno; //Cria a variavel aluno do tipo estrutura. Aqui aloca espaco na memoria para a aestrutura aluno
	
	do
	{
		printf("\nNome (Enter para sair): ");
		gets(aluno.nome);
		
		if(aluno.nome[0] == '\0')   //testa string vazia
		    break;
		    
		printf("\nSexo: ");
		scanf("%c", &aluno.sexo); 
		fclear();
		
		printf("\nIdade: ");
		scanf("%d", &aluno.idade);
		
		printf("\nMedia Final: ");
		scanf("%f", &aluno.media);
		
		//apresenta os dados do aluno
		funcAluno(aluno.nome, aluno.sexo, aluno.idade, aluno.media);
		
		//limpa o buffer de entrada do teclado 
		fclear();
	
	} while (1);
	
	
}

void funcAluno(char n[40], char s, int i, float md)
{
	printf("\n-------------------------------X-------------------------------\n");
	printf("%s\t| %c\t\t | %d\t\t | %.2f", n, s, i, md);
	printf("\n-------------------------------X-------------------------------\n");
	
		
}

//para limpeza do buffer do teclado 
void fclear()
{
	char carac;
	while( ( carac = fgetc(stdin)) != EOF && carac != '\n') {}
}









