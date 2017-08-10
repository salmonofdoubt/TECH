PROGRAM Liste_;  {CASE1.PAS}
USES  crt;
CONST max=100;
TYPE  st2 =STRING[2];
      st6 =STRING[6];
      st15=STRING[15];
      st20=STRING[20];
VAR   vorname: ARRAY[1..max] OF st15;
      name   : ARRAY[1..max] OF st20;
      MatNr  : ARRAY[1..max] OF st6;
      Stgang : ARRAY[1..max] OF st2;

      ch     : CHAR;  { Ein Auswahlpunkt }
      nr     : INTEGER;

PROCEDURE neuanlegen(VAR i:INTEGER);
BEGIN
    CLRSCR;
    i:=i+1;
    IF i<=max THEN BEGIN
      GOTOXY(15, 6);WRITE('Vorname       : ');READLN(vorname[i]);
      GOTOXY(15, 8);WRITE('Name          : ');READLN(name[i]);
      GOTOXY(15,10);WRITE('Matrikelnummer: ');READLN(MatNr[i]);
      GOTOXY(15,12);WRITE('Studiengang   : ');READLN(Stgang[i]);
      END
    ELSE BEGIN
      GOTOXY(15,12);WRITELN('Maximale Anzahl ist erreicht.');
    END;
END;

PROCEDURE liste(VAR anz:INTEGER);
VAR i:INTEGER;
    s:STRING[75];
BEGIN
    CLRSCR;
    IF anz>0 THEN BEGIN
      WRITELN('   Vorname         Name                  Mat.Nr.   Studiengang');
      FOR i:=1 to anz DO
        BEGIN
          s:='                                                                   ';
          INSERT(vorname[i],s,4);
          INSERT(name[i],s,20);
          INSERT(MatNr[i],s,42);
          INSERT(Stgang[i],s,56);
          WRITELN(s);
        END
      END
    ELSE BEGIN
      GOTOXY(15,12);WRITELN('Kein Name eingegeben.');
    END;
END;

PROCEDURE auswahl(VAR was:CHAR);
CONST
    str30 = '==================================';
    pkt0  = 'Liste der Studenten des FB Technik';
    pkt1  = '(N)euanlage';
    pkt2  = '(L)isten';
    pkt3  = '(E) N D E';
    wahl  = '***** Bitte wÑhlen Sie ---> ';

BEGIN
    CLRSCR;
    GOTOXY(22,5) ; WRITE(pkt0);
    GOTOXY(22,6) ; WRITE(str30);
    GOTOXY(31,8) ; WRITE(pkt1);
    GOTOXY(31,10); WRITE(pkt2);
    GOTOXY(31,12); WRITE(pkt3);
    GOTOXY(22,14); WRITE(str30);
    GOTOXY(24,24); WRITE(wahl);
    REPEAT
      GOTOXY(28+LENGTH(wahl)+1,24);
      was:= UPCASE(READKEY);
    UNTIL was in ['N','L','E'];
END;

PROCEDURE aktion(was:CHAR;VAR i:INTEGER);
BEGIN
    CASE was OF
      'N': neuanlegen(i);
      'L': liste(i);
    END; { case }
    GOTOXY(15,24);WRITE('Weiter mit <CR> ... ');READLN;
END;

BEGIN
  nr:=0;
  REPEAT
    auswahl(ch);
    IF ch <> 'E' THEN aktion(ch,nr);
  UNTIL ch = 'E'; { Ende MenÅ-Auswahl }
  CLRSCR;
end.