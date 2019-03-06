

PROGRAM Integral;
uses crt;
VAR  u_grenze,o_grenze,flaeche:real;
     Procedure eingabe(var u_grenze,o_grenze:real);
      BEGIN
       clrscr;
       Writeln('Program zur Berechnung der Flaeche');
       writeln;
       Write('Untere Grenze eingeben : ');
       readln(u_grenze);
       write('Obere Grenze eingeben  : ');
       readln(o_grenze);
       end;

FUNCTION f(x:real):real;
      BEGIN
       f:=x;
      END;


     Procedure Kepler(a,b:real;VAR fl:real);
     Var mitte:real;
        BEGIN
        mitte:=a+(b-a)/2;
        fl:=(b-a)/6*(f(a)+4*f(mitte)+f(b));
       end;

     Procedure ausgabe(fl:real);
       BEGIN
        Write('Die Flaeche betr„gt: ',fl:5:2);Readln;
        end;

BEGIN
     eingabe(u_grenze,o_grenze);
     kepler(u_grenze,o_grenze,flaeche);
     ausgabe(flaeche);
end.