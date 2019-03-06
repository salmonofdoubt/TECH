 PROGRAM grafik;   {Andr‚ Baumann Physik 942215}
USES   Crt, Graph;


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
    InitGraph(GraphDriver, GraphMode,'\BP\BGI');
    ErrorCode := GraphResult;             { preserve error return }
    IF ErrorCode <> grOK THEN             { error? }
      Writeln('Graphics error: ', GraphErrorMsg(ErrorCode));
      MaxColor := GetMaxColor;  { Get the maximum allowable drawing color }
      MaxX := GetMaxX;          { Get screen resolution values }
      MaxY := GetMaxY;
    END; { Initialize }

  PROCEDURE koordinate;
  BEGIN
    LINE(30,30,30,450);
    MOVETO(30,450);LINETO(610,450);
    MOVETO(25,36);LINETO(30,30);LINETO(35,36);
    MOVETO(604,445);LINETO(610,450);LINETO(604,455);
    OUTTEXTXY(18,38,'y');
    MOVETO(599,458);OUTTEXT('x');
  END;

  Procedure sinus;
  VAR i,x,y:INTEGER ;
  BEGIN
       Line (0,0,0,470);
       Line (0,240,639,240);
      FOR i:= 1 TO 639 DO BEGIN
       x:=i;
       y:= -TRUNC ( 100 * sin(ln(i/100*50))) + 240;
       PUTPIXEL (x,y,3);
   END;END;
BEGIN
  Initialize;  
  {koordinate};
  {setcolor (6);
  circle(200,200,50);
  setcolor (9);
  circle (200,300,50);
  setcolor (7);
  circle (100,200,50);    wird zuerst gezeichnet, also daran orientieren
  setcolor (2);
  circle (100,300,50);
  setcolor (5);
  rectangle(50,150,250,350);
  setcolor (3);
  rectangle(52,152,252,352)};
  sinus;
  REPEAT UNTIL KEYPRESSED;
  CloseGraph;
END; { grafik_arbeit }

BEGIN
  grafik_arbeit;
END.
