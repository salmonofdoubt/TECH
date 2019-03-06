USES crt;

Label 5;

VAR   V,P,T : REAL;
     Zeichen: CHAR;
        Wahl: Byte;
   korrekt,fertig: BOOLEAN;

CONST  R = 8314;

Procedure Eingabe;
   Begin
     WriteLn; WriteLn (' Falsche Eingabe! Musstes eben besser machen ! ');
     WriteLn;
   End;

Begin
  clrscr;
  writeln;writeln;writeln;writeln ('   Allg. Gasgleichung    ');
  Repeat
    writeln ('    Druckberechnung      ****1**** ');
    writeln ('    Volumenberechnung    ****2**** ');
    writeln ('    Temperaturberechnung ****3**** ');
   repeat
    readln  (Wahl);
    korrekt := (Wahl=1)or(Wahl=2)or(Wahl=3);
    if not korrekt then
    writeln ('ERROR');
  Until korrekt;
  Repeat Until Keypressed;

    writeln;writeln;writeln;

  Case Wahl of
    1: begin write ( 'Temp in K ...:');            
             readln (T);
       5: write ( 'Vol...:');
             readln (V);
       if V=0 then begin eingabe ; goto 5 end else

        P:=T*R/V;

       writeln;writeln;writeln ( 'Druck = :',P:4:3,' Pa');
       repeat until keypressed; writeln;writeln;
       end;

    2: begin write ( 'p in Pa ...:');    readln (p);
             write ( 'Temp in K...:');   readln (T);

               V:=T*R/p;

             writeln;writeln;writeln ( 'Vol = :',V:4:3, 'l');
             repeat until keypressed;
       end;

    3: begin write ( 'Vol in l...:');    readln (V);
             write ( 'p in Pa...:');     readln (p);

              T:=V/R*p;

               writeln;writeln;writeln ( 'T = : ',T:4:3, ' K bzw ' ,
                                             T-273.15 :4:3,' grd C');
             repeat until keypressed;
       end;
end;
writeln; writeln; writeln;
write (' Weiter  ( j / n )  ?'); readln (Zeichen);

                          fertig := (Zeichen = 'n') or (Zeichen = 'N');
                         

                        until fertig;

end.
