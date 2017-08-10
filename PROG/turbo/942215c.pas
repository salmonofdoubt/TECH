{Andr‚ Baumann Techn. Physik Matr. 942215}
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

         end;
begin
clrscr; berechnung(xx,yy);ausgabe(xx,yy);    repeat until keypressed;
end.


