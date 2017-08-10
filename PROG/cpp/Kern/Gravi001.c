#include	<stdio.h>
#include	<graphics.h>
#include	<process.h>
#include	<conio.h>
#include    <dos.h>

#define		Y_UNTEN		479           /* die Koordinaten des Displays       */
#define		Y_OBEN		0
#define		X_LINKS		0
#define		X_RECHTS	639

#define		XW_LINKS		(X_LINKS+10)  /* die Koordinaten des Darstellungsfensters */
#define		XW_RECHTS	  (X_RECHTS-10)
#define		YW_OBEN		  (Y_OBEN+5)
#define		YW_UNTEN		(Y_UNTEN-5)

float		x_von = -6.0E11 ;           /* definiere den physikalischen Raum  */
float		x_bis = +6.0E11 ;
float		y_von = -6.0E11 ;
float		y_bis = +6.0E11 ;

#include	<math.h>

int		display(float x,float y, int color, int delet,int groesse, float x_old, float y_old);

/* definiere hier die notwendigen globalen Variablen :                    */
#define      ANZAHL   20          /* rechne mit maximal 20 Himmelsk”rpern */
#define      PLANETEN 8          /* Zahl der real beobachteten Himmelsk”rper */

int          radius[] = { 2,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,} ;

float        y[ANZAHL][2][2],k1[ANZAHL][2][2],k2[ANZAHL][2][2],y_alt[ANZAHL][2][2];
float        m[ANZAHL] ;          /* die Massen der K”rper                */
int          farbe[] = { YELLOW, GREEN,RED,LIGHTBLUE,MAGENTA,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
    } ;

#define      GAMMA     6.67E-11
float yy[ANZAHL][2][2],t,dt ;

main()
{
	int	i1,i2,i3 ;			/* definiere einige Indexvariablen	*/
    int delet ;         /* 1 mal zeichnen, dann immer l”schen + zeichnen   */
    float f(int i1,int i2,int i3,float yy[ANZAHL][2][2],int t);

	i1 = VGA ;		/* initialisiere die Grafik		*/
	i2 = VGAHI ;
	initgraph(&i1,&i2,"c:\\TC\\BGI\\");
	if( i1 < 0 )		/* Grafik l„át sich nicht initialisieren ?	*/
	{
		printf("Error #001 ? initgraph (%d)\n",i1);
		getch();
		exit(1);
	}
	setcolor(WHITE);
	rectangle(X_LINKS,Y_UNTEN,X_RECHTS,Y_OBEN);

    /* initialisiere die Felder :                                */
    /* Sonne :                                                   */
    y[0][0][0] = 0.0 ;          /* Masse 0, X-Koordinate, Ort    */
    y[0][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[0][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[0][1][1] = 0.0 ;          /*        , Y-Koordinate, Geschw.*/

    /* Merkur :                                                  */
    y[1][0][0] = 5.79E10 ;      /* Masse 1, X-Koordinate, Ort    */
    y[1][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[1][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[1][1][1] = 6.28*y[1][0][0]/7.60E6 ;/* Y-Koordinate, Geschw.*/

    /* Venus :                                                   */
    y[2][0][0] = 1.08E11 ;      /* Masse 2, X-Koordinate, Ort    */
    y[2][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[2][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[2][1][1] = 6.28*y[2][0][0]/1.94E7 ;/* Y-Koordinate, Geschw.*/

    /*  Erde :                                                   */
    y[3][0][0] = 1.49E11 ;      /* Masse 3, X-Koordinate, Ort    */
    y[3][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[3][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[3][1][1] = 6.28*y[3][0][0]/3.16E7 ;/* Y-Koordinate, Geschw.*/

    /* Mars :                                                    */
    y[4][0][0] = 2.28E11 ;      /* Masse 4, X-Koordinate, Ort    */
    y[4][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[4][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[4][1][1] = 6.28*y[4][0][0]/5.94E7 ;/* Y-Koordinate, Geschw.*/

    /* Jupiter :                                                 */
    y[5][0][0] = 7.78E11 ;      /* Masse 5, X-Koordinate, Ort    */
    y[5][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[5][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[5][1][1] = 6.28*y[5][0][0]/3.74E8 ;/* Y-Koordinate, Geschw.*/

    /* Saturn :                                                  */
    y[6][0][0] = 1.43E12 ;      /* Masse 6, X-Koordinate, Ort    */
    y[6][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[6][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[6][1][1] = 6.28*y[6][0][0]/9.30E8 ;/* Y-Koordinate, Geschw.*/

    /* Uranus :                                                  */
    y[7][0][0] = 2.87E12 ;      /* Masse 7, X-Koordinate, Ort    */
    y[7][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[7][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[7][1][1] = 6.28*y[7][0][0]/2.66E9 ;/* Y-Koordinate, Geschw.*/

    /* Neptun :                                                  */
    y[8][0][0] = 4.50E12 ;      /* Masse 8, X-Koordinate, Ort    */
    y[8][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[8][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[8][1][1] = 6.28*y[8][0][0]/5.20E9 ;/* Y-Koordinate, Geschw.*/

    /* Pluto :                                                   */
    y[9][0][0] = 5.91E12 ;      /* Masse 9, X-Koordinate, Ort    */
    y[9][1][0] = 0.0 ;          /*        , Y-Koordinate,        */
    y[9][0][1] = 0.0 ;          /*        , X-Koordinate, Geschw.*/
    y[9][1][1] = 6.28*y[9][0][0]/7.82E9 ;/* Y-Koordinate, Geschw.*/

    /* Mond :                                                   */
    y[10][0][0] = y[3][0][0] ; /* Masse 10,X-Koordinate, Ort    */
    y[10][1][0] = 3.84E8 ;     /*        , Y-Koordinate,        */
    y[10][0][1] = +6.28*y[10][1][0]/2.36E6 ; /* X-Koordinate, Geschw.*/
    y[10][1][1] = y[3][1][1] ; /* Y-Koordinate, Geschwindigkeit */


    m[0]       = 1.98E30 ;      /* Masse der Sonne               */
    m[1]       = 3.28E23 ;      /* Masse des Merkur              */
    m[2]       = 4.83E24 ;      /* Masse der Venus               */
    m[3]       = 5.98E24 ;      /*           Erde                */
    m[4]       = 6.40E23 ;      /*           Mars                */
    m[5]       = 1.90E27 ;      /*           Jupiter             */
    m[6]       = 5.68E26 ;      /*           Saturn              */
    m[7]       = 8.67E25 ;      /*           Uranus              */
    m[8]       = 1.05E26 ;      /*           Neptun              */
    m[9]       = 5.37E24 ;      /*           Pluto               */
    m[10]      = 7.34E22 ;      /*           Mond                */

    dt         = 8.64E4 ;       /* delta-t = 1 Tag               */
    dt /= 10.0 ;

	for( delet = 0, t = 0.0 ; kbhit() == 0 ; delet = 1 , t += dt )
	{
      /* berechne das Feld "k1" :                             */

      /* berechne das Feld "k2" :                             */

      for( i1 = 0 ; i1 < PLANETEN ; i1++ )
      {
        for( i2 = 0 ; i2 < 2 ; i2++ )
        {
            y_alt[i1][i2][0] = y[i1][i2][0] ;
            y[i1][i2][0]    += dt*y[i1][i2][1] ;
          }

        display(y[i1][0][0],y[i1][1][0],farbe[i1],delet,radius[i1],y_alt[i1][0][0],y_alt[i1][1][0]);
      }
	}

	getch();
	closegraph();
	return(0);
}

#include	<math.h>

float f(int i1,int i2,int i3,float yy[ANZAHL][2][2],int t)
{
    float  result ;
    return( result );
}

int	display(float x,float y,int color, int delet, int groesse, float x_old, float y_old)
{
        int	xcoor, ycoor ;

		xcoor  = XW_LINKS + ( XW_RECHTS - XW_LINKS )*( x_old - x_von)/( x_bis - x_von );
		if( xcoor < XW_LINKS  ) xcoor = XW_LINKS ;
		if( xcoor > XW_RECHTS ) xcoor = XW_RECHTS ;

		ycoor  = YW_UNTEN + ( YW_OBEN - YW_UNTEN )*( y_old - y_von )/( y_bis - y_von );
		if( ycoor > YW_UNTEN ) ycoor = YW_UNTEN ;
		if( ycoor < YW_OBEN  ) ycoor = YW_OBEN ;

        if( delet != 0 )
        {
		  setcolor(BLACK);
		  setfillstyle(SOLID_FILL,BLACK);
		  pieslice(xcoor,ycoor,0,360,groesse);
	    }

		xcoor  = XW_LINKS + ( XW_RECHTS - XW_LINKS )*( x - x_von)/( x_bis - x_von );
		if( xcoor < XW_LINKS  ) xcoor = XW_LINKS ;
		if( xcoor > XW_RECHTS ) xcoor = XW_RECHTS ;

		ycoor  = YW_UNTEN + ( YW_OBEN - YW_UNTEN )*( y - y_von )/( y_bis - y_von );
		if( ycoor > YW_UNTEN ) ycoor = YW_UNTEN ;
		if( ycoor < YW_OBEN  ) ycoor = YW_OBEN ;


		setcolor(color);
		setfillstyle(SOLID_FILL,color);
		pieslice(xcoor,ycoor,0,360,groesse);

	return(0);
}
