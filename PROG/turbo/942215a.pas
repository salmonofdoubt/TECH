{Andr‚ Baumann Techn. Physik Matr. 942215, diese Datei ist gedacht, um
beide Programme aufzurufen, einzeln in 942215b bzw. 942215c}
Program Limes;
uses crt     ;

const eps = 1E-4;

var       yy: integer;
          xx: real;

function  f(n:real):real;

         begin
              f:=sin(1/n)/(1/n);
         end;

procedure berechnung (var xx: real; var yy: integer);


         begin
                  yy := 1;
           repeat yy := yy+1 until f(yy+1)-f(yy)<eps;
                  xx := f(yy);
        end;




procedure    ausgabe(xx:real;yy:integer);

         begin
              writeln;writeln('Berechnung Grenzwert (sin(1/n) /(1/n)) nach');
              writeln('best. Genauigkeit');
              writeln;writeln('lim dieser Fkt. ist ',xx:15:15);
              writeln;writeln('Anzahl der Iterationen bei einer Differenz');
              writeln('von ',eps : 0,' betraegt  ',yy);

              repeat until keypressed;
         end;





Procedure Variablen;
begin
 var a          : array[1..200] of integer;
   max,n,x,i,j : integer;
  s,m,k       : real;
end;
procedure einlesen;
     begin
          x := 0;
          writeln('Wieviele Dezimalzahlen sollen sortiert werden ? : ');
          writeln('..was 200 wohl nicht sein werden..');
          readln(k);
          writeln; writeln('Bitte die Zahlen eingeben ');

          for i := 1 to x do
              begin
                   readln (a[i]);
                   s := s +a[i];
              end;
     end;

procedure algorithmus;

    begin
          m := s/x;
          n := i  ;

     for j := 1 to n-1 do
      for i := 1 to n-1 do

      if a[i] > a[i+1] then
         begin
              max := a[i];
              a[i]:= a[i+1];
              a[i+1]:= max;
         end;
     end;

procedure ausgeben;
    begin

         writeln('Geordnete Reihenfolge: ');
         for i := 1 to n do
         writeln('a[i]:10');
         writeln('kleinste Zahl  ',a[1]);
         writeln('groesste       ',a[x]);
         repeat until keypressed;
end;
begin
     clrscr;
     berechnung (xx,yy);
     ausgabe (xx,yy);
end;
begin
     clrscr;
     variablen;
     einlesen;
     algorithmus;
     ausgeben;
end;

end.


