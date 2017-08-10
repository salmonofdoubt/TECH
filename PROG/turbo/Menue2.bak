PROGRAM Menue;  {CASE1.PAS}
USES
    crt;  { Unit aus Turbo Pascal 5.0 }
VAR
    ch: CHAR;  { Ein Auswahlpunkt }

PROCEDURE auswahl(VAR was:CHAR);
CONST
    str30 = '==============================';
    pkt0  = 'Adre·-Verwaltung';
    pkt1  = '(N)euanlage';
    pkt2  = '(A)endern';
    pkt3  = '(L)îschen';
    pkt4  = '(D)rucken';
    pkt5  = '(E) N D E';
    wahl  = '***** Bitte wÑhlen Sie ---> ';

BEGIN
    CLRSCR;
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
    UNTIL was in ['N','A','L','D','E'];
END;

PROCEDURE aktion(was:CHAR);
BEGIN
    GOTOXY(20,21);
    CASE was OF
      'N': WRITE('eine neue Adresse eingeben!');
      'A': WRITE('eine vorhandene Adresse Ñndern!');
      'L': WRITE('eine Adresse lîschen!');
      'D': WRITE('eine Druckliste ausgeben!');
    END; { case }
    WRITE('  Bitte <CR> drÅcken...');
    READLN;
END;

BEGIN
  REPEAT
    auswahl(ch);
    IF ch <> 'E' THEN aktion(ch);
  UNTIL ch = 'E'; { Ende MenÅ-Auswahl }
  CLRSCR;



end.