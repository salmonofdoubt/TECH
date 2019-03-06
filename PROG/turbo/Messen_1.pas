PROGRAM Tabelle;
USES  crt;
CONST max=100;
VAR   Messwert            : ARRAY[1..max] OF REAL;
      ch     : CHAR;
      nr     : INTEGER;

PROCEDURE neuanlegen(VAR i:INTEGER);
BEGIN
clrscr;
i:=i+1;
if i<=max then
   BEGIN
   GOTOXY (15,10);write('Geben Sie bitte den Messwert ein :  ');
   READLN(Messwert[i]);
   END
ELSE
  BEGIN
    GOTOXY(15,12);writeln('Maximale Anzahl ist erreicht.')
  END;
End;

PROCEDURE mittel(i:integer);
var s,r:real;
BEGIN
    clrscr;
    for i:=1 to i do
    BEGIN
     s:=0;
     s:=s+messwert[i];
     r:=s/i;
     gotoxy(15,15);writeln('Der Mittelwert betr„gt    :' ,s:5:3)
    END;
END;

PROCEDURE auswahl(VAR was:CHAR);
CONST
    str30 = '==================================';
    pkt1  = '(M)esswerteingabe';
    pkt2  = '(B)erechnung';
    pkt3  = '(E) N D E';

BEGIN
    CLRSCR;
    GOTOXY(22,6) ; WRITE(str30);
    GOTOXY(31,8) ; WRITE(pkt1);
    GOTOXY(31,10); WRITE(pkt2);
    GOTOXY(31,12); WRITE(pkt3);
    GOTOXY(22,14); WRITE(str30);
    REPEAT
      GOTOXY(28+LENGTH(pkt3)+1,24);
      was:= UPCASE(READKEY);
    UNTIL was in ['M','B','E'];
END;

PROCEDURE aktion(was:CHAR;VAR i:INTEGER);
BEGIN
    CASE was OF
      'M': neuanlegen(i);
      'B': mittel(i);
    END; { case }
    GOTOXY(15,24);WRITE('Weiter mit <CR> ... ');READLN;
END;

BEGIN
  nr:=0;
  REPEAT
    auswahl(ch);
    IF ch <> 'E' THEN aktion(ch,nr);
  UNTIL ch = 'E';
  CLRSCR;
END.