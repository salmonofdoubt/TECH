#include	<stdio.h>
#include	<math.h>
    
    
double	f1(double x,double v,double t)
{
	return(v);
}

double	f2(double x,double v,double t)
{         
	double m,g,l,D,y ;
	
	m = 1.0 ;
	g = 9.81 ;
	l = 1.0 ;
	D = 0.1 ;
	
	y = -(m*g/l)*sin(x) - D*v ; 
	
	return(y);
}


void	main()
{   
    double x0,v0,x,v,t,dt ;
	FILE *stream;
	    
    x0 = 1.2 ;
    v0 = 0.0 ; 
    x = x0 ;
    v = v0 ;
    dt = 0.1 ;
    if(( stream = fopen( "test.txt", "w" )) == NULL )
    {
    	printf("Kann File ´test.txt´ nicht öffnen \n");
    	return;
    }
    fprintf(stream,"x  v  t\n");
    
    for( t = 0 ; t < 20 ; t += dt )
    { 
    	printf(" %e  %e  %e\n",x,v,t);
    	fprintf(stream," %e  %e  %e\n",x,v,t);
   
    	
    	x += dt*f1(x,v,t);
    	v += dt*f2(x,v,t);
    }
	
	fclose(stream);
}  


