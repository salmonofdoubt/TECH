#include	<stdio.h>
#include	<math.h>
    
#define	DIMENSION	100
#define	ITERATION	1000

float		T[DIMENSION][DIMENSION] ;
float far	T_alt[DIMENSION][DIMENSION] ;
          
void	main()    /* Hauptprogramm */
{   
	FILE *stream; 
	int	i,j,k,ip1,im1,jp1 ;		
    float c,dt,dx,alpha ;
        
    c     = 1.0;
    dt    = 0.1;
    dx    = 0.1;
	alpha = 0.5 ;        
    if(( stream = fopen( "temperat.txt", "w" )) == NULL )
    {
    	printf("Kann File ´temperat.txt´ nicht öffnen \n");
    	return;
    }        
    
    // Initialisiere T_alt :
    for( i = 0 ; i < DIMENSION ; i++ )
    	for( j = 0 ; j < DIMENSION ; j++ )
    		T_alt[i][j]=0.0f;
    for( j = 0 ; j < DIMENSION ; j++ )
    	T_alt[DIMENSION/2][j] = 1000.0 ;
             
    for( k = 0 ; k < ITERATION ; k++ )
    {
    	printf(" Iteration = %d\n",k);
    	for ( i=0; i < DIMENSION ; i++ )
    	{       
    		if(( ip1 = ( i + 1 )) >= DIMENSION )
    			ip1 = DIMENSION -1 ;
    		if(( im1 = ( i - 1 )) < 0 )
    			im1 = 0 ;
    		
    		for( j = 1 ; j < DIMENSION ; j++ )
    		{
    			if(( jp1 = ( j + 1 )) >= DIMENSION )
    				jp1 = DIMENSION -1 ;
    			T[i][j] = (T_alt[ip1][j]+T_alt[im1][j])/2 - ((dx*dx)/(2*c*c*dt))*( T_alt[i][jp1] - T_alt[i][j-1]);
    		}
    	}  
	    for( i = 0 ; i < DIMENSION ; i++ )
    		for( j = 1 ; j < DIMENSION ; j++ )
    			T_alt[i][j] += alpha*( T[i][j]-T_alt[i][j] );
    	
    } 
    for( i = 0 ; i < DIMENSION ; i++ )        
    {
    	for( j = 0 ; j < DIMENSION ; j++ )
    		fprintf(stream,"%f ",T_alt[i][j]);
    	fprintf(stream,"\n");
    }
    	
	fclose(stream);
}  


