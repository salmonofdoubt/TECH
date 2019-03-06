PROGRAM  main11AC;
USES crt;

VAR
 v_anfang,zeit,winkel,ort_x,ort_y:REAL;

PROCEDURE
 eingabe(VAR v,t,w:REAL);

BEGIN
 WRITELN('Geben Sie bitte v_anfang ein:');
 READLN(v);

 WRITELN('Geben Sie den Zeitpunkt ein:');
 READLN(t);

 WRITELN('Und nun noch den Winkel in Grad:');

 READLN(w);

END;

PROCEDURE
   berechnungen(v,t,w:REAL;VAR x,y:REAL);

 CONST  g=10;
 BEGIN
    w:=w*180/Pi;
    x:=v*t* COS(w);
    y:=v*t*sin( w)-(g*t*2/2);
 END;

PROCEDURE
   ausgabe(x,y:REAL);
 BEGIN
  WRITELN('Die x - Koordinate betraegt',x);
  WRITELN('Die y - Koordinate betraegt',y);
 READLN;
END;
BEGIN
   eingabe(v_anfang,zeit,winkel);
   ausgabe(ort_x,ort_y);
END.

