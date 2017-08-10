Program Programmiertest Partsumme;

Uses crt;

Const eps = 0.001;
      n_max = 100;
      k   =   1;
VAR   x:REAL;
Function f(k:real):Real;

 BEGIN
   x:=((1/k)*(1/(k+1)));
 END;

Procedure berechnen(x:REAL);
 BEGIN
   REPEAT
   x:= ((1/k)*(1/(k+1)));
   UNTIL
   f(x)-f(x+1)<eps;
 END;

 BEGIN
writeln('Partialsummenfolge konvergiert nach : ' , x:8:3);
readln;
 END.