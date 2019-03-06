PROGRAM kern1;
{Karsten Voigt
 942207
 Technische Physik}
USES   Crt, Graph;

VAR     GraphDriver : integer;
        GraphMode   : integer;
        MaxX, MaxY  : word;
        ErrorCode   : integer;
        MaxColor    : word;
const   xbis = 630;
        xvon = 0;
        xmax = 20;
        xmin = -20;
        yvon = 0;
        ybis = 470;
        ymin = -2;
        ymax = 2;

PROCEDURE Initialize;
  BEGIN
    GraphDriver := Detect;
    InitGraph(GraphDriver, GraphMode,'c:\BP\BGI');
    ErrorCode := GraphResult;
    IF ErrorCode <> grOK THEN
      Writeln('Graphics error: ', GraphErrorMsg(ErrorCode));
      MaxColor := GetMaxColor;
      MaxX := GetMaxX;
      MaxY := GetMaxY;
END;

FUNCTION a (x:real):real;
  const h = 0.5;
  BEGIN
  a:=(sin(x+h)*0.1*(x+h)-sin(x)*x*0.1)/h;
  END;

FUNCTION b (x:real):real;
  BEGIN
  b:=0.1*sin(x)*x;
  END;

FUNCTION c (x:real):real;
  BEGIN
  c:=0.1*(sin(x)+x*cos(x));
  END;

PROCEDURE koordinate0 ;

  VAR    z,n:real;
         x,y,i:integer;
  BEGIN
       FOR i:=1 TO xbis DO
       BEGIN
         z:=xmin+(i*((xmax-xmin)/(xbis-xvon)));
         x:=trunc(((xbis-xvon)/(xmax-xmin)*(z-xmin))+xmin);
         y:=trunc(((ybis-yvon)/(ymax-ymin)*(a(z)-ymin))+ymin);
         putpixel(x,y,10);{
         setcolor(10);
         lineto(x,y);     }
       END;
  END;

  PROCEDURE koordinate1 ;
  VAR    z,n  :real;
         x,y,i:integer;
  BEGIN
       FOR i:=1 TO xbis DO
       BEGIN
         z:=xmin+(i*((xmax-xmin)/(xbis-xvon)));
         x:=trunc(((xbis-xvon)/(xmax-xmin)*(z-xmin))+xmin);
         y:=trunc(((ybis-yvon)/(ymax-ymin)*(b(z)-ymin))+ymin);
         putpixel(x,y,1); {
         setcolor(1);
         lineto(x,y);     }
       End;
  End;

  PROCEDURE koordinate2 ;
  VAR    z,n  :real;
         x,y,i:integer;
  BEGIN
       FOR i:=1 TO xbis DO
       BEGIN
         z:=xmin+(i*((xmax-xmin)/(xbis-xvon)));
         x:=trunc(((xbis-xvon)/(xmax-xmin)*(z-xmin))+xmin);
         y:=trunc(((ybis-yvon)/(ymax-ymin)*(c(z)-ymin))+ymin);
         putpixel(x,y,13);{
         setcolor(13);
         lineto(x,y);     }
       End;
  END;

BEGIN
  initialize;
  koordinate0;
  koordinate1;
  koordinate2;
  repeat until keypressed ;
  closegraph;
END.



