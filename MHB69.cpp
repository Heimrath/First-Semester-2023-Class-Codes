#include <iostream>

main()
{
	char Tab[20][30];
	int i, j; //i = linha ; j = coluna 
	
	Tab[i][j] = '.'; 
	
	printf("\t");
	for(j = 0; j < 30; j++)
	    printf("%2d  ", j);
	    
	printf("\n\n");
	
	for(i= 0; i<20; i++)
	{
		printf("%2d", i);
		printf("\t");
		for(j = 0; j < 30; j++)
	    {
	    	Tab[i][j] = '.';
	    	printf("%2c  ",Tab[i][j]);
		}
	    printf("\n");
	}
	
    int x,y;
    
    do
    {
    	
    	printf("Insira as coordenadas (x = linha , y = coluna) ((-1, -1) para sair): ");
    	scanf("%d,%d", &x, &y);
    	
    	if(x == -1 && y == -1)
    	    break;
    	else if ((x > 20 || y > 30) || (x < -1 || y < -1))
    	{
    		printf("Coordenadas erradas, insira novamente!\n");
    		continue;
		}
		
    	Tab[x][y] = 'x';
    	
    	printf("\n\t");
    	    	
	    for(j = 0; j < 30; j++)
	        printf("%2d  ", j);
	        
	    printf("\n\n");
	        
	    for(i= 0; i<20; i++)    
	    {
		    printf("%2d", i);
		    printf("\t");
		    
		    for(j = 0; j < 30; j++)
	        {
	    	    
	    	     printf("%2c  ",Tab[i][j]);
		    }
		    
	        printf("\n");
	    }
    	
    	
	} while (x != -1 &&  y != -1);
	        
	
}