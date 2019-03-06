#include	<stdio.h>
#include	<math.h>
    
    
double	f(int n,int z,double x,double y,double vx,double vy,double t)
{                                                              
	double ak ; /* Beschleunigung */ 
	double A,m,cw,g ;
	m = 1.0 ;
	g = 9.81;
    cw= 0.3;
	A = 0.2 ;

	switch(n)      /* Unterscheidung von x und y - Richtung */
	{
		case 1 :
			switch(z)       /* Unterscheidung von f1->v(x) und f2->a(x)*/
			{
				case 1 :
					return(vx);    		/* dx/dt	*/
					break;
					
				case 2 :
				    ak = -vx*cw*A/m ;   /* dvx/dt	*/
					return( ak );	   
					break ;
					
				default :
					printf(" Fehler in UP ´f´ x-Richtung ?? z = %d\n",z);
					return(-1.0);
			}		
		case 2 :
				switch(z)   /* Unterscheidung von f1->v(y) und f2->a(y)  */
			    {
				case 1 :
					return(vy);				/* dy/dt	*/
				case 2 :
			        ak = -g - vy*cw*A/m ;	/*	dvy/dt	*/
			        return(ak);   
			   	default :
					printf(" Fehler in UP ´f´ y-Richtung ?? z = %d\n",z);
					return(-1.0);
	            }
	  default :
				printf(" Fehler in UP ´f´ ?? n = %d\n",n);
				return(-1.0);       
	}			
}


        
double	k(int Ordnung,int raumrichtung, int vavariable,double x,double y,double vx,double vy,double t, double dt)
{
	double k0 ;	
switch(Ordnung) /* k1 , k2 , k3 , k4 */
{	
	case 1:     /* k1 */
		k0=f(raumrichtung,vavariable,x,y,vx,vy,t); 
		return(k0);

	case 2 :    /* k2 und k3 */    
	case 3 :
		k0=f(raumrichtung,vavariable,(x + (dt/2)*k(Ordnung-1,1,1,x,y,vx,vy,t,dt)), 
									(y + (dt/2)*k(Ordnung-1,2,1,x,y,vx,vy,t,dt)),
									(vx + (dt/2)*k(Ordnung-1,1,2,x,y,vx,vy,t,dt)),
									(vy + (dt/2)*k(Ordnung-1,2,2,x,y,vx,vy,t,dt)),t+dt/2); 
		return(k0);

	case 4 :    /* k4 */
		k0=f(raumrichtung,vavariable,(x + (dt)*k(Ordnung-1,1,1,x,y,vx,vy,t,dt)), 
									(y + (dt)*k(Ordnung-1,2,1,x,y,vx,vy,t,dt)),
									(vx + (dt)*k(Ordnung-1,1,2,x,y,vx,vy,t,dt)),
									(vy + (dt)*k(Ordnung-1,2,2,x,y,vx,vy,t,dt)),t+dt); 
		return(k0);
		
	default :
		printf("Fehler in UP ´k()´: Ordnung = %d\n",Ordnung);
	}
    return(0.0);
}
    
          
void	main()    /* Hauptprogramm */
{   
    double x0,y0,vx0,vy0,x,y,vx,vy,t,dt ;
    double dxv[6];
    int xvvariable,raumrichtung; 
    int i;
	FILE *stream;
  
   /* Anfangsparameter */
	    
    x0  = 0.0 ;     /* Ort x */
    vx0 = 1.0 ;    /* Geschwindigkeit x */
    y0  = 0.0 ;      /* Ort y */
    vy0 = 1.0 ;    /* Geschwindigkeit y */
    
    x   = x0 ;
    y   = y0 ;
    vx  = vx0;
    vy  = vy0;
    dt = 0.01 ;        
    i = 0;
    
    if(( stream = fopen( "test4.txt", "w" )) == NULL )
    {
    	printf("Kann File ´test4.txt´ nicht öffnen \n");
    	return;
    }
    fprintf(stream,"x y vx vy t\n");
    
    for( t = 0 ; t < 40 ; t += dt )   /* Zeitintervalle */
    { 
    	i = 0;
    	printf(" %e  %e  %e  %e  %e\n",x,y,vx,vy,t);
    	fprintf(stream," %e  %e  %e  %e  %e\n",x,y,vx,vy,t);  
   	    
   	    for(raumrichtung =1; raumrichtung < 3;raumrichtung++ )
   	    {   
   	        
   	    	for(xvvariable =1; xvvariable < 3 ; xvvariable++ ) 
   	    	{
    	        	    
      	    	dxv[++i] = (dt/6)*(k(1,raumrichtung,xvvariable,x,y,vx,vy,t,dt)         /*Runge Kutta 4.Ordnung */
    	          	            +2*k(2,raumrichtung,xvvariable,x,y,vx,vy,t,dt)
    	            	        +2*k(3,raumrichtung,xvvariable,x,y,vx,vy,t,dt)
    	                  	      +k(4,raumrichtung,xvvariable,x,y,vx,vy,t,dt));   		
    	
    		}
    	}	
    	
    	x  += dxv[1];
    	vx += dxv[2];
    	y  += dxv[3];
    	vy += dxv[4];
    }
	
	fclose(stream);
}  


