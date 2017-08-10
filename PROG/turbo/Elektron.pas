Program Electron;

USES
    Crt;

CONST
     me = 9.11E-31;
     e  = 1.602E-19;
     co = 2.998E8;

VAR
     V : REAL;
     U :LongInt;
BEGIN
     ClrScr;
     writeln;

     write ('durchlaufene Spannung : '); readln (U);

     V := SQRT (2*e*U / me);

     IF V < 0.1*co THEN BEGIN
       write ('Endgeschwindigkeit : '   );
       write (V);
       write ('m/s');
       END
     ELSE BEGIN
       V := co * SQRT ( 1-(1/(SQRT(e*U / (me * SQR(co)) + 1))) );
       write ('Endgeschwindigkeit : '    );
              write (V);
       write ( 'm/s' ) ;
       END; { if-then-Anweisung }
       readln
END.



