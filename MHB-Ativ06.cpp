//MHB-Ativ06 - Intervalo de dias entre duas datas
//Matheus Heimrath Barbosa - 20/05/2023

#include <iostream>

int fAnoBissexto(int a); //retorna 1 se o ano e' bissexto
int fDataValida(int d, int m, int a); //verifica se uma data e' valida indicando qual o erro
int fDiasInicioAno(int d, int m, int a); //retorna a quantidade de dias desde o inicio do ano 
int fDiasFimAno(int d, int m, int a); //retorna a quantidade de dias que faltam para o fim do ano
int fQtdBissextos(int a, int a2);

//Aqui comecamos com a funcao principal
main()
{
	int dia1, mes1, ano1, dia2, mes2, ano2;
	
	do
	{
		printf("Digite duas datas separadas por um espaco (DD/MM/AAAA) (DD == 0 para sair): "); //Primeiro pedimos a data
		scanf("%d/%d/%d %d/%d/%d", &dia1, &mes1, &ano1, &dia2, &mes2, &ano2);
		
		if (dia1 == 0 || dia2 == 0) //caso dia = 0, o programa encerra
		    break;
		if((ano2 < ano1) || ((ano2 == ano1) && (mes2 < mes1)) || ((ano2 == ano1) && (mes2 == mes1) && (dia2 < dia1)))
		    {
		       printf("Insira uma segunda data valida, a mesma deve ser apos a primeira e nao antes!\n");
		       continue;	
			}
		if(fDataValida(dia1, mes1, ano1) && fDataValida(dia2, mes2, ano2)  == 1) //se a funcao DataValida retornar 1 significa que nao ha erros e as informacoes podem ser mostradas
		    //Agora com o total de dias entre os anos, iremos retirar desse total a quantidade que ja se passou desde o inicio do ano da primeira data e somar com a quantidade que ainda falta ate o final da segunda
		    printf("Passaram-se %d dias entre as datas %d/%d/%d - %d/%d/%d.\n\n", fQtdBissextos(ano1, ano2) - fDiasInicioAno(dia1, mes1, ano1) + fDiasInicioAno(dia2, mes2, ano2), dia1, mes1, ano1, dia2, mes2, ano2);
					
	}while (dia1 != 0 || dia2 !=0 ); //tudo isso enquanto o dia for diferente de 0
}

//Agora definimos uma funcao para testar se o ano e' bissexto
int fAnoBissexto(int a)
{
	if (a%400 == 0 || ((a%4 == 0) && (a%100 != 0)))
      	return 1; //caso sim retorna 1
	else
	    return 0;
}
 //Agora criamos uma funcao para verificar se nao houve nenhum erro de digitacao no dia, mes ou ano
int fDataValida(int d, int m, int a)
{
	int ultdia; //ultimo dia do mes
	if (a < 1600 || a > 3000)
	{
		printf("Ano invalido!\n\n");
		return 0;
	}	    
	if (m < 1 || m > 12)
	{
		printf("Mes invalido!\n\n");
		return 0;
	}
	   
	if(d < 1 || d > 31)
	{
		printf("Dia invalido!\n\n"); 
		return 0;
	}
	
	//Aqui definimos os dias de cada mes
	ultdia = 31;
	
	if (m == 4 || m == 6 || m == 9 || m == 11)  
	    ultdia = 30;
	    
	if(m == 2)
	{
	    if(fAnoBissexto(a) == 1)
	        ultdia = 29;
	    else 
	       ultdia = 28;
	}
	
	if(d < 1 || d > ultdia)
	{
		printf("Dia invalido!\n\n");
		return 0;
	}
	
	return 1;
}


//Agora para definirmos quantos dias se passaram, somamos os dias, com a quantidade de dias correspondente ao mes
int fDiasInicioAno(int d, int m, int a)
{
    for(int i=1; i<m; i++)
        {
        if(i==4 || i==6 || i==9 || i==11)
            d+=30;

        else if(i==2)
            {
                if(fAnoBissexto(a)==1)
                    d+=29;

                else
                    d+=28;
            }

        else
            d+=31;
        }
    return d;
}


//E por fim, fazemos a funcao para definir quantos dias restam. Anos bissexto tem 366 - a quantidade de dias que se passaram (fDiasInicioAno), e anos nao bissexto 365.
int fDiasFimAno(int d, int m, int a)
{
    if (fAnoBissexto(a)==1)
        {
        d = 366 - fDiasInicioAno(d, m, a);
        return d;
        }

    else
        {
        d = 365 - fDiasInicioAno(d, m, a);
        return d;
        }
}

//Nessa funcao iremos calcular a quantidade de anos bissextos, somando os dias com a respectiva quantidade de dias no ano
int fQtdBissextos(int a, int a2)
{
	int dias = 0;
	while(a != a2)
	{
		if(fAnoBissexto(a) == 1)		   
		    dias+=366;
		else 
		    dias+=365;
		a++;
	}
	
	return dias;
}

