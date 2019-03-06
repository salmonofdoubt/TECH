program ableitung;
uses crt,graph3,
 graph;



VAR     MAXX,MINX,MAXY,MINY :WORD;
        X,Y                 :INTEGER;
CONST                 a = -20;                   {Intervalle}
                      b =  20;
                      c = - 2;
                      d =   2;
                  delta = 0.01;                  {Schrittweite}
                  h     = 0.01;                   {h fÅr Differenzenquotient}

PROCEDURE grafik_arbeit;

VAR GraphDriver : integer;  { The Graphics device driver }
    GraphMode   : integer;  { The Graphics mode value }
    MaxX, MaxY  : word;     { The maximum resolution of the screen }
    ErrorCode   : integer;  { Reports any graphics errors }
    MaxColor    : word;     { The maximum color value available }

  PROCEDURE Initialize;
  { Initialize graphics and report any errors that may occur }
  BEGIN
    GraphDriver := Detect;                { use autodetection }
    InitGraph(GraphDriver, GraphMode,'\bp\bgi');
    ErrorCode := GraphResult;             { preserve error return }
    IF ErrorCode <> grOK THEN             { error? }
      Writeln('Graphics error: ', GraphErrorMsg(ErrorCode));
      MaxColor := GetMaxColor;  { Get the maximum allowable drawing color }
      MaxX := GetMaxX;          { Get screen resolution values }
      MaxY := GetMaxY;
    END; { Initialize }


PROCEDURE rahmen;

CONST
     Y_unten = 479;
     Y_oben  = 0  ;
     X_links = 0  ;
     X_rechts= 639;

BEGIN

     RECTANGLE(X_links+1,Y_unten-10,X_rechts-1,Y_oben+10);

END;


PROCEDURE darstellung;
VAR                 f,g,o :REAL;
                  X,Y,z :INTEGER;

BEGIN
     MAXX:=GETMAXX;
     MAXY:=GETMAXY;
     MINX:=0;
     MINY:=0;
                                 { FOR z:= -20 TO 20 DO BEGIN}
        o:= -20;
    REPEAT

     f := (0.1*o)*sin(o);
     X := TRUNC (((MAXX - MINX)/(b-a)) * (o-a) + MINX);
     Y := TRUNC (((MAXY - MINY)/(d-c))* (f-c) +MINY);
    PUTPIXEL (X,Y,3);
     g := (0.1*o)*cos(o) + 0.1*sin(o);
     X := TRUNC (((MAXX - MINX)/(b-a)) * (o-a) + MINX);
     Y := TRUNC (((MAXY - MINY)/(d-c))* (g-c) +MINY);
    PUTPIXEL(X,Y,4);

     o:= o + delta;
    UNTIL
     o > 20;

END;


                                  { BEGIN  FOR i:=0 TO 639 DO BEGIN X:=i;
                                    Y:= TRUNC ((0.1 * X) * SIN(X))+240;
                                    PUTPIXEL(X,Y,3);END;END;}

PROCEDURE numerisch;
VAR     abl,p:REAL;


BEGIN
              MAXX:=GETMAXX;
              MAXY:=GETMAXY;
              MINX:=0;
              MINY:=0;
               p:= -20;
     REPEAT

        abl:=(0.1*(p+h)*sin((p+h)) - ( 0.1*p*sin(p)))/h;

             X := TRUNC (((MAXX - MINX)/(b-a)) * (p-a) + MINX);
             Y := TRUNC (((MAXY - MINY)/(d-c))* (abl-c) +MINY);
             PUTPIXEL(X,Y,14);
             p:=p+delta;
     UNTIL   p > 20;
END;

BEGIN

     Initialize;
     rahmen;
     darstellung;
     numerisch;
     REPEAT UNTIL KEYPRESSED;
     CLOSEGRAPH;
END;
BEGIN
     Grafik_arbeit;
END.


