//JLM-Hotel02 - 09/06/2023
//Joao Guilherme Costa Couto 
//Luis Augusto Coelho de Souza
//Matheus Heimrath Barbosa
//Requisitos 04, 05, 06 do Projeto Hotel LIC

#include <iostream>

typedef struct apartamento
{
	char endereco[40];
	char nome[40];
	char cpf[15];
    char telefone[15];
    char email[40];	
	char situacao;
	
} tipoApto;

void fclear();
void fimprimirtab (tipoApto tab[20][14]); //Imprime o mapa de quartos
int fCheckinSemReserva (int l, int c, tipoApto tab[20][14]); //Faz o checkin do usuario sem reserva caso tudo esteja correto
int fReserva(int l, int c, tipoApto tab[20][14]); //Faz a reserva caso tudo esteja correto
int fCheckout(int l, int c, tipoApto tab[20][14]); //Faz o checkout de um quarto selecionado 
int fCancelarReserva (int l, int c, tipoApto tab[20][14]); //Faz o cancelamento de uma reserva 
int fCheckinReserva (int l, int c, tipoApto tab[20][14]); //Faz o checkin do usuario que possui reserva caso tudo esteja correto
void fDadosHospede(int l, int c, tipoApto tab[20][14]);


main()
{	

    int ocupado=0;
    int reservado=0;
    
	tipoApto tabe[20][14]; //inicializa o vetor Bidimensional que mostra o mapa de quartos
	int l=20, c=14, menu, lr, cr; //inicializa as variaveis l (linhas) e c(colunas) que vao construir a matriz
								  //menu que controla o switch e lr(linha recebida), cr(coluna recebida) que armazenam a escolha do usuario
	
	//Constroi a Matriz de mapa de quartos	
	for(l = 0; l <20; l++) 
	{
		for (c = 0; c < 14; c++)
		{
			tabe[l][c].situacao = '.';
		}
	}
	
	printf("SEJA BEM-VINDO! Escolha no menu a opcao desejada (Caso deseje sair digite 0):\n");
	
	do //Inicia loop que ira repetir o menu e o switch, tendo fim apenas ao digitar 0
	{
		
	    printf("\n(1) - Mapa de quartos.\n(2) - Reservar quarto.\n(3) - Fazer CheckIn sem reserva.\n(4) - Fazer CheckOut.\n(5) - Cancelar Reserva.\n(6) - Fazer CheckIn com reserva.\n(7) - Verificar situacao de um quarto.\n(8) - Taxa Ocupacao dos quartos.\n(R):. ");
	    scanf("%d",&menu); //Recebe a opcao digitada no menu
		
		int repet=0; //A sentinela repet controla o loop de reuso do menu
		int erro=0; //A sentinela erro contabiliza se ha (erro!=0) ou nao (erro==0) erros para que a tela nao seja apagada e o usuario corrija o erro

		do //inicia loop controlado pela sentinela repet. Caso repet tenha valor diferente de 0, o loop sera interrompido, voltando ao menu
		{  //Dessa maneira, o usuario pode selecionar varias opcoes em um acesso ao programa	
	
        	switch(menu)            
	    	{	
				case 0: //para opcao 0
				repet++; //repet recebe 1 para quebrar o loop e apos a quebra desse loop sera testada while(menu!=0) 
				break;	 //O que fara com que o usuario saia do programa
				
				case 1: //para opcao 1
		 	    system("cls"); //Limpa a tela das mensagens antigas
		 	    fimprimirtab(tabe);	//Chama a funcao que imprime o Mapa de quartos
				repet++; //repet recebe 1 para quebrar o loop 						
				break;
	
				case 2: //para opcao 2
		    	if(erro==0) //Iniciada com 0, o codigo rodara uma primeira vez apagando a tela 
					{
		
	    	    	system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
		    		}
			    	
				printf("\n------Digite qual quarto deseja RESERVAR no formato: Andar Quarto (digite 0 0 para voltar ao menu)------\n(R):.");
			    scanf("%d %d",&lr,&cr);
			    	
				if(lr==0 && cr ==0) //Caso o usuario deseje retornar a selecao de opcoes sem reservar um quarto pode digitar 0 0
					{
					repet++; //repet recebe 1 para quebrar o loop
					system("cls"); //Limpa a tela das mensagens antigas
					break; //finaliza o case 2
					}
			    	
				if((lr<=20 && lr >= 1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{											
					lr--; cr--;	//Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0
				    
				    system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
					if(fReserva (lr, cr,tabe)==1) //Se a funcao apontar 1, serao escritas apenas as correcoes a serem feitas 	
						erro++; //Se a funcao apontar 1, ha um erro na entrada assim erro recebe 1 e o usuario vai repetir a escolha do quarto sem que a tela seja apagada 		  	
					
					else //Se a funcao receber 0 ela so Realizara a reserva do quarto
					{
						fDadosHospede(lr, cr, tabe);
						repet++; //repet recebe 1 para quebrar o loop
					}
					
					}
							
			    else //Define as mensagens de erro para ajudar o usuario a reescrever o texto 
			    	{
			       	//Como os if nao estao encadeados, testara as duas condicoes imprimindo apenas 1 ou as 2
				 	
					system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
		        	
				    if(lr>20 || lr < 1 ) //Se o andar estiver incorreto
						{
						printf("\n-> O andar %d nao existe!",lr);	
						erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}	
			            
																				
				    if(cr>14 || cr < 1 ) //Se o Quarto estiver incorreto
						{
						printf("\n-> O quarto %d nao existe!\n",cr);
						erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}    
			    	}				
				    break; //Fim do case 2
					
				case 3: //para opcao 3
				if(erro==0)
					{
		        	system("cls"); //Limpa a tela das mensagens antigas
			    	fimprimirtab(tabe); //Imprime a tabela novamente
					}
			    
				printf("\n------Digite o quarto para o CHECKIN no formato: Andar Quarto(digite 0 0 para voltar ao menu)------\n(R):.");
			    scanf("%d %d",&lr,&cr);
				
				if(lr==0 && cr==0) //Caso o usuario deseje retornar a selecao de opcoes sem fazer checkin pode digitar 0 0
					{
					repet++; //repet recebe 1 para quebrar o loop
					system("cls"); //Limpa a tela das mensagens antigas
					break; //Finaliza a opcao 3
					}											
			    
				if((lr<=20 && lr>=1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{
				    lr--; cr--; //Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0
				    
				    system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
					if(fCheckinSemReserva(lr, cr, tabe)==1) //Se a funcao apontar 1, serao escritas apenas as correcoes a serem feitas 
						erro++; //Se a funcao apontar 1, ha um erro no codigo assim erro recebe 1 e o usuario vai repetir a escolha do quarto sem que a tela seja apagada						 
						
					else //Se a funcao apontar 0, sera feito o checkin no quarto
						repet++; //repet recebe 1 para quebrar o loop					
					}
							
			    else //Define as mensagens de erro para ajudar o usuario a reescrever o texto 
			    	{
			    	//Como os if nao estao encadeados, testara as duas condicoes imprimindo apenas 1 ou as 2	
			    	system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
					if(lr>20 || lr < 1 ) //Se o andar estiver incorreto
				    	{
				   		printf("\n-> O andar %d nao existe!",lr);	
				   		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}
				        			
				    if(cr>14 || cr < 1 ) //Se o Quarto estiver incorreto	
				    	{
				    	printf("\n-> O quarto %d nao existe!\n",cr);
				  		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}  
			    	}
				break; //Fim do case 3
				
				case 4: //para opcao 4
				if(erro==0)
					{
		        	system("cls"); //Limpa a tela das mensagens antigas
			    	fimprimirtab(tabe); //Imprime a tabela novamente
					}
			    
				printf("\n------Digite o quarto para o CHECKOUT no formato: Andar Quarto(digite 0 0 para voltar ao menu)------\n(R):.");
			    scanf("%d %d",&lr,&cr);
				
				if(lr==0 && cr==0) //Caso o usuario deseje retornar a selecao de opcoes sem fazer checkout pode digitar 0 0
					{
					repet++; //repet recebe 1 para quebrar o loop
					system("cls"); //Limpa a tela das mensagens antigas
					break; //Finaliza a opcao 4
					}											
			    
				if((lr<=20 && lr>=1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{
				    lr--; cr--; //Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0
				    
				    system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
					if(fCheckout(lr, cr, tabe)==1) //Se a funcao apontar 1, serao escritas apenas as correcoes a serem feitas 
						erro++; //Se a funcao apontar 1, ha um erro no codigo assim erro recebe 1 e o usuario vai repetir a escolha do quarto sem que a tela seja apagada						 
						
					else //Se a funcao apontar 0, sera feito o checkout no quarto
						repet++; //repet recebe 1 para quebrar o loop					
					}
							
			    else //Define as mensagens de erro para ajudar o usuario a reescrever o texto 
			    	{
			    	//Como os if nao estao encadeados, testara as duas condicoes imprimindo apenas 1 ou as 2
					system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar	
		        	
					if(lr>20 || lr < 1 ) //Se o andar estiver incorreto
				    	{
				   		printf("\n-> O andar %d nao existe!",lr);	
				   		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}
				        			
				    if(cr>14 || cr < 1 ) //Se o Quarto estiver incorreto	
				    	{
				    	printf("\n-> O quarto %d nao existe!\n",cr);
				  		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}  
			    	}
				break; //Fim do case 4
				
				case 5: //para opcao 5
				
				if(erro==0)
					{
		        	system("cls"); //Limpa a tela das mensagens antigas
			    	fimprimirtab(tabe); //Imprime a tabela novamente
					}
			    
				printf("\n------Digite o quarto que deseja CANCELAR a RESERVA no formato: Andar Quarto (digite 0 0 para voltar ao menu)------\n(R):.");
			    scanf("%d %d",&lr,&cr);
				
				if(lr==0 && cr==0) //Caso o usuario deseje retornar a selecao de opcoes sem cancelar uma reserva pode digitar 0 0
					{
					repet++; //repet recebe 1 para quebrar o loop
					system("cls"); //Limpa a tela das mensagens antigas
					break; //Finaliza a opcao 5
					}											
			    
				if((lr<=20 && lr>=1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{
				    lr--; cr--; //Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0
				    
				 	system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
				    
					if(fCancelarReserva(lr, cr, tabe) == 1)//Se a funcao apontar 1, serao escritas apenas as correcoes a serem feitas 
						erro++; //Se a funcao apontar 1, ha um erro no codigo assim erro recebe 1 e o usuario vai repetir a escolha do quarto sem que a tela seja apagada						 
						
					else //Se a funcao apontar 0, sera feito o cancelamento da reserva no quarto
						repet++; //repet recebe 1 para quebrar o loop					
					}
							
			    else //Define as mensagens de erro para ajudar o usuario a reescrever o texto 
			    	{
			    	//Como os if nao estao encadeados, testara as duas condicoes imprimindo apenas 1 ou as 2
					
					system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar	
		        	
					if(lr>20 || lr < 1 ) //Se o andar estiver incorreto
				    	{
				   		printf("\n-> O andar %d nao existe!",lr);	
				   		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}
				        			
				    if(cr>14 || cr < 1 ) //Se o Quarto estiver incorreto	
				    	{
				    	printf("\n-> O quarto %d nao existe!\n",cr);
				  		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}  
			    	}
				break; //Fim do case 5
				
				case 6: //para opcao 6
				if(erro==0)
					{
		        	system("cls"); //Limpa a tela das mensagens antigas
			    	fimprimirtab(tabe); //Imprime a tabela novamente
					}
			    
				printf("\n------Digite o quarto para o CHECKIN com RESERVA no formato: Andar Quarto(digite 0 0 para voltar ao menu)------\n(R):.");
			    scanf("%d %d",&lr,&cr);
				
				if(lr==0 && cr==0) //Caso o usuario deseje retornar a selecao de opcoes sem fazer checkin pode digitar 0 0
					{
					repet++; //repet recebe 1 para quebrar o loop
					system("cls"); //Limpa a tela das mensagens antigas
					break; //Finaliza a opcao 6
					}											
			    
				if((lr<=20 && lr>=1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{
				    lr--; cr--; //Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0
				    
				    system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
					if(fCheckinReserva(lr, cr, tabe)==1) //Se a funcao apontar 1, serao escritas apenas as correcoes a serem feitas 
						erro++; //Se a funcao apontar 1, ha um erro no codigo assim erro recebe 1 e o usuario vai repetir a escolha do quarto sem que a tela seja apagada						 
						
					else //Se a funcao apontar 0, sera feito o checkin no quarto caso o usuario possua uma reserva
						repet++; //repet recebe 1 para quebrar o loop					
					}
					
							
			    else //Define as mensagens de erro para ajudar o usuario a reescrever o texto 
			    	{
			    	//Como os if nao estao encadeados, testara as duas condicoes imprimindo apenas 1 ou as 2
					system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar	
		        	
					if(lr>20 || lr < 1 ) //Se o andar estiver incorreto
				    	{
				   		printf("\n-> O andar %d nao existe!",lr);	
				   		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}
				        			
				    if(cr>14 || cr < 1 ) //Se o Quarto estiver incorreto	
				    	{
				    	printf("\n-> O quarto %d nao existe!\n",cr);
				  		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}  
			    	}
				break; //Fim do case 6
				
				case 7:
					if(erro==0)
					{
		        	system("cls"); //Limpa a tela das mensagens antigas
			    	fimprimirtab(tabe); //Imprime a tabela novamente
					}
			    
				printf("\n------Digite o quarto para visualizar o estado do quarto: Andar Quarto(digite 0 0 para voltar ao menu)------\n(R):.");
			    scanf("%d %d",&lr,&cr);
				
				if(lr==0 && cr==0) //Caso o usuario deseje retornar a selecao de opcoes sem fazer checkin pode digitar 0 0
					{
					repet++; //repet recebe 1 para quebrar o loop
					system("cls"); //Limpa a tela das mensagens antigas
					break; //Finaliza a opcao 6
					}											
			    
				if((lr<=20 && lr>=1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{
				    lr--; cr--; //Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0
				    
				    system("cls"); //Limpa a tela das mensagens antigas
		        	fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
					
					if(tabe[l][c].situacao == 'O')
					{
						printf("\n------O Quarto %d do andar %d esta ocupado pela pessoa cuja os dados sao:------\n",cr+1,lr+1);
						printf("CPF: %s\n", tabe[lr][cr].cpf);
						printf("Nome: %s\n", tabe[lr][cr].nome);
						printf("Endereco: %s\n", tabe[lr][cr].endereco);
						printf("Celular: %s\n", tabe[lr][cr].telefone);
						printf("Email: %s\n", tabe[lr][cr].email);
						repet++;
					}
					else if(tabe[l][c].situacao == 'R')
					{
						printf("\n------O Quarto %d do andar %d esta reservado!------\n",cr+1,lr+1);
						repet++;
					}
					else 
					{printf("\n------O Quarto %d do andar %d esta livre!------\n",cr+1,lr+1);
					repet++;
					}
					
							
					}
							
			        else 
			    	{
			    	
					system("cls"); 
		        	fimprimirtab(tabe); 
		        	
					if(lr>20 || lr < 1 ) 
				    	{
				   		printf("\n-> O andar %d nao existe!",lr);	
				   		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}
				        			
				    if(cr>14 || cr < 1 ) //Se o Quarto estiver incorreto	
				    	{
				    	printf("\n-> O quarto %d nao existe!\n",cr);
				  		erro++; //Como ha um erro, ao receber 1 a sentinela fara com que o codigo nao seja apagado para que o usuario corrija o erro
						}  
			    	}		
			        break;
				
				case 8: 
				    if(erro==0)
					{
		        	system("cls"); //Limpa a tela das mensagens antigas
			    	fimprimirtab(tabe); //Imprime a tabela novamente
					}
			    
					ocupado=0;
					reservado=0;
	
			    	for(l = 0; l <20; l++) 
					{
						for (c = 0; c < 14; c++)
							{
								if(tabe[l][c].situacao=='O') ocupado++;
								else if (tabe[l][c].situacao=='R')reservado++;
								
							}
					}
						
				    printf("---A tava de ocupacao eh de %0.2f porcento!---\n",(ocupado/2.8));
			        printf("---A tava de reserva eh de %0.2f porcento!---\n",reservado/2.8);
			        repet++;
				
			    	break;
			
				
				default: //Se o numero da opcao for invalido
	 				{       
	       			repet++; //repet recebe 1 para quebrar o loop
	       			printf("\n------Digito de menu invalido(tente novamente)------\n");
		   			break; 
					}										
    		}
		}while(repet==0); //Comando sentinela que permite que o usuario acesse o menu multiplas vezes 	
	}while(menu!=0); //Se menu = 0 o programa sera interrompido

}
	
void fimprimirtab (tipoApto tab[20][14]) //Imprime o mapa de quartos
{
	printf("\n\tQuartos ->\t"); 
	
	for (int c = 0; c < 14; c++)
		{
		printf("%2d  ",c+1);
		}
	
	printf("\n\n");
	
	for(int l = 19; l >= 0; l--)
		{
		printf("\tAndar %2d",l+1);
		printf("\t");
		for (int c = 0; c < 14; c++)
			printf("%2c  ", tab[l][c].situacao);
		
		printf("\n");
		}	
}

int fCheckinSemReserva (int l, int c, tipoApto tab[20][14]) //Faz o checkin do usuario sem reserva caso tudo esteja correto
{
	 if (tab[l][c].situacao=='R') //Se a posicao de entrada estiver sido reservada:	
		{
		printf("\n-> Nao ha como fazer o checkin do quarto %d do andar %d pois ele esta reservado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()
		}
	 
								
	 else if (tab[l][c].situacao=='O') //Se a posicao de entrada estiver sido reservada e ocupada:	
		{
		printf("\n-> Nao ha como fazer o checkin do quarto %d do andar %d pois ele esta ocupado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()
		}
	
	else //Se a posicao de entrada estiver livre:
		{
		tab[l][c].situacao ='O'; //Ocupa a posicao
		system("cls"); //Limpa a tela das mensagens anteriores
		fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Ocupada
		printf("\n------Checkin do Quarto %d do andar %d foi feito com sucesso!------\n",c+1,l+1);
		return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()
		}			
}
	
int fReserva (int l, int c, tipoApto tab[20][14]) //Faz a reserva caso tudo esteja correto
{
	if(tab[l][c].situacao=='O') //Se a posicao de entrada estiver sido reservada e ocupada:
		{
		printf("\n-> Nao ha como reservar o quarto %d do andar %d pois ele esta ocupado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()		
		}
							
	else if(tab[l][c].situacao=='R') //Se a posicao de entrada estiver reservada:
		{
		printf("\n-> Nao ha como reservar o quarto %d do andar %d pois ele ja foi reservado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()		
		}
						
	else //Se a posicao estiver livre:
		{
		tab[l][c].situacao ='R'; //Reserva a posicao
		system("cls"); //Limpa a tela das mensagens anteriores
		fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Reservada
		printf("\n------Quarto %d do andar %d foi reservado com sucesso!------\n",c+1,l+1);
			return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()			
		}			
}




int fCheckout(int l, int c, tipoApto tab[20][14]) //Faz o checkout de um quarto selecionado 
{
    if (tab[l][c].situacao=='R' || tab[l][c].situacao=='.' )  //Se a posicao estiver reservada ou livre:
	{
		printf("\n-> Nao ha como fazer o checkout do quarto %d do andar %d pois ele ainda nao foi ocupado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()
	}  
        

    else //Se estiver ocupada
    {
        tab[l][c].situacao ='.'; //Libera a posicao
        system("cls"); //Limpa a tela anterior
        fimprimirtab(tab); //Imprime a tela novamente
        printf("\n-> CheckOut do quarto %d do andar %d foi realizado com sucesso!\n",c+1,l+1);
        return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()
    }            
}    

int fCancelarReserva (int l, int c, tipoApto tab[20][14]) //Faz o cancelamento de uma reserva 
{
	if(tab[l][c].situacao=='O') //Se a posicao de entrada estiver sido reservada e ocupada:
		{
		printf("\n-> Nao ha como cancelar a reserva do quarto %d do andar %d pois ele ja esta ocupado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()		
		}
							
	else if(tab[l][c].situacao=='.') //Se a posicao de entrada estiver livre:
		{
		printf("\n-> Nao ha como cancelar a reserva do quarto %d do andar %d pois ele esta vazio(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()		
		}
						
	else //Se a posicao estiver reservada:
		{
		tab[l][c].situacao ='.'; //Libera a posicao
		system("cls"); //Limpa a tela das mensagens anteriores
		fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Livre
		printf("\n------Reserva do Quarto %d do andar %d foi cancelada com sucesso!------\n",c+1,l+1);
			return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()			
		}
}

int fCheckinReserva (int l, int c, tipoApto tab[20][14]) //Faz o checkin do usuario que possuir uma reserva caso tudo esteja correto
{
	 if (tab[l][c].situacao=='.') //Se a posicao de entrada estiver livre:	
		{
		printf("\n-> Nao ha como fazer o checkin do quarto %d do andar %d pois ele nao esta reservado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()
		}
	 
								
	 if (tab[l][c].situacao=='O') //Se a posicao de entrada estiver sido reservada e ocupada:	
		{
		printf("\n-> Nao ha como fazer o checkin do quarto %d do andar %d pois ele esta ocupado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()
		}
		
		
	else //Se a posicao de entrada estiver reservada:
	{
			char cpf[15];
			printf("DIgite o Cpf: ");
			gets(cpf);
			
		if(cpf == tab[l][c].cpf)
		{
			tab[l][c].situacao ='O'; //Ocupa a posicao
		system("cls"); //Limpa a tela das mensagens anteriores
		fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Ocupada
		printf("\n------Checkin do Quarto %d do andar %d foi feito com sucesso!------\n",c+1,l+1);
		return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()
		}
		
		else
		{
			printf("O cpf nao corresponde ao digitado na reserva!0");
			return 1;
		}
		
	}			
}

void fDadosHospede(int l, int c, tipoApto tab[20][14])
{
	printf("Digite seu nome: ");
	fclear();
	gets(tab[l][c].nome);
	
	printf("\nDigite seu CPF: ");
	gets(tab[l][c].cpf);
	
	printf("\nDigite seu email: ");
	gets(tab[l][c].email);
	
	printf("\nDigite seu endereco: ");
	gets(tab[l][c].endereco);
	
	printf("\nDigite seu telefone: ");
	gets(tab[l][c].telefone);
}

void fclear()
{
	char carac;
	while ( (carac = fgetc (stdin)) != EOF && carac != '\n') {}
}

