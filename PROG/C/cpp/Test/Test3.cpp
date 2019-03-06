#include	<stdio.h>
#include	<math.h>
    
    
double	f1(double x,double v,double t)
{
	return(v);
}

double	f2(double x,double v,double t)
{         
	double m,g,l,D,y,A,w ;
	
	m = 1.0 ;
	g = 9.81;
	l = 9.81 ;
	D = 0.1 ; 
	A = 0.75 ;
	w = sqrt(g/l)*0.666 ;
	
	y = -(m*g/l)*sin(x) - D*v + A*sin(w*t); 
	
	return(y);
}


double	k11(double x,double v,double t, double dt)
{
	return(f1(x,v,t));
}
       
double	k12(double x,double v,double t, double dt)
{
	return(f2(x,v,t));
}
        
double	k21(double x,double v,double t, double dt)
{
	return(f1(x+(dt/2)*k11(x,v,t,dt),v+(dt/2)*k12(x,v,t,dt),t+dt/2));
}
       
double	k22(double x,double v,double t, double dt)
{
	return(f2(x+(dt/2)*k11(x,v,t,dt),v+(dt/2)*k12(x,v,t,dt),t+dt/2));
}
double	k31(double x,double v,double t, double dt)
{
	return(f1(x+(dt/2)*k21(x,v,t,dt),v+(dt/2)*k22(x,v,t,dt),t+dt/2));
}
       
double	k32(double x,double v,double t, double dt)
{
	return(f2(x+(dt/2)*k21(x,v,t,dt),v+(dt/2)*(k22(x,v,t,dt)),t+dt/2));
} 
double	k41(double x,double v,double t, double dt)
{
	return(f1(x+dt*(k31(x,v,t,dt)),v+dt*(k32(x,v,t,dt)),t + dt));
}
       
double	k42(double x,double v,double t, double dt)
{
	return(f2(x+dt*(k31(x,v,t,dt)),v+dt*(k32(x,v,t,dt)),t + dt));
}    
          
void	main()
{   
    double x0,v0,x,v,t,dt,y,yv ;
	FILE *stream;
	    
    x0 = 1.2 ;
    v0 = 0.0 ; 
    x = x0 ;
    v = v0 ;
    dt = 0.1 ;
    if(( stream = fopen( "test3.txt", "w" )) == NULL )
    {
    	printf("Kann File ´test3.txt´ nicht öffnen \n");
    	return;
    }
    fprintf(stream,"x  v  t\n");
    
    for( t = 0 ; t < 200 ; t += dt )
    { 
    	printf(" %e  %e  %e\n",x,v,t);
    	fprintf(stream," %e  %e  %e\n",x,v,t);  
   	
    	y = (dt/6)*(k11(x,v,t,dt)+2*k21(x,v,t,dt)+2*k31(x,v,t,dt)+k41(x,v,t,dt));   		
    	yv = (dt/6)*(k12(x,v,t,dt)+2*k22(x,v,t,dt)+2*k32(x,v,t,dt)+k42(x,v,t,dt));    
    	
    	x += y ;
    	v += yv ;
   	}
	
	fclose(stream);
}  


