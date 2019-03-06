PROGRAM grafikgesamtzeug;
USES   Crt, Graph;


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
  VAR  x,y,z,i:INTEGER;
  BEGIN
    LINE(0,0,0,479);
    LINE(0,240,639,240);
    MOVETO(25,36);LINETO(30,30);LINETO(35,36);
    MOVETO(604,445);LINETO(610,450);LINETO(604,455);
    OUTTEXTXY(18,38,'y');
    MOVETO(599,458);OUTTEXT('x');
    Setbkcolor(0);

      FOR i:=0 TO 639 DO BEGIN
      x:=i;
      y:=- TRUNC (100* sin (i/100))+240;
      PUTPIXEL (x,y,3);
      z:= - TRUNC(100* cos (i/100))+240;
      PUTPIXEL (x,z,15);
    END;
  END;

BEGIN
  Initialize;
  koordinate;
  setcolor (7);
  circle(200,200,50);
  setcolor (1);
  circle(200,300,50);
  circle(300,200,50);
  circle(300,300,50);
  setcolor(15);
  rectangle(150,150,350,350);
  REPEAT UNTIL KEYPRESSED;
  CloseGraph;
END. { grafik_arbeit }



