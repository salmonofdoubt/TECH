program
             grenzwert                                                    ;

uses         crt                                                          ;

var          zz       :   integer      {Anzahl der Iterationen }          ;
             xx       :   real         {Wert des Grenzwertes   }          ;

function     f ( x : real ) : real                                        ;
             var a : shortint                                             ;
             begin
                 if frac ( x / 2 ) = 0 then a := 1 else a := -1           ;
                 begin
                      f := a / exp ( x * ln (2) )                         ;
                 end                                                      ;
             end                                                          ;

procedure    eingabe ( var zz : integer )                                 ;
               begin
                   writeln                                                     ;
                   writeln ('Im folgenden wird der Grenzwert der Reihe ') ;
                   writeln ('y = ( -1 ^ k ) / ( 2 ^ k ) berechnet      ') ;
                   writeln                                                     ;
                   write   ('Gewuenschte Anzahl der Iterationen        ') ;
                   readln  ( zz )                                              ;
                end                                                       ;

procedure    berechnung ( var xx : real; zz : integer)                    ;
             var i : integer                                              ;
                begin
                    xx       := 1                                         ;
                    for i    := 1  to  zz  do
                    begin
                           xx := xx + f(i)                                ;
                     end                                                  ;
                end                                                       ;

procedure    ausgabe  ( xx : real ; var zz : integer )                    ;
                begin
                   writeln                                                ;
                   writeln ('Der Grenzwert der gegebenen Funktion '    )  ;
                   writeln ('wurde berechnet mit  ',xx : 10 : 10       )  ;
                   writeln                                                ;
                   repeat  until  keypressed                              ;
                end                                                       ;

begin
            clrscr                                                        ;
            eingabe (zz)                                                  ;
            berechnung (xx,zz)                                            ;
            ausgabe (xx,zz)                                               ;
end.