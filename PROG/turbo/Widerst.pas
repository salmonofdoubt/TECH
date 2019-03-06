Program Widerstand;
{Andr‚ Baumann}
{TP}
uses crt;
Var a, b: real;
          R, P : real;

Procedure Reihe (var d,e :real);

begin
   R:=d+e;
end;

Procedure Parallel (var f,g:real);

begin
   P:=(f*g)/(f+g);
end;

begin
clrscr; writeln;
write ('Widerstand Reihe und Parallel');
writeln ('Widerst„nde?');

write ('Eingabe Widerst. 1 :  '); readln (a);
writeln;
write ('und Widerstand 2 ?: ');   readln (b);
Parallel (a,b);
Reihe (a,b);
writeln ('Schaltung parallel: ',P:5:2);
writeln ('Schaltung reihe : ',R:5:2);
readln;
end.