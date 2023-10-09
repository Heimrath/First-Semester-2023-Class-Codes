//MHB-Ativ04 - Sequencia de numeros 
//Matheus Heimrath Barbosa - 26/04/2023

#include <iostream>

main()
{
	//Definimos as variaveis, reservando 20 numeros a variavel N
	int N[20], i, func; 
	
	//Aqui usamos o "for" junto da variavel "i" para obter os 20 numeros
	for(i = 0; i < 20; i++)
	{
		printf("%.2d - Digite um numero inteiro: ", i);
	    scanf("%d", &N[i]);
	}
	    
	do //Colocamos o menu de opcoes em loop "do-while"
	{
		printf("\n\nSelecione uma opcao:\n1. Apresentar todos os numeros digitados na ordem de entrada\n2. Apresentar todos os numeros digitados na ordem inversa de entrada\n3. Apenas os numeros multiplos de 3\n4. Apenas os numeros precedidos na entrada por um numero par\nOutro qualquer. Para sair do programa\n");
		scanf("%d", &func);
	  //E agora definimos o que deve ser feito para cada opcao 	
		switch(func)
        {
			case 1:
	        {   //Aqui ele sempre apresentara o numero em ordem de digitacao somando 1 ao "i"
			    for(i = 0; i < 20; i++) 
		        printf("%d(%d)\t", N[i], i);
		        break;
	        }
			   		       
            case 2:
		    {   //Aqui ele comecará de tras para frente, diminuindo 1 de "i", mostrando assim os numeros na ordem inversa de digitacao
			    for(i = 19; i >= 0; i--)
		        printf("%d(%d)\t", N[i], i);
			    break;		
		    }   
			   		       
		    case 3:
		    {   
			    for(i = 0; i < 20; i++)
			    {      //Aqui definimos para caso o resto da divisao entre o numero digitado e o 3 seja 0, ele mostrara na tela apenas esses numeros
				    if(N[i] % 3 == 0)
		    	    printf("%d(%d)\t", N[i], i);
			    }		
			    break;			
		    }
		   		
		    case 4:
		    {
			    for(i = 0; i < 19; i++)
		        {   //Ja na opcao 4 queremos apenas os numeros seguidos de numeros pares
		            if(N[i] % 2 == 0)  //Por isso colocamos uma condicao "if", para se caso o numero for par
		            {                  //ele ira somar 1 ao "i", pegando assim o proximo numero e mostrando na tela
		        	++i;  
				    printf("%d(%d)\t", N[i], i);
					--i;   //e apos isso ele voltara o "i" ao que era, subitraindo o 1 que lhe foi somando antes		            
				    }
			    }
			    break;
	        }
	    
	        default:
	    	    break;
	    }
	    
	} while((func == 1) || (func == 2) || (func == 3) || (func == 4)); //E por fim, colocamos no "while" que tudo isso vai rodar enquanto os numeros digitados
}                                                                      //no menu de opcoes forem iguais a 1, 2, 3 ou 4. Caso seja diferente o progama para
