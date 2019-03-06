program lotto;
uses crt;
var x,y: integer;
    begin
         clrscr;
         randomize;
         write('6 aus 49');
         for y:=1 to 6 do
             begin
                  x:=random(49)+1;
                  writeln(x:5);

              end;
              readln;end.