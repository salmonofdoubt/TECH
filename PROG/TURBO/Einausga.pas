Program EingabeTest (input, output);
uses crt;

Var a:byte;
    s:integer;
    aussdruck : boolean;

    Procedure EingabeAbfrage (var aussdruck : boolean);
begin
     aussdruck := true ;
     if ioresult =0 then aussdruck := true
        else aussdruck := false;
end;
begin
     s:=0;
     clrscr;
     repeat;
            write ('Geben Sie einen byte (0-255) Wert ein :');
            {readln;}
            {$I-} readln (a) {$I+};

            EingabeAbfrage (aussdruck);

            writeln ('Wahrheitswert     : ', aussdruck);
            writeln ('eingegebener Wert : ',a);
            writeln ; s:=s+1;

     until s>3; writeln (s);
     read;
end.