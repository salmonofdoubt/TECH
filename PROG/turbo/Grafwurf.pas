Program schraegenWurfdarstellen;
Uses crt, graph;

Var  treiber, modus, fehler     :integer;
     i,f,g,xp,z,wmp,wp,hp       :integer;
     a,b,c,h,s,t,v,w,wm,x,y     :real;
     as,hs,vs,ws,zs             :string;
                             yp :array [50..639] of integer;
     Antwort  :char;
     wieder   :boolean;

procedure screen;
    begin
      TextMode (1);
      Textcolor(10);
      gotoxy (1,14);
      writeln('         Programm zur Berechnung');
      writeln('             und Zeichnung');
      writeln('           des schiefen Wurfs');
      writeln;writeln;writeln(' Startgeschw. > 31 m / s');writeln;
      writeln('...');
    end;
procedure eingabe;
    begin
      gotoxy(3,18);
      write('Startgeschwindigkeit ( m / s ):');
      readln (v); str(v:5:2,vs); writeln;
      write('Abwurfwinkel ( ø ):');
      readln (a); str(a:5:2,vs); TextMode (3);
    end;

procedure Achsen;
   begin
     DirectVideo := False;
     Treiber     := Detect;
     Initgraph (Treiber, modus,'\bp\bgi');
     fehler      := Graphresult;
     if fehler <> grOK then
       begin
       writeln;writeln('Grafikfehler: ',GraphErrorMsg(Fehler));
       writeln('Programm wird abgebrochen'); delay (3000);
       Halt (1);
       end;
     g:= getmaxY + 1;
     MoveTo(50,round(0.01*g));
     LineRel (3,10);
     LineRel (-6,0);
     Linerel (3,-10);
     Lineto(50,round(0.9*g));
     lineto(600,round(0.9*g));
     Linerel (-15,2);
     Linerel (0,-4);
     Linerel (15,2);
   end;

procedure skalen;
   begin
     for i := 0 to 10 do
     line (50+50*i, round (0.9*g), 50 + 50 * i, round ( 0.914*g ));
     for i := 0 to 10 do
     line (43, round ((0.9-I*0.08)*g), 50, round (( 0.9-I*0.08)*g));;
     for i := 0 to 5 do begin
       z:= 20*i;
       str(z,zs);
       settextstyle(3,0,1);
       settextjustify(1,0);
       outtextXY (52+i*100, round (0.98*g ), zs);
       outtextXY (610, round (0.98*g),'x/m');
     end;
     for i := 0 to 5 do begin
       z:= 10*i;
       str(z,zs);
       settextjustify(2,0);
       outtextXY (40, round ((0.92-0.16*i)*g), zs);
       outtextXY (42, round (0.03*g),'y/m');
     end;
   end;

procedure rechnen;
   begin
     b:= a * Pi / 180;
     w:= SQR(v) * Sin(2*b) / 9.81;
     str(w:5:2,ws);
     wp:= round( 5*w+50);
     if wp>639 then begin
       setviewport (150,50,490,200,true);
       clearviewport;
       settextjustify (1,1);
       settextstyle(1,0,4);
       setcolor (red);
       rectangle (0,0,340,150);
       outtextXY (170,55,'Abbruch');
       outtextXY (170,95,'v zu groá');
       delay (3000);
       halt (1);
     end;
     wm:= w / 2 ;
     wmp:= round (5*wm+50);
     h:= SQR (v*SIN(b))/(2*9.81);
     str(h:5:2,hs);
     hp:= round(g*(0.9-0.016*h));
     c:= 9.81/2/sqr(v*cos(b));
     t:= sin(b)/cos(b);
     for xp:= 50 to wp do begin
       x:= (xp-50)/5;
       y:= x*t-c*sqr(x);
       yp[xp]:= round(g*(0.9-0.016*y));
       end;
     end;

procedure zeichnen;
begin
  wieder:= true;
  f:= 9;
  setcolor(f);
  repeat
    settextjustify(2,0);
    outtextXY (465,round(0.06 * g),'v :');
    outtextXY (535,round(0.06 * g),vs);
    outtextXY (450,round(0.12 * g),(#224));
    outtextXY (465,round(0.12 * g),' : ');
    outtextXY (535,round(0.12 * g),as);
    outtextXY (465,round(0.18 * g),'w :');
    outtextXY (535,round(0.18 * g),ws);
    outtextXY (465,round(0.24 * g),'h :');
    outtextXY (535,round(0.24 * g),hs);
    settextjustify(0,0);
    outtextXY (545,round(0.06 * g),'m/s');
    circle(550,round(0.18*g),4);
    outtextXY (545,round(0.18 * g),'m');
    outtextXY (545,round(0.24 * g),'m'#224);
    for xp:= 50 to wp-1 do
      line (xp,yp[xp],xp+1,yp[xp+1]);

      {+++++++++++++++}

     circle(wmp,hp,3);

     outtextXY(440,round(0.33*g),'weiter? (j/n)');
     Antwort:= readkey;
     if antwort = 'j' then begin
       f:= f+1;
       if f=16 then f:= 1;
       setcolor(f);
       outtextXY (440,round(0.42 * g),'v :');
       gotoxy (61,13);
       readln(v);
       str(v:5:2,vs);
       outtextXY (440,round(0.49 * g),(#224));
       outtextXY (440,round(0.49 * g),':');
       gotoxy (61,15);
       readln (a);
       str(a:5:2,as);
       setfillstyle(1,0);
       bar(430,5,600,round(0.55*g));
       Rechnen;
     end else
       wieder:= False;
   until wieder=False;
   closegraph;
   end;

     begin screen;delay(5000); clrscr;eingabe;achsen;skalen; rechnen;Zeichnen;
        repeat until keypressed ;end.




