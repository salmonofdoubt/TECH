PROGRAM bsp7;			{ Berechnung mit vorgegebener Genauigkeit }

{ Vereinbarungsteil }
USES CRT;
CONST 	eps	          =0.001;
VAR 	u_grenze,o_grenze :REAL;
     	i,s		  :INTEGER;

FUNCTION f(x:REAL):REAL;
BEGIN
         f:=ln(x);
END;

PROCEDURE eingabe(VAR a,b:REAL);
BEGIN
     CLRSCR;
     WRITELN;WRITELN;
     WRITELN('N„herungsweise Berechnung eines bestimmten Integrals');
     WRITELN('----------------------------------------------------');
     WRITELN;WRITELN;
     WRITE('Untere Grenze des Intervalles : '); READLN(a);
     WRITE('Obere Grenze des Intervalles  : '); READLN(b);
END;
FUNCTION rechteck(a,b:REAL;n:INTEGER):REAL;
VAR i           :INTEGER;
    d,flaeche    :REAL;
BEGIN
  d:=(b-a)/n;
  flaeche:=0;
  FOR  i:=0 TO n-1 DO  flaeche:=flaeche+f(a+i*d);
  rechteck:= d*flaeche;
END;
PROCEDURE ausgabe(flaeche:REAL);
BEGIN
     WRITELN;WRITELN;
     WRITELN('Die Fl„che des Integrals betr„gt: ',flaeche:8:3);
     READLN;
END;
BEGIN
  eingabe(u_grenze,o_grenze);
  s:=1;
  i:=1;
     repeat
   i:=i+s;
  until rechteck(u_grenze,o_grenze,i)-rechteck(u_grenze,o_grenze,i+s)<eps;
  writeln('Anzahl der Iterationen',i:8);
  ausgabe(rechteck(u_grenze,o_grenze,i));
END.
{ Anweisungsteil }
BEGIN
     eingabe(u_grenze,o_grenze);
     ausgabe;
END.
