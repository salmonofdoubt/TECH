//Sierpinski - X-eck//

#include <conio.h>
#include <graph.h>
#include <stdlib.h>
#include <stdio.h>

void main( void )
{
   long xhalf, yhalf, x[10],y[10],i, xn,yn;
   struct _videoconfig vc;
   /* Find a valid graphics mode. */
   if( !_setvideomode( _MAXRESMODE ) )
      exit( 1 );    
   _clearscreen( _GCLEARSCREEN );
   _getvideoconfig( &vc );
   xhalf = vc.numxpixels ;
   yhalf = vc.numypixels ;
  
   _rectangle( _GBORDER, 0,  0, xhalf - (short)1, yhalf - (short)1 );      
   _setcolor(2);
   x[0] = 10 ;
   y[0] = 10 ;
   x[1] = xhalf - 10 ;
   y[1] = 10 ;
   x[2] = 10 ;
   y[2] = yhalf-10 ; 
   x[3] = 300 ;
   y[3] = yhalf-20 ; 
   x[4] = 30 ;
   y[4] = yhalf-30 ; 
 
   xn = 20 ;
   yn = 20 ;
                  
   for( i = 0 ; i < 5 ; i++ )
   	_setpixel(x[i],y[i]);
   
   while( _kbhit() == 0 )
   {
   		i = rand() & 0xf ; 
  		if( i >= 5 )
  			continue ;
   		xn = (xn + x[i])/2 ;
   		yn = (yn + y[i])/2 ;   

   		_setpixel(xn,yn);
   		
   }                               
   _getch();  _getch();
   _clearscreen( _GVIEWPORT );
   _setvideomode( _DEFAULTMODE );  
   

}


