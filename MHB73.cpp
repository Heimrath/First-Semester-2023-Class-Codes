//MHB73 - Estrutura de um grupo dee amigos 
//Matheus Heimrath Barbosa - 31/05/2023

/* Criar uma estrutura contendo os seguintes dados de cada amigo
nome, celular e idade
o grupo dereva ter 4 amigos
Criar uma funcao que apresente esses dados */

#include <iostream>

void fGrupo(struct stamigo am[50]);
void fclear();

struct stamigo
{
	char nome[40];
	char cel[12];
	int idade;
};

main()
{
	struct stamigo amigo[50]; //cria um vetor do tipo struct stamigo (reserva espaco)
	int i;
	
	for(i = 0; i < 50; i++)
	{
		printf("\nNome %d: ", i+1);
		gets(amigo[i].nome);
		
		if(amigo[i].nome[0] == '\0')   //testa string vazia
		    break;
		    
		printf("\nCelular: ");
		gets(amigo[i].cel);
		
		printf("\nIdade: ");
		scanf("%d", &amigo[i].idade);
		
	    fclear();
	}
	
	fGrupo(amigo);
}

void fGrupo(struct stamigo am[50])
{
	system("cls"); //limpa a tela
	int j; 
	printf("\nGrupo de amigos\n--------------------------------\n");
	for(j = 0; j<50; j++)
	{
		printf("%s\n", am[j].nome);
		printf("%s\n", am[j].cel);
		printf("%d\n", am[j].idade);
		printf("\n");
		
		
	}
	
}
void fclear()
{
	char carac;
	while( ( carac = fgetc(stdin)) != EOF && carac != '\n') {}
}