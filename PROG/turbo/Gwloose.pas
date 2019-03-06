PROGRAM GRENZWERT;
{$N+ $E+}
USES Crt;
     VAR n,k:LONGINT;
           c:CHAR;

  PROCEDURE eingabe;
    VAR io:INTEGER;
    BEGIN
      CLRSCR;
      GotoXY(2,2);
      write('Anzahl der Iterationsschritte :');
{$I-}
      REPEAT
         GotoXY(33,2);ClrEoL;
         readln(n);
         io:=IOResult;
      UNTIL io=0;
{$I+}
    END;

   
                 FUNCTION berechnung(n:LONGINT; VAR j:LONGINT):DOUBLE;
                 CONST eps=1e-50;
                 VAR v,g,g1,x,epsT:DOUBLE;
                           epsTOVR:BOOLEAN;

                 BEGIN
                  epsT:=1;k:=0;
                  REPEAT
                     IF (k/2)=ROUND(k/2) THEN g1:=(exp(k*ln(1))*1) ELSE
                                              g1:=(exp(k*ln(1))*-1);
                     g:=g1/(exp(k*ln(2)));
                     IF k>0 THEN BEGIN
                     IF (k/2)=ROUND(k/2) THEN g1:=(exp((k-1)*ln(1))*1) ELSE
                                              g1:=(exp((k-1)*ln(1))*-1);
                     v:=g1/(exp((k-1)*ln(2)));
                     epsT:=ABS(g-v);
                   END;
                     x:=x+g;
                     INC(k);
                  IF epsT>eps THEN epstOVR:=FALSE ELSE epstOVR:=TRUE;
                  UNTIL (epstOVR=TRUE) or (k>n);
                 berechnung:=x;j:=k;
                 END;


    PROCEDURE ausgabe(d:DOUBLE);
      BEGIN
        GotoXY(2,6);
        WRITELN('Grenzwert :', d:5:7);
        GotoXY(2,8);
        WRITELN('bei ',k-1,' ausgefÅhrten Iterationsschritten');
      END;

BEGIN
       REPEAT
           eingabe;
           ausgabe(berechnung(n,n));
           REPEAT
             GotoXY(2,12);
             WRITE('Nochmal ? [J/N]');
             c:=UPCASE(readkey);
           UNTIL (c='J') or (c='N');
       UNTIL c='N';
END.