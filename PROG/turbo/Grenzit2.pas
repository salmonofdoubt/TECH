Program grenzwert2;
uses crt;
var eps, xn,xn_1,s:real;
    n,nmax        :integer;
PROCEDURE EINGABE;
   begin
     clrscr;
     gotoxy(1,5);
     writeln('Bitte geben Sie eine von Ihnen gewaehlte Abbruchschranke eps: ');
     readln(eps);
     writeln;
     writeln('Bitte geben Sie,einen von Ihnen gewaehlten Wert ein der die ');
     writeln('Haeufigkeit der Berechnung angibt.');
     writeln('Der Wert wird mit nmax bezeichnet: ');
     readln(nmax);
     writeln;
   end;
PROCEDURE AUSGABE1;
   begin
   writeln;
   writeln('Die Bedingung ,der Wert ist kleiner als der von Ihnen gegebene');
   writeln('Wert fuer eps ist erreicht.');
   writeln('Der Grenzwert betraegt: ',10:10);
   end;
PROCEDURE AUSGABE2;
   begin
   writeln;
   writeln('Der von Ihnen gegebene Wert fuer die Haeufigkeit wurde erreicht.');
   writeln('Der Grenzwert betraegt: ',10:10);
   end;
FUNCTION fkt2(vars:real;xn_1:real;n:integer):real;
  begin
    s:=-0.5*s;
    fkt2:=xn_1+s;
  end;
BEGIN
EINGABE;
  s:=1;
  n:=1;xn:=fkt2 (s,1,1);
    repeat
     n:=n+1;
     xn_1:=xn;
     xn:=fkt2(s,xn_1,n);
     if abs (xn-xn_1)>eps then AUSGABE1;
     until n>nmax;  AUSGABE2;
     delay (10000);
end.