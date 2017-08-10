UNIT l1_unit;  {CASE1.PAS}
{$F+,O+}

INTERFACE

USES  crt;
CONST max=100;
TYPE  Personal = RECORD
                       vorname: STRING[15];
                       name   : STRING[20];
                       matnr  : STRING[6];
                       stgang : STRING[2];
                 END;
      P_Tabelle= ARRAY[1..max] OF Personal;
      
VAR   Tabelle  : P_Tabelle;


     PROCEDURE neuanlegen(VAR i:INTEGER);
     PROCEDURE liste(VAR anz:INTEGER);
     PROCEDURE Datei_auf(VAR i:INTEGER; VAR tab:P_Tabelle);
     PROCEDURE Datei_zu(anz:INTEGER; tab:P_Tabelle);


IMPLEMENTATION

TYPE   P_Datei  = FILE OF Personal;
VAR    Datei    : P_Datei;

PROCEDURE neuanlegen(VAR i:INTEGER);
BEGIN
    CLRSCR;
    i:=i+1;
    IF i<=max THEN
      WITH Tabelle[i] DO
        BEGIN
          GOTOXY(15, 6);WRITE('Vorname       : ');READLN(vorname);
          GOTOXY(15, 8);WRITE('Name          : ');READLN(name);
          GOTOXY(15,10);WRITE('Matrikelnummer: ');READLN(MatNr);
          GOTOXY(15,12);WRITE('Studiengang   : ');READLN(Stgang);
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
          INSERT(Tabelle[i].vorname,s,4);
          INSERT(Tabelle[i].name,s,20);
          INSERT(Tabelle[i].MatNr,s,42);
          INSERT(Tabelle[i].Stgang,s,56);
          WRITELN(s);
        END
      END
    ELSE BEGIN
      GOTOXY(15,12);WRITELN('Kein Name eingegeben.');
    END;
END;

PROCEDURE Datei_auf(VAR i:INTEGER; VAR tab:P_Tabelle);
BEGIN
     ASSIGN(datei,'N:\liste.dat');
     {$I-}
     RESET(datei);
     {$I+}
     IF IORESULT <> 0 THEN REWRITE(datei);

     i:=0;
     WHILE NOT EOF(datei) DO BEGIN
       i:=i+1;
       READ(datei,tab[i]);
     END;
     CLOSE(datei);
END;

PROCEDURE Datei_zu(anz:INTEGER; tab:P_Tabelle);
VAR i:INTEGER;
BEGIN
     REWRITE(datei);
     i:=0;
     WHILE i < anz DO BEGIN
       i:=i+1;
       WRITE(datei,tab[i]);
     END;
     CLOSE(datei);
END;
BEGIN
END.