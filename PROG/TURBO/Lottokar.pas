program
                zufallszahlen ;

uses            crt           ;

const           ziehZ    =  5 ;
                gesZ     =  35;
                anzZi    =  5 ;

type            werte   = array [1..ziehZ] of integer  ;

var             xx  :    werte  ;
                a   :    integer;

procedure       zufall (ziehZ,gesZ:integer;var xx : werte)  ;
                var i,b,zahl : integer;
                      wied   : boolean;

                begin
                    for i:= 1 to ziehZ do xx[i]:=0;

                    for i:= 1 to ziehZ do
                       begin

                       repeat
                          wied := false ;
                          zahl := random(gesZ)+1;
                             for b:= 1 to i do
                             if  zahl = xx[b] then
                                 wied := true ;

                            until wied=false ;

                            xx[i]:=zahl;
                       end;
                 For i:=1 to ziehZ do writeln('  Zahl ',i:3,'  =  ',xx [i]:3 ) ;                       readln;
                 end ;


begin
clrscr;
for a:=1 to anzZi do
zufall(ziehZ,gesZ,xx);
end.