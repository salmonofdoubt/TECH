Program Grenzwert;
uses crt;
VAR eps, xn, xn_1:real;
    n,nmax       :integer;
PROCEDURE EINGABE;
  BEGIN
     clrscr;
     gotoxy(1,5);
     writeln('Bitte geben Sie einen von Ihnen gewaehlten Wert ein, der');
     writeln('die Haeufigkeit der Berechnung angibt.');
     writeln('Der Wert wird mit nmax bezeichnet:  ');
     readln(nmax);
     writeln;
     writeln('Bitte geben Sie eine von Ihn gewaehlte Abbruchschranke');
     writeln('eps:  ');

     readln(eps);
     writeln;
  END;
PROCEDURE AUSGABE1;
  BEGIN
     writeln('Die Bedingung der Grenzwert ist kleiner als das von Ihnen');
     writeln('gewaehlte eps,ist erreicht.');
     writeln('Der Grenzwert betreagt: ',10:10);
     writeln;
     exit
  END;
PROCEDURE AUSGABE2;
  BEGIN
     writeln('Der von Ihnen gesetzte Wert fuer die Haeufigkeitnmax wurde');
     writeln('erreicht.Der Grenzwert betraegt: ',10:10);
     writeln;
     exit
  END;
FUNCTION  fkt1(n:integer):real;
  BEGIN
  fkt1:=n*sin(1/n);
  end;
BEGIN
  EINGABE;
   n:=1;xn:=fkt1(+1);
   repeat
     n:=n+1;
     xn_1:=xn;
     xn:=fkt1(n);
     if abs(xn-xn_1)<eps then AUSGABE1;
    until
     n>nmax;
     AUSGABE2;
     delay  (10000);
END.

