PROGRAM Menue;
USES
    crt;
VAR
    a:Integer;

PROCEDURE auswahl(VAR a:Integer);
VAR was: CHAR;
CONST
    str30 = '==============================';
    pkt0  = 'Text-Verwaltung';
    pkt1  = '1 Neuanlage';
    pkt2  = '2 Aendern';
    pkt3  = '3 Lîschen';
    pkt4  = '4 Drucken';
    pkt5  = '0 E N D E';
    wahl  = '***** Bitte wÑhlen Sie ---> ';

BEGIN
    CLRSCR;textcolor(7);textbackground(Random(6));
    GOTOXY(33,5) ; WRITE(pkt0);
    GOTOXY(26,6) ; WRITE(str30);
    GOTOXY(35,8) ; WRITE(pkt1);
    GOTOXY(35,10); WRITE(pkt2);
    GOTOXY(35,12); WRITE(pkt3);
    GOTOXY(35,14); WRITE(pkt4);
    GOTOXY(35,16); WRITE(pkt5);
    GOTOXY(26,18); WRITE(str30);
    GOTOXY(28,24); WRITE(wahl);
    REPEAT
      GOTOXY(28+LENGTH(wahl)+1,24);
      was:= UPCASE(READKEY);
    UNTIL was in ['1','2','3','4','0']; a:=ord(was)-48;
END;

PROCEDURE aktion(a:Integer);
BEGIN
    GOTOXY(20,21);
    CASE a OF
       1: WRITE('einen neuen Text eingeben!');
       2: WRITE('einen vorhandenen Text Ñndern!');
       3: WRITE('einen Text lîschen!');
       4: WRITE('eine Druckliste ausgeben!');
    END; { case }
    WRITE('  Bitte <CR> drÅcken...');
    READLN;
END;

BEGIN
  REPEAT
    auswahl(a);
    IF a <> 0 THEN aktion(a);
  UNTIL a = 0;
  CLRSCR;



end.