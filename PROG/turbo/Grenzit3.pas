
PROGRAM GRENZWERT;
(*$N+*)
    {Berechnet wird der Grenzwert einer Zahlenfolge}

USES crt;

Var b,d:DOUBLE;
    n,x:LONGINT;

    PROCEDURE eingabe(VAR n:LONGINT);
      BEGIN  clrscr;
        writeln;
        writeln;
        write('Geben Sie die Anzahl der Iterationsschritte an ');
        readln(n);
      END;

   
    FUNCTION y (x:longint;b:DOUBLE):DOUBLE;
      VAR f,g:DOUBLE;
         BEGIN
            if x=0  Then
            y:=1
            else
            y:=-b/2
         END;

    PROCEDURE berechnung(n:longint;VAR d,b:DOUBLE);
    VAR c,e:DOUBLE;
      LABEL ende;
      CONST eps=1e-25;
             BEGIN
                 x:=1;
                 b:=1;
                 e:=1;
                 c:=1;
                 WHILE(abs(c)>eps)do
          BEGIN
              IF x>n
              THEN GOTO ende
              ELSE BEGIN
                       x:=x+1;
                       c:=b-y(x,b);
                       e:=e+y(x,b);
                       b:=y(x,b)
                   END;
         END;
         ende:
         d:=e;
        END;

    PROCEDURE ausgabe(d:DOUBLE;x:longint);
      BEGIN
        writeln;
        writeln;
        writeln('Der Grenzwert betrÑgt ', d:5:7);
        writeln;
        writeln('nach ', x-1,' ausgefÅhrten Iterationsschritten' );
        readln;
      END;

BEGIN
           eingabe(n);
           berechnung(n,d,b);
           ausgabe(d,x);

END.