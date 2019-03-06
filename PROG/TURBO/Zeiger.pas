Program zeiger1;                { Zeiger1.pas }
USES crt;
TYPE zeiger = ^INTEGER;
VAR  a,b,c  : zeiger;

BEGIN
     CLRSCR;
     { Erzeugung der dynamischen Variablen a^,b^,c^ }
     NEW (a);
     NEW (b);
     NEW (c);
     { Zuweisung von Werten an die Variablen }
     a^:= 20;
     b^:= 40;
     c^:= 60;
     WRITELN ( 'a^=  ',a^, ' b^=  ',b^, ' c^=  ' , c^ );
     WRITELN;
     WRITELN ( 'Inhalt von b^wird a^zugewiesen');
     WRITELN;
     a^:= b^;
     WRITELN ( ' a^= ' , a^, ' b^= ' , b^, ' c^= ',c^ );
     WRITELN ( 'c^ wird das Produkt b^ * a^zugewiesen. ' );
     WRITELN;
     c^:= a^* b^;

     WRITELN ('a^=  ' , a^, '  b^= ' , b^, '  c^=  ' ,c^);
     GOTOXY (1,25);
     WRITE ( ' Bitte <CR> druecken ... ' );
     READLN;
     { Dynamische Variablen wieder entfernen }
     DISPOSE (a);
     DISPOSE (b);
     DISPOSE (c);
     END.