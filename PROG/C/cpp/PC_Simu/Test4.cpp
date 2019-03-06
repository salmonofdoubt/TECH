#include	<stdio.h>
#include	<math.h>
    
    
double	f(int n,int z,double x,double y,double vx,double vy,double t)
{                                                              
	double ak ; /* Beschleunigung */ 
	double A,m,cw,g ;
	m = 1.0 ;
	g = 9.81;
    cw= 0.35;
	A = 0.75 ;

	switch(n)      /* Unterscheidung von x und y - Richtung */
	{
		case 1 :
			switch(z);       /* Unterscheidung von f1->v(x) und f2->a(x)*/
			{
				case 1 :
					return(vx);
				case 2 :
				    ak = -vx*cw*A/sqrt(vx*vx + vy*vy)/m ;
					return( ak );	   
				default :
					printf(" Fehler in UP ´f´ x-Richtung ?? z = %d\n",z);
					return(-1.0);
			}		
		case 2 :
				switch(z);   /* Unterscheidung von f1->v(y) und f2->a(y)  */
			    {
				case 1 :
					return(vy);
				case 2 :
			        ak = -m*g - vy*cw*A/sqrt(vx*vx + vy*vy)/m ;
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
	
switch(Ordnung) /* k1 , k2 , k3 , k4 */
{	
	case 1:     /* k1 */
		k=f(raumrichtung,vavariable,x,y,vx,vy,t); 
		return(k);

	case 2 :    /* k2 und k3 */    
	case 3 :
		k=f(raumrichtung,vavariable,(x + (dt/2)*k(Ordnung-1,1,1,x,v,vx,vy,t)), 
									(y + (dt/2)*k(Ordnung-1,2,1,x,v,vx,vy,t)),
									(vx + (dt/2)*k(Ordnung-1,1,2,x,v,vx,vy,t)),
									(vy + (dt/2)*k(Ordnung-1,2,2,x,v,vx,vy,t)),t+dt/2); 
		return(k);

	case 4 :    /* k4 */
		k=f(raumrichtung,vavariable,(x + (dt)*k(Ordnung-1,1,1,x,v,vx,vy,t)), 
									(y + (dt)*k(Ordnung-1,2,1,x,v,vx,vy,t)),
									(vx + (dt)*k(Ordnung-1,1,2,x,v,vx,vy,t)),
									(vy + (dt)*k(Ordnung-1,2,2,x,v,vx,vy,t)),t+dt); 
		return(k);

}
    
          
void	main()    /* Hauptprogramm */
{   
    double xx0,xv0,yx0, yv0,x,v,t,dt,y,yv ;
    double xvvariable;
	FILE *stream;
  
   /* Anfangsparameter */
	    
    xx0 = 0.0 ;    /* Ort x */
    xv0 = 1.0 ;    /* Geschwindigkeit x */
    yx0 = 0.0 ;    /* Ort y */
    yv0 = 1.0 ;    /* Geschwindigkeit y */
    
    x = x0 ;
    v = v0 ;
    dt = 0.1 ;
    
    if(( stream = fopen( "test4.txt", "w" )) == NULL )
    {
    	printf("Kann File ´test4.txt´ nicht öffnen \n");
    	return;
    }
    fprintf(stream,"xx xv yx yv t\n");
    
    for( t = 0 ; t < 200 ; t += dt )
    { 
    	printf(" %e  %e  %e  %e  %e\n",xx,xv,yx,yv,t);
    	fprintf(stream," %e  %e  %e  %e  %e\n",xx,xv,yx,yv,t);  
   	    
   	    for(raumrichtung =0; raumrichtung =1;t+=1)
   	    { 
   	    	for(xvvariable =0; xvvariable =1; t+=1) 
   	    	{
    	
    	    y = (dt/6)*(k11(x,v,t,dt)+2*k21(x,v,t,dt)+2*k31(x,v,t,dt)+k41(x,v,t,dt));   		
    	
    		}
    	}	
    	
    	x += y ;
    	v += yv ;
   	}
	
	fclose(stream);
}  


