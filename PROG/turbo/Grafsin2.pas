Program GraphFun;
uses Crt,Graph;
var GraphDriver,GraphMode,xm,ym     : integer;
    x1,x2,y1,y2                     : real;


type float = real;

var World : record xv,yv,  { WK der linken unteren Ecke des Windows }
                   xo,yo,  { "      rechten oberen  "    "    "   }
                   xf,yf : float end;
const WindNr = 10;
var  WindList  : array[1..WindNr] of record
                   VP: ViewPortType; Size : Word; Pt : Pointer
                 end;

procedure DefineWindow(wn,xl,yo,xr,yu : integer; clipping : boolean);
begin
   if (wn < 1) or (wn > WindNr) then Exit;
   with WindList[wn],VP do
   begin x1:= xl; y1:= yo; x2:= xr; y2:= yu;
      clip:= clipping; Size:= 0;
   end;
end;

procedure SelectWindow(wn : integer);
begin if (wn < 1) or (wn > WindNr) then Exit;
   with WindList[wn],VP do SetViewPort(x1,y1,x2,y2,clip)
end;

procedure DefineWorld(xl,yl,xr,yr : float);
var VP : ViewPortType;
begin GetViewSettings(VP);
   with VP,World do
   begin xv:= xl; yv:= yr; xo:= xr; yo:= yl;
      xf:= (x2-x1)/(xr-xl); yf:= (y2-y1)/(yr-yl);
   end;
end;

function x_window(x : float) : integer;
begin x_window := round( World.xf * (x - World.xv) ) end;

function y_window(y : float) : integer;
begin y_window := round( World.yf * (World.yv - y) ) end;

procedure PutPixelW(x,y : float; Col : byte);
begin PutPixel(x_window(x),y_window(y),Col) end;

procedure LineW(x1,y1,x2,y2 : float);
begin Line(x_window(x1),y_window(y1),x_window(x2),y_window(y2)) end;

begin
 GraphDriver:=Detect;
 InitGraph(GraphDriver,GraphMode, '\BP\bgi');
 xm:=GetMaxX;ym:=GetMaxY;
 SetBkColor(white);
 ClearDevice;
 DefineWindow(1,20,20,xm-20,ym-20,true);
 SelectWindow(1);
 DefineWorld(-2*Pi,-1.5,2*Pi,1.5);
 SetColor(blue);
 LineW(-2*pi,0,2*pi,0);LineW(0,-1.5,0,1.5);
 SetColor(red);
 x1:=-2*pi;y1:=sin(x1);
 repeat
  x2:=x1+0.3;
  y2:=sin(x2);
  LineW(x1,y1,x2,y2);
  x1:=x2; y1:=y2;
 until x2>=2*pi;
 SetColor(green);
 Line(x_window(-2*pi),y_window(0)-5,x_window(-2*pi),y_window(0)+5);
 Line(x_window(-1*pi),y_window(0)-5,x_window(-1*pi),y_window(0)+5);
 Line(x_window(0),y_window(0)-5,x_window(0),y_window(0)+5);
 Line(x_window(1*pi),y_window(0)-5,x_window(1*pi),y_window(0)+5);
 Line(x_window(2*pi),y_window(0)-5,x_window(2*pi),y_window(0)+5);
 readln;
 CloseGraph;
end.


