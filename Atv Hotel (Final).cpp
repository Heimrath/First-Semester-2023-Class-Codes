//JLM-Hotel04 - 22/06/2023
//Joao Guilherme Costa Couto 
//Luis Augusto Coelho de Souza
//Matheus Heimrath Barbosa
//Entrega Final para apresentacao

#include <iostream>

typedef struct endereco //Cria o novo tipo de dado que armazena os dados de endereco do hospede
{
	char endereco[60];
	char municipio[20];
	char estado[20];
	char cep[9];
} tipoCasa;
	
typedef struct cliente //Cria o novo tipo de dado que armazena os dados pessoais do hospede e seu endereco
{
	char CPF[14];
	char Nome[50];
	char telefone[15];
	char email[25];
	int idade;
	tipoCasa endereco;
} tipoHospede;
	
typedef struct apartamento //Cria o novo tipo de dado que armazena todos os dados do hospede
{
	char situacao;
	tipoHospede cliente;
} tipoQuarto; 
	
void fimprimirtab (tipoQuarto tab[20][14]); //Imprime o mapa de quartos
int fCheckinSemReserva (int l, int c, tipoQuarto tab[20][14]); //Faz o checkin do usuario sem reserva caso tudo esteja correto
int fReserva(int l, int c, tipoQuarto tab[20][14]); //Faz a reserva caso tudo esteja correto
int fCheckout(int l, int c, tipoQuarto tab[20][14]); //Faz o checkout de um quarto selecionado 
int fCancelarReserva (int l, int c, tipoQuarto tab[20][14]); //Faz o cancelamento de uma reserva 
int fCheckinReserva (int l, int c, tipoQuarto tab[20][14]); //Faz o checkin do usuario que possui reserva caso tudo esteja correto
void fArmazenadados (int l, int c, tipoQuarto tab[20][14]); //Armazena os dados do usuario que faz uma reserva ou checkin
int fVerificaCPF (char ID[14], int l, int c, tipoQuarto tab[20][14]); //Verifica se o CPF do usuario fazendo Checkin, Checkout ou Cancelamento de Reserva para saber se ele que selecionou o quarto ao inicio
void fPorcentagemReOc (tipoQuarto tab[20][14]); //Mostra a porcentagem de ocupacao, reserva e de quartos livres
void fclear(); //Realiza a limpeza de Buffer do teclado

main()
{	
	tipoQuarto tabe[20][14]; //inicializa o vetor Bidimensional de estrutura que controla o mapa de quartos
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
	printf("SEJA BEM-VINDO! Escolha no menu a opcao desejada: \n");
	
	do //Inicia loop que ira repetir o menu e o switch, tendo fim apenas ao digitar 0
	{		
	    printf("\n(1) - Mapa de quartos.\n(2) - Reservar quarto.\n(3) - Cancelar Reserva.\n(4) - Fazer CheckIn sem reserva.\n(5) - Fazer CheckIn com reserva.\n(6) - Fazer CheckOut.\n(7) - Visualizar situacao de um apartamento.\n(8) - Taxas de Reserva, ocupacao e quartos livres.\n(9) - Fechar Programa.\n(R):. ");
	    scanf("%d",&menu); //Recebe a opcao digitada no menu
		
		int repet=0; //A sentinela repet controla o loop de reuso do menu
		int erro=0; //A sentinela erro contabiliza se ha (erro!=0) ou nao (erro==0) erros para que a tela nao seja apagada e o usuario corrija o erro

		do //inicia loop controlado pela sentinela repet. Caso repet tenha valor diferente de 0, o loop sera interrompido, voltando ao menu
		{  //Dessa maneira, o usuario pode selecionar varias opcoes em um acesso ao programa	
	
        	switch(menu)            
	    	{				
				case 1: //para opcao 1
		 	        system("cls"); //Limpa a tela das mensagens antigas
		 	        fimprimirtab(tabe);	//Chama a funcao que imprime o Mapa de quartos
				    repet++; //repet recebe 1 para quebrar o loop 						
				    break; //Finaliza a opcao 1
					
				case 2: //para opcao 2
				    if(erro==0) //Iniciada com 0, o codigo rodara uma primeira vez apagando a tela 
	    	    	{    system("cls"); //Limpa a tela das mensagens antigas
		        	    fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
		    		}
			    	    printf("\n------Digite qual quarto deseja RESERVAR no formato: Andar Quarto (digite 0 0 para voltar ao menu)------\n(R):.");
			            scanf("%d %d",&lr,&cr);
			    	
				    if(lr==0 && cr ==0) //Caso o usuario deseje retornar a selecao de opcoes sem reservar um quarto pode digitar 0 0
					{
					    repet++; //repet recebe 1 para quebrar o loop
					    system("cls"); //Limpa a tela das mensagens antigas
					    fimprimirtab(tabe);
					    break; //finaliza o case 2
					}
			    	
				    if((lr<=20 && lr >= 1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{											
					    lr--; cr--;	//Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0				    
				        system("cls"); //Limpa a tela das mensagens antigas
		        	    fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
		        	    
					    if(fReserva (lr, cr, tabe)==1) //Se a funcao apontar 1, serao escritas apenas as correcoes a serem feitas 	
						    erro++; //Se a funcao apontar 1, ha um erro na entrada assim erro recebe 1 e o usuario vai repetir a escolha do quarto sem que a tela seja apagada 		  	
					
					    else //Se a funcao receber 0 ela so Realizara a reserva do quarto
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
				    break; //Fim do case 2
				
				case 3: //para opcao 3
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
					    fimprimirtab(tabe);
					    break; //Finaliza a opcao 3
					}											
			    
				    if((lr<=20 && lr>=1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{
				        lr--; cr--; //Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0				    
				 	    system("cls"); //Limpa a tela das mensagens antigas
		        	    fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
				    
					    if(fCancelarReserva(lr, cr, tabe)==1) //Se a funcao apontar 1, serao escritas apenas as correcoes a serem feitas 
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
				    break; //Fim do case 3
				
				case 4: //para opcao 4				
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
				    	fimprimirtab(tabe);
				        break; //Finaliza a opcao 4
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
				    break; //Fim do case 4
				
				case 5: //para opcao 5
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
					    fimprimirtab(tabe);
					    break; //Finaliza a opcao 5
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
				    break; //Fim do case 5
			
				case 6: //para opcao 6
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
					    fimprimirtab(tabe);
					    break; //Finaliza a opcao 6
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
				    break; //Fim do case 6
				
				case 7: //para opcao 7
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
					    fimprimirtab(tabe);
					    break; //Finaliza a opcao 7
					}											
			    
				    if((lr<=20 && lr>=1) && (cr<=14 && cr>=1)) //Verifica se o andar e o quarto estao dentro dos parametros permitidos
			    	{
				        lr--; cr--; //Diminui os valores recebidos em 1 para que sejam comparaveis com a Matriz pois ela comeca em 0				    
				        system("cls"); //Limpa a tela das mensagens antigas
		        	    fimprimirtab(tabe); //imprime novamente a tabela para ajudar o usuario a se guiar
					
					    if(tabe[lr][cr].situacao == 'O') //Se o quarto estiver ocupado mostra os dados da pessoa que o ocupa
					    {
						    printf("\n------O Quarto %d do andar %d esta ocupado pela pessoa cujos dados sao:------\n",cr+1,lr+1);
						    printf("CPF: %s\n", tabe[lr][cr].cliente.CPF);
						    printf("Nome: %s\n", tabe[lr][cr].cliente.Nome);
						    printf("Idade: %d\n", tabe[lr][cr].cliente.idade);
						    printf("Endereco: %s, %s-%s, %s\n", tabe[lr][cr].cliente.endereco, tabe[lr][cr].cliente.endereco.municipio, tabe[lr][cr].cliente.endereco.estado, tabe[lr][cr].cliente.endereco.cep);
						    printf("Celular: %s\n", tabe[lr][cr].cliente.telefone);
						    printf("Email: %s\n", tabe[lr][cr].cliente.email);
						    printf("-----------------------------------------------------------------------------\n");
						    repet++;
					    }
					    
					    else if(tabe[lr][cr].situacao == 'R') //Se o quarto estiver reservado mostra os dados da pessoa que o reservou
					    {
						    printf("\n------O Quarto %d do andar %d esta reservado pela pessoa cujos dados sao:------\n",cr+1,lr+1);
						    printf("CPF: %s\n", tabe[lr][cr].cliente.CPF);
						    printf("Nome: %s\n", tabe[lr][cr].cliente.Nome);
						    printf("Idade: %d\n", tabe[lr][cr].cliente.idade);
						    printf("Endereco: %s, %s-%s, %s\n", tabe[lr][cr].cliente.endereco, tabe[lr][cr].cliente.endereco.municipio, tabe[lr][cr].cliente.endereco.estado, tabe[lr][cr].cliente.endereco.cep);
						    printf("Celular: %s\n", tabe[lr][cr].cliente.telefone);
						    printf("Email: %s\n", tabe[lr][cr].cliente.email);
						    printf("-----------------------------------------------------------------------------\n");
						    repet++;
					    }
					    
					    else //Se o quarto estiver livre mostra o status livre
					    {
						    printf("\n------O Quarto %d do andar %d esta livre!------\n",cr+1,lr+1);
					        repet++;
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
				    break;	//Fim do case 7    
				    
	            case 8: //Para opcao 8
				    system("cls"); //Limpa a tabela 
				    fPorcentagemReOc (tabe); //Chama a funcao void que calcula e imprime as taxas de ocupacao, reserva e de quartos livres
				    repet++; //repet recebe 1 para quebrar o loop
				    break; //Fim do case 8
				
				case 9:
					repet++; //repet recebe 1 para quebrar o loop e apos a quebra desse loop sera testada while(menu!=0) 
				    break;	 //O que fara com que o usuario saia do programa
								
				default: //Se o numero da opcao for invalido
	 			{       
	       			repet++; //repet recebe 1 para quebrar o loop
	       			printf("\n------Digito de menu invalido(tente novamente)------\n");
		   			break; 
				}
														
    		}
    		
		}while(repet==0); //Comando sentinela que permite que o usuario acesse o menu multiplas vezes 	
		
	}while(menu!=9); //Se menu = 0 o programa sera interrompido
	
}
	
void fimprimirtab (tipoQuarto tab[20][14]) //Imprime o mapa de quartos
{
	printf("\n\tQuartos ->\t"); 
	
	for (int c = 0; c < 14; c++)
		printf("%2d  ",c+1);
		
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

int fCheckinSemReserva (int l, int c, tipoQuarto tab[20][14]) //Faz o checkin do usuario sem reserva caso tudo esteja correto
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
		fArmazenadados(l, c, tab); //Chama a funcao responsavel por armazenar os dados do hospede no ponto correspondente da estrutura
		system("cls"); //Limpa a tela das mensagens anteriores
		fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Ocupada
		printf("\n------Checkin do Quarto %d do andar %d foi feito com sucesso!------\n",c+1,l+1);
		return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()
	}			
}
	
int fReserva (int l, int c, tipoQuarto tab[20][14]) //Faz a reserva caso tudo esteja correto
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
		fArmazenadados (l, c, tab); //Chama a funcao responsavel por armazenar os dados do hospede no ponto correspondente da estrutura
		system("cls"); //Limpa a tela das mensagens anteriores
		fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Reservada
		printf("\n------Quarto %d do andar %d foi reservado com sucesso!------\n",c+1,l+1);
			return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()			
	}			
}




int fCheckout(int l, int c, tipoQuarto tab[20][14]) //Faz o checkout de um quarto selecionado 
{
    char CPF[14]; //Inicia a variavel que vai receber o CPF do hospede que quer fazer checkout
	
	if (tab[l][c].situacao=='R' || tab[l][c].situacao=='.' )  //Se a posicao estiver reservada ou livre:
	{
		printf("\n-> Nao ha como fazer o checkout do quarto %d do andar %d pois ele ainda nao foi ocupado(tente novamente)\n",c+1,l+1);
		return 1; //retorna 1 ao valor da funcao para fazer a verificacao no main()
	}  
        
    else //Se estiver ocupada
    {
		//Para evitar que outro hospede efetue um checkout em um quarto que nao e seu, vamos conferir seu CPF
    	fclear();
		printf("Digite o CPF do hospede que deseja fazer o checkout para confirmacao: "); 
    	gets(CPF);
    	
    	if(fVerificaCPF(CPF, l, c, tab)==1) //Se o CPF for o mesmo realiza o Checkout
		{	
			tab[l][c].situacao ='.'; //Libera a posicao
        	system("cls"); //Limpa a tela anterior
        	fimprimirtab(tab); //Imprime a tela novamente
        	printf("\n-> CheckOut do quarto %d do andar %d foi realizado com sucesso!\n",c+1,l+1);
        	return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()
    	}
    	
    	else //Se nao for apresenta o erro e faz o usuario selecionar outro quarto
    	{
    		printf("\n-> O CPF dado no Checkin do quarto nao corresponde ao CPF digitado\n");
			return 1;	
		}
	}            
}    

int fCancelarReserva (int l, int c, tipoQuarto tab[20][14]) //Faz o cancelamento de uma reserva 
{
	char CPF[14]; //Inicia a variavel que vai receber o CPF do hospede que quer fazer o cancelamento da reserva
	
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
		//Para evitar que outro hospede efetue um cancelamento de uma reserva em um quarto que nao e seu, vamos conferir seu CPF
		fclear();
		printf("\nDigite o CPF do hospede que deseja fazer o cancelamento da reserva para confirmacao: "); 
    	gets(CPF);
    	
		if(fVerificaCPF(CPF, l, c, tab)==1) //Se o CPF for o mesmo realiza o cancelamento da Reserva
		{
			tab[l][c].situacao ='.'; //Libera a posicao
			system("cls"); //Limpa a tela das mensagens anteriores
			fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Livre
			printf("\n------Reserva do Quarto %d do andar %d foi cancelada com sucesso!------\n",c+1,l+1);
			return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()			
		}
		
		else //Se nao for apresenta o erro e faz o usuario selecionar outro quarto
		{
			printf("\n-> O CPF dado na Reserva do quarto nao corresponde ao CPF digitado\n");
			return 1;	
		}
	}
}

int fCheckinReserva (int l, int c, tipoQuarto tab[20][14]) //Faz o checkin do usuario que possuir uma reserva caso tudo esteja correto
{
	 char CPF[14]; //Inicia a variavel que vai receber o CPF do hospede que quer fazer o checkin
	 
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
		//Pega o CPF para verificar se esse e o hospede que fez a reserva
		fclear();
		printf("Digite o CPF para confirmacao: ");
	 	gets(CPF);
		
		if(fVerificaCPF(CPF, l, c, tab)==1)	//Se o CPF for o mesmo faz o Checkin
		{	
			tab[l][c].situacao ='O'; //Ocupa a posicao
			system("cls"); //Limpa a tela das mensagens anteriores
			fimprimirtab(tab); //Imprime novamente a tabela, agora com a posicao selecionada Ocupada
			printf("\n------Checkin do Quarto %d do andar %d foi feito com sucesso!------\n",c+1,l+1);
			return 0; //retorna 0 ao valor da funcao para fazer a verificacao no main()
		}
		
		else //Se nao for pede para o usuario colocar novamente o quarto
		{
			printf("\n-> O CPF dado na reserva do quarto nao corresponde ao CPF digitado\n");
			return 1;
		} 			
	}			
}

void fArmazenadados (int l, int c, tipoQuarto tab[20][14]) //Armazena os dados do usuario que faz uma reserva ou checkin
{
	//Recolhe os dados do hospede
	printf("\nDigite os dados do hospede: ");
	
	fclear();
	printf("\nNome: ");
	gets(tab[l][c].cliente.Nome);
	
	printf("\nIdade: ");
	scanf("%d", &tab[l][c].cliente.idade);
	
	fclear();
	printf("\nCPF: ");
	gets(tab[l][c].cliente.CPF);
				
	printf("\nEmail: ");
	gets(tab[l][c].cliente.email);
	
	printf("\nTelefone: ");
	gets(tab[l][c].cliente.telefone);
		
	printf("\nEndereco: ");
	gets(tab[l][c].cliente.endereco.endereco);
	
	printf("\nMunicipio: ");
	gets(tab[l][c].cliente.endereco.municipio);
	
	printf("\nEstado: ");
	gets(tab[l][c].cliente.endereco.estado);
	
	printf("\nCEP: ");
	gets(tab[l][c].cliente.endereco.cep);

}	

int fVerificaCPF (char ID[14], int l, int c, tipoQuarto tab[20][14]) //Verifica se o CPF do usuario fazendo Checkin, Checkout ou Cancelamento de Reserva para saber se ele que selecionou o quarto ao inicio
{
	int i=0, TamanhoID=0, TamanhoCPF=0; //Inicia a variavel que vai controlar o caractere lido, o Tamanho do ID (CPF recolhido na confirmacao) e o Tamanho do CPF

	while(ID[TamanhoID]!='\0') //Conta o tamanho da string ID, que e o CPF recolhido na confirmacao
	{
		TamanhoID++;
	}
	
	while(tab[l][c].cliente.CPF[TamanhoCPF]!='\0') //Conta o tamanho da string CPF, Coletado no armazenamento de dados na reserva ou checkin
	{
		TamanhoCPF++;
	}
	
	if(TamanhoID!=TamanhoCPF) //Se as strings tiverem tamanhos diferentes ele nao fara nem a leitura e ja marca os dois dados como diferentes
		return 0;

	//Inicia o leitor de strings
	while (ID[i]!='\0' && tab[l][c].cliente.CPF[i]!='\0') //Enquanto as strings que Contem o dado armazenado na operacao (ID) e a que contem o dado no quarto selecionado nao terminarem
	{
        if (ID[i]!=tab[l][c].cliente.CPF[i]) //Se for encontrado um caractere diferente
		{
            return 0; //retorna 0 para funcao indicando CPF diferente 
            break;
        }
       	i++; //Vai para proxima letra
    }
    		
	return 1; //Se nenhum dos testes resultar em strings diferentes, retorna 1 indicando CPFs iguais
}

void fPorcentagemReOc (tipoQuarto tab[20][14]) //Mostra a porcentagem de ocupacao, reserva e de quartos livres
{
	int reservado=0, ocupado=0, Total=0; //Inicializa as variaveis
	float TxOcup, TxReser, TxQuartoL;
	
	//Inicia o leitor da matriz
	for(int l = 0; l <20; l++) 
	{
		for (int c = 0; c < 14; c++)
		{
			if(tab[l][c].situacao=='O') //Se encontrar um quarto ocupado adiciona 1 a variavel ocupado
				ocupado++;
			
			else if (tab[l][c].situacao=='R') //Se encontrar um quarto reservado adiciona 1 a variavel reservado
				reservado++;	
		}
	}
	
	Total = 20*14; //Calcula quantos quartos Tem o hotel no total
	TxOcup = ocupado/(Total/100.0); //Calcula a taxa de ocupacao
	TxReser = reservado/(Total/100.0); //Calcula a taxa de reservas
	TxQuartoL = 100 - TxOcup - TxReser; //Calcula a taxa de quartos livres
	
	printf("\n-----------------------------------------");
	printf("\n--> Taxa de ocupacao: %.2f%%", TxOcup);
	printf("\n--> Taxa de reservas: %.2f%%", TxReser);
	printf("\n--> Taxa de quartos livres: %.3f%%", TxQuartoL);
	printf("\n-----------------------------------------\n");
}



void fclear() //Realiza a limpeza de Buffer do teclado
{
	char carac;
	while( ( carac = fgetc(stdin)) != EOF && carac != '\n') {}
}
