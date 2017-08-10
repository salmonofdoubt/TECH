
PROGRAM grafik ;
USES   Crt, Graph;

PROCEDURE grafik_arbeit;
VAR GraphDriver : integer;  { The Graphics device driver }
    GraphMode   : integer;  { The Graphics mode value }
    MaxX, MaxY  : word;     { The maximum resolution of the screen }
    ErrorCode   : integer;  { Reports any graphics errors }
    MaxColor    : word;     { The maximum color value available }
    a,b,c,d,e,f :integer;
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


  BEGIN
    REPEAT
    Initialize;
    RANDOMIZE;
    cleardevice;
    { Kreis }
    setcolor(random(15));
    circle(random(640),random(480),random(200));
    setcolor(random(14));
    { Rechteck }
    rectangle(random(450),random(300),random(500),random(300));
    { Dreieck }
    setcolor(random(17));
    a:=random(630);b:=random(470);c:=random(630);d:=random(470);
    e:=random(630);f:=random(470);
    line(a,b,c,d);line(c,d,e,f);line(e,f,a,b);
    delay(1000);
    CLOSEGRAPH;
    
    UNTIL KEYPRESSED;
   
  END;

BEGIN
grafik_arbeit;
END.

