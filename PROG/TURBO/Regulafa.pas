PROGRAM Nullstellenberechnung;
{ Vereinbarungsteil }
USES CRT;

VAR  l_grenze, r_grenze: REAL;

FUNCTION f(x:REAL):REAL;
BEGIN
     f:=x*x-0.5;
END;

PROCEDURE eingabe(VAR a,b:REAL);
BEGIN
     CLRSCR;
     WRITELN;WRITELN;
     WRITELN('Nullstellenberechnung mit REGULA FALSI');
     WRITELN('--------------------------------------');
     WRITELN;WRITELN;
     WRITE('Linke Grenze des Intervalles  : '); READLN(a);
     WRITE('Rechte Grenze des Intervalles : '); READLN(b);
END;

PROCEDURE ausgabe(nullstelle:REAL);
BEGIN
     WRITELN;WRITELN;
     WRITELN('Die Nullstelle liegt bei  x=  ',nullstelle:7:3);
     READLN;
END;

FUNCTION regula_falsi(x1,x2:REAL):REAL;
CONST eps = 0.0001;
VAR   x3,
      y1,y2,y3: REAL;
BEGIN
     x3:=x2;
     REPEAT
       y1:=f(x1);
       y2:=f(x2);
       x3:=x1-(x2-x1)/(y2-y1)*y1;
       y3:=f(x3);
       IF y3*y2>0 THEN x2:=x3 ELSE x1:=x3;
     UNTIL ABS(y3)<=eps;
     regula_falsi:=x3;
END;

{ Anweisungsteil }
BEGIN
     eingabe(l_grenze,r_grenze);
     ausgabe(regula_falsi(l_grenze,r_grenze));
END.
