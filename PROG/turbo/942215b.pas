{Andr‚ Baumann Techn. Physik Matr. 942215}
Program Feld;
uses crt;

var
   a           : array[1..200] of integer;
   max,n,x,i,j : integer;
   s,m         : real;
procedure einlesen;
     begin
          x := 0;
          writeln('Wieviele Dezimalzahlen sollen sortiert werden ? : ');
          writeln('..was 200 wohl nicht sein werden..');
          readln(x);
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
     einlesen;
     algorithmus;
     ausgeben;
end.


