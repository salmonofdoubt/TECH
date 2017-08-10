Program Reynold;

USES crt;

CONST
     r= 0.1;
    cw= 0.2;                   {Widerstandsbeiwert}
    ro= 1261;                  {Dichtewert}
     k= 1170E-6;               {kinematische Viskosit„t}

VAR
   Re,v,Fw: REAL;               {Reynoldszahl,Relativgeschwindigkeit und
                                Str”mungswiderstand}

BEGIN
CLRSCR;
Re := 0; v := 0;
 WHILE Re < 1160 DO BEGIN

 v := v + 0.1 ;
 Fw:= cw * pi * SQR(r) * 0.5 * ro * SQR (v);
 Re:= (r*v/k);
 GOTOXY (1,20); WRITELN (' Geschwindigkeit der Kugel : ' , v:10:1, 'm/s');
 GOTOXY (1,22); WRITELN (' Stroemungswiderstand      : ' , Fw:10:3, 'N');
 END;  {der WHILE Schleife}
 READLN;
END.