//JLM - HOTEL

void fimprimirtab (char tab[20][14]);
void fReservaCheckin (int l, int c, char tab[20][14]);
int fReserva(int l, int c, char tab[20][14]);

#include <iostream>
main()
{	
	char tabe[20][14];
	int l=20,c=14,menu,lr,cr;
		
	for(l = 0; l <20; l++)
	{
		for (c = 0; c < 14; c++)
		{
			tabe[l][c] = '.';
		}
	}
	
	printf("SEJA BEM-VINDO! Escolha no menu a opcao desejada (Caso deseje sair digite 0):\n");
	
	do
	{
		
	    printf("\n(1) - Mapa de quartos.\n(2) - Reservar quarto.\n(3) - Fazer checkin.\n\n(R):. ");
	    scanf("%d",&menu);
		int repet=0;
		int vdd=0;
	
	
	do
{
	
        switch(menu)            
	    {
	        default: 
		    break;
					
		    case 1:
			    system("cls");
			    fimprimirtab(tabe);	
				repet++;						
			    break;
	
		    case 2:
		    	if(vdd == 0)
				{
	    	    system("cls");
		        fimprimirtab(tabe);
		    	}
			    printf("\nQual quarto deseja (Andar, Quarto)\n(R):.");
			    scanf("%d %d",&lr,&cr);
		
			    if( (lr<=20 && lr >= 1) && (cr<=14 && cr>=1))
			    {											
				    lr--; cr--;
				    if(fReserva ( lr, cr,tabe)==1)
							{
							vdd++;
							menu =2;
							}
							else 
							{
							repet++;
							}
				    
				    
				    
		        }
							
			    else
			    {
			        if(lr>20 || lr < 1 )
					{
					printf("\nO andar nao existe!\n");	
						menu =2 ;
								vdd++;
						}	
			            
																				
				    if(cr>14 || cr < 1 ) 
					{
						printf("\nO quarto nao existe!\n");
							menu =2 ;
								vdd++;
						}	
				        
			    }			
			    break;
					
		    case 3: 
		        system("cls");
			    fimprimirtab(tabe);
			    printf("\nDigite o quarto para o checkin (Andar, Quarto) \n(R):.");
			    scanf("%d %d",&lr,&cr);
															
			    if( (lr<=20 && lr >= 1) && (cr<=14 && cr>=1) )
			    {
				    lr--; cr--;
				    fReservaCheckin(lr, cr, tabe);	
					repet++;						
                }
							
			    else
			    {
				    if(lr>20 || lr < 1 )
				        printf("\nO andar nao existe!\n");
								
				    if(cr>14 || cr < 1 ) 	
				        printf("\nO quarto nao existe!\n");
			    }
	            break;
											
       }
	   	}while(repet==0);	
	}while(menu!=0);
}
	
void fimprimirtab (char tab[20][14])
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
			printf("%2c  ", tab[l][c]);
		
		printf("\n");
	}	
}

void fReservaCheckin (int l, int c, char tab[20][14])
{
	if(tab[l][c]=='.')
		printf("\nEste quarto nao esta reservado!\n");							
		
	else if (tab[l][c]=='O')	
		printf("\nEste quarto ja esta ocupado!\n");
		
	else 
	{
		tab[l][c] ='O';
		system("cls");
		fimprimirtab(tab);
		printf("\nQuarto %d do andar %d foi ocupado com sucesso!\n",c+1,l+1);
	}			
}
	
int fReserva (int l, int c, char tab[20][14])
{
	if(tab[l][c]=='O'){
		printf("\nEste quarto ja esta ocupado!\n");
		return 1;}
							
	else if(tab[l][c]=='R'){
	
		printf("\nEste quarto ja esta reservado!\n");
		return 1;}
						
	else 
	{
		tab[l][c] ='R';
		system("cls");
		fimprimirtab(tab);
		printf("\nQuarto %d do andar %d foi reservado com sucesso!\n",c+1,l+1);
			return 0;			
	}			
}
	
	
	
	
	
	
	
