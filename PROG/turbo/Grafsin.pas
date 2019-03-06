PROGRAM SINUSFkt;
USES   Crt, Graph;

 PROCEDURE plot;
  VAR GraphDriver : integer;
    GraphMode   : integer;
    MaxX, MaxY  : word;
    Error       : integer;
    MaxColor    : word;

 PROCEDURE Initialize;
  BEGIN                                                
    GraphDriver := Detect;                
    InitGraph(GraphDriver, GraphMode,'\BP\bgi');
    Error       := GraphResult;           
    IF Error <> grOK THEN
      Writeln('Graphics error: ', GraphErrorMsg(Error));
      MaxColor  := GetMaxColor;  
      MaxX      := GetMaxX;         
      MaxY      := GetMaxY;
    END;

 PROCEDURE grafik;
   VAR i,x,y,z:INTEGER;


  BEGIN
    LINE(30,30,30,450);
    MOVETO(30,225);LINETO(610,225);
    MOVETO(25,36);LINETO(30,30);LINETO(35,36);
    MOVETO(604,220);LINETO(610,225);LINETO(604,230);
    OUTTEXTXY(18,38,'y');
    MOVETO(599,233);OUTTEXT('x');
    FOR i:=0 TO 565 DO
     BEGIN
        x:=i+30;
        y:=-TRUNC(30*SIN(i/30))+225;
        putpixel(x,y,4);
     END;
  END;
BEGIN
  Initialize;
  grafik;
  REPEAT UNTIL KEYPRESSED;
  CloseGraph;
END;

BEGIN
  plot;
END.