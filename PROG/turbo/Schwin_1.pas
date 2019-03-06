program schwingung;

uses  crt,graph;

const m   =0.1             ;
      d   =0.1             ;
      l   =0.05            ;
      h   =0.00001         ;
      k   =10.0            ;

var   i,s,v0,s0                  :real;
      gd,gm,x,y                  :integer;

procedure Berechnung (var v0,s0,s:real);
var F,a,v:real;
begin
  F  := -k*s0-d*v0         ;
  a  := F/m                ;
  v  := a*h+v0             ;
  s  := v*h+s0             ;
  s0 := s                  ;
  v0 := v                  ;
end;

procedure bild (s,i:real;var x,y:integer);
begin
  x:=trunc(i)    ;
  y:=trunc(s+240);
  putpixel(x,y,1);
end;

begin
  i:=1      ;
  Gd:=detect;
  initGraph(Gd,Gm,'c:\bp\bgi');
  v0:=50    ;
  s0:=200   ;
repeat
    berechnung(v0,s0,s);
    i:=i+0.0005  ;
    bild(s,i,x,y);
until keypressed ;
    readln       ;
    closegraph   ;
end.

