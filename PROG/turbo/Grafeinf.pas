PROGRAM grafik;
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
    InitGraph(GraphDriver, GraphMode,'\BP\bgi');
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

BEGIN
  Initialize;
  koordinate;
  circle(200,200,100);
  rectangle(450,50,550,350);
  REPEAT UNTIL KEYPRESSED;
  CloseGraph;
END; { grafik_arbeit }

BEGIN
  grafik_arbeit;
END.
