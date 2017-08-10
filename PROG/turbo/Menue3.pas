PROGRAM auswahlmenue;
USES
    crt;  
VAR
     p: CHAR;  { Auswahlpunkt }

     i: INTEGER ;
PROCEDURE auswahl(VAR w:CHAR);
CONST
    str30 = '==============================';
    pktx  = 'MenÅ-Verwaltung';
    pkt1  = '(1) Feiern';
    pkt2  = '(2) Arbeiten';
    pkt0  = '(0) Ende';
    wahl  = '***** Bitte wÑhlen Sie ---> ';
    enter = '   ---> Enter';

BEGIN
    CLRSCR;textbackground(2);textcolor(5);
    GOTOXY(33,5) ; WRITE(pktx);
    GOTOXY(26,6) ; WRITE(str30);textcolor(1);
    GOTOXY(35,8) ; WRITE(pkt1);
    GOTOXY(35,10); WRITE(pkt2);
    GOTOXY(35,12); WRITE(pkt0);textcolor(5);
    GOTOXY(26,14); WRITE(str30);
    GOTOXY(28,24); WRITE(wahl);
    GOTOXY(28,40); WRITE(enter);
    REPEAT
      GOTOXY(28+LENGTH(wahl)+1,24);textcolor(1);
      READLN(w);
    UNTIL w in ['1','2','0'];
END;

PROCEDURE aktion(m:INTEGER);
BEGIN
    CLRSCR;textcolor(1);
    GOTOXY(10,10);
    CASE m OF
      1: WRITE('Feiern kînnen Sie zu Hause! ');
      2: WRITE('An der FHB wird gearbeitet! ');
    END; { case }
    WRITE('  Bitte <Enter> drÅcken...');
    READLN;
END;

BEGIN
  REPEAT
    auswahl(p);
    i:=ORD(p)-48;
    IF p <> '0' THEN aktion(i);
  UNTIL p = '0'; { Ende MenÅ-Auswahl }
  CLRSCR;
end.