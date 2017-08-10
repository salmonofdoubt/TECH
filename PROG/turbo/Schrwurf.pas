PROGRAM wurf;
uses crt;
VAR  v,alpha,t,alb:real;
      x,y:real;
     Procedure eingabe(var v,alpha,t:real);
      BEGIN
       clrscr;
       Writeln('Berechnen der Wurfh”he- und -weite');
       writeln;
       Write('Anfangsgeschwindigkeit in m/s eingeben : ');
       readln(v);
       write('Winkel Alpha in Grad angeben : ');
       readln(alpha);
       write('Zeit in s angeben:');
       readln(t);writeln;writeln;
       end;

     Procedure berechnung(var v,alpha,t,alb,x,y:real);
       const g=9.81;
       BEGIN
        alb:=alpha*pi/180;
        x:=v*t*cos(alb);
        y:=v*t*sin(alb)-0.5*g*t*t;
       end;

     Procedure ausgabe(var x,y:real);
       BEGIN
        Write('Wurfweite: ',x:5:2);
        writeln(' in m');
        Write('Wurfh”he:  ',y:5:2);
        writeln(' in m');readln;
       end;

BEGIN
     eingabe(v,alpha,t);
     berechnung(v,alpha,t,alb,x,y);
     ausgabe(x,y);
end.